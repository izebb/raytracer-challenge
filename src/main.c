#include "common.h"
#include "tuple.h"
#include "colors.h"
#include "canvas.h"

#define GRAVITY vector(0, -0.1, 0)
#define WIND vector(-0.01, 0, 0)
#define ENV new_environment(GRAVITY, WIND)

typedef struct Projectile {
	tuple position, velocity;
} projectile;

typedef struct Environment {
	tuple gravity, wind;
} environment;

projectile new_projectile(tuple position, tuple velocity)
{
	projectile proj = {position, velocity};

	return proj;
}

environment new_environment(tuple gravity, tuple wind)
{
	environment env = {gravity, wind};
	return env;
}

void print_pos(projectile *proj)
{
	printf("position\n");
	printf("--------------------------------------\n");
	print_tuple(&proj->position);
	printf("\n");
}

void print_vel(projectile *proj)
{
	printf("velocity\n");
	printf("--------------------------------------\n");
	print_tuple(&proj->velocity);
	printf("\n");
}

projectile tick(projectile *proj, environment *env)
{
	tuple position = add(&proj->position, &proj->velocity);
	tuple env_vec = add(&env->gravity, &env->wind);
	tuple velocity = add(&proj->velocity, &env_vec);
	
	return new_projectile(position, velocity); 
}

void run_projectile()
{
	tuple start = point(0, 1, 0);
	
	tuple velocity = vector(1.0, 1.8, 0.0);
	velocity = norm(&velocity);
	velocity = mul(&velocity, 11.25);

	projectile p = new_projectile(start, velocity);
	environment e = ENV;

	const double width = 900;
	const double height = 550;
	
	canvas c = new_canvas(width, height, NULL);
	color red = new_color(1, 0, 0); 
	p = tick(&p, &e);

	while(p.position.y >= 0.0)
	{
		int y = height - p.position.y;
		y = y < 0 ? 0 : y;
		write_pixel(&c, p.position.x, y, red);
		p = tick(&p, &e);
	}

  	int ppm_length = pixel_size(&c) * 10;
	char s[ppm_length];
	canvas_to_ppm(s, &c);

	printf("%s", s);
  	canvas_destroy(&c);
}


int main(void)
{
	run_projectile();
	return 0;
}
