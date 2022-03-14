#include "stdafx.h"
#include "Stage1.h"

Stage1::Stage1()
{
    m_planet = new TutorialPlanet();
    m_planet->SetScale(2.0f,2.0f);
    m_root->AddChild(m_planet);
    
    
    AddATurret({100.0f,170.0f}, 0.0f);
    AddATurret({-100.0f,65.0f}, 42.0f);
    AddATurret({-110.0f,-110.0f}, 208.0f);
    AddATurret({90.0f,-95.0f}, 200.0f);

    AddAFuelTank({100.0f,150.0f}, 0.0f);
    AddAFuelTank({-112.0f,30.0f}, 42.0f);
    AddAFuelTank({-138.0f,-100.0f}, 208.0f);
    AddAFuelTank({90.0f,-47.0f}, 205.0f);
}

bool Stage1::MissionComplete()
{
    for(const auto turret: m_list_turrets)
    {
        if(turret->IsEnabled())
        {
            return false;
        }
    }
    return true;
}
