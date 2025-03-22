/*
B:硬币
查看提交统计提问
总时间限制: 1000ms 内存限制: 262144kB
描述
宇航员Bob有一天来到火星上，他有收集硬币的习惯。于是他将火星上所有面值的硬币都收集起来了，一共有n种，每种只有一个：面值分别为a1,a2… an。 Bob在机场看到了一个特别喜欢的礼物，想买来送给朋友Alice，这个礼物的价格是X元。Bob很想知道为了买这个礼物他的哪些硬币是必须被使用的，即Bob必须放弃收集好的哪些硬币种类。飞机场不提供找零，只接受恰好X元。

输入
第一行包含两个正整数n和x。（1 <= n <= 200, 1 <= x <= 10000)
第二行从小到大为n个正整数a1, a2, a3 … an （1 <= ai <= 10000)
输出
第一行是一个整数，即有多少种硬币是必须被使用的。
第二行是这些必须使用的硬币的面值（从小到大排列）。
样例输入
5 18
1 2 3 5 10
样例输出
2
5 10
提示
输入数据将保证给定面值的硬币中至少有一种组合能恰好能够支付X元。
如果不存在必须被使用的硬币，则第一行输出0，第二行输出空行。
查看 提交 统计 提问
*/
#include<iostream>
#include<cstring>

using namespace std;

const int N = 200 + 1;
int a[N], ans[N], dp[10000];

int cal(int x, int y)
{
    if (x < 0) return 0;
    else return dp[x] - cal(x - y, y);
}

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = x; j >= a[i]; j--)
            dp[j] += dp[j - a[i]];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (cal(x, a[i]) == 0) ans[cnt++] = a[i];

    printf("%d\n", cnt);
    if (cnt == 0) printf(" \n");
    else {
        printf("%d", ans[0]);
        for (int i = 1; i < cnt; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }

    return 0;
}