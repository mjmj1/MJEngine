#pragma once
#include "mjEntity.h"
#include "mjGameObject.h"
#include "mjLayer.h"

namespace mj
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(const enums::eLayerType type, GameObject* gameObject);
		Layer* GetLayer(enums::eLayerType type) { return m_layers[(UINT)type]; }

	private:
		std::vector<Layer*> m_layers;
	};
}
