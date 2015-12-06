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
	if (rows != m.get_rows() || cols != m.cols)
		return temp_m;
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

Matrix Matrix::scalar_mult(double x)
{
	Matrix temp_m = *this;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp_m.entries[i][j] *= x;
	return temp_m;
}

Matrix Matrix::transpose()
{
	if (rows != cols)
		return Matrix(rows, cols);
	vector< vector<double> > transpose;

	for (int i = 0; i < rows; i++)
	{
		vector<double> temp;
		for (int j = 0; j < cols; j++)
			temp.push_back(entries[j][i]);
		transpose.push_back(temp);
	}

	return Matrix(transpose, rows, cols);
}

// Method: cofactor expansion across first row
double find_determinate(Matrix A, int n)
{
	
	if (A.get_rows() != A.get_cols())
		return NULL;

	int size = A.get_rows();

	vector<vector<double>> a = A.get_entries();
	double det = 0;

	if (size == 2)
	{
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}

	for (int j = 0; j < size; j++)
	{
		int sign;
		vector<vector<double>> row_e;
		vector<double> col_e;

		for (int i1 = 1; i1 < size; i1++)
		{
			col_e = a[i1];
			col_e.erase(col_e.begin() + j);
			row_e.push_back(col_e);
		}

		Matrix B(row_e, size - 1, size - 1);
		if (n % 2)
		{
			if (j % 2)
				sign = 1;
			else
				sign = -1;
		}
		else
		{
			if (j % 2)
				sign = -1;
			else
				sign = 1;
		}
		det += sign * a[0][j] * find_determinate(B, n + 1);
	}
	return det;
}

Matrix cofactor(Matrix A)
{
	if (A.get_rows() != A.get_cols())
		return Matrix();

	int size = A.get_rows();
	Matrix C(size, size);
	vector<vector<double>> c = C.get_entries();
	vector<vector<double>> a = A.get_entries();
	double det = 0;
	int k = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int sign;
			vector<vector<double>> row_e;
			vector<double> col_e;

			for (int i1 = 0; i1 < size; i1++)
			{
				if (i1 == i)
					continue;
				col_e = a[i1];
				col_e.erase(col_e.begin() + j);
				row_e.push_back(col_e);
			}

			Matrix B(row_e, size - 1, size - 1);
			det = find_determinate(B, 0);

			if (j % 2)
				sign = -1;
			else
				sign = 1;
			c[i][j] = pow(-1, i + j + 2.0) * det;
		}
	}
	C.set_entries(c);
	return C;
}

Matrix Matrix::inverse()
{
	if (rows != cols)
		return Matrix();
	int size = rows;
	double determinate = find_determinate(*this, 0);
	Matrix A = cofactor(*this);
	A.print();
	A = A.transpose();

	if (determinate == 0)
		return Matrix();

	A = A.scalar_mult(1.0 / determinate);

	return A;
}