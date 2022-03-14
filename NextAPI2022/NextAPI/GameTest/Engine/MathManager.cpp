#include "stdafx.h"
#include <cmath>
#include "MathManager.h"

#include <complex>

#include "../app/AppSettings.h"

float MathManager::GetDistanceBetweenPoints(Vector2 point1, Vector2 point2)
{
    const Vector2 difference = GetDirectionBetweenVectors(point1, point2);
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

float MathManager::GetAngleFromVector(Vector2 vector)
{
    return atan2f(vector.y, vector.x);
}

Vector2 MathManager::GetDirectionBetweenVectors(Vector2 from, Vector2 destination)
{
    return {destination.x - from.x, destination.y - from.y};
}

Vector2 MathManager::NormalizeVector(Vector2 vector)
{
    const float magnitude = GetMagnitudeOfVector(vector);
    return {vector.x / magnitude, vector.y/magnitude};
}

Vector2 MathManager::RotateVectorByAnAngle(Vector2 vector,float angle)
{
    angle *= PI/180.0f;
    const float x = cosf(angle)*vector.x - sinf(angle)*vector.y;
    const float y = sinf(angle)*vector.x + cosf(angle)*vector.y;
    return {x,y};
}
