#include "stdafx.h"
#include "Player.h"

#include "../../StaticGameData.h"
#include "../../../app/app.h"
#include "../../../Engine/MathManager.h"

Player::Player()
{
    m_sprite = new Entity("sprite", ".\\TestData\\Nave.bmp");
    AddChild(m_sprite);
    
    m_weapon = new Weapon();
    m_sprite->AddChild(m_weapon);
    m_weapon->SetPosition(0.f, 20.f);

    m_propulsion_flame = new Entity("sprite", ".\\TestData\\PropulsionFlame.bmp", 7, 1);
    m_propulsion_flame->CreateAnimation(0,0.1f,{0,1,2,3,4,5,6});
    m_propulsion_flame->SetAnimation(0);
    m_sprite->AddChild(m_propulsion_flame);
    m_propulsion_flame->SetPosition(0.0f,-20.0f);
    m_propulsion_flame->SetScale(2.0f,2.0f);
    m_propulsion_flame->SetAngle(PI);
    m_propulsion_flame->SetActive(false);

    m_rigidBody = new RigidBody();
    //m_rigidBody->SetGravity({1000.0f,0.0f});
    m_sprite->AddChild(m_rigidBody);

    m_player_shield = new PlayerShield();
    m_sprite->AddChild(m_player_shield);
    m_player_shield->SetActive(false);

    m_player_scanner = new PlayerScanner();
    m_sprite->AddChild(m_player_scanner);
    m_player_scanner->SetActive(false);
    
    m_collider = new BoxCollider(20.f,20.f);
    m_collider->SetTag(CollisionTag::PLAYER);
    m_sprite->AddChild(m_collider);

    SetScale(0.3f, 0.3f);

    StaticGameData::PlayerRef = this;
}

void Player::HandleInput()
{
    //rotation
    if(App::GetController().GetLeftThumbStickX() > 0.5f)
    {
        m_sprite->SetAngle(m_sprite->GetAngle() - m_rot_speed);
    }
    if(App::GetController().GetLeftThumbStickX() < -0.5f)
    {
        m_sprite->SetAngle(m_sprite->GetAngle() + m_rot_speed);
    }
    
    //movement
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_A, false))
    {
        MoveForward();
    }
    else
    {
        StopEngine();
    }
    
    //fire
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_X, true))
    {
        ShootWeapon(GetDirection());
    }
    
    //shield
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_Y, false))
    {
       UseShieldAndScanner();
    }
    else
    {
       StopShieldAndScanner();
    }
   
}

void Player::Update(float dt)
{
    SceneNode::Update(dt);
    HandleInput();
    
    UpdatePositionWithRigidBody();
    
    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::ENEMYBULLET))
    {
        if(m_player_shield->IsActive())
        {
            //make a sound or something
            return;
        }
        StaticGameData::KillPlayer();
    }
}

void Player::Draw()
{
    SceneNode::Draw();
}

void Player::Exit()
{
    ExitChildren();

    delete m_sprite;
    m_sprite = nullptr;

    delete m_collider;
    m_collider = nullptr;

    App::StopSound(".\\TestData\\spaceship_engine.wav");
}

Vector2 Player::GetDirection() const
{
    return MathManager::GetDirectionBetweenVectors(m_sprite->GetWorldPosition(), m_weapon->GetWorldPosition());
}

void Player::SetBulletPool(BulletPool* bullet_pool) const
{
    m_weapon->SetBulletPool(bullet_pool);
}

void Player::ShootWeapon(Vector2 direction) const
{
    App::PlaySoundEffect(".\\TestData\\laser1.wav");
    m_weapon->Shoot(direction);
}

void Player::SetRespawnPoint(Vector2 respawnPoint)
{
    m_respawn_point = respawnPoint;
    SetPosition(respawnPoint.x, respawnPoint.y);
}

void Player::GoToRespawnPoint()
{
    SetPosition(m_respawn_point.x, m_respawn_point.y);
    m_rigidBody->Restart();
}

void Player::UpdatePositionWithRigidBody()
{
    //update with RigidBody
    Vector2 currentPosition = GetPosition();
    const Vector2 rigidBodyVelocity = m_rigidBody->GetVelocity();
    currentPosition = {currentPosition.x + rigidBodyVelocity.x, currentPosition.y + rigidBodyVelocity.y};
    SetPosition(currentPosition.x, currentPosition.y);
}

void Player::MoveForward() const
{
    //physics
    Vector2 external_force;
    const Vector2 direction = GetDirection();
    const Vector2 normalizedDirection = MathManager::NormalizeVector(direction);
    external_force.x += normalizedDirection.x * m_forward_force;
    external_force.y += normalizedDirection.y * m_forward_force;
    m_rigidBody->SetExternalForce(external_force);

    //animation
    m_propulsion_flame->SetActive(true);
    
    //sound
    if(!App::IsSoundPlaying(".\\TestData\\spaceship_engine.wav"))
    {
        App::PlaySoundEffect(".\\TestData\\spaceship_engine.wav", true);
    }

    //game data
    StaticGameData::UseFuel(1);
}

void Player::StopEngine() const
{
    //sound
    App::StopSound(".\\TestData\\spaceship_engine.wav");

    //animation
    m_propulsion_flame->SetActive(false);

    //physics
    m_rigidBody->SetExternalForce({0.0f,0.0f});
}

void Player::UseShieldAndScanner() const
{
    //animation
    m_player_shield->SetActive(true);
    CheckForCloseResource();

    //game data
    StaticGameData::UseFuel(1);
}

void Player::StopShieldAndScanner() const
{
    //animation
    m_player_shield->SetActive(false);
    m_player_scanner->SetActive(false);
}

void Player::CheckForCloseResource() const
{
    const auto resources = StaticGameData::ResourcesList;
    for(const auto resource : resources)
    {
        if(!resource->IsActive()) continue;
        const float distance = MathManager::GetDistanceBetweenPoints(GetWorldPosition(), resource->GetWorldPosition());
        if(distance <= m_player_scanner->GetScannerDetectionRadius())
        {
            //set scanner direction
            const Vector2 direction = MathManager::GetDirectionBetweenVectors(GetWorldPosition(), resource->GetWorldPosition());
            m_player_scanner->SetDirection(direction);
            //show scanner
            m_player_scanner->SetActive(true);
            //make sound
            if(!App::IsSoundPlaying(".\\TestData\\laser13.wav"))
            {
                App::PlaySoundEffect(".\\TestData\\laser13.wav");
            }
            if(distance<= m_player_scanner->GetGatherRange())
            {
                //gather resource
                resource->SetActive(false);
                StaticGameData::GetFuelTank(1000);
                //make sound
                if(!App::IsSoundPlaying(".\\TestData\\Powerup.wav"))
                {
                    App::PlaySoundEffect(".\\TestData\\Powerup.wav");
                }
            }
            return;
        }
    }
    m_player_scanner->SetActive(false);
}
