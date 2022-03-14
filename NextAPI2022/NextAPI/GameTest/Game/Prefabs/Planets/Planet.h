#pragma once
#include "../../../Engine/Line.h"
#include "../../../Engine/SceneNode.h"

class Planet : public SceneNode
{
public:
    Planet();

    void Update(float dt) override;
    void Draw() override;
    void Exit() override;
    
    void AddNewPoint(Vector2 point);
    void CloseCircle();
    void BuildPlanet(std::vector<Vector2> points);
    void SetCollision(bool state);
    void SetColor(Vector3 color);
    void SetClosingCircle(bool state);
protected:
    void ClearLines();
    void AddNewLine(Vector2 point1, Vector2 point2);
    bool m_closing_circle = true;
    std::vector<Line*> m_lines;
    std::vector<Vector2> m_points;
};
