#include "mjPlayScene.h"
#include "mjGameObject.h"
#include "mjTransform.h"
#include "mjSpriteRenderer.h"
#include "mjPlayer.h"
#include <mjInput.h>
#include <mjSceneManager.h>

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
		player = new Player();
		Transform* tr = player->AddComponent<Transform>();

		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = player->AddComponent<SpriteRenderer>();

		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\user\\Pictures\\Saved Pictures\\test.jpg");

		AddGameObject(eLayerType::Background, player);
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
		Transform* tr = player->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}

