#pragma once
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

enum Transition
{
    FADE_IN,
    STILL,
    FADE_OUT
};

class SplashImage : public SceneNode
{
public:
    SplashImage();

    void Update(float dt) override;
    void Draw() override;

private:

    void ManageTransitions(float deltaTime);
    Entity* m_splash_image;

    Transition m_current_transition = FADE_IN;
    float m_current_alpha = 0.0f;
    
    float m_timer = 0.0f;
    float m_seconds_between_transitions = 5.0f;
    float m_vanish_velocity = 0.01f;
};
