#ifndef __SHAPE_FACTORY__
#define __SHAPE_FACTORY__

#include "Shape.h"
#include <cstdlib>

class ShapeFactory {
private:
    static ShapeFactory* instance;
    Shape* cur_shape;
    Shape* next_shape;
    Shape* random_shape();
    ShapeFactory();
    ~ShapeFactory();
public:
    Shape* get_shape();
    Shape* get_next();
    void generate_shape();
    static ShapeFactory* GetInstance();
    void init();
};

#endif