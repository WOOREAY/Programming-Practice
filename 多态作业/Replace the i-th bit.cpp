/*
B:Replace the i-th bit
查看提交统计提问
总时间限制: 1000ms 内存限制: 1024kB
描述
Please change the i-th bit of integer n as the same with the i-th bit of integer m, with other bits unchanged.

You are only allowed to use just one statement to complete function bitManipulation to achieve the above goal.

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
The first line contains an integer t, which denotes the number of test cases.
Then it is followed by t lines, each containing three integers: n, m, and i (0<=i<=31).
输出
For each test case, it prints a line containing the value of n after replacement.
样例输入
1
1 2 1
样例输出
3
提示
Order positions are counted from the rightmost bit, which is order position 0.
查看 提交 统计 提问
*/
#include <iostream>
using namespace std;

int bitManipulation1(int n, int m, int i) {
// 在此处补充你的代码
    return ((1<<i) & m) | (n & ~ (1<<i));
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