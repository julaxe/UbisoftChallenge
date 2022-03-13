#include "stdafx.h"
#include "MainMenuScene.h"

#include "../StaticGameData.h"
#include "../../Engine/Entity.h"
#include "../../Engine/Button.h"
#include "../../Engine/CollisionManager.h"

MainMenuScene::MainMenuScene()
{
    CollisionManager::ClearCollisionList();
    StaticGameData::ResourcesList.clear();
    
    m_root = new ZoomInEffect();
    AddRootNode(m_root);
    
    m_play_game_planet = new PlayGamePlanet("Play Game", ".\\TestData\\planet1.bmp");
    m_root->AddChild(m_play_game_planet);
    m_play_game_planet->SetPosition(-200.0f,200.0f);

    m_instructions_planet = new InstructionsPlanet("Instructions", ".\\TestData\\planet2.bmp");
    m_root->AddChild(m_instructions_planet);
    m_instructions_planet->SetPosition(200.0f,200.0f);

    m_credits_planet = new CreditsPlanet("Credits", ".\\TestData\\planet3.bmp");
    m_root->AddChild(m_credits_planet);
    m_credits_planet->SetPosition(-200.0f,-200.0f);

    m_quit_game_planet = new QuitGamePlanet("Quit Game", ".\\TestData\\planet4.bmp");
    m_root->AddChild(m_quit_game_planet);
    m_quit_game_planet->SetPosition(200.0f,-200.0f);

    const Bullet* playerBullet = new Bullet(".\\TestData\\PlayerBullet.bmp",3,1);
    m_player_bullet_pool = new BulletPool(new Bullet(*playerBullet));
    m_root->AddChild(m_player_bullet_pool);

    m_player = new Player();
    m_player->SetBulletPool(m_player_bullet_pool);
    m_root->AddChild(m_player);

    m_pause_manager = new PauseManager();
    m_root->AddChild(m_pause_manager);
}

void MainMenuScene::Exit()
{
    Scene::Exit();

    delete m_root;
    m_root = nullptr;

    delete m_player;
    m_player = nullptr;

    delete m_play_game_planet;
    m_play_game_planet = nullptr;

    delete m_instructions_planet;
    m_instructions_planet = nullptr;

    delete m_credits_planet;
    m_credits_planet = nullptr;

    delete m_quit_game_planet;
    m_quit_game_planet = nullptr;

    delete m_pause_manager;
    m_pause_manager = nullptr;

    m_player_bullet_pool = nullptr;
}
