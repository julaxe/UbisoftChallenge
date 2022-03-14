#pragma once
#include "StageBase.h"
#include "../Planets/TutorialPlanet.h"

class Stage1 : public StageBase
{
public:
    Stage1();

    bool MissionComplete() override;

private:
    TutorialPlanet* m_planet;
};
