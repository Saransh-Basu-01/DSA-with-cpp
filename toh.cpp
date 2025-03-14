#include<stdio.h>
#include<conio.h>
using namespace std;
void toh(int,char,char,char);
int main(){
    int n;
    printf("enter the number of disks\n");
    scanf("%d",&n);
    toh(n,'S','M','D');
    return 0;
}
void toh(int n,char S,char M,char D){
    if(n==1){
        printf("move disk 1 from %c to %c\n",S,D);
        return;
    }
    toh(n-1,S,D,M);
    printf("move disk %d from %c to %c\n",n,S,D);
    toh(n-1,M,S,D);
}