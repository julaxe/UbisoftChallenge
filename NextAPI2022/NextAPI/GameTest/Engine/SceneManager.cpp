#include "stdafx.h"
#include "SceneManager.h"

#include "CollisionManager.h"

std::vector<Scene*> SceneManager::m_scenes;
void SceneManager::AddScene(Scene* scene)
{
    m_scenes.push_back(scene);
}

void SceneManager::PopScene()
{
    if(m_scenes.size() == 1) return;

    const int numberOfScenes = static_cast<int>(m_scenes.size());
    m_scenes[numberOfScenes - 1]->Exit();
    delete m_scenes[numberOfScenes-1];
    m_scenes[numberOfScenes-1] = nullptr;
    
    m_scenes.pop_back();
}

void SceneManager::ChangeScene(Scene* newScene)
{
    if(m_scenes.size() > 0)
    {
        const int numberOfScenes = static_cast<int>(m_scenes.size());
        for(int i = 0; i < numberOfScenes; i++)
        {
            m_scenes[numberOfScenes-1-i]->Exit();
            delete m_scenes[numberOfScenes-1-i];
            m_scenes[numberOfScenes-1-i] = nullptr;
            
            m_scenes.pop_back();
        }
    }
    AddScene(newScene);
}
