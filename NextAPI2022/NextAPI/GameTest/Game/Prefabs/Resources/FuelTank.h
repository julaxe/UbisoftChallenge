#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

class FuelTank : public SceneNode
{
public:
    FuelTank();

    void Update(float dt) override;

private:
    Entity* m_fueltank_sprite;
    
};
