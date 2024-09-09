/*
E:别叫，这个大整数已经很简化了!
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
输入
多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
输出
对每组数据，输出6行，内容对应程序中6个输出语句
样例输入
99999999999999999999999999888888888888888812345678901234567789 12
6 6
样例输出
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
来源
Guo Wei
查看 提交 统计 提问
*/
#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
private:
    char num[MAX];
public:
    CHugeInt(const char* s){
        strcpy(num,s);
    }
    CHugeInt(int n){
        sprintf(num,"%d",n);
    }
    CHugeInt operator+(const CHugeInt& a){
        CHugeInt temp(0);
        int carry = 0;
        for(int i = strlen(num) - 1, j = strlen(a.num) - 1; i >= 0 || j >= 0; i--, j--){
            int x = i >= 0 ? num[i] - '0' : 0;
            int y = j >= 0 ? a.num[j] - '0' : 0;
            int z = x + y + carry;
            temp.num[strlen(temp.num)] = z % 10 + '0';
            carry = z / 10;
        }
        if(carry) temp.num[strlen(temp.num)] = carry + '0';
        for(int i = 0; i < strlen(temp.num) / 2; i++){
            swap(temp.num[i],temp.num[strlen(temp.num) - i - 1]);
        }
        return temp;
    }
    CHugeInt operator+(int n){
        CHugeInt temp(n);
        return *this + temp;
    }
    CHugeInt operator+=(int n){
        *this = *this + n;
        return *this;
    }
    CHugeInt operator++(int){
        CHugeInt temp(*this);
        *this += 1;
        return temp;
    }
    CHugeInt operator++(){
        *this += 1;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const CHugeInt& a){
        os << a.num;
        return os;
    }
    friend int operator+(int n,CHugeInt& a){
        return n + atoi(a.num);
    }
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
