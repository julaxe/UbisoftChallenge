#pragma once
#include <string>

#include "SceneNode.h"

class Entity;

class Button : public SceneNode
{
public:
    Button(std::string name, const char* fileNameActive, const char* fileNameInactive);

    void HandleInput();
    void Update(float dt) override;
    void Draw() override;

    void SetFocus(bool state);
    bool GetFocus() const {return m_isFocused;}
    virtual void OnClick(){};

    float GetWidth() const;
    float GetHeight() const;

protected:
    bool m_isFocused = false;
    Entity* m_spriteInactive;
    Entity* m_spriteActive;
};
