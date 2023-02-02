
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
		Texture* testTexture = new Texture("D:\\Randy's_Disk\\Pictures_D\\ahamam2.png");
		Material* testMaterial = new Material(defaultShader, testTexture);

		float *testVertexBuffer = new float[12]
		{
			-0.5, 0.5, 0,
			 0.5, 0.5, 0,
			-0.5,-0.5, 0,
			 0.5,-0.5, 0
		};

		float *testTextureAttribBuffer = new float[8]
		{
			0, 0,
			1, 0,
			0, 1,
			1, 1
		};

		unsigned int *testIndexBuffer = new unsigned int[4]{ 0, 1, 2, 3 };

		VertexBufferObject *testVbo = new VertexBufferObject(testVertexBuffer, 12);
		VertexArrayObject  *testVao = new VertexArrayObject(testIndexBuffer, 4, GL_TRIANGLE_STRIP);

		int testLoc = glGetAttribLocation(defaultShader->GetId(), "position");
		VertexAttribute* testAttrib = new VertexAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0, testVbo);

		int testTexLoc = glGetAttribLocation(defaultShader->GetId(), "inTexCoord");
		VertexBufferObject* testTextureVbo = new VertexBufferObject(testTextureAttribBuffer, 8);
		VertexAttribute* testTextureAttrib = new VertexAttribute(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0, testTextureVbo);

		testVao->AddAttribute(*testAttrib);
		testVao->AddAttribute(*testTextureAttrib);

		RenderObject* testRenderPrefab = new RenderObject(testVao, testVbo, testMaterial);
		this->_Renderer->_camera.SetCameraShader(defaultShader, "viewTranslate");
		this->_Renderer->_camera._screenTransform._Position = Vector3(0.5, 0.5, 0);
		this->_objectManager.CreateGameObject(*testRenderPrefab);
		testRenderPrefab->_Transform._Position = Vector3(-0.5, -0.5, 0);
		this->_objectManager.CreateGameObject(*testRenderPrefab);

		init = true;
	}
	Application::OnUpdate();
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