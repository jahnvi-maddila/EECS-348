#include <iostream>
#include <fstream>

#define MAX_SIZE 20

using namespace std;

// Function to print a matrix
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int dimension, const string& name) {
    cout << "Matrix " << name << ":" << endl;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

// Function to perform matrix addition
void addMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int dimension) {
    cout << "Addition: Matrix A + Matrix B" << endl;
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

// Function to perform matrix multiplication
void multiplyMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int dimension) {
    cout << "Multiplication: Matrix A x Matrix B" << endl;
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            int sum = 0;
            for (int k = 0; k < dimension; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

// Function to perform matrix subtraction
void subtractMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int dimension) {
    cout << "Subtraction: Matrix A - Matrix B" << endl;
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

// Function to update an element in the matrix
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int row, int col, int value, int dimension) {
    matrix[row][col] = value;
    cout << "Updated Matrix A:" << endl;
    printMatrix(matrix, dimension, "A");
}

// Function to find the maximum value in the matrix
void findMaxValue(int matrix[MAX_SIZE][MAX_SIZE], int dimension) {
    int maxValue = matrix[0][0];
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
            }
        }
    }
    cout << "Maximum Value of Matrix A: " << maxValue << endl;
}

// Function to transpose the matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int dimension) {
    cout << "Transpose: Matrix A" << endl;
    int result[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            result[i][j] = matrix[j][i];
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    int dimension;
    file >> dimension;
    if (dimension > MAX_SIZE) {
        cerr << "Matrix size exceeds maximum allowed size" << endl;
        return 1;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            file >> matrixA[i][j];
        }
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            file >> matrixB[i][j];
        }
    }

    file.close();

    printMatrix(matrixA, dimension, "A");
    cout << endl;
    printMatrix(matrixB, dimension, "B");
    cout << endl;
    addMatrix(matrixA, matrixB, dimension);
    cout << endl;
    multiplyMatrix(matrixA, matrixB, dimension);
    cout << endl;
    subtractMatrix(matrixA, matrixB, dimension);
    cout << endl;
    updateElement(matrixA, 2, 2, 40, dimension);
    cout << endl;
    findMaxValue(matrixA, dimension);
    cout << endl;
    transposeMatrix(matrixA, dimension);
    cout << endl;

    return 0;
}
