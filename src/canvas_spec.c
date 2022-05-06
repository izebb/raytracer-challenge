#include "common.h"
#include "colors.h"
#include "canvas.h"

void should_create_canvas() {
  canvas c = new_canvas(10, 20, NULL);
  assert(EQ(c.width, 10));
  assert(EQ(c.height, 20));

  color px;
  color expected_color = new_color(0, 0, 0);

  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 10; j++)
      px = pixel_at(&c, i, j); is_colors_eq(&px, &expected_color);

  printf("canvas is created\n");
  canvas_destroy(&c);
}

void should_get_write_pixel() {
  canvas c = new_canvas(10, 20, NULL);
  color red = new_color(1, 0, 0);

  write_pixel(&c, 2, 3, red);
  color expected = pixel_at(&c, 2, 3);

  print_color(&expected);
  assert(is_colors_eq(&expected, &red));
  printf("pixel is written successfully\n");
  canvas_destroy(&c);
}

void should_create_file() {
  canvas c = new_canvas(5, 3, NULL);
  color c1 = new_color(1.5, 0, 0);
  color c2 = new_color(0, 0.5, 0);
  color c3 = new_color(-0.5, 0, 1);

  write_pixel(&c, 0, 0, c1);
  write_pixel(&c, 2, 1, c2);
  write_pixel(&c, 4, 2, c3);

  int ppm_length = pixel_size(&c) * 10;
  char output_1[ppm_length], output_2[ppm_length]; 
  canvas_to_ppm(output_1, &c);
  char *expected = "P3\n"
                   "5 3\n"
				   "255\n"
                   "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
                   "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
                   "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
  printf("%s\n", output_1);
  assert(strcmp(expected, output_1) == 0);
  canvas_destroy(&c);

  color c4 = new_color(1, 0.8, 0.6);
  c = new_canvas(10, 2, &c4);

  canvas_to_ppm(output_2, &c);
  expected = "P3\n10 2\n255\n"
             "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
             "153 255 204 153 255 204 153 255 204 153 255 204 153\n"
             "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
             "153 255 204 153 255 204 153 255 204 153 255 204 153\n";

 printf("%s\n", output_2);
 assert(strcmp(expected, output_2) == 0);
 printf("ppm string generated\n");
 canvas_destroy(&c);
}

int main(void) {
	should_create_canvas();
  	should_get_write_pixel();
	should_create_file();

  return 0;
}
