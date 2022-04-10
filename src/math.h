#pragma once

#include "types.h"

#include <cmath>

#define PI 3.14159265358979323846264338327950288
#define PI2 6.28318530717958647692528676655900576

union Vec3{
    struct{
        f32 x, y, z;
    };
    f32 v[3];

    Vec3(): x(0), y(0), z(0){}
    Vec3(float x, float y, float z): x(x), y(y), z(z){}

    f32 operator[](u32 i){
        return v[i];
    }

    Vec3 operator=(Vec3 other){
        v[0] = other.x;
        v[1] = other.y;
        v[2] = other.z;
        return *this;
    }

    Vec3 operator-(){
        return Vec3(-v[0], -v[1], -v[2]);
    }

    Vec3 operator+=(Vec3 other){
        v[0] += other.v[0];
        v[1] += other.v[1];
        v[2] += other.v[2];
        return *this;
    }

    f32 length(){
        return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
    }

    Vec3 normalize();
};

Vec3 vec3_lerp(Vec3 a, Vec3 b, f32 t);
Vec3 vec3_cross(Vec3 a, Vec3 b);
f32 vec3_dot(Vec3 a, Vec3 b);
Vec3 operator/(Vec3 v, f32 s);
Vec3 operator*(Vec3 v, f32 s);
Vec3 operator*(f32 s, Vec3 v);
Vec3 operator-(Vec3 a, Vec3 b);
Vec3 operator+(Vec3 a, Vec3 b);
f32 rad(f32 deg);
f32 rand_f32();
Vec3 rand_point_unit_sphere();