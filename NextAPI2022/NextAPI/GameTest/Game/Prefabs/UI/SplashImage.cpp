#include "stdafx.h"
#include "SplashImage.h"

#include "../../../Engine/SceneManager.h"
#include "../../Scenes/MainMenuScene.h"

SplashImage::SplashImage()
{
    m_splash_image = new Entity("triangle", ".\\TestData\\Ubisoft.bmp");
    m_splash_image->SetAlpha(0.0f);
    AddChild(m_splash_image);
}

void SplashImage::Update(float dt)
{
    ManageTransitions(dt);
    UpdateChildren(dt);
}

void SplashImage::Draw()
{
    DrawChildren();
}

void SplashImage::ManageTransitions(float deltaTime)
{
    switch (m_current_transition)
    {
    case FADE_IN:
        m_current_alpha += m_vanish_velocity;
        if(m_current_alpha >= 1.0f)
        {
            m_current_alpha = 1.0f;
            m_current_transition = STILL;
        }
        m_splash_image->SetAlpha(m_current_alpha);
        break;
    case FADE_OUT:
        m_current_alpha -= m_vanish_velocity;
        if(m_current_alpha <= 0.0f)
        {
            m_current_alpha = 0.0f;
            m_current_transition = STILL;
        }
        m_splash_image->SetAlpha(m_current_alpha);
        break;
    case STILL:
        if(m_timer >= m_seconds_between_transitions)
        {
            m_timer = 0.0f;
            if(m_current_alpha == 1.0f)
            {
                m_current_transition = FADE_OUT;
            }
            else
            {
                SceneManager::ChangeScene(new MainMenuScene());
            }
        }
        m_timer += deltaTime;
    default:
        break;
    }
}
