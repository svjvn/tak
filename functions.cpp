#include "headers.h"


void defineMat()
{
    while (true) {
        if (inputMatrixA(matA, filenameA))
            break;
    }

    while (true) {
        if (inputMatrixB(matB, filenameB))
            break;
    }
}

void printMatrix(const matrix& mat)
{
    for (int i = 0; i < M_SIZE; i++) {
        cout << "[";
        for (int j = 0; j < M_SIZE; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << "]" << endl;
    }
}

bool inputMatrixA(matrix& mat)
{
    int data;
    //fstream file;
    fstream file(filenameA);
    for (int i = 0; i < M_SIZE; i++) {
        for (int j = 0; j < M_SIZE; j++) {
            while (file >> data) {
                file >> mat[i][j];
            }

            if (file.fail()) {
                file.clear();
                file.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "\ninvalid input\n" << endl;
                return false;
            }
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return true;
}

bool inputMatrixB(matrix& mat)
{
    for (int i = 0; i < M_SIZE; i++) {
        for (int j = 0; j < M_SIZE; j++) {
            cin >> mat[i][j];

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "\ninvalid input\n" << endl;
                return false;
            }
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return true;
}

void addMat(const matrix& mat1, const matrix& mat2, matrix& result)
{
    for (int i = 0; i < M_SIZE; i++) {
        for (int j = 0; j < M_SIZE; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMat(const matrix& mat1, const matrix& mat2, matrix& result)
{
    for (int i = 0; i < M_SIZE; i++) {
        for (int j = 0; j < M_SIZE; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
void multiplyMat(const matrix& mat1, const matrix& mat2, matrix& result)
{
    for (int i = 0; i < M_SIZE; i++) {
        for (int j = 0; j < M_SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < M_SIZE; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
