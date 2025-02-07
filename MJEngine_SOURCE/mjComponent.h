#pragma once
#include "mjEntity.h"

namespace mj
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { m_owner = owner; }
		GameObject* GetOwner() { return m_owner; }

	private:
		GameObject* m_owner;
	};
}
