#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/UI/Buttons/MainMenuButton.h"
class InstructionsScene : public Scene
{
public:
    InstructionsScene();

private:
    Entity* m_instructionsImage;
    MainMenuButton* m_back_button;
};