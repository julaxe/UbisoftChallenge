#include "stdafx.h"
#include "ResumeButton.h"

#include "../../../../Engine/SceneManager.h"

ResumeButton::ResumeButton(std::string name, const char* text, const char* fileNameActive,
                             const char* fileNameInactive) : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("ResumeText", text);
    AddChild(m_text);
    
    const float newPosX = m_text->GetWidth()*0.5f;
    m_text->SetPosition(-newPosX, -4.0f);
}

void ResumeButton::Exit()
{
    Button::Exit();

    delete m_text;
    m_text = nullptr;
}

void ResumeButton::OnClick()
{
    SceneManager::PopScene();
    for(const auto scene: SceneManager::GetScenes())
    {
        if(scene)
            scene->SetPause(false);
    }
}
