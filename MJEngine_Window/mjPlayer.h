#pragma once
#include "mjGameObject.h"

namespace mj
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}
