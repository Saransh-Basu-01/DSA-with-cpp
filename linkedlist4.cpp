//doubly circular linked list
#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
    int info;
    struct node *next,*prev;
};
struct node *pnew,*pthis,*ptemp,*ptemp1,*head;
static int count=0;
void headp(){
    head=(struct node*)malloc(sizeof(struct node));
    head->next=head;
    head->prev=head;
    head->info=0;
}
void create(){
    pnew=(struct node*)malloc(sizeof(struct node));
    cout<<"enter the data\n";
    cin>>pnew->info;
    count++;
}
void insertatbeg(){
    if(head->next==head){
        head->next=pnew;
        head->prev=pnew;
        pnew->next=head;
        pnew->prev=head;
    }
    else{
        ptemp=head->next;
        head->next=pnew;
        pnew->prev=head;
        pnew->next=ptemp;
        ptemp->prev=pnew;
    }
}
void insertatend(){
    if(head->next==head){
        head->next=pnew;
        head->prev=pnew;
        pnew->next=head;
        pnew->prev=head;
    }
    else{
        ptemp=head->prev;
        head->prev=pnew;
        pnew->next=head;
        pnew->prev=ptemp;
        ptemp->next=pnew;
    }
}
void insert_before_sppos(){
    int loc;
    cout<<"enter the location\n";
    cin>>loc;
    if(loc==1){
        insertatbeg();
    }
    else if(loc>count||head->next==head||loc==0){
        cout<<"invalid operation\n";
    }
    else{
        pthis=head->next;
        for(int i=1;i<loc;i++){
            pthis=pthis->next;
        }
        ptemp=pthis->prev;
        ptemp->next=pnew;       
        pnew->prev=ptemp;
        pnew->next=pthis;
        pthis->prev=pnew;
    }
}
void insert_after_sppos(){
    int loc;
    cout<<"enter location\n";
    cin>>loc;
    if(loc==count){
        insertatend();
    } 
    else if(loc>count||head->next==NULL||loc==0){
        cout<<"invalid operation\n";
    }
    else{
        pthis=head->next;
        for(int i=1;i<loc;i++){
            pthis=pthis->next;
        }
        ptemp=pthis->next;
        pthis->next=pnew;
        pnew->prev=pthis;
        pnew->next=ptemp;
        ptemp->prev=pnew;
    }
}
void display(){
    if(head->next==head){
        cout<<"the list is empty\n";
    }
    else{
        pthis=head->next;
        while(pthis!=head){
            cout<<pthis->info<<" ";
            pthis=pthis->next;
        }
        cout<<endl;
    }
}
void deletionbeg(){
    if(head->next==head){
        cout<<"the list is empty:";
    }
    else if(head->next==head->prev){
        cout<<"the deleted data is:"<<head->next->info<<endl;
        count--;
        free(head->next);
        head->next=head;
        head->prev=head;
    }
    else{
        cout<<"the deleted data is:"<<head->next->info<<endl;
        count--;
        ptemp=head->next->next;
        free(head->next);
        head->next=ptemp;
        ptemp->prev=head;
    }
}
void deletionend(){
    if(head->next==head){
        cout<<"the list is empty:";
    }
    else if(head->next==head->prev){
        cout<<"the deleted data is:"<<head->next->info<<endl;
        count--;
        free(head->next);
        head->next=head;
        head->prev=head;
   }
    else{
        ptemp=head->prev->prev;
        cout<<"the deleted data is:"<<head->prev->info<<endl;
        count--;
        free(head->prev);
        head->prev=ptemp;
        ptemp->next=head;
    }
}
void delete_spec_node(){
    int loc;
    cout<<"enter the location\n";
    cin>>loc;
    if(loc==1){
        deletionbeg();
    }
    else if(loc==0||loc>count){
        cout<<"invalid operation\n";
    }
    else if(loc==count){
        deletionend();
    }
    else{
        pthis=head->next;
        for(int i=1;i<loc;i++){
            pthis=pthis->next;
        }
        ptemp=pthis->prev;
        ptemp1=pthis->next;
        cout<<"the deleted data is:"<<pthis->info<<endl;
        count--;
        free(pthis);
        ptemp->next=ptemp1;
        ptemp1->prev=ptemp;
        }
}
int main(){
    int n;
    char c;
    headp();
    do{
        cout<<"1 insert at beg\n";
        cout<<"2 insert at end\n";
        cout<<"3 insert before specified location\n";
        cout<<"4 insert after specified location\n";
        cout<<"5 delete at beg\n";
        cout<<"6 delete at end\n";
        cout<<"7 delete at specified location\n";
        cout<<"8.display\n";
        cout<<"9exit\n";
        cout<<"enter your choice\n";
        cin>>n;
        switch(n){
            case 1:
            create();
            insertatbeg();
            break;
            case 2:
            create();
            insertatend();;
            break;
            case 3:
            create();
            insert_before_sppos();
            break;
            case 4:
            create();
            insert_after_sppos();
            break;
            case 5:
            deletionbeg();
            break;
            case 6:
            deletionend();
            break;
            case 7:
            delete_spec_node();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            break;
        }
        cout<<"do you want to continue?(y/n)\n";
        cin>>c;
    }while(c=='y');
return 0;
}