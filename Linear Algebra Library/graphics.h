#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "matrix.h"

class Shape: public Matrix
{
public:
	Shape() {}
	Shape(double arr[], int cols);
	Matrix translate(int x, int y);
	void draw();
};

#endif