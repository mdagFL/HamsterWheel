#include <iostream>
#include "TheGame.h"
	
void TheGame::OnInit()
{
	std::cout << "Client entry point" << std::endl;
}

TheGame::TheGame() : HWapplication()
{
	
}

HW::HWapplication* CreateApplication()
{
	/*
	TheGame* game = new TheGame();
	return (HW::HWapplication*)game;
	*/
	return new TheGame();
}