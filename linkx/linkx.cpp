#include "pch.h"
#include "MyForm.h"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

using namespace System;

using namespace System::Windows::Forms;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	linkx::MyForm form;

	Application::Run(% form);
	return 0;
}
