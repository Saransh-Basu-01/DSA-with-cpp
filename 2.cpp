// program for postfix expn
#define maxsize 5
#include<iostream>
#include<conio.h>
#include<math.h>
#include<string.h>
using namespace std;
int stack[maxsize];
int top=-1;
char str[30];
int pop(){
    int data=stack[top];
    top=top-1;
    return data;
}
void push(int x){
    top=top+1;
    stack[top]=x;
}
int main()
{
    int a,b,l,var;
    int i;
    cout<<"enter the  post fix string you want to calculate\n";
    cin>>str;
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        cout<<str[i]<<"\n";
        if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*')
        {
            a=pop();
            b=pop();
            switch(str[i])
            {
                case '+':
                var=b+a;
                break;
                case '-':
                var=b-a;
                break;
                case '/':
                var=b/a;
                break;
                case '*':
                var=b*a;
                break;
                default:
                cout<<"invalid input\n";
                break;
            }
            push(var);
        }
        else{
            push(str[i]-48);
        }
    }
    cout<<stack[top];
    return 0;    
}
