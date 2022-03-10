#include "stdafx.h"
#include "GameSceneButton.h"

#include "../../../Engine/SceneManager.h"
#include "../../../Engine/Text.h"
#include "../../Scenes/GameScene.h"

GameSceneButton::GameSceneButton(std::string name, const char* text, const char* fileNameActive, const char* fileNameInactive)  : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("GameSceneText", text);
    SetScale(0.5f,0.5f);
    AddChild(m_text);

    m_spriteInactive->SetAlpha(0.5f);
    //set position of text
    float newPosX = m_text->GetWidth()*0.5f;
    m_text->SetPosition(-newPosX, -4.0f);
}

void GameSceneButton::OnClick()
{
    SceneManager::ChangeScene(new GameScene());
}
