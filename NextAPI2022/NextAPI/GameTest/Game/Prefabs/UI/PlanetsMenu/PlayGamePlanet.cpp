#include "stdafx.h"
#include "PlayGamePlanet.h"

#include "../../../StaticGameData.h"
#include "../../../../Engine/CollisionManager.h"
#include "../../../../Engine/SceneManager.h"
#include "../../../Scenes/GameScene.h"

PlayGamePlanet::PlayGamePlanet(std::string name, const char* fileName) : UIMenuPlanet(name, fileName)
{
}

void PlayGamePlanet::Update(float dt)
{
    UIMenuPlanet::Update(dt);
    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYER))
    {
        SceneManager::ChangeScene(new GameScene());
    }
}
