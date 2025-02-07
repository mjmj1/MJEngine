#include "mjSpriteRenderer.h"
#include "mjGameObject.h"
#include "mjTransform.h"

namespace mj
{
	SpriteRenderer::SpriteRenderer()
		: m_image(nullptr)
		, m_width(0)
		, m_height(0)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(m_image, Gdiplus::Rect(pos.x, pos.y, m_width, m_height));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		m_image = Gdiplus::Image::FromFile(path.c_str());
		m_width = m_image->GetWidth();
		m_height = m_image->GetHeight();
	}
}