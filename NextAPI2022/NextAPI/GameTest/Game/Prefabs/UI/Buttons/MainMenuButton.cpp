#include "stdafx.h"
#include "MainMenuButton.h"

#include "../../../../Engine/SceneManager.h"
#include "../../../Scenes/MainMenuScene.h"

MainMenuButton::MainMenuButton(std::string name,const char* text,  const char* fileNameActive, const char* fileNameInactive) : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("MainMenuText", text);
    AddChild(m_text);
    const float newPosX = m_text->GetWidth()*0.5f;
    m_text->SetPosition(-newPosX, -4.0f);
}

void MainMenuButton::OnClick()
{
    SceneManager::ChangeScene(new MainMenuScene());
}
