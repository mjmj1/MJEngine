#pragma once
#include "CommonInclude.h"
#include "mjGameObject.h"

namespace mj
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND m_hwnd;

		HDC m_hdc;
		HDC m_backHdc;

		HBITMAP m_backBitmap;

		UINT m_width;
		UINT m_height;

		GameObject m_player;
	};
}


