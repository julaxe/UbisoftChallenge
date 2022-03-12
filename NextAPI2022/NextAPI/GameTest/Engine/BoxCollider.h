#pragma once
#include "SceneNode.h"

enum class CollisionTag
{
    DEFAULT,
    PLAYER,
    GROUND,
    ENEMY,
    PLAYERBULLET,
    ENEMYBULLET
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
    float GetWidth() const;

    void SetHeight(float height);
    float GetHeight() const;

    void SetCollidingExternal(bool state);
    bool IsBeingHitByAnExternalSource() const {return m_external_collision;} //when someone else collide with you

    bool CheckCollisionWithAnotherTag(CollisionTag tag);
    bool OutsideGameWorld() const;

private:
    
    CollisionTag m_tag = CollisionTag::DEFAULT;
    bool m_external_collision;
    bool m_isColliding;
    float m_width;
    float m_height;
};
