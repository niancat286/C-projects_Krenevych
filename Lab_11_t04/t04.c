#include <stdio.h>
#include "rectangles.h"

int main() {
    const char *file = "rectangles.txt";
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Find rectangle with max area\n");
        printf("2. Delete rectangle by ID\n");
        printf("3. Replace rectangle by order\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            double maxArea;
            int id = find_max_area(file, &maxArea);
            if (id >= 0)
                printf("Rectangle with max area: ID=%d, Area=%.2lf\n", id, maxArea);
            else
                printf("File error\n");
        }

        else if (choice == 2) {
            int id;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            if (delete_rectangle(file, id))
                printf("Deleted\n");
            else
                printf("Not found\n");
        }

        else if (choice == 3) {
            int order;
            Rectangle r;
            printf("Enter order number: ");
            scanf("%d", &order);

            printf("Enter new rectangle (ID x1 y1 x2 y2): ");
            scanf("%d %lf %lf %lf %lf", &r.id, &r.x1, &r.y1, &r.x2, &r.y2);

            if (replace_by_order(file, order, r))
                printf("Replaced\n");
            else
                printf("Order not found\n");
        }

    } while (choice != 0);

    return 0;
}