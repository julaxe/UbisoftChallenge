#pragma once
#include "../../Engine/Scene.h"
#include "../Prefabs/UI/SplashImage.h"

class SplashScreen : public Scene
{
public:
    SplashScreen();

    void Exit() override;

private:
    SplashImage* m_ubisoftLogo;
};
