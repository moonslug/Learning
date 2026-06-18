#include <stdio.h>

#define SIZE 5  // preprocessor directive. Complier doens't know the var SIZE only sees 5

// const int SIZE = 5; // compiler statement. Complier will go around replace SIZE with 5 


int main()
{
    int nums[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i);
        scanf("%d", &nums[i]);
    }
    return 0;
}