//
// Created by 丁俊峰 on 2022/10/20.
//
#include "ShapeFactory.h"
#include <QDebug>
#include <QRandomGenerator>

Shape* ShapeFactory::get_shape() {
    const int i = QRandomGenerator::global()->bounded(7);
    qInfo() << "shape index" << i;
    Shape* shape = nullptr;
    switch (i) {
        case 0:
            shape = new SquareShape();
            break;
        case 1:
            shape = new ZShape1();
            break;
        case 2:
            shape = new ZShape2();
            break;
        case 3:
            shape = new IShape();
            break;
        case 4:
            shape = new LShape1();
            break;
        case 5:
            shape = new LShape2();
            break;
        case 6:
            shape = new TShape();
    }
    return shape;
}