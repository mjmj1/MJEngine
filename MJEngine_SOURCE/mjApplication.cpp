#include "mjApplication.h"
#include "mjInput.h"
#include "mjTime.h"
#include "mjSceneManager.h"

namespace mj
{
	Application::Application()
		: m_hwnd(nullptr)
		, m_hdc(nullptr)
		, m_width(0), m_height(0)
		, m_backHdc(nullptr)
		, m_backBitmap(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		SceneManager::Initialize();
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

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(m_backHdc);
		SceneManager::Render(m_backHdc);

		copyRenderTarget(m_backHdc, m_hdc);
	}

	void Application::clearRenderTarget()
	{
		Rectangle(m_backHdc, -1, -1, m_width + 1, m_height + 1);
	}

	void Application::copyRenderTarget(HDC src, HDC dest)
	{
		BitBlt(dest, 0, 0, m_width, m_height, src, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		m_hwnd = hwnd;
		m_hdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_width = rect.right - rect.left;
		m_height = rect.bottom - rect.top;

		SetWindowPos(m_hwnd, nullptr, 0, 0, m_width, m_height, 0);
		ShowWindow(m_hwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		m_backBitmap = CreateCompatibleBitmap(m_hdc, width, height);

		m_backHdc = CreateCompatibleDC(m_hdc);

		HBITMAP oldBitmap = (HBITMAP) SelectObject(m_backHdc, m_backBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}