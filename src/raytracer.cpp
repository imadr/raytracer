#include "raytracer.h"
#include <cstdio>
#include "frame.h"
#include "hit.h"
#include "ray.h"
#include "time.h"
#include "types.h"
#include "window.h"

Vec3 Raytracer::ray_color(Ray r, u32 depth){
    Hit hit;

    if(depth >= max_depth){
        return Vec3(0, 0, 0);
    }

    f32 t_max = 1000;
    f32 t_min = 0.01;

    f32 closest_so_far = t_max;
    bool hit_anything = false;
    for(auto hittable: hittables){
        if((*hittable).hit(r, t_min, closest_so_far, &hit)){
            hit_anything = true;
            closest_so_far = hit.ray_t;
        }
    }
    if(hit_anything){
        Vec3 target = hit.point+hit.normal+rand_point_unit_sphere();
        return 0.5*ray_color(Ray(hit.point, target-hit.point), depth+1);
        // return (hit.normal+Vec3(1, 1, 1))/2;
        // return Vec3(hit.depth, hit.depth, hit.depth);
    }

    Vec3 ray_dir = r.direction.normalize();
    f32 t = (ray_dir.y+1)*0.5;
    return vec3_lerp(Vec3(1.0, 1.0, 1.0), Vec3(0.5, 0.7, 1.0), t);
}

void Raytracer::trace(){
    printf("Starting raytracing\n");
    u64 start_time = get_time();
    f32 aspect_ratio = (f32)frame->width/(f32)frame->height;

    f32 viewport_height = 2.0;
    f32 viewport_width = viewport_height*aspect_ratio;
    f32 focal_length = 1.0;

    Vec3 horizontal = Vec3(viewport_width, 0, 0);
    Vec3 vertical = Vec3(0, viewport_height, 0);

    Vec3 lower_left_corner = camera_pos-horizontal*0.5-vertical*0.5-Vec3(0, 0, focal_length);
    u32 count = 0;
    u32 total_count = frame->height*frame->width;
    frame->clear();
    for(u32 j = 0; j < frame->height; j++){
        for(u32 i = 0; i < frame->width; i++){
            Vec3 color;
            for(u32 s = 0; s < samples_per_pixel; s++){
                f32 u = (f32)(i+rand_f32())/frame->width;
                f32 v = 1-(f32)(j+rand_f32())/frame->height;
                Ray r = Ray(camera_pos, lower_left_corner+horizontal*u+vertical*v-camera_pos);
                color += ray_color(r, 0);
            }
            draw_pixel(frame, i, j, color, samples_per_pixel);
            count++;
            float progress = (float)count/total_count*100;
            if(fmod(progress, 10) == 0){
                window_redraw();
            }
        }
    }
    window_redraw();
    printf("Finished raytracing in %fs\n", ((float)get_time()-start_time)/1000000);
}
