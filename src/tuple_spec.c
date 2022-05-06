#include "common.h"
#include "tuple.h"

void tuple_is_a_point() {
  tuple a = new_tuple(4.3, -4.2, 3.1, 1.0);

  assert(a.x == 4.3);
  assert(a.y == -4.2);
  assert(a.z == 3.1);
  assert(a.w == 1.0);

  printf("a is a point\n");
}

void tuple_is_a_vector() {
  tuple a = new_tuple(4.3, -4.2, 3.1, 0.0);

  assert(a.x == 4.3);
  assert(a.y == -4.2);
  assert(a.z == 3.1);
  assert(a.w == 0.0);

  printf("a is a vector\n");
}

void point_is_created() {
  tuple p = point(4, -4, 3);
  tuple a = new_tuple(4, -4, 3, 1);

  assert(is_equal(&p, &a));

  printf("point is created\n");
}

void vector_is_created() {
  tuple p = vector(4, -4, 3);
  tuple a = new_tuple(4, -4, 3, 0);

  assert(is_equal(&p, &a));

  printf("vector is created\n");
}

void should_add_tuples() {
  tuple a = new_tuple(3, -2, 5, 1);
  tuple b = new_tuple(-2, 3, 1, 0);

  tuple sum = add(&a, &b);
  tuple expected = new_tuple(1, 1, 6, 1);

  assert(is_equal(&sum, &expected));
  printf("tuples are added\n");
}

void should_subtract_points() {
  tuple p1 = point(3, 2, 1);
  tuple p2 = point(5, 6, 7);

  tuple diff = sub(&p1, &p2);
  tuple expected = vector(-2, -4, -6);

  assert(is_equal(&diff, &expected));
  printf("substracting two points, yeilds a vector\n");
}

void should_subtract_vectors() {
  tuple p = vector(3, 2, 1);
  tuple v = vector(5, 6, 7);

  tuple diff = sub(&p, &v);
  tuple expected = vector(-2, -4, -6);

  assert(is_equal(&diff, &expected));
  printf("substracting two vectors, yeilds a vector\n");
}

void should_subtract_point_and_vector() {
  tuple p = point(3, 2, 1);
  tuple v = vector(5, 6, 7);

  tuple diff = sub(&p, &v);
  tuple expected = point(-2, -4, -6);

  assert(is_equal(&diff, &expected));
  printf("substracting a point and a vector, yeilds a point\n");
}

void should_negate_a_vector() {
  tuple v = vector(1, -2, 3);
  tuple neg = negate(&v);
  tuple expected = vector(-1, 2, -3);

  assert(is_equal(&neg, &expected));
  printf("vector should be negated\n");
}

void should_negate_a_tuple() {
  tuple t = new_tuple(1, -2, 3, -4);
  tuple neg = negate(&t);
  tuple expected = new_tuple(-1, 2, -3, 4);

  assert(is_equal(&neg, &expected));
  printf("tuple should be negated\n");
}

void should_multilply_tuple_by_a_scalar() {
  tuple t = new_tuple(1, -2, 3, -4);
  tuple new_t = mul(&t, 3.5);

  tuple expected = new_tuple(3.5, -7, 10.5, -14);
  assert(is_equal(&new_t, &expected));
  printf("should multiply by scalar\n");
}

void should_multilply_tuple_by_a_fraction() {
  tuple t = new_tuple(1, -2, 3, -4);
  tuple new_t = mul(&t, 0.5);

  tuple expected = new_tuple(0.5, -1, 1.5, -2);
  assert(is_equal(&new_t, &expected));
  printf("should multiply by fraction\n");
}

void should_divide_tuple_by_a_scalar() {
  tuple t = new_tuple(1, -2, 3, -4);
  tuple new_t = div_tuple(&t, 2);

  tuple expected = new_tuple(0.5, -1, 1.5, -2);
  assert(is_equal(&new_t, &expected));
  printf("should multiply by fraction\n");
}

void should_get_magnitude_of_vector() {
  tuple v = vector(1, 0, 0);
  assert(mag(&v) == 1);

  v = vector(0, 1, 0);
  assert(mag(&v) == 1);

  v = vector(0, 0, 1);
  assert(mag(&v) == 1);

  v = vector(0, 0, 1);
  assert(mag(&v) == 1);

  v = vector(1, 2, 3);
  assert(mag(&v) == sqrt(14));

  v = vector(-1, -2, -3);
  assert(mag(&v) == sqrt(14));

  printf("should gets the magnitude of vector\n");
}

void should_normalize_vector() {
  tuple v = vector(4, 0, 0);
  tuple v_norm = norm(&v);
  tuple expected = vector(1, 0, 0);

  assert(is_equal(&v_norm, &expected));
  printf("should normalize vector\n");
}

void should_get_dot_products() {
  tuple a = vector(1, 2, 3);
  tuple b = vector(2, 3, 4);

  assert(dot(&a, &b) == 20);
  printf("should return dot products\n");
}

void should_get_cross_products() {
  tuple a = vector(1, 2, 3);
  tuple b = vector(2, 3, 4);

  tuple c = cross(&a, &b);
  tuple expected = vector(-1, 2, -1);

  assert(is_equal(&c, &expected));

  c = cross(&b, &a);
  expected = vector(1, -2, 1);

  assert(is_equal(&c, &expected));
  printf("should return cross products\n");
}

int main() {
  tuple_is_a_point();
  tuple_is_a_vector();

  point_is_created();
  vector_is_created();

  should_add_tuples();

  should_subtract_points();
  should_subtract_vectors();
  should_subtract_point_and_vector();

  should_negate_a_vector();
  should_negate_a_tuple();

  should_multilply_tuple_by_a_scalar();
  should_multilply_tuple_by_a_fraction();

  should_get_magnitude_of_vector();

  should_normalize_vector();

  should_get_dot_products();
  should_get_cross_products();

  return 0;
}
