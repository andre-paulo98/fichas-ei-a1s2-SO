#ifndef MATRIZ_H
#define MATRIZ_H

float** matrix_new(int n_rows, int n_cols);
void matrix_delete(float** matrix);
void matrix_fill(float** matrix, float value, int n_rows, int n_cols);
#endif
