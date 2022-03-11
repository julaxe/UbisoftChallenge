#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/UI/Buttons/MainMenuButton.h"

class CreditsScene : public Scene
{
public:
    CreditsScene();
    void Exit() override;

private:
    Entity* m_creditsImage;
    MainMenuButton* m_back_button;
};
