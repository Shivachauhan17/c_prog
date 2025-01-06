#include<stdio.h>
#include <stdlib.h>

int **allocateMatrix(int size){
    int **matrix=(int **) malloc(size*sizeof(int*));
    for(int i=0;i<size;i++){
        matrix[i]=(int *) malloc(size*sizeof(int));
    }

    return matrix;
}

void freeMatrix(int **matrix,int size){
    for(int i=0;i<size;i++){
        free(matrix[i]);
    }
    free(matrix);
}

void addMatrices(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}


// Function to subtract two matrices
void subtractMatrices(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}


void strassen(int** A, int** B, int** C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;

    int** A11 = allocateMatrix(newSize);
    int** A12 = allocateMatrix(newSize);
    int** A21 = allocateMatrix(newSize);
    int** A22 = allocateMatrix(newSize);

    int** B11 = allocateMatrix(newSize);
    int** B12 = allocateMatrix(newSize);
    int** B21 = allocateMatrix(newSize);
    int** B22 = allocateMatrix(newSize);

    int** P1 = allocateMatrix(newSize);
    int** P2 = allocateMatrix(newSize);
    int** P3 = allocateMatrix(newSize);
    int** P4 = allocateMatrix(newSize);
    int** P5 = allocateMatrix(newSize);
    int** P6 = allocateMatrix(newSize);
    int** P7 = allocateMatrix(newSize);

    int** Temp1 = allocateMatrix(newSize);
    int** Temp2 = allocateMatrix(newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    subtractMatrices(B12, B22, Temp1, newSize);  // Temp1 = B12 - B22
    strassen(A11, Temp1, P1, newSize);          // P1 = A11 * Temp1

    addMatrices(A11, A12, Temp1, newSize);      // Temp1 = A11 + A12
    strassen(Temp1, B22, P2, newSize);          // P2 = Temp1 * B22

    addMatrices(A21, A22, Temp1, newSize);      // Temp1 = A21 + A22
    strassen(Temp1, B11, P3, newSize);          // P3 = Temp1 * B11

    subtractMatrices(B21, B11, Temp1, newSize); // Temp1 = B21 - B11
    strassen(A22, Temp1, P4, newSize);          // P4 = A22 * Temp1

    addMatrices(A11, A22, Temp1, newSize);      // Temp1 = A11 + A22
    addMatrices(B11, B22, Temp2, newSize);      // Temp2 = B11 + B22
    strassen(Temp1, Temp2, P5, newSize);        // P5 = Temp1 * Temp2

    subtractMatrices(A12, A22, Temp1, newSize); // Temp1 = A12 - A22
    addMatrices(B21, B22, Temp2, newSize);      // Temp2 = B21 + B22
    strassen(Temp1, Temp2, P6, newSize);        // P6 = Temp1 * Temp2

    subtractMatrices(A11, A21, Temp1, newSize); // Temp1 = A11 - A21
    addMatrices(B11, B12, Temp2, newSize);      // Temp2 = B11 + B12
    strassen(Temp1, Temp2, P7, newSize);        // P7 = Temp1 * Temp2

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];              // C11
            C[i][j + newSize] = P1[i][j] + P2[i][j];                          // C12
            C[i + newSize][j] = P3[i][j] + P4[i][j];                          // C21
            C[i + newSize][j + newSize] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j]; // C22
        }
    }

    freeMatrix(A11, newSize);
    freeMatrix(A12, newSize);
    freeMatrix(A21, newSize);
    freeMatrix(A22, newSize);

    freeMatrix(B11, newSize);
    freeMatrix(B12, newSize);
    freeMatrix(B21, newSize);
    freeMatrix(B22, newSize);

    freeMatrix(P1, newSize);
    freeMatrix(P2, newSize);
    freeMatrix(P3, newSize);
    freeMatrix(P4, newSize);
    freeMatrix(P5, newSize);
    freeMatrix(P6, newSize);
    freeMatrix(P7, newSize);

    freeMatrix(Temp1, newSize);
    freeMatrix(Temp2, newSize);
}



int main(){
    int size = 4; 
    int** A = allocateMatrix(size);
    int** B = allocateMatrix(size);
    int** C = allocateMatrix(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    strassen(A, B, C, size);

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}