#include "stdafx.h"
#include "StageBase.h"
#include "WormHole.h"
#include "../../StaticGameData.h"
#include "../../../Engine/CollisionManager.h"
#include "../../../Engine/MathManager.h"

StageBase::StageBase()
{
    m_root = new ZoomInEffect();
    AddChild(m_root);

    m_top_wormhole = new WormHole(this);
    m_root->AddChild(m_top_wormhole);
    m_top_wormhole->SetPosition(0.0,390.0f);
    
    m_left_wormhole = new WormHole(this);
    m_root->AddChild(m_left_wormhole);
    m_left_wormhole->SetPosition(-520.0,0.0f);
    
    m_right_wormhole = new WormHole(this);
    m_root->AddChild(m_right_wormhole);
    m_right_wormhole->SetPosition(520.0,0.0f);
    
    m_bottom_wormhole = new WormHole(this);
    m_root->AddChild(m_bottom_wormhole);
    m_bottom_wormhole->SetPosition(0.0,-390.0f);
    
    SetPlayerInitialPosition({0.0f, 300.0f});

    SetWormHolesState(false);
}

void StageBase::Update(float dt)
{
    if(!IsActive()) return;
    if(!IsEnabled()) return;
    SceneNode::Update(dt);
    if(MissionComplete())
    {
        SetWormHolesState(true);
    }
}


void StageBase::SetTopWormHoleConnection(StageBase* stage)
{
    m_top_wormhole->SetStageDestination(stage);
}

void StageBase::SetLeftWormHoleConnection(StageBase* stage)
{
    m_left_wormhole->SetStageDestination(stage);
}

void StageBase::SetRightWormHoleConnection(StageBase* stage)
{
    m_right_wormhole->SetStageDestination(stage);
}

void StageBase::SetBottomWormHoleConnection(StageBase* stage)
{
    m_bottom_wormhole->SetStageDestination(stage);
}
void StageBase::SetWormHolesState(bool unlocked) const
{
    m_top_wormhole->SetUnlocked(unlocked);
    m_left_wormhole->SetUnlocked(unlocked);
    m_right_wormhole->SetUnlocked(unlocked);
    m_bottom_wormhole->SetUnlocked(unlocked);
}

void StageBase::SetPlayer(Player* player)
{
    m_player = player;
    m_player->ChangeParent(m_root);
}

void StageBase::SetPlayerBulletPool(BulletPool* bullet_pool)
{
    m_player_bullet_pool = bullet_pool;
    m_player_bullet_pool->ChangeParent(m_root);
    m_player->SetBulletPool(m_player_bullet_pool);
}

void StageBase::SetTurretsBulletsPool(BulletPool* bullet_pool)
{
    m_turrets_bullet_pool = bullet_pool;
    m_turrets_bullet_pool->ChangeParent(m_root);
}

void StageBase::InitializeStage()
{
    InitializeStaticData();
    SetActive(true);
    RestartZoomAnimation();
    RandomGravity();
}

void StageBase::InitializeStaticData()
{
    StaticGameData::PlayerBulletPool->DisableBullets();
    StaticGameData::TurretsBulletPool->DisableBullets();
    
    SetPlayer(StaticGameData::PlayerRef);
    SetPlayerBulletPool(StaticGameData::PlayerBulletPool);
    SetTurretsBulletsPool(StaticGameData::TurretsBulletPool);

    m_player->SetRespawnPoint(m_player_initial_position);
}

void StageBase::RestartZoomAnimation() const
{
    m_root->Restart();
}

void StageBase::AddATurret(Vector2 position, float angle)
{
    Turret* turret = new Turret();
    m_root->AddChild(turret);
    turret->SetPosition(position.x, position.y);
    turret->SetAngle(angle * PI/180);
    turret->SetBulletPool(m_turrets_bullet_pool);
    m_list_turrets.push_back(turret);
}

void StageBase::AddAFuelTank(Vector2 position, float angle)
{
    FuelTank* fuelTank = new FuelTank();
    m_root->AddChild(fuelTank);
    fuelTank->SetPosition(position.x, position.y);
    fuelTank->SetAngle(angle * PI/180);
    m_list_fuelTanks.push_back(fuelTank);
}

void StageBase::SetPlayerInitialPosition(Vector2 initialPos)
{
    m_player_initial_position = initialPos;
}

void StageBase::RandomGravity()
{
    const float top = 100.0f;
    float randomX = rand()/(float)RAND_MAX * top - 50.0f ;
    float randomY = rand()/(float)RAND_MAX * top - 50.0f;
    m_player->SetGravity({randomX,randomY});
}
