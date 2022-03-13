#pragma once
#include "../../../Engine/SceneNode.h"

class ZoomInEffect : public SceneNode
{
public:
    ZoomInEffect();

    void Update(float dt) override;

private:
    float m_time_interval = 3.0f;
    float m_start_scale = 0.0f;
    float m_current_scale = 0.0f;
    float m_final_scale = 1.0f;
    float m_timer = 0.0f;

    bool m_children_pause = true;
    
};
