#pragma once
#include "../../Engine/Button.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../../Engine/Text.h"
#include "../Prefabs/Buttons/GameSceneButton.h"
#include "../Prefabs/Buttons/MainMenuButton.h"

class MainMenuScene :public Scene
{
public:
    MainMenuScene();
private:
    Entity* m_player;
    Entity* m_background;
    Text* m_testText;
    GameSceneButton* m_buttonTest;
};
