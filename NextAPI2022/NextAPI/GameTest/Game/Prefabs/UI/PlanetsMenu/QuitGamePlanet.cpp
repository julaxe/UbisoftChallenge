#include "stdafx.h"
#include "QuitGamePlanet.h"

QuitGamePlanet::QuitGamePlanet(std::string name, const char* fileName) : UIMenuPlanet(name,fileName)
{
}

void QuitGamePlanet::Update(float dt)
{
    UIMenuPlanet::Update(dt);

    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYER))
    {
        exit(0);
    }
}