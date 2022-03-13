#pragma once

#include "UIMenuPlanet.h"

class QuitGamePlanet : public UIMenuPlanet
{
public:
    QuitGamePlanet(std::string name, const char* fileName);

    void Update(float dt) override;
};
