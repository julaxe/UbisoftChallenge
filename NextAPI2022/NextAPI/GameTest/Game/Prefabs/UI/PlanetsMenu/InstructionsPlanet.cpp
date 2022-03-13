#include "stdafx.h"
#include "InstructionsPlanet.h"

#include "../../../../Engine/SceneManager.h"
#include "../../../Scenes/InstructionsScene.h"

InstructionsPlanet::InstructionsPlanet(std::string name, const char* fileName) : UIMenuPlanet(name,fileName)
{
}

void InstructionsPlanet::Update(float dt)
{
    UIMenuPlanet::Update(dt);

    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYER))
    {
        SceneManager::ChangeScene(new InstructionsScene());
    }
}