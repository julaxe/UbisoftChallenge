#include "stdafx.h"
#include "PlayerScanner.h"

#include "../../../Engine/MathManager.h"

PlayerScanner::PlayerScanner()
{
    m_line1 = new Line({-5.0f, 0.0f}, {-12.0f,40.0f});
    m_line1->SetCanCollide(false);
    m_line1->SetColor({1.0f,1.0f,1.0f});
    AddChild(m_line1);
    
    m_line2 = new Line({5.0f, 0.0f}, {12.0f,40.0f});
    m_line2->SetCanCollide(false);
    m_line2->SetColor({1.0f,1.0f,1.0f});
    AddChild(m_line2);
    
    SetScale(4.0f,4.0f);
}

void PlayerScanner::SetDirection(Vector2 direction)
{
    const float angle = MathManager::GetAngleFromVector(direction) - PI*0.5f;
    SetAngle(angle);
}

void PlayerScanner::SetGatherRange(float range)
{
    m_gather_range = range;
}

void PlayerScanner::SetScannerDetectionRadius(float radius)
{
    m_scanner_detection = radius;
}

void PlayerScanner::Exit()
{
    SceneNode::Exit();

    delete m_line1;
    m_line1 = nullptr;

    delete m_line2;
    m_line2 = nullptr;
}
