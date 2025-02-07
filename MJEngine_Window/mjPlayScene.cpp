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
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();

		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\mj\\Documents\\planet_kirby.jpg");

		AddGameObject(bg);
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
	}
}

