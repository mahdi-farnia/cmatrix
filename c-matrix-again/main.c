//
//  main.c
//  c-matrix-again
//
//  Created by mahdi farnia on 9/14/1401 AP.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

static size_t get_dimension(void) {
    size_t dimension = 0;
    int assigned = 0;

    do {
        if (assigned == EOF)
            exit(EXIT_FAILURE);

        printf("Enter matrix dimension: ");
        assigned = scanf("%lu", &dimension);
    } while(assigned != 1);

    return dimension;
}
static inline void matrix_int_scanf(matrix_int_t *matrix) {
    for (size_t i = 0; i < matrix->col; ++i)
        for (size_t j = 0; j < matrix->row; ++j)
            scanf("%d", &matrix->data[i][j]);
}

int main(int argc, const char * argv[]) {
    size_t dimension = get_dimension();
    matrix_int_t *matrix = matrix_int_create(dimension, dimension, 0);
    
    // Fill matrix with input from user
    matrix_int_scanf(matrix);
    
    matrix_int_print(matrix);
    
    matrix_int_t *m2 = matrix_int_rotate(matrix, MATRIX_ROTATE_BACKWARD);

    matrix_int_print(m2);

    matrix_free(matrix);
    matrix_free(m2);
    return EXIT_SUCCESS;
}
