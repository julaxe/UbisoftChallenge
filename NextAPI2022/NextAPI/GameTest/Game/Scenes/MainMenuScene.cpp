#include "stdafx.h"
#include "MainMenuScene.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Button.h"
#include "../Prefabs/UI/Buttons/GameSceneButton.h"
#include "../Prefabs/UI/Buttons/NavigationButtons.h"
#include "../Prefabs/UI/Buttons/CreditsButton.h"
#include "../Prefabs/UI/Buttons/InstructionsButton.h"
#include "../Prefabs/UI/Buttons/ExitButton.h"

MainMenuScene::MainMenuScene()
{
    m_background = new Entity("background", ".\\TestData\\Pokemon.bmp");
    AddRootNode(m_background);

    m_vertical_navigation_buttons = new NavigationButtons();
    m_background->AddChild(m_vertical_navigation_buttons);

    m_play_game_button = new GameSceneButton("play game button","Play Game", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_credits_button = new CreditsButton("credits button","Credits", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_instructions_button = new InstructionsButton("instructions button","Instructions", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_exit_button = new ExitButton("exit button","Quit Game", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    
    m_vertical_navigation_buttons->AddButton(m_play_game_button);
    m_vertical_navigation_buttons->AddButton(m_instructions_button);
    m_vertical_navigation_buttons->AddButton(m_credits_button);
    m_vertical_navigation_buttons->AddButton(m_exit_button);
    m_vertical_navigation_buttons->SetVerticalLayout(10.f);
    
}

void MainMenuScene::Exit()
{
    Scene::Exit();
}
