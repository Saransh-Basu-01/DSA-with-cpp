#include<iostream>
using namespace std;
int main(){
    int n,i,key,mid;
    int beg=0;
    cout<<"enter the number of elements in the array: ";
    cin>>n; 
    int arr[n];
    int end=n-1;
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
    mid=(beg+end)/2;
    while(beg<=end && arr[mid]!=key){
        if(key<arr[mid]){
            end=mid-1;
            cout<<"number to be searched is less than mid"<<endl;
        }
        else{
            beg=mid+1;
            cout<<"number to be searched is greater than mid"<<endl;
        }
        mid=(beg+end)/2;
    }
    if(arr[mid] == key){
        cout<<"element found at position: "<<mid+1;
    }
    else{
        cout<<"element not found";
    }
    return 0;
}