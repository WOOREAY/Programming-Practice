/*
A:Boolean Expressions
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
The objective of the program you are going to produce is to evaluate boolean expressions as the one shown next:
Expression: ( V | V ) & F & ( F | V )

where V is for True, and F is for False. The expressions may include the following operators: ! for not , & for and, | for or , the use of parenthesis for operations grouping is also allowed.

To perform the evaluation of an expression, it will be considered the priority of the operators, the not having the highest, and the or the lowest. The program must yield V or F , as the result for each expression in the input file.
输入
The expressions are of a variable length, although will never exceed 100 symbols. Symbols may be separated by any number of spaces or no spaces at all, therefore, the total length of an expression, as a number of characters, is unknown.

The number of expressions in the input file is variable and will never be greater than 20. Each expression is presented in a new line, as shown below.
输出
For each test expression, print "Expression " followed by its sequence number, ": ", and the resulting value of the corresponding test expression. Separate the output for consecutive test expressions with a new line.

Use the same format as that shown in the sample output shown below.
样例输入
( V | V ) & F & ( F| V)
!V | V & V & !F & (F | V ) & (!F | F | !V & V)
(F&F|V|!V&!F&!(F|F&V))
样例输出
Expression 1: F
Expression 2: V
Expression 3: V
来源
México and Central America 2004
查看 提交 统计 提问
*/
#include <iostream>
using namespace std;
 
bool factor_value();
bool term_value();
bool expression_value();
void DelSpace();
 
int main()
{
    // freopen("test.rtf", "r", stdin);
    int count = 1;
    do
    {
        if (expression_value())
            cout << "Expression " << count << ": V" << endl;
        else
            cout << "Expression " << count << ": F" << endl;
        count++;
        cin.get();
    } while (cin.peek() != EOF);
    return 0;
}
 
bool expression_value()
{
    bool result = term_value();
    while (1)
    {
        DelSpace();
        char op = cin.peek();
        if (op == '|')
        {
            cin.get();
            result = (term_value() || result);
        }
        else
            break;
    }
    return result;
}
 
bool term_value()
{
    bool result = factor_value();
    while (1)
    {
        DelSpace();
        char op = cin.peek();
        if (op == '&')
        {
            cin.get();
            result = factor_value() && result;
        }
        else
            break;
    }
    return result;
}
 
bool factor_value()
{
    bool result;
    DelSpace();
    char c = cin.get();
    if (c == '(')
    {
        result = expression_value();
        DelSpace();
        char temp = cin.get();
    }
    else if (c == '!')
        result = !factor_value();
    else
    {
        if (c == 'V')
            result = true;
        else if (c == 'F')
            result = false;
    }
    return result;
}
 
void DelSpace()
{
    while (cin.peek() == ' ')
        cin.get();
}
