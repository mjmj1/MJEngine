#include "mjTransform.h"

namespace mj
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, m_scale(Vector2::One)
		, m_rotation(0.0f)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render(HDC hdc)
	{
	}
}