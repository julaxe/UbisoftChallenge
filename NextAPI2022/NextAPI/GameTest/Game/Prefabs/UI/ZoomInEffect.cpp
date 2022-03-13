#include "stdafx.h"
#include "ZoomInEffect.h"

ZoomInEffect::ZoomInEffect()
{
    m_timer = 0.0f;
    m_current_scale = m_start_scale;
}

void ZoomInEffect::Update(float dt)
{
    if(m_timer < m_time_interval)
    {
        m_current_scale = m_timer/m_time_interval;
        SetScale(m_current_scale, m_current_scale);
    }
    else
    {
        m_children_pause = false;
        SetScale(1.0f, 1.0f);
    }
    m_timer += dt*0.001f;

    if(m_children_pause) return;
    SceneNode::Update(dt);
}
