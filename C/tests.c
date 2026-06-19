#include <stdio.h>

int main()
{
    printf("enter name: ");
    char myName[10];
    //scanf("%10s", myName);  // do not use scanf. no protection at the end other than hard code
    //printf("The name is %s\n", myName);
    
    // recommended
    fgets(myName, 10, stdin);

    // print each ascii to investigate 
    for (int i = 0; i < 20; i++){
        printf("%d\n", myName[i]);
    }

    // replace line break or null terminator with null terminator
    int j = 0;
    while (myName[j] != '\n' && myName[j] != '\0')
        j++;
    myName[j] = '\0';

    printf("The name is %s!\n", myName);

    return 0;
}