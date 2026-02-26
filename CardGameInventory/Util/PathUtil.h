#pragma once

#include <string>
#include <Windows.h>


// Extract Target Directory based on the las '\' || '/'.
namespace PathUtil
{
	// Returns the .exe file directory.
	inline std::string GetExeDir()
	{
		char buffer[MAX_PATH] = {};
		const DWORD len = GetModuleFileNameA(nullptr, buffer, MAX_PATH);
		if (len == 0 || len >= MAX_PATH) return {};

		std::string fullPath(buffer, buffer + len);

		// Extract directory.
		const size_t pos = fullPath.rfind("\\");
		if (pos == std::string::npos) return{};


		return fullPath.substr(0, pos);
	}

	inline std::string JoinPath(const std::string& a, const std::string& b)
	{
		if (a.empty()) return b;
		if (b.empty()) return a;

		const char last = a.back(); // if it fails, try a[a.size()-1].
		if (last == '\\' || last == '/') return a + b;

		return a + "\\" + b;
	}
}