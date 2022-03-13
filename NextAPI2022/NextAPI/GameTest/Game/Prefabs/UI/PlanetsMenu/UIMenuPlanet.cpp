#include "stdafx.h"
#include "UIMenuPlanet.h"

UIMenuPlanet::UIMenuPlanet(std::string name, const char* fileName)
{
    m_planet_sprite = new Entity(fileName);
    AddChild(m_planet_sprite);

    m_collider = new BoxCollider(40.f,40.f);
    AddChild(m_collider);

    m_text = new Text(name, name);
    AddChild(m_text);
}

void UIMenuPlanet::Exit()
{
    SceneNode::Exit();

    delete m_planet_sprite;
    m_planet_sprite = nullptr;
    
    delete m_collider;
    m_collider = nullptr;
    
    delete m_text;
    m_text = nullptr;
}
