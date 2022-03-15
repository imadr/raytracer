#pragma once

#include "types.h"
#include <cstdlib>
union Vec3;

struct Frame{
    u32* buffer;
    u32 width;
    u32 height;

    Frame(u32 width, u32 height):
        buffer(buffer),
        width(width),
        height(height){
        buffer = (u32*)calloc(width*height, sizeof(u32));
    }

    void clear();
};

void draw_pixel(Frame* frame, u32 i, u32 j, Vec3 color, u32 samples_per_pixel);