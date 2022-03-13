#pragma once
#include "../../Engine/Scene.h"
#include "../Prefabs/Player/Player.h"
#include "../Prefabs/UI/PauseManager.h"
#include "../Prefabs/UI/ZoomInEffect.h"
#include "../Prefabs/UI/PlanetsMenu/CreditsPlanet.h"
#include "../Prefabs/UI/PlanetsMenu/InstructionsPlanet.h"
#include "../Prefabs/UI/PlanetsMenu/PlayGamePlanet.h"
#include "../Prefabs/UI/PlanetsMenu/QuitGamePlanet.h"


class ExitButton;
class InstructionsButton;
class CreditsButton;
class NavigationButtons;
class Entity;
class GameSceneButton;

class MainMenuScene :public Scene
{
public:
    MainMenuScene();
    void Exit() override;
private:
    ZoomInEffect* m_root;
    BulletPool* m_player_bullet_pool;
    Player* m_player;
    PlayGamePlanet* m_play_game_planet;
    InstructionsPlanet* m_instructions_planet;
    CreditsPlanet* m_credits_planet;
    QuitGamePlanet* m_quit_game_planet;

    PauseManager* m_pause_manager;
};
