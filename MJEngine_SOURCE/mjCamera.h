#pragma once
#include "mjComponent.h"

namespace mj
{
	using namespace mj::math;
	class Camera : public Component
	{
	public:
		Vector2 CalculatePosition(Vector2 pos) { return pos - m_distance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		// std::vector<GameObject*> m_gameobjects;
		class GameObject* m_target;
		Vector2 m_distance;
		Vector2 m_resolution;
		Vector2 m_lookPosition;

	};
}
