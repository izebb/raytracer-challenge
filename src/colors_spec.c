#include "colors.h"
#include "common.h"

void should_create_new_new_color() {
  color c = new_color(-0.5, 0.4, 1.7);

  assert(c.red == -0.5);
  assert(c.green == 0.4);
  assert(c.blue == 1.7);

  printf("should return a new color\n");
}

void should_add_colors() {
  color c = new_color(0.9, 0.6, 0.75), d = new_color(0.7, 0.1, 0.25);
  color sum = colors_add(&c, &d);
  color expected = new_color(1.6, 0.7, 1.0);

  assert(is_colors_eq(&sum, &expected));
  printf("colors added\n");
}

void should_subtract_colors() {
  color c = new_color(0.9, 0.6, 0.75), d = new_color(0.7, 0.1, 0.25);
  color diff = colors_sub(&c, &d);
  color expected = new_color(0.2, 0.5, 0.5);

  assert(is_colors_eq(&diff, &expected));
  printf("colors substracted\n");
}

void should_multiply_colors() {
  color c = new_color(1, 0.2, 0.4), d = new_color(0.9, 1, 0.1);
  color mul = colors_mul(&c, &d);
  color expected = new_color(0.90, 0.20, 0.040);

  assert(is_colors_eq(&mul, &expected));
  printf("colors muliplied\n");
}

void should_multiply_colors_by_scalar_value() {
  color c = new_color(1, 0.2, 0.4);
  color result = color_mul_sca(&c, 2);
  color expected = new_color(2, 0.4, 0.8);

  assert(is_colors_eq(&result, &expected));
  printf("colors are multiplied\n");
}

int main() {
  should_create_new_new_color();

  should_add_colors();
  should_subtract_colors();
  should_multiply_colors();
  should_multiply_colors();

  should_add_colors();
  should_multiply_colors_by_scalar_value();
  should_subtract_colors();
  should_multiply_colors_by_scalar_value();

  return 0;
}
