#include <stdio.h>
#include "t10_6e.h"


void input_payment(Payment *p) {
    printf("Введіть тип платежу: ");
    scanf("%19s", p->type);
    printf("Введіть призначення: ");
    scanf(" %[^\n]", p->purpose); // зчитування рядка з пробілами
    printf("Введіть суму: ");
    scanf("%lf", &p->amount);
}

void output_payment(const Payment *p) {
    printf("\nІнформація про платіж:\n");
    printf("Тип: %s\n", p->type);
    printf("Призначення: %s\n", p->purpose);
    printf("Сума: %.2lf\n", p->amount);
}

