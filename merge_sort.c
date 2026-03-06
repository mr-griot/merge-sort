// using c language 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1, n2;
    int *L, *R;

    n1 = mid - left + 1;
    n2 = right - mid;

    L = (int *)malloc(n1 * sizeof(int));
    R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printFirst100(int arr[], int size)
{
    int i;
    int limit;

    if (size > 100)
        limit = 100;
    else
        limit = size;

    for (i = 0; i < limit; i++)
        printf("%d ", arr[i]);

    if (size > 100)
        printf("\n... (only first 100 elements shown)");

    printf("\n");
}

int main()
{
    int n, i;
    int *arr;

    printf("Enter array size (1 to 10000000): ");
    scanf("%d", &n);

    if (n < 1 || n > 10000000)
    {
        printf("Invalid size. Enter a number from 1 to 10,000,000.\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < n; i++)
        arr[i] = rand() % 100000; 

    printf("\nArray before sorting:\n");
    printFirst100(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nArray after sorting:\n");
    printFirst100(arr, n);

    free(arr);

    return 0;
}