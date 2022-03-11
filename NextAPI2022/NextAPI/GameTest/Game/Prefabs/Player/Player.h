#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

class Player : public SceneNode
{
public:
    Player();
    void HandleInput();
    void Update(float dt) override;
    void Draw() override;
    void Exit() override;

private:
    Entity* m_sprite;
    Entity* m_triangle;
    BoxCollider* m_collider;
};
