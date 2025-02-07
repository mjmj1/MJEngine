#pragma once
#include "CommonInclude.h"
#include "mjComponent.h"

namespace mj
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* m_image;
		UINT m_width;
		UINT m_height;
	};
}
