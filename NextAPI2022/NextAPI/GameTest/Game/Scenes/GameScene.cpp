#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
    m_background = new SceneNode("background");
    m_background->SetScale(1.0f, 1.0f);
    AddRootNode(m_background);

    const Bullet* playerBullet = new Bullet(".\\TestData\\PlayerBullet.bmp",3,1);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_background->AddChild(m_player_bullet_pool);
    
    m_tutorial_planet = new TutorialPlanet();
    m_tutorial_planet->SetScale(2.0f,2.0f);
    m_background->AddChild(m_tutorial_planet);
    m_player = new Player();
    m_background->AddChild(m_player);


    m_player->SetBulletPool(m_player_bullet_pool);
    m_pause_manager = new PauseManager();
    m_background->AddChild(m_pause_manager);
}

void GameScene::Exit()
{
    Scene::Exit();
}
