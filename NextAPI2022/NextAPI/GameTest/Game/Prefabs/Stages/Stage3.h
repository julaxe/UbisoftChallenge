#pragma once
#include "StageBase.h"
#include "../Planets/CircleWithHolePlanet.h"
#include "../Resources/CorePlanet.h"

class Stage3 : public StageBase
{
public:
    Stage3();

    void Update(float dt) override;

    void InitializeStage() override;
    bool MissionComplete() override;

private:
    CircleWithHolePlanet* m_circle_with_hole1;
    CircleWithHolePlanet* m_circle_with_hole2;
    //CircleWithHolePlanet* m_circle_with_hole3;

    CorePlanet* m_corePlanet;
};
