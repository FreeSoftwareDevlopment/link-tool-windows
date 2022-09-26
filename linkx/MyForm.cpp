#include "pch.h"
#include "MyForm.h"

#include "partos.hpp"
#include "dafx.h"
#include <filesystem>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace fs = std::filesystem;

void linkx::MyForm::enableDisable(bool bend)
{
	button1->Enabled = bend;
	button2->Enabled = bend;
	button3->Enabled = bend;
}

enum linktype { winlnk, hardlink, softlink, copy };

void rRun(linktype l) {
	switch (l) {
	case winlnk:
		partOS([](c a, c b) { if (CreateLink(a, b)) throw std::exception("Link error"); }, 1);
		break;
	case hardlink:
		partOS([](c a, c b) { fs::create_hard_link(a, b); });
		break;
	case softlink:
		partOS([](c a, c b) { fs::create_symlink(a, b); });
		break;
	default:
		partOS([](c a, c b) { fs::copy(a, b); });
	}
}

System::Void linkx::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	enableDisable(0);
	rRun(winlnk);
	enableDisable(1);
	return System::Void();
}

System::Void linkx::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	enableDisable(0);
	rRun(hardlink);
	enableDisable(1);
	return System::Void();
}

System::Void linkx::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	enableDisable(0);
	rRun(softlink);
	enableDisable(1);
	return System::Void();
}

System::Void linkx::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	enableDisable(0);
	rRun(copy);
	enableDisable(1);
	return System::Void();
}
