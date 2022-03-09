#include "stdafx.h"
#include "SceneNode.h"

SceneNode::SceneNode(std::string name)
{
    m_name = name;
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
        worldPos.x += m_parent->GetWorldPosition().x;
        worldPos.y += m_parent->GetWorldPosition().y;
    }
    return worldPos;
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
