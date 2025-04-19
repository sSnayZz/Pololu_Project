#include <stdio.h>
#include <pico/stdlib.h>
#include "../pololu_3pi_2040_robot/include/pololu_3pi_2040_robot.h"

rgb_color colors[6];

int main()
{
    stdio_init_all();
    rgb_leds_init();
    motors_init();
    bump_sensors_calibrate();

    while(1)
    {
        bump_sensors_read();
        if (bump_sensor_left_is_pressed() && bump_sensor_right_is_pressed())
        {
            // Les deux bumpers sont pressés : active les deux moteurs
            motors_set_speeds(1000, 1000); // Active les deux moteurs
            colors[0] = (rgb_color){ 0xFF, 0xFF, 0xFF };  // blanc
            colors[1] = (rgb_color){ 0xFF, 0xFF, 0xFF };  // blanc
            colors[2] = (rgb_color){ 0xFF, 0xFF, 0xFF };  // blanc
            colors[3] = (rgb_color){ 0xFF, 0xFF, 0xFF };  // blanc
            colors[4] = (rgb_color){ 0xFF, 0xFF, 0xFF };  // blanc
            colors[5] = (rgb_color){ 0xFF, 0xFF, 0xFF };  // blanc
            rgb_leds_write(colors, 6, 8);
        }
        else if (bump_sensor_left_is_pressed())
        {
            // Seulement le bumper gauche est pressé
            motors_set_speeds(1000, 0); // Active le moteur gauche
            colors[0] = (rgb_color){ 0xFF, 0xA5, 0x00 };  // orange
            colors[1] = (rgb_color){ 0xFF, 0xA5, 0x00 };  // orange
            colors[2] = (rgb_color){ 0xFF, 0xA5, 0x00 };  // orange
            colors[3] = (rgb_color){ 0x00, 0x00, 0x00 };  // 0
            colors[4] = (rgb_color){ 0x00, 0x00, 0x00 };  // 0
            colors[5] = (rgb_color){ 0x00, 0x00, 0x00 };  // 0
            rgb_leds_write(colors, 6, 8);
        }
        else if (bump_sensor_right_is_pressed())
        {
            // Seulement le bumper droit est pressé
            motors_set_speeds(0, 1000); // Active le moteur droit
            colors[0] = (rgb_color){ 0x00, 0x00, 0x00 };  // 0
            colors[1] = (rgb_color){ 0x00, 0x00, 0x00 };  // 0
            colors[2] = (rgb_color){ 0x00, 0x00, 0x00 };  // 0
            colors[3] = (rgb_color){ 0x00, 0x40, 0x40 };  // cyan
            colors[4] = (rgb_color){ 0x00, 0x40, 0x40 };  // cyan
            colors[5] = (rgb_color){ 0x00, 0x40, 0x40 };  // cyan
            rgb_leds_write(colors, 6, 8);
        }
        else
        {
            // Aucun bumper n'est pressé
            motors_set_speeds(0, 0); // Arrête les moteurs
            rgb_leds_write(colors, 6, 0); // Éteint les LEDs
        }
    }
}