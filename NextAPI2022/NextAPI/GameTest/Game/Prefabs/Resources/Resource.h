#pragma once
#include "../../../Engine/Entity.h"
#include "../../../Engine/SceneNode.h"

enum class ResourceTag
{
    FUELTANK,
    CORE
};
class Resource : public SceneNode
{
public:
    Resource();
    
    void SetTag(ResourceTag tag);
    ResourceTag GetTag()const{return m_tag;}
protected:
    ResourceTag m_tag;
    Entity* m_sprite;
};
