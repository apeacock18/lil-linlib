#include "matrix.h"

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

Matrix Matrix::transpose()
{
	Matrix temp_m(rows, cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp_m.entries[i][j] = entries[j][i];
	return temp_m;
}

Matrix Matrix::inverse()
{
	return *this;
}