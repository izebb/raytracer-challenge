#include "common.h"
#include "matrix.h"

void test_matrix_equality() {

  double arr_1[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}},
         arr_2[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}},
         arr_3[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 3}};

  matrix m1 = new_matrix(4, 4, arr_1);
  matrix m2 = new_matrix(4, 4, arr_2);
  matrix m3 = new_matrix(4, 4, arr_3);

  assert(matrix_eq(&m1, &m2));
  assert(matrix_eq(&m3, &m2) != true);

  printf("matrics, should be equal\n");
}

void test_multiplying_matrices() {
  double a[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}};
  double b[][4] = {{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}};
  double c[][4] = {{20, 22, 50, 48},
                   {44, 54, 114, 108},
                   {40, 58, 110, 102},
                   {16, 26, 46, 42}};
  double d[4][4];

  matrix ma = new_matrix(4, 4, a), mb = new_matrix(4, 4, b),
         expected = new_matrix(4, 4, c), result = new_matrix(4, 4, d);
  matrix_multiply(&ma, &mb, &result);
  assert(matrix_eq(&result, &expected));
  printf("matrices, should multiply without errors\n");
}

void test_multiplying_matrix_tuple() {
  double arr_[][4] = {{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}};
}

int main(void) {
  test_matrix_equality();
  test_multiplying_matrices();

  return 0;
}
