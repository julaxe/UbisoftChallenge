#include "stdafx.h"
#include "ResumeManager.h"

#include <iostream>

#include "../../../App/app.h"
#include "../../../Engine/SceneManager.h"
#include "../../Scenes/PauseScene.h"

void ResumeManager::HandleInput()
{
    if(App::GetController().CheckButton(XINPUT_GAMEPAD_START,true))
    {
        SceneManager::PopScene();
        for(const auto scene: SceneManager::GetScenes())
        {
            scene->SetPause(false);
        }
    }
}

void ResumeManager::Update(float dt)
{
    HandleInput();
}
