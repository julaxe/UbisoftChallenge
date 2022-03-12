#pragma once
#include "../../Engine/Entity.h"
#include "../../Engine/Line.h"
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
    BulletPool* m_player_bullet_pool;
    Line* m_line;

    PauseManager* m_pause_manager;
};
