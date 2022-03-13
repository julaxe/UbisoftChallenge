#include "stdafx.h"
#include "FuelTank.h"

#include "../../StaticGameData.h"

FuelTank::FuelTank()
{
    m_fueltank_sprite = new Entity("sprite", ".\\TestData\\FuelTank.bmp");
    AddChild(m_fueltank_sprite);
    
    StaticGameData::ResourcesList.push_back(this);
}

void FuelTank::Update(float dt)
{
    SceneNode::Update(dt);
}
