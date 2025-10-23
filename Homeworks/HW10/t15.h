#ifndef C_PROJECTS_KRENEVYCH_T15_H
#define C_PROJECTS_KRENEVYCH_T15_H

#define MAX_NAME 30
#define MAX_STUDENTS 100

typedef struct {
    char surname[MAX_NAME];
    char name[MAX_NAME];
    char patronymic[MAX_NAME];
    char gender; // 'M' або 'F'
    int age;
    int course;
} Student;


extern void input_students(Student *arr, int n);
extern void output_students(const Student *arr, int n);
extern void find_most_popular(const Student *arr, int n);
extern void find_popular_age(const Student *arr, int n);

#endif //C_PROJECTS_KRENEVYCH_T15_H