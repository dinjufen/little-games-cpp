#pragma once
#include "Shape.h"
#include <cstdlib>

static class ShapeFactory {
private:
	static Shape cur_shape;
	static Shape next_shape;
	static Shape random_shape() {
		int i = rand() % 7;
		switch (i) {
		case 0:
			return SquareShape();
		case 1:
			return ZShape1();
		case 2:
			return ZShape2();
		case 3:
			return IShape();
		case 4:
			return LShape1();
		case 5:
			return LShape2();
		case 6:
			return TShape();
		}
	}
public:
	void init() {
		cur_shape = random_shape();
		next_shape = random_shape();
	}
	static Shape get_shape() {
		next_shape = random_shape();
		return cur_shape;
	}
	static Shape get_next() {
		cur_shape = next_shape;
		return next_shape;
	}
};