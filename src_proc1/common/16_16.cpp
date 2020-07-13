#include "nmgldef.h"
#include "nmgltex_common.h"
#include "texture_config.h"

#ifdef __GNUC__
#define SECTION(sec) __attribute__((section(sec)))
#else
#define SECTION(sec)
#endif // __GNUC__

#ifdef __cplusplus
extern "C"
{
#endif


//alignment = 4

// SECTION(TEXTURE_SECTION)
SECTION(".data_imu0")
unsigned char pixels_16_16[768] = {  
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0x00, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};  

// SECTION(TEXTURE_SECTION)
SECTION(".data_imu0")
TexImage2D teximage_16_16 = { 
    //internal format
    NMGL_RGB,

    //level
    0,

    //pixels
    pixels_16_16,

    //width
    16,

    //height
    16,

    //border
    0
};  



#ifdef __cplusplus
}
#endif