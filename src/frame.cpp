#include "frame.h"
#include "math.h"
#include <cstring>

void draw_pixel(Frame* frame, u32 i, u32 j, Vec3 color, u32 samples_per_pixel){
    frame->buffer[j*frame->width+i] = (0xff<<24)+
        ((u32)(color.x/samples_per_pixel*255)<<16)+
        ((u32)(color.y/samples_per_pixel*255)<<8)+
        ((u32)(color.z/samples_per_pixel*255));
}

void Frame::clear(){
    memset(buffer, 0, width*height*sizeof(u32));
}