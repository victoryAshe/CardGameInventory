#include "CardGameInventory.h"

#include "Util/PathUtil.h"


#include <conio.h>


// key.
#define LEFT 75
#define RIGHT 77
#define OTHER 224

CardGameInventory::CardGameInventory()
{
	renderer = new Renderer();
	cardArray = new CardArray();
}

CardGameInventory::~CardGameInventory()
{
	if (renderer) delete renderer;
	if (cardArray) delete cardArray;
}

void CardGameInventory::Run()
{
	isQuit = !LoadData();
	if (isQuit) return;

	Draw();

	ProcessInput();
}

const bool CardGameInventory::LoadData()
{
	// TODO: PlayerInfo에서 inventory에 보유한 cardID만 불러와서 생성
	// Make Path.
	std::string exePath = PathUtil::GetExeDir();
	std::string cardTablePath = exePath;

	cardTablePath = PathUtil::JoinPath(cardTablePath, "Card");
	cardTablePath = PathUtil::JoinPath(cardTablePath, "CardItemTable.csv");

	bool loaded = CardArray::LoadFromCSV(cardTablePath);

	// Exception Handling.
	if (!loaded)
	{
		std::cerr << "Failed to load csv.\n";
		__debugbreak();
		return false;
	}

	return true;
}

void CardGameInventory::ProcessInput()
{
	while (!isQuit)
	{
		if (_kbhit())
		{

			int key = _getch();
			if (key == OTHER) key = _getch();

			switch (key)
			{
			case LEFT:
				--currentIndex;
				break;
			case RIGHT:
				++currentIndex;
				break;

			default:
				system("cls");
				std::cout << "다른 키가 입력되어 프로그램을 종료합니다.\n";
				isQuit = true;
				break;
			}


			if (isQuit) break;

			Draw();
		}
	}
}

void CardGameInventory::Draw()
{
	renderer->Submit(CardArray::GetInfo(currentIndex));
}
