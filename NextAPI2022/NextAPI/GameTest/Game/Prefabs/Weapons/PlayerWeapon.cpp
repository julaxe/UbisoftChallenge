#include "stdafx.h"
#include "PlayerWeapon.h"

#include "../../../app/app.h"

PlayerWeapon::PlayerWeapon()
{
}

void PlayerWeapon::SetBulletPool(BulletPool* bullet_pool)
{
    m_bulletPool = bullet_pool;
}

void PlayerWeapon::HandleInput()
{
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_X, true))
    {
        Shoot();
    }
}

void PlayerWeapon::Update(float dt)
{
    HandleInput();
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

void PlayerWeapon::Shoot()
{
    Bullet* bullet = m_bulletPool->GetAvailableBullet();
    //set position and direction here.
    bullet->SetWorldPosition({GetWorldPosition().x, GetWorldPosition().y});
    //set direction here.
}
