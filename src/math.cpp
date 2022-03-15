#include "math.h"

Vec3 operator+(Vec3 a, Vec3 b){
    return Vec3(a.x+b.x, a.y+b.y, a.z+b.z);
}

Vec3 operator-(Vec3 a, Vec3 b){
    return Vec3(a.x-b.x, a.y-b.y, a.z-b.z);
}

Vec3 operator*(f32 s, Vec3 v){
    return Vec3(v.x*s, v.y*s, v.z*s);
}

Vec3 operator*(Vec3 v, f32 s){
    return s*v;
}

Vec3 operator/(Vec3 v, f32 s){
    return (1/s)*v;
}

f32 vec3_dot(Vec3 a, Vec3 b){
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3 vec3_cross(Vec3 a, Vec3 b){
    return Vec3(
        a.y*b.z-a.z*b.y,
        a.z*b.x-a.x*b.z,
        a.x*b.y-a.y*b.x
    );
}

Vec3 vec3_lerp(Vec3 a, Vec3 b, f32 t){
    t = t < 0 ? 0 : t;
    t = t > 1 ? 1 : t;
    return b*t + a*(1-t);
}

Vec3 Vec3::normalize(){
    f32 l = length();
    if(l == 0) return Vec3(0, 0, 0);
    return Vec3(v[0]/l, v[1]/l, v[2]/l);
}

f32 rand_f32(){
    return rand()/(RAND_MAX+1.0);
}