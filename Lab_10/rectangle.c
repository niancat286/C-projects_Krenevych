#include "rectangle.h"


int input_rectangle(struct Rectangle * rect) {
    struct Vertex a,b;
    printf("input vertex A: ");
    scanf("%f %f",&a.x, &a.y);

    printf("input vertex B: ");
    scanf("%f %f",&b.x, &b.y);

    rect->A = a;
    rect->C = b;
    return 0;
}

void output_rectangle(const struct Rectangle * rect) {
    printf("(%f,%f)-(%f,%f)",rect->A.x,rect->A.y, rect->C.x,rect->C.y);
}