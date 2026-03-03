#pragma once

#include "Render/Renderer.h"
#include "Card/CardArray.h"

class CardGameInventory
{
public:
	CardGameInventory();
	~CardGameInventory();

	void Run();

	const bool IsQuit() const { return isQuit; }
	
private:
	const bool LoadData();
	
	void ProcessInput();

	void Draw();


private:
	Renderer* renderer = nullptr;
	CardArray* cardArray = nullptr;

	bool isQuit = false;
	
	int currentIndex = 0;
};

