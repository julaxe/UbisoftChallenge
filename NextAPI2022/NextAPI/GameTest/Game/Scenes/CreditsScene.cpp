#include "stdafx.h"
#include "CreditsScene.h"

CreditsScene::CreditsScene()
{
    m_creditsImage = new Entity("background", ".\\TestData\\CreditsTitle.bmp");
    AddRootNode(m_creditsImage);

    m_back_button = new MainMenuButton("back button","Back", ".\\TestData\\Button01.bmp", ".\\TestData\\Button02.bmp");
    m_creditsImage->AddChild(m_back_button);
    m_back_button->SetPosition(-300.0f,-300.0f);
    m_back_button->SetFocus(true);
    
}
