#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/RigidBody.h"
#include "../../../Engine/SceneNode.h"
#include "../Weapons/PlayerScanner.h"
#include "../Weapons/PlayerShield.h"
#include "../Weapons/Weapon.h"

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
    void SetRespawnPoint(Vector2 respawnPoint);
    void GoToRespawnPoint();
    BoxCollider* GetCollider() const {return m_collider;}
    void SetGravity(Vector2 newGravity) const;

private:
    void UpdatePositionWithRigidBody();
    void MoveForward() const;
    void StopEngine() const;
    void UseShieldAndScanner() const;
    void StopShieldAndScanner() const;
    void CheckForCloseResource() const;
    Entity* m_sprite;
    Entity* m_propulsion_flame;
    BoxCollider* m_collider;
    Weapon* m_weapon;
    RigidBody* m_rigidBody = nullptr;
    PlayerShield* m_player_shield;
    PlayerScanner* m_player_scanner;

    Vector2 m_respawn_point = {0.0f, 0.0f};
    
    float m_rot_speed = 0.1f;
    float m_forward_force = 200.0f;
};




