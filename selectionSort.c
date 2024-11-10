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