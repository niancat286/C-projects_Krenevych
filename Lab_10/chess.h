#ifndef C_PROJECTS_KRENEVYCH_CHESS_H
#define C_PROJECTS_KRENEVYCH_CHESS_H

#include <stdio.h>

struct Field {
    int vert;
    char hor;
};

extern struct Field input_field();
extern void output_field(struct Field f);
extern _Bool queen_can_move(struct Field from, struct Field to);


#endif //C_PROJECTS_KRENEVYCH_CHESS_H