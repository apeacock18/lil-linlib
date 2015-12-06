#include "matrix.h"

int main() 
{
	Matrix m1(3, 3);
	m1.set_entry(0, 0, 6);
	m1.set_entry(0, 1, -3);
	m1.set_entry(0, 2, 4);
	m1.set_entry(1, 0, 5);
	m1.set_entry(1, 1, 1);
	m1.set_entry(1, 2, 9);
	m1.set_entry(2, 0, 1);
	m1.set_entry(2, 1, 5);
	m1.set_entry(2, 2, 8);
	m1.print();
	std::vector<std::vector<double>> entries2(3, std::vector<double>(3, 1));
	Matrix m2(entries2, 3, 3);
	m2.print();
	Matrix m3 = m1 * m2;
	m3.print();
	std::cout << "Determinate of m1: " << find_determinate(m1, 0) << std::endl;
	Matrix m5 = m1.inverse();
	m5.print();
}