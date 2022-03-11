#pragma once
#include "BoxCollider.h"
#include "GameObject.h"

class CollisionManager
{
public:
    static bool isMouseInsideRectangle(float posX, float posY, float width, float height);
    static bool AABBCollision(Vector2 pos1, Vector2 box1, Vector2 pos2, Vector2 box2);
    static void AddBoxColliderToCollisionList(BoxCollider* boxCollider);
    static void ClearCollisionList();
    static std::vector<BoxCollider*> GetListBoxCollidersInScene() {return m_listBoxColliders;}
private:
    static std::vector<BoxCollider*> m_listBoxColliders;
};
