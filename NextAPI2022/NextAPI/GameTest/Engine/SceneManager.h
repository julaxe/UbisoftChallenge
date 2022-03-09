#pragma once
#include <stack>

#include "Scene.h"

class SceneManager
{
public:
    static void AddScene(Scene* scene);
    static void PopScene();
    static void ChangeScene(Scene* newScene);
    static std::vector<Scene*> GetScenes(){return m_scenes;}
    
    static std::vector<Scene*> m_scenes;
};
