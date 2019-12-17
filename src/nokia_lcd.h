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
*/
void lcd_send(uint8_t byte, uint8_t is_data);

/*
 * Clear buffer
 */
void lcd_buf_clear();

/*
 * Clear screen
 */
void lcd_clear();

/**
 * Set buffer cursor position
 * @x: horizontal position
 * @y: vertical position
 */
void lcd_buf_set_cursor(uint8_t x, uint8_t y);

/**
 * Set lcd cursor position
 * @x: horizontal position
 * @y: vertical position
 */
void lcd_set_cursor(uint8_t x, uint8_t y);


#define lcd_buf_new_line() lcd_buf_set_cursor(nokia_lcd.cursor_x, (nokia_lcd.cursor_y+1)%LCDHEIGHT)
#define lcd_new_line() lcd_set_cursor(nokia_lcd.cursor_x, (nokia_lcd.cursor_y+1)%LCDHEIGHT)
#define lcd_buf_car_return() lcd_buf_set_cursor(0, nokia_lcd.cursor_y);
#define lcd_car_return() lcd_set_cursor(0, nokia_lcd.cursor_y);


/**
 * Set single pixel in buffer
 * @x: horizontal pozition
 * @y: vertical position
 * @value: show/hide pixel
 */
void lcd_buf_set_pixel(uint8_t x, uint8_t y, uint8_t value);

/**
 *Set a single 8-pixel collumn to buffer
 *@byte: data to write, MSE top.
 */
void lcd_buf_write_col(const uint8_t byte);

/**
 *Set a single 8-pixel collumn to lcd
 *@byte: data to write, MSE top.
 */
void lcd_write_col(const uint8_t byte);


/**
 * Write a 5x8 bitmap to buffer
 * @btmp: array of 5 bytes
 */
void lcd_buf_write_char_btmp(const uint8_t *btmp);

/**
 * Write a 5x8 bitmap on lcd
 * @btmp: array of 5 bytes
 */
void lcd_write_char_btmp(const uint8_t *btmp);

/**
 * Write single char as a 5x8 bitmap to buffer
 * @code: char code
 */
void lcd_buf_write_char(char c);

/**
 * Draw single char as a 5x8 bitmap on display
 * @code: char code
 */
void lcd_write_char(char c);

/**
 * Write string to buffer. 
 * Example: writeString("abc",3);
 * @str: sending string
 * @scale: size of text
 */
void lcd_buf_write_string(const char *str);

void lcd_write_string(const char *str);

/**
 * Render screen to display
 */
void lcd_render_all(void);


#endif
