#include "stdafx.h"
#include "Bullet.h"

#include <iostream>

#include "../../../Engine/MathManager.h"

Bullet::Bullet(const char* fileName, int columns, int rows)
{
    m_fileName_sprite = fileName;
    m_bullet_sprite = new Entity(fileName, columns, rows);
    AddChild(m_bullet_sprite);

    m_collider = new BoxCollider(7.0f, 7.0f);
    AddChild(m_collider);

    if(columns > 1)
    {
        std::vector<int> frames;
        for(int i = 0; i < columns; i++)
        {
            frames.push_back(i);
        }
        m_bullet_sprite->CreateAnimation(0,0.1f, frames);
        m_bullet_sprite->SetAnimation(0);
    }
}

Bullet::Bullet(Bullet* bullet)
{
    m_fileName_sprite = bullet->m_fileName_sprite;
    const int columns = bullet->GetSprite()->GetColumns();
    const int rows = bullet->GetSprite()->GetRows();
    m_bullet_sprite = new Entity(m_fileName_sprite, columns, rows);
    AddChild(m_bullet_sprite);

    m_collider = new BoxCollider(bullet->m_collider->GetWidth(), bullet->m_collider->GetHeight());
    AddChild(m_collider);

    SetScale(bullet->GetScale().x, bullet->GetScale().y);
    SetSpeed(bullet->GetSpeed());
    SetTag(bullet->GetTag());

    if(columns > 1)
    {
        std::vector<int> frames;
        for(int i = 0; i < columns; i++)
        {
            frames.push_back(i);
        }
        m_bullet_sprite->CreateAnimation(0,0.1f, frames);
        m_bullet_sprite->SetAnimation(0);
    }
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
    if(m_collider->IsBeingHitByAnExternalSource())
    {
        SetActive(false);
        m_collider->SetCollidingExternal(false);
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
    const Vector2 normalized = MathManager::NormalizeVector(direction);
    m_direction = normalized;
}

void Bullet::SetSpeed(float speed)
{
    m_speed = speed;
}

void Bullet::SetTag(CollisionTag tag) const
{
    m_collider->SetTag(tag);
}

void Bullet::AddCollisionTag(CollisionTag tag)
{
    m_collisionTags.push_back(tag);
}
