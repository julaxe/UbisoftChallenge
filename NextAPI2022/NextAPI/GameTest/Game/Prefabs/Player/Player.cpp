#include "stdafx.h"
#include "Player.h"

#include "../../../App/app.h"

enum AnimationState
{
    ANIM_FORWARD,
    ANIM_LEFT,
    ANIM_RIGHT,
    ANIM_BACKWARD
};

Player::Player()
{
    m_sprite = new Entity("sprite", ".\\TestData\\Test.bmp", 8, 4);
    float speed = 1.0f/15.0f;
    m_sprite->CreateAnimation(ANIM_FORWARD, speed, {0,1,2,3,4,5,6,7});
    m_sprite->CreateAnimation(ANIM_LEFT, speed, {8,9,10,11,12,13,14,15});
    m_sprite->CreateAnimation(ANIM_RIGHT, speed, {16,17,18,19,20,21,22,23});
    m_sprite->CreateAnimation(ANIM_BACKWARD, speed, {24,25,26,27,28,29,30,31});
    AddChild(m_sprite);
}

void Player::HandleInput()
{
    const float speed = 1.0f;
    Vector2 newPosition = m_sprite->GetPosition();
    if(App::GetController().GetLeftThumbStickX() > 0.5f)
    {
        m_sprite->SetAnimation(ANIM_RIGHT);
        newPosition.x += speed;
    }
    if(App::GetController().GetLeftThumbStickX() < -0.5f)
    {
        m_sprite->SetAnimation(ANIM_LEFT);
        newPosition.x -= speed;
    }
    if(App::GetController().GetLeftThumbStickY() > 0.5f)
    {
        m_sprite->SetAnimation(ANIM_BACKWARD);
        newPosition.y += speed;
    }
    if(App::GetController().GetLeftThumbStickY() < -0.5f)
    {
        m_sprite->SetAnimation(ANIM_FORWARD);
        newPosition.y -= speed;
    }
    m_sprite->SetPosition(newPosition.x, newPosition.y);
}

void Player::Update(float dt)
{
    HandleInput();
    UpdateChildren(dt);
}

void Player::Draw()
{
    DrawChildren();
}
