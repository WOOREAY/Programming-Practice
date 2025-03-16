/*
A:拨钟问题
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
有9个时钟，排成一个3*3的矩阵。

|-------|    |-------|    |-------|
|       |    |       |    |   |   |
|---O   |    |---O   |    |   O   |
|       |    |       |    |       |
|-------|    |-------|    |-------|
    A            B            C    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            I    
(图 1)
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。



移动    影响的时钟
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
输入
9个整数，表示各时钟指针的起始位置，相邻两个整数之间用单个空格隔开。其中，0=12点、1=3点、2=6点、3=9点。
输出
输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号从小到大输出结果。相邻两个整数之间用单个空格隔开。
样例输入
3 3 0 
2 2 2 
2 1 2 
样例输出
4 5 8 9 
来源
1166
查看 提交 统计 提问
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 记录每种操作影响的时钟
int moves[9][9] = {
    {1,1,0,1,1,0,0,0,0}, // 操作1: ABDE
    {1,1,1,0,0,0,0,0,0}, // 操作2: ABC
    {0,1,1,0,1,1,0,0,0}, // 操作3: BCEF
    {1,0,0,1,0,0,1,0,0}, // 操作4: ADG
    {0,1,0,1,1,1,0,1,0}, // 操作5: BDEFH
    {0,0,1,0,0,1,0,0,1}, // 操作6: CFI
    {0,0,0,1,1,0,1,1,0}, // 操作7: DEGH
    {0,0,0,0,0,0,1,1,1}, // 操作8: GHI
    {0,0,0,0,1,1,0,1,1}  // 操作9: EFHI
};

int clocks[9]; // 当前时钟状态
vector<int> solution; // 当前解决方案
vector<int> bestSolution; // 最优解决方案

// 检查所有时钟是否指向12点
bool allZero() {
    for (int i = 0; i < 9; i++) {
        if (clocks[i] != 0) return false;
    }
    return true;
}

// 执行操作
void doMove(int moveIndex) {
    for (int i = 0; i < 9; i++) {
        if (moves[moveIndex][i] == 1) {
            clocks[i] = (clocks[i] + 1) % 4;
        }
    }
}

// 尝试所有可能的操作
void solve(int moveIndex) {
    // 如果已尝试所有操作
    if (moveIndex == 9) {
        if (allZero() && (bestSolution.empty() || solution.size() < bestSolution.size())) {
            bestSolution = solution;
        }
        return;
    }
    
    // 尝试当前操作0-3次
    for (int times = 0; times < 4; times++) {
        // 先尝试递归，相当于执行0次当前操作
        if (times == 0) {
            solve(moveIndex + 1);
        } else {
            // 执行当前操作times次
            for (int j = 0; j < times; j++) {
                solution.push_back(moveIndex + 1);
                doMove(moveIndex);
            }
            
            // 递归尝试下一个操作
            solve(moveIndex + 1);
            
            // 撤销操作
            for (int j = 0; j < times; j++) {
                solution.pop_back();
                // 执行3次相当于逆时针旋转90度
                doMove(moveIndex);
                doMove(moveIndex);
                doMove(moveIndex);
            }
        }
    }
}

int main() {
    // 读入初始状态
    for (int i = 0; i < 9; i++) {
        cin >> clocks[i];
    }
    
    // 求解
    solve(0);
    
    // 按照操作序号从小到大排序输出
    sort(bestSolution.begin(), bestSolution.end());
    
    // 输出结果
    for (size_t i = 0; i < bestSolution.size(); i++) {
        cout << bestSolution[i] << " ";
    }
    cout << endl;
    
    return 0;
}
