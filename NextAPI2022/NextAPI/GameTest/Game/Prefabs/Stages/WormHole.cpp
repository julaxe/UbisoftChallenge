#include "stdafx.h"
#include "WormHole.h"
#include "StageBase.h"

WormHole::WormHole()
{
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

    m_collider = new BoxCollider(40.0f, 40.0f);
    AddChild(m_collider);

    m_wormhole_sprite_locked->SetActive(false);
}

void WormHole::SetStageDestination(StageBase* stage)
{
    m_stage_destination = stage;
}

void WormHole::SetUnlocked(bool state)
{
    m_unlocked = state;
}
