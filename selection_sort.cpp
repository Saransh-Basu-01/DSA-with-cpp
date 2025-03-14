#include<iostream>
using namespace std;
int main(){
    int n,temp,i,j,k;
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
    for(i=0;i<n-1;i++){
        cout<<i+1<<":pass"<<endl;
        for(k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            for(k=0;k<n;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"sorted array is: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}