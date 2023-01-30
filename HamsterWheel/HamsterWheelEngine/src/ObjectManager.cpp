#include "ObjectManager.h"

namespace HW
{
	GameObject* ObjectManager::CreateGameObject(GameObject& objPrefab)
	{
		GameObject* instance;
		RenderObject* render = (RenderObject*)&objPrefab;
		if (render)
		{
			instance = new RenderObject(*render);
		}
		else
		{
			instance = new GameObject(objPrefab);
		}

		_gameObjects.push_back(instance);
		return &objPrefab;
	}
	//GameObject* ObjectManager::CreateGameObject(const RenderObject& objPrefab)
	//{
	//	// temp
	//	return CreateGameObject(objPrefab);
	//}
	void ObjectManager::DestroyGameObject(GameObject* object)
	{
		delete object;
	}
}
