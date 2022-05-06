#include "common.h"
#include "colors.h"

color new_color(double red, double green, double blue) {
  color c = {red, green, blue};

  return c;
}

void print_color(color *c) {
  printf("color:[red: %f, green: %f, blue: %f]\n", c->red, c->green, c->blue);
}

color colors_add(color *c, color *d) {
  return new_color(c->red + d->red, c->green + d->green, c->blue + d->blue);
}

color colors_sub(color *c, color *d) {
  return new_color(c->red - d->red, c->green - d->green, c->blue - d->blue);
}

color colors_mul(color *c, color *d) {
  return new_color(c->red * d->red, c->green * d->green, c->blue * d->blue);
}

color color_mul_sca(color *c, double n) {
  return new_color(c->red * n, c->green * n, c->blue * n);
}

bool is_colors_eq(color *c, color *d) {
  return (EQ(c->red, d->red) && EQ(c->blue, d->blue) && EQ(c->green, d->green));
}

int color_value(double c) {
  int value = round(255 * c);

  if (value < 0)
    return 0;
  else if (value > 255)
    return 255;
  else
    return value;
}


void color_str(char* red, char* green, char* blue, color col) {
  sprintf(red, "%d", color_value(col.red));
  sprintf(green, "%d",color_value(col.green));
  sprintf(blue, "%d", color_value(col.blue));
}
