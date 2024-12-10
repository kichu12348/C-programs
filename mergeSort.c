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

//pseudo code

/*
merge(arr,left,mid,right):
    1. i = left
    2. j = mid+1
    3. k = 0
    4. temp[right-left+1]
    5. while i<=mid && j<=right:
        5.1 if arr[j]<arr[i] then temp[k++] = arr[j++]
        5.2 else temp[k++] = arr[i++]
    6. while i<=mid then temp[k++] = arr[i++]
    7. while j<=right then temp[k++] = arr[j++]
    8. for i=left and k=0 then i<=right then i++ and k++:
        8.1 arr[i] = temp[k]


mergeSort(arr,left,right):
    1. if left<right:
        1.1 mid = (left + right)/2
        1.2 mergeSort(arr,left,mid)
        1.3 mergeSort(arr,mid+1,right)
        1.4 merge(arr,left,mid,right)
*/