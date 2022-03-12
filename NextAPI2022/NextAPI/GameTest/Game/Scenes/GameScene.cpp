#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
    m_background = new Entity("background", ".\\TestData\\Pokemon2.bmp");
    m_background->SetScale(0.5f, 0.5f);
    AddRootNode(m_background);
    
    m_testCollider = new BoxCollider(30.0f, 40.f);
    m_background->AddChild(m_testCollider);
    m_testCollider->SetTag(CollisionTag::ENEMYBULLET);
    m_testCollider->SetPosition(-100.f,100.0f);

    m_bulletTest = new Bullet(".\\TestData\\Triangle.bmp");
    m_bulletTest->SetScale(0.3f, 0.3f);
    m_background->AddChild(m_bulletTest);
    m_bulletTest->SetPosition(-200.0f,0.0f);
    
    m_player_bullet_pool = new BulletPool(new Bullet(*m_bulletTest));
    m_background->AddChild(m_player_bullet_pool);
    
    m_player = new Player();
    m_background->AddChild(m_player);

    m_line = new Line({400.0f, 400.0f}, {-400.f, -400.f});
    m_background->AddChild(m_line);

    m_player->SetBulletPool(m_player_bullet_pool);
    m_pause_manager = new PauseManager();
    m_background->AddChild(m_pause_manager);
}

void GameScene::Exit()
{
    Scene::Exit();
}
