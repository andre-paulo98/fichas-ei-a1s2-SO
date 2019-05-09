#include <stdlib.h>
#include "debug.h"


float** matrix_new(int n_rows, int n_cols){

	float *data = malloc(sizeof (float) * n_cols * n_rows);
	if(data == NULL){
		return NULL;
	}

	float **m = malloc(sizeof (float*) * n_rows);
	if(m == NULL){
		return NULL;
	}

	for(int i = 0; i < n_rows; i++){
		m[i] = &data[i * n_cols];
	}

	return m;

}

void matrix_delete(float** matrix){
	if(matrix == NULL){
		return;
	}
	free(matrix[0]);
	free(matrix);
}

void matrix_fill(float** matrix, float value, int n_rows, int n_cols){
	for(int i = 0; i < n_rows; i++){
		for(int j = 0; j < n_cols; j++){
			matrix[i][j] = value;
		}
	}
}