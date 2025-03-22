/*
B:最佳加法表达式
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。例如，在1234中摆放1个加号，最好的摆法就是12+34,和为36

输入
有不超过15组数据
每组数据两行。第一行是整数m，表示有m个加号要放( 0<=m<=50)
第二行是若干个数字。数字总数n不超过50,且 m <= n-1
输出
对每组数据，输出最小加法表达式的值
样例输入
2
123456
1
123456
4
12345
样例输出
102
579
15
提示
要用到高精度计算，即用数组来存放long long 都装不下的大整数，并用模拟列竖式的办法进行大整数的加法。
来源
Guo Wei
查看 提交 统计 提问
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string Add(string &a, string &b)
{
    string sum;
    int lena = a.length();
    int lenb = b.length();
    int i = 0;
    int j = 0;
    int carry = 0;
    int number = 0;
    while (i < lena || j < lenb)
    {
        number = carry;
        if (i < lena)
            number += (a[i++] - '0');
        if (j < lenb)
            number += (b[j++] - '0');
        sum += (number % 10 + '0');
        carry = number / 10;
    }
    if (carry == 1)
    {
        sum = sum + '1';
    }

    return sum;
}

// 1大于 0等于 -1小于
int comp(string &a, string &b)
{
    if (a.length() > b.length())
        return 1;
    if (a.length() < b.length())
        return -1;
    for (int i = a.length() - 1; i >= 0; --i)
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
        {
            return -1;
        }
    }
    return 0;
}

string maxSum(vector<vector<string>> &record, string &s, int start, int m)
{
    if (m == 0)
        return s.substr(start);

    if (record[start][m] != "")
    {
        return record[start][m];
    }

    string &rec = record[start][m];
    string minNumber = s;
    for (int i = start; i < s.length() - m; ++i)
    {
        string sub = s.substr(start, i - start + 1);
        string remain = maxSum(record, s, i + 1, m - 1);
        string r = Add(sub, remain);
        if (comp(minNumber, r) == 1)
        {
            minNumber = r;
        }
    }
    return rec = minNumber;
}

int main()
{
    int m;
    string s;
    while (cin >> m)
    {
        cin >> s;
        if (m == 0)
        {
            cout<<s<<endl;
            continue;
        }
        reverse(s.begin(), s.end());
        vector<vector<string>> record(s.length(), vector<string>(m + 1, ""));
        string sum = maxSum(record, s, 0, m);
        reverse(sum.begin(), sum.end());
        cout << sum << endl;
    }
    return 0;
}