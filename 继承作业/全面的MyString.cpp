/*
A:全面的MyString
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空，输出指定结果

#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
输入
无
输出
1. abcd-efgh-abcd-
2. abcd-
3.
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
样例输入
无
样例输出
1. abcd-efgh-abcd-
2. abcd-
3. 
4. abcd-efgh-
5. efgh-
6. c
7. abcd-
8. ijAl-
9. ijAl-mnop
10. qrst-abcd-
11. abcd-qrst-abcd- uvw xyz
about
big
me
take
abcd
qrst-abcd-
来源
Guo Wei
查看 提交 统计 提问
*/
#include <cstdlib>
#include <iostream>
using namespace std;
// int strlen(const char * s) 
// {	int i = 0;
// 	for(; s[i]; ++i);
// 	return i;
// }
// void strcpy(char * d,const char * s)
// {
// 	int i = 0;
// 	for( i = 0; s[i]; ++i)
// 		d[i] = s[i];
// 	d[i] = 0;
		
// }
// int strcmp(const char * s1,const char * s2)
// {
// 	for(int i = 0; s1[i] && s2[i] ; ++i) {
// 		if( s1[i] < s2[i] )
// 			return -1;
// 		else if( s1[i] > s2[i])
// 			return 1;
// 	}
// 	return 0;
// }
// void strcat(char * d,const char * s)
// {
// 	int len = strlen(d);
// 	strcpy(d+len,s);
// }
class MyString
{
public:
        char* s;

    MyString() {
        s = NULL;
    }

	~MyString() {
	    if (s) {
            delete s;
		}
	}
    MyString(const char* str) {
        s = new char[strlen(str)];
        strcpy(s, str);
    }

    MyString(const MyString & obj) {
        s = new char[strlen(obj.s)];
        strcpy(s, obj.s);
    }
    
    void operator = (const MyString & obj) {
        if (s) {
            delete s;
        }
        s = new char[strlen(obj.s)];
        strcpy(s, obj.s);
    }

    MyString operator + (const MyString & obj) {
        int len = strlen(s) + strlen(obj.s);
        char* tmp = new char[len];
        strcpy(tmp, s);
        strcpy(tmp + strlen(s), obj.s);
        return MyString(tmp);
    }

    MyString operator += (const char* str) {
        int len = strlen(s) + strlen(str);
        char* tmp = new char[len];
        strcpy(tmp, s);
        strcpy(tmp + strlen(s), str);

		if (s) {
			delete s;
		}
        s = tmp;
        return *this;
    }

    bool operator < (const MyString & obj) {
		int len = min(strlen(s), strlen(obj.s));
		for (int i = 0; i < len; i++) {
            if (s[i] < obj.s[i])
			    return true;
			else
			    return false;
		}		    
        return false;
    }

    bool operator > (const MyString & obj) {
        return s > obj.s;
    }

    bool operator == (const MyString & obj) {
        return (s == obj.s);
    }

    char & operator [] (int i) {
        return *(s + i);
    }

    string operator () (int start, int len) {
		string str;
	    for(int i = start; i < start + len; ++i) {
		    str.push_back(s[i]);
	    }
        return str;
    }
    // overwrite str + obj
    friend MyString operator + (const char* str, MyString & obj) {
		int len = strlen(obj.s) + strlen(str);
        char* tmp = new char[len];

        strcpy(tmp, str);
        strcpy(tmp + strlen(str), obj.s);

        return MyString(tmp);
	}

    friend ostream & operator << (ostream & os, const MyString & obj)
    {
        if (obj.s)
            os << obj.s;
        return os;
    }
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}