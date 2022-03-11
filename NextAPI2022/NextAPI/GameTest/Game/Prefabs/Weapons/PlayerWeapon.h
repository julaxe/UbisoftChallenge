#pragma once
#include "../../../Engine/SceneNode.h"
#include "../Bullets/Bullet.h"
#include "../Bullets/BulletPool.h"

class PlayerWeapon : public SceneNode
{
public:
    PlayerWeapon();

    void HandleInput();
    void Update(float dt) override;
    void Draw() override;
    void Exit() override;

private:
    void Shoot();
    BulletPool* m_bulletPool;
};
