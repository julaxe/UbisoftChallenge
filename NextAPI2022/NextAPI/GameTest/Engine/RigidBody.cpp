#include "stdafx.h"
#include "RigidBody.h"

#include "MathManager.h"

RigidBody::RigidBody()
{
}

void RigidBody::Update(float dt)
{
    SceneNode::Update(dt);

    dt *= 0.0001f;
    const Vector2 sumForces = {m_gravityForce.x + m_external_force.x, m_gravityForce.y + m_external_force.y};
    m_acceleration = {sumForces.x * dt, sumForces.y * dt};

    m_velocity = {m_velocity.x + m_acceleration.x * dt, m_velocity.y +m_acceleration.y *dt};
    if(MathManager::GetMagnitudeOfVector(m_velocity) > m_maxSpeed)
    {
        const Vector2 normalized = MathManager::NormalizeVector(m_velocity);
        m_velocity = {normalized.x * m_maxSpeed, normalized.y * m_maxSpeed};
    }
}

void RigidBody::SetGravity(Vector2 gravity)
{
    m_gravityForce = gravity;
}

void RigidBody::SetExternalForce(Vector2 externalForce)
{
    m_external_force = externalForce;
}


void RigidBody::SetMaxSpeed(float maxSpeed)
{
    m_maxSpeed = maxSpeed;
}

void RigidBody::Restart()
{
    m_velocity = {0.0f, 0.0f};
    m_external_force = {0.0f, 0.0f};
}
