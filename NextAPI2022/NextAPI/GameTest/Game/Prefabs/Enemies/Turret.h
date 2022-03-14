#pragma once
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"
#include "../Weapons/Weapon.h"

class Turret : public SceneNode
{
public:
    Turret();

    void Update(float dt) override;
    void Exit() override;
    void SetBulletPool(BulletPool* bulletPool) const;
    void SetFireRate(float fireRate);
    void SetDetectionRadius(float radius);
    void SetCurrentHealth(float health);
    float GetDetectionRadius() const {return m_detection_radius;}
private:
    void ShootBullet() const;
    bool IsPlayerInRange() const;
    bool CheckForCollision();
private:
    Entity* m_turret_sprite;
    Weapon* m_weapon;
    BoxCollider* m_collisionBox;
    float m_health = 100.0f;
    float m_detection_radius = 200.0f;
    float m_fire_rate = 1.0f;
    float m_timer = 0.0f;
    
};
