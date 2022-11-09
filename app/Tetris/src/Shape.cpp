#include "Shape.h"

Shape::Shape(){
    color = Qt::red;
    offset.x = 3;
}

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
    old.x = offset.x;
    old.y = offset.y;
    offset.x--;
}

/*
move right
*/
void Shape::move_right() {
    old.x = offset.x;
    old.y = offset.y;
    offset.x++;
}

/*
move down
*/
void Shape::move_down() {
    old.x = offset.x;
    old.y = offset.y;
    offset.y = offset.y + 1;
}

Coor& Shape::get_offset() {
    return offset;
}

vector<Coor>& Shape::get_coor() {
    return coor[cur_angle];
}

Coor& Shape::get_old_offset() {
    return old;
}

vector<Coor>& Shape::get_old_shape() {
    return cur_angle == 0 ? coor[3] : coor[cur_angle - 1];
}

vector<Coor>& Shape::get_turn_shape() {
    return cur_angle == 3 ? coor[0] : coor[cur_angle + 1];
}

/*
����
*/
SquareShape::SquareShape() {
    color = Qt::yellow;
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
    color = Qt::green;
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
    color = Qt::blue;
    offset.y = -2;
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
    color = Qt::cyan;
    offset.y = -1;
    coor = {
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(3, 0)},
            {Coor(1, 0), Coor(1, 1), Coor(1, 2), Coor(1, 3)},
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(3, 0)},
            {Coor(1, 0), Coor(1, 1), Coor(1, 2), Coor(1, 3)}
    };
}


/*
I Shape
*/
IShape2::IShape2() {
    color = Qt::darkBlue;
    offset.y = -2;
    coor = {
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(1, 1)},
            {Coor(1, 0), Coor(1, 1), Coor(1, 2), Coor(0, 1)},
            {Coor(0, 1), Coor(1, 1), Coor(1, 0), Coor(2, 1)},
            {Coor(0, 0), Coor(0, 1), Coor(1, 1), Coor(0, 2)}
    };
}

/*
L����-1
*/
LShape1::LShape1() {
    color = Qt::magenta;
    offset.y = -3;
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
    color = Qt::darkRed;
    offset.y = -2;
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
    color = Qt::darkGreen;
    offset.y = -1;
    coor = {
            {Coor(0, 0), Coor(1, 0), Coor(2, 0), Coor(1, 1)},
            {Coor(1, 0), Coor(1, 1), Coor(1, 2), Coor(0, 1)},
            {Coor(0, 1), Coor(1, 1), Coor(1, 0), Coor(2, 1)},
            {Coor(0, 0), Coor(0, 1), Coor(1, 1), Coor(0, 2)}
    };
}