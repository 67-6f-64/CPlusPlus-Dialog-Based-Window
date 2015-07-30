#pragma once

#include <Windows.h>

class DialogWindow
{
private:
	HWND dialog{};
public:
	DialogWindow();
	~DialogWindow();

	void setHwnd(HWND hwnd) { this->dialog = hwnd; }
	HWND getHwnd() { return this->dialog; }
	BOOL CreateDialogWindow(HWND hwnd);
};

BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);

extern DialogWindow myDialog;
