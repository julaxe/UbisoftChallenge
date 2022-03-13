#pragma once
#include "Prefabs/Player/Player.h"

class StaticGameData
{
public:
    static int PlayerLives;
    static int PlayerFuel;
    static int PlayerScore;
    static int PlayerBonusScore;
    static bool DataChanged;
    static Player* PlayerRef;

    static void KillPlayer();
    static void UseFuel(int amount);
};
