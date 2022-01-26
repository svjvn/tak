#include <iostream>
#include <cstdlib>
#include <limits>
#include "headers.h"
#include "functions.cpp"


int main()
{
    int choice = -1;

    cout << "Name of the file where matrix A is stored: ";
        cin >> filenameA;
    cout << "Name of the file, where matrix B is stored: ";
        cin >> filenameB;

    defineMat();

    system("CLS");

    while (choice != 3) {
        cout << "\nMatrix A:\n";
        printMatrix(matA);
        cout << "\nMatrix B:\n";
        printMatrix(matB);

        cout << "\nChoose an action:\n\n"
            << "0 - redefine your matrixes\n"
            << "1 - addition (+)\n"
            << "2 - substraction (-)\n"
            << "3 - multiplication (*)\n"
            << "4 - if you want to quit the programme\n\n"
            << "enter the number of an action you want to perform: ";

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\ninvalid input\n"
                << "enter the actions number again ";
        }

        cout << endl;

        switch (choice) {
        case 0:
            defineMat();
            break;

        case 1:
            addMat(matA, matB, result);
            cout << "The result of addition of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 2:
            subtractMat(matA, matB, result);
            cout << "The result of subtraction of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 3:
            multiplyMat(matA, matB, result);
            cout << "The result of multiplication of Matrix A and Matrix B is:\n";
            printMatrix(result);
            break;

        case 4:
            cout << "exiting...\n";
            exit(0);
            break;
        

        default:
            cout << "\ninvalid input!\n";
            cout << "\nenter the number of an action again:\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        system("CLS");
    }

    return 0;
}

