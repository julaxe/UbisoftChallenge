#include "stdafx.h"
#include "Button.h"

#include <iostream>

#include "CollisionManager.h"
#include "Entity.h"
#include "../App/app.h"

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
    if(m_isFocused)
    {
        if(App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
        {
            OnClick();
            std::cout << "Button pressed! " << std::endl;
        }
    }
}

void Button::Update(float dt)
{
    HandleInput();
    if(m_isFocused)
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

void Button::SetFocus(bool state)
{
    m_isFocused = state;
}
