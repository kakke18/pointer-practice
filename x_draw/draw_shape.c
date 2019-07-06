#include <stdio.h>
#include <assert.h>
#include "shape.h"

void draw_polyline(Shape *shape);
void draw_rectangle(Shape *shape);
void draw_circle(Shape *shape);

void draw_primitive(Shape *shape) {
    switch (shape->u.primitive.type) {
        case POLYLINE_PRIMITIBE:
            draw_polyline(shape);
            break;
        case RECTANGLE_PRIMITIBE:
            draw_rectangle(shape);
            break;
        case CIRCLE_PRIMITIBE:
            draw_circle(shape);
            break;
        default:
            assert(0);
    }
}

void draw_all_shape(Shape *head)
{
    Shape *pos;

    for (pos = head; pos != NULL; pos = pos->next;) {
        switch (pos->type) {
            case POLYLINE_PRIMITIBE:
                draw_polyline(pos);
                break;
            case RECTANGLE_PRIMITIBE:
                draw_rectangle(pos);
                break;
            case CIRCLE_PRIMITIBE:
                draw_circle(pos);
                break;
            default:
                assert(0);
        }
    }
}