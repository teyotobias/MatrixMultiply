// matrix-multiplication <Project2.cpp>
// EE 312 Project 2 submission by
// Teyo Turrubiates
// ttt2443
// Slip days used: 0
// Spring 2022
// Include the contents of this file at the top of every file that you submit, replacing the fields within <>.  Do not keep the <>.

#include <stdio.h>
#include <stdint.h>
#include "MatrixMultiply.h"
#include <stdlib.h>


//void printmatrix(double matrixxxx[], size_t nrows, size_t ncols){
    //for (int i = 0; i < nrows; i++){
        //for (int j = 0; j<ncols; j++){
       //     printf("%f\t", matrixxxx[i * ncols + j]);
    //    }
   // }
//}

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    double sum = 0;
    double hold = 0;
    while(i < a_rows){
        while(j < b_cols){
            while(k < a_cols){
                hold = a[i*a_cols + k]*b[k*b_cols + j];
                sum = hold + sum;
                k++;
            }
            k = 0;
            c[i*b_cols+j] = sum;
            j++;
            sum = 0;
        }
        j=0;
        i++;

    }
    //printmatrix(c, 5, 2);

    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
    int p = 0;
    int q = 0;
    int h = 0;
    double total = 0;
    double tempHold = 0;
    double** multMatrix = (double**)malloc(sizeof(double)*a_rows);
    for(int i = 0;i < a_rows;i++){
        multMatrix[i] = (double*)malloc(sizeof(double)*b_cols);
    }
    while(p < a_rows){
        while(q < b_cols){
            while(h < a_cols){
                tempHold = a[p][h]*b[h][q];
                total = tempHold + total;
                h++;
            }
            h = 0;
            multMatrix[p][q] = total;
            q++;
            total = 0;
        }
        q=0;
        p++;

    }


    return multMatrix;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols) {
    int x = 0;
    int y = 0;
    double** transMatrix = (double**)malloc(sizeof(double)* a_cols);
    for(int i = 0;i < a_cols;i++) {
        transMatrix[i] = (double *) malloc(sizeof(double) * a_rows);
    }
    while(x < a_cols){
        while(y < a_rows){
            transMatrix[x][y] = a[y][x];
            y++;
        }
        x++;
        y = 0;
    }

    return transMatrix;
}

