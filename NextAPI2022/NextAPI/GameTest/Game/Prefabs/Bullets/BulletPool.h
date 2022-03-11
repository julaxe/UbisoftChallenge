#pragma once
#include "Bullet.h"
#include "../../../Engine/SceneNode.h"

class BulletPool : public SceneNode
{
public:
    BulletPool(Bullet* bullet);

    void Exit() override;
    Bullet* GetAvailableBullet();
private:
    void InitializePool();
    void AddABulletToThePool();
    void IncreaseBulletSize();
    void RestartBullet(Bullet* bullet);
    void ClearPool();
    int m_initial_size = 10;
    int m_increment_value = 1;
    Bullet* m_bulletRef;
    std::vector<Bullet*> m_bulletPool;
};
