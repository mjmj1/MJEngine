#pragma once
#include "mjEntity.h"
#include "CommonInclude.h"
#include "mjGameObject.h"

namespace mj
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		//eLayerType m_type;
		std::vector<GameObject*> m_gameobjects;
	};
}
