#include "common.h"
#include "matrix.h"

matrix new_matrix(size_t rows, size_t cols, double arr[rows][cols]) {
  double *value = (double *)malloc(sizeof(double) * rows * cols);
  value = &arr[0][0];
  matrix m = {value, rows, cols};

  return m;
}

size_t matrix_index(matrix_ref m, size_t r, size_t c) {
  return m->cols * r + c;
}

double matrix_val(matrix_ref m, size_t r, size_t c) {
  return m->value[matrix_index(m, r, c)];
}

bool matrix_eq(matrix_ref m1, matrix_ref m2) {
  if (m1->rows != m2->rows || m1->cols != m2->cols)
    return false;

  for (size_t r = 0; r < m1->rows; ++r) {
    for (size_t c = 0; c < m1->cols; ++c) {
      if (matrix_val(m1, r, c) != matrix_val(m2, r, c))
        return false;
    }
  }

  return true;
}

void print_matrix(matrix_ref m) {
  for (size_t r = 0; r < m->rows; ++r) {
    for (size_t c = 0; c < m->cols; ++c)
      printf("%f ", matrix_val(m, r, c));

    printf("\n");
  }
}
