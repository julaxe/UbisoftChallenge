#pragma once
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

class Player : public SceneNode
{
public:
    Player();
    void HandleInput();
    void Update(float dt) override;
    void Draw() override;

private:
    Entity* m_sprite;
};
