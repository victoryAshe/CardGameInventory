#include "CsvReader.h"

#include <fstream>
#include <vector>

#include <Windows.h>

std::vector<std::string> CsvReader::ParseLine(const std::string& inLine)
{
	std::string line = inLine;
	TrimCR(line);

	std::vector<std::string> fields;
	std::string field = "";

	for (size_t i = 0; i < line.size(); ++i)
	{
		char c = line[i];
		if (c == ',')
		{
			fields.push_back(field);
			field.clear();
		}
		else
		{
			field.push_back(c);
		}

	}
	fields.push_back(field);


	return fields;
}

bool CsvReader::ReadAll(const std::string& path, std::vector<std::vector<std::string>>& outRows)
{
	std::ifstream file(path);
	if (!file.is_open()) return false;

	outRows.clear();

	std::string line;
	while (std::getline(file, line))
	{
		TrimCR(line);
		if (line.empty()) continue;

		outRows.push_back(ParseLine(line));
	}

	return true;
}

int CsvReader::ToInt(const std::string& s)
{
	return std::atoi(s.c_str());
}

std::wstring CsvReader::UTF8toWide(const std::string& utf8)
{
	if (utf8.empty()) return std::wstring();

	int size = MultiByteToWideChar(
		CP_UTF8,
		0,
		utf8.data(),
		static_cast<int>(utf8.size()),
		nullptr,
		0
	);
	if (size <= 0) return std::wstring();

	std::wstring wide;
	wide.resize(size);

	MultiByteToWideChar(
		CP_UTF8,
		0,
		utf8.data(),
		static_cast<int>(utf8.size()),
		&wide[0],
		size
	);

	return wide;
}


void CsvReader::TrimCR(std::string& s)
{
	if (!s.empty() && s.back() == '\r') s.pop_back();
}
