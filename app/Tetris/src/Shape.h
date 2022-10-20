#pragma once
#include "Coor.h"
#include <QColor>
#include <vector>

using namespace std;

class Shape {
private:
    int cur_angle = 0;
    int length;
    int speed;
    Coor offset;
    Coor old;

protected:
    vector<vector<Coor>> coor;

public:
    QColor color;
    Shape();
    void turn();
    void move_left();
    void move_right();
    void move_down();
    Coor get_offset();
    Coor get_old_offset();
    vector<Coor> get_vir_coor();
    vector<Coor> get_old_shape();
    vector<Coor> get_next_shape();
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