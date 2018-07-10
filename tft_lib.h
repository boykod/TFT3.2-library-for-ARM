#ifndef TFT_LIB_H_
#define TFT_LIB_H_

extern void blink ();

extern int TFT_line, TFT_char,Text_size, Axis, TFT_zdvig;
extern uint16_t Text_color;

//uint32_t readReg (uint8_t r);
//uint16_t readId (void);

extern void Write_8(DATA);
extern void Delay_5(S);

extern void ILI9481_init(void);
extern void writedata(DATA);

extern void orientation (int or);
extern void setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
extern void setRotation(int rotation, int id);
extern void fillScreen(uint16_t color);
extern void drawPixel(int16_t x, int16_t y, uint16_t color);
extern void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
extern void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
extern void printString(unsigned char _char, uint16_t color);
extern void printChar (unsigned char _char ,int16_t x, int16_t y, int16_t color);
extern void TextSize( size );
extern void lcdPrintString(uint8_t *c);
//extern void WriteDisplayBrightness(uint16_t Brightness);
extern void lcdOff();
extern void lcdOn();
extern void pulse();
extern uint16_t returnColor24_16(R , G , B);

extern void drawRect(int x1, int y1, int x2, int y2, uint16_t color);
extern void drawRoundRect(int x1, int y1, int x2, int y2, uint16_t color);
extern void fillRect(int x1, int y1, int x2, int y2, uint16_t color);
extern void fillRoundRect(int x1, int y1, int x2, int y2, uint16_t color);
extern void drawCircle(int x, int y, int radius, uint16_t color);
extern void fillCircle(int x, int y, int radius, uint16_t color);

extern void drawLine(int x1, int y1, int x2, int y2, uint16_t color);

extern void LCD_Writ_Bus(ch,cl);
extern void LCD_Write_DATA(VH,VL);
extern void LCD_Write_COM(VL);

#endif /* TFT_LIB_H_ */
