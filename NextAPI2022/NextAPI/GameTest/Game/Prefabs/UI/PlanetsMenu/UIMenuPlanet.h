#pragma once
#include "../../../../Engine/BoxCollider.h"
#include "../../../../Engine/Entity.h"
#include "../../../../Engine/SceneNode.h"
#include "../../../../Engine/Text.h"

class UIMenuPlanet : public SceneNode
{
public:
    UIMenuPlanet(std::string name, const char* fileName);

    void Exit() override;

protected:
    Entity* m_planet_sprite;
    BoxCollider* m_collider;
    Text* m_text;
    
};
