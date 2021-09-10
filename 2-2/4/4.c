#include <stdio.h>

void combination(char *arr, unsigned int digit, int count, int n, int k)
{
    if(count == k)
    {
        while(*arr != 0)
        {
            printf("%d ", *(arr++));
        }
        printf("\n");

        return;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(digit & (1 << i))
            {
                arr[count] = 1 + i;
                arr[count + 1] = 0;

                combination(arr, (digit >> i + 1) << i + 1, count + 1, n, k);
            }
        }
    }
}

int main(void)
{
    unsigned int digit = 0;
    int n = 0, k = 0;

    char arr[256];

    while(1)
    {
        int rtnval;
        printf("Enter n : ");
        rtnval = scanf("%d", &n);

        if(rtnval == 0 || rtnval == EOF)
        {
            char ch;
            do
            {
                ch = getchar();
            }
            while (ch != '\n' && ch != EOF);
            
            continue;
        }

        if(n >= 4 && n <= 10)
        {
            break;
        }
        printf("n must follow 4 <= n <= 10. Try again.\n");
    }

    while(1)
    {
        int rtnval;
        printf("Enter k : ");
        rtnval = scanf("%d", &k);

        if(rtnval == 0 || rtnval == EOF)
        {
            char ch;
            do
            {
                ch = getchar();
            }
            while (ch != '\n' && ch != EOF);

            continue;
        }

        if(k >= 1 && k <= n)
        {
            break;
        }
        printf("k must follow 1 <= k <= %d. Try again.\n", n);
    }

    {
        unsigned int temp = 1;
        for(int i = 0; i < n; i++)
        {
            temp *= 2;
        }
        digit = temp - 1;
    }

    combination(arr, digit, 0, n, k);

    return 0;
}