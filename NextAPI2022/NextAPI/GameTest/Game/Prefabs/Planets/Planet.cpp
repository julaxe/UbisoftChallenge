#include "stdafx.h"
#include "Planet.h"

Planet::Planet()
{
}

void Planet::Update(float dt)
{
    SceneNode::Update(dt);
}

void Planet::Draw()
{
    SceneNode::Draw();
}

void Planet::Exit()
{
    SceneNode::Exit();
    ExitChildren();
    ClearLines();
}

void Planet::AddNewPoint(Vector2 point)
{
    if(m_lines.size() == 0)
    {
        AddNewLine(point, point);
        return;
    }
    AddNewLine(m_lines.back()->GetPoint2(), point);
}

void Planet::CloseCircle()
{
    if(m_lines.size() == 0) return;
    AddNewLine(m_lines.back()->GetPoint2(), m_lines.front()->GetPoint1());
}

void Planet::BuildPlanet(std::vector<Vector2> points)
{
    for(const auto point : points)
    {
        AddNewPoint(point);
    }
    if(m_closing_circle)
        CloseCircle();
}

void Planet::SetCollision(bool state)
{
    for(int i = 0; i < m_lines.size(); i++)
    {
        m_lines[i]->SetCanCollide(state);
    }
}

void Planet::SetColor(Vector3 color)
{
    for(int i = 0; i < m_lines.size(); i++)
    {
        m_lines[i]->SetColor(color);
    }
}

void Planet::SetClosingCircle(bool state)
{
    m_closing_circle = state;
}

void Planet::ClearLines()
{
    for(int i = 0; i < m_lines.size(); i++)
    {
        delete m_lines[i];
        m_lines[i] = nullptr;
    }
}

void Planet::AddNewLine(Vector2 point1, Vector2 point2)
{
    Line* newLine = new Line(point1, point2);
    m_lines.push_back(newLine);
    AddChild(newLine);
}
