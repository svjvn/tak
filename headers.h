#pragma once
#include <iostream>
#include <cstdlib>
#include <limits> 
#include <string>
#include <fstream>

using namespace std;

string filenameA;
string filenameB;

const int M_SIZE = 3;
typedef double matrix[M_SIZE][M_SIZE];

void printMatrix(const matrix& mat);
bool inputMatrixA(matrix& mat, std::string filenameA);
bool inputMatrixB(matrix& mat, std::string filenameB);
void addMat(const matrix& mat1, const matrix& mat2, matrix& result);
void subtractMat(const matrix& mat1, const matrix& mat2, matrix& result);
void multiplyMat(const matrix& mat1, const matrix& mat2, matrix& result);
void defineMat();



matrix matA;
matrix matB;
matrix result;

