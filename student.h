#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};

extern struct student *head;

void read_string(char *str);
int read_int(void);
float read_float(void);

void add_student(void);
void delete_student(void);
void show_students(void);
void modify_student(void);

void save_students(void);
void load_students(void);

void sort_students(void);
void delete_all(void);
void reverse_list(void);

#endif
