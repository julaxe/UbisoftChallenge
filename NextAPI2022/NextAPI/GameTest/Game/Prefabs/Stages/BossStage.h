#pragma once
#include "StageBase.h"
#include "../Enemies/BossHearth.h"
#include "../Planets/BossPlanet.h"

class BossStage: public StageBase
{
public:
    BossStage();

    void Update(float dt) override;

    bool MissionComplete() override;

private:
    BossPlanet* m_boss_planet;
    BossHearth* m_boss_hearth;
    float m_repulsion_force = 100.0f;
};
