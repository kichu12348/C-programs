#include<stdio.h>


int binarySearch(int arr[],int n,int val){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==val) return mid;
        else if(arr[mid]<val) low=mid+1;
        else high=mid-1;
    }

    return -1;
}

void main(){
    int arr[]={2,3,4,10,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int val=10;
    int result=binarySearch(arr,n,val);
    if(result==-1){
        printf("Element not found\n");
    }else{
        printf("Element found at index %d\n",result);
    }
}