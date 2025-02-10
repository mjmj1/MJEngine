#include "mjPlayScene.h"
#include "mjGameObject.h"
#include "mjSpriteRenderer.h"
#include "mjPlayer.h"
#include <mjInput.h>
#include "mjSceneManager.h"
#include "mjObject.h"
#include "mjTexture.h"
#include "mjResources.h"
#include "mjPlayerScript.h"
#include "mjCamera.h"
#include "mjRenderer.h"
#include "mjAnimator.h"

namespace mj
{
	PlayScene::PlayScene()
		: m_player(nullptr)
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		//main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(808.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		m_player = object::Instantiate<Player>(enums::eLayerType::Player);
		m_player->AddComponent<PlayerScript>();

		graphics::Texture* warriorTexture = Resources::Find<graphics::Texture>(L"Warrior");
		Animator* animator = m_player->AddComponent<Animator>();
		animator->CreateAnimation(L"Warrior_Idle", warriorTexture, Vector2::Zero, Vector2(192.0f, 192.0f), Vector2::Zero, 6, 0.1f);

		animator->PlayAnimation(L"Warrior_Idle", true);

		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Background);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"BG");
		bgsr->SetTexture(bgTexture);

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

