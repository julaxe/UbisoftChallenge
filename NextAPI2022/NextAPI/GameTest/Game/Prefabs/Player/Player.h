#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"
#include "../Weapons/PlayerWeapon.h"

class Player : public SceneNode
{
public:
    Player();
    void HandleInput();
    void Update(float dt) override;
    void Draw() override;
    void Exit() override;

    void SetBulletPool(BulletPool* bullet_pool) const;

private:
    Entity* m_sprite;
    Entity* m_triangle;
    BoxCollider* m_collider;
    PlayerWeapon* m_weapon;
};
