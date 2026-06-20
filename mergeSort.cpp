#include<iostream>
using namespace std;
void merge(int arr[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=left;
    int temp[100];
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
        }else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=right){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(int i=left;i<=right;i++){
        arr[i]=temp[i];
    }
}
void merge_Sort(int arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_Sort(arr,left,mid);
        merge_Sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    return;
}
void display(int arr[],int n){
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    merge_Sort(arr,0,n-1);
    cout<<"Sorted Array: ";
    display(arr,n);
    return 0;
}