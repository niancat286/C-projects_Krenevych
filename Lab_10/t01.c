#include "date.h"
#include "chess.h"
#include "rectangle.h"
#include "polynome.h"

void test_date(){
    Date d;
    InputDate(&d);
    OutputDate(&d);
}

void test_chess() {
    struct Field f = input_field();
    output_field(f);
}

void test_rectangle() {
    struct Rectangle r;
    input_rectangle(&r);
    output_rectangle(&r);
}

void test_polynome() {
    struct Polynome p;
    input_polynome(&p);
    output_polynome(&p);
    free_polynome(&p);
}

void task2() {
    struct Field from, to;

    printf("Enter start field:\n");
    from = input_field();

    getchar();

    printf("Enter target field:\n");
    to = input_field();

    printf("From ");
    output_field(from);
    printf(" to ");
    output_field(to);

    if (queen_can_move(from, to))
        printf(" — YES, the queen can move there.\n");
    else
        printf(" — NO, the queen cannot move there.\n");
}

void task3() {
    Date today;

    if (!InputDate(&today)) {
        printf("Invalid input.\n");
        return;
    }

    printf("Today is ");
    OutputDate(&today);
    printf(" — %s\n", DayOfWeek(&today));

    Date tomorrow = Tomorrow(today);
    printf("Tomorrow will be ");
    OutputDate(&tomorrow);
    printf(" — %s\n", DayOfWeek(&tomorrow));
}

int main(){
    int index = 6;
    if (index == 1) {
        test_date();
    }
    if (index == 2) {
        test_chess();
    }
    if (index == 3) {
        test_rectangle();
    }
    if (index == 4) {
        test_polynome();
    }
    if (index == 5) {
        task2();
    }
    if (index == 6) {
        task3();
    }
}