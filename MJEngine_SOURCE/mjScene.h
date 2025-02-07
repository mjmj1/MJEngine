#pragma once
#include "mjEntity.h"
#include "mjGameObject.h"

namespace mj
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<GameObject*> m_gameobjects;
	};
}
