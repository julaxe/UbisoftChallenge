#include "stdafx.h"
#include "StaticGameData.h"

int StaticGameData::PlayerLives = 5;
int StaticGameData::PlayerFuel = 9999;
int StaticGameData::PlayerScore = 0;
int StaticGameData::PlayerBonusScore = 0;
bool StaticGameData::DataChanged = false;
Player* StaticGameData::PlayerRef = nullptr;

void StaticGameData::KillPlayer()
{
    PlayerLives -= 1;
    PlayerRef->GoToRespawnPoint();
    DataChanged = true;
}

void StaticGameData::UseFuel(int amount)
{
    PlayerFuel-= amount;
    DataChanged = true;
}
