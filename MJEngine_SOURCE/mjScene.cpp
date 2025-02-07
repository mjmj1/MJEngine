#include "mjScene.h"

namespace mj
{
	Scene::Scene()
		: m_gameobjects{}
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (GameObject* gameObj : m_gameobjects)
		{
			gameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : m_gameobjects)
		{
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : m_gameobjects)
		{
			gameObj->Render(hdc);
		}
	}
}