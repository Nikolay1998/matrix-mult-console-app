#include <iostream>
#include <vector>
#include "MyMatrix.h"
#include <fstream>
#include "MatrixMultConsoleApp.h"

using namespace std;

MyMatrix *readFromFile(const char *filename) {
    //cout << "Reading from File" << endl;
    ifstream srcStream(filename);
    if (!srcStream.is_open()) {
        cout << "Error during reading matrix from file: " << filename << endl;
        srcStream.close();
        return NULL;
    }
    //read numbers from file to vector. Also count columns count(into columnCounter)
    double currNumber;
    int columnCounter = 0;
    bool isFirstLine = true;
    vector<double> numbers(0);

    while (srcStream >> currNumber) {
        cout << currNumber << " ";
        numbers.push_back(currNumber);

        if (isFirstLine) {
            columnCounter++;
            if (srcStream.peek() == '\n' || srcStream.peek() == EOF)
                isFirstLine = false;
        }

    }
    int rowsCount = numbers.size() / columnCounter;
    //cout << "dimension: " << rowsCount << " " << columnCounter << endl;
    MyMatrix *matrix = new MyMatrix(rowsCount, columnCounter, numbers);
    srcStream.close();
    //cout << "End Reading from File" << endl

    return matrix;
}

int writeToFile(MyMatrix *matrix, const char *fileName) {
    ofstream tgtStream(fileName);
    if (!tgtStream.is_open()) {
        cout << "Error during writing matrix to file: " << fileName << endl;
        tgtStream.close();
        return -1;
    }
    for (int i = 0; i < matrix->getRowsCount(); i++) {
        for (int j = 0; j < matrix->getColumnsCount(); j++) {
            tgtStream << matrix->getValue(i, j) << " ";
        }
        tgtStream << endl;
    }
    cout << "Success";
    return 0;
}

MyMatrix *multiplication(MyMatrix *first, MyMatrix *second) {
    if (first->getColumnsCount() != second->getRowsCount()) {
        cout << "Dimensions of matrixes are not matched" << endl;
        return NULL;
    }
    vector<double> res(0);
    int N = first->getRowsCount();
    double tmp = 0;
    for (int r = 0; r < first->getRowsCount(); r++) {
        for (int j = 0; j < second->getColumnsCount(); j++) {
            for (int i = 0; i < N; i++) {
                tmp += first->numbers[r][i] * second->numbers[i][j];
            }
            res.push_back(tmp);
            tmp = 0;
        }
    }
    return new MyMatrix(first->getRowsCount(), second->getColumnsCount(), res);
}

void help(char *argv[]) {
    if (argv[0] == "--help") {
        cout << "Help";
    }
}

int main(int argc, char *argv[]) {
    help(argv);

    MyMatrix *first = readFromFile("test/first.txt");
    MyMatrix *second = readFromFile("test/second.txt");
    MyMatrix *third = NULL;
    if (first != NULL && second != NULL) {
        third = multiplication(first, second);
        if (third != NULL) {
            int res = writeToFile(third, "test/third.txt");
        }
    }
    if (first != NULL) first->~MyMatrix();
    if (second != NULL) second->~MyMatrix();
    if (third != NULL) third->~MyMatrix();
    cin.get();


    return 0;
}