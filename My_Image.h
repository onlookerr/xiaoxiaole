#pragma once
#include "stdafx.h"
#include <GdiPlus.h>//引入gdi+头文件
#pragma comment(lib, "Gdiplus.lib")//导入GDI+的库
#include "My_Struct.h"
#include "消消乐1.0.h"

using namespace std;
using namespace Gdiplus;


extern ULONG_PTR gdiplusToken;
extern GdiplusStartupInput gdiplusStartupInput;
class My_Image
{

public:
	My_Image(Graphics *bmpGraphics)
	{

		this->bmpGraphics = bmpGraphics;

	}
	My_Image(HWND hWnd)
	{
		this->hWnd = hWnd;

	}



public:
	HWND hWnd;
	Graphics *bmpGraphics;
	Graphics *my_graphic;
	int x;
	int y;
	void Put_All(Block block[10][10]);
	void Is_Selected(int att, POINT a);
	void If_Selected(POINT a);
	void Image_Bigger(Block block[10][10], POINT A);
	void Falling(Block block[10][10]);
	void Re_Int(Block block[10][10]);
	void Explode_Output(Block block[10][10]);
	void Line_Clean_Output(Block block[10][10]);
	void Norm_Clean_Output(Block block[10][10]);
private:


};