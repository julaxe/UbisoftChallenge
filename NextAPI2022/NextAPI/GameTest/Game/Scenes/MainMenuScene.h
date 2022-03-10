#pragma once
#include "../../Engine/Scene.h"
class NavigationButtons;
class Entity;
class GameSceneButton;

class MainMenuScene :public Scene
{
public:
    MainMenuScene();
private:
    Entity* m_background;
    GameSceneButton* m_play_game_button;
    GameSceneButton* m_restart_button;
    NavigationButtons* m_vertical_navigation_buttons;
};
