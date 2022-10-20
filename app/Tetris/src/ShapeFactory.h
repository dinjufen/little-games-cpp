#pragma once
#include "Shape.h"
#include <cstdlib>

class ShapeFactory {
private:
    static Shape* cur_shape;
    static Shape* next_shape;
    static Shape* random_shape();
public:
    ShapeFactory()=delete;
    ~ShapeFactory()=delete;
    static void init();
    static Shape* get_shape();
    static Shape* get_next();
};