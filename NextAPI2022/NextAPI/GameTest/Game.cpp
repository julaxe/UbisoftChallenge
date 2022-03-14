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
	srand((unsigned int)time(NULL));
	SceneManager::AddScene(new SplashScreen());
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