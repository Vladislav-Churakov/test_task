#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

int **mult_integer_matrix(int **array_result_integer, int **array_1, int **array_2, int matrix_height, int matrix_width_2, int matrix_width_1);
double **mult_float_matrix(double **array_result_float, double **array_1, double **array_2, int matrix_height, int matrix_width_2, int matrix_width_1);
double **convert_integer_to_float(double **array_result_float, int **array_result_integer, int matrix_height, int matrix_width, int koef);
void write_matrix_to_file_float(double **matrix, size_t rows, size_t cols, const char *filename);
void write_matrix_to_file_integer(int **matrix, size_t rows, size_t cols, const char *filename);
double **absolute_error(double **array_abs_err, double **array_result_float, double **array_convert_result_integer_to_float, int matrix_height, int matrix_width_2);
double random_generator();
double find_max_in_array(double **array, size_t rows, size_t cols);
double MSE(double **array_result_float, double **array_convert_result_integer_to_float, int matrix_height, int matrix_width);
void dynamic_array_print(double **A, size_t N, size_t M);
double **dynamic_array_alloc(size_t N, size_t M);
int **dynamic_array_alloc_integer(size_t N, size_t M);
void dynamic_array_free_float(double **A, size_t N); 
void dynamic_array_free_integer(int **A, size_t N);
double **dynamic_array_test(size_t N, size_t M);
int **dynamic_array_integer_test(double **array_result_float, int **array_result_integer, size_t matrix_height, size_t matrix_width, unsigned int koef);

#endif // MATRIX_OPERATIONS_H