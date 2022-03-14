#include "stdafx.h"
#include "StaticGameData.h"

#include "../App/app.h"

int StaticGameData::PlayerLives = 5;
int StaticGameData::PlayerFuel = 9999;
int StaticGameData::PlayerScore = 0;
int StaticGameData::PlayerBonusScore = 0;
bool StaticGameData::DataChanged = false;
Player* StaticGameData::PlayerRef = nullptr;
BulletPool* StaticGameData::PlayerBulletPool = nullptr;
BulletPool* StaticGameData::TurretsBulletPool = nullptr;
BulletPool* StaticGameData::BossBulletPool = nullptr;
std::vector<Resource*> StaticGameData::ResourcesList;

void StaticGameData::KillPlayer()
{
    PlayerLives -= 1;
    PlayerRef->GoToRespawnPoint();
    DataChanged = true;
    App::PlaySoundEffect(".\\TestData\\Explosion.wav");
}

void StaticGameData::UseFuel(int amount)
{
    PlayerFuel-= amount;
    DataChanged = true;
}

void StaticGameData::GetFuelTank(int amount)
{
    PlayerFuel+= amount;
    PlayerScore+=50;
    DataChanged = true;
}
