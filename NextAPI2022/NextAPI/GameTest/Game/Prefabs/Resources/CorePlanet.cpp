#include "stdafx.h"
#include "CorePlanet.h"

CorePlanet::CorePlanet()
{
    m_sprite = new Entity("sprite", ".\\TestData\\Core.bmp", 3,4);
    m_sprite->CreateAnimation(0,0.1f,{0,1,2});
    m_sprite->SetAnimation(0);
    AddChild(m_sprite);

    SetScale(0.6f,0.6f);
    m_tag = ResourceTag::CORE;
}
