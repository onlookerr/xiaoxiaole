#pragma once
struct Block
{
	int x;//在网格中的横坐标
	int y;//在网格中的纵坐标
	int att;//它的属性，贴什么图片
	bool is_selected;//它是否被鼠标选中，用来显示选中框
	bool is_visited;//它是否被访问过，用来十字算法
	bool is_explod;//它是否能爆炸
	bool is_line;//它是否能列消
	bool is_row;//它是否能行消
};
