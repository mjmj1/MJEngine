#pragma once
#include "CommonInclude.h"
#include "mjComponent.h"
#include "mjTexture.h"

namespace mj
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::Texture* texture) { m_texture = texture; }
		void SetScale(math::Vector2 scale) { m_size = scale; }

	private:
		graphics::Texture* m_texture;
		math::Vector2 m_size;
	};
}
