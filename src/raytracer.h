#pragma once

#include <memory>
#include <vector>
#include "math.h"
struct Frame;
struct Hittable;
struct Ray;

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::static_pointer_cast;

struct Raytracer{
    Frame* frame;
    vector<shared_ptr<Hittable>> hittables;
    Vec3 camera_pos = Vec3(0, 0, 0);

    u32 max_depth = 50;
    u32 samples_per_pixel = 10;

    Raytracer(){}
    Raytracer(Frame* frame): frame(frame){}

    Vec3 ray_color(Ray r, u32 depth);
    void trace();
};