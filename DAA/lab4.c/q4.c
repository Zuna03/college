#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition_asc(int array[], int low, int high)
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

void quickSort_asc(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_asc(array, low, high);
        quickSort_asc(array, low, pi - 1);
        quickSort_asc(array, pi + 1, high);
    }
}

int partition_dsc(int array[], int low, int high)
{

    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] >= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort_dsc(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_dsc(array, low, high);
        quickSort_dsc(array, low, pi - 1);
        quickSort_dsc(array, pi + 1, high);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void randomArray(int arr[], int n)
{
    int rand_max;
    printf("Enter the largest random number you want :- ");
    scanf("%d", &rand_max);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % rand_max;
    }
}
void to_sort_half(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

double timeComplexity(clock_t start, clock_t end)
{
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
    int t = 1;
    int n;
    printf("Enter the size of the array :- ");
    scanf("%d", &n);
    int arr[n];
    printf("0. Quit.\n");
    printf("1. Create array with random Numbers.\n");
    printf("2. Display the Random array list.\n");
    printf("3. Quick Sort the array in Ordered list.\n");
    printf("4. Quick Sort the array in Reverse ordered list.\n");
    printf("5. sort half of array\n");
    printf("6. Find the time complexity to sort ascending of random data.\n");
    printf("7. Find the time complexity to sort ascending of data already sorted in ascending order.\n");
    printf("8. Find the time complexity to sort ascending of data already sorted in descending order.\n");
    while (t)
    {

        int choice;
        printf("\nEnter Your choice :-");
        scanf("%d", &choice);
        clock_t start, end;

        switch (choice)
        {
        case 0:
            printf("Exiting the code....\n");
            t = 0;
            break;
        case 1:
            randomArray(arr, n);
            printf("Random array generated...\n\n");
            break;
        case 2:
            printf("The current array is :- \n");
            displayArray(arr, n);
            break;
        case 3:
            printf("The array before sorting :-\n");
            displayArray(arr, n);
            quickSort_asc(arr, 0, n - 1);
            printf("The array after Quick sorting in ordered list :-\n");
            displayArray(arr, n);
            break;
        case 4:
            printf("The array before sorting :-\n");
            displayArray(arr, n);
            quickSort_dsc(arr, 0, n - 1);
            printf("The array after  Quick sorting in reverse ordered list :-\n");
            displayArray(arr, n);
            break;
        case 5:
            printf("The array before sorting :-\n");
            displayArray(arr, n);
            to_sort_half(arr, n);
            printf("The array after half sort in reverse ordered list :-\n");
            displayArray(arr, n);
            break;
        case 6:
            printf("Time complexity of sorting a random array :-\n");
            randomArray(arr, n);
            printf("Array :- ");
            displayArray(arr, n);
            start = clock();
            quickSort_asc(arr, 0, n - 1);
            end = clock();
            printf("Time complexity:- %lf\n", timeComplexity(start, end));
            break;
        case 7:
            printf("Time complexity of sorting a array already sorted in ascending order :-\n");
            randomArray(arr, n);
            quickSort_asc(arr, 0, n - 1);
            printf("Array :- ");
            displayArray(arr, n);
            start = clock();
            quickSort_asc(arr, 0, n - 1);
            end = clock();
            printf("Time complexity:- %lf\n", timeComplexity(start, end));
            break;
        case 8:
            printf("Time complexity of sorting an array already sorted in descending order :-\n");
            randomArray(arr, n);
            quickSort_dsc(arr, 0, n - 1);
            printf("Array :- ");
            displayArray(arr, n);
            start = clock();
            quickSort_asc(arr, 0, n - 1);
            end = clock();
            printf("Time complexity:- %lf\n", timeComplexity(start, end));
            break;
        }
    }

    return 0;
}