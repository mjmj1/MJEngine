#include "mjTexture.h"
#include "mjApplication.h"

//해당 전역변수가 존재함을 알려주는 키워드
extern mj::Application application;

namespace mj::graphics
{
	Texture::Texture()
		:Resource(enums::eResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		//if bmp
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		if (ext == L"bmp")
		{
			m_type = eTextureType::Bmp;
			m_bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (m_bitmap == nullptr) return S_FALSE;
			
			BITMAP info = {};
			GetObject(m_bitmap, sizeof(BITMAP), &info);

			m_width = info.bmWidth;
			m_height = info.bmHeight;

			HDC mainDC = application.GetHDC();
			m_hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldbitmap = (HBITMAP) SelectObject(m_hdc, m_bitmap);
			DeleteObject(oldbitmap);
		}
		else if (ext == L"png")
		{
			m_type = eTextureType::Png;
			m_image = Gdiplus::Image::FromFile(path.c_str());

			if (m_image == nullptr) return S_FALSE;

			m_width = m_image->GetWidth();
			m_height = m_image->GetHeight();
		}

		return S_OK;
	}
}