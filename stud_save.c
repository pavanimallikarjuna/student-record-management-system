#include "student.h"

void save_students(void)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "wb");

    if(fp == NULL)
    {
        printf("File cannot be opened.\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fwrite(&temp->rollno,
               sizeof(int),
               1,
               fp);

        fwrite(temp->name,
               sizeof(temp->name),
               1,
               fp);

        fwrite(&temp->percentage,
               sizeof(float),
               1,
               fp);

        temp = temp->next;
    }

    fclose(fp);

    printf("Records saved successfully.\n");
}


void load_students(void)
{
    FILE *fp;

    struct student *new;
    struct student *temp;

    fp = fopen("student.dat", "rb");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        new = (struct student *)malloc(sizeof(struct student));

        if(new == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(fp);
            return;
        }

        if(fread(&new->rollno,
                 sizeof(int),
                 1,
                 fp) != 1)
        {
            free(new);
            break;
        }

        fread(new->name,
              sizeof(new->name),
              1,
              fp);

        fread(&new->percentage,
              sizeof(float),
              1,
              fp);

        new->next = NULL;

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
    }

    fclose(fp);
}
