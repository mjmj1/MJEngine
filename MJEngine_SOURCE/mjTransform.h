#pragma once
#include "mjEntity.h"
#include "mjComponent.h"

namespace mj
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { m_position.x = pos.x; m_position.y = pos.y; }
		Vector2 GetPosition() { return m_position; }

	private:
		Vector2 m_position;
	};
}
