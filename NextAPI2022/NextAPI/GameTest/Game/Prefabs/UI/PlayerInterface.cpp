#include "stdafx.h"
#include "PlayerInterface.h"

#include "../../StaticGameData.h"

PlayerInterface::PlayerInterface()
{
    m_player_lives = new Text("player lives", "Lives: " + std::to_string(StaticGameData::PlayerLives));
    AddChild(m_player_lives);
    m_player_lives->SetPosition(-400.0f, 350.0f);

    m_player_fuel = new Text("player fuel", "Fuel: " + std::to_string(StaticGameData::PlayerFuel));
    AddChild(m_player_fuel);
    m_player_fuel->SetPosition(-400.0f, 300.0f);

    m_player_score = new Text("player score", "Score: " + std::to_string(StaticGameData::PlayerScore));
    AddChild(m_player_score);
    m_player_score->SetPosition(-100.0f, 350.0f);

    m_player_bonus_score = new Text("player bonus score", "Bonus: " + std::to_string(StaticGameData::PlayerBonusScore));
    AddChild(m_player_bonus_score);
    m_player_bonus_score->SetPosition(200.0f, 350.0f);
}

void PlayerInterface::Update(float dt)
{
    SceneNode::Update(dt);
    if(!StaticGameData::DataChanged) return;
    
    m_player_lives->SetText("Lives: " + std::to_string(StaticGameData::PlayerLives));

    m_player_fuel->SetText("Fuel: " + std::to_string(StaticGameData::PlayerFuel));
    
    m_player_score->SetText("Score: " + std::to_string(StaticGameData::PlayerScore));
    
    m_player_bonus_score->SetText("Bonus: " + std::to_string(StaticGameData::PlayerBonusScore));

    StaticGameData::DataChanged = false;
}

void PlayerInterface::Exit()
{
    SceneNode::Exit();
    
    delete m_player_lives;
    m_player_lives = nullptr;

    delete m_player_fuel;
    m_player_fuel = nullptr;
    
    delete m_player_score;
    m_player_score = nullptr;
    
    delete m_player_bonus_score;
    m_player_bonus_score = nullptr;
}
