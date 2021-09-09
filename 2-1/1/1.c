#include <stdio.h>

int main(void)
{
    char name[32];
    char major[32];
    int studentID;

    printf("name: ");
    scanf("%s", name);

    printf("major: ");
    scanf("%s", major);

    printf("studentID: ");
    scanf("%d", &studentID);

    printf("Hello. My name is %s.\nMy major is %s.\nMy student ID is %010d.\n", name, major, studentID);

    return 0;
}