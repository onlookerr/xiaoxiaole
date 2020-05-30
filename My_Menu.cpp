#include "stdafx.h"
#include "My_Menu.h"
#include "time.h"
#include <atlstr.h>
void My_Menu::Output_Menu()
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	Graphics my_graphic(hWnd);
	Image menu_bg(L"menu_bg.jpg");
	
	RECT rc;
	GetClientRect(hWnd, &rc);
	my_graphic.DrawImage(&menu_bg, 0, 0, rc.right, rc.bottom);
	//DrawText(hdc, TEXT("消消乐"),-1,&rc, DT_CENTER);
	TextOut(hdc,100,200, TEXT("消消乐"),10);
	//TextOut(hdc, 510, 200, TEXT("time:"), strlen("time:"));

	//int ret = MessageBox(NULL,TEXT("开始游戏吗？"),TEXT("请确认"),MB_YESNO | MB_ICONQUESTION);
	//if (ret == IDYES)

	EndPaint(hWnd, &ps);

	
}

void My_Menu::intialize(Block block[10][10])
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			block[i][j].x = i;
			block[i][j].y = j;
			block[i][j].att = rand() % 9 + 1;
		}
	}
}

void My_Menu::Output_Time(int temp)
{
	int hour, min, sec;
	hour = temp / 3600;
	min = (temp % 3600) / 60;
	sec = (temp % 60);
	CString str_h,str_min,str_sec;
	str_h.Format(_T("%d"), hour);
	str_min.Format(_T("%d"), min);
	str_sec.Format(_T("%d"), sec);
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);

	RECT rc;
	GetClientRect(hWnd, &rc);
	//TextOut(hdc, 20, 100, str_h, str_h.GetLength());
	//TextOut(hdc, 20, 120, str_min, str_min.GetLength());
	//TextOut(hdc, 20, 140, str_sec, str_sec.GetLength());
	DrawText(
		hdc,
		TEXT("你好，欢迎来到C语言中文网"),
		-1,
		&rc,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER
	);

	EndPaint(hWnd, &ps);
	

}