#include "matrix.h"
#include "graphics.h"""

int main() 
{
	double arr3[6] = { 0, 2, 1, 0, 0, 3 };
	Shape shape(arr3, 3);
	shape.print();
	Matrix A = shape.translate(0, 2);
	A.print();
	/*double arr[9] = { 6, -3, 4, 5, 1, 9, 1, 5, 8 };
	Matrix m1(arr, 3, 3);
	m1.print();
	double arr2[9] = { 3, 2, 1, 4, 3, 5, 6, 5, 2.3 };
	Matrix m2(arr2, 3, 3);
	m2.print();
	Matrix m3 = m1 * m2;
	m3.print();
	std::cout << "Determinate of m1: " << m1.find_determinate() << std::endl;
	m1.cofactor().print();
	Matrix m5 = m1;
	m5 = m5.inverse();
	m5.print();*/
}