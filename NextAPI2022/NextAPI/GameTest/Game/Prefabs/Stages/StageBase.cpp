#include "stdafx.h"
#include "StageBase.h"
#include "WormHole.h"
#include "../../StaticGameData.h"
#include "../../../Engine/CollisionManager.h"

StageBase::StageBase()
{
    CollisionManager::ClearCollisionList();
    StaticGameData::ResourcesList.clear();
    
    m_root = new ZoomInEffect();
    AddChild(m_root);

    m_top_wormhole = new WormHole();
    m_root->AddChild(m_top_wormhole);
    m_top_wormhole->SetPosition(0.0,300.0f);
    
    m_left_wormhole = new WormHole();
    m_root->AddChild(m_left_wormhole);
    m_left_wormhole->SetPosition(-300.0,0.0f);
    
    m_right_wormhole = new WormHole();
    m_root->AddChild(m_right_wormhole);
    m_right_wormhole->SetPosition(300.0,0.0f);
    
    m_bottom_wormhole = new WormHole();
    m_root->AddChild(m_bottom_wormhole);
    m_bottom_wormhole->SetPosition(0.0,-300.0f);

    Bullet* playerBullet = new Bullet(".\\TestData\\PlayerBullet.bmp",3,1);
    playerBullet->SetTag(CollisionTag::PLAYERBULLET);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_root->AddChild(m_player_bullet_pool);

    const Bullet* turretBullet = new Bullet(".\\TestData\\TurretBullet.bmp",1,1);
    turretBullet->SetTag(CollisionTag::ENEMYBULLET);
    m_turrets_bullet_pool = new BulletPool(new Bullet(*turretBullet));
    m_root->AddChild(m_turrets_bullet_pool);

    m_player = new Player();
    m_root->AddChild(m_player);
    m_player->SetRespawnPoint({0.0f,0.0f});
}
