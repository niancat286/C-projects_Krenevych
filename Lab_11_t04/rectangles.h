#ifndef C_PROJECTS_KRENEVYCH_RECTANGLES_H
#define C_PROJECTS_KRENEVYCH_RECTANGLES_H

#include <stdio.h>

typedef struct {
    int id;
    double x1, y1; // top-left
    double x2, y2; // bottom-right
} Rectangle;

int find_max_area(const char *filename, double *maxArea);
int delete_rectangle(const char *filename, int id);
int replace_by_order(const char *filename, int order, Rectangle newRect);



#endif //C_PROJECTS_KRENEVYCH_RECTANGLES_H