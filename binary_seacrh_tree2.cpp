// binary search tree
#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *lchild, *rchild;
};
struct node *root = NULL, *pnew, *pthis, *ppthis, *ptemp;
void preorder(struct node *P)
{
    if (P != NULL)
    {
        cout << P->info << endl;
        preorder(P->lchild);
        preorder(P->rchild);
    }
}
void inorder(struct node *P)
{
    if (P != NULL)
    {
        inorder(P->lchild);
        cout << P->info << endl;
        inorder(P->rchild);
    }
}
void postorder(struct node *P)
{
    if (P != NULL)
    {
        postorder(P->lchild);
        postorder(P->rchild);
        cout << P->info << endl;
    }
}
void create()
{
    pnew = (struct node *)malloc(sizeof(struct node));
    cout << "enter the data\n";
    cin >> pnew->info;
    pnew->lchild = NULL;
    pnew->rchild = NULL;
}
int main()
{
    int n;
    char c;
    int m;
    char ch;
    cout <<"do you want to create a tree\n";
    cin >> ch;
    while(ch=='y'||ch=='Y'){
        cout << "enter the number of nodes u want to enter\n";
        cin >> m;
    for (int i = 0; i < m; i++)
    {
        create();
        if (root == NULL)
        {
            root = pnew;
        }
        else
        {
            pthis = root;
            while (pthis != NULL)
            {
                ppthis = pthis;
                if (pnew->info < pthis->info)
                {
                    pthis = pthis->lchild;
                    if (pthis == NULL)
                    {
                        ppthis->lchild = pnew;
                    }
                }
                else
                {
                    pthis = pthis->rchild;
                    if (pthis == NULL)
                    {
                        ppthis->rchild = pnew;
                    }
                }
            }
        }
    }
    ch=n;
    cout<<"you cant create a new tree after creating one tree\n";
}
    do
    {
        cout << "1 preorder\n";
        cout << "2 inorder\n";
        cout << "3 postorder\n";
        cout << "4.search specific node\n";
        cout << "5 exit\n";
        cout << "enter your choice\n";
        cin >> n;
        switch (n)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            int data;
            cout << "enter the data to be searched\n";
            cin >> data;
            pthis = root;
            if (root == NULL)
            {
                cout << " tree is empty\n";
            }
            else
            {
                while (pthis != NULL)
                {
                    if (data == pthis->info)
                    {
                        cout << "data found\n";
                        cout << pthis->info << endl;
                        break;
                    }
                    else if (data < pthis->info)
                    {
                        cout << "data is in left subtree below this data:";
                        cout << pthis->info << endl;
                        pthis = pthis->lchild;
                    }
                    else
                    {
                        cout << "data is in right subtree below this data:";
                        cout << pthis->info << endl;
                        pthis = pthis->rchild;
                    }
                }
                if(pthis==NULL){
                    cout<<"data not found\n";
                }
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "invalid choice\n";
        }
        cout << "do you want to continue\n";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    return 0;
}
