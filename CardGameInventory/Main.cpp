

#include "Card/CardArray.h"
#include "Util/PathUtil.h"

#include "Util/CsvReader.h" // temporary
#include "Render/Renderer.h"

#include <iostream>

int main()
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
		return 0;
	}


	//for (const CardInfo& it : CardArray::info)
	//{
	//	std::cout << it.id << " " << it.name.c_str() << " " << it.type <<" " << it.cost << " " << it.rarity << "\n";
	//}

	Renderer* renderer = new Renderer();
	Renderer::Get().Submit(CardArray::GetInfo(-1));

	return 0;
}