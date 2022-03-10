#pragma once
#include "../../../Engine/SceneNode.h"

class PauseManager : public SceneNode
{
public:
    void Update(float dt) override;

private:
    void HandleInput();
};
