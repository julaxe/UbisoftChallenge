#pragma once
#include "SceneNode.h"

class Text : public SceneNode
{
public:
    Text(std::string name, std::string text);
    void Draw() override;
    void SetText(std::string text);
    void SetColor(float r, float g, float b);
    Vector3 GetColor() const {return m_color;}
    std::string GetText() const {return m_text;}
    float GetWidth() const;

private:
    std::string m_text;
    Vector3 m_color = {1.0f,1.0f,1.0f};
};
