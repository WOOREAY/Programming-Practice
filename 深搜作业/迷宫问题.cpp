/*
A:迷宫问题
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
定义一个二维数组：

int maze[5][5] = {

0, 1, 0, 0, 0,

0, 1, 0, 1, 0,

0, 0, 0, 0, 0,

0, 1, 1, 1, 0,

0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。



输入
一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
输出
左上角到右下角的最短路径，格式如样例所示。
样例输入
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
样例输出
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
查看 提交 统计 提问
*/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
#define MAX 100000
#define INF 0x3f3f3f3f
using namespace std;
char f[5][5];
int dis[10][10];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
struct p{
    int x,y;
}cur, nxt;
vector<p> arr;
void dfs(int x, int y)
{
    arr.push_back({x,y});
    for(int i = 0; i < 4; i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if(a >= 0 && a < 5 && b >= 0 && b < 5 && dis[a][b] + 1 == dis[x][y]){
            dfs(a, b);
        }
    }
}
int main()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> f[i][j];
            getchar();
        }
    }
    cur.x = 0;
    cur.y = 0;
    queue<p> q;
    memset(dis, INF, sizeof dis);
    dis[0][0] = 0;
    q.push(cur);
    while(q.size()){
        cur = q.front();
        q.pop();
        if(cur.x == 4 && cur.y == 4)break;
        for(int i = 0; i < 4; i++){
            nxt.x = cur.x + dx[i];
            nxt.y = cur.y + dy[i];
            if(nxt.x >= 0 && nxt.x < 5 && nxt.y >= 0 && nxt.y < 5 && dis[nxt.x][nxt.y] == INF && f[nxt.x][nxt.y] == '0'){
                dis[nxt.x][nxt.y] = dis[cur.x][cur.y] + 1;
                q.push(nxt);
            }
        }
    }
    dfs(4, 4);
    for(int i = arr.size() - 1; i >= 0 ; i--){
        printf("(%d, %d)\n",arr[i].x, arr[i].y);
    }
    return 0;
}
