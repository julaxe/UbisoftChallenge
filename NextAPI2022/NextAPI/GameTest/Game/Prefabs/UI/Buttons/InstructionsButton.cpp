#include "stdafx.h"
#include "InstructionsButton.h"

#include "../../../../Engine/SceneManager.h"
#include "../../../Scenes/InstructionsScene.h"

InstructionsButton::InstructionsButton(std::string name, const char* text, const char* fileNameActive,
                                       const char* fileNameInactive) : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("InstructionText", text);
    AddChild(m_text);
    
    const float newPosX = m_text->GetWidth()*0.5f;
    m_text->SetPosition(-newPosX, -4.0f);
}

void InstructionsButton::OnClick()
{
    SceneManager::ChangeScene(new InstructionsScene());
}
