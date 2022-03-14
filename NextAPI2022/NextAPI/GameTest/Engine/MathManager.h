#pragma once
#include "GameObject.h"

class MathManager
{
public:
    static float GetDistanceBetweenPoints(Vector2 point1, Vector2 point2);
    static float GetMagnitudeOfVector(Vector2 vector);
    static Vector2 LerpBetweenVectors(Vector2 vector1, Vector2 vector2, float t);
    static float GetAngleFromVector(Vector2 vector);
    static Vector2 GetDirectionBetweenVectors(Vector2 vector1, Vector2 vector2);
    static Vector2 NormalizeVector(Vector2 vector);
    static Vector2 RotateVectorByAnAngle(Vector2 vector, float angle);
};
