#include <stdio.h>


char *strcpy(char *dst, const char *src)
{
    // char *s = dst;
    while(*dst++ = *src++)
        ;
    return dst;
}

int main()
{
    char array[] = {"hello"};

    char newarrayp[] = {'\0'};

    printf("len : %ld\n", sizeof(newarrayp));

    strcpy(newarrayp, array);

    for(int idx = 0; idx < 6; idx++)
    {
        printf("%c", newarrayp[idx]);
    }
    printf("\n");



    return 0;
}