#include "mjDogScript.h"
#include "mjPlayerScript.h"
#include "mjInput.h"
#include "mjTime.h"
#include "mjTransform.h"
#include "mjGameObject.h"
#include <time.h>

namespace mj
{
	DogScript::DogScript()
		: m_state(DogScript::eState::Sitdown)
		, m_animator(nullptr)
		, m_time(0.0f)
		, m_direction(eDirection::Down)
	{
	}

	DogScript::~DogScript()
	{
	}

	void DogScript::Initialize()
	{
	}

	void DogScript::Update()
	{
		if (m_animator == nullptr)
		{
			m_animator = GetOwner()->GetComponent<Animator>();
		}

		switch (m_state)
		{
		case mj::DogScript::eState::Sitdown:
			sitDown();
			break;
		case mj::DogScript::eState::Walk:
			move();
			break;
		case mj::DogScript::eState::SideSitDown:
			sitDown();
			break;
		default:
			break;
		}
	}

	void DogScript::LateUpdate()
	{
	}

	void DogScript::Render(HDC hdc)
	{
	}

	void DogScript::sitDown()
	{
		m_time += Time::DeltaTime();

		if (m_time > 3.0f)
		{
			m_state = DogScript::eState::Walk;
			m_direction = (eDirection)(rand() % 4);
			playWalkAnimationByDirection(m_direction);

			m_time = 0.0f;
		}
	}

	void DogScript::sideSitDown()
	{
		m_time += Time::DeltaTime();

		if (m_time > 3.0f)
		{
			m_state = DogScript::eState::Walk;
			m_direction = (eDirection) (rand() % 4);
			playWalkAnimationByDirection(m_direction);

			m_time = 0.0f;
		}
	}

	void DogScript::move()
	{
		m_time += Time::DeltaTime();

		if (m_time > 2.0f)
		{
			int isSide = rand() % 2;

			if(isSide == 0)
			{
				m_state = DogScript::eState::Sitdown;
				m_animator->PlayAnimation(L"SitDown", false);
			}
			else
			{
				m_state = DogScript::eState::SideSitDown;
				m_animator->PlayAnimation(L"SideSitDown", false);
			}
			
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();

		translate(tr);
	}
	void DogScript::playWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case mj::DogScript::eDirection::Left:
			m_animator->PlayAnimation(L"LeftWalk");
			break;
		case mj::DogScript::eDirection::Right:
			m_animator->PlayAnimation(L"RightWalk");
			break;
		case mj::DogScript::eDirection::Down:
			m_animator->PlayAnimation(L"DownWalk");
			break;
		case mj::DogScript::eDirection::Up:
			m_animator->PlayAnimation(L"UpWalk");
			break;
		default:
			assert(false);
			break;
		}
	}

	void DogScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (m_direction)
		{
		case mj::DogScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case mj::DogScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case mj::DogScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case mj::DogScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		case mj::DogScript::eDirection::End:
			break;
		default:
			break;
		}

		tr->SetPosition(pos);

		/*if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left) ||
			Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
		{
			m_state = eState::Sitdown;
			m_animator->PlayAnimation(L"SitDown", false);
		}*/
	}
}