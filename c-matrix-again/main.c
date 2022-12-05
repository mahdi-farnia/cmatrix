//
//  main.c
//  c-matrix-again
//
//  Created by mahdi farnia on 9/14/1401 AP.
//

#include <stdio.h>
#include "matrix.h"

int main(int argc, const char * argv[]) {
    matrix_int_t *matrix = matrix_int_create(2, 2, 0);
    
    printf("Before summation:\n");
    matrix_int_print(matrix);

    matrix_int_t *temp = matrix_int_create(2, 2, 1);

    matrix_int_sum(matrix, temp);

    matrix_free(temp);

    printf("After summation:\n");
    matrix_int_print(matrix);

    matrix_int_t *m2 = matrix_int_multiply(matrix, matrix);

    printf("Result of power 2:\n");
    matrix_int_print(m2);
    
    matrix_free(matrix);
    return 0;
}
