#pragma once
#include "..\MJEngine_SOURCE\mjSceneManager.h"
#include "mjPlayScene.h"
#include "mjTitleScene.h"

namespace mj
{
	void CreateScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
	}

	void LoadScenes()
	{
		SceneManager::LoadScene(L"PlayScene");
	}
}