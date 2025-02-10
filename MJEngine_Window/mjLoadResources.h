#pragma once
#include "..\\MJEngine_SOURCE\\mjResources.h"
#include "..\\MJEngine_SOURCE\\mjTexture.h"

namespace mj
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\mj\\Documents\\pngegg.png");
		Resources::Load<graphics::Texture>(L"Warrior", L"C:\\Users\\mj\\Documents\\Github\\MJEngine\\Resource\\warrior\\idle\\idle01.png");
	}
}