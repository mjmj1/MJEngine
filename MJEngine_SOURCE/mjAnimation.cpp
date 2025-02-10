#include "mjAnimation.h"


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
			if (m_index < m_animationSheet.size())
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
