//linear search

#include <stdio.h>

int linearSearch(int arr[],int n,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val) return i;
    }
    return -1;
}

void main(){
    int arr[]={2,3,4,10,40};
    int n=sizeof(arr)/sizeof(arr[0]);
    int val=10;
    int result=linearSearch(arr,n,val);
    if(result==-1){
        printf("Element not found\n");
    }else{
        printf("Element found at index %d\n",result);
    }
}