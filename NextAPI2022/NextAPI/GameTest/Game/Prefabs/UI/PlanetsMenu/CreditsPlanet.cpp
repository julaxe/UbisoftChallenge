#include "stdafx.h"
#include "CreditsPlanet.h"

#include "../../../../Engine/SceneManager.h"
#include "../../../Scenes/CreditsScene.h"

CreditsPlanet::CreditsPlanet(std::string name, const char* fileName) : UIMenuPlanet(name,fileName)
{
}

void CreditsPlanet::Update(float dt)
{
    UIMenuPlanet::Update(dt);

    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYER))
    {
       SceneManager::ChangeScene(new CreditsScene());
    }
}
