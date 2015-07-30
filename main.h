#pragma once

#include <Windows.h>

class MainWindow
{
private:
	HWND hwnd{};
public:
	MainWindow();
	~MainWindow();

	HWND GetHwnd() { return this->hwnd; }
	void SetHwnd(HWND hWnd) { this->hwnd = hWnd; }
	BOOL CreateMyWindow(HINSTANCE hInst);

};

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

extern MainWindow window;
