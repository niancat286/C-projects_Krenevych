#ifndef C_PROJECTS_KRENEVYCH_T10_6E_H
#define C_PROJECTS_KRENEVYCH_T10_6E_H

typedef struct {
    char type[20];      // тип платежу (шифр, автор, назва)
    char purpose[50];   // призначення платежу
    double amount;      // сума
} Payment;


extern void input_payment(Payment *p);
extern void output_payment(const Payment *p);


#endif //C_PROJECTS_KRENEVYCH_T10_6E_H