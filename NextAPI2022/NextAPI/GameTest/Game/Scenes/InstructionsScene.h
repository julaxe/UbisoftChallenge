#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/Player/Player.h"
#include "../Prefabs/UI/ZoomInEffect.h"
#include "../Prefabs/UI/PlanetsMenu/MainMenuPlanet.h"

class InstructionsScene : public Scene
{
public:
    InstructionsScene();
    void Exit() override;

private:
    BulletPool* m_player_bullet_pool;
    Player* m_player;
    ZoomInEffect* m_root;
    Entity* m_instructionsImage;
    MainMenuPlanet* m_back_planet;
};
