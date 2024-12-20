// insertion sort algorithm

#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, j, piv;
    for (int i = 1; i < n; i++)
    {
        piv = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > piv)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = piv;
    }
}

int main()
{
    int arr[6] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// O(n^2) time complexity
// O(1) space complexity

//pseudo code

/*
insertionSort(arr):
    1. for i = 1 and i<n then i++ :
        1.1 piv = arr[i]
        1.2 j = i - 1
        1.3 while j >= 0 && arr[j] > piv:
            1.3.1 arr[j + 1] = arr[j]
            1.3.2 j--
        1.4 arr[j + 1] = piv

*/