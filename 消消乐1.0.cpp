#pragma once
#include "stdafx.h"
#include "windowsx.h"
#include "消消乐1.0.h"
#include <comdef.h>
#include <GdiPlus.h>//引入gdi+头文件
#include "time.h"
#include "My_Struct.h"
#include "My_Image.h"
#include "My_Rule.h"
#include "My_Menu.h"
#include "My_Game.h"
#include "My_File.h"
#include <atlstr.h>
#pragma comment(lib, "Gdiplus.lib")//导入GDI+的库
#define MAX_LOADSTRING 100

int GTIMER = 0;
int gscore = 0;
int Round = 1;
int Num_Tip = 3;
using namespace std;
using namespace Gdiplus;

Block block[10][10];
Image *myImage[10];
Image *effect[5];

BOOL Is_Relax=false;
BOOL Is_Infinite=false;
BOOL Is_Saved=false;
static bool is_score_output = false;
static HWND H_Username;  //密码输入框
static HWND Mode_Relax;
static HWND Mode_Infinite;
static HWND Select_Mode;
static HWND Static_Rule;

ULONG_PTR gdiplusToken;
GdiplusStartupInput gdiplusStartupInput;

//ULONG_PTR gdiplusToken;
//GdiplusStartupInput gdiplusStartupInput;
// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
TCHAR szChildClass[] = TEXT("game");
TCHAR szChildClass_FILE[] = TEXT("keep in file");

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
ATOM                MyRegisterClass1(HINSTANCE hInstance);
ATOM				MyRegisterClass2(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildWndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildWndProc2(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void    CALLBACK    Timer(HWND, UINT, UINT, DWORD);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY10, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
	MyRegisterClass1(hInstance);
	MyRegisterClass2(hInstance);
    // 执行应用程序初始化:

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY10));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY10));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY10);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));


//	wcex.lpfnWndProc = ChildWndProc;
//	wcex.hIcon = NULL;
//	wcex.lpszClassName = szChildClass;

    return RegisterClassExW(&wcex);
}

ATOM MyRegisterClass1(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ChildWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY10));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY10);
	wcex.lpszClassName = szChildClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	return RegisterClassExW(&wcex);
}

ATOM MyRegisterClass2(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ChildWndProc2;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY10));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDI_MY10);
	wcex.lpszClassName = szChildClass_FILE;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED| WS_CAPTION| WS_SYSMENU,
      CW_USEDEFAULT, 0, PWIN_LEN, PWIN_WID, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
static HWND STAR_BUTTON = NULL;
static HWND GAME_WINDOW = NULL;
static HWND CHECKBOX_RE = NULL;
static HWND CHECKBOX_EX = NULL;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	static bool is_button = false;

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
			if ((HWND)lParam == Mode_Relax)
			{
				Is_Relax = true;
				Is_Infinite = false;
			}
			else if ((HWND)lParam == Mode_Infinite)
			{
				Is_Relax = false;
				Is_Infinite = true;
			}
            // 分析菜单选择:
			switch (wmId)
			{
			case IDM_ABOUT:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
			case IDB_END:
			{
				if (MessageBox(hWnd, TEXT("是否要退出游戏？"), TEXT("请确认"), MB_YESNO) == IDYES)
				{
					if (!Is_Saved)
					{
						KillTimer(hWnd, ID_STIMER);
						KillTimer(hWnd, ID_GTIMER);
						CString final;
						if (Is_Relax)
						{
							final.Format(L"你的时间为：%d秒 分数为：%d\n是否进行存档", GTIMER / 20, gscore);
						}
						if (Is_Infinite)
						{
							final.Format(L"你只闯到了第%d关,是否要存档", Round);
						}
						if (MessageBox(hWnd, final, TEXT("请确认"), MB_YESNO) == IDNO)
						{
							DestroyWindow(hWnd);
						}
						else
						{
							Is_Saved = true;
							CreateWindowW(szChildClass_FILE, NULL,
								WS_VISIBLE | WS_CAPTION | WS_POPUP | WS_SYSMENU,
								700, 400, 300, 300, hWnd, nullptr,
								(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), nullptr);
						}
					}
					else
					{
						DestroyWindow(hWnd);
					}
				}
			}
				break;
			case IDB_START:
			{
				if (Is_Infinite || Is_Relax)
				{
					if (Is_Infinite)
					{
						MessageBox(hWnd, TEXT("分数超过80才可过关哦！（每回合你有三次求助机会）"), TEXT("友情提示"), MB_OK);
					}
					DestroyWindow(Mode_Infinite);
					DestroyWindow(Mode_Relax);
					DestroyWindow(STAR_BUTTON);
					DestroyWindow(Static_Rule);
					GAME_WINDOW = CreateWindow(szChildClass,
						NULL,
						WS_CHILD | WS_VISIBLE,
						0, 0, CWIN_LEN - 15, CWIN_WID - 5,
						hWnd, (HMENU)9,
						(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
					//隐藏按钮
					//创建计时器
					CreateWindow(TEXT("BUTTON"),
						TEXT("重置"),
						WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
						PWIN_LEN - 150, PWIN_WID - 160, 133, 50,
						hWnd, (HMENU)IDB_RESET,
						(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

					CreateWindow(TEXT("BUTTON"),
						TEXT("结束游戏"),
						WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
						PWIN_LEN - 150, PWIN_WID - 110, 133, 50,
						hWnd, (HMENU)IDB_END,
						(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

					CreateWindow(TEXT("BUTTON"),
						TEXT("提示"),
						WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
						PWIN_LEN - 150, PWIN_WID - 210, 133, 50,
						hWnd, (HMENU)IDB_TIP,
						(HINSTANCE)GetWindowLongPtr(GAME_WINDOW, GWLP_HINSTANCE), NULL);

					SetTimer(hWnd, ID_GTIMER, 50, Timer);
					SetTimer(hWnd, ID_STIMER, 1000, Timer);
					is_button = !is_button;
					GTIMER = 0;

					RECT rc;
					GetClientRect(hWnd, &rc);
					InvalidateRect(hWnd, &rc, 1);
				}
				else 
				{
					MessageBox(hWnd, TEXT("请选择游戏模式"), TEXT("注意！"), MB_OK);
				}
				break;
			}
			case IDB_RESET:
			{
				if (Is_Infinite)
				{
					MessageBox(hWnd, TEXT("无尽闯关模式不可用！"), TEXT("注意！"), MB_OK);
					break;
				}
				//GTIMER = 0;
				//gscore = 0;
				My_Menu Q(hWnd);
				Q.intialize(block);
				My_Image I(hWnd);
				I.Put_All(block);

			}
				break;

			case IDB_TIP:
			{
				if (Is_Infinite)
				{
					if (Num_Tip > 0)
					{
						Num_Tip--;
					}
					else
					{
						MessageBox(hWnd, TEXT("使用超过次数限制了！"), TEXT("注意！"), MB_OK);
						break;
					}
				}
				if (GTIMER == 0)
				{
					break;
				}
				POINT Q, W;
				My_Rule::Help_Clean(block, &Q, &W);
				My_Image B(GAME_WINDOW);
				B.If_Selected(Q);
				B.If_Selected(W);
			}


            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
		
        }
        break;

	case WM_CTLCOLORSTATIC:
	{
		HDC hdc  = (HDC)wParam;
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		//break;
		return (LRESULT)GetStockObject(NULL_BRUSH);
	}


	case WM_CREATE:

	{		
		//透明 静态文本框，里面写规则
		Static_Rule=CreateWindow(
		L"static",
		L"APEX主题消消乐游戏规则：\n\n点击两个相邻的方块进行交换，交换后以这两个方块为中心若出现单行/列三个或以上连续相同的方块即可消除",
		WS_CHILD | WS_VISIBLE | SS_CENTER,
		0 , 300 , 210 , 100 ,
		hWnd, 
		(HMENU)16, 
		hInst, 
		NULL
		);
		LONG nRet = ::GetWindowLong(Static_Rule, GWL_EXSTYLE);
		nRet = nRet | WS_EX_TRANSPARENT;
		::SetWindowLong(Static_Rule, GWL_EXSTYLE, nRet);

		//开始游戏按钮
		STAR_BUTTON = CreateWindow(TEXT("BUTTON"),
			TEXT("开始游戏"),
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			0, (PWIN_WID - 108), 210, 50,
			hWnd, (HMENU)IDB_START,
			(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
		Mode_Relax = CreateWindow(L"BUTTON", L"休闲模式", BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE,
			0, 428, 105, 25, hWnd, (HMENU)13, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), 0);
		Mode_Infinite = CreateWindow(L"BUTTON", L"无尽闯关", BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE,
			105, 428, 105, 25, hWnd, (HMENU)14, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), 0);
		break;
		
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		SetBkMode(hdc, TRANSPARENT);
		if (is_button)
		{
			CString hour, min, sec, mins;
			if (Is_Infinite)
			{
				int countdown;
				countdown = TIME_LIMIT - TIME_CUT * (Round-1)  - GTIMER;
				min.Format(L"%d", countdown / 1200);
				sec.Format(L"%d", (countdown / 20)%60);
				mins.Format(L"%d", countdown * 5 % 100);
			}
			else
			{
				min.Format(L"%d", GTIMER / 1200);
				sec.Format(L"%d", (GTIMER / 20)%60);
				mins.Format(L"%d", GTIMER * 5 % 100);
			}
			TextOut(hdc, TIME_POS_X, TIME_POS_Y + 25, min, min.GetLength());
			TextOut(hdc, TIME_POS_X + 20, TIME_POS_Y + 25, TEXT(":"), strlen(":"));
			TextOut(hdc, TIME_POS_X + 30, TIME_POS_Y + 25, sec, sec.GetLength());
			TextOut(hdc, TIME_POS_X + 50, TIME_POS_Y + 25, TEXT(":"), strlen(":"));
			TextOut(hdc, TIME_POS_X + 60, TIME_POS_Y + 25, mins, mins.GetLength());
			TextOut(hdc, TIME_POS_X + 27, TIME_POS_Y, TEXT("TIME"), strlen("TIME"));
			TextOut(hdc, SCORE_POS_X + 20, SCORE_POS_Y, TEXT("SCORE"), strlen("SCORE"));

			if (Is_Infinite)
			{
				TextOut(hdc, ROUND_POS_X + 20, ROUND_POS_Y, TEXT("ROUND"), strlen("ROUND"));
				CString round;
				round.Format(L"%d", Round);
				TextOut(hdc, ROUND_POS_X + 38, ROUND_POS_Y + 25, round, round.GetLength());//修改刷新
			}
			if (is_score_output)
			{
				CString score;
				score.Format(L"%d", gscore);
				
				TextOut(hdc, SCORE_POS_X +38 , SCORE_POS_Y + 25, score, score.GetLength());
				is_score_output = false;

				EndPaint(hWnd, &ps);
			}

			break;
		}

		EndPaint(hWnd, &ps);
		My_Menu Q(hWnd);
		Q.Output_Menu();
		Q.intialize(block);

	}
	break;

	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("是否要退出游戏？"), TEXT("请确认"), MB_YESNO) == IDYES)
		{
			KillTimer(hWnd, ID_GTIMER);
			KillTimer(hWnd, ID_STIMER);
			DestroyWindow(hWnd);
		}
		else
			return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	My_Game mg;
	mg.GAME(hWnd, message, wParam, lParam, block);
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	My_File mf;
	mf.File(hWnd, message, wParam, lParam);
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void CALLBACK Timer(HWND hWnd, UINT message, UINT iTimerID, DWORD dwTime)
{
	switch (iTimerID)
	{
	case ID_GTIMER:
	{
		RECT rc;
		rc.bottom = TIME_POS_Y + 45;
		rc.left = TIME_POS_X;
		rc.right = TIME_POS_X + 90;
		rc.top = TIME_POS_Y + 25;
		InvalidateRect(hWnd, &rc, 1);
		GTIMER++;
		if (Is_Infinite)//选择无尽模式
		{
			if (gscore >= PASS_SCORE)//下一关
			{
				Round += 1;
				gscore = 0;
				GTIMER = -5;
				Num_Tip = 3;
				MessageBox(hWnd, TEXT("恭喜进入下一关！"), TEXT("恭喜"), MB_OK);
				RECT rc2;
				rc2.bottom = ROUND_POS_Y + 45;
				rc2.left = ROUND_POS_X;
				rc2.right = ROUND_POS_X + 90;
				rc2.top = ROUND_POS_Y + 25;
				My_Menu Q(hWnd);
				Q.intialize(block);
				My_Image I(hWnd);
				I.Put_All(block);
				InvalidateRect(hWnd, &rc2, 1);

				break;
			}
			if (GTIMER >= TIME_LIMIT - TIME_CUT * (Round- 1))
			{
				KillTimer(hWnd, ID_STIMER);
				KillTimer(hWnd, ID_GTIMER);
				//记录成绩
				MessageBox(hWnd, TEXT("game over!"), TEXT("请确认"), MB_OK);
				CString final;
				final.Format(L"你成功闯过%d关,是否进行存档", Round);
				if (MessageBox(hWnd, final, TEXT("请确认"), MB_YESNO) == IDNO)
				{
					DestroyWindow(hWnd);
				}
				else
				{
					Is_Saved = true;
					CreateWindowW(szChildClass_FILE, NULL,
						WS_VISIBLE | WS_CAPTION | WS_POPUP | WS_SYSMENU,
						700, 400, 300, 300, hWnd, nullptr,
						(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), nullptr);
				}
				break;
			}
		}
	}
	break;
	case ID_STIMER:
	{		
		RECT rc;
		rc.bottom = SCORE_POS_Y + 45;
		rc.left = SCORE_POS_X;
		rc.right = SCORE_POS_X + 90;
		rc.top = SCORE_POS_Y + 25;
		InvalidateRect(hWnd, &rc, 1);
		is_score_output = true;

		break;
	}
	}

}

