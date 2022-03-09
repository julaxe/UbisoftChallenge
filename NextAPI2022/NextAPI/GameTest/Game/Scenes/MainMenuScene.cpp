#include "stdafx.h"
#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
    m_background = new Entity("background", ".\\TestData\\Pokemon.bmp");
    AddRootNode(m_background);
    
    // m_player = new Entity("player", ".\\TestData\\Test.bmp", 8,4);
    // m_background->AddChild(m_player);

    m_buttonTest = new GameSceneButton("test button", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_buttonTest->SetFocus(true);
    m_background->AddChild(m_buttonTest);
   // m_buttonTest->SetPosition(100.0f, 100.0f);

    // m_testText = new Text("test Text", "Holaaaaaa!");
    // m_buttonTest->AddChild(m_testText);
    
}
