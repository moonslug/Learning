#include <stdio.h>
#include <limits.h>

#define SIZE 5  // preprocessor directive. Complier doens't know the var SIZE only sees 5

// const int SIZE = 5; // compiler statement. Complier will go around replace SIZE with 5 



void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d: %d", i, arr[i]);
    }
    printf("\n");
}

void inputArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Enter number %d:", i);
        scanf("%d", &arr[i]);
    }
}

void doubleArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = arr[i] * 2;
    }
}

int findMax(int arr[], int length)
{
    int tmpMax = INT_MIN;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > tmpMax)
        {
            tmpMax = arr[i];
        }
    }
    return tmpMax;
}

int main()
{
    int nums[SIZE];

    inputArray(nums, SIZE);
    printArray(nums, SIZE);

    int max = findMax(nums, SIZE);
    printf("Max num of array is: %d\n", max);

    doubleArray(nums, SIZE);
    printArray(nums, SIZE);
    return 0;
}