#include "PreCompile.h"
#include "GameEngineCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineTime.h>

std::shared_ptr<GameEngineObject> GameEngineCore::CoreObject;
GameEngineTime GameEngineCore::MainTime;
GameEngineWindow GameEngineCore::MainWindow;
GameEngineDevice GameEngineCore::MainDevice;

std::shared_ptr<GameEngineLevel> GameEngineCore::CurLevel;
std::shared_ptr<GameEngineLevel> GameEngineCore::NextLevel;
std::map<std::string, std::shared_ptr<GameEngineLevel>> GameEngineCore::AllLevel;



GameEngineCore::GameEngineCore() 
{
}

GameEngineCore::~GameEngineCore() 
{
}

void GameEngineCore::Start() 
{
	CoreObject->Start();
}

void GameEngineCore::Update() 
{

	if (nullptr != NextLevel)
	{
		if (nullptr != CurLevel)
		{
			CurLevel->AllLevelEnd(NextLevel.get());
		}

		// NextLevel->OverCheck(CurLevel);

		NextLevel->AllLevelStart(CurLevel.get());

		CurLevel = NextLevel;

		NextLevel = nullptr;
		MainTime.Reset();
	}

	MainTime.Update();
	float DeltaTime = MainTime.GetDeltaTime();

	if (DeltaTime > 1.0f / 60.0f)
	{
		DeltaTime = 1.0f / 60.0f;
	}

	GameEngineSound::Update();
	CoreObject->Update(DeltaTime);

	if (true == GameEngineWindow::IsFocus())
	{
		GameEngineInput::Update(DeltaTime);
	}
	else
	{
		GameEngineInput::Reset();
	}

	CurLevel->AddLiveTime(DeltaTime);
	CurLevel->AllUpdate(DeltaTime);

	//HDC DC;
	//{
	//	DC = GameEngineCore::MainWindow.GetBackBuffer()->GetImageDC();
	//	float4 WinScale = GameEngineCore::MainWindow.GetScale();
	//	Rectangle(DC, 0, 0, WinScale.iX(), WinScale.iY());
	//}

	MainDevice.RenderStart();

	CurLevel->Render(DeltaTime);

	MainDevice.RenderEnd();

	CurLevel->AllReleaseCheck();
}

void GameEngineCore::Release() 
{
	CoreObject->Release();
}

void GameEngineCore::EngineProcess(HINSTANCE _Inst, const std::string& _WindowName, float4 _Pos, float4 _Size)
{
	// ��üũ ���ְ�
	GameEngineDebug::LeakCheck();

	// ������ �����
	MainWindow.Open(_WindowName, _Inst);
	MainWindow.SetPosAndScale(_Pos, _Size);

	// 3D ����̽��� �� �����츦 ������� �����.
	MainDevice.Initiallize(MainWindow);

	// �ð��̳� Ÿ��
	GameEngineWindow::MessageLoop(_Inst, Start, Update, Release);
}

void GameEngineCore::LevelInit(std::shared_ptr<GameEngineLevel> _Level)
{
	_Level->Start();
}