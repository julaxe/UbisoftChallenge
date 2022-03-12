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
            const Vector2 newPoint =  MathManager::LerpBetweenVectors(m_point1, m_point2, lerpPosition);
            const float width = m_playerRefCollider->GetWidth();
            const float height = m_playerRefCollider->GetHeight();
            const Vector2 boxPos = {m_playerRefCollider->GetWorldPosition().x - width*0.5f, m_playerRefCollider->GetWorldPosition().y - height* 0.5f};
            if(CollisionManager::PointInsideRectangle(newPoint,boxPos, width, height))
            {
                m_color = {1.0f,0.2f,0.2f};
                return;
            }
        }
        m_color = {1.0f, 1.0f, 1.0f};
    }
}

void Line::Draw()
{
    SceneNode::Draw();
    App::DrawLine(m_point1.x, m_point1.y, m_point2.x, m_point2.y, m_color.x, m_color.y, m_color.z);
}
