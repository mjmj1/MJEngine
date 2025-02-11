#include "mjSpriteRenderer.h"
#include "mjGameObject.h"
#include "mjTransform.h"
#include "mjTexture.h"
#include "mjRenderer.h"

namespace mj
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, m_texture(nullptr)
		, m_size(Vector2::One)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	}

	void SpriteRenderer::Update()
	{
	}

	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (m_texture == nullptr)
		{
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 scale = tr->GetScale();
		float rotation = tr->GetRotation();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (m_texture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y,
				m_texture->GetWidth() * m_size.x * scale.x,
				m_texture->GetHeight() * m_size.y * scale.y,
				m_texture->GetHDC(), 0, 0, m_texture->GetWidth(), m_texture->GetHeight(),
				RGB(255, 0, 255));
		}
		else if (m_texture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			// 내가 원하는 픽셀을 투명화시킬 때 사용
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(
				m_texture->GetImage(),
				Gdiplus::Rect(
					pos.x, pos.y,
					m_texture->GetWidth() * m_size.x * scale.x,
					m_texture->GetHeight() * m_size.y * scale.y
				),
				0, 0,
				m_texture->GetWidth(), m_texture->GetHeight(),
				Gdiplus::UnitPixel,
				nullptr
			);
		}
	}
}