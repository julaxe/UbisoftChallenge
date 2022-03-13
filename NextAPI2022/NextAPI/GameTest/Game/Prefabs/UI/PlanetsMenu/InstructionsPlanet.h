#pragma once

#include "UIMenuPlanet.h"

class InstructionsPlanet : public UIMenuPlanet
{
public:
    InstructionsPlanet(std::string name, const char* fileName);

    void Update(float dt) override;
};