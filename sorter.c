#include <stdio.h>
void sort_by_insertion_and_print(int arr[], int n)
{
    int p, slider, q;
    for (p = 1; p < n; p++)
    {
        slider = arr[p];
        q = p - 1;

        while (q >= 0 && arr[q] > slider)
        {
            arr[q + 1] = arr[q];
            q = q - 1;
        }
        arr[q + 1] = slider;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_by_selection_and_print(int array[], int n)
{

    for (int step = 0; step < n - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < n; i++)
        {

            if (array[i] < array[min_idx])
                min_idx = i;
        }

        swap(&array[min_idx], &array[step]);
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void bubbleSort_and_print(int arr[], int n)
{
    int j;
    for (int i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

void mergesort_and_print(int arr[], int n)
{
    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int array[], int low, int high)
{

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            i++;

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void quicksort_and_print(int arr[], int n)
{
    quickSort(arr, 0, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter array size:");
    scanf("%d", &n);
    printf("Enter the array: \n");
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Choose the sorting technique to use:\n");
    printf("1 -> Insertion sort\n");
    printf("2 -> Selection sort\n");
    printf("3 -> Bubble sort\n");
    printf("4 -> Merge Sort\n");
    printf("5 -> Quick Sort\n");
    printf("Enter your option:");

    int status;
    scanf("%d", &status);

    switch (status)
    {
    case 1:
    {
        sort_by_insertion_and_print(arr, n);
    }
    break;

    case 2:
    {
        sort_by_selection_and_print(arr, n);
    }
    break;

    case 3:
    {
        bubbleSort_and_print(arr, n);
    }
    break;

    case 4:
    {
        mergesort_and_print(arr, n);
    }
    break;
    case 5:
    {
        quicksort_and_print(arr, n);
    }
    break;
    default:
        break;
    }
}