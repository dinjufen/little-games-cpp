//
// Created by 丁俊峰 on 2022/10/20.
//
#include "ShapeFactory.h"
#include <QDebug>
#include <QRandomGenerator>
#include <memory>

ShapeFactory* ShapeFactory::instance = nullptr;
Shape* ShapeFactory::random_shape() {
    const int i = QRandomGenerator::global()->bounded(7);
    Shape* shape = nullptr;
    switch (i) {
        case 0:
            shape = new SquareShape();
        case 1:
            shape = new ZShape1();
        case 2:
            shape = new ZShape2();
        case 3:
            shape = new IShape();
        case 4:
            shape = new LShape1();
        case 5:
            shape = new LShape2();
        case 6:
            shape = new TShape();
    }
    return shape;
}

ShapeFactory::ShapeFactory() {

}

ShapeFactory::~ShapeFactory() {
    if (cur_shape) {
        delete cur_shape;
        cur_shape = nullptr;
    }
    if (next_shape) {
        delete next_shape;
        next_shape = nullptr;
    }
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

ShapeFactory* ShapeFactory::GetInstance() {
    if (instance == nullptr) {
        instance = new ShapeFactory();
    }
    return instance;
}

void ShapeFactory::init() {
    cur_shape = random_shape();
    next_shape = random_shape();
}

Shape* ShapeFactory::get_shape() {
    return cur_shape;
}

Shape* ShapeFactory::get_next() {
    cur_shape = next_shape;
    next_shape = random_shape();
    return next_shape;
}

void ShapeFactory::generate_shape() {
//    delete cur_shape;
    cur_shape = next_shape;
    next_shape = random_shape();
}