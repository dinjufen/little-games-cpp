#ifndef __SHAPE_FACTORY__
#define __SHAPE_FACTORY__

#include "Shape.h"

class ShapeFactory {
private:
    ShapeFactory()=delete;
    ~ShapeFactory()=default;

public:
    static Shape* get_shape();
};

#endif