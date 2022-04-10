#include "window.h"
#include "types.h"
#include "math.h"
#include "frame.h"
#include "hit.h"
#include "raytracer.h"

#include <vector>
#include <memory>

using std::make_shared;

Raytracer raytracer;

void keyboard_callback(u32 keycode, KeyState key_state){
    if(keycode == KEY_ESCAPE && key_state == RELEASED){
        window_close();
    }
    if(keycode == KEY_SPACE && key_state == RELEASED){
        raytracer.trace();
    }
}

i32 main(){
    u32 width = 700;
    u32 height = 500;
    Frame frame = Frame(width, height);

    raytracer = Raytracer(&frame);

    raytracer.hittables.push_back(make_shared<Sphere>(Sphere(Vec3(0, 0, -1), 0.5)));
    raytracer.hittables.push_back(make_shared<Sphere>(Sphere(Vec3(0, -100.5, -1), 100)));

    u8 err = window_create("raytracer", width, height, &frame);
    if(err){
        return 1;
    }

    raytracer.trace();

    window_set_keyboard_callback(keyboard_callback);
    while(window_event()){
    }

    return 0;
}