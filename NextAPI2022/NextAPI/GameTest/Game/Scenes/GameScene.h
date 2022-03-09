#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"

class GameScene : public Scene
{
public:
    GameScene();
private:
    Entity* m_background;
};
