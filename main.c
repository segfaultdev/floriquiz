#include "pico/stdlib.h"
#include "hardware/pio.h"
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
    
    0x02, 0x04, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x0F,
    0x02, 0x04, 0x00, 0x0E, 0x11, 0x1F, 0x10, 0x0E,
    0x02, 0x04, 0x00, 0x04, 0x0C, 0x04, 0x04, 0x0E,
    0x02, 0x04, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E,
    0x02, 0x04, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0D,
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

void trivia_show(const trivia_t trivia) {
  lcd_send(0x0D, false);
  lcd_clear();
  
  trivia_write(trivia.text);
  
  lcd_send(0x0C, false);
  sleep_ms(2000);
  
  for (uint i = 0; i < 4; i++) {
    trivia_show_option(trivia.options_long[i]);
  }
  
  sleep_ms(2000);
}

int main(void) {
  uint offset = pio_add_program(pio0, &neopixel_program);
  neopixel_program_init(pio0, 0, offset, 22, 1000000, false);
  
  for (int i = 0; i < 10; i++) {
    pio_sm_put_blocking(pio0, 0, 0xFF000000);
    pio_sm_put_blocking(pio0, 0, 0xFFFF0000);
    pio_sm_put_blocking(pio0, 0, 0x00FF0000);
    pio_sm_put_blocking(pio0, 0, 0x00FFFF00);
    pio_sm_put_blocking(pio0, 0, 0x0000FF00);
    pio_sm_put_blocking(pio0, 0, 0xFF00FF00);
  }
  
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
