#include<stdio.h>

int binarySearch(int arr[],int low,int high,int val){
    int mid = (low+high)/2;
    if(low<=high){
        if(arr[mid]==val) return mid;
        else if(arr[mid]<val) return binarySearch(arr,mid+1,high,val);
        else return binarySearch(arr,low,mid-1,val);
    }
    return -1;
}

void main(){
    int arr[]={2,3,4,10,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int val=10;
    int result=binarySearch(arr,0,n-1,val);
    if(result==-1){
        printf("Element not found\n");
    }else{
        printf("Element found at index %d\n",result);
    }
}