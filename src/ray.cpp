#include "ray.h"

Vec3 Ray::at(f32 t){
    return origin+direction*t;
}