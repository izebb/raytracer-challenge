#include "common.h"
#include "tuple.h"

tuple new_tuple(double x, double y, double z, double w) {
  tuple t = {x, y, z, w};

  return t;
}

void print_tuple(tuple *t) {
  printf("tuple:[x: %f, y: %f, z: %f]\n", t->x, t->y, t->z);
}

bool is_equal(tuple *a, tuple *b) {
  return (EQ(a->x, b->x) && EQ(a->y, b->y) && EQ(a->z, b->z) && EQ(a->w, b->w));
}

tuple point(double x, double y, double z) { return new_tuple(x, y, z, 1.0); }

tuple vector(double x, double y, double z) { return new_tuple(x, y, z, 0.0); }

tuple add_tuples(tuple *a, tuple *b) {
  return new_tuple(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w);
}

tuple add(tuple *a, tuple *b) {
  // result can either be a vector or a point
  assert(a->w + b->w < 2);
  return add_tuples(a, b);
}

tuple sub_tuples(tuple *a, tuple *b) {
  return new_tuple(a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w);
}

tuple sub(tuple *a, tuple *b) {
  // result can either be a vector or a point
  assert((a->w - b->w) > -1);
  return sub_tuples(a, b);
}

tuple negate(tuple *a) {
  tuple t = new_tuple(0, 0, 0, 0);

  return sub_tuples(&t, a);
}

tuple mul(tuple *a, double m) {
  return new_tuple(m * a->x, m * a->y, m * a->z, m * a->w);
}

tuple div_tuple(tuple *a, double m) {
  return new_tuple((a->x) / m, (a->y) / m, (a->z) / m, (a->w) / m);
}

double mag(tuple *a) {
  return sqrt((a->x * a->x) + (a->y * a->y) + (a->z * a->z) + (a->w * a->w));
}

tuple norm(tuple *a) {
  return new_tuple(a->x / mag(a), a->y / mag(a), a->z / mag(a), a->w / mag(a));
}

double dot(tuple *a, tuple *b) {
  return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w));
}

tuple cross(tuple *a, tuple *b) {
  return vector((a->y * b->z) - (a->z * b->y), (a->z * b->x) - (a->x * b->z),
                (a->x * b->y) - (a->y * b->x));
}
