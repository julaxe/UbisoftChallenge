#pragma once
#include "../../../Engine/Line.h"
#include "../../../Engine/SceneNode.h"

class PlayerScanner : public SceneNode
{
public:
    PlayerScanner();

    void SetDirection(Vector2 direction);
    void SetGatherRange(float range);
    float GetGatherRange()const {return m_gather_range;}
    void SetScannerDetectionRadius(float radius);
    float GetScannerDetectionRadius() const {return m_scanner_detection;}
    void Exit() override;
    
private:
    Line* m_line1;
    Line* m_line2;

    float m_gather_range = 50.0f;
    float m_scanner_detection = 200.0f;
};
