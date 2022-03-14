#include "stdafx.h"
#include "InstructionsScene.h"

#include "../StaticGameData.h"
#include "../../Engine/CollisionManager.h"

InstructionsScene::InstructionsScene()
{
    CollisionManager::ClearCollisionList();
    StaticGameData::ResourcesList.clear();
    
    m_root = new ZoomInEffect();
    AddRootNode(m_root);
    
    m_instructionsImage = new Entity("background", ".\\TestData\\InstructionsTitle.bmp");
    m_root->AddChild(m_instructionsImage);

    m_back_planet = new MainMenuPlanet("Back", ".\\TestData\\planet5.bmp");
    m_root->AddChild(m_back_planet);
    m_back_planet->SetPosition(-350.0f,-300.0f);
    
    const Bullet* playerBullet = new Bullet(".\\TestData\\PlayerBullet.bmp",3,1);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_root->AddChild(m_player_bullet_pool);
    
    m_player = new Player();
    m_player->SetBulletPool(m_player_bullet_pool);
    m_root->AddChild(m_player);
}

void InstructionsScene::Exit()
{
    Scene::Exit();
}
