#include "stdafx.h"
#include "NavigationButtons.h"

#include "../../../../App/app.h"

NavigationButtons::NavigationButtons()
{
}

void NavigationButtons::HandleInput()
{
    if(m_vertical_navigation)
    {
        if(App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, true))
        {
            NavigateToPreviousButton();
        }
        else if(App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, true))
        {
            NavigateToNextButton();
        }
    }
    else
    {
        if(App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, true))
        {
            NavigateToNextButton();
        }
        else if(App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, true))
        {
            NavigateToPreviousButton();
        }
    }
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
    {
        m_buttonList[m_current_focused_button]->OnClick();
    }
}

void NavigationButtons::Update(float dt)
{
    HandleInput();
    UpdateChildren(dt);
}

void NavigationButtons::Draw()
{
    DrawChildren();
}

void NavigationButtons::AddButton(Button* button)
{
    AddChild(button);
    m_buttonList.push_back(button);
    if(m_buttonList.size() == 1)
    {
        button->SetFocus(true);
    }
}

void NavigationButtons::NavigateToNextButton()
{
    m_buttonList[m_current_focused_button]->SetFocus(false);
    m_current_focused_button += 1;
    if(m_current_focused_button >= m_buttonList.size())
    {
        m_current_focused_button = 0;
    }
    m_buttonList[m_current_focused_button]->SetFocus(true);
}

void NavigationButtons::NavigateToPreviousButton()
{
    m_buttonList[m_current_focused_button]->SetFocus(false);
    m_current_focused_button -= 1;
    if(m_current_focused_button < 0)
    {
        m_current_focused_button = m_buttonList.size() - 1;
    }
    m_buttonList[m_current_focused_button]->SetFocus(true);
}


Button* NavigationButtons::GetCurrentButton()
{
    return m_buttonList[m_current_focused_button];
}

void NavigationButtons::SetHorizontalLayout(float offset)
{
    m_vertical_navigation = false;
    m_horizontal_offset = offset;
    if(m_buttonList.size() == 0) return;
    for(int i = 1; i < m_buttonList.size(); i++)
    {
        const float newPosX = m_buttonList[i-1]->GetPosition().x + (m_buttonList[i-1]->GetWidth() * m_buttonList[i-1]->GetWorldScale().x)  + m_horizontal_offset;
        m_buttonList[i]->SetPosition(newPosX, 0.0f);
    }
}

void NavigationButtons::SetVerticalLayout(float offset)
{
    m_vertical_navigation = true;
    m_vertical_offset = offset;
    if(m_buttonList.size() == 0) return;
    for(int i = 1; i < m_buttonList.size(); i++)
    {
        const float newPosY = m_buttonList[i-1]->GetPosition().y - m_buttonList[i-1]->GetHeight() * m_buttonList[i-1]->GetWorldScale().y - m_vertical_offset;
        m_buttonList[i]->SetPosition(0.0f, newPosY);
    }
}
