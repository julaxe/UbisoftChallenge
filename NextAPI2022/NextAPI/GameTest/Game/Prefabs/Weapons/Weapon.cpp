#include "stdafx.h"
#include "Weapon.h"

#include "../../../app/app.h"

Weapon::Weapon()
{
}

void Weapon::SetBulletPool(BulletPool* bullet_pool)
{
    m_bulletPool = bullet_pool;
}

void Weapon::Update(float dt)
{
    SceneNode::Update(dt);
}

void Weapon::Draw()
{
    SceneNode::Draw();
}

void Weapon::Exit()
{
    ExitChildren();

    delete m_bulletPool;
    m_bulletPool = nullptr;
}

void Weapon::Shoot(Vector2 direction) const
{
    Bullet* bullet = m_bulletPool->GetAvailableBullet();
    bullet->SetWorldPosition({GetWorldPosition().x, GetWorldPosition().y});
    bullet->SetDirection(direction); // not normalized
}
