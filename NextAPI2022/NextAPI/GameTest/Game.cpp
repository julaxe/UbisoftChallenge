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
#include "Game/Scenes/SplashScreen.h"
//------------------------------------------------------------------------
void Init()
{
	SceneManager::AddScene(new GameScene());
}

void HandleInput()
{
	
}
void Update(float deltaTime)
{
	HandleInput();
	for(const auto scene : SceneManager::GetScenes())
	{
		if(scene)
			scene->Update(deltaTime);
	}
	
}


void Render()
{	
	for(const auto scene :SceneManager::GetScenes())
	{
		if(scene)
			scene->Draw();
	}
}
void Shutdown()
{
	for(const auto scene :SceneManager::GetScenes())
	{
		if(scene)
			scene->Exit();
	}
}