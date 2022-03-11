#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

class Bullet : public SceneNode
{
public:
    Bullet(const char* fileName);

    void Update(float dt) override;
    void Draw() override;
    void Exit() override;

    void SetDirection(Vector2 direction);
    Vector2 GetDirection() const {return m_direction;}
    
    void SetSpeed(float speed);
    float GetSpeed() const {return m_speed;}
private:
    Entity* m_bullet_sprite;
    BoxCollider* m_collider;

    float m_speed = 500.0f;
    Vector2 m_direction = {1.0f, 0.0f};
};
