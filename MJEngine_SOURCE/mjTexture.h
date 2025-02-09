#pragma once
#include "mjResource.h"

namespace mj::graphics
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

		Texture();
		~Texture();

		HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return m_width; }
		UINT GetHeight() { return m_height; }
		HDC GetHDC() { return m_hdc; }
		eTextureType GetTextureType() { return m_type; }
		Gdiplus::Image* GetImage() { return m_image; }

	private:
		eTextureType m_type;
		Gdiplus::Image* m_image;
		HBITMAP m_bitmap;
		HDC m_hdc;

		UINT m_width;
		UINT m_height;
	};
}
