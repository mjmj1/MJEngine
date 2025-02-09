#pragma once
#include "..\\MJEngine_SOURCE\\mjResources.h"
#include "..\\MJEngine_SOURCE\\mjTexture.h"

namespace mj
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\user\\Pictures\\Saved Pictures\\pngegg.png");
	}
}