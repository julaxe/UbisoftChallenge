#pragma once

#include "UIMenuPlanet.h"

class MainMenuPlanet : public UIMenuPlanet
{
public:
    MainMenuPlanet(std::string name, const char* fileName);

    void Update(float dt) override;
};
