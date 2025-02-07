#pragma once
#include "mjScene.h"

namespace mj
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();

			scene->SetName(name);
			scene->Initialize();

			m_scenes.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
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

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<std::wstring, Scene*> m_scenes;
		static Scene* m_activeScene;
	};
}

