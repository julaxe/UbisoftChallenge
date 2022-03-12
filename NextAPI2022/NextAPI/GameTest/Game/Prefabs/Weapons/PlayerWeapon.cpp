#include "stdafx.h"
#include "PlayerWeapon.h"

#include "../../../app/app.h"

PlayerWeapon::PlayerWeapon()
{
    // m_weapon_sprite = new Entity(".\\TestData\\Triangle.bmp");
    // m_weapon_sprite->SetScale(0.2f, 0.2f);
    // AddChild(m_weapon_sprite);
}

void PlayerWeapon::SetBulletPool(BulletPool* bullet_pool)
{
    m_bulletPool = bullet_pool;
}

void PlayerWeapon::Update(float dt)
{
    SceneNode::Update(dt);
}

void PlayerWeapon::Draw()
{
    SceneNode::Draw();
}

void PlayerWeapon::Exit()
{
    ExitChildren();

    delete m_bulletPool;
    m_bulletPool = nullptr;
}

void PlayerWeapon::Shoot(Vector2 direction)
{
    Bullet* bullet = m_bulletPool->GetAvailableBullet();
    bullet->SetWorldPosition({GetWorldPosition().x, GetWorldPosition().y});
    bullet->SetDirection(direction);
}
