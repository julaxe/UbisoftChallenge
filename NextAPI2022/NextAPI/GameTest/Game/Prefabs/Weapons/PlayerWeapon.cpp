#include "stdafx.h"
#include "PlayerWeapon.h"

#include "../../../app/app.h"

PlayerWeapon::PlayerWeapon()
{
    Bullet* bullet = new Bullet(".\\TestData\\Triangle.bmp");
    bullet->SetScale(0.3f, 0.3f);
    
    m_bulletPool = new BulletPool(bullet);
    AddChild(m_bulletPool);
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
    m_bulletPool->GetAvailableBullet();
    //set direction here.
}
