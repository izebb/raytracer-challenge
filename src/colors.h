typedef struct Color {
  double red, green, blue;
} color;

void print_color(color *c);

color new_color(double red, double green, double blue);

color colors_add(color *c, color *d);

color colors_sub(color *c, color *d);

color colors_mul(color *c, color *d);

color color_mul_sca(color *c, double n);

bool is_colors_eq(color *c, color *d);

int color_value(double c);

void color_str(char* red, char* green, char* blue, color col); 
