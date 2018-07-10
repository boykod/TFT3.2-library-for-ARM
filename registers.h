// vertical
//#define TFTWIDTH  319
//#define TFTHEIGHT 479

// horizontal
//#define TFTWIDTH  479
//#define TFTHEIGHT 319

#define HX8357B_MADCTL_RGB          0x00
#define HX8357B_MADCTL_MY           0x80
#define HX8357B_MADCTL_MX           0x40
#define HX8357B_MADCTL_MV           0x20

#define HX8357D_SETC                0xB9

#define ILI9341_MADCTL_MY           0x80
#define ILI9341_MADCTL_MX           0x40
#define ILI9341_MADCTL_MV           0x20
#define ILI9341_MADCTL_RGB          0x00
#define ILI9341_MADCTL_BGR          0x08
#define ILI9341_MADCTL              0x36

// chip ID
#define ID_932X                     0
#define ID_7575                     1
#define ID_9341                     2
#define ID_HX8357D                  3
#define ID_4535                     4
#define ID_9481                     5
#define ID_UNKNOWN                  0xFF
