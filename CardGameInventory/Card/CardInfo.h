#pragma once

#include <unordered_map>
#include <string>

enum eCardType
{
	None = 0,
	Spell = 1,
	Unit,
	Artifact,
	Support
};

static std::unordered_map<std::string, eCardType> cardTypeMap =
{
	{"", eCardType::None},
	{"Spell", eCardType::Spell},
	{"Unit", eCardType::Unit},
	{"Artifact", eCardType::Artifact},
	{"Support", eCardType::Support}
};

struct CardInfo
{
	int id = 0;
	std::wstring name = L"";
	eCardType type = eCardType::None;
	int cost = 0;
	int rarity = 0;
};