/*
C:The Sierpinski Fractal
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Consider a regular triangular area, divide it into four equal triangles of half height and remove the one in the middle. Apply the same operation recursively to each of the three remaining triangles. If we repeated this procedure infinite times, we'd obtain something with an area of zero. The fractal that evolves this way is called the Sierpinski Triangle. Although its topological dimension is 2, its Hausdorff-Besicovitch dimension is log(3)/log(2)~1.58, a fractional value (that's why it is called a fractal). By the way, the Hausdorff-Besicovitch dimension of the Norwegian coast is approximately 1.52, its topological dimension being 1.

For this problem, you are to outline the Sierpinski Triangle up to a certain recursion depth, using just ASCII characters. Since the drawing resolution is thus fixed, you'll need to grow the picture appropriately. Draw the smallest triangle (that is not divided any further) with two slashes, to backslashes and two underscores like this:

 /\
/__\
To see how to draw larger triangles, take a look at the sample output.

输入
The input contains several testcases. Each is specified by an integer n. Input is terminated by n=0. Otherwise 1<=n<=10 indicates the recursion depth.
输出
For each test case draw an outline of the Sierpinski Triangle with a side's total length of 2n characters. Align your output to the left, that is, print the bottom leftmost slash into the first column. The output must not contain any trailing blanks. Print an empty line after each test case.
样例输入
3
2
1
0
样例输出
       /\
      /__\
     /\  /\
    /__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\

   /\
  /__\
 /\  /\
/__\/__\

 /\
/__\
提示

The Sierpinski-Triangle up to recursion depth 7
来源
Ulm Local 2002
查看 提交 统计 提问
*/
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define F(i,j,k) for (int i=j;i<=k;++i)
#define D(i,j,k) for (int i=j;i>=k;--i)
#define ll long long
#define mp make_pair
#define maxn 2050
 
char s[maxn][maxn];
 
int l[11]={0,4,8,16,32,64,128,256,512,1024,2048},n,h[11]={0,2,4,8,16,32,64,128,256,512,1024};
int upper[maxn],high=0;
 
inline void solve(int x,int y,int siz)
{
	if (!siz) return;
	if (siz==1)
	{
		s[x][y]=' ';
		s[x][y+1]='/';
		s[x][y+2]='\\';
		s[x+1][y]='/';
		s[x+1][y+3]='\\';
		s[x+1][y+1]='_';
		s[x+1][y+2]='_';
		upper[x]=max(upper[x],y+2);
		upper[x+1]=max(upper[x],y+3);
		high=max(high,x+1);
		return ;
	}
	F(i,x,x+h[siz-1]-1) F(j,y,l[siz-1]/2+y-1) s[i][j]=' ';
	solve(x,y+l[siz-1]/2,siz-1);
	solve(x+h[siz-1],y,siz-1);
	solve(x+h[siz-1],y+l[siz-1],siz-1);
}
 
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		F(i,0,h[n]) F(j,0,l[n]) s[i][j]=' ';
		high=0;memset(upper,0,sizeof upper);
		solve(0,0,n);
		F(i,0,high)
		{
			F(j,0,upper[i]) putchar(s[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
}
