#include <stdio.h>
#include <string.h>

// void printfarray(char array[])
// {
//     int len = sizeof(array) / sizeof(array[0]);
//     printf("len4 : %d\n", len);


//     for(int idx = 0; idx < len; idx++)
//     {
//         printf("idx: %d, value : %c\n", idx, array[idx]);
//     }
// }

void printfArray(const char *array)
{
    int idx = 0;
    while(array[idx] != '\0')
    {
        printf("%c", array[idx]);
        idx++;
    }
    printf("\n");
}




int main()
{
    char array[] = "hello sajf";

    int len = sizeof(array) / sizeof(array[0]);



#if 1
    printfArray(array); 
#else

    for(int idx = 0; idx < len; idx++)
    {
        printf("idx: %d, value : %c\n", idx, array[idx]);
    }

#endif

    return 0;
}