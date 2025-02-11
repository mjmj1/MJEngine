#pragma once
#include "..\\MJEngine_SOURCE\\mjResources.h"
#include "..\\MJEngine_SOURCE\\mjTexture.h"

namespace mj
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"..\\Resource\\kirby.png");
		// Resources::Load<graphics::Texture>(L"Warrior", L"..\\Resource\\warrior\\Warrior_Red.png");
		Resources::Load<graphics::Texture>(L"Warrior", L"..\\Resource\\Warrior_.bmp");
		Resources::Load<graphics::Texture>(L"Warrior2", L"..\\Resource\\warrior\\Warrior_Red.png");
		Resources::Load<graphics::Texture>(L"skill", L"..\\Resource\\skill.png");
		Resources::Load<graphics::Texture>(L"Dog", L"..\\Resource\\dog.png");
	}
}