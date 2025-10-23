#include "date.h"


int DaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // високосний рік
            return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
        default:
            return 0;
    }
}

int IsValidDate(const Date* date) {
    if (date->year < 1) return 0;
    if (date->month < 1 || date->month > 12) return 0;

    int dim = DaysInMonth(date->month, date->year);
    if (dim == 0) return 0;

    if (date->day < 1 || date->day > dim) return 0;

    return 1;
}

int InputDate(Date* date) {
    printf("Please input day, month, year (format: dd/mm/yyyy):\n");
    int result = scanf("%d/%d/%d", &date->day, &date->month, &date->year);
    if (result != 3) {
        printf("Invalid format!\n");
        return 0;
    }

    if (!IsValidDate(date)) {
        printf("Invalid date entered!\n");
        return 0;
    }

    return 1; // правильна дата
}

void OutputDate(const Date* date){
    printf("%02d/%02d/%4d", date->day, date->month, date->year);
}

Date Tomorrow(Date date) {
    date.day++;
    if (date.day > DaysInMonth(date.month, date.year)) {
        date.day = 1;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

const char* DayOfWeek(const Date* date) { //наскільки мені відомо це алгоритм Зеллера
    static const char* days[] = {
        "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
    };

    int d = date->day;
    int m = date->month;
    int y = date->year;

    if (m < 3) {
        m += 12;
        y--;
    }

    int K = y % 100;
    int J = y / 100;

    int h = (d + 13*(m + 1)/5 + K + K/4 + J/4 + 5*J) % 7;

    return days[h];
}

