#include <stdio.h>
#include <pico/stdlib.h>
#include "../pololu_3pi_2040_robot/include/pololu_3pi_2040_robot.h"

rgb_color colors[5];

int main()
{
    stdio_init_all();
    rgb_leds_init();
    motors_init();
    bump_sensors_calibrate();

    while(1)
    {
        bump_sensors_read();
        while (bump_sensor_left_is_pressed())
        {
            motors_set_speeds(500, 0);
            colors[0] = (rgb_color){ 0x40, 0x00, 0x00 };  // red
            colors[1] = (rgb_color){ 0x00, 0x40, 0x00 };  // green
            colors[2] = (rgb_color){ 0x00, 0x00, 0x40 };  // blue
            rgb_leds_write(colors, 5, 31);
        }
        while (bump_sensor_right_is_pressed())
        {
            motors_set_speeds(0, 1000);
            colors[3] = (rgb_color){ 0x40, 0x00, 0x00 };  // red
            colors[4] = (rgb_color){ 0x00, 0x40, 0x00 };  // green
            colors[5] = (rgb_color){ 0x00, 0x00, 0x40 };  // blue
            rgb_leds_write(colors, 5, 31);
        }
        motors_set_speeds(0, 0);
        rgb_leds_write(colors, 5, 0);
    }
}