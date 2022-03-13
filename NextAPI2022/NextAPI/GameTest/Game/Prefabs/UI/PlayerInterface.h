#pragma once
#include "../../../Engine/SceneNode.h"
#include "../../../Engine/Text.h"

class PlayerInterface : public SceneNode
{
public:
    PlayerInterface();

    void Update(float dt) override;
    void Exit() override;

private:
    Text* m_player_lives;
    Text* m_player_fuel;
    Text* m_player_score;
    Text* m_player_bonus_score;
};
