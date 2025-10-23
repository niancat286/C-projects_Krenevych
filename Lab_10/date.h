#ifndef C_PROJECTS_KRENEVYCH_DATE_H
#define C_PROJECTS_KRENEVYCH_DATE_H

#include <stdio.h>

typedef
struct Date {
    int day;
    int month;
    int year;
} Date;

extern int IsValidDate(const Date* date);

extern int InputDate(Date* date);
extern void OutputDate(const Date* date);

extern Date Tomorrow(Date date);
extern const char* DayOfWeek(const Date* date);

#endif //C_PROJECTS_KRENEVYCH_DATE_H