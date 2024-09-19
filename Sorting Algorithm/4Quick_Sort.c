#include <stdio.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(int a[], int start, int end)
{
    int pivot = a[start]; 
    int left = start + 1;
    int right = end;

    while (left <= right)
    {
        // Increment left index while the left element is less than or equal to pivot
        while (left <= right && a[left] <= pivot)
        {
            left++;
        }

        // Decrement right index while the right element is greater than pivot
        while (left <= right && a[right] > pivot)
        {
            right--;
        }

        // Swap left and right elements if they are in the wrong order
        if (left < right)
        {
            swap(a, left, right);
        }
    }

    // Final swap to place pivot in the correct position
    swap(a, start, right);

    return right;
}
void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        // Partition the array and get the pivot index
        int pivot_index = partition(a, start, end);
        printf("%d \n",pivot_index);

        // Recursively sort the elements before and after the pivot
        quickSort(a, start, pivot_index - 1);
        quickSort(a, pivot_index + 1, end);
    }
}

int main()
{
    int a[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
//time complexity is O(n^2)
// average case: O(nlogn)
