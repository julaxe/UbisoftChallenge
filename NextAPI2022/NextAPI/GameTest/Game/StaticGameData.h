#pragma once
#include "Prefabs/Player/Player.h"
#include "Prefabs/Resources/FuelTank.h"
#include "Prefabs/Resources/Resource.h"

class StaticGameData
{
public:
    static int PlayerLives;
    static int PlayerFuel;
    static int PlayerScore;
    static int PlayerBonusScore;
    static bool DataChanged;
    static Player* PlayerRef;
    static BulletPool* PlayerBulletPool;
    static BulletPool* TurretsBulletPool;
    static BulletPool* BossBulletPool;
    static std::vector<Resource*> ResourcesList;

    static void KillPlayer();
    static void UseFuel(int amount);
    static void GetFuelTank(int amount);
    
};
