#include "graphics.h"

Shape::Shape(double arr[], int cols)
{
	rows = 2;
	this->cols = cols;
	for (int i = 0; i < rows; i++) {
		row.clear();
		for (int j = 0; j < cols; j++) {
			row.push_back(arr[j + (i * cols)]);
		}
		entries.push_back(row);
	}
}

Matrix Shape::translate(int x, int y)
{
	add_row();
	print();
	IdentityMatrix A(3);
	A.set_entry(0, 2, x);
	A.set_entry(1, 2, y);
	A.print();
	Matrix B = A * (*this);
	return B;
}

void draw()
{

}