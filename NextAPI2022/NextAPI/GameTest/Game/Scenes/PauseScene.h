#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/UI/ResumeManager.h"
#include "../Prefabs/UI/Buttons/GameSceneButton.h"
#include "../Prefabs/UI/Buttons/MainMenuButton.h"
#include "../Prefabs/UI/Buttons/NavigationButtons.h"
#include "../Prefabs/UI/Buttons/ResumeButton.h"

class PauseScene : public Scene
{
public:
    PauseScene();
    void Exit() override;

private:
    Entity* m_blurryBackground;
    NavigationButtons* m_navigation_buttons;
    ResumeButton* m_resume_button;
    GameSceneButton* m_restart_button;
    MainMenuButton* m_main_menu_button;
    ResumeManager* m_resume_manager;
};
