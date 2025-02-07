#pragma once
#include "mjSceneManager.h"
#include "mjPlayScene.h"

namespace mj
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
	}
}