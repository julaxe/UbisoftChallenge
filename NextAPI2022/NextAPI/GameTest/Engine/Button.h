#pragma once
#include <string>

#include "SceneNode.h"

class Entity;

class Button : public SceneNode
{
public:
    Button(std::string name, const char* fileName1, const char* fileName2);

    void HandleInput();
    void Update(float dt) override;
    void Draw() override;

private:
    bool m_isActive = false;
    Entity* m_spriteInactive;
    Entity* m_spriteActive;
};
