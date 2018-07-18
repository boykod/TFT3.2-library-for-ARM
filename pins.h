//*********************************************************
//                      MSP432P401x
//                 -----------------
//             /|\|                 |
//              | |             P5.7|-> LCD_DB15  Data BUS
//              --|RST           .  |
//                |              .  |
//                |             P5.0|-> LCD_DB8
//                |                 |
//     LCD_RS  <- |P2.6         P6.7|-> LCD_DB7
//     LCD_WR  <- |P2.7          .  |
//     LCD_CS  <- |P2.4          .  |
//     LCD_RST <- |P2.5         P6.0|-> LCD_DB0
//
//*********************************************************

#define TFTLCD_CS                   0x10;
#define TFTLCD_RST                  0x20;
#define TFTLCD_RS                   0x40;
#define TFTLCD_WR                   0x80;
