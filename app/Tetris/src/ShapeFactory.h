#ifndef __SHAPE_FACTORY__
#define __SHAPE_FACTORY__

#include "Shape.h"
#include <vector>

class ShapeFactory {
private:
    ShapeFactory()=delete;
    ~ShapeFactory()=default;
//    static const vector<Shape> shape_list;

public:
    static Shape* get_shape();
};

#endif