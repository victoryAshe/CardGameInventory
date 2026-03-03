#include "CardArray.h"

#include "Util/CsvReader.h"


CircleArray<CardInfo> CardArray::info = {};

//std::unordered_map<int, CardInfo> CardArray::info;

bool CardArray::LoadFromCSV(const std::string& path)
{

	std::vector<std::vector<std::string>> rows;
	if (!CsvReader::ReadAll(path, rows)) return false;

	bool skipHeader = true;
	for (const std::vector<std::string>& fields : rows)
	{
		if (fields.empty()) continue;

		if (skipHeader)
		{
			skipHeader = false;
			continue;
		}

		// stageName, npcName, dialogueStartID, dialogueEndID
		// id, name, type, cost, rarity
		//if (fields.size() < 5) continue;

		CardInfo curInfo;
		curInfo.id = CsvReader::ToInt(fields[0]);
		curInfo.name = CsvReader::UTF8toWide(fields[1]);
		curInfo.type = cardTypeStringMap[fields[2]];
		curInfo.cost = CsvReader::ToInt(fields[3]);
		curInfo.rarity = CsvReader::ToInt(fields[4]);

		info.Insert(curInfo);
		//info[curInfo.id] = curInfo;
	}

	return true;
}

const CardInfo CardArray::GetInfo(int index)
{
	return info[index];
}
