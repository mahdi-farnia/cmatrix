//
//  matrix.c
//  c-matrix-again
//
//  Created by mahdi farnia on 9/14/1401 AP.
//

#include <stdlib.h> // malloc
#include <stdio.h>
#include "matrix.h"

matrix_int_t *matrix_int_create(size_t row, size_t col, int fill) {
    matrix_int_t *matrix = malloc(sizeof(matrix_int_t));

    matrix->row = row;
    matrix->col = col;
    matrix->data = malloc(sizeof(int *) * col);

    for (size_t i = 0; i < col; ++i) {
        matrix->data[i] = malloc(sizeof(int) * row);
        for (size_t j = 0; j < row; ++j)
            matrix->data[i][j] = fill;
    }

    return matrix;
}

void matrix_int_sum(matrix_int_t *restrict mutable_matrix, matrix_int_t const *restrict matrix_2) {
    // Check for same dimension
    if (mutable_matrix->col != matrix_2->col || mutable_matrix->row != matrix_2->row)
        return;

    for (size_t i = 0; i < mutable_matrix->col; ++i)
        for (size_t j = 0; j < mutable_matrix->row; ++j)
            mutable_matrix->data[i][j] += matrix_2->data[i][j];
}

void matrix_int_sub(matrix_int_t *restrict mutable_matrix, matrix_int_t const *restrict matrix_2) {
    // Check for same dimension
    if (mutable_matrix->col != matrix_2->col || mutable_matrix->row != matrix_2->row)
        return;

    for (size_t i = 0; i < mutable_matrix->col; ++i)
        for (size_t j = 0; j < mutable_matrix->row; ++j)
            mutable_matrix->data[i][j] -= matrix_2->data[i][j];
}

matrix_int_t *matrix_int_multiply(matrix_int_t const *restrict matrix_1, matrix_int_t const *restrict matrix_2) {
    // Check for multiply probability
    if (matrix_1->col != matrix_2->row)
        return NULL;

    matrix_int_t *result = matrix_int_create(matrix_1->row, matrix_2->col, 0);
    
    for (size_t i = 0; i < matrix_1->row; ++i) {
        for (size_t j = 0; j < matrix_2->row; ++j) {
            int multResult = 0;
            for (size_t k = 0; k < matrix_2->row; ++k)
                multResult += matrix_1->data[i][k] * matrix_2->data[j][k];
            result->data[i][j] = multResult;
        }
    }
    
    return result;
}

void matrix_int_fill(matrix_int_t *matrix, int fill) {
    for (size_t i = 0; i < matrix->col; ++i)
        for (size_t j = 0; j < matrix->row; ++j)
            matrix->data[i][j] = fill;
}

void matrix_int_print(matrix_int_t *matrix) {
    for (size_t i = 0; i < matrix->col; ++i) {
        printf("[ ");
        for (size_t j = 0; j < matrix->row; ++j)
            printf("%d ", matrix->data[i][j]);
        printf("]\n");
    }
}

void matrix_free(matrix_int_t *matrix) {
    for (size_t i = 0; i < matrix->col; ++i)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
}
