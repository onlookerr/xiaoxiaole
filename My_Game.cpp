#include "stdafx.h"
#include "My_Game.h"
#include "消消乐1.0.h"
extern int gscore;
extern HINSTANCE hInst;

#define IDB_TIP		  3304

LRESULT My_Game::GAME(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, Block block[10][10])
{
	static BOOL Is_Menu_End = false;
	static int mouse_note = -1;
	static int rec_num = -1;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	switch (message)
	{
		static POINT Temp_P;
		static POINT Valid_1, Valid_2;
		static POINT mouse_move;
		/*
		case WM_LBUTTONDOWN:
		{
			HDC hdc;
			hdc = GetDC(hWnd);
			SetROP2(hdc, R2_NOT);
			SelectObject(hdc, GetStockObject(NULL_BRUSH));
			Rectangle(hdc, 20, 20, 50, 50);
			ReleaseDC(hWnd, hdc);
		}
		break;
		}
		*/

	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

	}
	break;
	/*
		case WM_CREATE:
		{
			CreateWindow(szChildClass,
				NULL,
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				30, 30, 200, 50,
				hWnd, (HMENU)1,
				((LPCREATESTRUCT)lParam)->hInstance, NULL);

			break;
		}

	*/

	case WM_LBUTTONDOWN:
	{
		Temp_P.x = GET_X_LPARAM(lParam);
		Temp_P.y = GET_Y_LPARAM(lParam);

		if (mouse_note == -1 || mouse_note == 0)
		{
			Valid_1 = Temp_P;
			mouse_note = 1;
			rec_num++;
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			My_Image A(hWnd);
			A.Is_Selected(mouse_note, Valid_1);
			EndPaint(hWnd, &ps);
			break;
		}
		else if (mouse_note == 1)
		{
			Valid_2 = Temp_P;
			mouse_note = 0;
			rec_num++;
			My_Rule B(Valid_1, Valid_2);
			My_Image A(hWnd);
			B.Exchange(block);
			A.Put_All(block);
			A.Is_Selected(mouse_note, Valid_2);
			Sleep(200);

			if (B.Is_Exchange())
			{
				if (B.Is_More_Than_3(block, Valid_1))
				{
					B.Cross_Method(block, Valid_1, 1);
				}
				if (B.Is_More_Than_3(block, Valid_2))
				{
					B.Cross_Method(block, Valid_2, 2);
				}

				if (!B.Is_More_Than_3(block, Valid_1) && !B.Is_More_Than_3(block, Valid_2))
				{
					B.Exchange(block);
					A.Put_All(block);
					break;
				}

				int temp = 0;
				temp = B.Is_Line_Clean(block);
				//关于消除的逻辑判断
				//
				//如果执行了整行消除，则不执行爆炸判断
				if (temp)
				{
					if (block[Valid_1.x / 50][Valid_1.y / 50].att == block[Valid_2.x / 50][Valid_2.y / 50].att && B.count1 == B.count2)
					{
						gscore += temp / 2;
					}
					else
						gscore += temp;
					B.Line_Clean(block);
					A.Line_Clean_Output(block);
					Sleep(100);
					B.Num_to_Normal(block,13);
					B.Clean_Up(block);
					A.Put_All(block);
					A.Falling(block);
					A.Re_Int(block);
					break;
				}
				//进行爆炸判断
				else
				{
					if (B.count1 + B.count2 >= 5)
					{
						if (block[Valid_1.x / 50][Valid_1.y / 50].att == block[Valid_2.x / 50][Valid_2.y / 50].att && B.count1 == B.count2)
						{
							if ((B.count1 + B.count2) / 2 >= 5)
							{
								gscore += B.Explode(block);
								A.Explode_Output(block);
								B.Num_to_Normal(block, 12);
							}
							else
							{
								B.Normal_Clean(block);
								A.Norm_Clean_Output(block);
								B.Num_to_Normal(block, 12);
								Sleep(100);
							}
						}
						else
						{
							if (B.count1 + B.count2 >= 5)
							{
								gscore += B.Explode(block);
								A.Explode_Output(block);
								B.Num_to_Normal(block, 12);
							}
						}
					}
					//无效果判断
					else
					{
						B.Normal_Clean(block);
						A.Norm_Clean_Output(block);
						B.Num_to_Normal(block, 12);
						//Sleep(100);
					}

					gscore+=B.Clean_Up(block);
					A.Put_All(block);
					A.Falling(block);
					A.Re_Int(block);
				}
			}
			else
			{
				B.Exchange(block);
				A.Put_All(block);
			}
			break;
		}

	}
	//双缓冲
/*
	case WM_MOUSEMOVE:
	{
		if (block[GET_X_LPARAM(lParam)][GET_Y_LPARAM(lParam)].att != block[mouse_move.x][mouse_move.y].att )
		{
			mouse_move.x = GET_X_LPARAM(lParam);
			mouse_move.y = GET_Y_LPARAM(lParam);
			//GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			My_Image A(hWnd);
			A.Put_All(block);
			//A.If_Selected(hWnd, mouse_move);
			A.Image_Bigger(block, mouse_move);

			break;
		}
		else
		break;
	}
*/
	case WM_PAINT:
	{
		//GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		My_Image A(hWnd);
		A.Put_All(block);
		//TextOut(hdc, 100, 200, TEXT("消消乐"), 3);


	}
	break;

	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("是否要退出游戏？"), TEXT("请确认"), MB_YESNO) == IDYES)
			DestroyWindow(hWnd);
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