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
            DebugManager::DrawCollisionBox(GetWorldPosition().x, GetWorldPosition().y, GetWidth(),GetHeight(),1.0f, 0.2f, 0.2f); //red
        }
        else if (m_external_collision)
        {
            DebugManager::DrawCollisionBox(GetWorldPosition().x, GetWorldPosition().y, GetWidth(),GetHeight(),0.2f, 0.2f, 1.0f); //blue
        }
        else
        {
            DebugManager::DrawCollisionBox(GetWorldPosition().x, GetWorldPosition().y, GetWidth(),GetHeight(),0.2f, 1.0f, 0.2f); //green
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

float BoxCollider::GetWidth() const
{
    return m_width*m_parent->GetWorldScale().x;
}

float BoxCollider::GetHeight() const
{
    return m_height*m_parent->GetWorldScale().y;
}

void BoxCollider::SetHeight(float height)
{
    m_height = height;
}

void BoxCollider::SetCollidingExternal(bool state)
{
    m_external_collision = state;
}

bool BoxCollider::CheckCollisionWithAnotherTag(CollisionTag tag)
{
    //go trough all the collisionBoxes in the scene and check if AABB with tag is true
    const auto listOfBoxCollidersInScene = CollisionManager::GetListBoxCollidersInScene();
    for(const auto boxCollider : listOfBoxCollidersInScene)
    {
        if(boxCollider == this) continue;
        if(!boxCollider->IsActive()) continue;
        if(!boxCollider->IsEnabled()) continue;
        if(boxCollider->GetTag() == tag)
        {
            const Vector2 pos1 = {GetWorldPosition().x - GetWidth()*0.5f, GetWorldPosition().y - GetHeight()*0.5f};
            const Vector2 box1 = {GetWidth(), GetHeight()};
            const Vector2 pos2 = {boxCollider->GetWorldPosition().x - boxCollider->GetWidth()*0.5f, boxCollider->GetWorldPosition().y - boxCollider->GetHeight() *0.5f};
            const Vector2 box2 = {boxCollider->GetWidth(), boxCollider->GetHeight()};
            if(CollisionManager::AABBCollision(pos1, box1, pos2, box2))
            {
                boxCollider->SetCollidingExternal(true);
                m_isColliding = true;
                return m_isColliding;
            }
        }
    }
    m_isColliding = false;
    return m_isColliding;
}

bool BoxCollider::OutsideGameWorld(float scale) const
{
    const float posX = GetWorldPosition().x;
    const float posY = GetWorldPosition().y;
    
    if(posX > APP_VIRTUAL_WIDTH*scale ||
        posX < APP_VIRTUAL_WIDTH - APP_VIRTUAL_WIDTH*scale ||
        posY > APP_VIRTUAL_HEIGHT*scale ||
        posY < APP_VIRTUAL_HEIGHT-APP_VIRTUAL_HEIGHT*scale)
    {
        return true;
    }
    return false;
}
