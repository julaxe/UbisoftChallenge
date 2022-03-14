#include "stdafx.h"
#include "WormHole.h"
#include "StageBase.h"
#include "../../StaticGameData.h"

WormHole::WormHole(StageBase* stage_owner)
{
    m_stage_owner = stage_owner;
    std::vector<int> frames;
    for(int i = 0; i < 64; i++)
    {
        frames.push_back(i);
    }

    m_wormhole_sprite_unlocked = new Entity("sprite", ".\\TestData\\wormhole1.bmp", 7,10);
    m_wormhole_sprite_unlocked->CreateAnimation(0, 0.1f,frames);
    m_wormhole_sprite_unlocked->SetAnimation(0);
    AddChild(m_wormhole_sprite_unlocked);
    
    m_wormhole_sprite_locked = new Entity("sprite", ".\\TestData\\wormhole2.bmp",7,10);
    m_wormhole_sprite_locked->CreateAnimation(0, 0.1f,frames);
    m_wormhole_sprite_locked->SetAnimation(0);
    AddChild(m_wormhole_sprite_locked);

    m_collider = new BoxCollider(160.0f, 160.0f);
    m_wormhole_sprite_unlocked->AddChild(m_collider);

    SetScale(0.5f,0.5f);
    SetEnable(false);
    
}

void WormHole::Update(float dt)
{
    SceneNode::Update(dt);
    if(!m_unlocked) return;
    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYER))
    {
        TravelToNextStage();
    }
}

void WormHole::SetStageDestination(StageBase* stage)
{
    m_stage_destination = stage;
    SetEnable(true);
    SetUnlocked(false);
}

void WormHole::SetUnlocked(bool state)
{
    m_unlocked = state;
    if(m_unlocked)
    {
        m_wormhole_sprite_unlocked->SetEnable(true);
        m_wormhole_sprite_locked->SetEnable(false);
    }
    else
    {
        m_wormhole_sprite_unlocked->SetEnable(false);
        m_wormhole_sprite_locked->SetEnable(true);
    }
}

void WormHole::AssignPlayerLocationNextStage()
{
    Vector2 playerPos;
    constexpr float offSet = 100.0f;
    if(this == m_stage_owner->GetTopWormHole())
    {
        playerPos = m_stage_destination->GetBottomWormHole()->GetPosition();
        playerPos = {playerPos.x, playerPos.y + offSet};
        m_stage_destination->SetPlayerInitialPosition(playerPos);
    }
    else if (this == m_stage_owner->GetLeftWormHole())
    {
        playerPos = m_stage_destination->GetRightWormHole()->GetPosition();
        playerPos = {playerPos.x - offSet, playerPos.y};
        m_stage_destination->SetPlayerInitialPosition(playerPos);
    }
    else if (this == m_stage_owner->GetRightWormHole())
    {
        playerPos = m_stage_destination->GetLeftWormHole()->GetPosition();
        playerPos = {playerPos.x + offSet, playerPos.y};
        m_stage_destination->SetPlayerInitialPosition(playerPos);
    }
    else if (this == m_stage_owner->GetBottomWormHole())
    {
        playerPos = m_stage_destination->GetTopWormHole()->GetPosition();
        playerPos = {playerPos.x, playerPos.y - offSet};
        m_stage_destination->SetPlayerInitialPosition(playerPos);
    }
}

void WormHole::TravelToNextStage()
{
    if(!m_stage_destination) return;
    
    m_stage_owner->SetActive(false);
    AssignPlayerLocationNextStage();
    m_stage_destination->InitializeStage();
}
