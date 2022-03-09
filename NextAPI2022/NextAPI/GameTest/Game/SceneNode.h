#pragma once
#include <string>
#include <vector>

#include "GameObject.h"

class SceneNode : GameObject
{
public:
    SceneNode();
    
    //scene
    void SetActive(bool state);
    bool IsActive() const {return m_enable;}
    void SetName(std::string name);
    std::string GetName() const {return m_name;}
    
    //transform
    void SetPosition(float x, float y);
    void SetScale(float x, float y);
    void SetAngle(float angle);
    Vector2 GetPosition() const {return m_position;}
    Vector2 GetScale() const {return m_scale;}
    float GetAngle() const {return m_angle;}
    
    //local->world
    Vector2 GetWorldPosition() const;

    //relations
    void AddChild(SceneNode* child);
    void DeleteChild(SceneNode* child);
    void SetParent(SceneNode* parent);

protected:
    //scene
    bool m_enable = true;
    std::string m_name = "";
    
    //transform
    Vector2 m_position;
    Vector2 m_scale;
    float m_angle = 0.0f;

    //relations
    SceneNode* m_parent = nullptr;
    std::vector<SceneNode*> m_children;

protected:
    void RotateChildren(float angle);
};
