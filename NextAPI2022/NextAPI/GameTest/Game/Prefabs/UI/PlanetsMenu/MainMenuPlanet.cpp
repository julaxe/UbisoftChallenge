#include "stdafx.h"
#include "MainMenuPlanet.h"
#include "../../../../Engine/SceneManager.h"
#include "../../../Scenes/MainMenuScene.h"

MainMenuPlanet::MainMenuPlanet(std::string name, const char* fileName)  : UIMenuPlanet(name,fileName)
{
}

void MainMenuPlanet::Update(float dt)
{
    UIMenuPlanet::Update(dt);

    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYER))
    {
        SceneManager::ChangeScene(new MainMenuScene());
    }
}
