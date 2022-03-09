#include "stdafx.h"
#include "SceneManager.h"

std::vector<Scene*> SceneManager::m_scenes;
void SceneManager::AddScene(Scene* scene)
{
    m_scenes.push_back(scene);
}

void SceneManager::PopScene()
{
    m_scenes.pop_back();
}

void SceneManager::ChangeScene(Scene* newScene)
{
    if(m_scenes.size() > 0)
    {
        for(int i = 0; i < m_scenes.size(); i++)
        {
            PopScene();
        }
    }
    AddScene(newScene);
}
