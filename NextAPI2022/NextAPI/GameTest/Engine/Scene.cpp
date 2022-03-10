#include "stdafx.h"
#include "Scene.h"

void Scene::Start()
{
    for(const auto node : listOfRootNodes)
    {
        node->Start();
    }
}

void Scene::Update(float dt)
{
    if(m_paused) return;
    for(const auto node : listOfRootNodes)
    {
        node->Update(dt);
    }
}

void Scene::Draw()
{
    for(const auto node : listOfRootNodes)
    {
        node->Draw();
    }
}

void Scene::Exit()
{
    for(const auto node : listOfRootNodes)
    {
        node->Exit();
    }
}

void Scene::SetPause(bool state)
{
    m_paused = state;
}

void Scene::AddRootNode(SceneNode* node)
{
    listOfRootNodes.push_back(node);
}
