#pragma once
#include "Prefabs/Player/Player.h"
#include "Prefabs/Resources/FuelTank.h"

class StaticGameData
{
public:
    static int PlayerLives;
    static int PlayerFuel;
    static int PlayerScore;
    static int PlayerBonusScore;
    static bool DataChanged;
    static Player* PlayerRef;
    static std::vector<FuelTank*> ResourcesList;

    static void KillPlayer();
    static void UseFuel(int amount);
    static void GetFuelTank(int amount);
    
};
