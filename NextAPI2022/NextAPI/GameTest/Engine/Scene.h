#pragma once
#include <vector>

#include "GameObject.h"
#include "SceneNode.h"

class Scene : public GameObject
{
public:
    Scene() {}
    void Start() override;
    void Update(float dt) override;
    void Draw() override;
    void Exit() override;

    void AddRootNode(SceneNode* node);
private:
    std::vector<SceneNode*> listOfRootNodes;
};
