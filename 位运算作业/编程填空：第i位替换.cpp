/*
A:编程填空：第i位替换
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 1024kB
描述
写出函数中缺失的部分，使得函数返回值为一个整数,该整数的第i位和m的第i位相同，其他位和n相同。

请使用【一行代码】补全bitManipulation1函数使得程序能达到上述的功能

#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// 在此处补充你的代码
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}
输入
第一行是整数 t，表示测试组数。
每组测试数据包含一行，是三个整数 n, m 和 i (0<=i<=31)
输出
对每组输入数据，每行输出整型变量n变化后的结果
样例输入
1
1 2 1
样例输出
3
提示
二进制的最右边是第0位
*/
#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// 在此处补充你的代码
    return (n&(^(1<<i)))|(m&(1<<i));
}

int main() {
	int n, m, i, t;
	cin >> t;
	while (t--) { 
		cin >> n >> m >> i;
		cout << bitManipulation1(n, m, i) << endl;
	}
	return 0;
}
