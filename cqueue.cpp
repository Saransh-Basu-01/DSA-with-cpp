// circular queue
#include<iostream>
using namespace std;
#define max 5
int rear=-1,front=-1;
int data,queue[max];
int main(){
    int n,i;
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
                if(front==(rear+1)%max){
                    cout<<"queue is overflow\n";
                }
                else{
                    rear=(rear+1)%max;
                    cout<<"enter a data:";
                    cin>>data;
                    if(front==-1){
                        front=0;
                    }
                    queue[rear]=data;
                }
                break;
            case 2:
                if(front==-1){
                    cout<<"queue is underflow\n";                    
                }
                else if(front==rear){
                        cout<<"the dequed element is:"<<queue[front];
                        front=-1;
                        rear=-1;
                    }
                else{
                        cout<<"the dequeued element is:"<<queue[front];
                        front=(front+1)%max;
                    }
                break;
            case 3:
                if(front==-1){
                    cout<<"queue is underflow\n";
                }
                else{
                    i=front;
                    while(i!=rear){
                        cout<<queue[i]<<endl;
                        i=(i+1)%max;
                    }
                cout<<queue[i];
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