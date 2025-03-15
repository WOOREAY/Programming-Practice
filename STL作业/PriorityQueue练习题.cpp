/*
G:priority queue练习题
查看提交统计提问
总时间限制: 2500ms 内存限制: 131072kB
描述
我们定义一个正整数a比正整数b优先的含义是：
*a的质因数数目（不包括自身）比b的质因数数目多；
*当两者质因数数目相等时，数值较大者优先级高。


现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，每次添加之后，要求输出优先级最高与最低的元素，并把该两元素从容器中删除。

输入
第一行: num (添加元素次数，num <= 30)

下面10*num行，每行一个正整数n（n < 10000000).

输出
每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。

样例输入
1
10 7 66 4 5 30 91 100 8 9
样例输出
66 5
查看 提交 统计 提问
*/
#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <bitset>
using namespace std;
bitset<3200> tab;
 
int op(int k){
    int num = 0;
    for(int j = 2; j < 3200 && j < k; j++){
        if(tab[j] == 0 && k % j == 0){
            while(k % j == 0)
                k /= j ;
            num ++ ;
            if(k == 1) break ;
        }
    }
    if(k == 1)
        return num;
    else if(num == 0)
        return 0;
    else
        return num + 1;
}

class MyLess{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        int tmp1 = a.first;
        int tmp2 = b.first;
        if(tmp1 == tmp2)
            return a.second > b.second;
        else
            return tmp1 > tmp2;
    }
};

class MyGreater{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        int tmp1 = a.first;
        int tmp2 = b.first;
        if(tmp1 == tmp2)
            return a.second < b.second;
        else
            return tmp1 < tmp2;
    }
};

int main()
{
    tab[0] = tab[1] = 1;
    for(int i = 2; i < 3200; i++)
            tab[i] = 0;
    for(int i = 2; i < 3200; i++)
        if(!tab[i])
            for(int j = i+i; j < 3200; j += i)
                tab[j] = 1;
    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int> >, MyGreater> q;
    priority_queue<pair<int,int>, vector<pair<int,int> >, MyLess> p;
    while(n--){
        for(int i = 0; i < 10; ++i){
            int tmp;
            cin >> tmp;
            q.push(make_pair(op(tmp), tmp));
            p.push(make_pair(op(tmp), tmp));
        }
        cout << q.top().second <<' '<< p.top().second << endl;
        q.pop();
        p.pop();
    }
}
