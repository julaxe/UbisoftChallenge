#pragma once
#include "BoxCollider.h"
#include "SceneNode.h"

class Line : public SceneNode
{
public:
    Line(Vector2 point1, Vector2 point2);

    void Update(float dt) override;
    void Draw() override;

private:
    Vector2 m_point1;
    Vector2 m_point2;
    Vector3 m_color = {1.0f, 1.0f, 1.0f};

    BoxCollider* m_playerRefCollider = nullptr;
    bool m_canCollide = true;
    float m_collisionPrecision = 0.01f; // lower -> more precise
    float m_WakeUpRadius; //lenght * 0.7
    
};
