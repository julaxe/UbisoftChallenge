#include "stdafx.h"
#include "CreditsButton.h"

#include "../../../../Engine/SceneManager.h"
#include "../../../Scenes/CreditsScene.h"

CreditsButton::CreditsButton(std::string name, const char* text, const char* fileNameActive,
                             const char* fileNameInactive) : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("CreditsText", text);
    AddChild(m_text);
    
    const float newPosX = m_text->GetWidth()*0.5f;
    m_text->SetPosition(-newPosX, -4.0f);
}

void CreditsButton::Exit()
{
    Button::Exit();

    delete m_text;
    m_text = nullptr;
}

void CreditsButton::OnClick()
{
    SceneManager::ChangeScene(new CreditsScene());
}
