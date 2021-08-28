#include <stdio.h>

#define EQUAL_POINT(p1, p2)  ((p1)->x == (p2)->x) && ((p1)->y == (p2)->y);

typedef struct _point {
    int x;
    int y;
} Point;

typedef enum{FALSE, TRUE} boolean;

boolean is_Adjacent(Point *u, Point *v)
{
    int x_diff = u->x - v->x;
    int y_diff = u->y - v->y;
    
}

int f(Point *u, Point *v)
{

}