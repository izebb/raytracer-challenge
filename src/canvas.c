#include "common.h"
#include "colors.h"
#include "canvas.h"

size_t arr_index(const canvas *c, size_t x, size_t y) { 
	return y * (size_t)c->width + x; 
}

canvas new_canvas(double width, double height, const color *initial_color) {
  canvas c = {width, height};
  c.pixels = malloc(sizeof(color) * pixel_size(&c));

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
		if(initial_color == NULL)
			c.pixels[arr_index(&c, x, y)] = new_color(0, 0, 0);
		else
			c.pixels[arr_index(&c, x, y)] = *initial_color;
    }
  }

  return c;
}

void canvas_destroy(canvas *c)
{
	free(c->pixels);
}


int pixel_size(const canvas *c) { return (int)c->width * (int)c->height; }

void write_pixel(canvas *c, int x, int y, color px) { 
	c->pixels[arr_index(c, x, y)] = px;
}

color pixel_at(const canvas *c, int x, int y) { 
	return c->pixels[arr_index(c, x, y)]; 
}

void add_spacing(char* c, char *d, int *k) {
	if((*k + strlen(d)) < 70)
	{
		if(*k > 0) {
			*k += 1;
			strcat(c, " ");
		}

		*k += strlen(d);
	}else {
		strcat(c, "\n");
		*k = 1;
	}
}

void canvas_to_ppm(char *ppm, const canvas *c) {
  const int max_color = 255;

  sprintf(ppm, "P3\n%d %d\n%d\n", (int)c->width, (int)c->height, max_color);

  for (int y = 0; y < c->height; ++y) {
  	int k = 0;
    for (int x = 0; x < c->width; ++x) {
		char red[4], green[4], blue[4];
		color_str(red, green, blue, pixel_at(c, x, y));

		add_spacing(ppm, red, &k);
		strcat(ppm, red);
		add_spacing(ppm, green, &k);
		strcat(ppm, green);
		add_spacing(ppm, green, &k);
		strcat(ppm, blue);
    }

	strcat(ppm, "\n");
  }
}

