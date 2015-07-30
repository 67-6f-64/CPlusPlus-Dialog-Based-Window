#include "main.h"

MainWindow window;

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

MainWindow::MainWindow()
{
	this->hwnd = NULL;
}

MainWindow::~MainWindow()
{

}

BOOL MainWindow::CreateMyWindow(HINSTANCE hInst)
{
	/* REGISTER CLASSEX */
	WNDCLASSEX wce;
	ZeroMemory(&wce, sizeof(WNDCLASSEX));
	wce.cbSize = sizeof(WNDCLASSEX);
	wce.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wce.hCursor = LoadCursor(NULL, IDC_ARROW);
	wce.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wce.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wce.hInstance = hInst;
	wce.lpfnWndProc = WinProc;
	wce.lpszClassName = "main";
	wce.lpszMenuName = NULL;
	wce.style = CS_HREDRAW | CS_VREDRAW;
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;

	if (!RegisterClassEx(&wce))
	{
		MessageBox(NULL, "Could not Register Class", "RcEX", MB_ICONERROR);
		return FALSE;
	}

	/* CREATE WINDOW */
	int w = 400;
	int h = 300;
	int x = GetSystemMetrics(SM_CXSCREEN) / 2 - w / 2;
	int y = GetSystemMetrics(SM_CYSCREEN) / 2 - h / 2;

	window.SetHwnd(CreateWindowEx(0, "main", "External", WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX, x, y, w, h, NULL, NULL, hInst, NULL));
	if (!window.GetHwnd())
	{
		return FALSE;
	}

	return TRUE;
}



