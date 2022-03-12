#include "stdafx.h"
#include "CollisionManager.h"

#include "../app/app.h"

std::vector<BoxCollider*> CollisionManager::m_listBoxColliders;

bool CollisionManager::PointInsideRectangle(Vector2 point, Vector2 rectPos, float width, float height)
{
    if(point.x >= (rectPos.x - width * 0.5f) &&
        point.x <= (rectPos.x + width * 0.5f) &&
        point.y >= (rectPos.y - height * 0.5f) &&
        point.y <= (rectPos.y + height * 0.5f))
    {
        return true;
    }
    return false;
}

bool CollisionManager::isMouseInsideRectangle(float posX, float posY, float width, float height)
{
    float mouseX, mouseY;
    App::GetMousePos(mouseX, mouseY);

    return PointInsideRectangle({mouseX, mouseY}, {posX, posY}, width, height);
}

bool CollisionManager::AABBCollision(Vector2 pos1, Vector2 box1, Vector2 pos2, Vector2 box2)
{
    if( pos1.x < pos2.x + box2.x &&
        pos1.x + box1.x > pos2.x &&
        pos1.y < pos2.y + box2.y &&
        pos1.y + box1.y > pos2.y)
    {
        return true;
    }
    return false;
}

void CollisionManager::AddBoxColliderToCollisionList(BoxCollider* boxCollider)
{
    m_listBoxColliders.push_back(boxCollider);
}

void CollisionManager::ClearCollisionList()
{
    m_listBoxColliders.clear();
}
