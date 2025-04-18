#include <stdio.h>
#include <pico/stdlib.h>
#include <pololu_3pi_2040_robot.h>

int main()
{
  stdio_init_all();
  display_init();

  display_set_font(font_8x16);
    display_fill(0);
    display_show();
    display_text("");

}
