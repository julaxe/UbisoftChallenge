#include "stdafx.h"
#include "TutorialPlanet.h"

TutorialPlanet::TutorialPlanet()
{
    m_points.push_back({-100.0,0.0f});
    m_points.push_back({-80.0,0.0f});
    m_points.push_back({-20.0,50.0f});
    m_points.push_back({0.0,50.0f});
    m_points.push_back({30.0,80.0f});
    m_points.push_back({60.0,80.0f});
    m_points.push_back({60.0,-20.0f});
    m_points.push_back({40.0,-30.0f});
    m_points.push_back({50.0,-40.0f});
    m_points.push_back({0.0,-60.0f});
    m_points.push_back({-20.0,-60.0f});
    m_points.push_back({-50.0,-45.0f});
    m_points.push_back({-80.0,-60.0f});

    BuildPlanet(m_points);
}
