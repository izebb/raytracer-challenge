typedef struct Tuple {
  double x, y, z, w;
} tuple;

tuple new_tuple(double x, double y, double z, double w);

void print_tuple(tuple *t);
bool is_equal(tuple *a, tuple *b);

tuple point(double x, double y, double z);

tuple vector(double x, double y, double z);

tuple add_tuples(tuple *a, tuple *b);
tuple add(tuple *a, tuple *b);

tuple sub_tuples(tuple *a, tuple *b);
tuple sub(tuple *a, tuple *b);

tuple mul(tuple *a, double m);
tuple div_tuple(tuple *a, double m);

tuple negate(tuple *a);

double mag(tuple *a);

tuple norm(tuple *a);

double dot(tuple *a, tuple *b);
tuple cross(tuple *a, tuple *b);
