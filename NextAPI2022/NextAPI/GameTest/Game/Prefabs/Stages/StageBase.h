#pragma once
#include "../../../Engine/SceneNode.h"
#include "../Player/Player.h"
#include "../UI/ZoomInEffect.h"
class WormHole;

class StageBase : public SceneNode
{
public:
    StageBase();

private:
    ZoomInEffect* m_root;
    
    WormHole* m_top_wormhole;
    WormHole* m_left_wormhole;
    WormHole* m_right_wormhole;
    WormHole* m_bottom_wormhole;

    Player* m_player;
    BulletPool* m_player_bullet_pool;
    BulletPool* m_turrets_bullet_pool;

    
};
