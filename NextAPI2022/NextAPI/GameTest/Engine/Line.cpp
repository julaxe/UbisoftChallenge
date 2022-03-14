#include "stdafx.h"
#include "Line.h"

#include "CollisionManager.h"
#include "MathManager.h"
#include "../app/app.h"
#include "../Game/StaticGameData.h"

Line::Line(Vector2 point1, Vector2 point2)
{
    m_point1 = point1;
    m_point2 = point2;

    CalculateMiddlePoint();
    m_WakeUpRadius = MathManager::GetDistanceBetweenPoints(point1, point2) * 0.8f;
}

void Line::Update(float dt)
{
    if(!IsActive()) return;
    if(!IsEnabled()) return;
    if(!m_canCollide) return;
    const float distanceToPlayer = MathManager::GetDistanceBetweenPoints(GetPointWorldPosition(m_middlePoint), StaticGameData::PlayerRef->GetWorldPosition());
    if(distanceToPlayer > m_WakeUpRadius) return;
    
    m_playerRefCollider = StaticGameData::PlayerRef->GetCollider();
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
                //m_color = {1.0f,0.2f,0.2f};
                StaticGameData::KillPlayer();
                return;
            }
        }
        m_color = m_defaultColor;
    }
}

void Line::Draw()
{
    if(!IsEnabled()) return;
    if(!IsActive()) return;
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
        worldPos.x = m_parent->GetWorldPosition().x + newX*m_parent->GetWorldScale().x;
        worldPos.y = m_parent->GetWorldPosition().y + newY*m_parent->GetWorldScale().y;
    }
    return worldPos;
}

void Line::SetColor(Vector3 color)
{
    m_color = color;
    m_defaultColor = color;
}

void Line::SetCanCollide(bool state)
{
    m_canCollide = state;
}

void Line::CalculateMiddlePoint()
{
    Vector2 difference = MathManager::GetDirectionBetweenVectors(m_point1, m_point2);
    Vector2 halfway = {difference.x * 0.5f, difference.y * 0.5f};
    m_middlePoint = {m_point1.x + halfway.x, m_point1.y + halfway.y};
}
