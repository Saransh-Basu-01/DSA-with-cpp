// infix to postfix
#include<iostream>
#include<string.h>
using namespace std;
int top=-1;
int pos=0;
char stack[50];
char data;
void push(char x){
    top=top+1;
    stack[top]=x;
}
char pop(){
    data=stack[top];
    top=top-1;
    return data;
}
int precedence(char op){
    if(op=='*'|| op=='/'){
        return 2;
    }
    if(op=='+'|| op=='-'){
        return 1;
    }
}
int main(){
    char infix[50],postfix[50];
    cout<<"enter the infix string\n";
    cin>>infix;
    int n=strlen(infix);
    for(int i=0;i<n;i++){
        cout<<infix[i]<<endl;
        if(infix[i]>=33 && infix[i]<=47){
            if(infix[i]=='('){
                push(infix[i]);
            }
            else if(infix[i]==')'){
                while(stack[top]!='('){
                    char popped=pop();
                    postfix[pos]=popped;
                    pos++;
                }
                top=top-1;
            }
            else{
                while(top>-1 && stack[top]!='('){
                    if(precedence(stack[top])>=precedence(infix[i])){
                        char popped=pop();
                        postfix[pos]=popped;
                        pos++;
                    }
                    else{
                        break;
                    }
                }
                push(infix[i]);
            }
        }
        else{
            postfix[pos]=infix[i];
            pos++;
        }
    }
    if(top==-1){
        cout<<postfix;
    }
    else{
        while(top!=-1){
            char popped=pop();
            postfix[pos]=popped;
            pos++;
        }
        cout<<postfix;
    }
    return 0;
}
