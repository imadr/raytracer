#pragma once

#include "math.h"
#include "types.h"
struct Ray;

struct Hit{
    Vec3 point;
    Vec3 normal;
    f32 ray_t;
    f32 depth;

    Hit(){
        point = Vec3();
        normal = Vec3();
        ray_t = 0;
    }

    Hit(Vec3 point, Vec3 normal, f32 ray_t): point(point),
        normal(normal),
        ray_t(ray_t){}
};

struct Hittable{
    virtual bool hit(Ray ray, Hit* hit) = 0;
};

struct Sphere: Hittable{
    Vec3 center;
    f32 radius;

    Sphere(Vec3 center, f32 radius): center(center), radius(radius){}

    virtual bool hit(Ray ray, Hit* hit);
};