#include "matrix.h"
#include <cmath>

using std::vector;

bool Matrix::is_matrix(Matrix m)
{
	if (m.entries.empty())
		return false;
	else if (m.rows <= 0)
		return false;
	else if (m.cols <= 0)
		return false;
	else
		return true;
}

bool Matrix::operator==(Matrix m)
{
	if (rows != m.get_rows() && cols != m.get_cols())
		return false;
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			if (entries[i][j] != m.entries[i][j])
				return false;
	return true;
}

Matrix Matrix::operator+(Matrix m)
{
	Matrix temp_m(rows, cols);
	if (rows != m.get_rows() || cols != m.cols)
		return temp_m;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			temp_m.entries[i][j] = entries[i][j] + m.entries[i][j];
	}
	return temp_m;
}

Matrix Matrix::operator-(Matrix m)
{
	Matrix temp_m(rows, cols);
	if (rows != m.get_rows() || cols != m.cols)
		return temp_m;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			temp_m.entries[i][j] = entries[i][j] - m.entries[i][j];
	}
	return temp_m;
}

Matrix Matrix::operator*(Matrix m)
{
	Matrix temp_m(rows, cols);
	if (cols != m.rows) {
		std::cout << "poop" << std::endl;
		return temp_m;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			for (int k = 0; k < cols; k++)
				temp_m.entries[i][j] += entries[i][k] * m.entries[k][j];
		}
	}
	return temp_m;
}

//Matrix Matrix::operator=(Matrix m)
//{
//	return Matrix(entries, rows, cols);
//}

Matrix Matrix::scalar_mult(double x)
{
	Matrix temp_m = *this;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp_m.entries[i][j] *= x;
	return temp_m;
}

void Matrix::add_row(double arr[])
{
	vector<double> temp;
	for (int i = 0; i < cols; i++)
		temp.push_back(arr[i]);
	entries.push_back(temp);
	rows++;
}

void Matrix::add_row()
{
	vector<double> temp;
	for (int i = 0; i < cols; i++)
		temp.push_back(1.0);
	entries.push_back(temp);
	rows++;
}

Matrix Matrix::transpose()
{
	if (rows != cols)
		return Matrix(rows, cols);

	vector<vector<double>> transpose;

	for (int i = 0; i < rows; i++) {
		row.clear();
		for (int j = 0; j < cols; j++) {
			row.push_back(entries[j][i]);
		}
		transpose.push_back(row);
	}
	return Matrix(transpose, rows, cols);
}

// Method: cofactor expansion across first row
double Matrix::find_determinate()
{
	
	if (rows != cols)
		return NAN;

	double det = 0;

	if (rows == 2)
		return entries[0][0] * entries[1][1] - entries[0][1] * entries[1][0];

	for (int j = 0; j < rows; j++) {
		int sign;
		vector<vector<double>> row_e;
		vector<double> col_e;

		for (int i = 1; i < rows; i++) {
			col_e = entries[i];
			col_e.erase(col_e.begin() + j);
			row_e.push_back(col_e);
		}

		Matrix B(row_e, rows - 1, rows - 1);

		if (j % 2)
			det -= entries[0][j] * B.find_determinate();
		else
			det += entries[0][j] * B.find_determinate();
	}
	return det;
}

Matrix Matrix::cofactor()
{
	if (rows != cols)
		return Matrix();

	double det = 0;
	vector<vector<double>> c;

	for (int i = 0; i < rows; i++)
	{
		vector<double> c_row;
		for (int j = 0; j < rows; j++)
		{
			int sign;
			vector<vector<double>> row_e;
			vector<double> col_e;

			for (int i1 = 0; i1 < rows; i1++)
			{
				if (i1 == i) continue;
				col_e = entries[i1];
				col_e.erase(col_e.begin() + j);
				row_e.push_back(col_e);
			}

			Matrix B(row_e, rows - 1, rows - 1);
			det = B.find_determinate();

			if (j % 2)
				sign = -1;
			else
				sign = 1;

			c_row.push_back(pow(-1, i + j + 2.0) * det);
		}
		c.push_back(c_row);
	}
	Matrix C(c, rows, cols);
	return C;
}

Matrix Matrix::inverse()
{
	if (rows != cols)
		return Matrix();
	int size = rows;
	double determinate = find_determinate();
	if (determinate == 0)
		return Matrix();

	Matrix A = cofactor();
	A = A.transpose();
	A = A.scalar_mult(1.0 / determinate);

	return A;
}