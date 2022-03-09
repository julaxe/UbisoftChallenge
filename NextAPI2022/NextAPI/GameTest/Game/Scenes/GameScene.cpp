#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene()
{
    m_background = new Entity("background", ".\\TestData\\Pokemon2.bmp");
    AddRootNode(m_background);
}
