#pragma once
#include "mjResource.h"
#include "mjTexture.h"

namespace mj
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);
		
		void CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet,
			Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration);

		void Reset();

		bool isComplete() { return m_complete; }
		void SetAnimator(class Animator* animator) { m_animator = animator; }

	private:
		class Animator* m_animator;
		graphics::Texture* m_texture;

		std::vector<Sprite> m_animationSheet;
		int m_index;
		float m_time;
		bool m_complete;

	};
}