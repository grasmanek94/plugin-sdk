#pragma once
#include <Windows.h>
#include <stdio.h>

namespace plugin
{
	template <typename... ArgTypes> bool Error(char *format, ArgTypes... Args) {
		char text[512];
		sprintf_s(text, format, Args...);
		MessageBoxA(NULL, text, "plugin-sdk", 0);
		return false;
	}

	template <typename... ArgTypes> bool Error(wchar_t *format, ArgTypes... Args) {
		wchar_t text[512];
		swprintf_s(text, format, Args...);
		MessageBoxW(NULL, text, L"plugin-sdk", 0);
		return false;
	}
}