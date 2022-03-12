#include "stdafx.h"
#include "Player.h"

#include "../../../app/app.h"
#include "../../../Engine/MathManager.h"

Player::Player()
{
    m_sprite = new Entity("sprite", ".\\TestData\\Nave.bmp");
    AddChild(m_sprite);
    
    m_weapon = new PlayerWeapon();
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
    m_rigidBody->SetGravity({1000.0f,0.0f});
    m_sprite->AddChild(m_rigidBody);
    
    m_collider = new BoxCollider(20.f,20.f);
    m_collider->SetTag(CollisionTag::PLAYER);
    m_sprite->AddChild(m_collider);

    SetScale(0.3f, 0.3f);
}

void Player::HandleInput()
{
    if(App::GetController().GetLeftThumbStickX() > 0.5f)
    {
        m_sprite->SetAngle(m_sprite->GetAngle() - m_rot_speed);
    }
    if(App::GetController().GetLeftThumbStickX() < -0.5f)
    {
        m_sprite->SetAngle(m_sprite->GetAngle() + m_rot_speed);
    }
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_A, false))
    {
        MoveForward();
        m_propulsion_flame->SetActive(true);
        if(!App::IsSoundPlaying(".\\TestData\\spaceship_engine.wav"))
        {
            App::PlaySoundEffect(".\\TestData\\spaceship_engine.wav", true);
        }
    }
    else
    {
        App::StopSound(".\\TestData\\spaceship_engine.wav");
        m_propulsion_flame->SetActive(false);
        m_rigidBody->SetExternalForce({0.0f,0.0f});
    }
   

    if(App::GetController().CheckButton(XINPUT_GAMEPAD_X, true))
    {
        App::PlaySoundEffect(".\\TestData\\laser1.wav");
        ShootWeapon(GetDirection());
    }
   
}

void Player::Update(float dt)
{
    SceneNode::Update(dt);
    HandleInput();
    
    UpdatePositionWithRigidBody();
    
    m_collider->CheckCollisionWithAnotherTag(CollisionTag::ENEMYBULLET);
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
    m_weapon->Shoot(direction);
}

void Player::UpdatePositionWithRigidBody()
{
    //update with RigidBody
    Vector2 currentPosition = GetPosition();
    const Vector2 rigidBodyVelocity = m_rigidBody->GetVelocity();
    currentPosition = {currentPosition.x + rigidBodyVelocity.x, currentPosition.y + rigidBodyVelocity.y};
    SetPosition(currentPosition.x, currentPosition.y);
}

void Player::MoveForward()
{
    Vector2 external_force;
    const Vector2 direction = GetDirection();
    const Vector2 normalizedDirection = MathManager::NormalizeVector(direction);
    external_force.x += normalizedDirection.x * m_forward_force;
    external_force.y += normalizedDirection.y * m_forward_force;
    m_rigidBody->SetExternalForce(external_force);
}
