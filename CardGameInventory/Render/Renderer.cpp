#include "Renderer.h"

#include <iostream>

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Submit(const CardInfo& info)
{
    Clear();
    Render(info);
}

void Renderer::Clear()
{
    system("cls");
}

void Renderer::Render(const CardInfo& info)
{
    std::cout << "[Card Info]\n";
    std::cout << "ID: " << info.id << "\n";
    std::wcout << L"Name: " << info.name << "\n";
    std::cout << "Type: " << cardTypeEnumMap[info.type] << "\n";
    std::cout << "Cost: " << info.cost << "\n";
    std::cout << "Rarity: " << info.rarity << "\n";
}
