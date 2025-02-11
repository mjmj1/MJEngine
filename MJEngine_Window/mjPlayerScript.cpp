#include "mjPlayerScript.h"
#include "mjInput.h"
#include "mjTime.h"
#include "mjTransform.h"
#include "mjGameObject.h"

namespace mj
{
	PlayerScript::PlayerScript()
		: m_state(PlayerScript::eState::Idle)
		, m_animator(nullptr)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}

	void PlayerScript::Update()
	{
		if (m_animator == nullptr)
		{
			m_animator = GetOwner()->GetComponent<Animator>();
		}

		switch (m_state)
		{
		case mj::PlayerScript::eState::Idle:
			idle();
			break;
		case mj::PlayerScript::eState::Walk:
			move();
			break;
		case mj::PlayerScript::eState::Attack1:
			break;
		case mj::PlayerScript::eState::Attack2:
			break;
		default:
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			m_state = eState::Walk;
			m_animator->PlayAnimation(L"Walk");
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			m_state = eState::Walk;
			m_animator->PlayAnimation(L"Walk");
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			m_state = eState::Walk;
			m_animator->PlayAnimation(L"Walk");
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			m_state = eState::Walk;
			m_animator->PlayAnimation(L"Walk");
		}
	}

	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left) ||
			Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
		{
			m_state = eState::Idle;
			m_animator->PlayAnimation(L"Idle");
		}
	}
}