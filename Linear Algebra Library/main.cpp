#include "matrix.h"

int main() 
{
	std::vector<std::vector<double>> entries(2, std::vector<double>(2, 0));
	Matrix m1(entries, 2, 2);
	m1.set_entries(0, 0, 1);
	m1.set_entries(0, 1, 3);
	m1.set_entries(1, 0, 5);
	m1.set_entries(1, 1, 1);
	m1.print();
	std::vector<std::vector<double>> entries2(2, std::vector<double>(2, 1));
	Matrix m2(entries2, 2, 2);
	m2.print();
	Matrix m3 = m1 * m2;
	m3.print();
	IdentityMatrix m4(5);
	m4.print();
}