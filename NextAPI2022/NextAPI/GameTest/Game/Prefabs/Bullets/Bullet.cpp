#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(const char* fileName)
{
    m_bullet_sprite = new Entity(fileName);
    AddChild(m_bullet_sprite);

    m_collider = new BoxCollider(10.0f, 10.0f);
    m_collider->SetTag(CollisionTag::BULLET);
    AddChild(m_collider);
}

void Bullet::Update(float dt)
{
    SceneNode::Update(dt);
    const float newX = GetPosition().x + m_speed * (dt * 0.0001f) * m_direction.x;
    const float newY = GetPosition().y + m_speed * (dt * 0.0001f) * m_direction.y;

    SetPosition(newX, newY);

    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYER))
    {
        SetActive(false);
    }
}

void Bullet::Draw()
{
    SceneNode::Draw();
}

void Bullet::Exit()
{
    ExitChildren();

    delete m_bullet_sprite;
    m_bullet_sprite = nullptr;

    delete m_collider;
    m_collider = nullptr;
}

void Bullet::SetDirection(Vector2 direction)
{
    m_direction = direction;
}

void Bullet::SetSpeed(float speed)
{
    m_speed = speed;
}
