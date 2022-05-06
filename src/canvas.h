typedef struct Canvas {
  double width, height;
  color *pixels;
} canvas;

canvas new_canvas(double width, double height, const color* c);
void canvas_destroy(canvas *c);

void write_pixel(canvas *c, int x, int y, color clr);

color pixel_at(const canvas *c, int x, int y);

int pixel_size(const canvas *c);

void canvas_to_ppm(char *ppm, const canvas *c); 

