#include<stdio.h>

void merge(int arr[],int left,int mid,int right){
   int i=left,
   j=mid+1,
   k=0,
   temp[right-left+1];

   while(i<=mid && j<=right){
    if(arr[j]<arr[i]) temp[k++] = arr[j++];
    else temp[k++] = arr[i++];
   }

   while(i<=mid) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];
    for(int i=left,k=0;i<=right;i++,k++)  arr[i] = temp[k];
}


void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid = (left + right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
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