#include <stdio.h>

int main() {
    char a;
    printf("Введіть цифру: ");
    scanf(" %c", &a);

    printf("%c)\n", a);
    printf("- %c - %c - %c\n", a, a, a);
    printf("%c | %c | %c\n", a, a, a);
    printf("- %c - %c - %c\n", a, a, a);

    return 0;
}