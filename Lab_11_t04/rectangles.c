#include "rectangles.h"

#include <stdlib.h>
#include <math.h>

double area(Rectangle r) {
    return fabs(r.x2 - r.x1) * fabs(r.y1 - r.y2);
}

int find_max_area(const char *filename, double *maxArea) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1;

    Rectangle r;
    int bestID = -1;
    *maxArea = -1.0;

    while (fscanf(f, "%d %lf %lf %lf %lf", &r.id, &r.x1, &r.y1, &r.x2, &r.y2) == 5) {
        double S = area(r);
        if (S > *maxArea) {
            *maxArea = S;
            bestID = r.id;
        }
    }

    fclose(f);
    return bestID;
}

int delete_rectangle(const char *filename, int id) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1;

    FILE *tmp = fopen("tmp.txt", "w");
    if (!tmp) return -2;

    Rectangle r;
    int deleted = 0;

    while (fscanf(f, "%d %lf %lf %lf %lf", &r.id, &r.x1, &r.y1, &r.x2, &r.y2) == 5) {
        if (r.id != id)
            fprintf(tmp, "%d %.2lf %.2lf %.2lf %.2lf\n", r.id, r.x1, r.y1, r.x2, r.y2);
        else
            deleted = 1;
    }

    fclose(f);
    fclose(tmp);

    remove(filename);
    rename("tmp.txt", filename);

    return deleted;
}


int replace_by_order(const char *filename, int order, Rectangle newRect) {
    FILE *f = fopen(filename, "r");
    if (!f) return -1;

    FILE *tmp = fopen("tmp.txt", "w");
    if (!tmp) return -2;

    Rectangle r;
    int current = 1;
    int replaced = 0;

    while (fscanf(f, "%d %lf %lf %lf %lf", &r.id, &r.x1, &r.y1, &r.x2, &r.y2) == 5) {
        if (current == order) {
            fprintf(tmp, "%d %.2lf %.2lf %.2lf %.2lf\n",
                    newRect.id, newRect.x1, newRect.y1, newRect.x2, newRect.y2);
            replaced = 1;
        } else {
            fprintf(tmp, "%d %.2lf %.2lf %.2lf %.2lf\n",
                    r.id, r.x1, r.y1, r.x2, r.y2);
        }
        current++;
    }

    fclose(f);
    fclose(tmp);

    remove(filename);
    rename("tmp.txt", filename);

    return replaced;
}

