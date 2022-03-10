#include "stdafx.h"
#include "PauseScene.h"

PauseScene::PauseScene()
{
    m_blurryBackground = new Entity("background", ".\\TestData\\GrayBG.bmp");
    m_blurryBackground->SetAlpha(0.5f);
    AddRootNode(m_blurryBackground);

    //Unpause with START button.
    m_resume_manager = new ResumeManager();
    m_blurryBackground->AddChild(m_resume_manager);

    //Navigate trough buttons in the screen.
    m_navigation_buttons = new NavigationButtons();
    m_blurryBackground->AddChild(m_navigation_buttons);
    
    m_resume_button = new ResumeButton("resume button","Resume", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_restart_button = new GameSceneButton("restart button","Restart", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_main_menu_button = new MainMenuButton("main menu button","Main Menu", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");

    m_navigation_buttons->AddButton(m_resume_button);
    m_navigation_buttons->AddButton(m_restart_button);
    m_navigation_buttons->AddButton(m_main_menu_button);

    //position each button vertically with a defined offset.
    m_navigation_buttons->SetVerticalLayout(10.0f);
}
