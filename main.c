#include "pico/multicore.h"
#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "trivia.h"

#include "neopixel.pio.h"

#define LCD_MASK (0x1C3FC000)

bool last_inputs[4];
bool inputs[4];

uint get_lcd_mask(uint data, bool rs, bool rw, bool en) {
  uint mask = (data & 0xFF) << 14;
  
  if (rs) {
    mask |= (1 << 26);
  }
  
  if (rw) {
    mask |= (1 << 27);
  }
  
  if (en) {
    mask |= (1 << 28);
  }
  
  return mask;
}

void lcd_send(uint data, bool rs) {
  gpio_put_masked(LCD_MASK, get_lcd_mask(data, rs, false, true));
  sleep_ms(1);
  
  gpio_put(28, false);
  sleep_ms(2);
}

void lcd_hispanify(void) {
  lcd_send(0x40, false);
  
  const unsigned char font[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    
    0x02, 0x04, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x00,
    0x02, 0x04, 0x0E, 0x11, 0x1F, 0x10, 0x0E, 0x00,
    0x02, 0x04, 0x04, 0x0C, 0x04, 0x04, 0x0E, 0x00,
    0x02, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00,
    0x02, 0x04, 0x11, 0x11, 0x11, 0x13, 0x0D, 0x00,
    
    0x04, 0x00, 0x04, 0x08, 0x10, 0x11, 0x0E, 0x00,
  };
  
  for (uint i = 0; i < 8 * 8; i++) {
    lcd_send(font[i], true);
  }
  
  lcd_send(0x80, false);
}

void lcd_clear(void) {
  lcd_send(0x01, false);
}

void lcd_home(void) {
  lcd_send(0x02, false);
}

void lcd_goto(uint x, uint y) {
  lcd_send(0x80 + (x + y * 64), false);
}

void lcd_write(const char *text) {
  while (*text) {
    lcd_send(*text, true);
    text++;
  }
}

bool input_pressed(uint input) {
  return (inputs[input] && !last_inputs[input]);
}

void input_refresh(void) {
  for (uint i = 10; i < 14; i++) {
    last_inputs[i - 10] = inputs[i - 10];
    inputs[i - 10] = !gpio_get(i);
  }
}

uint trivia_write(const char *text) {
  uint count = 0;
  
  while (*text) {
    if ((unsigned char)(*text) == 0xC2) {
      text++;
      
      if ((unsigned char)(*text) == 0xBF) {
        lcd_send(6, true);
      }
    } else if ((unsigned char)(*text) == 0xC3) {
      text++;
      
      if ((unsigned char)(*text) == 0xB1) {
        lcd_send(0, true);
      } else if ((unsigned char)(*text) == 0xA1) {
        lcd_send(1, true);
      } else if ((unsigned char)(*text) == 0xA9) {
        lcd_send(2, true);
      } else if ((unsigned char)(*text) == 0xAD) {
        lcd_send(3, true);
      } else if ((unsigned char)(*text) == 0xB3) {
        lcd_send(4, true);
      } else if ((unsigned char)(*text) == 0xBA) {
        lcd_send(5, true);
      }
    } else {
      lcd_send(*text, true);
    }
    
    count++, text++;
    sleep_ms(20);
  }
  
  return count;
}

void trivia_show_option(const char *text) {
  lcd_send(0x0D, false);
  lcd_goto(0, 1);
  
  uint count = trivia_write(text);
  
  lcd_send(0x0C, false);
  sleep_ms(1000);
  
  lcd_send(0x0D, false);
  lcd_goto(0, 1);
  
  while (count--) {
    lcd_send(' ', true);
    sleep_ms(20);
  }
  
  lcd_send(0x0C, false);
}

bool trivia_show(const trivia_t trivia) {
  lcd_send(0x0D, false);
  lcd_clear();
  
  trivia_write(trivia.text);
  
  lcd_send(0x0C, false);
  sleep_ms(2000);
  
  for (uint i = 0; i < 4; i++) {
    trivia_show_option(trivia.options_long[i]);
  }
  
  sleep_ms(2000);
  
  /* TODO: Show options in short form, all uppercase! */
  
  /* TODO: Read input and return true or false. */
  
  /* TODO: Change light colors depending on state (set up FIFO too). */
  
  return false;
}

void core1_main(void) {
  const int led_coords[60] = {500, 263, 503, 634, 506, 954, 510, 1249, 513, 1527, 516, 1793, 519, 2049, 522, 2297, 526, 2539, 529, 2776, 532, 3007, 535, 3234, 538, 3457, 542, 3677, 545, 3893, -545, 3893, -542, 3677, -538, 3457, -535, 3234, -532, 3007, -529, 2776, -526, 2539, -522, 2297, -519, 2049, -516, 1793, -513, 1527, -510, 1249, -506, 954, -503, 634, -500, 263};
  const int gamma_table[256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 22, 22, 23, 23, 24, 25, 25, 26, 26, 27, 28, 28, 29, 30, 30, 31, 32, 33, 33, 34, 35, 35, 36, 37, 38, 39, 39, 40, 41, 42, 43, 43, 44, 45, 46, 47, 48, 49, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 73, 74, 75, 76, 77, 78, 79, 81, 82, 83, 84, 85, 87, 88, 89, 90, 91, 93, 94, 95, 97, 98, 99, 100, 102, 103, 105, 106, 107, 109, 110, 111, 113, 114, 116, 117, 119, 120, 121, 123, 124, 126, 127, 129, 130, 132, 133, 135, 137, 138, 140, 141, 143, 145, 146, 148, 149, 151, 153, 154, 156, 158, 159, 161, 163, 165, 166, 168, 170, 172, 173, 175, 177, 179, 181, 182, 184, 186, 188, 190, 192, 194, 196, 197, 199, 201, 203, 205, 207, 209, 211, 213, 215, 217, 219, 221, 223, 225, 227, 229, 231, 234, 236, 238, 240, 242, 244, 246, 248, 251, 253, 255};
  
  uint fixed_counter = 0;
  
  int ball_coords[20] = {3732, 584, 600, -477, -461, 3062, 1848, 318, 1582, 555, 571, 587, -490, -474, 3948, 2831, 1582, 318, -455, 558};
  int move_coords[20] = {16, 5, 10, 14, 0, 17, -10, 14, -16, 5, -16, -5, -10, -14, 0, -17, 10, -14, 16, -5};
  
  uint ball_counter = 0;
  
  int run_array_0[31] = {0};
  int run_array_1[31] = {0};
  int run_array_2[31] = {0};
  
  int run_type = 0;
  int run_start = 0;
  int run_length = 0;
  
  int run_radius = 0;
  int run_wait = 1000;
  
  uint run_counter = 0;
  
  uint christmas_counter = 0;
  
  /* The following properties can be changed by commands in the FIFO: */
  
  int mode = 3; // 0 = Fixed, 1 = Balls, 2 = Runs, 3 = Christmas
  int speed = 17; // This speed directly marks the speed of all animations!
  
  int red_0 = 255, green_0 = 127, blue_0 = 0; // Primary color
  int red_1 = 0, green_1 = 127, blue_1 = 255; // Secondary color
  int red_2 = 63, green_2 = 255, blue_2 = 63; // Tertiary color
  
  while (true) {
    uint color_table[30];
    
    for (uint i = 0; i < 30; i++) {
      int x = led_coords[i * 2 + 0];
      int y = led_coords[i * 2 + 1];
      
      int red = 0;
      int green = 0;
      int blue = 0;
      
      if (mode == 0) {
        uint counter = (fixed_counter + i * 25) % 3000;
        
        if (counter < 1000) {
          red = (red_0 * (1000 - counter) + red_1 * (counter - 0)) / 1000;
          green = (green_0 * (1000 - counter) + green_1 * (counter - 0)) / 1000;
          blue = (blue_0 * (1000 - counter) + blue_1 * (counter - 0)) / 1000;
        } else if (counter < 2000) {
          red = (red_1 * (2000 - counter) + red_2 * (counter - 1000)) / 1000;
          green = (green_1 * (2000 - counter) + green_2 * (counter - 1000)) / 1000;
          blue = (blue_1 * (2000 - counter) + blue_2 * (counter - 1000)) / 1000;
        } else {
          red = (red_2 * (3000 - counter) + red_0 * (counter - 2000)) / 1000;
          green = (green_2 * (3000 - counter) + green_0 * (counter - 2000)) / 1000;
          blue = (blue_2 * (3000 - counter) + blue_0 * (counter - 2000)) / 1000;
        }
      } else if (mode == 1) {
        for (uint j = 0; j < 10; j++) {
          int dx = ball_coords[j * 2 + 0] - x;
          int dy = ball_coords[j * 2 + 1] - y;
          
          if (dx < 0) {
            dx = -dx;
          }
          
          if (dy < 0) {
            dy = -dy;
          }
          
          int factor = 1 + dx * dx + dy * dy;
          
          if (j % 3 == 0) {
            red += (20480 * red_0) / factor;
            green += (20480 * green_0) / factor;
            blue += (20480 * blue_0) / factor;
          } else if (j % 3 == 1) {
            red += (20480 * red_1) / factor;
            green += (20480 * green_1) / factor;
            blue += (20480 * blue_1) / factor;
          } else {
            red += (20480 * red_2) / factor;
            green += (20480 * green_2) / factor;
            blue += (20480 * blue_2) / factor;
          }
        }
      } else if (mode == 2) {
        red = (red_0 * run_array_0[i] + red_1 * run_array_1[i] + red_2 * run_array_2[i]) / 1024;
        green = (green_0 * run_array_0[i] + green_1 * run_array_1[i] + green_2 * run_array_2[i]) / 1024;
        blue = (blue_0 * run_array_0[i] + blue_1 * run_array_1[i] + blue_2 * run_array_2[i]) / 1024;
      } else if (mode == 3) {
        uint counter = (christmas_counter + (((i * 166731) + 144) % 561 + 23) * 119) % 6000;
        
        if (counter < 1000) {
          red = red_0 * (1000 - counter);
          green = green_0 * (1000 - counter);
          blue = blue_0 * (1000 - counter);
        } else if (counter < 2000) {
          red = red_1 * (counter - 1000);
          green = green_1 * (counter - 1000);
          blue = blue_1 * (counter - 1000);
        } else if (counter < 3000) {
          red = red_1 * (3000 - counter);
          green = green_1 * (3000 - counter);
          blue = blue_1 * (3000 - counter);
        } else if (counter < 4000) {
          red = red_2 * (counter - 3000);
          green = green_2 * (counter - 3000);
          blue = blue_2 * (counter - 3000);
        } else if (counter < 5000) {
          red = red_2 * (5000 - counter);
          green = green_2 * (5000 - counter);
          blue = blue_2 * (5000 - counter);
        } else if (counter < 6000) {
          red = red_0 * (counter - 5000);
          green = green_0 * (counter - 5000);
          blue = blue_0 * (counter - 5000);
        }
        
        red /= 1000;
        green /= 1000;
        blue /= 1000;
      }
      
      if (red < 0) {
        red = 0;
      } else if (red > 255) {
        red = 255;
      }
      
      if (green < 0) {
        green = 0;
      } else if (green > 255) {
        green = 255;
      }
      
      if (blue < 0) {
        blue = 0;
      } else if (blue > 255) {
        blue = 255;
      }
      
      red = gamma_table[red];
      green = gamma_table[green];
      blue = gamma_table[blue];
      
      uint color = 0;
      
      color |= ((uint)(red) << 16);
      color |= ((uint)(green) << 24);
      color |= ((uint)(blue) << 8);
      
      color_table[i] = color;
    }
    
    if (mode == 0) {
      fixed_counter = (fixed_counter + speed) % 3000;
    } else if (mode == 1) {
      for (uint i = 0; i < 10; i++) {
        ball_coords[i * 2 + 0] += (speed * move_coords[i * 2 + 0]) / 17;
        ball_coords[i * 2 + 1] += (speed * move_coords[i * 2 + 1]) / 17;
        
        if (ball_counter % 19 == 0) {
          ball_coords[i * 2 + 0] += 5;
        } else if (ball_counter % 19 == 9) {
          ball_coords[i * 2 + 0] -= 5;
        }
        
        if (ball_coords[i * 2 + 0] > 1000) {
          ball_coords[i * 2 + 0] = 1000;
          move_coords[i * 2 + 0] *= -1;
        } else if (ball_coords[i * 2 + 0] < -1000) {
          ball_coords[i * 2 + 0] = -1000;
          move_coords[i * 2 + 0] *= -1;
        }
        
        if (ball_coords[i * 2 + 1] > 4000) {
          ball_coords[i * 2 + 1] = 4000;
          move_coords[i * 2 + 1] *= -1;
        } else if (ball_coords[i * 2 + 1] < 0) {
          ball_coords[i * 2 + 1] = 0;
          move_coords[i * 2 + 1] *= -1;
        }
      }
      
      ball_counter++;
    } else if (mode == 2) {
      if (run_radius >= run_length) {
        run_wait -= speed;
        
        if (run_wait < 0) {
          run_type = (run_counter / 11) % 3;
          run_start = run_counter % 30;
          run_length = 15 + (run_counter / 17) % 15;
          
          run_radius = 0;
          run_wait = 256 + ((run_counter * 17777 + 1313) % 9859 + 104) % 768;
        }
      } else {
        int left = run_start - run_radius;
        int right = run_start + run_radius;
        
        if (left < 0) {
          left = 30;
        }
        
        if (right > 30) {
          right = 30;
        }
        
        if (run_type == 0) {
          run_array_0[left] = 1024;
          run_array_0[right] = 1024;
        } else if (run_type == 1) {
          run_array_1[left] = 1024;
          run_array_1[right] = 1024;
        } else if (run_type == 2) {
          run_array_2[left] = 1024;
          run_array_2[right] = 1024;
        }
        
        run_radius++;
      }
      
      for (int i = 0; i < 30; i++) {
        run_array_0[i] -= speed;
        run_array_1[i] -= speed;
        run_array_2[i] -= speed;
        
        if (run_array_0[i] < 0) {
          run_array_0[i] = 0;
        }
        
        if (run_array_1[i] < 0) {
          run_array_1[i] = 0;
        }
        
        if (run_array_2[i] < 0) {
          run_array_2[i] = 0;
        }
      }
      
      run_counter++;
    } else if (mode == 3) {
      christmas_counter = (christmas_counter + speed) % 6000;
    }
    
    for (uint i = 0; i < 30; i++) {
      pio_sm_put_blocking(pio0, 0, color_table[i]);
    }
    
    sleep_ms(33);
  }
}

int main(void) {
  uint offset = pio_add_program(pio0, &neopixel_program);
  neopixel_program_init(pio0, 0, offset, 22, 1000000, false);
  
  gpio_init_mask(LCD_MASK);
  gpio_set_dir_out_masked(LCD_MASK);
  gpio_clr_mask(LCD_MASK);
  
  for (uint i = 10; i < 14; i++) {
    gpio_set_input_enabled(i, true);
    gpio_set_dir(i, false);
    
    gpio_pull_up(i);
    
    gpio_set_input_hysteresis_enabled(i, true);
    gpio_set_slew_rate(i, GPIO_SLEW_RATE_SLOW);
    
    last_inputs[i - 10] = false;
    inputs[i - 10] = false;
  }
  
  sleep_ms(100);
  
  multicore_launch_core1(&core1_main);
  
  lcd_send(0x38, false);
  lcd_send(0x0C, false);
  lcd_send(0x06, false);
  
  lcd_hispanify();
  
  /* --- */
  
  while (true) {
    /*
    if (input_pressed(0)) {
      lcd_write("A");
    }
    
    if (input_pressed(1)) {
      lcd_write("B");
    }
    
    if (input_pressed(2)) {
      lcd_write("C");
    }
    
    if (input_pressed(3)) {
      // lcd_write("D");
      lcd_send(0x18, false);
    }
    
    input_refresh();
    */
    
    trivia_show(trivia_set_a[0]);
  }
  
  return 0;
}
