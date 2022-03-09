#include "stdafx.h"
#include "Button.h"

#include "CollisionManager.h"
#include "Entity.h"

Button::Button(std::string name, const char* fileNameActive, const char* fileNameInactive)
{
    m_name = name;
    m_spriteActive = new Entity(fileNameActive);
    m_spriteInactive = new Entity(fileNameInactive);

    AddChild(m_spriteActive);
    AddChild(m_spriteInactive);
}

void Button::HandleInput()
{
    if(CollisionManager::isMouseInsideRectangle(GetWorldPosition().x, GetWorldPosition().y, m_spriteInactive->GetWidth(), m_spriteInactive->GetHeight()))
    {
        m_isActive = true;
    }
    else
    {
        m_isActive = false;
    }
}

void Button::Update(float dt)
{
    HandleInput();
    if(m_isActive)
    {
        m_spriteActive->SetActive(true);
        m_spriteInactive->SetActive(false);
    }
    else
    {
        m_spriteActive->SetActive(false);
        m_spriteInactive->SetActive(true);
    }
    UpdateChildren(dt);
    
}

void Button::Draw()
{
    DrawChildren();
}
