#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
    int i= left,//starting index of left subarray
    j=mid+1,//starting index of right subarray
    k=0,//starting index of temp array
    temp[right-left+1];//temporary array to store the sorted elements

    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }


    while(i<=mid){
        temp[k++]=arr[i++];
    }

    while(j<=right){
        temp[k++]=arr[j++];
    }

    for(k=0,i=left;i<=right;i++,k++){
        arr[i]=temp[k];
    }
}


void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr,left,mid);//splitting the array into two halves from left to mid
        mergeSort(arr,mid+1,right);//splitting the array into two halves from mid+1 to right
        merge(arr,left,mid,right); //merging the two halves
    }
}


int main(){
    int arr[6] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}


//O(nlogn) time complexity
//O(n) space complexity