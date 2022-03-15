#include "hit.h"
#include <math.h>
#include "ray.h"

bool Sphere::hit(Ray ray, Hit* hit){
    Vec3 rc = ray.origin-center;
    f32 a = vec3_dot(ray.direction, ray.direction);
    f32 b = 2*vec3_dot(ray.direction, rc);
    f32 c = vec3_dot(rc, rc)-radius*radius;
    f32 delta = b*b-4*a*c;
    if(delta < 0) return 0;

    f32 root = (-b-sqrt(delta))/(2*a);
    if(root < 0) return 0;

    hit->ray_t = root;
    hit->point = ray.at(hit->ray_t);
    hit->normal = (hit->point-center).normalize();
    hit->depth = (hit->point-ray.origin).length();
    return 1;
}