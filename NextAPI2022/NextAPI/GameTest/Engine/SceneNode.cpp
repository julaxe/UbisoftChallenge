#include "stdafx.h"
#include "SceneNode.h"

SceneNode::SceneNode(std::string name)
{
    m_name = name;
}

void SceneNode::Update(float dt)
{
    GameObject::Update(dt);
    if(!IsActive()) return;
    UpdateChildren(dt);
}

void SceneNode::Draw()
{
    GameObject::Draw();
    if(!IsActive()) return;
    DrawChildren();
}

void SceneNode::SetActive(bool state)
{
    m_enable = state;
    for(const auto child : m_children)
    {
        child->SetActive(state);
    }
}

void SceneNode::SetName(std::string name)
{
    m_name = name;
}

void SceneNode::SetPosition(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
}

void SceneNode::SetScale(float x, float y)
{
    m_scale.x = x;
    m_scale.y = y;
}

void SceneNode::SetAngle(float angle)
{
    m_angle = angle;
}

Vector2 SceneNode::GetWorldPosition() const
{
    Vector2 worldPos = m_position;
    
    if(m_parent)
    {
        const float parentAngle = m_parent->GetAngle();
        const float newX = m_position.x * cosf(parentAngle) - m_position.y * sinf(parentAngle);
        const float newY = m_position.x * sinf(parentAngle) + m_position.y * cosf(parentAngle);
        worldPos.x = m_parent->GetWorldPosition().x + newX;
        worldPos.y = m_parent->GetWorldPosition().y + newY;
    }
    return worldPos;
}

void SceneNode::SetWorldPosition(Vector2 worldPos)
{
    Vector2 newPosition = worldPos;
    if(m_parent)
    {
        newPosition.x -= m_parent->GetWorldPosition().x;
        newPosition.y -= m_parent->GetWorldPosition().y;
    }
    SetPosition(newPosition.x, newPosition.y);
}

float SceneNode::GetWorldRotation() const
{
    float worldRotation = m_angle;
    if(m_parent)
    {
        worldRotation += m_parent->GetWorldRotation();
    }
    return worldRotation;
}

Vector2 SceneNode::GetWorldScale() const
{
    Vector2 worldScale = m_scale;
    if(m_parent)
    {
        worldScale.x *= m_parent->GetWorldScale().x;
        worldScale.y *= m_parent->GetWorldScale().y;
    }
    return worldScale;
}

void SceneNode::AddChild(SceneNode* child)
{
    m_children.push_back(child);
    child->m_position = {0.0f, 0.0f};
    child->SetParent(this);
}

void SceneNode::DeleteChild(SceneNode* child)
{
    //find child iterator
    auto it = m_children.begin();
    for(; it < m_children.end(); it++)
    {
        if((*it) == child)
        {
            break;
        }
    }
    (*it)->Exit();
    m_children.erase(it);
}

void SceneNode::ChangeParent(SceneNode* newParent)
{
    if(m_parent)
    {
        m_parent->DeleteChild(this);
    }
    SetParent(newParent);
    newParent->AddChild(this);
}

void SceneNode::UpdateChildren(float dt)
{
    for(const auto child : m_children)
    {
        child->Update(dt);
    }
}

void SceneNode::DrawChildren()
{
    for(const auto child : m_children)
    {
        child->Draw();
    }
}

void SceneNode::ExitChildren()
{
    for(const auto child : m_children)
    {
        child->Exit();
    }
    m_children.clear();
}

void SceneNode::SetParent(SceneNode* parent)
{
    m_parent = parent;
}

void SceneNode::RotateChildren(float angle)
{
    //for each children
    //change children pos with the parent angle.
    //update children angle as well.
}
