#include "mjSceneManager.h"

namespace mj
{
	void SceneManager::Initialize()
	{
	}

	void SceneManager::Update()
	{
		m_activeScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		m_activeScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		m_activeScene->Render(hdc);
	}
}