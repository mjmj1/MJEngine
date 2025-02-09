#include "mjGameObject.h"
#include "mjInput.h"
#include "mjTime.h"
#include "mjTransform.h"

namespace mj
{
	GameObject::GameObject()
	{
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
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : m_components)
		{
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : m_components)
		{
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : m_components)
		{
			comp->Render(hdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}