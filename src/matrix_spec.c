#include "common.h"
#include "matrix.h"

void test_matrix_equality()
{

	double matrix_1[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	
	double matrix_2[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};

	assert(matrix_eq(&matrix_1[0][0], &matrix_2[0][0], 4, 4));
}

int main(void)
{
	test_matrix_equality();
	return 0;
}
