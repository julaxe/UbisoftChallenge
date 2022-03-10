#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/Buttons/MainMenuButton.h"

class CreditsScene : public Scene
{
public:
    CreditsScene();

private:
    Entity* m_creditsImage;
    MainMenuButton* m_back_button;
};
