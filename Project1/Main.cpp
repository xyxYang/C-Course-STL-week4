/********************************************************
题目：
编写一个Sink迭代器，同时可以完成inserter迭代器和打印数值的功能
*********************************************************/
#include "Sink.h"
#include <vector>
#include <list>
#include <iostream>
#include <allocators>
using namespace std;

int main()
{
	vector<int, allocator<int>> v{ 1,2,3,4,5,6,7,8,9 };
	list<int> l;
	char ch[] = ", ";
	cout << endl;
	copy(l.begin(), l.end(), sinker(v, cout, v.begin(), ch));
	return 0;
}