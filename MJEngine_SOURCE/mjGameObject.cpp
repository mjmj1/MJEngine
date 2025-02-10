#include "mjGameObject.h"
#include "mjInput.h"
#include "mjTime.h"
#include "mjTransform.h"

namespace mj
{
	GameObject::GameObject()
	{
		m_components.resize((UINT) enums::eComponentType::End);
		initializeTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : m_components)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : m_components)
		{
			if (comp == nullptr) continue;

			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : m_components)
		{
			if (comp == nullptr) continue;

			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : m_components)
		{
			if (comp == nullptr) continue;

			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : m_components)
		{
			if (comp == nullptr) continue;

			comp->Render(hdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}