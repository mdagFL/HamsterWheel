#pragma once
#include <vector>
#include <string>

#include "GameObject.h"
#include "RenderObject.h"


namespace HW
{
	class ObjectManager
	{
	public:
		// Public interface
		GameObject* CreateGameObject(GameObject& objPrefab);
		//GameObject* CreateGameObject(const RenderObject& objPrefab);
		void DestroyGameObject(unsigned int id);
		void DestroyGameObject(std::string name);
		void DestroyGameObject(GameObject* object);
		GameObject* GetGameObject(unsigned int id);
		GameObject* GetGameObject(std::string name);

		// Application can directly access private state
		friend class Application;
	private:
		// Private state
		std::vector<GameObject*> _gameObjects;
		std::vector<RenderObject*> _renderObjects;
	};

}
