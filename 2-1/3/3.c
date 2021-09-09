#include <stdio.h>

int matrix[15][15];

int main(void)
{
    int order = 0;
    int loopCount;
    int y, x;
    int padding;

    printf("Odd num: ");
    scanf("%d", &order);

    if(order % 2 == 0)
    {
        printf("That's even number. Program exits.");
        return 1;
    }

    loopCount = order * order;

    y = 0;
    x = order / 2;

    for(int i = 1; i <= loopCount; i++)
    {
        matrix[y][x] = i;

        if(matrix[((y - 1) % order + order) % order][((x - 1) % order + order) % order])
        {
            y = (y + 1) % order;
        }
        else
        {
            y = ((y - 1) % order + order) % order;
            x = ((x - 1) % order + order) % order;
        }
    }

    padding = 1;
    while(loopCount /= 10)
    {
        padding++;
    }

    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            printf("%*d ", padding, matrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}