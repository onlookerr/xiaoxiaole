#include "stdafx.h"
#include "My_File.h"
#include "消消乐1.0.h"
#include <stdio.h>
void TcharToChar(const TCHAR * tchar, char * _char);//转换字符类型
void CharToTchar(const char * _char, TCHAR * tchar);
#define B_SAVE		3000
LRESULT My_File::File(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND staticwin = NULL;
	static HWND editwin = NULL;
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case B_SAVE:
		{
			static TCHAR szUsername[100];
			GetWindowText(editwin, szUsername, 100);
			if (Is_Relax)
			{
				if (MessageBox(hWnd, szUsername, TEXT("请确认"), MB_YESNO) == IDYES)
				{
					HANDLE hFile;
					hFile = CreateFile(L"relax.txt",
						GENERIC_WRITE,
						FILE_SHARE_WRITE,
						NULL,
						OPEN_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//使用CreatFile这个API函数打开文件   
					SetFilePointer(hFile, 0, NULL, FILE_END);
					DWORD Written;
					char temp[100];
					TcharToChar(szUsername, temp);
					WriteFile(hFile, temp, strlen(temp), &Written, NULL);
					WriteFile(hFile, "	", strlen("	"), &Written, NULL);
					char num_s[10];
					sprintf_s(num_s, "%d", gscore);
					WriteFile(hFile, "得分:", strlen("得分:"), &Written, NULL);
					WriteFile(hFile, num_s, strlen(num_s), &Written, NULL);
					WriteFile(hFile, "	", strlen("	"), &Written, NULL);
					char num_t[10];
					sprintf_s(num_t, "%d", GTIMER / 20);
					WriteFile(hFile, "用时:", strlen("用时:"), &Written, NULL);
					WriteFile(hFile, num_t, strlen(num_t), &Written, NULL);
					WriteFile(hFile, " 秒", strlen(" 秒"), &Written, NULL);
					WriteFile(hFile, "\r\n", strlen("\r\n"), &Written, NULL);
					CloseHandle(hFile);//关闭句柄   


					gscore = 0;
					GTIMER = 0;


					HANDLE RhFile;//定义一个句柄。   
					RhFile = CreateFile(L"relax.txt",
						GENERIC_READ,
						FILE_SHARE_READ,
						NULL,
						OPEN_EXISTING,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//使用CreatFile这个API函数打开文件   
					DWORD dwDataLen;
					char FileContent[1000];
					ReadFile(RhFile, FileContent, 1000, &dwDataLen, NULL);//读取数据   
					FileContent[dwDataLen] = 0;//将数组未尾设零。   
					CloseHandle(RhFile);//关闭句柄   
					TCHAR Tfilecontent[100];
					CharToTchar(FileContent, Tfilecontent);
					MessageBox(hWnd, Tfilecontent, TEXT("成绩"), MB_OK);//输出结果  
					DestroyWindow(hWnd);
				}
			}

			if (Is_Infinite)
			{
				if (MessageBox(hWnd, szUsername, TEXT("请确认"), MB_YESNO) == IDYES)
				{
					HANDLE hFile;
					hFile = CreateFile(L"infinite.txt",
						GENERIC_WRITE,
						FILE_SHARE_WRITE,
						NULL,
						OPEN_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//使用CreatFile这个API函数打开文件   
					SetFilePointer(hFile, 0, NULL, FILE_END);
					DWORD Written;
					char temp[100];
					TcharToChar(szUsername, temp);
					WriteFile(hFile, temp, strlen(temp), &Written, NULL);
					WriteFile(hFile, "	", strlen("	"), &Written, NULL);
					char num[10];
					sprintf_s(num, "%d", Round);
					WriteFile(hFile, "成绩:", strlen("成绩:"), &Written, NULL);
					WriteFile(hFile, num, strlen(num), &Written, NULL);
					WriteFile(hFile, "关", strlen("关"), &Written, NULL);
					WriteFile(hFile, "\r\n", strlen("\r\n"), &Written, NULL);
					CloseHandle(hFile);//关闭句柄   

					gscore = 0;
					GTIMER = 0;


					HANDLE RhFile;//定义一个句柄。   
					RhFile = CreateFile(L"infinite.txt",
						GENERIC_READ,
						FILE_SHARE_READ,
						NULL,
						OPEN_EXISTING,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//使用CreatFile这个API函数打开文件   
					DWORD dwDataLen;
					char FileContent[1000];
					ReadFile(RhFile, FileContent, 1000, &dwDataLen, NULL);//读取数据   
					FileContent[dwDataLen] = 0;//将数组未尾设零。   
					CloseHandle(RhFile);//关闭句柄   
					TCHAR Tfilecontent[100];
					CharToTchar(FileContent, Tfilecontent);
					MessageBox(hWnd, Tfilecontent, TEXT("成绩"), MB_OK);//输出结果  
					DestroyWindow(hWnd);
				}
			}

			break;
		}
		break;
		}

		break;
	}
	case WM_CREATE:
	{
		staticwin = CreateWindow(TEXT("static"), TEXT("你的名字："),
			WS_CHILD | WS_VISIBLE,
			10, 25, 200, 24,
			hWnd, NULL, NULL, NULL);
		editwin = CreateWindow(TEXT("edit"), TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER /*边框*/ | ES_AUTOHSCROLL /*水平滚动*/,
			80, 25, 150, 26,
			hWnd, NULL, NULL, NULL);
		CreateWindow(L"Button", L"确定", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			80, 100, 100, 50, hWnd, (HMENU)B_SAVE, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
		break;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//获取字节长度   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//将tchar值赋给_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

void CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}