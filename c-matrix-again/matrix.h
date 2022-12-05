//
//  matrix.h
//  c-matrix-again
//
//  Created by mahdi farnia on 9/14/1401 AP.
//

#ifndef matrix_h
#define matrix_h

#include <stdint.h> // size_t

typedef struct matrix_int_t {
    size_t row;
    size_t col;
    int **data;
} matrix_int_t;

matrix_int_t *matrix_int_create(size_t row, size_t col, int fill);

/** Calculate summation of two matrixes and keeps the result in the first matrix */
void matrix_int_sum(matrix_int_t *restrict, matrix_int_t const *restrict);

/** Calculate subtract of two matrixes and keeps the result in the first matrix */
void matrix_int_sub(matrix_int_t *restrict, matrix_int_t const *restrict);

/** Creates new matrix with the dimension of first matrix row and second matrix column, Return NULL for invalid dimensions: m1->col != m2->row */
matrix_int_t *matrix_int_multiply(matrix_int_t const *restrict, matrix_int_t const *restrict);

/** Pass NULL as last paramter to fill new matrix with the first index of given matrix */
inline matrix_int_t *matrix_int_cofactor(matrix_int_t const *matrix, void *fill) {
    return matrix_int_create(matrix->row - 1, matrix->col - 1, fill == NULL ? matrix->data[0][0] : *(int *)fill);
}

/** Fill matrix with given value */
void matrix_int_fill(matrix_int_t *, int);

void matrix_int_print(matrix_int_t *);

void matrix_free(matrix_int_t *);

#endif /* matrix_h */