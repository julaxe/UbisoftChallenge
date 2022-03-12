#include "stdafx.h"
#include <cmath>
#include "MathManager.h"

#include <complex>

float MathManager::GetDistanceBetweenPoints(Vector2 point1, Vector2 point2)
{
    const Vector2 difference = {point2.x - point1.x, point2.y - point1.x};
    return GetMagnitudeOfVector(difference);
}

float MathManager::GetMagnitudeOfVector(Vector2 vector)
{
    const float magnitude = std::sqrt(vector.x*vector.x + vector.y*vector.y);
    return magnitude;
}

Vector2 MathManager::LerpBetweenVectors(Vector2 vector1, Vector2 vector2, float t)
{
    const float lerpedX = vector1.x + (vector2.x - vector1.x) * t;
    const float lerpedY = vector1.y + (vector2.y - vector1.y) * t;
    
    return {lerpedX, lerpedY};
}
