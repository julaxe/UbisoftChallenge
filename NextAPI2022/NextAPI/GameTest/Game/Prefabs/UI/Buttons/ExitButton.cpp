#include "stdafx.h"
#include "ExitButton.h"

ExitButton::ExitButton(std::string name, const char* text, const char* fileNameActive, const char* fileNameInactive) : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("ExitText", text);
    AddChild(m_text);
    
    const float newPosX = m_text->GetWidth()*0.5f;
    m_text->SetPosition(-newPosX, -4.0f);
}

void ExitButton::OnClick()
{
    exit(0);
}
