#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lowInd, int higInd) {
    int pivo = arr[lowInd];
    int i = lowInd;

    for (int j = lowInd + 1; j < higInd; j++)
    {
        if (arr[j] < pivo)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }      
    }
    swap(&arr[lowInd], &arr[i]);
    return i;
}

void quickSort(int arr[], int lowInd, int higInd) {
    if (lowInd < higInd)
    {
        int pi = partition(arr, lowInd, higInd);
        quickSort(arr, lowInd, pi - 1);
        quickSort(arr, pi + 1, higInd);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[] = {5, 10, 11, 3, 4, 1, 13, 15, 2, 20, 16, 7, 19, 14};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array desordenada:\n");
    printArray(arr, sizeArr);

    quickSort(arr, 0, sizeArr - 1);

    printf("\nArray ordenada:\n");
    printArray(arr, sizeArr);
    
    return 0;
}