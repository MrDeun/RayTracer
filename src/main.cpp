#include <iostream>

#include "color.h"
#include "ray.h"
#include "vec3.h"

color shader_color(const ray& r) {
  vec3 unit_direction = r.direction().unit_vector();
  auto a = 0.5*(unit_direction.y + 1.0);
  return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}



int main(int, char **) {

  auto aspect_ratio = 16.0 / 9.0;
  int IMAGE_WIDTH = 800;

  int IMAGE_HEIGHT = int(IMAGE_WIDTH / aspect_ratio);
  IMAGE_HEIGHT = (IMAGE_HEIGHT < 1) ? 1 : IMAGE_HEIGHT;

  auto focal_lenght = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(IMAGE_WIDTH)/IMAGE_HEIGHT);
  auto camera_center = point3(0,0,0);

  auto viewport_u = vec3(viewport_width,0,0);
  auto viewport_v = vec3(0,-viewport_height,0);

  auto pixel_delta_u = viewport_u/IMAGE_WIDTH;
  auto pixel_delta_v = viewport_v/IMAGE_HEIGHT;

  auto viewport_upper_left = camera_center - vec3(0,0,focal_lenght)  - viewport_u/2 - viewport_v/2;
  auto pixel100_loc = viewport_upper_left + (pixel_delta_u + pixel_delta_v) * 0.5 ;

  std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";
  for (int j = 0; j < IMAGE_HEIGHT; j++) {
    std::clog << "\rScanlines remaining: " << (IMAGE_HEIGHT - j) << std::flush;
    for (int i = 0; i < IMAGE_WIDTH; i++) {
      auto pixel_center = pixel100_loc + (i*pixel_delta_u) + (j*pixel_delta_v);
      auto ray_direction = pixel_center - camera_center;
      ray r(camera_center,ray_direction);

      color pixel_color = shader_color(r);
      write_color(std::cout, pixel_color);
    }
  }
  std::clog << "\rDone.\t\t\t\t\t\n;";
}
