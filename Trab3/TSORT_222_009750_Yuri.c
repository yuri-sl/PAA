#include <stdio.h>

#define MAX_SIZE 1000000

void quickSort(int arr[], int low, int high);
int hoarePartition(int arr[], int low, int high);

int main() {
    int t;
    scanf("%d", &t);

    int arr[MAX_SIZE];

    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, t - 1);

    for (int i = 0; i < t; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = hoarePartition(arr, low, high);
        quickSort(arr, low, partitionIndex);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
