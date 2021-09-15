#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Initialization
    int num_1, num_2;
    int gcd;

    size_t num_1_divisor_size = 0;
    size_t num_2_divisor_size = 0;
    size_t gcd_divisor_size = 0;

    int *num_1_divisor = NULL;
    int *num_2_divisor = NULL;
    int *gcd_divisor = NULL;


    //Input
    while(1)
    {
        int rtnval;
        printf("num_1 integer : ");
        rtnval = scanf("%d", &num_1);

        if(rtnval == 0 || rtnval == EOF)
        {
            char ch;
            do
            {
                ch = getchar();
            }
            while (ch != '\n' && ch != EOF);

            printf("Only digits(0-9) are allowed.\n");
            
            continue;
        }

        if(num_1 > 0 && num_1 <= 50)
        {
            break;
        }
        printf("num_1 must follow 0 < num_1 <= 50. Try again.\n");
    }

    while(1)
    {
        int rtnval;
        printf("num_2 integer : ");
        rtnval = scanf("%d", &num_2);

        if(rtnval == 0 || rtnval == EOF)
        {
            char ch;
            do
            {
                ch = getchar();
            }
            while (ch != '\n' && ch != EOF);

            printf("Only digits(0-9) are allowed.\n");

            continue;
        }

        if(num_2 > 0 && num_2 <= 50)
        {
            break;
        }
        printf("num_2 must follow 0 < num_2 <= 50. Try again.\n");
    }


    //Processing
    for(int i = 1; i <= num_1; i++)
    {
        if(num_1 % i == 0)
        {
            int *temp = (int *)malloc(sizeof(int) * (num_1_divisor_size + 1));

            if(temp == NULL)
            {
                printf("Memory Allocation Failed. Out of memory. Exiting...\n");

                return -1;
            }

            for(size_t index = 0; index < num_1_divisor_size; index++)
            {
                temp[index] = num_1_divisor[index];
            }

            temp[num_1_divisor_size++] = i;

            free(num_1_divisor);
            num_1_divisor = temp;
        }
    }

    for(int i = 1; i <= num_2; i++)
    {
        if(num_2 % i == 0)
        {
            int *temp = (int *)malloc(sizeof(int) * (num_2_divisor_size + 1));

            if(temp == NULL)
            {
                printf("Memory Allocation Failed. Out of memory. Exiting...\n");

                return -1;
            }

            for(size_t index = 0; index < num_2_divisor_size; index++)
            {
                temp[index] = num_2_divisor[index];
            }

            temp[num_2_divisor_size++] = i;

            free(num_2_divisor);
            num_2_divisor = temp;
        }
    }

    for(int i = 1; i <= num_1 && i <= num_2; i++)
    {
        if(num_1 % i == 0 && num_2 % i == 0)
        {
            int *temp = (int *)malloc(sizeof(int) * (gcd_divisor_size + 1));

            if(temp == NULL)
            {
                printf("Memory Allocation Failed. Out of memory. Exiting...\n");

                return -1;
            }

            for(size_t index = 0; index < gcd_divisor_size; index++)
            {
                temp[index] = gcd_divisor[index];
            }

            temp[gcd_divisor_size++] = i;

            free(gcd_divisor);
            gcd_divisor = temp;
        }
    }


    //Output
    printf("num_1 integer divisor :");
    for(size_t i = 0; i < num_1_divisor_size; i++)
    {
        printf(" %d", num_1_divisor[i]);
    }
    printf("\n");

    printf("num_2 integer divisor :");
    for(size_t i = 0; i < num_2_divisor_size; i++)
    {
        printf(" %d", num_2_divisor[i]);
    }
    printf("\n");

    printf("Total common divisor : %zu\n", gcd_divisor_size);

    free(num_1_divisor);
    free(num_2_divisor);
    free(gcd_divisor);

    return 0;
}