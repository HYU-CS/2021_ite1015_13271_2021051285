#include <stdio.h>
#include <stdlib.h>

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(void)
{
    int n;
    int nSquare;
    int **arr;
    int padding;
    size_t y, x, direction;

    while(1)
    {
        int rtnval;
        printf("the size of square : ");
        rtnval = scanf("%d", &n);

        if(rtnval == 0 || rtnval == EOF)
        {
            char ch;
            do
            {
                ch = getchar();
            } while (ch != '\n' && ch != EOF);

            printf("Only digits(0-9) are allowed.");
            
            continue;
        }

        if(n <= 0)
        {
            continue;
        }

        break;
    }

    arr = (int **)malloc(sizeof(int *) * n);
    if(arr == NULL)
    {
        printf("Memory Allocation Failed. Out of memory. Exiting...");

        return -1;
    }
    for(size_t i = 0; i < n; i++)
    {
        arr[i] = (int *)calloc((size_t)n, sizeof(int));

        if(arr[i] == NULL)
        {
            printf("Memory Allocation Failed. Out of memory. Exiting...");

            return -1;
        }
    }

    y = 0; x = 0;
    direction = 0;
    nSquare = n * n;
    for(int i = 1; i <= nSquare; i++)
    {
        arr[y][x] = i;

        int nY = y + dy[direction];
        int nX = x + dx[direction];

        if(nY < 0 || nY >= n || nX < 0 || nX >= n || arr[nY][nX] != 0)
        {
            direction = (direction + 1) % 4;

            nY = y + dy[direction];
            nX = x + dx[direction];
        }

        y = nY;
        x = nX;
    }

    padding = 1;
    while(nSquare /= 10)
    {
        padding++;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%*d ", padding, arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}