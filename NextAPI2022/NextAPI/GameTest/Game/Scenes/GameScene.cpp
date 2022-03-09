#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
    m_background = new Entity("background", ".\\TestData\\Pokemon2.bmp");
    AddRootNode(m_background);

    m_main_menu_button_ = new MainMenuButton("test button", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_main_menu_button_->SetFocus(true);
    m_background->AddChild(m_main_menu_button_);
}
