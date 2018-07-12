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
#include <stdio.h>
#include "tft_lib.h"

void setData ();
void setText();
void clear ();

int main(void) {
    volatile uint32_t in_;
    volatile uint32_t i;

    char buffer [80];
    unsigned char new;

    WDT_A->CTL = WDT_A_CTL_PW |             // Stop WDT
            WDT_A_CTL_HOLD;

//    EUSCI_B0->CTLW0 = EUSCI_A_CTLW0_SWRST;  // Software reset enabled
    P2->OUT |= BIT4 | BIT5 | BIT6 | BIT7;
    P2->DIR |= BIT4 | BIT5 | BIT6 | BIT7;   // Configure P2  as output

    P6->OUT |= 0xff;
    P6->DIR |= 0xff;                        // Configure P6  as output

    P5->OUT |= 0xff;
    P5->DIR |= 0xff;                        // Configure P5  as output

//*******************************************************************************************************************************************
    CS->KEY = CS_KEY_VAL;                                                 // Unlock CS module for register access
    CS->CTL0 = 0;                                                         // Reset tuning parameters
    CS->CTL0 = CS_CTL0_DCORSEL_3;                                         // Set DCO to 12MHz (nominal, center of 8-16MHz range)
    CS->CTL1 = CS_CTL1_SELA_2 |                                           // Select ACLK = REFO
            CS_CTL1_SELS_3 |                                              // SMCLK = DCO
            CS_CTL1_SELM_3;                                               // MCLK = DCO
    CS->KEY = 0;                                                          // Lock CS module from unintended accesses

    // Configure UART pins
    P1->SEL0 |= BIT2 | BIT3;                                              // set 2-UART pin as secondary function //

    // Configure UART
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST;                               // Put eUSCI in reset
    EUSCI_A0->CTLW0 = EUSCI_A_CTLW0_SWRST |                               // Remain eUSCI in reset
            EUSCI_B_CTLW0_SSEL__SMCLK;                                    // Configure eUSCI clock source for SMCLK
    // Baud Rate calculation
    // 12000000/(16*9600) = 78.125
    // Fractional portion = 0.125
    // User's Guide Table 21-4: UCBRSx = 0x10
    // UCBRFx = int ( (78.125-78)*16) = 2
    EUSCI_A0->BRW = 6;                                                    // 12000000/16/115200
    EUSCI_A0->MCTLW = (8 << EUSCI_A_MCTLW_BRF_OFS) |
            EUSCI_A_MCTLW_OS16;

    EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SWRST;                              // Initialize eUSCI
    EUSCI_A0->IFG &= ~EUSCI_A_IFG_RXIFG;                                  // Clear eUSCI RX interrupt flag
    EUSCI_A0->IE |= EUSCI_A_IE_RXIE;                                      // Enable USCI_A0 RX interrupt
//*******************************************************************************************************************************************

    // orientation 0 - vertical, 1 - horizontal
    orientation (0);
    ILI9481_init();
    // 0,2 - vertical, 1,3 - horizontal
    setRotation(2, 9341);
    fillScreen(0x00);

    setText();

    while(1) {
        if (EUSCI_A0->IFG & EUSCI_A_IFG_RXIFG) {                            // Check if the message is came
            clear ();

            sprintf (buffer, "%d\n", new);
            lcdPrintString(buffer);

            new = EUSCI_A0->RXBUF;                                       // Set message from buffer to RXData
            new = new - 48;

            setData ();
            sprintf (buffer, "%d", new);
            lcdPrintString(buffer);
        }
    }
}

void setText () {
    Axis = 1;
    Text_color = returnColor24_16(0, 237, 237);
    Text_size = 2;
    TFT_line=2;
    TFT_char=2;
    lcdPrintString("Data:");
}

void setData () {
    Axis = 1;
    Text_color = returnColor24_16(0, 237, 237);
    Text_size = 2;
    TFT_line=2;
    TFT_char=70;
}

void clear () {
    Axis = 1;
    Text_color = returnColor24_16(0, 0, 0);
    Text_size = 2;
    TFT_line=2;
    TFT_char=70;
}
