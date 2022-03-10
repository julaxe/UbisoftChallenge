#include "stdafx.h"
#include "SceneManager.h"

std::vector<Scene*> SceneManager::m_scenes;
void SceneManager::AddScene(Scene* scene)
{
    m_scenes.push_back(scene);
}

void SceneManager::PopScene()
{
    if(m_scenes.size() == 1) return;
    m_scenes.pop_back();
}

void SceneManager::ChangeScene(Scene* newScene)
{
    if(m_scenes.size() > 0)
    {
        const int numberOfScenes = m_scenes.size();
        for(int i = 0; i < numberOfScenes; i++)
        {
            delete m_scenes[numberOfScenes-1-i];
            m_scenes[numberOfScenes-1-i] = nullptr;
            
            m_scenes.pop_back();
        }
    }
    AddScene(newScene);
}
