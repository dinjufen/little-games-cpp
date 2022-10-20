//
// Created by 丁俊峰 on 2022/10/20.
//

#pragma once
#include "ShapeFactory.h"
#include <cstdlib>

Shape* ShapeFactory::cur_shape = ShapeFactory::random_shape();
Shape* ShapeFactory::next_shape = ShapeFactory::random_shape();

Shape* ShapeFactory::random_shape() {
    int i = rand() % 7;
    switch (i) {
        case 0:
            return new SquareShape();
        case 1:
            return new ZShape1();
        case 2:
            return new ZShape2();
        case 3:
            return new IShape();
        case 4:
            return new LShape1();
        case 5:
            return new LShape2();
        case 6:
            return new TShape();
    }
}

Shape* ShapeFactory::get_shape() {
    next_shape = random_shape();
    return cur_shape;
}

Shape* ShapeFactory::get_next() {
    delete cur_shape;
    cur_shape = next_shape;
    return next_shape;
}