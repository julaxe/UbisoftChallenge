#include "stdafx.h"
#include "BossPlanet.h"

#include "../../StaticGameData.h"
#include "../../../Engine/MathManager.h"

BossPlanet::BossPlanet()
{
    Vector2 length = {0.0f,200.0f};
    float angle = 140.0f;
    for(int i = 0; i < 20; i++)
    {
        length = MathManager::RotateVectorByAnAngle(length, angle);
        m_points.push_back(length);

        Weapon* newWeapon = new Weapon();
        newWeapon->SetBulletPool(StaticGameData::BossBulletPool);
        AddChild(newWeapon);
        newWeapon->SetPosition(length.x, length.y);
        m_list_of_weapons.push_back(newWeapon);
    }
    SetClosingCircle(false);
    BuildPlanet(m_points);
}

void BossPlanet::Update(float dt)
{
    Planet::Update(dt);
    ShootBullet(dt);
    RotateBehaviour(dt);
    ScaleBehaviour(dt);
}

void BossPlanet::ShootBullet(float dt)
{
    if(m_timer >= m_fireRate)
    {
        for(const auto weapon : m_list_of_weapons)
        {
            weapon->Shoot(weapon->GetPosition());
        }
        const int randomNumber = rand()%40 + 5;
        m_fireRate = static_cast<float>(randomNumber) * 0.1f;
        m_timer = 0.0f;
    }
    m_timer += dt*0.001f;
}

void BossPlanet::RotateBehaviour(float dt)
{
    if(m_timer2 >= m_rotate_cooldown)
    {
        m_rotation_speed += m_rotation_acceleration * dt * 0.001f;
        if(m_rotation_speed >= m_max_rotation_speed || m_rotation_speed <= -m_max_rotation_speed)
        {
            const int randomNumber = rand()%80 + 20;
            m_rotate_cooldown = static_cast<float>(randomNumber) * 0.1f;
            m_rotation_speed -= m_rotation_acceleration;
            m_rotation_acceleration *= -1;
            m_timer2 = 0.0f;
        }
        SetAngle(GetAngle() + m_rotation_speed);
    }
    m_timer2 += dt*0.001f;
}

void BossPlanet::ScaleBehaviour(float dt)
{
    if(m_timer3 >= m_scale_cooldown)
    {
        SetScale(GetScale().x + m_scale_speed * dt* 0.001f, GetScale().y + m_scale_speed* dt* 0.001f);
        if(GetScale().x > 1.5f)
        {
            m_scale_speed = abs(m_scale_speed) * -1.0f;
        }
        else if(GetScale().x < 1.0f)
        {
            m_scale_speed = abs(m_scale_speed);
        }
    }
    m_timer3 += dt*0.001f;
}
