#include <stdio.h>

int myStrCmp(const char *lhs, const char *rhs)
{
    unsigned int i = 0;

    while(lhs[i] != '\0' && rhs[i] != '\0' && lhs[i] == rhs[i])
    {
        i++;
    }

    return lhs[i] - rhs[i];
}

int main(void)
{
    char str1[16];
    char str2[16];
    int cmp;

    printf("First string: ");
    scanf("%s", str1);

    printf("Second string: ");
    scanf("%s", str2);

    cmp = myStrCmp(str1, str2);

    if(cmp == 0)
    {
        printf("Same string\n");
    }
    else if(cmp > 0)
    {
        printf("First string is larger.\n");
    }
    else
    {
        printf("Second string is larger.\n");
    }

    return 0;
}