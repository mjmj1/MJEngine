#include "mjApplication.h"
#include "mjInput.h"
#include "mjTime.h"

namespace mj
{
	Application::Application()
		: m_hwnd(nullptr), m_hdc(nullptr),
		  m_width(0), m_height(0),
		  m_backHdc(nullptr), m_backBitmap(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		m_hwnd = hwnd;
		m_hdc = GetDC(hwnd);

		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_width = rect.right - rect.left;
		m_height = rect.bottom - rect.top;

		SetWindowPos(m_hwnd, nullptr, 0, 0, m_width, m_height, 0);
		ShowWindow(m_hwnd, true);

		// ������ �ػ󵵿� �´� ����� ����
		m_backBitmap = CreateCompatibleBitmap(m_hdc, width, height);
		
		// ���� ������ ����۸� ����ų hdc ����
		m_backHdc = CreateCompatibleDC(m_hdc);

		HBITMAP oldBitmap = (HBITMAP) SelectObject(m_backHdc, m_backBitmap);
		DeleteObject(oldBitmap);

		m_player.SetPosition(0, 0);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		m_player.Update();
	}

	void Application::LateUpdate()
	{
		m_player.LateUpdate();
	}

	void Application::Render()
	{
		Rectangle(m_backHdc, 0, 0, m_width, m_height);

		Time::Render(m_backHdc);
		m_player.Render(m_backHdc);

		// backbuffer�� �ִ� �� ���� hdc�� ����
		BitBlt(m_hdc, 0, 0, m_width, m_height,
			m_backHdc, 0, 0, SRCCOPY);
	}
}