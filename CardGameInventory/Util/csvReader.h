#pragma once

#include <vector>

#include <string>


class csvReader
{
public:
	static std::vector<std::string> ParseLine(const std::string& inLine);

	static bool ReadAll(
		const std::string& path,
		std::vector<std::vector<std::string>>& outRows
	);

	static int ToInt(const std::string& s);
	static inline std::wstring UTF8toWide(const std::string& utf8);
	
private:
	static void TrimCR(std::string& s);
};

