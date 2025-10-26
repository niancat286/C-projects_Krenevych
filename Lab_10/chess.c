#include "chess.h"
#include <stdlib.h>

struct Field input_field() {
    struct Field f;
    printf("Please enter the Symbol:\n");
    scanf("%c", &f.hor);
    printf("Please enter the Number:\n");
    scanf("%d", &f.vert);

    return f;
}


void output_field(struct Field f) {
    printf("%c%d", f.hor, f.vert);
}

_Bool queen_can_move(struct Field from, struct Field to) {
    if (from.hor == to.hor || from.vert == to.vert)
        return 1;

    if (abs(from.hor - to.hor) == abs(from.vert - to.vert))
        return 1;

    return 0;
}
