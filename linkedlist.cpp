//singly linear linked list
#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
    int info;
    struct node *next;
};
struct node *pfirst=NULL,*pnew,*pthis,*ptemp;
static int count=0;
void create(){
    pnew=(struct node*)malloc(sizeof(struct node));
    cout<<"enter the data\n";
    cin>>pnew->info;
    count++;
}
void insertatbeg(){
    if(pfirst==NULL){
        pfirst=pnew;
        pfirst->next=NULL;
    }
    else{
        pnew->next=pfirst;
        pfirst=pnew;
    }
}
void insertatend(){
    if(pfirst==NULL){
        pfirst=pnew;
        pfirst->next=NULL;
    }
    else{
        pthis=pfirst;
        while(pthis->next!=NULL){
            pthis=pthis->next;
        }
        pthis->next=pnew;
        pnew->next=NULL;
    }
}
void insert_before_sppos(){
    int loc;
    cout<<"enter the location\n";
    cin>>loc;
    if(loc==1){
        insertatbeg();
    }
    else if(loc>count||pfirst==NULL||loc==0){
        cout<<"invalid operation\n";
    }
    else{
        pthis=pfirst;
        for(int i=1;i<loc-1;i++){
            pthis=pthis->next;
        }
        ptemp=pthis->next;
        pthis->next=pnew;
        pnew->next=ptemp;
    }
}
void insert_after_sppos(){
    int loc;
    cout<<"enter location\n";
    cin>>loc;
    if(loc==count){
        insertatend();
    } 
    else if(loc>count||pfirst==NULL||loc==0){
        cout<<"invalid operation\n";
    }
    else{
        pthis=pfirst;
        for(int i=1;i<loc;i++){
            pthis=pthis->next;
        }
        ptemp=pthis->next;
        pthis->next=pnew;
        pnew->next=ptemp;
    }
}
void display(){
    if(pfirst==NULL){
        cout<<"the list is empty";
    }
    else{
        pthis=pfirst;
        while(pthis->next!=NULL){
            cout<<pthis->info<<"\n";
            pthis=pthis->next;
        }
        cout<<pthis->info<<endl;
    }
}
void deletionbeg(){
    if(pfirst==NULL){
        cout<<"the list is empty:";
    }
    else if(pfirst->next==NULL){
        cout<<"the deleted data is:"<<pfirst->info;
        count--;
        free(pfirst);
        pfirst=NULL;
    }
    else{
        cout<<"the deleted data is:"<<pfirst->info<<endl;
        count--;
        ptemp=pfirst->next;
        free(pfirst);
        pfirst=ptemp;
    }
}
void deletionend(){
    if(pfirst==NULL){
        cout<<"the list is empty:";
    }
    else if(pfirst->next==NULL){
        cout<<"the deleted data is:"<<pfirst->info;
        count--;
        free(pfirst);
        pfirst=NULL;
    }
    else{
        pthis=pfirst;
        while(pthis->next->next!=NULL){
            pthis=pthis->next;
        }
        cout<<"the deleted data is:"<<pthis->next->info<<endl;
        count--;
        free(pthis->next);
        pthis->next=NULL;
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
        pthis=pfirst;
        for(int i =1;i<loc-1;i++){
            pthis=pthis->next;
        }
        ptemp=pthis->next->next;
        cout<<"the deleted data is:"<<pthis->next->info<<endl;
        free(pthis->next);
        count--;
        pthis->next=ptemp;
    }
}
int main(){
    int n;
    char c;
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