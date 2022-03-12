#include "stdafx.h"
#include "Bullet.h"

#include <iostream>

Bullet::Bullet(const char* fileName)
{
    m_fileName_sprite = fileName;
    m_bullet_sprite = new Entity(fileName);
    AddChild(m_bullet_sprite);

    m_collider = new BoxCollider(10.0f, 10.0f);
    AddChild(m_collider);
}

Bullet::Bullet(Bullet* bullet)
{
    m_fileName_sprite = bullet->m_fileName_sprite;
    m_bullet_sprite = new Entity(m_fileName_sprite);
    AddChild(m_bullet_sprite);

    m_collider = new BoxCollider(bullet->m_collider->GetWidth(), bullet->m_collider->GetHeight());
    AddChild(m_collider);

    SetScale(bullet->GetScale().x, bullet->GetScale().y);
    SetSpeed(bullet->GetSpeed());
}

void Bullet::Update(float dt)
{
    SceneNode::Update(dt);
    if(!IsActive()) return;
    
    const float newX = GetPosition().x + m_speed * (dt * 0.0001f) * m_direction.x;
    const float newY = GetPosition().y + m_speed * (dt * 0.0001f) * m_direction.y;

    SetPosition(newX, newY);

    if(m_collider->OutsideGameWorld())
    {
        SetActive(false);
        return;
    }
    for(const auto tag : m_collisionTags)
    {
        if(m_collider->CheckCollisionWithAnotherTag(tag))
        {
            SetActive(false);
            return;
        }
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

    m_collisionTags.clear();
}

void Bullet::SetDirection(Vector2 direction)
{
    m_direction = direction;
}

void Bullet::SetSpeed(float speed)
{
    m_speed = speed;
}

void Bullet::AddCollisionTag(CollisionTag tag)
{
    m_collisionTags.push_back(tag);
}
