#include "student.h"

void add_student(void)
{
    struct student *new;
    struct student *temp;

    int roll = 1;
    int found;

    new = (struct student *)malloc(sizeof(struct student));

    if(new == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    /* Find the smallest unused roll number */

    while(1)
    {
        found = 0;

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                found = 1;
                break;
            }

            temp = temp->next;
        }

        if(found == 0)
            break;

        roll++;
    }

    new->rollno = roll;

    printf("\nAssigned Roll Number : %d\n", new->rollno);

    printf("Enter student name : ");
    read_string(new->name);

    while(1)
    {
        printf("Enter percentage : ");
        new->percentage = read_float();

        if(new->percentage >= 0 &&
           new->percentage <= 100)
        {
            break;
        }

        printf("Percentage must be between 0 and 100.\n");
    }

    new->next = NULL;

    /* Insert node into the list */

    if(head == NULL)
    {
        head = new;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new;
    }

    printf("Student added successfully.\n");
}
