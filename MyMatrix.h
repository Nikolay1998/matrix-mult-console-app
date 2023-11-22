#pragma once
#include <vector>

class MyMatrix
{//Matrix MxN
public:
	MyMatrix(int M, int N, std::vector<double> data);
	MyMatrix(const MyMatrix& orig);
	
	double getValue(int row, int col);
	int getRowsCount();
	int getColumnsCount();

	void printMatrix();
	virtual ~MyMatrix();

	double** numbers;
private:
	int M, N;
};