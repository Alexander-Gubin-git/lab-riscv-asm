#include <stdio.h>

#define N 5
#define M 6

void fun(int matrix[M][N], int *num_of_pos, int *num_of_neg) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] > 0) {
				(*num_of_pos)++;
			}
			else if (matrix[i][j] < 0) {
				(*num_of_neg)++;
			}
		}
	}
}

int main(){
	int num_of_pos = 0;
	int num_of_neg = 0;

	int matrix[M][N] = {
	{-18, -14, 24, 22, 23},
	{29, -18, 21, -18, -20},
	{-9, 28, 30, 13, -3},
	{-25, 22, 30, -24, 14},
	{-27, 4, -21, -10, 16},
	{-22, -8, -27, -3, 11}
	};

	fun(matrix, &num_of_pos, &num_of_neg);

	printf("Number of positive numbers: %d\n", num_of_pos);
	printf("Number of negative numbers: %d\n", num_of_neg);

	return 0;
}