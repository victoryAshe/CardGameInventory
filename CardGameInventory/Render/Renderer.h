#pragma once

#include "Card/CardInfo.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Submit(const CardInfo& info);

	// Singleton 접근 변수.
	static Renderer& Get();

private:
	void Clear();
	void Render(const CardInfo& info);

private:

	// Singleton 구현을 위한 static 변수.
	static Renderer* instance;
};

