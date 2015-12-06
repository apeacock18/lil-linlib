#include "matrix.h"

Matrix::Matrix() {}

Matrix::Matrix(vector<vector<double>> entries, int rows, int cols)
{
	this->entries = entries;
	this->rows = rows;
	this->cols = cols;
}

Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	std::vector<std::vector<double>> e1(rows, std::vector<double>(cols, 0));
	entries = e1;
}

int Matrix::get_rows()
{
	return rows;
}

int Matrix::get_cols()
{
	return cols;
}

vector<vector<double>> Matrix::get_entries()
{
	return entries;
}

void Matrix::set_entries(vector<vector<double>> entries)
{
	this->entries = entries;
}

void Matrix::set_entry(int r, int c, double val)
{
	entries[r][c] = val;
}

void Matrix::print()
{
	std::cout << "--------------------";
	for (int i = 0; i < rows; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < cols; j++)
		{
			if (j != 0) std::cout << " ";
			std::cout << std::setw(5) << std::setfill(' ') << std::setprecision(2) << entries[i][j];
		}
	}
	std::cout << "\n-------------------" << std::endl;
}

IdentityMatrix::IdentityMatrix(int size)
{
	rows = size;
	cols = size;

	for (int i = 0; i < rows; i++)
	{
		vector<double> col(size, 0);
		entries.push_back(col);
		entries[i][i] = 1;
	}
}