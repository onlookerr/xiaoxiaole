#pragma once

#include "stdafx.h"
#include "resource.h"
#include <comdef.h>
#include <GdiPlus.h>//引入gdi+头文件
#pragma comment(lib, "Gdiplus.lib")//导入GDI+的库

//按钮ID
#define IDB_START     3301  
#define IDB_END       3302  
#define IDB_RESET     3303
#define IDB_TIP		  3304
#define IDB_USERNAME  3304

//窗口大小信息
#define PWIN_LEN      650
#define PWIN_WID      560
#define CWIN_LEN      515
#define CWIN_WID      560

//TIMER的ID值
#define ID_GTIMER        1
#define ID_STIMER        2

//需要输出的文本的位置信息
#define TIME_POS_Y		100
#define TIME_POS_X		520
#define SCORE_POS_Y		180
#define SCORE_POS_X		520
#define ROUND_POS_Y		30
#define ROUND_POS_X		520

//闯关模式的时间限制
#define TIME_LIMIT		1000
//每过一关减少的时间
#define TIME_CUT		100
//过一关所需要的分数
#define PASS_SCORE		80

using namespace std;
using namespace Gdiplus;

//需要在别的文件引用的实例句柄
extern HINSTANCE hInst;
//gdi绘图所需要的
extern ULONG_PTR gdiplusToken;
extern GdiplusStartupInput gdiplusStartupInput;
//绘图所用的图片
extern Image *myImage[10];
//特效所用的图片
extern Image *effect[5];
//游戏分数
extern int gscore;
//游戏时间
extern int GTIMER;
//游戏回合
extern int Round;
//是否选择休闲模式
extern BOOL Is_Relax;
//是否选择无尽闯关模式
extern BOOL Is_Infinite;
//是否进行了保存
extern BOOL Is_Saved;