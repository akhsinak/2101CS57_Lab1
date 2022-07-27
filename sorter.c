#include <stdio.h>
int main()
{
    int n;
    printf("Enter array size:");
    scanf("%d", &n);

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
    }
    break;

    default:
        break;
    }
}