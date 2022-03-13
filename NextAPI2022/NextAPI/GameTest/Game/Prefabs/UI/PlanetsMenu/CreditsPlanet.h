#pragma once

#include "UIMenuPlanet.h"

class CreditsPlanet : public UIMenuPlanet
{
public:
    CreditsPlanet(std::string name, const char* fileName);

    void Update(float dt) override;
};
