#include <stdio.h>
#include <stdlib.h>

int getNextGap(int gap){
    gap = (gap * 10) / 13;
    if (gap < 1)
    {
        return 1;
    }
    return gap;
}

void combSort(int arr[], int sizeArr){
    int gap = sizeArr;

    while (gap != 1)
    {
        gap = getNextGap(gap);

        for (int i = 0; i < sizeArr - gap; i++)
        {
            if (arr[i]> arr[i + gap])
            {
                int aux = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = aux;
            }  
        } 
    }   
}

void printArray(int arr[], int sizeArr) {
    for (int i = 0; i < sizeArr; i++) 
        printf("%d ", arr[i]);
}

int main() {
    int arr[] = { 5, 10, 11, 3, 4, 1, 13, 15, 2, 20, 16, 7, 19, 14};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    printf("Array desordenada:\n");
    printArray(arr, sizeArr);

    combSort(arr, sizeArr);

    printf("\nArray ordenada:\n");
    printArray(arr, sizeArr);

    return 0;
}