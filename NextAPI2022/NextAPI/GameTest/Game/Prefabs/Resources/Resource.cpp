#include "stdafx.h"
#include "Resource.h"

#include "../../StaticGameData.h"

Resource::Resource()
{
    StaticGameData::ResourcesList.push_back(this);
}

void Resource::SetTag(ResourceTag tag)
{
    m_tag = tag;
}
