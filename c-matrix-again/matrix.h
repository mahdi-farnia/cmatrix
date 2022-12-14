//
//  matrix.h
//  c-matrix-again
//
//  Created by mahdi farnia on 9/14/1401 AP.
//

#ifndef matrix_h
#define matrix_h

#include <stdint.h> // size_t
#include <string.h> // memset

typedef struct matrix_int_t {
    size_t row;
    size_t col;
    int **data;
} matrix_int_t;

typedef enum matrix_rotate_t: uint8_t {
    MATRIX_ROTATE_FORWARD,
    MATRIX_ROTATE_BACKWARD
} matrix_rotate_t;

matrix_int_t *matrix_int_create(size_t row, size_t col, int fill);

/** Calculate summation of two matrixes and keeps the result in the first matrix */
void matrix_int_sum(matrix_int_t *restrict, matrix_int_t const *restrict);

/** Calculate subtract of two matrixes and keeps the result in the first matrix */
void matrix_int_sub(matrix_int_t *restrict, matrix_int_t const *restrict);

/** Creates new matrix with the dimension of first matrix row and second matrix column, Return NULL for invalid dimensions: m1->col != m2->row */
matrix_int_t *matrix_int_multiply(matrix_int_t const *restrict, matrix_int_t const *restrict);

// TODO: matrix_int_sort -> { diagonal, column, line }

matrix_int_t *matrix_int_rotate(matrix_int_t const*, matrix_rotate_t);

inline matrix_int_t *matrix_int_cpy(matrix_int_t const *origin) {
    matrix_int_t *copy = matrix_int_create(origin->row, origin->col, 0);

    for (size_t i = 0; i < origin->col; ++i)
        memcpy(copy->data[i], origin->data[i], sizeof(int) * origin->row);
    
    return copy;
}

/** Pass NULL as last paramter to fill new matrix with the first index of given matrix */
inline matrix_int_t *matrix_int_cofactor(matrix_int_t const *restrict matrix, void *restrict fill) {
    // FIXME: fill with last matrix data instead of filling
    return matrix_int_create(matrix->row - 1, matrix->col - 1, fill == NULL ? matrix->data[0][0] : *(int *)fill);
}

/** Fill matrix with given value */
inline void matrix_int_fill(matrix_int_t *matrix, int fill) {
    for (size_t i = 0; i < matrix->col; ++i)
        for (size_t j = 0; j < matrix->row; ++j)
            matrix->data[i][j] = fill;
}

void matrix_int_print(matrix_int_t const*);

inline void matrix_free(matrix_int_t *matrix) {
    for (size_t i = 0; i < matrix->col; ++i)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
}

#endif /* matrix_h */
