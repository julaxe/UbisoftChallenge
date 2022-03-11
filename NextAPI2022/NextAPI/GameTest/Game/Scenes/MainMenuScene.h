#pragma once
#include "../../Engine/Scene.h"


class ExitButton;
class InstructionsButton;
class CreditsButton;
class NavigationButtons;
class Entity;
class GameSceneButton;

class MainMenuScene :public Scene
{
public:
    MainMenuScene();
    void Exit() override;
private:
    Entity* m_background;
    GameSceneButton* m_play_game_button;
    CreditsButton* m_credits_button;
    InstructionsButton* m_instructions_button;
    ExitButton* m_exit_button;
    NavigationButtons* m_vertical_navigation_buttons;
};
