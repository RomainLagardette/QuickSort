#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void random_shuffle(int array[])
{
    srand(time(NULL));
    int i, j, temp;
    for (i = MAX - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int array[], int start, int end)
{
    int pivotIndex = start + rand()%(end - start + 1); //generates a random number as a pivot
    int pivot;
    int left = start - 1;
    int temp;
    pivot = array[pivotIndex];
    swap(&array[pivotIndex], &array[end]);
    for (temp = start; temp < end; temp++)
    {
        if (array[temp] < pivot)
        {
            left++;
            swap(&array[left], &array[temp]);
        }

    }
    swap(&array[left+1], &array[end]);
    return left + 1;
}

void quick_sort(int array[], int start, int end)
{
    int pivot;
    if (start < end)
    {
        pivot = partion(array, start, end);
        quick_sort(array, start, pivot-1);
        quick_sort(array, pivot+1, end);
    }
}

int main()
{
    int i;
    int array[MAX];

    for (i = 0; i < MAX; i++)
        array[i] = i;

    random_shuffle(array);

    for (i = 0; i < MAX; i++)
         printf("%d ", array[i]);
    printf("\n");

    quick_sort(array, 0, MAX-1);

    for (i = 0; i < MAX; i++)
         printf("%d ", array[i]);
    printf("\n");

    return 0;
}
