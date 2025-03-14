// linear queue
#include<iostream>
#include<string.h>
using namespace std;
int rear=-1,front=-1;
#define max 5
int data,queue[max];
int main(){
    int n;
    char c;
    do{
        cout<<"enter your choice\n";
        cout<<"1.enqueue\n";
        cout<<"2.dequeue\n";
        cout<<"3.display\n";
        cout<<"4.exit\n";
        cin>>n;
        switch(n){
            case 1:
                if(rear==max-1){
                    cout<<"queue is overflow\n";
                }
                else{
                    cout<<"enter the data\n";
                    cin>>data;
                    rear=rear+1;
                    if(front==-1){
                        front=0;
                    }
                    queue[rear]=data;
                }
                break;
            case 2:
                if(front==-1){
                    cout<<"queue is undeflow\n";
                }
                else{
                    data=queue[front];
                    cout<<"the dequeued data is:"<<data<<endl;
                    front=front+1;
                    if(front>rear){
                    front=-1;
                    rear=-1;
                }
                }
                break;
            case 3:
                if(front==-1){
                    cout<<"queue is underflow\n";
                }
            else{
                for(int i=front;i<=rear;i++){
                    cout<<queue[i]<<endl;
                }
            }
            break;
            case 4:
                exit(0);
                break;
            default:
                break;
        }
    cout<<"do you want to continue\n";
    cin>>c;
    }while(c=='y');
    return 0;
}
