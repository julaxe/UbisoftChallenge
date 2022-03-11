#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Scene.h"
#include "../Prefabs/Bullets/Bullet.h"
#include "../Prefabs/UI/PauseManager.h"
#include "../Prefabs/UI/Buttons/MainMenuButton.h"
#include "../Prefabs/Player/Player.h"

class GameScene : public Scene
{
public:
    GameScene();
    void Exit() override;
private:
    Entity* m_background;
    Player* m_player;
    BoxCollider* m_testCollider;
    Bullet* m_bulletTest;
    

    PauseManager* m_pause_manager;
};
