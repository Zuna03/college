#include <stdio.h>

// program to merge two sorted arrays

void merge_array_195(int arr1_195[], int arr2_195[], int l1_195, int l2_195)
{
    int i = 0, j = 0, k = 0;

    int l3_195 = l1_195 + l2_195;
    int arr3_195[l1_195 + l2_195];

    while (i < l1_195 && j < l2_195)
    {
        if (arr1_195[i] < arr2_195[j])
        {
            arr3_195[k] = arr1_195[i];
            i++;
            k++;
        }
        else if (arr1_195[i] > arr2_195[j])
        {
            arr3_195[k] = arr2_195[j];
            j++;
            k++;
        }
        else
        {
            arr3_195[k] = arr1_195[i];
            i++;
            k++;
            arr3_195[k] = arr2_195[j];
            j++;
            k++;
        }
    }

    // for rest of the elements left in one of the two arrays

    while (i < l1_195)
    {
        arr3_195[k] = arr1_195[i];
        i++;
        k++;
    }

    while (j < l2_195)
    {
        arr3_195[k] = arr2_195[j];
        j++;
        k++;
    }

    int size_195 = sizeof(arr3_195);

    // printing merged array

    for (int x = 0; x < l3_195; x++)
    {
        printf("%d  ", arr3_195[x]);
    }
}
int main()
{
    printf("Enter size of first array :- \n");
    int l1_195;
    scanf("%d", &l1_195);

    int arr1_195[l1_195];
    printf("Enter elements of first array");

    for (int i = 0; i < l1_195; i++)
    {
        scanf("%d", &arr1_195[i]);
    }

    printf("Enter size of second array :- \n");
    int l2_195;
    scanf("%d", &l2_195);

    int arr2_195[l2_195];
    printf("Enter elements of second array");

    for (int i = 0; i < l2_195; i++)
    {
        scanf("%d", &arr2_195[i]);
    }

    merge_array_195(arr1_195, arr2_195, l1_195, l2_195);

    return 0;
}