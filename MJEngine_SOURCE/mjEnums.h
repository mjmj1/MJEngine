#pragma once

namespace mj::enums
{
	enum class eLayerType
	{
		None,
		Background,
		Title,
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		//Mesh,
		//Shader,
		AudioClip,
		Prefab,
		End,
	};
}
