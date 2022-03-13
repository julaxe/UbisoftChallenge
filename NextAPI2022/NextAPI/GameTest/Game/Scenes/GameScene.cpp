#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
    m_background = new SceneNode("background");
    m_background->SetScale(1.0f, 1.0f);
    AddRootNode(m_background);

    m_player_interface = new PlayerInterface();
    AddRootNode(m_player_interface);

    Bullet* playerBullet = new Bullet(".\\TestData\\PlayerBullet.bmp",3,1);
    playerBullet->SetTag(CollisionTag::PLAYERBULLET);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_background->AddChild(m_player_bullet_pool);

    const Bullet* turretBullet = new Bullet(".\\TestData\\TurretBullet.bmp",1,1);
    turretBullet->SetTag(CollisionTag::ENEMYBULLET);
    m_turrets_bullet_pool = new BulletPool(new Bullet(*turretBullet));
    m_background->AddChild(m_turrets_bullet_pool);
    
    m_tutorial_planet = new TutorialPlanet();
    m_tutorial_planet->SetScale(2.0f,2.0f);
    m_background->AddChild(m_tutorial_planet);

    m_turret = new Turret();
    m_turret->SetBulletPool(m_turrets_bullet_pool);
    m_background->AddChild(m_turret);
    m_turret->SetPosition(-180.0f,12.0f);
    
    m_player = new Player();
    m_background->AddChild(m_player);
    m_player->SetRespawnPoint({0.0f,300.0f});

    m_player->SetBulletPool(m_player_bullet_pool);
    m_pause_manager = new PauseManager();
    m_background->AddChild(m_pause_manager);
}

void GameScene::Exit()
{
    Scene::Exit();
}
