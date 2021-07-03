#include <iostream>
#include "TheGame.h"
#include "EntryPoint.h"
	

void TheGame::OnInit()
{
	std::cout << "Client entry point" << std::endl;
}

TheGame::TheGame() : HWapplication()
{
	OnInit();
}

void TheGame::OnRender()
{
	std::cout << "game init" << std::endl;
}

void TheGame::OnUpdate()
{
	std::cout << "game init" << std::endl;
}

HW::HWapplication* HW::CreateApplication()
{
	/*
	TheGame* game = new TheGame();
	return (HW::HWapplication*)game;
	*/
	return new TheGame();
}