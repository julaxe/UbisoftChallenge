#include "stdafx.h"
#include "BossHearth.h"

#include "../../../Engine/SceneManager.h"
#include "../../Scenes/CreditsScene.h"

BossHearth::BossHearth()
{
    m_sprite_boss = new Entity("sprite", ".\\TestData\\BossBullet.bmp");
    AddChild(m_sprite_boss);

    m_collider = new BoxCollider(45.f,45.f);
    m_collider->SetTag(CollisionTag::PLAYER);
    AddChild(m_collider);

    m_text = new Text("text", "");
    m_text->SetText(std::to_string(m_boss_health));
    AddChild(m_text);
    m_text->SetPosition(-15.0f,20.f);
}

void BossHearth::Update(float dt)
{
    SceneNode::Update(dt);
    if(m_collider->CheckCollisionWithAnotherTag(CollisionTag::PLAYERBULLET))
    {
        m_boss_health -= 10;
        m_text->SetText(std::to_string(m_boss_health));
        if(m_boss_health <= 0)
        {
            SceneManager::ChangeScene(new CreditsScene());
        }
    }
}
