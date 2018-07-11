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
//******************************************************************************

#include "ti/devices/msp432p4xx/inc/msp.h"
#include <stdint.h>
#include "tft_lib.h"

int main(void) {
    volatile uint32_t in_;

    WDT_A->CTL = WDT_A_CTL_PW |             // Stop watchdog timer
            WDT_A_CTL_HOLD;



    EUSCI_B0->CTLW0 = EUSCI_A_CTLW0_SWRST;  // Software reset enabled
    P2->OUT |= BIT4 | BIT5 | BIT6 | BIT7;
    P2->DIR |= BIT4 | BIT5 | BIT6 | BIT7;   // Configure P2  as output

    P6->OUT |= 0xff;
    P6->DIR |= 0xff;                        // Configure P6  as output

    P5->OUT |= 0xff;
    P5->DIR |= 0xff;                        // Configure P5  as output

    // orientation 0 - vertical, 1 - horizontal
    orientation (1);
    ILI9481_init();
    // 0,2 - vertical, 1,3 - horizontal
    setRotation(3, 9341);
//    fillScreen(0x00);
    fillScreen(127);

    Axis = 1;
    Text_color = returnColor24_16(0, 237, 237);
    Text_size = 2;
    TFT_line=150;
    TFT_char=180;
//    fillRect(30, 118, 290, 280,0xffab);
//    fillRect(40, 128, 280, 270,0xab);

    lcdPrintString(" Axis = 1 ");

    Axis = 0;
    Text_color = returnColor24_16(0, 237, 237);
    Text_size = 2;
    TFT_line=150;
    TFT_char=180;
    //    fillRect(30, 118, 290, 280,0xffab);
    //    fillRect(40, 128, 280, 270,0xab);

    lcdPrintString(" Axis = 0 ");

    while(1) {

    }
}


