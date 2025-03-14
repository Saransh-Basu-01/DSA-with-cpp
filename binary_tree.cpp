#include<iostream>
using namespace std;
struct node{
    char info;
    struct node *lchild,*rchild;
};  
struct node *root=NULL,*pnew,*pthis,*ppthis,*ptemp;
void preorder(struct node *P){
    if(P!=NULL){
        cout<<P->info;
        preorder(P->lchild);
        preorder(P->rchild);
    }
}
void inorder(struct node *P){
    if(P!=NULL){
        inorder(P->lchild);
        cout<<P->info;
        inorder(P->rchild);
    }
}
void postorder(struct node *P){
    if(P!=NULL){
        postorder(P->lchild);
        postorder(P->rchild);
        cout<<P->info;
    }
}
void create(){
    pnew=new node;
    cout<<"enter the data\n";
    cin>>pnew->info;
    pnew->lchild=NULL;
    pnew->rchild=NULL;
}
int main(){
    int n;
    char c;
    do{
        cout<<"1.insert\n";
        cout<<"2.preorder\n";
        cout<<"3.postorder\n";
        cout<<"4.inorder\n";
        cout<<"5.exit\n";
        cout<<"enter your choice\n";
        cin>>n;
        switch(n)
        {
            case 1:
            create();
            if(root==NULL){
                root=pnew;
            }
            else{
                pthis=root;
                while(pthis!=NULL){
                    ppthis=pthis;
                    char ch;
                    cout<<"where do you want to insert the data\n";
                    cin>>ch;
                    if(ch=='l'){
                        pthis=pthis->lchild;
                        if(pthis==NULL){
                            ppthis->lchild=pnew;
                        }
                    }
                    else{
                        pthis=pthis->rchild;
                        if(pthis==NULL){
                            ppthis->rchild=pnew;
                        }
                    }
                }
            }
            break;
            case 2: 
            preorder(root);
            break;
            case 3: 
            postorder(root);
            break;
            case 4:
            inorder(root);
            break;
            case 5:
            exit(0);
        }
        cout<<"do you want to continue\n";
        cin>>c;
    }while(c=='y');
    return 0;
        }