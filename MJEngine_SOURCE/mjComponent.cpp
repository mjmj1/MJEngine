#include "mjComponent.h"


namespace mj
{

	Component::Component(enums::eComponentType type)
		: m_type(type)
		, m_owner(nullptr)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}