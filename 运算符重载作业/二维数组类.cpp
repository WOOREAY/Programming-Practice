/*
D:二维数组类
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
写一个二维数组类 Array2,使得下面程序的输出结果是：

0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,

程序：

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
输入
无
输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
样例输入
None
样例输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
查看 提交 统计 提问
*/
#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
    int **p;
    public:
    Array2(int n, int m) {
        p = new int*[n];
        for(int i = 0; i < n; i++) {
            p[i] = new int[m];
        }
    }
    Array2() {
        p = NULL;
    }
    ~Array2() {
        if(p) {
            delete [] p;
        }
    }
    int* operator[](int n) {
        return p[n];
    }
    int operator()(int n, int m) {
        return p[n][m];
    }
    Array2& operator=(Array2 & a) {
        if(p) {
            delete [] p;
        }
        p = new int*[3];
        for(int i = 0; i < 3; i++) {
            p[i] = new int[4];
        }
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 4; j++) {
                p[i][j] = a[i][j];
            }
        }
        return *this;
    }
    
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
