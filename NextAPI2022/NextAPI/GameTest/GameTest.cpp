//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
//------------------------------------------------------------------------
#include <iostream>

#include "app\app.h"
#include "Engine/SceneManager.h"
#include "Game/Scenes/GameScene.h"
#include "Game/Scenes/MainMenuScene.h"
//------------------------------------------------------------------------
void Init()
{
	SceneManager::AddScene(new MainMenuScene());
}

void HandleInput()
{
	
}
void Update(float deltaTime)
{
	HandleInput();
	for(const auto scene : SceneManager::GetScenes())
	{
		scene->Update(deltaTime);
	}
	
}


void Render()
{	
	for(const auto scene :SceneManager::GetScenes())
	{
		scene->Draw();
	}
}
void Shutdown()
{
	for(const auto scene :SceneManager::GetScenes())
	{
		scene->Exit();
	}
}