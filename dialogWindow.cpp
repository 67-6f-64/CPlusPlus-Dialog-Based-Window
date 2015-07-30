#include "dialogWindow.h"
#include "resource.h"
#include "main.h"

DialogWindow myDialog;

BOOL CALLBACK DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_INITDIALOG:
	{
		//align dialogframe to window size
		RECT rect;
		GetClientRect(window.GetHwnd(), &rect);
		int w = rect.right - rect.left;
		int h = rect.bottom - rect.top;
		SetWindowPos(hwnd, HWND_TOP, 0, 0, w, h, SWP_SHOWWINDOW);
		return TRUE;
	}break;

	case WM_SIZE:
	{
		//if resize mainWindow resize dialog too
		RECT rect;
		GetClientRect(window.GetHwnd(), &rect);
		int w = rect.right - rect.left;
		int h = rect.bottom - rect.top;
		MoveWindow(hwnd, 0, 0, w, h, TRUE);
		return TRUE;
	}break;

	default:
		return TRUE;
	}

	return 0;
}

DialogWindow::DialogWindow()
{
	this->dialog = NULL;
}

DialogWindow::~DialogWindow()
{
}

BOOL DialogWindow::CreateDialogWindow(HWND hwnd)
{
	myDialog.setHwnd(CreateDialog(NULL, MAKEINTRESOURCE(mainDialog), hwnd, DialogProc));
	if (!myDialog.getHwnd())
		return FALSE;

	return TRUE;
}
