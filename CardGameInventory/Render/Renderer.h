#pragma once

#include "Card/CardInfo.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Submit(const CardInfo& info);

private:
	void Clear();
	void Render(const CardInfo& info);

private:

};

