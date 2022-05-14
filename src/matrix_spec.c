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

int main(void) {
  test_matrix_equality();
  return 0;
}
