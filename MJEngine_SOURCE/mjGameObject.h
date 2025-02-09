#pragma once
#include "CommonInclude.h"
#include "mjComponent.h"

namespace mj
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();

			comp->Initialize();
			comp->SetOwner(this);
			m_components.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;

			for (Component* comp : m_components)
			{
				component = dynamic_cast<T*>(comp);
				
				if (component) break;
			}
			
			return component;
		}

	private:
		void initializeTransform();

	private:
		std::vector<Component*> m_components;
	};
}


