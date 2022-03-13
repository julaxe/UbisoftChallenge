#include "stdafx.h"
#include "PlayerShield.h"

PlayerShield::PlayerShield()
{
    m_shield = new Planet();
    m_points.push_back({0.0f,10.0f});
    m_points.push_back({7.7f,7.7f});
    m_points.push_back({10.0f,0.0f});
    m_points.push_back({7.7f,-7.7f});
    m_points.push_back({0.0f,-10.0f});
    m_points.push_back({-7.7f,-7.7f});
    m_points.push_back({-10.0f,0.0f});
    m_points.push_back({-7.7f,7.7f});

    m_shield->BuildPlanet(m_points);
    m_shield->SetCollision(false);
    m_shield->SetColor({0.8f,0.8f,1.0f});
    m_shield->SetScale(2.0f,2.0f);
    AddChild(m_shield);
}

void PlayerShield::Exit()
{
    SceneNode::Exit();

    delete m_shield;
    m_shield = nullptr;
}
