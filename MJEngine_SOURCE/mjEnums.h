#pragma once

namespace mj::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		Background,
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
