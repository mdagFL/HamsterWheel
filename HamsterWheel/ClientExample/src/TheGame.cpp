
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
	//std::cout << "game update" << std::endl;
	if (!init)
	{
		using namespace HW;
		ShaderProgram* defaultShader = new ShaderProgram("C:\\dev\\git\\HamsterWheel\\HamsterWheel\\ClientExample\\res\\shader\\default.shader");
		Texture* testTexture = new Texture("C:\\Users\\mailm\\Pictures\\rat.PNG");
		Material* testMaterial = new Material(defaultShader, testTexture);
		RenderObject o(testMaterial);
		this->CreateGameObject(o);
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