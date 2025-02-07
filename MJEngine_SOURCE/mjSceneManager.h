#pragma once
#include "mjScene.h"

namespace mj
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(std::wstring& name)
		{
			T* scene = new T();

			scene->SetName(name);
			scene->Initialize();

			m_scenes.insert(std::make_pair(name, scene));
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

