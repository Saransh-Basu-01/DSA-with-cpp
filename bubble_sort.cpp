#include<iostream>
using namespace std;
int main(){
    int n,temp;
    int j=0;
    int i=0;
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
        for(int k=0;k<n;k++){ 
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            for(int k=0;k<n;k++){
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