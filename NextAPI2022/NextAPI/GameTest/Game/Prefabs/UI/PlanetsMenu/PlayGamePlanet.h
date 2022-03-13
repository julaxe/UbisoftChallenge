#pragma once
#include "UIMenuPlanet.h"

class PlayGamePlanet : public UIMenuPlanet
{
public:
    PlayGamePlanet(std::string name, const char* fileName);

    void Update(float dt) override;
};
