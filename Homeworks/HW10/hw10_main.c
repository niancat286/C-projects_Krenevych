#include <stdio.h>
#include "t10_6e.h"
#include "t15.h"


void test_payment() {
    Payment p;
    input_payment(&p);
    output_payment(&p);
}

void test_students() {
    int n;
    Student students[MAX_STUDENTS];

    printf("Введіть кількість студентів: ");
    scanf("%d", &n);

    input_students(students, n);
    output_students(students, n);

    find_most_popular(students, n);
    find_popular_age(students, n);

}

int main() {
    test_payment();
    test_students();
    return 0;
}