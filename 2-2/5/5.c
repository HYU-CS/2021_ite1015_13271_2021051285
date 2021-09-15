#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student
{
    int mid_score;
    int final_score;
    char grade;
};

int main(void)
{
    int N;
    int total = 0, average;

    struct Student *students = NULL;

    srand((unsigned int)time(NULL));

    while(1)
    {
        int rtnval;
        printf("How many students : ");
        rtnval = scanf("%d", &N);

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

        if(N >= 5 && N <= 30)
        {
            break;
        }
        printf("N must follow 5 <= n <= 30. Try again.\n");
    }

    students = (struct Student *)malloc(sizeof(struct Student) * N);
    
    if(students == NULL)
    {
        printf("Memory Allocation Failed. Out of memory. Exiting...\n");

        return -1;
    }

    for(int i = 0; i < N; i++)
    {
        total += students[i].mid_score = rand() % 11 * 10;
        total += students[i].final_score = rand() % 11 * 10;
    }

    average = total / N;

    for(int i = 0; i < N; i++)
    {
        students[i].grade = (students[i].mid_score + students[i].final_score >= average) ? 'P' : 'F';
    }

    for(int i = 0; i < N; i++)
    {
        printf("Student %d's grade is %c\n", i, students[i].grade);
    }

    free(students);

    return 0;
}