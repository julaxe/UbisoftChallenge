#include "stdafx.h"
#include "CreditsScene.h"
#include "../StaticGameData.h"
#include "../../Engine/CollisionManager.h"

CreditsScene::CreditsScene()
{
    CollisionManager::ClearCollisionList();
    StaticGameData::ResourcesList.clear();
    
    m_root = new ZoomInEffect();
    AddRootNode(m_root);
    
    m_creditsImage = new Entity("background", ".\\TestData\\CreditsTitle.bmp");
    m_root->AddChild(m_creditsImage);

    m_back_planet = new MainMenuPlanet("Back", ".\\TestData\\planet5.bmp");
    m_root->AddChild(m_back_planet);
    m_back_planet->SetPosition(-200.0f,-200.0f);
    
    const Bullet* playerBullet = new Bullet(".\\TestData\\PlayerBullet.bmp",3,1);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_root->AddChild(m_player_bullet_pool);

    m_player = new Player();
    m_player->SetBulletPool(m_player_bullet_pool);
    m_root->AddChild(m_player);
    
}

void CreditsScene::Exit()
{
    Scene::Exit();
}
