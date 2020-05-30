#pragma once
#include "stdafx.h"
#include "windowsx.h"
#include "My_Struct.h"
#include "ÏûÏûÀÖ1.0.h"
extern int gscore;

class My_Rule
{
public:
	My_Rule(POINT A,POINT B)
	{
		this->A = A;
		this->B = B;
	}
public:
	bool Is_Exchange();
	void Exchange(Block My_Block[10][10]);
	void Cross_Method(Block My_Block[10][10],POINT C, int t);
	void Cross_Method(Block My_Block[10][10], POINT C);
	int Clean_Up(Block My_Block[10][10]);
	bool Is_More_Than_3(Block MyBlock[10][10], POINT C);
	bool Is_Row_num(Block MyBlock[10][10], POINT C, int num);
	bool Is_Line_num(Block MyBlock[10][10], POINT C, int num);
	int Explode(Block block[10][10]);
	void Normal_Clean(Block block[10][10]);
	int Is_Line_Clean(Block block[10][10]);
	void Line_Clean(Block block[10][10]);
	void Num_to_Normal(Block block[10][10],int att);
	static BOOL Help_Clean(Block block[10][10],POINT*,POINT*);
	int count1 = 0;
	int count2 = 0;
private:
	
	BOOL Is_line_clean = false;
	POINT A, B;
	POINT Need_Clear1[20];
	POINT Need_Clear2[20];

};