#include "stdafx.h"
#include "FuelTank.h"

#include "../../StaticGameData.h"

FuelTank::FuelTank()
{
    m_sprite = new Entity("sprite", ".\\TestData\\FuelTank.bmp");
    AddChild(m_sprite);

    m_tag = ResourceTag::FUELTANK;
}

