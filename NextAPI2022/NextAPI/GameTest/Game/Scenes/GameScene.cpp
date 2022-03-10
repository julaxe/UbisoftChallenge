#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
    m_background = new Entity("background", ".\\TestData\\Pokemon2.bmp");
    m_background->SetScale(0.5f, 0.5f);
    AddRootNode(m_background);
    
    m_player = new Player();
    m_background->AddChild(m_player);

    m_pause_manager = new PauseManager();
    m_background->AddChild(m_pause_manager);
}
