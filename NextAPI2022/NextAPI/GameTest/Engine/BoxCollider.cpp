#include "stdafx.h"
#include "BoxCollider.h"

#include "CollisionManager.h"
#include "DebugManager.h"

BoxCollider::BoxCollider(float width, float height)
{
    m_width = width;
    m_height = height;

    CollisionManager::AddBoxColliderToCollisionList(this);
}

void BoxCollider::Update(float dt)
{
    SceneNode::Update(dt);
}

void BoxCollider::Draw()
{
    SceneNode::Draw();
    if(DEBUG_ON)
    {
        if(m_isColliding)
        {
            DebugManager::DrawCollisionBox(GetWorldPosition().x, GetWorldPosition().y, m_width,m_height,1.0f, 0.2f, 0.2f); //red
        }
        else
        {
            DebugManager::DrawCollisionBox(GetWorldPosition().x, GetWorldPosition().y, m_width,m_height,0.2f, 1.0f, 0.2f); //green
        }
    }
}

void BoxCollider::SetTag(CollisionTag tag)
{
    m_tag = tag;
}

void BoxCollider::SetWidth(float width)
{
    m_width = width;
}

void BoxCollider::SetHeight(float height)
{
    m_height = height;
}

bool BoxCollider::CheckCollisionWithAnotherTag(CollisionTag tag)
{
    //go trough all the collisionBoxes in the scene and check if AABB with tag is true
    const auto listOfBoxCollidersInScene = CollisionManager::GetListBoxCollidersInScene();
    for(const auto boxCollider : listOfBoxCollidersInScene)
    {
        if(boxCollider == this) continue;
        if(boxCollider->GetTag() == tag)
        {
            const Vector2 pos1 = {GetWorldPosition().x, GetWorldPosition().y};
            const Vector2 box1 = {m_width, m_height};
            const Vector2 pos2 = {boxCollider->GetWorldPosition().x, boxCollider->GetWorldPosition().y};
            const Vector2 box2 = {boxCollider->GetWidth(), boxCollider->GetHeight()};
            if(CollisionManager::AABBCollision(pos1, box1, pos2, box2))
            {
                m_isColliding = true;
                return m_isColliding;
            }
        }
    }
    m_isColliding = false;
    return m_isColliding;
}
