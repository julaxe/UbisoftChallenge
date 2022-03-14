#pragma once
#include "../../../Engine/BoxCollider.h"
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"
#include "../../../Engine/Text.h"

class BossHearth : public SceneNode
{
public:
    BossHearth();

    void Update(float dt) override;

private:
    Entity* m_sprite_boss;
    BoxCollider* m_collider;
    Text* m_text;

    int m_boss_health = 200;
};
