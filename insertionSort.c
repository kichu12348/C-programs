//insertion sort algorithm

#include <stdio.h>

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[6] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

//O(n^2) time complexity
//O(1) space complexity