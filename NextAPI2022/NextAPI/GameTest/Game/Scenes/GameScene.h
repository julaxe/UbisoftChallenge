#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/UI/PauseManager.h"
#include "../Prefabs/UI/Buttons/MainMenuButton.h"
#include "../Prefabs/Player/Player.h"

class GameScene : public Scene
{
public:
    GameScene();
private:
    Entity* m_background;
    MainMenuButton* m_main_menu_button_;
    Player* m_player;
    PauseManager* m_pause_manager;
};
