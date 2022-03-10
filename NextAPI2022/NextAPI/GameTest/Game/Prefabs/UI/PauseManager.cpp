#include "stdafx.h"
#include "PauseManager.h"

#include <iostream>

#include "../../../App/app.h"
#include "../../../Engine/SceneManager.h"
#include "../../Scenes/PauseScene.h"

void PauseManager::HandleInput()
{
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_START,true))
    {
        for(const auto scene: SceneManager::GetScenes())
        {
            if(scene)
                scene->SetPause(true);
        }
        SceneManager::AddScene(new PauseScene());
    }
}

void PauseManager::Update(float dt)
{
    HandleInput();
}
