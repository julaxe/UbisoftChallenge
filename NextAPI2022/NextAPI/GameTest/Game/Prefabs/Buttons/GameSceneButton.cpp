#include "stdafx.h"
#include "GameSceneButton.h"

#include "../../../Engine/SceneManager.h"
#include "../../../Engine/Text.h"
#include "../../Scenes/GameScene.h"

GameSceneButton::GameSceneButton(std::string name, const char* fileNameActive, const char* fileNameInactive)  : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("GameSceneText", "Play Game");
    AddChild(m_text);
}

void GameSceneButton::OnClick()
{
    SceneManager::ChangeScene(new GameScene());
}
