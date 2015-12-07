#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <iomanip>

class Matrix
{
protected:
	int rows;
	int cols;
	std::vector<std::vector<double>> entries;
	std::vector<double> row;
	Matrix(std::vector<std::vector<double>> entries, int rows, int cols);

public:
	// Constructors for filled and empty matrices
	Matrix();
	Matrix(double arr[], int rows, int cols);
	Matrix(int rows, int cols);

	// Basic matrix on matrix operations
	bool operator==(Matrix m);
	Matrix operator+(Matrix m);
	Matrix operator-(Matrix m);
	Matrix operator*(Matrix m);
	//Matrix operator=(Matrix m);
	Matrix scalar_mult(double x);
	void add_row(double arr[]);
	void add_row();

	Matrix inverse();
	Matrix transpose();
	double find_determinate();
	Matrix cofactor();

	bool is_matrix(Matrix m);
	int get_rows();
	int get_cols();
	std::vector<std::vector<double>> get_entries();
	double get_entry(int row, int col);
	void set_entries(double arr[]);
	void set_entry(int r, int c, double val);

	// Utility
	void print();
};

class IdentityMatrix : public Matrix
{
public:
	IdentityMatrix(int size);
};

#endif
