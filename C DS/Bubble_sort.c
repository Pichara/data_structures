#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        //Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++) {
            
            //Swap if the element is greater than the next (using a temp variable)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]); //Finding the size of the array

    printf("Unsorted array:\n");
    printArray(data, size);

    bubbleSort(data, size);

    printf("Sorted array:\n");
    printArray(data, size);

    return 0;
}


