#pragma once
#include "stdafx.h"
#include <comdef.h>
#include "My_Image.h"
#include "消消乐1.0.h"
#include "time.h"
using namespace std;
using namespace Gdiplus;


void My_Image::Put_All(Block block[10][10])
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT rc;
	GetClientRect(hWnd, &rc);
	Bitmap bmp(int(rc.right), int(rc.bottom));//用来在上面画图
	Graphics bmpGraphics(&bmp);//用这个指针画图
	bmpGraphics.SetSmoothingMode(SmoothingModeAntiAlias);
	Image myimage0(L"0.jpg");
	Image myimage1(L"1.jpg");
	Image myimage2(L"2.jpg");
	Image myimage3(L"3.jpg");
	Image myimage4(L"4.jpg");
	Image myimage5(L"5.jpg");
	Image myimage6(L"6.jpg");
	Image myimage7(L"7.jpg");
	Image myimage8(L"8.jpg");
	Image myimage9(L"9.jpg");
	myImage[0] = &myimage0;
	myImage[1] = &myimage1;
	myImage[2] = &myimage2;
	myImage[3] = &myimage3;
	myImage[4] = &myimage4;
	myImage[5] = &myimage5;
	myImage[6] = &myimage6;
	myImage[7] = &myimage7;
	myImage[8] = &myimage8;
	myImage[9] = &myimage9;

	for (int k = 0; k < 10; k++)
	{
		for (int z = 0; z < 10; z++)
		{
			bmpGraphics.DrawImage(myImage[block[k][z].att], 50 * k, 50 * z, 50, 50);
		}
	}

	Graphics my_graphic(hWnd);
	CachedBitmap cachedBmp(&bmp, &my_graphic);
	my_graphic.DrawCachedBitmap(&cachedBmp, 0, 0);
	EndPaint(hWnd, &ps);
}

void My_Image::Is_Selected(int att, POINT a)
{
	if (att == 1)
	{
		HDC hdc;
		hdc = GetDC(hWnd);
		SetROP2(hdc, R2_NOT);
		SelectObject(hdc, GetStockObject(NULL_BRUSH));
		Rectangle(hdc, (a.x / 50) * 50, (a.y / 50) * 50, ((a.x / 50) + 1) * 50, ((a.y / 50) + 1) * 50);
		ReleaseDC(hWnd, hdc);
	}
}

void My_Image::If_Selected(POINT a)
{

	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOT);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Rectangle(hdc, (a.x / 50) * 50, (a.y / 50) * 50, ((a.x / 50) + 1) * 50, ((a.y / 50) + 1) * 50);
	ReleaseDC(hWnd, hdc);
}

void My_Image::Image_Bigger(Block block[10][10],POINT A)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT rc;
	GetClientRect(hWnd, &rc);
	Bitmap bmp(int(rc.right), int(rc.bottom));//用来在上面画图
	Graphics bmpGraphics(&bmp);//用这个指针画图
	bmpGraphics.SetSmoothingMode(SmoothingModeAntiAlias);
	Image myimage0(L"0.jpg");
	Image myimage1(L"1.jpg");
	Image myimage2(L"2.jpg");
	Image myimage3(L"3.jpg");
	Image myimage4(L"4.jpg");
	Image myimage5(L"5.jpg");
	Image myimage6(L"6.jpg");
	Image myimage7(L"7.jpg");
	Image myimage8(L"8.jpg");
	Image myimage9(L"9.jpg");
	myImage[0] = &myimage0;
	myImage[1] = &myimage1;
	myImage[2] = &myimage2;
	myImage[3] = &myimage3;
	myImage[4] = &myimage4;
	myImage[5] = &myimage5;
	myImage[6] = &myimage6;
	myImage[7] = &myimage7;
	myImage[8] = &myimage8;
	myImage[9] = &myimage9;
	bmpGraphics.DrawImage(myImage[block[A.x/50][A.y/50].att], (A.x / 50) * 50 - 3 , (A.y / 50) * 50 - 3 , 50 + 6, 50 + 6);

	Graphics my_graphic(hWnd);
	CachedBitmap cachedBmp(&bmp, &my_graphic);
	my_graphic.DrawCachedBitmap(&cachedBmp, 0, 0);
	EndPaint(hWnd, &ps);
}



void My_Image::Falling(Block block[10][10])
{
	for (int k = 0; k < 10; k++)
	{
		for (int j = 0; j <= 8; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (block[i][j + 1].att == 0)
				{
					int temp = block[i][j].att;
					block[i][j].att = block[i][j + 1].att;
					block[i][j + 1].att = temp;
				}
			}
		}
		Put_All(block);
	}

}

void My_Image::Re_Int(Block block[10][10])
{
	srand((unsigned)time(NULL));
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (block[i][j].att == 0)
			{
				block[i][j].att = rand() % 9 + 1;
			}
		}
	}
	Put_All(block);
}

void My_Image::Norm_Clean_Output(Block block[10][10])
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT rc;
	GetClientRect(hWnd, &rc);
	Bitmap bmp(int(rc.right), int(rc.bottom));//用来在上面画图
	Graphics bmpGraphics(&bmp);//用这个指针画图
	bmpGraphics.SetSmoothingMode(SmoothingModeAntiAlias);
	Image effect0(L"normal.jpg");
	effect[0] = &effect0;
	for (int k = 0; k < 10; k++)
	{
		for (int z = 0; z < 10; z++)
		{
			if (block[k][z].att == 11)
			{
				bmpGraphics.DrawImage(effect[0], 50 * k, 50 * z, 50, 50);
			}
		}
	}

	Graphics my_graphic(hWnd);
	CachedBitmap cachedBmp(&bmp, &my_graphic);
	my_graphic.DrawCachedBitmap(&cachedBmp, 0, 0);
	EndPaint(hWnd, &ps);
}

void My_Image::Explode_Output(Block block[10][10])
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	Graphics my_graphic(hWnd);
	Image effect1(L"explode.jpg");
	effect[1] = &effect1;
	for (int k = 0; k < 10; k++)
	{
		for (int z = 0; z < 10; z++)
		{
			if (block[k][z].att == 12)
			{
				my_graphic.DrawImage(effect[1], 50 * k, 50 * z, 50*3, 50*3);
				return;
			}
		}
	}
	EndPaint(hWnd, &ps);
}

void My_Image::Line_Clean_Output(Block block[10][10])
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	RECT rc;
	GetClientRect(hWnd, &rc);
	Bitmap bmp(int(rc.right), int(rc.bottom));//用来在上面画图
	Graphics bmpGraphics(&bmp);//用这个指针画图
	bmpGraphics.SetSmoothingMode(SmoothingModeAntiAlias);
	Image effect2(L"line.jpg");
	effect[2] = &effect2;
	for (int k = 0; k < 10; k++)
	{
		for (int z = 0; z < 10; z++)
		{
			if (block[k][z].att == 13)
			{
				bmpGraphics.DrawImage(effect[2], 50 * k, 50 * z, 50, 50);
			}
		}
	}

	Graphics my_graphic(hWnd);
	CachedBitmap cachedBmp(&bmp, &my_graphic);
	my_graphic.DrawCachedBitmap(&cachedBmp, 0, 0);
	EndPaint(hWnd, &ps);
}