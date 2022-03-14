#include "stdafx.h"
#include "GameScene.h"

#include "../StaticGameData.h"
#include "../../app/app.h"
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
    playerBullet->SetActive(false);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_root->AddChild(m_player_bullet_pool);
    StaticGameData::PlayerBulletPool = m_player_bullet_pool;

    Bullet* turretBullet = new Bullet(".\\TestData\\TurretBullet.bmp",1,1);
    turretBullet->SetTag(CollisionTag::ENEMYBULLET);
    turretBullet->SetActive(false);
    m_turrets_bullet_pool = new BulletPool(new Bullet(*turretBullet));
    m_root->AddChild(m_turrets_bullet_pool);
    StaticGameData::TurretsBulletPool = m_turrets_bullet_pool;

    Bullet* bossBullet = new Bullet(".\\TestData\\BossBullet.bmp",1,1);
    bossBullet->SetTag(CollisionTag::ENEMYBULLET);
    bossBullet->SetActive(false);
    bossBullet->SetSpeed(bossBullet->GetSpeed()*0.3f);
    bossBullet->SetScale(0.5f,0.5f);
    m_boss_bullet_pool = new BulletPool(new Bullet(*bossBullet));
    m_root->AddChild(m_boss_bullet_pool);
    StaticGameData::BossBulletPool = m_boss_bullet_pool;
    
    m_player = new Player();
    m_root->AddChild(m_player);
    m_player->SetRespawnPoint({0.0f,0.0f});

    m_stage_manager = new StageManager();
    m_root->AddChild(m_stage_manager);
    
    
    m_pause_manager = new PauseManager();
    m_root->AddChild(m_pause_manager);
    App::PlaySoundEffect(".\\TestData\\Stage1.wav", true);
}

void GameScene::Exit()
{
    Scene::Exit();
}
