# Student Record Management System

A menu-driven C project using a singly linked list, dynamic memory allocation and file handling.

## Features
- Add, delete, display and modify student records
- Sort records by name and percentage
- Save and load records using `student.dat`
- Reverse and delete all records

## Modules
- `student.h` – Structure and function declarations
- `stud_main.c` – Main menu
- `stud_add.c` – Add records
- `stud_del.c` – Delete records
- `stud_show.c` – Display records
- `stud_mod.c` – Modify records
- `stud_save.c` – Save/load records
- `stud_ops.c` – Sort, reverse and delete all

## Compilation

```bash
gcc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_ops.c -o student
