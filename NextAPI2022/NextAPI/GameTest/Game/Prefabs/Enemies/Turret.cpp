#include "stdafx.h"
#include "Turret.h"

#include "../../StaticGameData.h"
#include "../../../app/app.h"
#include "../../../Engine/MathManager.h"

Turret::Turret()
{
    m_turret_sprite= new Entity("sprite", ".\\TestData\\Turret.bmp");
    AddChild(m_turret_sprite);

    m_weapon = new Weapon();
    AddChild(m_weapon);
    m_weapon->SetPosition(0.0f,5.0f);

    m_collisionBox = new BoxCollider(12.f,15.f);
    m_collisionBox->SetTag(CollisionTag::ENEMY);
    
    AddChild(m_collisionBox);
    SetScale(1.5f,1.5f);
    
}

void Turret::Update(float dt)
{
    SceneNode::Update(dt);

    if(!IsActive())return;
    if(!IsEnabled())return;
    
    if(CheckForCollision())
    {
        m_health -= 40.0f;
        if(m_health <= 0.0f)
        {
            SetEnable(false);
            App::PlaySoundEffect(".\\TestData\\Explosion2.wav");
            StaticGameData::PlayerScore += 20;
            //set score or something here
        }
    }
    if(!IsPlayerInRange()) return;
    
    dt *= 0.001f;
    if(m_timer >= m_fire_rate)
    {
        ShootBullet();
        m_timer = 0.0f;
    }
    m_timer += dt;
    
    
    
}

void Turret::Exit()
{
    SceneNode::Exit();
}

void Turret::SetBulletPool(BulletPool* bulletPool) const
{
    m_weapon->SetBulletPool(bulletPool);
}

void Turret::SetFireRate(float fireRate)
{
    m_fire_rate = fireRate;
}

void Turret::SetDetectionRadius(float radius)
{
    m_detection_radius = radius;
}

void Turret::SetCurrentHealth(float health)
{
    m_health = health;
}

void Turret::ShootBullet() const
{
    if(!m_weapon->GetBulletPool())
    {
        m_weapon->SetBulletPool(StaticGameData::TurretsBulletPool);
    }
    const Vector2 direction = MathManager::GetDirectionBetweenVectors(GetWorldPosition(), StaticGameData::PlayerRef->GetWorldPosition());
    m_weapon->Shoot(direction);
    App::PlaySoundEffect(".\\TestData\\laser5.wav");
}

bool Turret::IsPlayerInRange() const
{
    const float distance = MathManager::GetDistanceBetweenPoints(GetWorldPosition(), StaticGameData::PlayerRef->GetWorldPosition());
    if(distance < m_detection_radius * m_parent->GetWorldScale().x)
    {
        return true;
    }
    return false;
}

bool Turret::CheckForCollision()
{
    if(m_collisionBox->CheckCollisionWithAnotherTag(CollisionTag::PLAYERBULLET))
    {
        return true;
    }
    return false;
}
