#include "main.h"
#include "dialogWindow.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!window.CreateMyWindow(hInstance))
	{
		return 1;
	}

	ShowWindow(window.GetHwnd(), nCmdShow);
	UpdateWindow(window.GetHwnd());

	if (!myDialog.CreateDialogWindow(window.GetHwnd()))
	{
		return 1;
	}
	
	ShowWindow(myDialog.getHwnd(), nCmdShow);
	UpdateWindow(myDialog.getHwnd());

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		if (!IsDialogMessage(myDialog.getHwnd(), &msg)) // need this to keyboard navigation
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(1);
	}

	return msg.wParam;
}
