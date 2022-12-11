
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
		ShaderProgram* defaultShader = new ShaderProgram("C:\\dev\\git\\HamsterWheel\\HamsterWheel\\ClientExample\\Debug\\default.shader");
		Texture* testTexture = new Texture("D:\\Randy's_Disk\\Pictures_D\\ahamam2.png");
		Material* testMaterial = new Material(defaultShader, testTexture);
		RenderObject* o = new RenderObject(testMaterial);
		this->AddGameObject(o);
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