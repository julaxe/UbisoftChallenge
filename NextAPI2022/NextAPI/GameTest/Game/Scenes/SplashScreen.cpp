#include "stdafx.h"
#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
    m_ubisoftLogo = new SplashImage();
    AddRootNode(m_ubisoftLogo);
}

void SplashScreen::Exit()
{
    Scene::Exit();

    delete m_ubisoftLogo;
    m_ubisoftLogo = nullptr;
}
