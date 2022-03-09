#include "stdafx.h"
#include "DebugManager.h"

#include "../App/app.h"

void DebugManager::DrawCollisionBox(float posX, float posY, float width, float height)
{
    const float left = posX - width * 0.5f;
    const float right = posX + width * 0.5f;
    const float top = posY + height * 0.5f;
    const float bottom = posY - height * 0.5f;
    
    App::DrawLine(left, bottom, right, bottom);
    App::DrawLine(right, bottom, right, top);
    App::DrawLine(right, top, left, top);
    App::DrawLine(left, top, left, bottom);
}
