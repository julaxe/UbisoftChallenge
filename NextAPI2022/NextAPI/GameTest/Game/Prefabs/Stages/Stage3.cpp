#include "stdafx.h"
#include "Stage3.h"

Stage3::Stage3()
{
    m_circle_with_hole1 = new CircleWithHolePlanet();
    m_root->AddChild(m_circle_with_hole1);

    m_circle_with_hole2 = new CircleWithHolePlanet();
    m_circle_with_hole2->SetScale(0.55f,0.55f);
    m_circle_with_hole2->SetAngle(60.0f);
    m_root->AddChild(m_circle_with_hole2);

    // m_circle_with_hole3 = new CircleWithHolePlanet();
    // m_circle_with_hole3->SetScale(0.25f,0.25f);
    // m_circle_with_hole2->SetAngle(120.0f);
    // m_root->AddChild(m_circle_with_hole3);

    m_corePlanet = new CorePlanet();
    m_root->AddChild(m_corePlanet);
    
}

void Stage3::Update(float dt)
{
    StageBase::Update(dt);
    const float rotSpeed = 0.4f * dt * 0.001f;
    if(m_corePlanet->IsEnabled())
    {
        m_circle_with_hole1->SetAngle(m_circle_with_hole1->GetAngle() + rotSpeed*0.2f);
        m_circle_with_hole2->SetAngle(m_circle_with_hole2->GetAngle() - rotSpeed*0.5f);
       // m_circle_with_hole3->SetAngle(m_circle_with_hole3->GetAngle() + rotSpeed);
    }
    else
    {
        m_circle_with_hole1->SetAngle(m_circle_with_hole1->GetAngle() - rotSpeed*0.2f);
        m_circle_with_hole2->SetAngle(m_circle_with_hole2->GetAngle() + rotSpeed*0.5f);
       // m_circle_with_hole3->SetAngle(m_circle_with_hole3->GetAngle() - rotSpeed);
    }
}

void Stage3::InitializeStage()
{
    StageBase::InitializeStage();
}

bool Stage3::MissionComplete()
{
    if(m_corePlanet->IsEnabled())
    {
        return false;
    }
    return true;
}
