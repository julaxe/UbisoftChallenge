#pragma once
#include "StageBase.h"
#include "../Planets/RotatingPlanet.h"
#include "../Resources/CorePlanet.h"

class Stage2 : public StageBase
{
public:
    Stage2();

    void Update(float dt) override;

    void InitializeStage() override;
    bool MissionComplete() override;

private:
    RotatingPlanet* m_rotating_planet;
    CorePlanet* m_corePlanet;
};


