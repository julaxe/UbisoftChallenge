#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

class StageBase;
class WormHole : public SceneNode
{
public:
    WormHole();

    void SetStageDestination(StageBase* stage);
    void SetUnlocked(bool state);

private:
    Entity* m_wormhole_sprite_unlocked;
    Entity* m_wormhole_sprite_locked;
    BoxCollider* m_collider;
    bool m_unlocked = false;
    StageBase* m_stage_destination = nullptr;
};
