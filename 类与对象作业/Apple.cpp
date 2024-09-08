/*
A:Apple
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，使其输出4 5 1

#include <iostream>
using namespace std;
class Apple {
// 在此处补充你的代码
static void PrintTotal() {
		cout << nTotalNumber << endl; 
	}

};
int Apple::nTotalNumber = 0;
Apple Fun(const Apple & a) {
	a.PrintTotal();
	return a;
}
int main()
{
	Apple * p = new Apple[4];
	Fun(p[2]);
	Apple p1,p2;
	Apple::PrintTotal ();
	delete [] p;
	p1.PrintTotal ();
	return 0;
}
输入
无
输出
4
5
1
样例输入
None
样例输出
4
5
1
来源
Guo Wei
查看 提交 统计 提问
*/
#include <iostream>
using namespace std;
class Apple {
// 在此处补充你的代码
public:
    static int nTotalNumber;
    Apple() {
        nTotalNumber++;
    }
    ~Apple() {
        nTotalNumber--;
    }
    static void PrintTotal() {
            cout << nTotalNumber << endl; 
        }

    };
    int Apple::nTotalNumber = 0;
    Apple Fun(const Apple & a) {
        a.PrintTotal();
        return a;
}
int main()
{
	Apple * p = new Apple[4];
	Fun(p[2]);
	Apple p1,p2;
	Apple::PrintTotal ();
	delete [] p;
	p1.PrintTotal ();
	return 0;
}