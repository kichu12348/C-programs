// selection sort algorithm

#include <stdio.h>

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]) minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}


int main(){
    int arr[6] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

// O(n^2) time complexity
// O(1) space complexity

//pseudo code

/*
selectionSort(arr):
    1. for i=0 and i<n then i++:
        1.1 minIdx = i
        1.2 for j=i+1 and j<n then j++:
            1.2.1 if arr[j]<arr[minIdx] then minIdx = j
        1.3 temp = arr[i]
        1.4 arr[i] = arr[minIdx]
        1.5 arr[minIdx] = temp
*/