#include <stdio.h>

#define N 5
#define M 6

void fun(int matrix[N][M], int *num_of_pos, int *num_of_neg) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
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

	int matrix[N][M] = {
	{-18, -14, 24, 22, 23, -22},
	{29, -18, 21, -18, -20, -8},
	{-9, 28, 30, 13, -3, -3},
	{-25, 22, 30, -24, 14, -27},
	{-27, 4, -21, -10, 16, 11}
	};

	fun(matrix, &num_of_pos, &num_of_neg);

	printf("Number of positive numbers: %d\n", num_of_pos);
	printf("Number of negative numbers: %d\n", num_of_neg);

	return 0;
}