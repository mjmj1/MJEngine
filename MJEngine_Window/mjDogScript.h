#pragma once
#include "..\\MJEngine_SOURCE\\\mjScript.h"
#include "mjAnimator.h"
#include "mjTransform.h"

namespace mj
{
	class DogScript : public Script
	{
	public:
		enum class eState
		{
			Sitdown,
			Walk,
			SideSitDown,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		DogScript();
		~DogScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void sitDown();
		void sideSitDown();
		void move();
		void playWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);

	private:
		eState m_state;
		Animator* m_animator;
		eDirection m_direction;

		float m_time;
	};
}