#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    int dog_age = age * 7;
    printf("You are %d years old. If you were a dog, you would be %d years old.\n", age, dog_age);
}