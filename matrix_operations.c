#include "matrix_operations.h"



int **mult_integer_matrix(int **array_result_integer, int **array_1, int **array_2, int matrix_height, int matrix_width_2, int matrix_width_1) 
{
    for(size_t i = 0; i < matrix_height; i++) // строка
    {
        for(size_t j = 0; j < matrix_width_2; j++) // столбец
        {
            array_result_integer[i][j] = 0;
            for(size_t k = 0; k < matrix_width_1; k++)
            {
                array_result_integer[i][j] +=  array_1[i][k] * array_2[k][j];
            }
        }
    }
    return array_result_integer;
}
//------------------------------------------------------------------------------------------------------------
double **mult_float_matrix(double **array_result_float, double **array_1, double **array_2, int matrix_height, int matrix_width_2, int matrix_width_1)
{
    for(size_t i = 0; i < matrix_height; i++) // строка
    {
        for(size_t j = 0; j < matrix_width_2; j++) // столбец
        {
            array_result_float[i][j] = 0;
            for(size_t k = 0; k < matrix_width_1; k++)
            {
                array_result_float[i][j] +=  array_1[i][k] * array_2[k][j];
            }
        }
    }
    return array_result_float;
}
//------------------------------------------------------------------------------------------------------------
double **convert_integer_to_float(double **array_result_float, int **array_result_integer, int matrix_height, int matrix_width, int koef)
{
    for(int i = 0; i < matrix_height; i++) // matrix_height_1
    {
        for(int j = 0; j < matrix_width; j++)  // matrix_width_2
        {
            //array_result_float[i][j] = 0;
            array_result_float[i][j] = (double)(array_result_integer[i][j]) / (koef * koef);
            //printf("!!!%10.5f\n", array_result_float[i][j]);
            //printf("***%d %d\n", i, j);
        }
        //printf(" \n");
        
    }
    return array_result_float;
}
//------------------------------------------------------------------------------------------------------------
void write_matrix_to_file_float(double **matrix, size_t rows, size_t cols, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        perror("Ошибка открытия файла для записи");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < rows; i++) 
    {
        for (size_t j = 0; j < cols; j++) 
        {
            fprintf(file, "%10.5f ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
//------------------------------------------------------------------------------------------------------------
void write_matrix_to_file_integer(int **matrix, size_t rows, size_t cols, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        perror("Ошибка открытия файла для записи");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < rows; i++) 
    {
        for (size_t j = 0; j < cols; j++) 
        {
            fprintf(file, "%10d", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
//------------------------------------------------------------------------------------------------------------
double **absolute_error(double **array_abs_err, double **array_result_float, double **array_convert_result_integer_to_float, int matrix_height, int matrix_width_2)
{

  for(size_t i = 0; i < matrix_height; i++) // строка
    {
        for(size_t j = 0; j < matrix_width_2; j++) // столбец
        {
            array_abs_err[i][j] = 0;
            array_abs_err[i][j] =  array_result_float[i][j] - array_convert_result_integer_to_float[i][j];
            if(array_abs_err[i][j] < 0)
            {
                array_abs_err[i][j] *= -1;
            }
        }
    }
    return array_abs_err;
}
//------------------------------------------------------------------------------------------------------------
double MSE( double **array_result_float, double **array_convert_result_integer_to_float, int matrix_height, int matrix_width)
{
  double y = 0.0;  
  double z = 0.0;  
  for(size_t i = 0; i < matrix_height; i++) // строка
    {
        for(size_t j = 0; j < matrix_width; j++) // столбец
        {
            z =  array_result_float[i][j] - array_convert_result_integer_to_float[i][j];
            y = (y + (z * z));
        }
    }
    y = y / (matrix_height * matrix_width);
    return y;
}
//------------------------------------------------------------------------------------------------------------
double random_generator()
{
    int rand_int = rand();
    double rand_double = (double)rand_int / RAND_MAX;
    double rand_range = rand_double * 2.0 - 1.0;

    return rand_range;
}
//------------------------------------------------------------------------------------------------------------
void dynamic_array_print(double **A, size_t N, size_t M)
{
    for(size_t i = 0; i < N; i++) 
    {
        for(size_t j = 0; j < M; j++) 
        {
            printf("%10.5f", A[i][j]);
        }
        printf("\n");
    }
}

//------------------------------------------------------------------------------------------------------------
double **dynamic_array_alloc(size_t N, size_t M)
{
    double **A = (double **)malloc(N * sizeof(double *));
    for(size_t i = 0; i < N; i++) 
    {
        A[i] = (double *)malloc(M * sizeof(double));
    }
    return A;
}
//------------------------------------------------------------------------------------------------------------
int **dynamic_array_alloc_integer(size_t N, size_t M)
{
    int **A = (int **)malloc(N * sizeof(int *));
    for(size_t i = 0; i < N; i++)
    {
        A[i] = (int *)malloc(M * sizeof(int));
    }
    return A;
}
//------------------------------------------------------------------------------------------------------------
void dynamic_array_free_float(double **A, size_t N)
{
    for(size_t i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}
//------------------------------------------------------------------------------------------------------------
void dynamic_array_free_integer(int **A, size_t N)
{
    for(size_t i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}
//------------------------------------------------------------------------------------------------------------
double **dynamic_array_test(size_t N, size_t M)
{
    double **A = dynamic_array_alloc(N, M);
    for(size_t i = 0; i < N; i++) {
        for(size_t j = 0; j < M; j++) {
            A[i][j] = random_generator();
        }
    }
    //dynamic_array_print(A, N, M);
    return A;
}
//------------------------------------------------------------------------------------------------------------
double find_max_in_array(double **array, size_t rows, size_t cols) 
{
    double max_value = array[0][0];
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++) 
        {
            if(array[i][j] > max_value)
            {
                max_value = array[i][j];
            }
        }
    }
    return max_value;
}
//------------------------------------------------------------------------------------------------------------
int **dynamic_array_integer_test(double **array_result_float, int **array_result_integer, size_t N, size_t M, unsigned int koef)
{
    int **A = dynamic_array_alloc_integer(N, M);
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < M; j++) 
        {
            //A[i][j] = 0;
            A[i][j] = (int)(array_result_float[i][j] * koef);
            //printf("i = %d j = %d\n", i, j);
        }
    }
    //dynamic_array_print(A, N, M);
    return A;
}
//------------------------------------------------------------------------------------------------------------