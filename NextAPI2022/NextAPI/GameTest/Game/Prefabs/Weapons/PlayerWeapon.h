#pragma once
#include "../../../Engine/SceneNode.h"
#include "../Bullets/Bullet.h"
#include "../Bullets/BulletPool.h"

class PlayerWeapon : public SceneNode
{
public:
    PlayerWeapon();

    void SetBulletPool(BulletPool* bullet_pool);
    void HandleInput();
    void Update(float dt) override;
    void Draw() override;
    void Exit() override;

private:
    void Shoot();
    Entity* m_weapon_sprite;
    BulletPool* m_bulletPool = nullptr;
};
