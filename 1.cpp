// stack dsa with pop and push method
#define maxsize 5
#include <iostream>
using namespace std;
int main()
{
    int TOP = -1;
    int stack[maxsize], data;
    int a;
    char ch;
    do
    {
        cout << "enter your choice"<<endl;
        cout << "1.push\n";
        cout << "2.pop\n";
        cout << "3.display\n";
        cout << "4.exit\n";
        cin >> a;
        switch (a)
        {
        case 1:
            if (TOP == maxsize - 1)
            {
                cout << "stack is overflow";
            }
            else
            {
                TOP = TOP + 1;
                cout << "enter data";
                cin >> data;
                stack[TOP] = data;
            }
            break;
        case 2:
            if (TOP < 0)
            { // if top==-1
                cout << "stack is underflow";
            }
            else
            {
                data = stack[TOP];
                cout << "deleted item is:"<< data<<endl;
                TOP = TOP - 1;
            }
            break;
        case 3:
            if (TOP < 0)
            {
                cout << "stack is underflow"<<endl;
            }
            else
            {
                for (int i = 0; i <= TOP; i++)
                {
                    cout << stack[i]<<endl;
                }
            }
                break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
        cout << "do you want to continue(y/n)" << endl;
        cin >> ch;
    } while (ch == 'y' &&  ch!='n');
    return 0;
}