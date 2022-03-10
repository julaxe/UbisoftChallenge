#pragma once
#include "../../Engine/Scene.h"
#include "../Prefabs/SplashImage.h"

class SplashScreen : public Scene
{
public:
    SplashScreen();

private:
    SplashImage* m_ubisoftLogo;
};
