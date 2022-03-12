#include "stdafx.h"
#include "Line.h"

#include "CollisionManager.h"
#include "MathManager.h"
#include "../app/app.h"

Line::Line(Vector2 point1, Vector2 point2)
{
    m_point1 = point1;
    m_point2 = point2;

    m_WakeUpRadius = MathManager::GetDistanceBetweenPoints(point1, point2) * 0.7f;
}

void Line::Update(float dt)
{
    SceneNode::Update(dt);
    auto listOfColliders = CollisionManager::GetListBoxCollidersInScene();
    if(!m_playerRefCollider)
    {
        for(auto it = listOfColliders.begin(); it < listOfColliders.end(); it++)
        {
            if((*it)->GetTag() == CollisionTag::PLAYER)
            {
                m_playerRefCollider = (*it);
            }
        }
    }
    if(m_playerRefCollider)
    {
        float lerpPosition = m_collisionPrecision;
        for(;lerpPosition <= 1.0f; lerpPosition += m_collisionPrecision)
        {
            const Vector2 worldPosPoint1 = GetPointWorldPosition(m_point1);
            const Vector2 worldPosPoint2 = GetPointWorldPosition(m_point2);
            const Vector2 newPoint =  MathManager::LerpBetweenVectors(worldPosPoint1, worldPosPoint2, lerpPosition);
            const float width = m_playerRefCollider->GetWidth();
            const float height = m_playerRefCollider->GetHeight();
            const Vector2 boxPos = {m_playerRefCollider->GetWorldPosition().x, m_playerRefCollider->GetWorldPosition().y};
            if(CollisionManager::PointInsideRectangle(newPoint,boxPos, width, height))
            {
                m_color = {1.0f,0.2f,0.2f};
                return;
            }
        }
        m_color = {0.0f, 1.0f, 0.0f};
    }
}

void Line::Draw()
{
    SceneNode::Draw();
    const Vector2 worldPosPoint1 = GetPointWorldPosition(m_point1);
    const Vector2 worldPosPoint2 = GetPointWorldPosition(m_point2);
    App::DrawLine(worldPosPoint1.x, worldPosPoint1.y, worldPosPoint2.x, worldPosPoint2.y, m_color.x, m_color.y, m_color.z);
}

Vector2 Line::GetPointWorldPosition(Vector2 point) const
{
    Vector2 worldPos = point;
    
    if(m_parent)
    {
        const float parentAngle = m_parent->GetAngle();
        const float newX = point.x * cosf(parentAngle) - point.y * sinf(parentAngle);
        const float newY = point.x * sinf(parentAngle) + point.y * cosf(parentAngle);
        worldPos.x = m_parent->GetWorldPosition().x + newX*m_parent->GetScale().x;
        worldPos.y = m_parent->GetWorldPosition().y + newY*m_parent->GetScale().y;
    }
    return worldPos;
}
