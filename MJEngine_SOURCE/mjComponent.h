#pragma once
#include "mjEntity.h"

namespace mj
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { m_owner = owner; }
		GameObject* GetOwner() { return m_owner; }
		enums::eComponentType GetType() { return m_type; }

	private:
		enums::eComponentType m_type;
		GameObject* m_owner;
	};
}
