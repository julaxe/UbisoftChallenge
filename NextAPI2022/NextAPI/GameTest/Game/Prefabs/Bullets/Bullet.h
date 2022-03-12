#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

class Bullet : public SceneNode
{
public:
    Bullet(const char* fileName);
    Bullet(Bullet* bullet);

    void Update(float dt) override;
    void Draw() override;
    void Exit() override;

    void SetDirection(Vector2 direction);
    Vector2 GetDirection() const {return m_direction;}
    
    void SetSpeed(float speed);
    float GetSpeed() const {return m_speed;}

    void AddCollisionTag(CollisionTag tag);
private:
    const char* m_fileName_sprite;
    Entity* m_bullet_sprite;
    BoxCollider* m_collider;

    std::vector<CollisionTag> m_collisionTags;
    float m_speed = 500.0f;
    Vector2 m_direction = {1.0f, 0.0f};
};
