#pragma once
#include "SceneNode.h"

class RigidBody : public SceneNode
{
public:
    RigidBody();

    void Update(float dt) override;
    Vector2 GetVelocity() const {return m_velocity;}
    void SetGravity(Vector2 gravity);
    void SetExternalForce(Vector2 externalForce);
    void SetMaxSpeed(float maxSpeed);
    void Restart();
    
private:
    Vector2 m_velocity = {0.0f, 0.0f};
    Vector2 m_acceleration = {0.0f, 0.0f};
    Vector2 m_gravityForce = {0.0f, 0.0f};

    float m_maxSpeed = 2.0f;
    Vector2 m_external_force = {0.0f, 0.0f};
};
