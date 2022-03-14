#pragma once
#include "Planet.h"
#include "../Weapons/Weapon.h"

class BossPlanet : public Planet
{
public:
    BossPlanet();

    void Update(float dt) override;

private:
    void ShootBullet(float dt);
    void RotateBehaviour(float dt);
    void ScaleBehaviour(float dt);
    std::vector<Weapon*> m_list_of_weapons;
    float m_timer;
    float m_fireRate = 2.0f;

    float m_timer2;
    float m_rotate_cooldown;
    float m_rotation_speed;
    float m_rotation_acceleration = 0.005f;
    float m_max_rotation_speed = 0.01f;

    float m_timer3;
    float m_scale_cooldown;
    float m_scale_speed;
};
