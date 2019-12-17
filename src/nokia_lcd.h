/*
 */


#ifndef NOKIA5110LCD
#define NOKIA5110LCD


#define LCDWIDTH 84
#define LCDHEIGHT 48

#define LCDWIDTH 84   ///< LCD is 84 pixels wide
#define LCDHEIGHT 48  ///< 48 pixels high

// #define LCD_PORT GPIOE

#define LCD_PORT GPIOE

#define LCD_CLK GPIO_PIN_9
// #define LCD_CLK GPIO_PIN_14 // 

#define LCD_DIN GPIO_PIN_10
// #define LCD_DIN GPIO_PIN_12 //Red

#define LCD_DC GPIO_PIN_11
// #define LCD_DC GPIO_PIN_11 //Orange

// #define LCD_CE GPIO_PIN_10 //Yellow
#define LCD_CE GPIO_PIN_12

#define LCD_RST GPIO_PIN_13


#define LCD_CONTRAST 0x40


#define lcd_send_cmd(x) lcd_send(x, 0)
#define lcd_send_data(x) lcd_send(x, 1)

/* 
*Start the display
*!Must be invoked in the beginning of the program!
 */
void lcd_init(void);

/*
*Send one byte to lcd
*@byte data to send
*@ is_data 1 to send data, 0 to send command
*@visible: 1 to show on lcd, 0 otherwise
*/
void lcd_send(uint8_t byte, uint8_t is_data);


/*
 * Clear screen
 * @visible: 1 to show on lcd, 0 otherwise
 */
void lcd_clear(uint8_t visible);

/**
 * Set lcd cursor position
 * @x: horizontal position
 * @y: vertical position
 * @visible: 1 to show on lcd, 0 otherwise
 */
void lcd_set_cursor(uint8_t x, uint8_t y, uint8_t visible);


#define lcd_new_line() lcd_set_cursor(nokia_lcd.cursor_x, (nokia_lcd.cursor_y+1)%LCDHEIGHT, visible)

#define lcd_car_return() lcd_set_cursor(0, nokia_lcd.cursor_y, visible);


/**
 * Set single pixel to 1 or 0
 * @x: horizontal pozition
 * @y: vertical position
 * @value: show/hide pixel
 * @visible: 1 to show on lcd, 0 otherwise
 */
void lcd_set_pixel(uint8_t x, uint8_t y, uint8_t value, uint8_t visible);

/**
 *Set a single 8-pixel collumn to lcd
 *@byte: data to write, MSE top.
 *@visible: 1 to show on lcd, 0 otherwise
 */
void lcd_write_col(const uint8_t byte, uint8_t visible);


/**
 * Write a 5x8 bitmap on lcd
 * @btmp: array of 5 bytes
 *@visible: 1 to show on lcd, 0 otherwise
 */
void lcd_write_char_btmp(const uint8_t *btmp, uint8_t visible);

/**
 * Draw single char as a 5x8 bitmap on display
 * @code: char code
 *@visible: 1 to show on lcd, 0 otherwise
 */
void lcd_write_char(char c, uint8_t visible);


void lcd_write_string(const char *str, uint8_t visible);

/**
 * Render screen to display
 */
void lcd_render_all(void);


#endif
