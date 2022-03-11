#include "stdafx.h"
#include "GameSceneButton.h"

#include "../../../../Engine/SceneManager.h"
#include "../../../../Engine/Text.h"
#include "../../../Scenes/GameScene.h"

GameSceneButton::GameSceneButton(std::string name, const char* text, const char* fileNameActive, const char* fileNameInactive)  : Button(name, fileNameActive, fileNameInactive)
{
    m_text = new Text("GameSceneText", text);
    AddChild(m_text);
    
    //set position of text
    const float newPosX = m_text->GetWidth()*0.5f;
    m_text->SetPosition(-newPosX, -4.0f);
}

void GameSceneButton::Exit()
{
    Button::Exit();

    delete m_text;
    m_text = nullptr;
}

void GameSceneButton::OnClick()
{
    SceneManager::ChangeScene(new GameScene());
}
