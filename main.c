#include <stdio.h>
int binary_search(int arr[], int target, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 64, 76, 88};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    int idx = binary_search(arr, 50, length);
    if (idx != -1)
    {
        printf("found at index %d", idx);
    }
    return 0;
}