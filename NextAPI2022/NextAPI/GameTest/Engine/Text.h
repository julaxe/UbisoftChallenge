#pragma once
#include "SceneNode.h"

class Text : public SceneNode
{
public:
    Text(std::string name, const char* text);
    void Draw() override;
    void SetText(const char* text);
    void SetColor(float r, float g, float b);
    Vector3 GetColor() const {return m_color;}
    const char* GetText() const {return m_text;}
    float GetWidth() const;

private:
    const char* m_text;
    Vector3 m_color = {1.0f,1.0f,1.0f};
};
