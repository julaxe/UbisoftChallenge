#include "stdafx.h"
#include "BulletPool.h"

BulletPool::BulletPool(Bullet* bullet)
{
    m_bulletRef = bullet;

    InitializePool();
}

void BulletPool::Draw()
{
    SceneNode::Draw();
}

void BulletPool::Update(float dt)
{
    SceneNode::Update(dt);
}

void BulletPool::Exit()
{
   // ExitChildren();

    delete m_bulletRef;
    m_bulletRef = nullptr;

    ClearPool();
}

Bullet* BulletPool::GetAvailableBullet()
{
    //check if I have bullets available in my pool
    for(int i = 0; i < m_bulletPool.size(); i++)
    {
        if(!m_bulletPool[i]->IsEnabled())
        {
            RestartBullet(m_bulletPool[i]);
            return m_bulletPool[i];
        }
    }
    //if not, increase bullet size, and return of the new bullets.
    IncreaseBulletSize();
    RestartBullet(m_bulletPool.back());
    return m_bulletPool.back();
}

void BulletPool::InitializePool()
{
    for(int i = 0; i < m_initial_size; i++)
    {
        AddABulletToThePool();
    }
}

void BulletPool::AddABulletToThePool()
{
    Bullet* newBullet = new Bullet(m_bulletRef);
    newBullet->SetEnable(false);
    m_bulletPool.push_back(newBullet);
    AddChild(newBullet);
}

void BulletPool::IncreaseBulletSize()
{
    for(int i = 0; i < m_increment_value; i++)
    {
        AddABulletToThePool();
    }
}

void BulletPool::RestartBullet(Bullet* bullet)
{
    bullet->SetPosition(0.0f, 0.0f);
    bullet->SetEnable(true);
}

void BulletPool::DisableBullets()
{
    for(int i = 0; i < m_bulletPool.size(); i++ )
    {
        m_bulletPool[i]->SetEnable(false);
    }
}

void BulletPool::ClearPool()
{
    for(int i = 0; i < m_bulletPool.size(); i++ )
    {
        delete m_bulletPool[i];
        m_bulletPool[i] = nullptr;
    }
    
    m_bulletPool.clear();
}
