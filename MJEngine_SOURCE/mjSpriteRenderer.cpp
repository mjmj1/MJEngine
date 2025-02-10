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
		, m_scale(Vector2::One)
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
		pos = renderer::mainCamera->CalculatePosition(pos);

		if (m_texture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{

			TransparentBlt(hdc, pos.x, pos.y, m_texture->GetWidth() * m_scale.x, m_texture->GetHeight() * m_scale.y,
				m_texture->GetHDC(), 0, 0, m_texture->GetWidth(), m_texture->GetHeight(),
				RGB(255, 0, 255));
		}
		else if (m_texture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(m_texture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y, m_texture->GetWidth() * m_scale.x, m_texture->GetHeight() * m_scale.y));
		}
	}
}