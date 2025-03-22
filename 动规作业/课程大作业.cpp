/*
D:课程大作业
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
小明是北京大学信息科学技术学院三年级本科生。他喜欢参加各式各样的校园社团。这个学期就要结束了，每个课程大作业的截止时间也快到了，可是小明还没有开始做。每一门课程都有一个课程大作业，每个课程大作业都有截止时间。如果提交时间超过截止时间X天，那么他将会被扣掉X分。对于每个大作业，小明要花费一天或者若干天来完成。他不能同时做多个大作业，只有他完成了当前的项目，才可以开始一个新的项目。小明希望你可以帮助他规划出一个最好的办法(完成大作业的顺序)来减少扣分。

输入
输入包含若干测试样例。
输入的第一行是一个正整数T，代表测试样例数目。
对于每组测试样例，第一行为正整数N（1 <= N <= 15）代表课程数目。
接下来N行，每行包含一个字符串S（不多于50个字符）代表课程名称和两个整数D（代表大作业截止时间）和C（完成该大作业需要的时间）。
注意所有的课程在输入中出现的顺序按照字典序排列。
输出
对于每组测试样例，请输出最小的扣分以及相应的课程完成的顺序。
如果最优方案有多个，请输出字典序靠前的方案。
样例输入
2 
3 
Computer 3 3 
English 20 1 
Math 3 2 
3
Computer 3 3 
English 6 3 
Math 6 3
样例输出
2 
Computer 
Math 
English 
3 
Computer 
English 
Math
提示
第二个测试样例, 课程完成顺序Computer->English->Math 和 Computer->Math->English 都会造成3分罚分, 但是我们选择前者,因为在字典序中靠前.
查看 提交 统计 提问
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 15;
char name[N][50 + 1];
int d[N], c[N], sum[1 << (N + 1)], dp[1 << (N + 1)];
string ans[1 << (N + 1)];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0, i2 = 1; i < n; i2 <<= 1, i++)
            scanf("%s%d%d", name[i], &d[i], &c[i]);

        int num = 1 << n;
        memset(sum, 0, sizeof sum);
        for (int i = 1; i < num; i++)
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) sum[i] += c[j];

        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i < num; i++)
            for (int j = 0; j < n; j++) {
                int x = 1 << j;
                if( (i>>j) & 1 && dp[i] >= dp[i ^ x] + max(sum[i]- d[j], 0)) {
                    if(dp[i] > dp[i ^ x] + max(sum[i] - d[j], 0)) {
                        dp[i] = dp[i ^ x] + max(sum[i] - d[j],0);
                        ans[i] = ans[i ^ x] + (char)(j + '0');
                    } else if(ans[i] > ans[i ^ x] + (char)(j + '0'))
                        ans[i] = ans[i ^ x] + (char)(j + '0');
                }
            }

        printf("%d\n", dp[num - 1]);
        string c = ans[num - 1];
        for (int i = 0; c[i]; i++)
            printf("%s\n", name[c[i] - '0']);
    }

    return 0;
}
