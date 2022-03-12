#pragma once
#include "GameObject.h"

class MathManager
{
public:
    static float GetDistanceBetweenPoints(Vector2 point1, Vector2 point2);
    static float GetMagnitudeOfVector(Vector2 vector);
    static Vector2 LerpBetweenVectors(Vector2 vector1, Vector2 vector2, float t);
};
