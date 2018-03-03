#include "stdafx.h"
#include "MyMatrix.h"
#include <iostream>


using namespace std;

MyMatrix::MyMatrix(int M, int N, vector<double> data) {
	this->M = M;
	this->N = N;
	int k = 0;
	numbers = new double*[M];
	for (int i = 0; i < M; i++) {
		numbers[i] = new double[N];
		for (int j = 0; j < N; j++) {
			numbers[i][j] = data[k++];
		}
	}
}

MyMatrix::MyMatrix(const MyMatrix& orig) {
	//todo: implement it
}

int MyMatrix::getRowsCount() {
	return M;
}

int MyMatrix::getColumnsCount() {
	return N;
}

double MyMatrix::getValue(int row, int col) {
	return numbers[row][col];
}

void MyMatrix::printMatrix() {
	cout << "matrix: [" << M << "x" << N << "]" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << numbers[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

MyMatrix::~MyMatrix() {
	delete[] numbers;
}




