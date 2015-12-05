#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

using std::vector;

class Matrix
{
protected:
	int rows;
	int cols;
	vector<vector<double>> entries;

public:
	// Constructors for filled and empty matrices
	Matrix();
	Matrix(vector<vector<double>> entries, int rows, int cols);
	Matrix(int rows, int cols);

	// Basic matrix on matrix operations
	bool operator==(Matrix m);
	Matrix operator+(Matrix m);
	Matrix operator-(Matrix m);
	Matrix operator*(Matrix m);

	Matrix inverse();
	Matrix transpose();

	bool is_matrix(Matrix m);
	int get_rows();
	int get_cols();
	vector<vector<double>> get_entries();
	void set_entries(int m, int n, double val);

	// Utility
	void print();
};

class IdentityMatrix : public Matrix
{
public:
	IdentityMatrix(int size);
};

#endif
