#include "ObjectManager.h"

namespace HW
{
	GameObject* ObjectManager::CreateGameObject(const GameObject& objPrefab)
	{
		GameObject* instance = new GameObject(objPrefab);
		_gameObjects.push_back(instance);
		return instance;
	}
	GameObject* ObjectManager::CreateGameObject(const RenderObject& objPrefab)
	{
		// temp
		return CreateGameObject((GameObject)objPrefab);
	}
	void ObjectManager::DestroyGameObject(GameObject* object)
	{
		delete object;
	}
}
