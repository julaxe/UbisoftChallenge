#include "stdafx.h"
#include "CircleWithHolePlanet.h"

#include "../../../Engine/MathManager.h"
#include "../Enemies/Turret.h"

CircleWithHolePlanet::CircleWithHolePlanet()
{
    Vector2 length = {0.0f,200.0f};

    float angle = 45.0f;
    for(int i = 0; i < 8; i++)
    {
        length = MathManager::RotateVectorByAnAngle(length, angle);
        m_points.push_back(length);

        if(i == 2)
        {
            Turret* turret = new Turret();
            AddChild(turret);
            turret->SetPosition(length.x -20.0f, length.y+10.0f);
            turret->SetAngle(MathManager::GetAngleFromVector(length) - 90.0f);
        }
    }
    length = {length.x * 0.9f, length.y * 0.9f};
    // m_points.push_back(length);
    //
    // for(int i = 0; i < 7; i++)
    // {
    //     length = MathManager::RotateVectorByAnAngle(length, -angle);
    //     m_points.push_back(length);
    // }

    SetClosingCircle(false);
    BuildPlanet(m_points);
}
