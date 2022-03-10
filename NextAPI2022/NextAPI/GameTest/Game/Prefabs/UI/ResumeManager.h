#pragma once
#include "../../../Engine/SceneNode.h"

class ResumeManager : public SceneNode
{
public:
    void Update(float dt) override;

private:
    void HandleInput();
};
