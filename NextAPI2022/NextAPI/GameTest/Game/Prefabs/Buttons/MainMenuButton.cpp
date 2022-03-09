#include "stdafx.h"
#include "MainMenuButton.h"

#include "../../../Engine/SceneManager.h"
#include "../../Scenes/MainMenuScene.h"

MainMenuButton::MainMenuButton(std::string name, const char* fileNameActive, const char* fileNameInactive) : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("MainMenuText", "Main Menu");
    AddChild(m_text);
}

void MainMenuButton::OnClick()
{
    SceneManager::ChangeScene(new MainMenuScene());
}
