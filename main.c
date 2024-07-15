#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.c"

int main()
{
    int matrix_height_1 = 0; // строка
    int matrix_width_1 = 0; // столбец
    int matrix_height_2 = 0;
    int matrix_width_2 = 0;
    int res = 0;
    double x = 0.0;
    double y = 0.0;

    int **array_11, **array_22, **array_result_integer;

    unsigned int koef = 256;

    double **array_1, **array_2, **array_result_float, **array_convert_result_integer_to_float, **array_abs_err;

    srand(time(NULL));

    printf("Ввидите кол-во строк и столбцов 2-х матриц соотвественно.\n");
    res = scanf("%d%d%d%d", &matrix_height_1, &matrix_width_1, &matrix_height_2, &matrix_width_2);


    if(res != 4)
    {
        printf("Необходимо ввести 4 аргумента.\n");
        abort();
    }
    else if(matrix_width_1 != matrix_height_2)
    {
        printf("Число строк первой матрицы должно равняться числу столбцов второй матрицы!\n");
        abort();
    }


    array_1 = dynamic_array_test(matrix_height_1, matrix_width_1);
    array_2 = dynamic_array_test(matrix_height_2, matrix_width_2);

    

    // Выделение памяти для массива результата
    array_result_float = dynamic_array_alloc(matrix_height_1, matrix_width_2);
    array_result_integer = dynamic_array_alloc_integer(matrix_height_1, matrix_width_2);
    array_convert_result_integer_to_float = dynamic_array_alloc(matrix_height_1, matrix_width_2);
    array_abs_err = dynamic_array_alloc(matrix_height_1, matrix_width_2);


    write_matrix_to_file_float(array_1, matrix_height_1, matrix_width_1, "float_array_1.txt");
    write_matrix_to_file_float(array_2, matrix_height_2, matrix_width_2, "float_array_2.txt");


    array_result_float = mult_float_matrix(array_result_float, array_1, array_2, matrix_height_1, matrix_width_2, matrix_width_1);

    write_matrix_to_file_float(array_result_float, matrix_height_1, matrix_width_2, "float_result_mult.txt");

//************************************************************************************************************
// TASK 2
//************************************************************************************************************
    array_11 = dynamic_array_integer_test(array_1, array_11, matrix_height_1, matrix_width_1, koef);
    write_matrix_to_file_integer(array_11, matrix_height_1, matrix_width_1, "integer_array_11.txt");

    array_22 = dynamic_array_integer_test(array_2, array_22, matrix_height_2, matrix_width_2, koef);
    write_matrix_to_file_integer(array_22, matrix_height_2, matrix_width_2, "integer_array_22.txt");

    array_result_integer = mult_integer_matrix(array_result_integer, array_11, array_22, matrix_height_1, matrix_width_2, matrix_width_1);
    write_matrix_to_file_integer(array_result_integer, matrix_height_1, matrix_width_2, "integer_result_mult.txt");

    array_convert_result_integer_to_float = convert_integer_to_float(array_convert_result_integer_to_float, array_result_integer, matrix_height_1, matrix_width_2, koef);
    write_matrix_to_file_float(array_convert_result_integer_to_float, matrix_height_1, matrix_width_2, "convert_result_integer_to_float.txt");
  
    array_abs_err = absolute_error(array_abs_err, array_result_float, array_convert_result_integer_to_float, matrix_height_1, matrix_width_2);
    write_matrix_to_file_float(array_abs_err, matrix_height_1, matrix_width_2, "absolute_error.txt");

    x = find_max_in_array(array_abs_err, matrix_height_1, matrix_width_2);
    printf("Максимальная абсолютная ошибка: %10.5f\n", x);

    y = MSE(array_result_float, array_convert_result_integer_to_float, matrix_height_1,  matrix_width_2);
    printf("MSE: %10.5f\n", y);

    // Освобождение памяти
    dynamic_array_free_float(array_1, matrix_height_1);
    dynamic_array_free_float(array_2, matrix_height_2);
    dynamic_array_free_float(array_result_float, matrix_height_1);
    dynamic_array_free_integer(array_11, matrix_height_1);
    dynamic_array_free_integer(array_22, matrix_height_2);
    dynamic_array_free_integer(array_result_integer, matrix_height_1);
    dynamic_array_free_float(array_convert_result_integer_to_float, matrix_height_1);
    dynamic_array_free_float(array_abs_err, matrix_height_1);
    return 0;
}