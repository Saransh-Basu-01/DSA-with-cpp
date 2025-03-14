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
    cout<<"array after each pass is: "<<endl;
    i=0;
    while(i<=n-1){
        temp=arr[i];
        j=i-1;
        while(j>=0){
            if(temp<arr[j]){
                arr[j+1]=arr[j];
                j=j-1;
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
        i++;
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
    cout<<"sorted array is: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}