#include "matrix.h"
#include "common.h"
#include "tuple.h"

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

void matrix_insert(matrix_ref m, int row, int col, double value) {
  m->value[matrix_index(m, row, col)] = value;
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

void matrix_multiply(matrix_ref a, matrix_ref b, matrix_ref c) {
  assert(a->cols == b->rows);
  double arr[a->rows][b->cols], sum = 0.0;
  matrix result = new_matrix(a->rows, b->cols, arr);

  for (int i = 0; i < a->rows; ++i) {
    for (int j = 0; j < b->cols; ++j) {
      for (int k = 0; k < b->rows; ++k) {
        sum = sum + matrix_val(a, i, k) * matrix_val(b, k, j);
      }

      matrix_insert(&result, i, j, sum);
      sum = 0;
    }
  }

  *c = result;
}

matrix tuple_to_matrix(tuple *t) {
  double a[4][1];
  matrix m = new_matrix(4, 1, a);

  matrix_insert(&m, 0, 0, t->x);
  matrix_insert(&m, 1, 0, t->y);
  matrix_insert(&m, 2, 0, t->z);
  matrix_insert(&m, 3, 0, t->w);

  return m;
}

tuple matrix_tuple_multiply(matrix_ref m, tuple *t) {
  double new_matrix_arr[4][1];

  matrix mt = tuple_to_matrix(t);
  matrix result = new_matrix(4, 1, new_matrix_arr);

  matrix_multiply(m, &mt, &result);
  double x = matrix_val(&result, 0, 0);
  double y = matrix_val(&result, 1, 0);
  double z = matrix_val(&result, 2, 0);
  double w = matrix_val(&result, 3, 0);

  return new_tuple(x, y, z, w);
}
