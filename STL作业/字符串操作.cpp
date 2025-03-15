/*
D:字符串操作
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，现有如下若干操作：

copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。
find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
reset S N：将第N个字符串变为S。
print N：打印输出第N个字符串。
printall：打印输出所有字符串。
over：结束操作。
其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

输入
第一行为一个整数n（n在1-20之间）


接下来n行为n个字符串，字符串不包含空格及操作命令等。


接下来若干行为一系列操作，直到over结束。

输出
根据操作提示输出对应字符串。

样例输入
3
329strjvc
Opadfk48
Ifjoqwoqejr
insert copy 1 find 2 1 2 2 2
print 2
reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
print 3
insert a 3 2
printall
over
样例输出
Op29adfk48
358
329strjvc
Op29adfk48
35a8
提示
推荐使用string类中的相关操作函数。

查看 提交 统计 提问
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

vector<string> strGiven;
queue<string> strCommand;
char *strItoa = new char[101];

void strStorage(const char *ch);
bool strProcess();
string commandOp();
string nyCopy(int n, int x, int l);
string nyAdd(string s1, string s2);
int nyFind(int n, string s);
int nyRFind(int n, string s);
void nyInsert(int n, int x, string s);
void nyReset(int n, string s);
void nyPrint(int n);
void nyPrintAll();

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        strGiven.push_back(str);
    }
    cin.get();

    char *ch = new char[501];
    while (1)
    {
        cin.getline(ch, 500, '\n');
        strStorage(ch);
        int t = strProcess();
        if (t == false)
        {
            break;
        }
    }
    delete ch;
    delete strItoa;
    return 0;
}
void strStorage(const char *ch)
{
    string str;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] != ' ')
        {
            str.push_back(ch[i]);
        }
        else
        {
            strCommand.push(str);
            str.clear();
        }
    }
    strCommand.push(str);
}
bool strProcess()
{
    string str = strCommand.front();
    strCommand.pop();
    if (str == "insert")
    {
        string s = commandOp();
        int n = atoi(commandOp().c_str());
        int x = atoi(commandOp().c_str());
        nyInsert(n, x, s);
    }
    else if (str == "reset")
    {
        string s = commandOp();
        int n = atoi(commandOp().c_str());
        nyReset(n, s);
    }
    else if (str == "print")
    {
        int n = atoi(commandOp().c_str());
        nyPrint(n);
    }
    else if (str == "printall")
    {
        nyPrintAll();
    }
    else if (str == "over")
    {
        return false;
    }
    return true;
}
string commandOp()
{
    string str = strCommand.front();
    strCommand.pop();
    if (str == "copy")
    {
        int n = atoi(commandOp().c_str());
        int x = atoi(commandOp().c_str());
        int l = atoi(commandOp().c_str());
        return nyCopy(n, x, l);
    }
    else if (str == "add")
    {
        string s1 = commandOp();
        string s2 = commandOp();
        return nyAdd(s1, s2);
    }
    else if (str == "find")
    {
        string s = commandOp();
        int n = atoi(commandOp().c_str());
        sprintf(strItoa, "%d", nyFind(n, s));
        return strItoa;
    }
    else if (str == "rfind")
    {
        string s = commandOp();
        int n = atoi(commandOp().c_str());
        sprintf(strItoa, "%d", nyRFind(n, s));
        return strItoa;
    }
    else
    {
        return str;
    }
}
string nyCopy(int n, int x, int l)
{
    string str = strGiven.at(n - 1);
    return str.substr(x, l);
}
string nyAdd(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1.at(i) < '0' || s1.at(i) > '9')
        {
            return s1 + s2;
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2.at(i) < '0' || s2.at(i) > '9')
        {
            return s1 + s2;
        }
    }
    long a = atoi(s1.c_str());
    long b = atoi(s2.c_str());
    if (a >= 0 && a <= 99999 && b >= 0 && b <= 99999)
    {
        long c = a + b;
        sprintf(strItoa, "%d", c);
        return strItoa;
    }
    else
    {
        return s1 + s2;
    }
}
int nyFind(int n, string s)
{
    int pos = strGiven.at(n - 1).find(s);
    if (pos == string::npos)
    {
        return s.size();
    }
    else
    {
        return pos;
    }
}
int nyRFind(int n, string s)
{
    int pos = strGiven.at(n - 1).rfind(s);
    if (pos == string::npos)
    {
        return s.size();
    }
    else
    {
        return pos;
    }
}
void nyInsert(int n, int x, string s)
{
    strGiven.at(n - 1).insert(x, s);
}
void nyReset(int n, string s)
{
    strGiven.at(n - 1).swap(s);
}
void nyPrint(int n)
{
    cout << strGiven.at(n - 1) << endl;
}
void nyPrintAll()
{
    for (unsigned int i = 0; i < strGiven.size(); i++)
    {
        cout << strGiven.at(i) << endl;
    }
}
