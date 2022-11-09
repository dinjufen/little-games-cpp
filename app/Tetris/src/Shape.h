#ifndef __SHAPE_H__
#define __SHAPE_H__
#include "Coor.h"
#include <QColor>
#include <vector>

using namespace std;

class Shape {
private:
    int cur_angle = 0;
    Coor old;

protected:
    vector<vector<Coor>> coor;
    Coor offset;

public:
    QColor color;
    Shape();
    void turn();
    void move_left();
    void move_right();
    void move_down();
    Coor& get_offset();
    Coor& get_old_offset();
    vector<Coor>& get_coor();
    vector<Coor>& get_old_shape();
    vector<Coor>& get_turn_shape();
};

class SquareShape : public Shape {
public:
    SquareShape();
};

class ZShape1 : public Shape {
public:
    ZShape1();
};

class ZShape2 : public Shape {
public:
    ZShape2();
};

class IShape : public Shape {
public:
    IShape();
};

class LShape1 : public Shape {
public:
    LShape1();
};

class LShape2 : public Shape {
public:
    LShape2();
};

class TShape : public Shape {
public:
    TShape();
};

class IShape2 : public Shape {
public:
    IShape2();
};


#endif