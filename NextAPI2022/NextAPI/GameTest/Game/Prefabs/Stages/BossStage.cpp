#include "stdafx.h"
#include "BossStage.h"

#include "../../StaticGameData.h"
#include "../../../app/app.h"
#include "../../../Engine/MathManager.h"

BossStage::BossStage()
{
    m_boss_planet = new BossPlanet();
    m_root->AddChild(m_boss_planet);

    m_boss_hearth = new BossHearth();
    m_root->AddChild(m_boss_hearth);
    
    SetActive(true);
    
}

void BossStage::Update(float dt)
{
    StageBase::Update(dt);
    if(!m_player) return;
    if(!App::IsSoundPlaying(".\\TestData\\Boss.wav"))
    {
        App::StopSound(".\\TestData\\Stage1.wav");
        App::PlaySoundEffect(".\\TestData\\Boss.wav", true);
    }
    Vector2 gravityDirection = MathManager::GetDirectionBetweenVectors(m_boss_planet->GetWorldPosition(), m_player->GetWorldPosition());
    float distance = MathManager::GetMagnitudeOfVector(gravityDirection);
    Vector2 gravityDirectionNormalized = MathManager::NormalizeVector(gravityDirection);
    float gravityForce = m_repulsion_force * (1.0f - distance/static_cast<float>(APP_VIRTUAL_HEIGHT)*0.5f);
    Vector2 newGravityForce = {gravityDirectionNormalized.x * gravityForce, gravityDirectionNormalized.y * gravityForce};
    m_player->SetGravity(newGravityForce);
}

bool BossStage::MissionComplete()
{
    return StageBase::MissionComplete();
}
