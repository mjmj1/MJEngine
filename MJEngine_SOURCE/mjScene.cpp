#include "mjScene.h"

namespace mj
{
	Scene::Scene()
		: m_layers{}
	{
		m_layers.resize((UINT) eLayerType::Max);

		std::for_each(m_layers.begin(), m_layers.end(),
			[](Layer*& layer)
			{
				layer = new Layer();
			}
		);
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr) continue;

			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr) continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr) continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr) continue;

			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(eLayerType type, GameObject* gameObject)
	{
		m_layers[(UINT) type]->AddGameObject(gameObject);
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	
}