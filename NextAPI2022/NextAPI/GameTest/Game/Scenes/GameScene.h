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
#include "../Prefabs/UI/PlayerInterface.h"

class GameScene : public Scene
{
public:
    GameScene();
    void Exit() override;
private:
    SceneNode* m_background;
    Player* m_player;
    BulletPool* m_player_bullet_pool;
    BulletPool* m_turrets_bullet_pool;
    TutorialPlanet* m_tutorial_planet;
    PlayerInterface* m_player_interface;
    Turret* m_turret;

    PauseManager* m_pause_manager;
};
