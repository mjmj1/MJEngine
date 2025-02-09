#include "mjSceneManager.h"

namespace mj
{
	std::map<std::wstring, Scene*> SceneManager::m_scenes = {};
	Scene* SceneManager::m_activeScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (m_activeScene) m_activeScene->OnExit();

		// std::map<std::wstring, Scene*>::iterator
		auto iter = m_scenes.find(name);

		if (iter == m_scenes.end())
		{
			return nullptr;
		}

		m_activeScene = iter->second;
		m_activeScene->OnEnter();

		return iter->second;
	}

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