// program for prefix expression
#include <iostream>
#include <math.h>
#include <string.h>
#include <cstring>
using namespace std;
#define maxsize 10
int stack[maxsize];
int top=-1,data;
char str[50];
int pop()
{
    data=stack[top];
    top=top-1;
    return data;

}
void push(int x)
{
    top=top+1;
    stack[top]=x;
}
int main()
{
    int a, b, i, var;
    int l;
    cout << "enter the value of string prefix string:\n";
    cin >> str;
    strrev(str);
    l = strlen(str);
    for (i = 0; i < l; i++)
    {
        cout << str[i] << "\n";
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            a = pop();
            b = pop();
             switch (str[i])
            {
            case '+':
                var = a + b;
                break;
            case '-':
                var = a - b;
                break;
            case '/':
                var = a / b;
                break;
            case '*':
                var = b * a;
                break;
            default:
                cout << "invalid input\n";
                break;
            }
            push(var);
        }
        else
        {
            push(str[i]-48);
        }
    }
        cout<<stack[top];
        return 0;
}