#include "mjAnimation.h"
#include "mjAnimator.h"
#include "mjTime.h"
#include "mjTransform.h"
#include "mjComponent.h"
#include "mjGameObject.h"
#include "mjRenderer.h"

namespace mj
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, m_animator(nullptr)
		, m_texture(nullptr)
		, m_animationSheet{}
		, m_index(-1)
		, m_time(0)
		, m_complete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (m_complete) return;

		m_time += Time::DeltaTime();

		if (m_animationSheet[m_index].duration < m_time)
		{
			m_time = 0.0f;

			if (m_index < m_animationSheet.size() - 1)
			{
				m_index++;
			}
			else
			{
				m_complete = true;
			}
		}
	}

	void Animation::Render(HDC hdc)
	{
		// 알파블랜드를 쓸 수 있는 조건 : 해당 이미지에 알파 채널이 있어야 함
		// AlphaBlend()

		if (m_texture == nullptr) return;

		GameObject* gameObj = m_animator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
		{
			renderer::mainCamera->CalculatePosition(pos);
		}

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		Sprite sprite = m_animationSheet[m_index];
		HDC imgHdc = m_texture->GetHDC();

		AlphaBlend(
			hdc, pos.x, pos.y, sprite.size.x, sprite.size.y,
			imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y,
			func);
	}

	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		m_texture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			m_animationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		m_time = 0.0f;
		m_index = 0;
		m_complete = false;
	}
}
