#define matrix_ref matrix *

typedef struct Matrix {
  double *value;
  size_t rows, cols;
} matrix;

matrix_ref matrix_of(size_t rows, size_t cols, double arr[rows][cols]);

matrix_ref new_matrix(size_t rows, size_t cols);

void matrix_destroy(matrix_ref m);

bool matrix_eq(matrix_ref matrix_1, matrix_ref matrix_2);

size_t matrix_index(matrix_ref m, size_t x, size_t y);

double matrix_val(matrix_ref m, size_t r, size_t c);

void matrix_insert(matrix_ref m, int row, int col, double value);

void print_matrix(matrix_ref m);

matrix_ref matrix_multiply(matrix_ref a, matrix_ref b);

tuple matrix_tuple_multiply(matrix_ref m, tuple *t);

matrix_ref tuple_to_matrix(tuple *t);

matrix_ref identity_matrix(size_t size);

void matrix_transpose(matrix_ref m);
