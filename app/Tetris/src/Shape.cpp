#include "Shape.h"
#define WIDTH 10
#define HEIGHT 20

Shape::Shape(){}

/*
ת��
*/
void Shape::turn() {
    old.x = offset.x;
    old.y = offset.y;
    if (cur_angle == 3) {
        cur_angle = 0;
        return;
    }
    cur_angle++;
}

/*
move left one step
*/
void Shape::move_left() {
    for (const auto& c : coor[cur_angle]) {
        if (c.x + offset.x <= 0) return;
    }
    old.x = offset.x;
    old.y = offset.y;
    offset.x--;
}

/*
move right
*/
void Shape::move_right() {
    for (const auto& c : coor[cur_angle]) {
        if (c.x + offset.x >= (WIDTH - 1)) return;
    }
    old.x = offset.x;
    old.y = offset.y;
    offset.x++;
}

/*
move down
*/
void Shape::move_down() {
    for (const auto& c : coor[cur_angle]) {
        if (c.x + offset.y >= (HEIGHT - 1)) return;
    }
    old.x = offset.x;
    old.y = offset.y;
    offset.y++;
}

Coor Shape::get_offset() {
    return offset;
}

vector<Coor> Shape::get_vir_coor() {
    return coor[cur_angle];
}

Coor Shape::get_old_offset() {
    return old;
}

vector<Coor> Shape::get_old_shape() {
    return cur_angle == 0 ? coor[3] : coor[cur_angle - 1];
}

vector<Coor> Shape::get_next_shape() {
    return cur_angle == 3 ? coor[0] : coor[cur_angle + 1];
}

/*
����
*/
SquareShape::SquareShape() {
    coor = {
            {
                    Coor(0, 0), Coor(1, 0), Coor(1, 1), Coor(2, 1)
            },
            {
                    Coor(2, 0), Coor(2, 1), Coor(1, 1), Coor(1, 2)
            },
            {
                    Coor(0, 0), Coor(1, 0), Coor(1, 1), Coor(2, 1)
            },
            {
                    Coor(2, 0), Coor(2, 1), Coor(1, 1), Coor(1, 2)
            }
    };
}


/*
Z����-1
*/
ZShape1::ZShape1() {
    coor = {
            {Coor(0, 0), Coor(1, 0), Coor(1, 1), Coor(2, 1)},
            {Coor(2, 0), Coor(2, 1), Coor(1, 1), Coor(1, 2)},
            {Coor(0, 0), Coor(1, 0), Coor(1, 1), Coor(2, 1)},
            {Coor(2, 0), Coor(2, 1), Coor(1, 1), Coor(1, 2)}
    };
}

/*
Z����-2
*/
ZShape2::ZShape2() {
    coor = {
            {Coor(0, 1), Coor(1, 1), Coor(1, 0), Coor(2, 0)},
            {Coor(0, 0), Coor(0, 1), Coor(1, 1), Coor(1, 2)},
            {Coor(0, 1), Coor(1, 1), Coor(1, 0), Coor(2, 0)},
            {Coor(0, 0), Coor(0, 1), Coor(1, 1), Coor(1, 2)}
    };
}

/*
����
*/
IShape::IShape() {
    coor = {
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(3, 0)},
            {Coor(1, 0), Coor(1, 1), Coor(1, 2), Coor(1, 3)},
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(3, 0)},
            {Coor(1, 0), Coor(1, 1), Coor(1, 2), Coor(1, 3)}
    };
}

/*
L����-1
*/
LShape1::LShape1() {
    coor = {
            {Coor(0, 0), Coor(0, 1), Coor(1, 1), Coor(2, 1)},
            {Coor(1, 0), Coor(0, 0), Coor(0, 1), Coor(0, 2)},
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(2, 1)},
            {Coor(0, 2), Coor(1, 2), Coor(1, 1), Coor(1, 0)}
    };
}

/*
L Shape 2
*/
LShape2::LShape2() {
    coor = {
            {Coor(0, 1), Coor(1, 1), Coor(2, 1), Coor(2, 0)},
            {Coor(0, 0), Coor(0, 1), Coor(0, 2), Coor(1, 2)},
            {Coor(0, 1), Coor(0, 0), Coor(1, 0), Coor(2, 0)},
            {Coor(0, 0), Coor(1, 0), Coor(1, 1), Coor(1, 2)}
    };
}

/*
T Shape
*/
TShape::TShape() {
    coor = {
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(1, 1)},
            {Coor(1, 0), Coor(1, 1), Coor(1, 2), Coor(0, 1)},
            {Coor(0, 1), Coor(1, 1), Coor(1, 0), Coor(2, 1)},
            {Coor(0, 0), Coor(0, 1), Coor(1, 1), Coor(0, 2)}
    };
}