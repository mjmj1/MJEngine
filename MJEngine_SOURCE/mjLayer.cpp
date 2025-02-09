#include "mjLayer.h"

namespace mj
{
	Layer::Layer()
		: m_gameobjects{}
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : m_gameobjects)
		{
			if (gameObj == nullptr) continue;

			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : m_gameobjects)
		{
			if (gameObj == nullptr) continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : m_gameobjects)
		{
			if (gameObj == nullptr) continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : m_gameobjects)
		{
			if (gameObj == nullptr) continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr) return;

		m_gameobjects.push_back(gameObject);
	}
}