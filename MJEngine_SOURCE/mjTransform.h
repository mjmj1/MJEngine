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

		void SetPosition(Vector2 pos) { m_position.x = pos.x; m_position.y = pos.y; }
		void SetRotation(float rotate) { m_rotation = rotate; }
		void SetScale(Vector2 scale) { m_scale = scale; }

		Vector2 GetPosition() { return m_position; }
		float GetRotation() { return m_rotation; }
		Vector2 GetScale() { return m_scale; }

	private:
		Vector2 m_position;
		Vector2 m_scale;
		float m_rotation;
	};
}
