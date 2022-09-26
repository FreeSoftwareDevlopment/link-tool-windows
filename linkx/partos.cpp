#include "pch.h"
#include "partos.hpp"
#include <nfd.h>
#include <filesystem>
namespace fs = std::filesystem;
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <exception>
#include <string>

void partOS(void (*f) (c, c), bool lnk) {
	nfdchar_t* outPath = NULL;
	nfdresult_t result = NFD_OpenDialog(NULL, NULL, &outPath);

	if (result == NFD_OKAY) {
		nfdchar_t* outPath2 = NULL;
		result = NFD_SaveDialog(lnk ? "lnk" : NULL, NULL, &outPath2);

		if (result == NFD_OKAY) {
			if (!fs::exists(outPath))
				MessageBoxA(NULL, "Source File didn't exists!", "linkx", MB_OK | MB_ICONERROR);
			else {
				try {
					if (lnk) {
						fs::path __x = outPath2;
						if (__x.extension().string() != "lnk")
							__x += ".lnk";
						f(outPath, __x.string().c_str());
					}
					else {
						f(outPath, outPath2);
					}
				}
				catch (std::exception& ex) {
					MessageBoxA(NULL, ex.what(), "linkx - filesystemerror", MB_OK | MB_ICONERROR);
				}
			}
			free(outPath2);
		}
		free(outPath);
	}
	else {
		return;
	}
}
