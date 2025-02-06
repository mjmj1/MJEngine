#include "mjGameObject.h"
#include "mjInput.h"

namespace mj
{
	GameObject::GameObject()
		: mX(0), mY(0)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH) SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN) SelectObject(hdc, redPen);

		Rectangle(hdc, 10 + mX, 10 + mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);

		SelectObject(hdc, oldPen);
		DeleteObject(redPen);
	}
}