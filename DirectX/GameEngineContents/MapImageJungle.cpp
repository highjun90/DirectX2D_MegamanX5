#include "PreCompile.h"
#include "MapImageJungle.h"

MapImageJungle::MapImageJungle()
{
}

MapImageJungle::~MapImageJungle()
{
}

void MapImageJungle::Start()
{
	//{
	//	// ������ ���� ������ �������.
	//	TestCollision = CreateComponent<GameEngineComponent>(30);
	//	TestCollision->Transform.SetLocalScale({ 30, 30, 1 });

	//	MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(30);
	//	MainSpriteRenderer->SetSprite("HoHoYee_AttackABC2");
	//	/*MainSpriteRenderer->CreateAnimation("Run", "HoHoYee_AttackABC2", 0.05f, -1, -1, true);
	//	MainSpriteRenderer->ChangeAnimation("Run");
	//	MainSpriteRenderer->SetSamplerState(SamplerOption::LINEAR);
	//	MainSpriteRenderer->Transform.SetLocalPosition({ 100.0f, 0.0f, 0.0f });

	//	MainSpriteRenderer->SetEndEvent("Run", std::bind(&Player::TestEvent, this, std::placeholders::_1));*/

	//	// MainSpriteRenderer->Transform.SetLocalScale({5, 5});
	//	// MainSpriteRenderer->AutoSpriteSizeOn();
	//	// MainSpriteRenderer->SetAutoScaleRatio(2.0f);
	//	MainSpriteRenderer->Transform.SetLocalScale({ -100.0f, 100.0f, 1.0f });
	//}

	//{
	//	Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
	//	Col->Transform.SetLocalScale({ -100.0f, 100.0f, 1.0f });
	//}

	//float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	//Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });
	
	//Ÿ��Ʋ�̹��� ������Ʈ
	//{

	{
		SpriteRenderer0 = CreateComponent<GameEngineSpriteRenderer>(20);

		//MainSpriteRenderer->SetSprite("PlayerSelectImage0.PNG");
		SpriteRenderer0 ->SetSprite("Jungle0.PNG");
		//MainSpriteRenderer->SetSprite("Testmap.PNG");
		//MainSpriteRenderer->CreateAnimation("TitleImageAnimation", "TitleImage", 0.6f, -1, -1, true);
		//MainSpriteRenderer->ChangeAnimation("TitleImageAnimation");
		SpriteRenderer0->SetSamplerState(SamplerOption::POINT);
		SpriteRenderer0->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f });
		SpriteRenderer0->Transform.SetLocalScale({ 960.0f, 720.0f, 5.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });

	//{
	//	for (int i = 0; i < MapImageCount; i++)
	//	{
	//		SpriteRenderers[i] = CreateComponent<GameEngineSpriteRenderer>(20);

	//		//���⼭���� �۾��ʿ�
	//		SpriteRenderers[i]->SetSprite("Jungle0.PNG");
	//		SpriteRenderers[i]->SetSamplerState(SamplerOption::POINT);
	//		SpriteRenderers[i]->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f });
	//		SpriteRenderers[i]->Transform.SetLocalScale({ 960.0f, 720.0f, 5.0f });


	//	}
	//}
}



void MapImageJungle::Update(float _Delta)
{

	//EventParameter Event;

	//Event.Enter = [](GameEngineCollision* Col)
	//{
	//	int a = 0;
	//};

	//Event.Stay = [](GameEngineCollision* Col)
	//{
	//	int a = 0;
	//};


	//Event.Exit = [](GameEngineCollision* Col)
	//{
	//	Col->GetActor()->Death();

	//	int a = 0;
	//};

	//Col->CollisionEvent(ContentsCollisionType::Monster, Event);

	//Col->Collision(ContentsCollisionType::Monster, {100.0f, 0.0f, 0.0f}, [](std::vector<std::shared_ptr<GameEngineCollision>>& _Collision)
	//	{
	//		for (size_t i = 0; i < _Collision.size(); i++)
	//		{
	//			_Collision[i]->GetActor()->Death();
	//		}
	//	});

	//if (xxxx ��Ȳ�� �Ǹ�)
	//{
	//	MainSpriteRenderer->Death();
	//	MainSpriteRenderer = nullptr;
	//}

	// �浹�߳� ���߳ĸ� ����

	//std::list<std::shared_ptr<Monster>> MonsterList = 
	//	GetLevel()->GetObjectGroupConvert<Monster>(ContentsObjectType::Monster);

	//for (std::shared_ptr<Monster> MonsterPtr : MonsterList)
	//{
	//	// �������� �ϴ� ���� => ���ͷε� �Ҽ��ִµ�
	//	// ���� ���ʹ� ��ġ�� ������ ����ִ� �뵵�� ���˴ϴ�.
	//	// MainSpriteRenderer->Transform.Collision(MonsterPtr->Renderer->Transform);

	//	GameEngineTransform& Left = TestCollision->Transform;
	//	GameEngineTransform& Right = MonsterPtr->Renderer->Transform;
	//	Right.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });

	//	// �ݸ��� �Ķ���͸� ����� ������. 
	//	if (GameEngineTransform::Collision({ Left , Right, ColType::OBBBOX2D }))
	//	{
	//		MonsterPtr->Death();
	//		int a = 0;
	//		// �浹�ߴ�.
	//	}
	//}


	float Speed = 100.0f;


	if (GameEngineInput::IsPress('A'))
	{
		Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('Q'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });
	}

	if (GameEngineInput::IsPress('E'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, -360.0f * _Delta });
	}

	//GameEngineColor Color = PlayMap::MainMap->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	//if (GameEngineColor::RED != Color)
	//{
	//	GrivityForce.Y -= _Delta * 100.0f;
	//	Transform.AddLocalPosition(GrivityForce * _Delta);
	//}
	//else 
	//{
	//	GrivityForce = 0.0f;
	//}
	// ���� ���ٰ��ϰ� �ʹٸ� while������ �÷��ּ���.


	// float4 Color = GetColor(Transform.GetWorldPosition());
}