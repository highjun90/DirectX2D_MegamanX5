#include "PreCompile.h"
#include "ContentsCore.h"
#include "LevelTitle.h"
#include "LevelcharacterSelect.h"
#include "LevelJungle.h"

ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::Start()
{
	//기본적으로 SpriteRenderer를 만들때 넣어줄 샘플러를 지정합니다. 이 코드 없으면 static 초기화 에러가 날것임
	GameEngineSpriteRenderer::SetDefaultSampler("POINT");



	GameEngineCore::CreateLevel<LevelTitle>("LevelTitle");
	GameEngineCore::CreateLevel<LevelCharacterSelect>("LevelCharacterSelect");
	GameEngineCore::CreateLevel<LevelJungle>("LevelJungle");
	GameEngineCore::ChangeLevel("LevelTitle");
	

}

void ContentsCore::Update(float _Delta)
{

}

void ContentsCore::Release()
{

}