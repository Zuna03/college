#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *insert(int array[], int size, int *t1, int *time)
{
    clock_t start;
    int i, j, key;
    start = clock();
    for (j = 1; j < size; j++)
    {
        key = array[j];
        i = j - 1;

        while (i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i = i - 1;
            array[i + 1] = key;
        }
    }

    start = clock() - start;
    *t1 = start;
    *time = start;
    printf("%ld\n\n", start);

    return array;
}

int *decrem(int array[], int size, int *t2, int *time1)
{
    clock_t time;
    int i, j, key;
    time = clock();
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {

            if (array[i] < array[j])
            {
                key = array[i];
                array[i] = array[j];
                array[j] = key;
            }
        }
    }

    time = clock() - time;
    *t2 = time;
    *time1 = time;
    return array;
}

int main()
{
    int k = 0, l = 0, m = 0, o = 0;
    int time_i[20], time_a[20], time_d[20], n_value[50];
    while (1)
    {
        printf("\n0. quit");
        printf("\n1. generate array");
        printf("\n2. Display array");
        printf("\n3. Insertion sort ascending");
        printf("\n4. Descending order");
        printf("\n5. Time complexity in ascending");
        printf("\n6. Time complexity of aldready sorted array(increasing)");
        printf("\n7. Time complexity of sorted array(descending)");
        printf("\n8. TC calculate");
        int size, choice, i, j, array[10000], key;
        int *p;
        int *q;
        int t1, t2;
        printf("\n\nEnter choice :");
        scanf("%d", &choice);

        switch (choice)
        {

        case 0:
            printf("Exit program");
            exit(0);

        case 1:
            printf("enter the size of array : ");
            scanf("%d", &size);
            for (i = 0; i < size; i++)
            {
                array[i] = rand() / 10000000;
            }
            n_value[o] = size;
            o++;
            break;

        case 2:
            printf("\n Elements in the array :");
            for (i = 0; i < size; i++)
            {
                printf("%d   ", array[i]);
            }
            break;

        case 3:
            p = insert(array, size, &t1, &time_i[k]);
            k++;
            break;

        case 4:
            q = decrem(array, size, &t2, &time_d[m]);
            m++;
            break;

        case 5:

            printf("time complexity of insertion (random data): %d\n\n", t1);

            break;

        case 6:
            insert(array, size, &t1, &time_a[l]);
            l++;
            printf("time complexity of already inserted array : %d\n\n", t1);
            break;

        case 7:
            printf("time complexity of inserted array to reverse order : %d\n\n", t2);
            break;

        case 8:
            for (i = 0; i < 5; i++)
            {
                printf("n = %d, time_comlexity(random data) = %d, time_complexity(inserted) = %d,  time_complexity(decreasing) = %d\n\n", n_value[i], time_i[i], time_a[i], time_d[i]);
            }
            break;
        }
    }

    return 0;
}