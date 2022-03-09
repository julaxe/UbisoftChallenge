#include "stdafx.h"
#include "Text.h"

#include "../App/app.h"

Text::Text(std::string name, const char* text)
{
    m_name = name;
    m_text = text;
}

void Text::Draw()
{
    App::Print(GetWorldPosition().x, GetWorldPosition().y, m_text, m_color.x, m_color.y, m_color.z);
}

void Text::SetText(const char* text)
{
    m_text = text;
}

void Text::SetColor(float r, float g, float b)
{
    m_color.x = r;
    m_color.y = g;
    m_color.z = b;
}
