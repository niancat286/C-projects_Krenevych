#ifndef C_PROJECTS_KRENEVYCH_RECTANGLE_H
#define C_PROJECTS_KRENEVYCH_RECTANGLE_H

#include <stdio.h>

typedef struct Vertex{
    float x;
    float y;
};


typedef struct Rectangle{
    struct Vertex A;
    struct Vertex C;
};

extern int input_rectangle(struct Rectangle * rect);
extern void output_rectangle(const struct Rectangle * rect);

#endif //C_PROJECTS_KRENEVYCH_RECTANGLE_H