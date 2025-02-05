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

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();

	private:
		HWND m_hwnd;
		HDC m_hdc;

		GameObject m_player;
	};
}


