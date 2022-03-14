#include "stdafx.h"
#include "GameScene.h"

#include "../StaticGameData.h"
#include "../../Engine/CollisionManager.h"

GameScene::GameScene()
{
    CollisionManager::ClearCollisionList();
    StaticGameData::ResourcesList.clear();
    
    m_root = new SceneNode();
    AddRootNode(m_root);
    
    m_player_interface = new PlayerInterface();
    m_root->AddChild(m_player_interface);

    Bullet* playerBullet = new Bullet(".\\TestData\\PlayerBullet.bmp",3,1);
    playerBullet->SetTag(CollisionTag::PLAYERBULLET);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_root->AddChild(m_player_bullet_pool);
    StaticGameData::PlayerBulletPool = m_player_bullet_pool;

    Bullet* turretBullet = new Bullet(".\\TestData\\TurretBullet.bmp",1,1);
    turretBullet->SetTag(CollisionTag::ENEMYBULLET);
    turretBullet->SetActive(false);
    m_turrets_bullet_pool = new BulletPool(new Bullet(*turretBullet));
    m_root->AddChild(m_turrets_bullet_pool);
    StaticGameData::TurretsBulletPool = m_turrets_bullet_pool;
    
    m_player = new Player();
    m_root->AddChild(m_player);
    m_player->SetRespawnPoint({0.0f,0.0f});

    m_stage_manager = new StageManager();
    m_root->AddChild(m_stage_manager);
    
    
    m_pause_manager = new PauseManager();
    m_root->AddChild(m_pause_manager);
}

void GameScene::Exit()
{
    Scene::Exit();
}
