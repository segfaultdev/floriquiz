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

void lcd_clear(void) {
  lcd_send(0x01, false);
}

void lcd_home(void) {
  lcd_send(0x02, false);
}

void lcd_goto(uint x, uint y) {
  lcd_send(0x80 + (x + y * 64), false);
}

void lcd_write(const char *str) {
  while (*str) {
    lcd_send(*str, true);
    str++;
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

void trivia_

int main(void) {
  uint offset = pio_add_program(pio0, &neopixel_program);
  neopixel_program_init(pio0, 0, offset, 22, 1000000, false);
  
  for (int i = 0; i < 10; i++) {
    pio_sm_put_blocking(pio0, 0, 0x20000000);
    pio_sm_put_blocking(pio0, 0, 0x20200000);
    pio_sm_put_blocking(pio0, 0, 0x00200000);
    pio_sm_put_blocking(pio0, 0, 0x00202000);
    pio_sm_put_blocking(pio0, 0, 0x00002000);
    pio_sm_put_blocking(pio0, 0, 0x20002000);
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
  lcd_send(0x0D, false);
  lcd_send(0x06, false);
  
  /* --- */
  
  lcd_clear();
  lcd_write("FloriQuiz! ");
  
  while (true) {
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
      lcd_write("D");
    }
    
    input_refresh();
  }
  
  return 0;
}
