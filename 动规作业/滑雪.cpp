/*
A:滑雪
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。
样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
25
来源
Don't know
查看 提交 统计 提问
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m;
int dp[101][101];
int map[101][101];
int direction[][2]= {0,1,0,-1,1,0,-1,0};
int DP(int x,int y)
{
    int cnt=0;
    if(dp[x][y])
        return dp[x][y];
    for(int i=0; i<4; ++i)
    {
        int xx=x+direction[i][0],yy=y+direction[i][1];
        if(xx<0||xx>=n||yy<0||yy>=m)
            continue;
        if(map[xx][yy]<map[x][y])
            cnt=max(cnt,DP(xx,yy));
    }
    dp[x][y]=cnt+1;
    return dp[x][y];
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int i,j;
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j)
            {
                scanf("%d",&map[i][j]);
                dp[i][j]=0;
            }
        int ans=0;
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j)
            ans=max(ans,DP(i,j));
        printf("%d\n",ans);
    }
    return 0;
}
