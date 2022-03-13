#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Line.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/Bullets/Bullet.h"
#include "../Prefabs/Enemies/Turret.h"
#include "../Prefabs/Planets/TutorialPlanet.h"
#include "../Prefabs/UI/PauseManager.h"
#include "../Prefabs/UI/Buttons/MainMenuButton.h"
#include "../Prefabs/Player/Player.h"
#include "../Prefabs/Resources/FuelTank.h"
#include "../Prefabs/Stages/StageBase.h"
#include "../Prefabs/UI/PlayerInterface.h"

class GameScene : public Scene
{
public:
    GameScene();
    void Exit() override;
private:
    StageBase* m_stage;
    PlayerInterface* m_player_interface;

    PauseManager* m_pause_manager;
};
