

#include <iostream>
#include "TheGame.h"
#include "EntryPoint.h"
	

TheGame::TheGame(int width, int height) : Application(width, height)
{

}

void TheGame::OnRender() const
{
	//std::cout << "game render" << std::endl;
}

void TheGame::OnUpdate() const
{
	std::cout << "game update" << std::endl;
}

HW::Application* HW::CreateApplication()
{
	/*
	TheGame* game = new TheGame();
	return (HW::Application*)game;
	*/
	return new TheGame(1280, 720);
}