#include "stdafx.h"
#include "InstructionsScene.h"

InstructionsScene::InstructionsScene()
{
    m_instructionsImage = new Entity("background", ".\\TestData\\InstructionsTitle.bmp");
    AddRootNode(m_instructionsImage);

    m_back_button = new MainMenuButton("back button","Back", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_instructionsImage->AddChild(m_back_button);
    m_back_button->SetPosition(-300.0f,-300.0f);
    m_back_button->SetFocus(true);
}
