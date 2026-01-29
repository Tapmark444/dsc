#include <stdio.h>

/* Merge two subarrays */
void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[50];

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

/* Merge sort function */
void mergeSort(int arr[], int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

/* Main function */
int main() {
    int arr[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted list:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
/*
INPUT :
Enter number of elements: 6
Enter elements:
38 27 43 3 9 82
OUTPUT:
Sorted list:
3 9 27 38 43 82

*/
