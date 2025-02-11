#pragma once
#include "..\\MJEngine_SOURCE\\\mjGameObject.h"

namespace mj
{
	class Dog : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}