#pragma once

#include "types.h"
#include "math.h"

struct Ray{
    Vec3 origin;
    Vec3 direction;

    Ray(Vec3 origin, Vec3 direction): origin(origin), direction(direction){}

    Vec3 at(f32 t);
};