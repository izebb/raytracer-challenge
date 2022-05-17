#define matrix_ref matrix *
typedef struct Matrix {
  double *value;
  size_t rows, cols;
} matrix;

matrix new_matrix(size_t rows, size_t cols, double arr[rows][cols]);

bool matrix_eq(matrix_ref matrix_1, matrix_ref matrix_2);

size_t matrix_index(matrix_ref m, size_t x, size_t y);

double matrix_val(matrix_ref m, size_t r, size_t c);

void matrix_insert(matrix_ref m, int row, int col, double value);

void print_matrix(matrix_ref m);

void matrix_multiply(matrix_ref a, matrix_ref b, matrix_ref result);
