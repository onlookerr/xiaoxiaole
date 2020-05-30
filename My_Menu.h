#pragma once
#include "stdafx.h"
#include <comdef.h>
#include <GdiPlus.h>//引入gdi+头文件
#pragma comment(lib, "Gdiplus.lib")//导入GDI+的库
#include "My_Struct.h"
#include "消消乐1.0.h"

using namespace std;
using namespace Gdiplus;


extern ULONG_PTR gdiplusToken;
extern GdiplusStartupInput gdiplusStartupInput;

class My_Menu
{
public:
	My_Menu(HWND hWnd)
	{
		this->hWnd = hWnd;

	}
	HWND hWnd;
	void Output_Menu();
	void Output_Time(int temp);
	void Creat_Window();
	void intialize(Block block[10][10]);
};