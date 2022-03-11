#pragma once
#include "SceneNode.h"

enum class CollisionTag
{
    DEFAULT,
    PLAYER,
    GROUND,
    BULLET
};
class BoxCollider : public SceneNode
{
public:
    BoxCollider(float width, float height);
    
    void Update(float dt) override;
    void Draw() override;
    
    void SetTag(CollisionTag tag);
    CollisionTag GetTag() const {return m_tag;}

    void SetWidth(float width);
    float GetWidth() const {return m_width;}

    void SetHeight(float height);
    float GetHeight() const {return m_height;}

    bool CheckCollisionWithAnotherTag(CollisionTag tag);

private:
    
    CollisionTag m_tag = CollisionTag::DEFAULT;
    bool m_isColliding;
    float m_width;
    float m_height;
};
