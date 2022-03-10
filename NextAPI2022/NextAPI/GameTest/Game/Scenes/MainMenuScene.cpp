#include "stdafx.h"
#include "MainMenuScene.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Button.h"
#include "../Prefabs/Buttons/GameSceneButton.h"
#include "../Prefabs/Buttons/NavigationButtons.h"

MainMenuScene::MainMenuScene()
{
    m_background = new Entity("background", ".\\TestData\\Pokemon.bmp");
    AddRootNode(m_background);

    m_vertical_navigation_buttons = new NavigationButtons();
    m_background->AddChild(m_vertical_navigation_buttons);

    m_play_game_button = new GameSceneButton("play game button","Play Game", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_restart_button = new GameSceneButton("restart button","Restart", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_vertical_navigation_buttons->AddButton(m_play_game_button);
    m_vertical_navigation_buttons->AddButton(m_restart_button);
    m_vertical_navigation_buttons->SetVerticalLayout(10.f);
   // m_buttonTest->SetPosition(100.0f, 100.0f);

    // m_testText = new Text("test Text", "Holaaaaaa!");
    // m_buttonTest->AddChild(m_testText);
    
}
