#include<iostream>
using namespace std;
int main(){
    int n,i,j,key;
    cout<<"enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"array is: ";
    cout<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"enter the element to be searched: ";
    cin>>key;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"element found at position: "<<i+1;
            break;
        }
    }
    if(i==n){
        cout<<"element not found";
    }
    return 0;
}