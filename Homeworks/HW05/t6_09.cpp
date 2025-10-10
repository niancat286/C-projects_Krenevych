#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t m;
    int highest_one = -1;   // номер старшого != 0 біта
    int first_zero_after = -1; // 1-ий 0 після нього

    printf("m= ");
    scanf("%u", &m);

    // пошук старшого !=0 біта
    for (int i = 31; i >= 0; i--) {
        if ((m >> i) & 1) {
            highest_one = i;
            break;
        }
    }

    if (highest_one == -1) {
        printf("У числа немає ненульових бітів (m = 0)\n");
        return 0;
    }

    // 1-ий 0 біт після нього
    for (int i = highest_one - 1; i >= 0; i--) {
        if (((m >> i) & 1) == 0) {
            first_zero_after = i;
            break;
        }
    }

    printf("Номер найстаршого ненульового біта: %d\n", highest_one);
    if (first_zero_after != -1)
        printf("Номер найстаршого нульового біта після нього: %d\n", first_zero_after);
    else
        printf("Нульових бітів після нього немає\n");

    return 0;
}
