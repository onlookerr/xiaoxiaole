#pragma once
#include "stdafx.h"
#include "windowsx.h"
#include "消消乐1.0.h"
#include <comdef.h>
#include <GdiPlus.h>//引入gdi+头文件
#pragma comment(lib, "Gdiplus.lib")//导入GDI+的库
#include "time.h"
#include "My_Struct.h"
#include "My_Image.h"
#include "My_Rule.h"
#include "My_Menu.h"
using namespace std;
using namespace Gdiplus;
class My_Game
{
public:
	LRESULT GAME(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, Block block[10][10]);
};

