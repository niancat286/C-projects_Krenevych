#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();



int main() {
    int task_index = 7;
    if (task_index == 1) {
        task1();
    }

    if (task_index == 2) {
        task2();
    }

    if (task_index == 3) {
        task3();
    }

    if (task_index == 4) {
        task4();
    }

    if (task_index == 5) {
        task5();
    }

    if (task_index == 6) {
        task6();
    }

    if (task_index == 7) {
        task7();
    }
    return 0;
}


void task1() {
    unsigned char n;
    printf("Enter number n \n");
    scanf("%hhu", &n);
    printf("n=%hhu\n", n);
    if (n<64) {
        unsigned long long m = (1UL << n);
        printf("%llx\n", m);
    }
}


void task2() {
    int k;
    unsigned n, m;
    printf("Enter number n \n");
    scanf("%u", &n);
    printf("Enter number k \n");
    scanf("%d", &k);

    m = n | (1<<k);

    printf("%x or %d \n", m, m);            //x - в 16ова с-ма
}



void task3() {
    int j;
    unsigned long long m, res;

    printf("Enter 64-bit number m: ");
    scanf("%llu", &m);   // %llu для unsigned long long

    printf("Enter bit number j (0..63): ");
    scanf("%d", &j);

    if (j < 0 || j > 63) {
        printf("Error: j must be between 0 and 63\n");
        return;
    }

    // обнулення біта j
    res = m & ~(1ULL << j);

    printf("Result: %llu (dec), %llX (hex)\n", res, res);
}


void task4() {
    uint32_t n, m;
    printf("Enter number n \n");
    scanf("%" SCNu32"\n", &n);

    uint32_t b0 = n & 0xFFU;
    uint32_t b3 = (n >> 24) & 0xFFU;
    uint32_t b1 = (n >> 8) & 0xFFU;
    uint32_t b2 = (n >> 16) & 0xFFU;

    m = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
    printf("%" PRIu32 "\n", m);
}

void task5() {
    uint32_t n, m;
    printf("Enter number n \n");
    scanf("%" SCNx32"", &n);

    int counter = 0;
    int counter_max = 0;

    for (size_t i = 0; i < sizeof(n)*8; i++) {
        if ((1<<i) & n) {
            counter ++;
        }
        else {
            if (counter > counter_max) {
                counter_max = counter;
            }
            counter = 0;
        }
    }
    if (counter > counter_max) {
        counter_max = counter;
    }

    printf("in %" PRIx32 " max num of 1 in line is %d \n", n, counter_max);
}


void task6() {
    uint32_t x, y;

    printf("Введіть x: ");
    scanf("%" SCNu32, &x);

    // 1: чи має x ≥ 2 встановлені біти
    y = !!(x & (x - 1));
    printf("1) y = ((x & (x - 1)) > 0) -> %" PRIu32 "\n", y);

    // 2: ізоляція найменшого встановленого біта
    y = x & (~x + 1);
    printf("2) y = x & (-x) -> %" PRIu32 "\n", y);

    // шістнадцятковий вигляд
    printf("x у шістнадцятковому вигляді: 0x%" PRIx32 "\n", x);
}


void task7() {
    uint32_t value = 0x12345678;
    unsigned char *ptr = (unsigned char *)&value;

    printf("Пам’ять байтами: %02X %02X %02X %02X\n",
           ptr[0], ptr[1], ptr[2], ptr[3]);

    if (ptr[0] == 0x78 && ptr[1] == 0x56 && ptr[2] == 0x34 && ptr[3] == 0x12) {
        printf("Це little-endian архітектура.\n");
    }
    else if (ptr[0] == 0x12 && ptr[1] == 0x34 && ptr[2] == 0x56 && ptr[3] == 0x78) {
        printf("Це big-endian архітектура.\n");
    }
    else {
        printf("Ймовірно, середній (middle-endian) або нестандартний порядок байтів.\n");
    }
    //result -- little-endian, що є правдою для макбуків останніх поколінь
}