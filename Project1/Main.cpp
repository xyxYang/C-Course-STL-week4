/********************************************************
��Ŀ��
��дһ��Sink��������ͬʱ�������inserter�������ʹ�ӡ��ֵ�Ĺ���
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