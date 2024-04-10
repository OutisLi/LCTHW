#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *array, int low, int high, compare_cb cmp)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (cmp(array[j], pivot) < 0)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(int *array, int low, int high, compare_cb cmp)
{
    if (low < high)
    {
        int pi = partition(array, low, high, cmp);

        quick_sort(array, low, pi - 1, cmp);
        quick_sort(array, pi + 1, high, cmp);
    }
}

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - 1; j++)
        {
            if (cmp(target[j], target[j + 1]) > 0)
            {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int *quick_sort_wrapper(int *numbers, int count, compare_cb cmp)
{
    int *target = malloc(count * sizeof(int));
    if (!target)
        die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));
    quick_sort(target, 0, count - 1, cmp);

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    else
    {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = quick_sort_wrapper(numbers, count, cmp);

    if (!sorted)
        die("Failed to sort as requested.");

    for (i = 0; i < count; i++)
    {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);

    unsigned char *data = (unsigned char *)cmp;
    for (i = 0; i < 25; i++)
    {
        printf("%02X:", data[i]); // %02X: print as hex, 2 digits, 0 padded
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers)
        die("Memory error.");

    for (i = 0; i < count; i++)
    {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    return 0;
}