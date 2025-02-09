#include "mjPlayScene.h"
#include "mjGameObject.h"
#include "mjTransform.h"
#include "mjSpriteRenderer.h"
#include "mjPlayer.h"
#include <mjInput.h>
#include "mjSceneManager.h"
#include "mjObject.h"
#include "mjTexture.h"
#include "mjResources.h"

namespace mj
{
	PlayScene::PlayScene()
		: player(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		player = object::Instantiate<Player>(enums::eLayerType::Background);

		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();

		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(bg);

		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		/*Transform* tr = player->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));*/
	}
}

