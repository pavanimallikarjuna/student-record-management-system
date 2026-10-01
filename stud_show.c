#include "student.h"

void show_students(void)
{
    struct student *temp;

    if(head == NULL)
    {
        printf("\nNo student records available.\n");
        return;
    }

    temp = head;

    printf("\n");
    printf("-------------------------------------------------\n");
    printf("Roll No.\tName\t\tPercentage\n");
    printf("-------------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%d\t\t%-15s %.2f\n",
               temp->rollno,
               temp->name,
               temp->percentage);

        temp = temp->next;
    }

    printf("-------------------------------------------------\n");
}
