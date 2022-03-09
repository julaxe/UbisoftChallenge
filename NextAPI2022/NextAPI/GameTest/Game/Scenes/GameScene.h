#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/Buttons/MainMenuButton.h"

class GameScene : public Scene
{
public:
    GameScene();
private:
    Entity* m_background;
    MainMenuButton* m_main_menu_button_;
};
