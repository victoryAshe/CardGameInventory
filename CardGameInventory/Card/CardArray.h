#pragma once

#include "Container/CircleArray.h"
#include "CardInfo.h"

#include <string>
#include <vector> 


class CardArray
{
public:
	static bool LoadFromCSV(const std::string& path);
	const static CardInfo GetInfo(int index);

public:
	static CircleArray<CardInfo> info;
};

