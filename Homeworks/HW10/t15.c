#include <stdio.h>
#include <string.h>
#include "t15.h"

void input_students(Student *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nСтудент %d:\n", i + 1);
        printf("Прізвище: ");
        scanf("%s", arr[i].surname);
        printf("Ім'я: ");
        scanf("%s", arr[i].name);
        printf("По батькові: ");
        scanf("%s", arr[i].patronymic);
        printf("Стать (M/F): ");
        scanf(" %c", &arr[i].gender);
        printf("Вік: ");
        scanf("%d", &arr[i].age);
        printf("Курс: ");
        scanf("%d", &arr[i].course);
    }
}


void output_students(const Student *arr, int n) {
    printf("\nСписок студентів:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %s, стать: %c, вік: %d, курс: %d\n",
               arr[i].surname, arr[i].name, arr[i].patronymic,
               arr[i].gender, arr[i].age, arr[i].course);
    }
}

void find_most_popular(const Student *arr, int n) {
    char maleNames[MAX_STUDENTS][MAX_NAME];
    char femaleNames[MAX_STUDENTS][MAX_NAME];
    int maleCount[MAX_STUDENTS] = {0};
    int femaleCount[MAX_STUDENTS] = {0};
    int mSize = 0, fSize = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        if (arr[i].gender == 'M') {
            for (int j = 0; j < mSize; j++) {
                if (strcmp(arr[i].name, maleNames[j]) == 0) {
                    maleCount[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(maleNames[mSize], arr[i].name);
                maleCount[mSize++] = 1;
            }
        } else if (arr[i].gender == 'F') {
            for (int j = 0; j < fSize; j++) {
                if (strcmp(arr[i].name, femaleNames[j]) == 0) {
                    femaleCount[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(femaleNames[fSize], arr[i].name);
                femaleCount[fSize++] = 1;
            }
        }
    }

    int maxM = 0, maxF = 0;
    for (int i = 0; i < mSize; i++)
        if (maleCount[i] > maleCount[maxM]) maxM = i;
    for (int i = 0; i < fSize; i++)
        if (femaleCount[i] > femaleCount[maxF]) maxF = i;

    printf("\nНайпоширеніше чоловіче ім'я: %s\n", mSize ? maleNames[maxM] : "немає");
    printf("Найпоширеніше жіноче ім'я: %s\n", fSize ? femaleNames[maxF] : "немає");
}


void find_popular_age(const Student *arr, int n) {
    int ages[MAX_STUDENTS];
    int counts[MAX_STUDENTS] = {0};
    int size = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i].age == ages[j]) {
                counts[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            ages[size] = arr[i].age;
            counts[size++] = 1;
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < size; i++)
        if (counts[i] > counts[maxIndex]) maxIndex = i;

    int commonAge = ages[maxIndex];
    printf("\nНайпоширеніший вік: %d\n", commonAge);
    printf("Студенти цього віку:\n");

    for (int i = 0; i < n; i++) {
        if (arr[i].age == commonAge) {
            printf("%s %c.%c.\n",
                   arr[i].surname,
                   arr[i].name[0],
                   arr[i].patronymic[0]);
        }
    }
}

