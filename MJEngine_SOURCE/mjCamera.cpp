#include "mjCamera.h"
#include "mjGameObject.h"
#include "mjTransform.h"
#include "mjApplication.h"

extern mj::Application application;

namespace mj
{
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
		, m_distance(Vector2::Zero)
		, m_resolution(Vector2::Zero)
		, m_lookPosition(Vector2::Zero)
		, m_target(nullptr)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Initialize()
	{
		m_resolution.x = application.GetWidth();
		m_resolution.y = application.GetHeight();
	}

	void Camera::Update()
	{
		if (m_target)
		{
			Transform* tr = m_target->GetComponent<Transform>();
			m_lookPosition = tr->GetPosition();
		}

		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		m_lookPosition = cameraTr->GetPosition();

		m_distance = m_lookPosition - (m_resolution * 0.5f);
	}

	void Camera::LateUpdate()
	{

	}

	void Camera::Render(HDC hdc)
	{
	}
}