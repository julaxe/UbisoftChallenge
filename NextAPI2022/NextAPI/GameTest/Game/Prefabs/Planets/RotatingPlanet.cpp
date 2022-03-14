#include "stdafx.h"
#include "RotatingPlanet.h"

#include "../../../Engine/MathManager.h"

RotatingPlanet::RotatingPlanet()
{
    m_points.push_back({-250.0,200.0f});
    m_points.push_back({-180.0,220.0f});
    m_points.push_back({-170.0,100.0f});
    m_points.push_back({-20.0,80.0f});
    m_points.push_back({-60.0,-10.0f});
    m_points.push_back({-60.0,-100.0f});
    m_points.push_back({60.0,-100.0f});
    m_points.push_back({60.0,-30.0f});
    m_points.push_back({150.0,-10.0f});
    m_points.push_back({-50,225.0f});
    m_points.push_back({250.0,180.0f});
    m_points.push_back({180.0,-150.0f});
    m_points.push_back({-10.0,-200.0f});
    m_points.push_back({-150.0,-140.0f});
    m_points.push_back({-250.0,-10.0f});
    m_points.push_back({-215.0,90.0f});

    BuildPlanet(m_points);
}
