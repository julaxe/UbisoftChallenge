#include "stdafx.h"
#include "GameScene.h"

#include "../StaticGameData.h"
#include "../../Engine/CollisionManager.h"

GameScene::GameScene()
{
    m_stage = new StageBase();
    AddRootNode(m_stage);
    
    m_player_interface = new PlayerInterface();
    AddRootNode(m_player_interface);
    
    m_pause_manager = new PauseManager();
    AddRootNode(m_pause_manager);
}

void GameScene::Exit()
{
    Scene::Exit();
}
