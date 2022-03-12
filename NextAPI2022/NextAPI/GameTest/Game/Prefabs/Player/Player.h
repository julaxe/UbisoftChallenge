#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/RigidBody.h"
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

    Vector2 GetDirection() const;
    void SetBulletPool(BulletPool* bullet_pool) const;
    void ShootWeapon(Vector2 direction) const;

private:
    void UpdatePositionWithRigidBody();
    void MoveForward();
    Entity* m_sprite;
    Entity* m_propulsion_flame;
    BoxCollider* m_collider;
    PlayerWeapon* m_weapon;
    RigidBody* m_rigidBody;

    float m_rot_speed = 0.1f;
    float m_forward_force = 10000.0f;
};




