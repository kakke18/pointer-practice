#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

typedef enum {
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_RED,
    COLOR_MAGENTA,
    COLOR_GREEN,
    COLOR_CYAN,
    COLOR_YELLOW,
    COLOR_WHITE
} Color;

typedef enum {
    FILE_NONE,      // 塗りつぶさない
    FILE_SOLID,     // ベタ塗り
    FILE_HATCH,     // 斜線によるハッチング
    FILE_CROSSHATCH // 交差したハッチング
} FillPattern;

typedef enum {
    POLYLINE_PRIMITIVE,
    RECTANGLE_PRIMITIVE,
    CIRCLE_PRIMITIVE
} PrimitiveType;

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int npoints;
    Point *point;
} Polyline;

typedef struct {
    Point minPoint;
    Point maxPoint;
} Rectangle;

typedef struct {
    Point center;
    double radius;
} Circle;

typedef struct {
    Color pen_color;
    FillPattern fill_pattern;
    Color fill_color;
    PrimitiveType type;
    union {
        Polyline polyLine;
        Rectangle rectangle;
        Circle circle;
    } u;
} Primitive;

typedef struct Shape_tag Shape;

typedef enum {
    PRIMITIVE_TYPE,
    GROUP_TYPE
} ShapeType;

struct Shape_tag {
    ShapeType type;
    union {
        Primitive primitive;
        Group gourp;
    } u;
    struct Shape_tag *prev;
    struct Shape_tag *next;
};

#endif /* f SHAPE_H_INCLUDED */