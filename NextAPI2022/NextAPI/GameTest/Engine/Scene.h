#pragma once
#include <vector>

#include "GameObject.h"
#include "SceneNode.h"

class Scene : GameObject
{
public:
    void Start() override;
    void Update(float dt) override;
    void Draw() override;
    void Exit() override;
private:
    std::vector<SceneNode*> listOfRootNodes;
};
