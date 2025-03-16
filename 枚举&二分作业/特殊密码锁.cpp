/*
B:特殊密码锁
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹/凸两种状态，用手按按钮会改变其状态。

然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。

当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。

输入
两行，给出两个由0、1组成的等长字符串，表示当前/目标密码锁状态，其中0代表凹，1代表凸。
输出
至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
样例输入
011
000
样例输出
1
查看 提交 统计 提问
*/
#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int oriLock;
int lock;
int destLock;

inline int GetBit(int n,int i)
{
	return (n >> i) & 1;
} 

inline void SetBit(int & n,int i,int v)
{
	if(v) 
		n |= (1 << i);
	else
		n &= ~(1 << i);
}

inline void FlipBit(int & n,int i)
{
	n ^= (1 << i);
}

int main()
{
	char line[40];
	destLock = lock = oriLock = 0;
	cin >> line;
	int N = strlen(line);
	for(int i = 0; i < N; ++i)
		SetBit(oriLock,i, line[i] - '0');
	cin >> line;
	for(int i = 0; line[i]; ++i)
		SetBit(destLock,i, line[i] - '0');
	int minTimes = 1 << 30;
	for(int p = 0; p < 2; ++p) { 
		lock = oriLock;
		int times = 0;
		int curButton = p;
		for(int i = 0; i < N; ++i) {
			if(curButton) {
				++ times;
				if( i > 0)
					FlipBit(lock,i-1);
				FlipBit(lock,i);
				if( i < N-1)
					FlipBit(lock,i+1);
			}
			if( GetBit(lock,i) != GetBit(destLock,i))  
				curButton = 1;
			else 
				curButton = 0;
		}
		if( lock == destLock)
			minTimes = min(minTimes ,times);
	}
	if( minTimes == 1 << 30)
		cout <<"impossible" << endl;
	else
		cout << minTimes << endl;
	return 0;
}
