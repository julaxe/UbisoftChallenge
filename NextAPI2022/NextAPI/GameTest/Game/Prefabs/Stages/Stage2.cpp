#include "stdafx.h"
#include "Stage2.h"

Stage2::Stage2()
{
    m_rotating_planet = new RotatingPlanet();
    m_root->AddChild(m_rotating_planet);

    m_corePlanet = new CorePlanet();
    m_root->AddChild(m_corePlanet);
}

void Stage2::Update(float dt)
{
    StageBase::Update(dt);
    
    const float rotSpeed = 0.1f * dt * 0.001f;
    if(m_corePlanet->IsEnabled())
    {
        m_rotating_planet->SetAngle(m_rotating_planet->GetAngle() + rotSpeed);
    }
    else
    {
        m_rotating_planet->SetAngle(m_rotating_planet->GetAngle() - rotSpeed);
    }
    
}
void Stage2::InitializeStage()
{
    StageBase::InitializeStage();
    
    //m_player->SetGravity({0.0f,50.0f});
}
bool Stage2::MissionComplete()
{
    if(m_corePlanet->IsEnabled())
    {
        return false;
    }
    return true;
}
