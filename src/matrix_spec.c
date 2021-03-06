#include "common.h"
#include "tuple.h"
#include "matrix.h"

void test_matrix_equality() {

  double arr_1[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}},
         arr_2[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}},
         arr_3[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 3}};

  matrix_ref m1 = matrix_of(4, 4, arr_1);
  matrix_ref m2 = matrix_of(4, 4, arr_2);
  matrix_ref m3 = matrix_of(4, 4, arr_3);

  assert(matrix_eq(m1, m2));
  assert(matrix_eq(m3, m2) != true);

  matrix_destroy(m1);
  matrix_destroy(m2);
  matrix_destroy(m3);

  printf("matrix, should be equal\n");
}

void test_multiplying_matrices() {
  double a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
  double b[4][4] = {{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}};
  double c[4][4] = {{20, 22, 50, 48},
                    {44, 54, 114, 108},
                    {40, 58, 110, 102},
                    {16, 26, 46, 42}};

  matrix_ref ma = matrix_of(4, 4, a);
  matrix_ref mb = matrix_of(4, 4, b);
  matrix_ref expected = matrix_of(4, 4, c);

  matrix_ref result = matrix_multiply(ma, mb);

  assert(matrix_eq(result, expected));
  printf("matrix, should multiply without errors\n");

  matrix_destroy(ma);
  matrix_destroy(mb);
  matrix_destroy(expected);
  matrix_destroy(result);
}

void test_multiplying_matrix_tuple() {
  double arr[4][4] = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
  matrix_ref m = matrix_of(4, 4, arr);

  tuple t = new_tuple(1, 2, 3, 1);
  tuple received = matrix_tuple_multiply(m, &t);
  tuple expected = new_tuple(18, 24, 33, 1);

  assert(is_equal(&received, &expected));

  printf("matrix, should multiply matrix and tuple without error\n");

  matrix_destroy(m);
}

void test_identity_matrix() {
  double arr[4][4] = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};

  matrix_ref mid = identity_matrix(4);
  matrix_ref m = matrix_of(4, 4, arr);
  matrix_ref result = matrix_multiply(m, mid);

  assert(matrix_eq(m, result));

  matrix_destroy(m);
  matrix_destroy(mid);

  printf("matrix, should multiply identity_matrix correctly\n");

  tuple t = new_tuple(1, 2, 3, 1);
  mid = identity_matrix(4);
  tuple received = matrix_tuple_multiply(mid, &t);

  assert(is_equal(&received, &t));
  matrix_destroy(mid);
  
  printf("matrix, should multiply identity_matrix with tuple correctly\n");
}

void test_transpose_matrix() {
  double input_arr[4][4] = {{0, 9, 3, 0}, {9, 8, 0, 8}, {1, 8, 5, 3}, {0, 0, 5, 8}};
  double result_input_arr[4][4] = {{0, 9, 1, 0}, {9, 8, 8, 0}, {3, 0, 5, 5}, {0, 8, 3, 8}};

  matrix_ref input = matrix_of(4, 4, input_arr);
  matrix_ref result = matrix_of(4, 4, result_input_arr);

  matrix_transpose(input);

  assert(matrix_eq(input, result));
  printf("matrix, transpose matrix without error\n");

  matrix_destroy(input);
  matrix_destroy(result);
}

int main(void) {
  test_matrix_equality();
  test_multiplying_matrices();
  test_multiplying_matrix_tuple();
  test_identity_matrix();
  test_transpose_matrix();

  return 0;
}
