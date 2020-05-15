#include "image.h"
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

SECTION(TEXTURE_SECTION) unsigned char pixels_1_1[3] = {  
0x00, 0xff, 0xff, 
};  

SECTION(TEXTURE_SECTION) image_t image_1_1 = { 
    1,
    1,
    RGB,
    UNSIGNED_BYTE,
    pixels_1_1
};  


#ifdef __cplusplus
}
#endif