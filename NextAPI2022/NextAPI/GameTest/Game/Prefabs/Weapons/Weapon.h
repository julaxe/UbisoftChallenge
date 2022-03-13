#pragma once
#include "../../../Engine/SceneNode.h"
#include "../Bullets/Bullet.h"
#include "../Bullets/BulletPool.h"

class Weapon : public SceneNode
{
public:
    Weapon();

    void SetBulletPool(BulletPool* bullet_pool);
    void Update(float dt) override;
    void Draw() override;
    void Exit() override;
    void Shoot(Vector2 direction) const;

private:
    //Entity* m_weapon_sprite;
    BulletPool* m_bulletPool = nullptr;
};
