#include "stdafx.h"
#include "Text.h"

#include "../App/app.h"

Text::Text(std::string name, std::string text)
{
    m_name = name;
    m_text = text;
}

void Text::Draw()
{
    SceneNode::Draw();
    App::Print(GetWorldPosition().x, GetWorldPosition().y, m_text.c_str(), m_color.x, m_color.y, m_color.z);
}

void Text::SetText(std::string text)
{
    m_text = text;
}

void Text::SetColor(float r, float g, float b)
{
    m_color.x = r;
    m_color.y = g;
    m_color.z = b;
}

float Text::GetWidth() const
{
    float width = 0.0f;
    std::string str = m_text;
    for(char & c : str)
    {
        width += 8.0f * GetWorldScale().x; // hard coded value.
    }
    return width;
}
