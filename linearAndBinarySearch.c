#include <stdio.h>

int linearSearch(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int size, int value)
{
    int low,mid,high;
    low= 0;
    high = size-1; 
    while (low<=high)
    {
        mid = (low + high) / 2;
        if (value > arr[mid])
        {
            low = mid + 1;
        }
        else if (value < arr[mid])
        {
            high = mid - 1;
        }
        else if (value == arr[mid])
        {
            return mid;
        }
    }
            return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 6, 8, 12, 23, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index, value = 8;
    // index = linearSearch(arr,size,value);
    index = binarySearch(arr,size, value);

    if (index == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d \n", index);
    }
    return 0;
}
