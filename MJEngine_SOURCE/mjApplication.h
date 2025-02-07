#pragma once
#include "CommonInclude.h"
#include "mjGameObject.h"
#include "mjScene.h"

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
		void clearRenderTarget();
		void copyRenderTarget(HDC src, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND m_hwnd;

		HDC m_hdc;
		HDC m_backHdc;

		HBITMAP m_backBitmap;

		UINT m_width;
		UINT m_height;
	};
}


