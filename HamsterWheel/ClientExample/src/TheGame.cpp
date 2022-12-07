
#include <iostream>
#include "TheGame.h"
#include "EntryPoint.h"
	

TheGame::TheGame(int width, int height) : Application(width, height)
{

}

void TheGame::OnRender()
{
	//std::cout << "game render" << std::endl;
}

void TheGame::OnUpdate()
{
	static bool init = false;
	std::cout << "game update" << std::endl;
	if (!init)
	{
		using namespace HW;
		
		init = true;
	}

	
}

HW::Application* HW::CreateApplication()
{
	/*
	TheGame* game = new TheGame();
	return (HW::Application*)game;
	*/
	// TESTING //
	
	return new TheGame(1280, 720);
}