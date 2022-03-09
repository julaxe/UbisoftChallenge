#include "stdafx.h"
#include "CollisionManager.h"

#include "../app/app.h"

bool CollisionManager::isMouseInsideRectangle(float posX, float posY, float width, float height)
{
    float mouseX, mouseY;
    App::GetMousePos(mouseX, mouseY);

    if(mouseX >= (posX - width * 0.5f) &&
        mouseX <= (posX + width * 0.5f) &&
        mouseY >= (posY - height * 0.5f) &&
        mouseY <= (posY + height * 0.5f))
    {
        return true;
    }
    return false;
    
}
