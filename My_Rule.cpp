#include "stdafx.h"
#include "My_Rule.h"


bool My_Rule::Is_Exchange()
{
	if (((A.x/50 == B.x / 50) && (A.y/50 == B.y / 50 + 1)) ||
		((A.x/50 == B.x / 50) && (A.y/50== B.y / 50 - 1)) ||
		((A.x/50  == B.x / 50 - 1) && (A.y/50 == B.y / 50)) ||
		((A.x/50  == B.x / 50 + 1) && (A.y/50 == B.y / 50)))
	
		return true;
	
	else
		return false;
}

void My_Rule::Exchange(Block My_Block[10][10])
{
	int temp = 100;
	temp = My_Block[A.x/50][A.y/50].att;
	My_Block[A.x/50][A.y/50].att = My_Block[B.x/50][B.y/50].att;
	My_Block[B.x/50][B.y/50].att = temp;
}

void My_Rule::Cross_Method(Block My_Block[10][10],POINT C,int t)//用坐标
{
	My_Block[C.x/50][C.y/50].is_visited = true;
	if (t == 1)
	{
		Need_Clear1[count1].x = C.x;
		Need_Clear1[count1].y = C.y;
		count1 += 1;
	}
	if(t == 2)
	{
		Need_Clear2[count2].x = C.x;
		Need_Clear2[count2].y = C.y;
		count2 += 1;
	}


	if (C.x/50 + 1 <= 9)
	{
		if (My_Block[C.x/50 + 1][C.y/50].is_visited == false)
		{
			if (My_Block[C.x/50][C.y/50].att == My_Block[C.x/50 + 1][C.y/50].att)
			{
				POINT C1;
				C1.x = C.x + 50;
				C1.y = C.y;
				Cross_Method(My_Block, C1, t);
			}

		}
	}

	if (C.x/50 - 1 >= 0)
	{
		if (My_Block[C.x/50 - 1][C.y/50].is_visited == false)
		{
			if (My_Block[C.x/50][C.y/50].att == My_Block[C.x/50 - 1][C.y/50].att)
			{
				POINT C1;
				C1.x = C.x - 50;
				C1.y = C.y;
				Cross_Method(My_Block, C1, t);
			}
		}
	}

	if (C.y/50 + 1 <= 9)
	{
		if (My_Block[C.x/50][C.y/50 + 1].is_visited == false)
		{
			if (My_Block[C.x/50][C.y/50].att == My_Block[C.x/50][C.y/50 + 1].att)
			{
				POINT C1;
				C1.x = C.x;
				C1.y = C.y + 50;
				Cross_Method(My_Block, C1, t);
			}
		}
	}

	if (C.y/50 - 1 >= 0)
	{
		if (My_Block[C.x/50][C.y/50 - 1].is_visited == false)
		{
			if (My_Block[C.x/50][C.y/50].att == My_Block[C.x/50][C.y/50 - 1].att)
			{
				POINT C1;
				C1.x = C.x;
				C1.y = C.y - 50;
				Cross_Method(My_Block, C1, t);
			}
		}
	}

	My_Block[C.x/50][C.y/50].is_visited = false;
}

void My_Rule::Cross_Method(Block My_Block[10][10], POINT C)//用坐标
{
	if (C.x / 50 + 1 <= 9)
	{
		if (My_Block[C.x / 50 + 1][C.y / 50].is_visited == false)
		{
			if (My_Block[C.x / 50][C.y / 50].att == My_Block[C.x / 50 + 1][C.y / 50].att)
			{
				POINT C1;
				C1.x = C.x + 50;
				C1.y = C.y;
				Cross_Method(My_Block, C1);
			}

		}
	}

	if (C.x / 50 - 1 >= 0)
	{
		if (My_Block[C.x / 50 - 1][C.y / 50].is_visited == false)
		{
			if (My_Block[C.x / 50][C.y / 50].att == My_Block[C.x / 50 - 1][C.y / 50].att)
			{
				POINT C1;
				C1.x = C.x - 50;
				C1.y = C.y;
				Cross_Method(My_Block, C1);
			}
		}
	}

	if (C.y / 50 + 1 <= 9)
	{
		if (My_Block[C.x / 50][C.y / 50 + 1].is_visited == false)
		{
			if (My_Block[C.x / 50][C.y / 50].att == My_Block[C.x / 50][C.y / 50 + 1].att)
			{
				POINT C1;
				C1.x = C.x;
				C1.y = C.y + 50;
				Cross_Method(My_Block, C1);
			}
		}
	}

	if (C.y / 50 - 1 >= 0)
	{
		if (My_Block[C.x / 50][C.y / 50 - 1].is_visited == false)
		{
			if (My_Block[C.x / 50][C.y / 50].att == My_Block[C.x / 50][C.y / 50 - 1].att)
			{
				POINT C1;
				C1.x = C.x;
				C1.y = C.y - 50;
				Cross_Method(My_Block, C1);
			}
		}
	}

	My_Block[C.x / 50][C.y / 50].is_visited = false;
}

int My_Rule::Clean_Up(Block My_Block[10][10])
{
	int score=0;
	
	for (int i = 0; i < count1; i++)
	{
		My_Block[Need_Clear1[i].x/50][Need_Clear1[i].y/50].att = 0;
		score++;
	}
	for (int i = 0; i < count2; i++)
	{
		My_Block[Need_Clear2[i].x/50][Need_Clear2[i].y/50].att = 0;
		score++;
	}
	if (My_Block[A.x / 50][A.y / 50].att == My_Block[B.x / 50][B.y / 50].att)
	{
		score /= 2;
	}


	return score;
}


bool My_Rule::Is_More_Than_3(Block MyBlock[10][10], POINT C)
{
	if ((Is_Row_num(MyBlock, C, 3)) || (Is_Line_num(MyBlock, C, 3)))
	{
		return true;
	}
	else
		return false;
}


bool My_Rule::Is_Row_num(Block MyBlock[10][10],POINT C, int num)
{
	int count = 1;
	int i = 1, j = 1;
	while (C.x / 50 + i <= 9 && (MyBlock[C.x / 50][C.y / 50].att != 0) && MyBlock[C.x / 50][C.y / 50].att == MyBlock[C.x / 50 + i][C.y / 50].att)
	{
		i++;
		count++;
	}
	while (C.x / 50 - j >= 0 && (MyBlock[C.x / 50][C.y / 50].att != 0) && (MyBlock[C.x / 50][C.y / 50].att == MyBlock[C.x / 50 - j][C.y / 50].att))
	{
		j++;
		count++;
	}
	if (count >= num)
	{
		if (num >= 4)
		{
			MyBlock[C.x / 50][C.y / 50].is_line = true;
		}

		return true;
	}
	else
		return false;
}

bool My_Rule::Is_Line_num(Block MyBlock[10][10], POINT C, int num)
{
	int count = 1;
	int i = 1, j = 1;
	while (C.y / 50 + i <= 9 && (MyBlock[C.x / 50][C.y / 50 + i].att != 0) && MyBlock[C.x / 50][C.y / 50].att == MyBlock[C.x / 50][C.y / 50 + i].att)
	{
		i++;
		count++;
	}
	while (C.y / 50 - j >= 0 && (MyBlock[C.x / 50][C.y / 50 - j].att != 0) && MyBlock[C.x / 50][C.y / 50].att == MyBlock[C.x / 50][C.y / 50 - j].att)
	{
		j++;
		count++;
	}
	if (count >= num)
	{
		if (num >= 4)
		{
			MyBlock[C.x / 50][C.y / 50].is_line = true;
		}
		return true;
	}

	else
		return false;
}

int My_Rule::Explode(Block block[10][10])
{
	int tempx1 = 0;
	int tempy1 = 0;
	for (int i = 0; i < count1; i++)
	{
		tempx1 += Need_Clear1[i].x;
		tempy1 += Need_Clear1[i].y;
	}
	for (int i = 0; i < count2; i++)
	{
		tempx1 += Need_Clear2[i].x;
		tempy1 += Need_Clear2[i].y;
	}
	tempx1 = tempx1 / (count1 + count2) / 50;
	tempy1 = tempy1 / (count1 + count2) / 50;

	int tempx, tempy;
	int score=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tempx = tempx1 - 1 + i;
			tempy = tempy1 - 1 + j;
			if (9 >= tempx && tempx >= 0 && 9 >= tempy && tempy >= 0)
			{
				block[tempx][tempy].is_explod = true;
				block[tempx][tempy].att = 12;

			}

		}
	}
	score+=9;
	return score;
}



int My_Rule::Is_Line_Clean(Block MyBlock[10][10])
{
	int score = 0;
	int countA1 = 1, countA2 = 1, countB1 = 1, countB2 = 1;
	int i = 1, j = 1;

	while (MyBlock[A.x / 50][A.y / 50].att == MyBlock[A.x / 50][A.y / 50 + i].att)
	{
		i++;
		countA1++;

	}
	while (MyBlock[A.x / 50][A.y / 50].att == MyBlock[A.x / 50][A.y / 50 - j].att)
	{
		j++;
		countA1++;

	}
	i = 1; 
	j = 1;
	while (MyBlock[A.x / 50][A.y / 50].att == MyBlock[A.x / 50 + i][A.y / 50].att)
	{
		i++;
		countA2++;

	}
	while (MyBlock[A.x / 50][A.y / 50].att == MyBlock[A.x / 50 - j][A.y / 50].att)
	{
		j++;
		countA2++;


	}	
	i = 1; 
	j = 1;
	while (MyBlock[B.x / 50][B.y / 50].att == MyBlock[B.x / 50][B.y / 50 + i].att)
	{
		i++;
		countB1++;

	}
	while (MyBlock[B.x / 50][B.y / 50].att == MyBlock[B.x / 50][B.y / 50 - j].att)
	{
		j++;
		countB1++;

	}	
	i = 1;
	j = 1;
	while (MyBlock[B.x / 50][B.y / 50].att == MyBlock[B.x / 50 + i][B.y / 50].att)
	{
		i++;
		countB2++;

	}
	while (MyBlock[B.x / 50][B.y / 50].att == MyBlock[B.x / 50 - j][B.y / 50].att)
	{
		j++;
		countB2++;

	}
	i = 1;
	j = 1;
	if (countA1 >= 4)
	{
		MyBlock[A.x / 50][A.y / 50].is_line = true;
		score += 10;
	}
	if (countA2 >= 4)
	{
		MyBlock[A.x / 50][A.y / 50].is_row = true;
		score += 10;
	}
	if (countB1 >= 4)
	{
		MyBlock[B.x / 50][B.y / 50].is_line = true;
		score += 10;
	}
	if (countB2 >= 4)
	{
		MyBlock[B.x / 50][B.y / 50].is_row = true;
		score += 10;
	}
	return score;
}

void My_Rule::Line_Clean(Block My_Block[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (My_Block[i][j].is_row == true)
			{
				for (int c = 0; c < 10; c++)
				{
					My_Block[c][j].att = 13;
				}
				My_Block[i][j].is_row = false;
			}
			if (My_Block[i][j].is_line == true)
			{
				for (int c = 0; c < 10; c++)
				{
					My_Block[i][c].att = 13;
				}
				My_Block[i][j].is_line = false;
			}
		}
	}
}


void My_Rule::Num_to_Normal(Block My_Block[10][10],int att)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (My_Block[i][j].att==att)
			{
				My_Block[i][j].att = 0;
			}
		}
	}

}


void My_Rule::Normal_Clean(Block block[10][10])
{
	for (int i = 0; i < count1; i++)
	{
		block[Need_Clear1[i].x / 50][Need_Clear1[i].y / 50].att = 11;
	}
	for (int i = 0; i < count2; i++)
	{
		block[Need_Clear2[i].x / 50][Need_Clear2[i].y / 50].att = 11;
	}
}

BOOL My_Rule::Help_Clean(Block block[10][10],POINT* Q,POINT* W)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)//x
		{
			if (j + 1 < 10)
			{
				POINT A, B;
				A.x = j * 50;
				A.y = i * 50;
				B.x = (j + 1) * 50;
				B.y = i * 50;
				My_Rule temp(A , B);
				temp.Exchange(block);
				if (temp.Is_More_Than_3(block, B)||temp.Is_More_Than_3(block, A))
				{
					temp.Exchange(block);
					*Q = A;
					*W = B;
					return true;

				}
				temp.Exchange(block);

			}
			if (i + 1 < 10)
			{
				POINT A, B;
				A.x = j * 50;
				A.y = i * 50;
				B.x = j * 50;
				B.y = (i + 1) * 50;
				My_Rule temp(A, B);
				temp.Exchange(block);
				if (temp.Is_More_Than_3(block, B) || temp.Is_More_Than_3(block, A))
				{
					temp.Exchange(block);
					*Q = A;
					*W = B;
					return true;
				}
				temp.Exchange(block);
			}
			else
			{
				return false;
			}

		}
	}
}