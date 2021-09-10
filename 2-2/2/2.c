#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define _DEBUG

int main(void)
{
    srand((unsigned int)time(NULL));
    int randomDigit[3] = { 0 };

    for(size_t i = 0; i < 3; i++)
    {
        while(1)
        {
            int breakCond = 1;
            int digit = rand() % 9 + 1;

            for(size_t j = 0; j < i && breakCond; j++)
            {
                if(digit == randomDigit[j])
                {
                    breakCond = 0;
                    break;
                }
            }

            if(breakCond)
            {
                randomDigit[i] = digit;
                break;
            }
        }
    }

#ifdef _DEBUG
    printf("[DEBUG]");
    for(size_t i = 0; i < 3; i++)
    {
        printf(" %d", randomDigit[i]);
    }
    printf("\n");
#endif

    while(1)
    {
        int num, rtnval;
        int expectedDigit[3];
        int strike = 0, ball = 0;

        printf("jon (Three different numbers from 1 to 9) : ");
        rtnval = scanf("%d", &num);

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

        if(num < 123 || num > 987)
        {
            continue;
        }

        expectedDigit[0] = num / 100 % 10;
        expectedDigit[1] = num / 10 % 10;
        expectedDigit[2] = num % 10;

        if (expectedDigit[0] == 0 || expectedDigit[1] == 0 || expectedDigit[2] == 0)
        {
            continue;
        }

        if(expectedDigit[0] == expectedDigit[1] || expectedDigit[0] == expectedDigit[2] || expectedDigit[1] == expectedDigit[2])
        {
            continue;
        }

        printf("%d %d %d\n", expectedDigit[0], expectedDigit[1], expectedDigit[2]);

        for(size_t i = 0; i < 3; i++)
        {
            for(size_t j = 0; j < 3; j++)
            {
                if(expectedDigit[i] == randomDigit[j])
                {
                    if(i == j)
                    {
                        strike++;
                    }
                    else
                    {
                        ball++;
                    }
                }
            }
        }

        printf("%0d strike %0d ball\n", strike, ball);

        if(strike == 3)
        {
            break;
        }
    }

    printf("Right!\n");

    return 0;
}