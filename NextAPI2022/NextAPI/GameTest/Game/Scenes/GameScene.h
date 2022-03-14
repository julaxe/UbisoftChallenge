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
#include "../Prefabs/Stages/StageManager.h"
#include "../Prefabs/UI/PlayerInterface.h"

class GameScene : public Scene
{
public:
    GameScene();
    void Exit() override;
private:
    SceneNode* m_root;
    Player* m_player;
    BulletPool* m_player_bullet_pool;
    BulletPool* m_turrets_bullet_pool;
    StageManager* m_stage_manager;
    PlayerInterface* m_player_interface;

    PauseManager* m_pause_manager;
};
