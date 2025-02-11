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
#include "mjDog.h"
#include "mjDogScript.h"

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
		// main Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(808.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// player
		m_player = object::Instantiate<Player>(enums::eLayerType::Player);
		m_player->AddComponent<PlayerScript>();
		
		graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Warrior2");
		Animator* animator = m_player->AddComponent<Animator>();
		animator->CreateAnimation(L"Idle", playerTexture, Vector2::Zero,
			Vector2(192.0f, 192.0f), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"Walk", playerTexture, Vector2(0.0f, 192.0f),
			Vector2(192.0f, 192.0f), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"Attack1", playerTexture, Vector2(0.0f, 384.0f),
			Vector2(192.0f, 192.0f), Vector2::Zero, 6, 0.1f);
		animator->CreateAnimation(L"Attack2", playerTexture, Vector2(0.0f, 576.0f),
			Vector2(192.0f, 192.0f), Vector2::Zero, 6, 0.1f);

		animator->PlayAnimation(L"Idle", true);
		m_player->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));

		// Dog
		Dog* dog = object::Instantiate<Dog>(enums::eLayerType::Player);
		dog->AddComponent<DogScript>();

		graphics::Texture* dogTexture = Resources::Find<graphics::Texture>(L"Dog");
		Animator* dog_animator = dog->AddComponent<Animator>();
		dog_animator->CreateAnimation(L"DownWalk", dogTexture, Vector2::Zero,
			Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		dog_animator->CreateAnimation(L"RightWalk", dogTexture, Vector2(0.0f, 32.0f),
			Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		dog_animator->CreateAnimation(L"UpWalk", dogTexture, Vector2(0.0f, 64.0f),
			Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		dog_animator->CreateAnimation(L"LeftWalk", dogTexture, Vector2(0.0f, 96.0f),
			Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		dog_animator->CreateAnimation(L"SitDown", dogTexture, Vector2(0.0f, 128.0f),
			Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		dog_animator->CreateAnimation(L"SideSitDown", dogTexture, Vector2(0.0f, 160.0f),
			Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);

		dog->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		dog->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));

		dog_animator->PlayAnimation(L"SitDown", false);

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

