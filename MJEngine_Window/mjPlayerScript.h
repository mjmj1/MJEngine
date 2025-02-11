#pragma once
#include "..\\MJEngine_SOURCE\\\mjScript.h"
#include "mjAnimator.h"

namespace mj
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Attack1,
			Attack2,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();

	private:
		eState m_state;
		Animator* m_animator;
	};
}