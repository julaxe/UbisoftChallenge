#pragma once
#include "../../../Engine/Line.h"
#include "../../../Engine/SceneNode.h"
#include "../Planets/Planet.h"

class PlayerShield : public SceneNode
{
public:
    PlayerShield();
    void Exit() override;

private:
    Planet* m_shield;
    std::vector<Vector2> m_points;
};
