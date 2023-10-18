#include <stdlib.h>

#include "pico/multicore.h"
#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "trivia.h"

#include "neopixel.pio.h"

#define LCD_MASK (0x1C3FC000)

bool last_inputs[4];
bool inputs[4];

const trivia_t *trivia_set;
uint trivia_count;

uint diff_level = 1;

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
  sleep_us(50);
  
  gpio_put(28, false);
  
  if (!rs && data < 0x04) {
    sleep_ms(2);
  } else {
    sleep_us(50);
  }
}

void lcd_hispanify(void) {
  lcd_send(0x40, false);
  
  const unsigned char font[] = {
    0x02, 0x04, 0x0E, 0x01, 0x0F, 0x11, 0x0F, 0x00,
    0x02, 0x04, 0x0E, 0x11, 0x1F, 0x10, 0x0E, 0x00,
    0x02, 0x04, 0x04, 0x0C, 0x04, 0x04, 0x0E, 0x00,
    0x02, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00,
    0x02, 0x04, 0x11, 0x11, 0x11, 0x13, 0x0D, 0x00,
    0x13, 0x15, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00,
    
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    
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

void lcd_show(void) {
  lcd_send(0x0D, false);
}

void lcd_hide(void) {
  lcd_send(0x0C, false);
}

void lcd_goto(uint x, uint y) {
  lcd_send(0x80 + (x + y * 64), false);
}

uint lcd_write(const char *text, uint delay_ms) {
  uint length = 0;
  
  while (text[length]) {
    length++;
  }
  
  while (length) {
    if (text[length - 1] == ' ') {
      length--;
    } else {
      break;
    }
  }
  
  for (uint i = 0; i < length; i++) {
    if ((unsigned char)(*text) == 0xC2) {
      text++;
      
      if ((unsigned char)(*text) == 0xBF) {
        lcd_send(7, true);
      }
    } else if ((unsigned char)(*text) == 0xC3) {
      text++;
      
      if ((unsigned char)(*text) == 0xB1) {
        lcd_send(0xEE, true);
      } else if ((unsigned char)(*text) == 0xA1) {
        lcd_send(0, true);
      } else if ((unsigned char)(*text) == 0xA9) {
        lcd_send(1, true);
      } else if ((unsigned char)(*text) == 0xAD) {
        lcd_send(2, true);
      } else if ((unsigned char)(*text) == 0xB3) {
        lcd_send(3, true);
      } else if ((unsigned char)(*text) == 0xBA) {
        lcd_send(4, true);
      } else if ((unsigned char)(*text) == 0x9A) {
        lcd_send(5, true);
      }
    } else {
      lcd_send(*text, true);
    }
    
    text++;
    
    if (delay_ms) {
      sleep_ms(delay_ms);
    }
  }
  
  return length;
}

bool input_pressed(uint input) {
  return (inputs[input] && !last_inputs[input]);
}

bool input_released(uint input) {
  return (!inputs[input] && last_inputs[input]);
}

void input_refresh(void) {
  for (uint i = 10; i < 14; i++) {
    last_inputs[i - 10] = inputs[i - 10];
    inputs[i - 10] = !gpio_get(i);
  }
  
  rand();
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
  
  int mode = 0; // 0 = Fixed, 1 = Balls, 2 = Runs, 3 = Christmas
  int speed = 16; // This speed directly marks the speed of all animations!
  
  int red_0 = 0, green_0 = 127, blue_0 = 255; // Primary color
  int red_1 = 63, green_1 = 191, blue_1 = 255; // Secondary color
  int red_2 = 127, green_2 = 255, blue_2 = 255; // Tertiary color
  
  multicore_fifo_drain();
  
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
    
    if (multicore_fifo_rvalid()) {
      uint command = multicore_fifo_pop_blocking();
      
      uint red = ((command >> 16) & 0xFF);
      uint green = ((command >> 8) & 0xFF);
      uint blue = ((command >> 0) & 0xFF);
      
      uint color_select = ((command >> 24) & 3);
      
      mode = (int)((command >> 26) & 3);
      speed = (int)((command >> 28) * 3 + 1);
      
      if (color_select == 0) {
        red_0 = red;
        green_0 = green;
        blue_0 = blue;
      } else if (color_select == 1) {
        red_1 = red;
        green_1 = green;
        blue_1 = blue;
      } else if (color_select == 2) {
        red_2 = red;
        green_2 = green;
        blue_2 = blue;
      }
    }
    
    sleep_ms(33);
  }
}

void neo_send(int mode, int speed, int color) {
  const uint colors[] = {
    0x007FFF, 0x3FBFFF, 0x7FFFFF,
    0x00FF00, 0x2FFF2F, 0x5FFF5F,
    0xFF7F00, 0xFF9F1F, 0xFFAF3F,
    0x7F7F7F, 0xBFBFBF, 0xFFFFFF,
    0x007FFF, 0x00FF00, 0xFF7F00,
    0x00FF00, 0xFFFFFF, 0xFF00FF,
    0xFF0000, 0xFF7F00, 0xFFBF00,
    0xFF0000, 0x00FF00, 0x0000FF,
  };
  
  multicore_fifo_push_blocking(0x00000000 | ((speed - 1) << 28) | ((mode - 1) << 26) | colors[(color - 1) * 3 + 0]);
  multicore_fifo_push_blocking(0x01000000 | ((speed - 1) << 28) | ((mode - 1) << 26) | colors[(color - 1) * 3 + 1]);
  multicore_fifo_push_blocking(0x02000000 | ((speed - 1) << 28) | ((mode - 1) << 26) | colors[(color - 1) * 3 + 2]);
}

void scene_led_test(void) {
  lcd_clear();
  
  // Blue, Green, Orange, White, FloriQuiz, FloriStation, Spain, Rainbow
  
  const uint colors[] = {
    0x007FFF, 0x3FBFFF, 0x7FFFFF,
    0x00FF00, 0x2FFF2F, 0x5FFF5F,
    0xFF7F00, 0xFF9F1F, 0xFFAF3F,
    0x7F7F7F, 0xBFBFBF, 0xFFFFFF,
    0x007FFF, 0x00FF00, 0xFF7F00,
    0x00FF00, 0xFFFFFF, 0xFF00FF,
    0xFF0000, 0xFF7F00, 0xFFBF00,
    0xFF0000, 0x00FF00, 0x0000FF,
  };
  
  lcd_write("------ Prueba de patrones WS2812B ------", 0);
  
  int mode = 1, speed = 6, color = 1;
  bool display = true;
  
  while (true) {
    if (display) {
      lcd_goto(0, 1);
      
      lcd_write("\242Forma:", 0);
      lcd_send(' ', true);
      lcd_send(mode + '0', true);
      lcd_write("\243", 0);
      
      lcd_goto(10, 1);
      
      lcd_write("\242Vel.:", 0);
      lcd_send(' ', true);
      lcd_send((speed / 10) + '0', true);
      lcd_send((speed % 10) + '0', true);
      lcd_write("\243", 0);
      
      lcd_goto(20, 1);
      
      lcd_write("\242Color:", 0);
      lcd_send(' ', true);
      lcd_send(color + '0', true);
      lcd_write("\243", 0);
      
      lcd_goto(30, 1);
      
      lcd_write("\242Ir atrás\243", 0);
      display = false;
    }
    
    input_refresh();
    
    if (input_released(0)) {
      mode = (mode % 4) + 1;
      display = true;
      
      multicore_fifo_push_blocking(0x03000000 | ((speed - 1) << 28) | ((mode - 1) << 26));
    }
    
    if (input_released(1)) {
      speed = (speed % 16) + 1;
      display = true;
      
      multicore_fifo_push_blocking(0x03000000 | ((speed - 1) << 28) | ((mode - 1) << 26));
    }
    
    if (input_released(2)) {
      color = (color % 8) + 1;
      display = true;
      
      multicore_fifo_push_blocking(0x00000000 | ((speed - 1) << 28) | ((mode - 1) << 26) | colors[(color - 1) * 3 + 0]);
      multicore_fifo_push_blocking(0x01000000 | ((speed - 1) << 28) | ((mode - 1) << 26) | colors[(color - 1) * 3 + 1]);
      multicore_fifo_push_blocking(0x02000000 | ((speed - 1) << 28) | ((mode - 1) << 26) | colors[(color - 1) * 3 + 2]);
    }
    
    if (input_released(3)) {
      sleep_ms(500);
      return;
    }
  }
}

int scene_trivia(const trivia_t trivia, uint timer) {
  neo_send(2, 6, 1);
  lcd_clear();
  
  lcd_write(trivia.text, 40);
  sleep_ms(1000);
  
  for (uint i = 0; i < 4; i++) {
    lcd_goto(0, 1);
    
    uint length = lcd_write(trivia.options_long[i], 33);
    sleep_ms(1000);
    
    lcd_goto(0, 1);
    
    while (length--) {
      lcd_send(' ', true);
      sleep_ms(17);
    }
  }
  
  for (uint i = 0; i < 4; i++) {
    lcd_goto(i * 10, 1);
    
    lcd_write("\176", 33);
    lcd_write(trivia.options_short[i], 33);
  }
  
  sleep_ms(500);
  
  while (true) {
    input_refresh();
    
    if (inputs[0] && inputs[1] && inputs[2] && inputs[3]) {
      lcd_clear();
      
      while (inputs[0] || inputs[1] || inputs[2] || inputs[3]) {
        input_refresh();
      }
      
      input_refresh();
      return -1;
    }
    
    for (uint i = 0; i < 4; i++) {
      if (input_released(i)) {
        bool correct = (trivia.answer == i);
        neo_send(1, 6, correct ? 2 : 3);
        
        lcd_goto(trivia.answer * 10, 1);
        lcd_show();
        
        sleep_ms(5000);
        lcd_hide();
        
        return (correct ? 1 : 0);
      }
    }
  }
}

void scene_quiz(void) {
  // Timerless will run through all questions, with a 86400s (almost infinite) timer.
  // Easy will run through 10 easy questions, with an 30s timer.
  // Medium will run through 20 easy and medium questions, with a 12s timer.
  // Hard will run though 30 easy, medium and hard questions, with a 6s timer.
  
  uint score = 0, count, timer;
  
  if (diff_level == 0) {
    count = trivia_count;
    timer = 86400;
  } else if (diff_level == 1) {
    count = 10;
    timer = 30;
  } else if (diff_level == 2) {
    count = 20;
    timer = 12;
  } else if (diff_level == 3) {
    count = 30;
    timer = 6;
  }
  
  uint indexes[count];
  
  for (uint i = 0; i < count; i++) {
    uint index = rand() % trivia_count;
    
    trivia_loop: {
      index = (index + 1) % trivia_count;
      
      if (diff_level > 0) {
        if (diff_level - 1 < trivia_set[index].level) {
          goto trivia_loop;
        }
      }
      
      for (uint j = 0; j < i; j++) {
        if (indexes[j] == index) {
          goto trivia_loop;
        }
      }
    }
    
    neo_send(0, 6, 1);
    lcd_clear();
    
    lcd_write("Pregunta #", 0);
    lcd_send(' ', true);
    lcd_send(((i + 1) / 100) % 10 + '0', true);
    lcd_send(((i + 1) / 10) % 10 + '0', true);
    lcd_send((i + 1) % 10 + '0', true);
    lcd_write(" de", 0);
    lcd_send(' ', true);
    lcd_send((count / 100) % 10 + '0', true);
    lcd_send((count / 10) % 10 + '0', true);
    lcd_send(count % 10 + '0', true);
    lcd_write("...", 0);
    
    sleep_ms(1000);
    
    int result = scene_trivia(trivia_set[index], timer);
    indexes[i] = index;
    
    if (result < 0) {
      return;
    }
    
    score += result;
  }
  
  neo_send(0, 6, 1);
  lcd_clear();
  
  lcd_write("Se acertaron ", 0);
  lcd_send(' ', true);
  lcd_send((score / 100) % 10 + '0', true);
  lcd_send((score / 10) % 10 + '0', true);
  lcd_send(score % 10 + '0', true);
  lcd_write(" de", 0);
  lcd_send(' ', true);
  lcd_send((count / 100) % 10 + '0', true);
  lcd_send((count / 10) % 10 + '0', true);
  lcd_send(count % 10 + '0', true);
  lcd_write(".", 0);
  
  sleep_ms(2000);
}

void scene_main(void) {
  const char *diff_table[] = {"TL", "EZ", "ME", "HA"};
  
  bool display = true;
  
  lcd_clear();
  neo_send(3, 6, 1);
  
  while (true) {
    if (display) {
      lcd_write("-------------- FloriQuiz! --------------", 0);
      lcd_goto(0, 1);
      
      lcd_write("\242Florida.\243", 0);
      lcd_write("\242Cultural\243", 0);
      lcd_write("\242Dif.:", 0);
      lcd_send(' ', true);
      lcd_write(diff_table[diff_level], 0);
      lcd_write("\243", 0);
      lcd_write("\242Patrones\243", 0);
      
      display = false;
    }
    
    input_refresh();
    
    if (input_released(0)) {
      trivia_set = trivia_set_a;
      trivia_count = trivia_count_a;
      
      sleep_ms(500);
      scene_quiz();
      
      lcd_clear();
      neo_send(3, 6, 1);
      
      display = true;
    }
    
    if (input_released(1)) {
      trivia_set = trivia_set_b;
      trivia_count = trivia_count_b;
      
      sleep_ms(500);
      scene_quiz();
      
      lcd_clear();
      neo_send(3, 6, 1);
      
      display = true;
    }
    
    if (input_released(2)) {
      diff_level = (diff_level + 1) % 4;
      display = true;
    }
    
    if (input_released(3)) {
      sleep_ms(500);
      scene_led_test();
      
      lcd_clear();
      display = true;
    }
  }
}

int main(void) {
  srand(0);
  
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
  
  scene_main();
  return 0;
}
