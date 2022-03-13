#pragma once
#include "../../../Engine/Line.h"
#include "../../../Engine/SceneNode.h"

class PlayerScanner : public SceneNode
{
public:
    PlayerScanner();

    void SetDirection(Vector2 direction);
    void Exit() override;
    
private:
    Line* m_line1;
    Line* m_line2;
    
};
