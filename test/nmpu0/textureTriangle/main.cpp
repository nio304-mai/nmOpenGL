#include "nmtype.h"
#include "nmgldef.h"
#include <cstdio>
#include "nmgltex_common.h"
#include "nmgltex_nm0.h"
#include "demo3d_nm0.h"
#include <cstdlib>
#include "nmplv/vSupport.h"
#include "malloc32.h"
#include "time.h"
#include "compareImages.h"

#ifndef __NM__
#include "bmp.h"
#include "image.h"
#endif

#ifdef __GNUC__
#define SECTION(sec) __attribute__((section(sec)))
#else
#define SECTION(sec)
#endif // __GNUC__

#define TRIANGLE_AMOUNT 1

//Массив текстур в виде структур типа image_t
#define TEXTURE_AMOUNT 9

extern "C" TexImage2D teximage_mytexture_256_256;
extern "C" TexImage2D teximage_256_256;
extern "C" TexImage2D teximage_mytexture;
extern "C" TexImage2D teximage_128_128;
extern "C" TexImage2D teximage_64_64;
extern "C" TexImage2D teximage_32_32;
extern "C" TexImage2D teximage_16_16;
extern "C" TexImage2D teximage_8_8;
extern "C" TexImage2D teximage_4_4;
extern "C" TexImage2D teximage_2_2;
extern "C" TexImage2D teximage_1_1;
//extern "C" nm32s scenario_1[1024];

nm32s scenario_1[1024] = {0xff646cf6, 0xffabbaf3, 0xffaaceff, 0xffabb4ed, 0xff858ade, 0xff3e46cc, 0xff3e47cb, 0xff3e47ca, 0xff3d47ca, 0xff3e47ca, 0xff3d46ca, 0xff3e48cb, 0xff3d47cb, 0xff3e46ca, 0xff3e47cb, 0xff3e47cb, 0xff3b44c9, 0xff3c45c8, 0xff3d46ca, 0xff3c45c9, 0xff3d46cb, 0xff3b44c9, 0xff3c46c9, 0xff3d46ca, 0xff3d46ca, 0xff4049cb, 0xffabafe8, 0xffabafe8, 0xffaaaee7, 0xffabaee8, 0xff866cf3, 0xff000000, 0xffaaabe5, 0xffff8282, 0xffffd0d0, 0xffff0000, 0xffbdbdea, 0xff3d46cb, 0xff3d46ca, 0xff3c42c7, 0xff3b44c9, 0xff3e46ca, 0xff3c46ca, 0xff3c44c9, 0xff3c46ca, 0xff3d46ca, 0xff3d47cb, 0xff3d46ca, 0xff3b44c8, 0xff3d45c9, 0xff3d46ca, 0xff3b44c9, 0xff3d46ca, 0xff3a43c7, 0xff3d45c9, 0xff3d46ca, 0xff3d46ca, 0xff434bcb, 0xffffffff, 0xffffffff, 0xffffe5e5, 0xffffffff, 0xffabafe8, 0xff000000, 0xffa7abe7, 0xfffffefe, 0xfffff7f7, 0xffff9a9a, 0xffbdc5f1, 0xff3d46cb, 0xff3e47cb, 0xff3a42c6, 0xff3b44c9, 0xff3d47ca, 0xff3d46ca, 0xff3c45c8, 0xff3b45c9, 0xff3e46ca, 0xff3d45ca, 0xff3d46c9, 0xff3b44ca, 0xff3b46c9, 0xff3c46cb, 0xff3b45c9, 0xff3c46ca, 0xff3943c6, 0xff3c44ca, 0xff3d47ca, 0xff3e47cb, 0xff434bcb, 0xffffffff, 0xffff9393, 0xffff7d7d, 0xffff8e8e, 0xffaaabe5, 0xff000000, 0xffabafe8, 0xfffffcfc, 0xffff4343, 0xffff0e0e, 0xffbdbde9, 0xff3c45cb, 0xff3c45c9, 0xff3842c5, 0xff3d45c9, 0xff3c45ca, 0xff3d45ca, 0xff3c43c9, 0xff3c45c9, 0xff3c45cb, 0xff3e47cb, 0xff3c45ca, 0xff3b44c9, 0xff3c45ca, 0xff3b45c9, 0xff3c46ca, 0xff3c44ca, 0xff3a42c7, 0xff3c45c8, 0xff3d46cb, 0xff3d46ca, 0xff444ccd, 0xffffffff, 0xffffc4c4, 0xffffe0e0, 0xffffffff, 0xffaaafe8, 0xff000000, 0xffaaade7, 0xffffa8a8, 0xffffcfcf, 0xffff0505, 0xffbcbae6, 0xff3c46ca, 0xff3d46ca, 0xff3b43c7, 0xff3b45c9, 0xff3e46ca, 0xff3e47cb, 0xff3b45c8, 0xff3c44c9, 0xff3d46ca, 0xff3e47cb, 0xff3c44c9, 0xff3b44c9, 0xff3c46c9, 0xff3c45ca, 0xff3d45c9, 0xff3c45c8, 0xff3b44c7, 0xff3d47ca, 0xff3d45ca, 0xff3d46ca, 0xff434acc, 0xfffffffe, 0xffffc9c9, 0xffffe9e9, 0xffffffff, 0xffaaaee7, 0xff000000, 0xffa9aee6, 0xffffffff, 0xffffffff, 0xffffffff, 0xffbcbfec, 0xff3d46ca, 0xff3c45c9, 0xff3a43c7, 0xff3d46c9, 0xff3f49cb, 0xff3e47cb, 0xff3a43c7, 0xff3b45c8, 0xff3d45c9, 0xff3d46ca, 0xff3c46ca, 0xff3d45ca, 0xff3c45ca, 0xff3c44ca, 0xff3d46c9, 0xff3c44c9, 0xff3b42c7, 0xff414acb, 0xff3d45cb, 0xff3e47cb, 0xff434bcc, 0xffffffff, 0xfffffefe, 0xffff0000, 0xffffffff, 0xffabafe8, 0xff000000, 0xffb6baeb, 0xffffffff, 0xffffffff, 0xffffffff, 0xffcccef1, 0xff3c46cb, 0xff3d46ca, 0xff3943c7, 0xff3f4ac9, 0xfff8f8fc, 0xff1620bf, 0xff3942c7, 0xff3c45c8, 0xff3d45ca, 0xff3c45c9, 0xff3c46ca, 0xff3c45c8, 0xff3e47cb, 0xff3c45c8, 0xff3d47ca, 0xff3b44c9, 0xff1621bf, 0xffffffff, 0xff121dbf, 0xff3e47cb, 0xff434ccc, 0xffffffff, 0xfffffefe, 0xfffffbfb, 0xffffffff, 0xffabafe8, 0xff000000, 0xff3e47ca, 0xff3e48cb, 0xff4049cb, 0xff4048ca, 0xff3e47cb, 0xff3d46ca, 0xff3d46ca, 0xff3b44c8, 0xff474fcc, 0xfffefefe, 0xfffbfbfd, 0xffbfc3ed, 0xff4149c8, 0xff3b45c9, 0xff3c45ca, 0xff3c46c9, 0xff3c45c9, 0xff3c45ca, 0xff3b46c9, 0xff4a52cd, 0xffbfc2ed, 0xfffbfbfd, 0xfffefefe, 0xff535bd0, 0xff3e47cb, 0xff3f48cb, 0xff747ad9, 0xff727bd9, 0xff7379d8, 0xff7378d9, 0xff5d65d4, 0xff000000, 0xff3e46c9, 0xff3c45ca, 0xff3b45c9, 0xff3b46ca, 0xff3d46cb, 0xff3f48cc, 0xff3c46ca, 0xff3842c8, 0xff323bc6, 0xfff7f8fc, 0xffeeeffa, 0xfffdfdfe, 0xfff9f9fd, 0xff4951cc, 0xff3e47ca, 0xff3c46ca, 0xff3b44c8, 0xff3c45c8, 0xff565ed0, 0xfff4f4fb, 0xfffcfdfe, 0xfff3f4fb, 0xfff8f8fc, 0xff454ecc, 0xff3d46ca, 0xff3e46ca, 0xff3e47ca, 0xff3c45c9, 0xff3b44c8, 0xff3c44c8, 0xff3e47cb, 0xff000000, 0xff3c46c9, 0xff3e47c9, 0xff3b44ca, 0xff3d46c9, 0xff3c45ca, 0xff3d45ca, 0xff3e47cb, 0xff3b42c8, 0xff3d47ca, 0xfffefefe, 0xfffcfcfe, 0xff1a26be, 0xffffffff, 0xfffefefe, 0xfffbfbfd, 0xff363fc9, 0xff2c36c6, 0xffffffff, 0xfffefefe, 0xffffffff, 0xff212bc1, 0xfffdfdfe, 0xfffefefe, 0xff3e47cb, 0xff3d46ca, 0xff3e46ca, 0xff3d46c9, 0xff3c46ca, 0xff3b44c9, 0xff3a43c8, 0xff3e47cb, 0xff000000, 0xff3e46ca, 0xff3e47c9, 0xff3c44c9, 0xff3d45ca, 0xff3d45ca, 0xff3d46cb, 0xff3e47cb, 0xff3a43c7, 0xff3c45c9, 0xff5961d1, 0xfffafbfd, 0xff1923be, 0xff434bca, 0xffbec1ed, 0xfffcfcfe, 0xffffffff, 0xfffdfdfe, 0xfffcfcfe, 0xffb7baea, 0xff454dcb, 0xff1823c0, 0xfffcfcfd, 0xff424ccc, 0xff3e46ca, 0xff3d46c9, 0xff3d46ca, 0xff3d46ca, 0xff3b45c9, 0xff3c45c8, 0xff3b44c7, 0xff3e47cb, 0xff000000, 0xff3d47c9, 0xff3e48ca, 0xff3e46ca, 0xff3d46c9, 0xff3c44ca, 0xff3e47cb, 0xff3e47cb, 0xff3c43c9, 0xff3c45c9, 0xff2832c4, 0xfff7f8fc, 0xff8d93de, 0xff3d46c9, 0xff3e47ca, 0xff3b44ca, 0xffffffff, 0xffffffff, 0xff2f39c6, 0xff3e46ca, 0xff3b45c9, 0xffacb0e8, 0xfff7f8fc, 0xff303ac6, 0xff3d47cb, 0xff3d46ca, 0xff3e47cb, 0xff3e47ca, 0xff3c46c9, 0xff3b46ca, 0xff3c44c8, 0xff3d47cb, 0xff000000, 0xff3d47ca, 0xff3e47ca, 0xff3e45ca, 0xff3c46ca, 0xff3b44c9, 0xff3c45cb, 0xff3c45ca, 0xff3b44c9, 0xff3d46c9, 0xff3f48ca, 0xfffefefe, 0xffffffff, 0xff3f48ca, 0xff3f48cc, 0xff3e46ca, 0xff3f48cb, 0xff3f48cb, 0xff3f47cb, 0xff3e47ca, 0xff4049cb, 0xffffffff, 0xfffefefe, 0xff3e47cb, 0xff3e47cb, 0xff3d47cb, 0xff3d46cb, 0xff3e47c9, 0xff3c46c9, 0xff3d46ca, 0xff3943c8, 0xff3d46cb, 0xff000000, 0xff3e47cb, 0xff3f48cb, 0xff3f48ca, 0xff3d46c7, 0xff3d45c8, 0xff3e47cb, 0xff3c46c9, 0xff3b44c8, 0xff3d45ca, 0xff3c45ca, 0xff858add, 0xfffafafd, 0xff3d45c8, 0xff3c46c9, 0xff3c47c9, 0xff3d47cb, 0xff3e48cb, 0xff3e46ca, 0xff3e45c9, 0xff2b35c4, 0xfffbfcfe, 0xff6e75d7, 0xff3c45c9, 0xff3d46c9, 0xff3d46c9, 0xff3d46c8, 0xff3e46ca, 0xff3c45c9, 0xff3c46ca, 0xff3b44c8, 0xff3e47cb, 0xff000000, 0xff3e47ca, 0xff3c47ca, 0xff3e46ca, 0xff3e46c9, 0xff3b44ca, 0xff3b46c8, 0xff3d46ca, 0xff3a43c8, 0xff3b44c9, 0xff303bc7, 0xffffffff, 0xfffdfdfe, 0xff3f48ca, 0xff3e48ca, 0xff3e47ca, 0xff3d47c9, 0xff3e47cc, 0xff3e48ca, 0xff3e45c9, 0xff8a8fdf, 0xfffdfefe, 0xffffffff, 0xff333dc8, 0xff3c46c9, 0xff3c46ca, 0xff3c46c9, 0xff3c46ca, 0xff3c44c8, 0xff3c46ca, 0xff3c45c8, 0xff3e47cb, 0xff000000, 0xff3d46cb, 0xff3d46ca, 0xff3f48ca, 0xff3b44c8, 0xff3e47ca, 0xff3d46cb, 0xff3b44ca, 0xff464eca, 0xffcfd1f1, 0xfffdfdfe, 0xffffffff, 0xff525bcf, 0xff3e47cc, 0xff3e47c9, 0xff3e46cb, 0xff3d45c9, 0xff3d46ca, 0xff3d47ca, 0xff3c45ca, 0xff3c45c8, 0xff9196e0, 0xffffffff, 0xfffafafd, 0xffc2c5ee, 0xff4b53ce, 0xff3d46c9, 0xff3c46c9, 0xff3d46cb, 0xff3b46c9, 0xff3b45c9, 0xff3e48cc, 0xff000000, 0xff3d45c9, 0xff3d45ca, 0xff3e47cb, 0xff3b43c8, 0xff3c46ca, 0xff3d46ca, 0xff212bc2, 0xfffbfafd, 0xfffefefe, 0xffe7e8f8, 0xff3942c9, 0xff3f47ca, 0xff3f48cc, 0xff3d47ca, 0xff3d47ca, 0xff3e46ca, 0xff3c46ca, 0xff3c44c9, 0xff3d46c9, 0xff3c47c9, 0xff3d46c9, 0xff3842c8, 0xfff6f6fd, 0xffffffff, 0xffffffff, 0xff262fc3, 0xff3c45c9, 0xff3e46ca, 0xff3c45ca, 0xff3a44c7, 0xff3e47cb, 0xff000000, 0xff3d46cb, 0xff3e46cb, 0xff3c45ca, 0xff3b44c9, 0xff3f48c9, 0xff8a90df, 0xffffffff, 0xffffffff, 0xff3b44c9, 0xff414acc, 0xff424aca, 0xff424bcb, 0xff424bcb, 0xff3c47ca, 0xff3e46ca, 0xff3f45c9, 0xff3d46c8, 0xff3d45c8, 0xff3d47c9, 0xff4149cb, 0xff4149ca, 0xff4149ca, 0xff4149cb, 0xff8388dd, 0xffffffff, 0xffffffff, 0xff7278d7, 0xff3c45c9, 0xff3c46c9, 0xff3a45c8, 0xff3e47cb, 0xff000000, 0xff3d46ca, 0xff3d46ca, 0xff3c46c9, 0xff3d46ca, 0xffffffff, 0xfffefefe, 0xffffffff, 0xffffffff, 0xfffefefe, 0xfffefefe, 0xfffefefe, 0xfffefefe, 0xfffefefe, 0xffffffff, 0xff424ccb, 0xff3e46ca, 0xff3d46c9, 0xff4048ca, 0xfffefefe, 0xfffefefe, 0xfffefefe, 0xfffefefe, 0xfffefefe, 0xfffefefe, 0xffffffff, 0xffffffff, 0xfffefefe, 0xffececf9, 0xff3c45c8, 0xff3a43c8, 0xff3c45c9, 0xff000000, 0xff3e47cb, 0xff3d46ca, 0xff3d46ca, 0xff3d46c9, 0xff1e27c1, 0xff999de2, 0xff9ca1e4, 0xff9ca0e3, 0xff9ca0e4, 0xff9ca1e4, 0xff9ca1e4, 0xff9da2e5, 0xff9ca1e4, 0xffffffff, 0xff868cde, 0xff3e47c9, 0xff3d46c9, 0xff9498e1, 0xffffffff, 0xff8f94e0, 0xff9ca1e4, 0xff9da1e4, 0xff9da1e4, 0xff9da2e4, 0xff9ca0e3, 0xff9ca2e4, 0xff989de3, 0xff2c35c6, 0xff3d46ca, 0xff3b44c8, 0xff3d46ca, 0xff000000, 0xff3e47cb, 0xff3c45c9, 0xff3c45ca, 0xff3d46c8, 0xff3c45c9, 0xff3d46cb, 0xff3c46ca, 0xff3d47cb, 0xff3b44c9, 0xff3c45c9, 0xff3e46cb, 0xff3c45c9, 0xff3e47cb, 0xfffafbfd, 0xfff3f4fb, 0xff3f48ca, 0xff4149ca, 0xfffafafd, 0xffffffff, 0xff434acb, 0xff3d47ca, 0xff3e47ca, 0xff3d46c9, 0xff3d45ca, 0xff3b43c8, 0xff3c45ca, 0xff3c45ca, 0xff3d46ca, 0xff3b45c9, 0xff3b45c9, 0xff3d47cb, 0xff000000, 0xff3d47ca, 0xff3c45c9, 0xff3c45c9, 0xff3d47cb, 0xff3c44c9, 0xff3d45ca, 0xff3c45ca, 0xff3c45ca, 0xff3d47cb, 0xff3c45ca, 0xff3c45c9, 0xff3d47cb, 0xff3e47cb, 0xff757cd9, 0xfffefefe, 0xff353fc7, 0xff363fc8, 0xffffffff, 0xffffffff, 0xff3c45cb, 0xff3e47cc, 0xff3e46cb, 0xff3d47ca, 0xff3c44c9, 0xff3b45c8, 0xff3c45c9, 0xff3e47cb, 0xff3d46ca, 0xff3c45ca, 0xff3c44c9, 0xff3d46cb, 0xff000000, 0xff4148cc, 0xff444bcd, 0xff414acb, 0xff434ccb, 0xff4149cb, 0xff3d46ca, 0xff3e46ca, 0xff3d46ca, 0xff3e46ca, 0xff3c45c8, 0xff3c45ca, 0xff3e47cb, 0xff3d46ca, 0xff3b44c9, 0xfff9f9fd, 0xff787ed9, 0xffe7e9f8, 0xfffbfcfe, 0xff3c46c9, 0xff3c45c9, 0xff3d46ca, 0xff3c45ca, 0xff3c45c9, 0xff3b44c8, 0xff3c43c9, 0xff3c45ca, 0xff424bcb, 0xff424ccc, 0xff414acb, 0xff4049cb, 0xff3e47ca, 0xff000000, 0xffa7abe7, 0xfff8f9fd, 0xfff8f9fd, 0xfff8f9fd, 0xfff8f9fd, 0xff424bcb, 0xff3c46c9, 0xff3d46ca, 0xff3c46c9, 0xff3c45c8, 0xff3d46ca, 0xff3c44ca, 0xff3e47cb, 0xff3e46cb, 0xfffdfdfe, 0xfffafafd, 0xfffdfefe, 0xfffdfdfe, 0xff3c45c9, 0xff3c45c9, 0xff3d45ca, 0xff3c47ca, 0xff3c45ca, 0xff3c46ca, 0xff3b45c9, 0xff2831c5, 0xfff5f6fc, 0xfff8f9fd, 0xfff8f9fd, 0xfff8f9fd, 0xffa7abe7, 0xff000000, 0xffabafe8, 0xffffd2d2, 0xffff9393, 0xffff9292, 0xffffffff, 0xff434ccc, 0xff3e46ca, 0xff3d45ca, 0xff3c46c9, 0xff3c44c9, 0xff3e47c9, 0xff3e47cb, 0xff3e47cb, 0xff3e47cb, 0xff4851cc, 0xfffefefe, 0xfffefefe, 0xff333cc7, 0xff3d46c9, 0xff3c46cb, 0xff3c45c9, 0xff3e47ca, 0xff3b45c8, 0xff3d47ca, 0xff3a43c8, 0xff2832c5, 0xfffbd6d8, 0xffff8e8e, 0xffff9191, 0xfffffafa, 0xffabafe8, 0xff000000, 0xffabafe8, 0xffffffff, 0xffffa0a0, 0xffffffff, 0xffffffff, 0xff434bcc, 0xff3d46ca, 0xff3d45ca, 0xff3c44c9, 0xff3c45c9, 0xff3e46c9, 0xff3d45ca, 0xff3e47cb, 0xff3e47cb, 0xff2e38c6, 0xfffbfbfd, 0xfff8f8fc, 0xff3740c9, 0xff3c45cb, 0xff3c46ca, 0xff3d46c9, 0xff3d47ca, 0xff3b44c8, 0xff3d45cb, 0xff3b43c6, 0xff2832c5, 0xfffbffff, 0xffff4a4a, 0xffffffff, 0xffffffff, 0xffabafe8, 0xff000000, 0xffabafe8, 0xffffffff, 0xffff9898, 0xfffffdfd, 0xffffffff, 0xff424bcb, 0xff3d44ca, 0xff3e46cb, 0xff3b45c7, 0xff3e46c9, 0xff3d45ca, 0xff3e47cb, 0xff3c45c9, 0xff3d46ca, 0xff3d45ca, 0xffffffff, 0xffffffff, 0xff3c46ca, 0xff3d45ca, 0xff3e46ca, 0xff3c45c9, 0xff3d47ca, 0xff3c45c9, 0xff3d46ca, 0xff3b45c8, 0xff2731c4, 0xfffbfcfe, 0xffffffff, 0xffff4949, 0xfffffcfc, 0xffabafe8, 0xff000000, 0xffabafe8, 0xffffffff, 0xffff9797, 0xfffffdfd, 0xffffffff, 0xff424acc, 0xff3c46c9, 0xff3e47ca, 0xff3b44c9, 0xff3b45c9, 0xff3d45ca, 0xff3d45ca, 0xff3d46cb, 0xff3e46ca, 0xff3e47cb, 0xff3f49cb, 0xff3d46ca, 0xff3c45c9, 0xff3f47ca, 0xff3e46c9, 0xff3c45ca, 0xff3b44ca, 0xff3d46ca, 0xff3d46c9, 0xff3c44c9, 0xff2731c4, 0xfffbfdff, 0xfffffefe, 0xffffdcdc, 0xfffffefe, 0xffabafe8, 0xff000000, 0xffabafe8, 0xffff6868, 0xffff0505, 0xfffffcfc, 0xffffffff, 0xff424bcb, 0xff3c45ca, 0xff3d46c9, 0xff3c45c9, 0xff3c44c8, 0xff3e46c9, 0xff3c46c9, 0xff3e46c9, 0xff3e47c9, 0xff3d46c9, 0xff3e47ca, 0xff3d46ca, 0xff3d46ca, 0xff3d46ca, 0xff3e47cb, 0xff3d46ca, 0xff3d46c9, 0xff3c46ca, 0xff3b45c8, 0xff3c45c9, 0xff2832c5, 0xfffbc0c2, 0xffff2121, 0xffff0808, 0xfffffefe, 0xffabafe8, 0xff000000, 0xffabafe8, 0xfffffdfd, 0xfffff7f7, 0xfffffefe, 0xffffffff, 0xff414aca, 0xff3c45ca, 0xff3b44c9, 0xff3c45c9, 0xff3c45c6, 0xff3c45c8, 0xff3c46c9, 0xff3d45c9, 0xff3e46c9, 0xff3d46cb, 0xff3d46ca, 0xff3d46ca, 0xff3c45ca, 0xff3e47cb, 0xff3d45ca, 0xff3d46c9, 0xff3a44c9, 0xff3d47c9, 0xff3d46ca, 0xff3e47cb, 0xff2832c5, 0xfffbfbfd, 0xfffff7f7, 0xfffffafa, 0xfffffefe, 0xffabafe8, 0xff000000, 0xff8366d5, 0xffabafe8, 0xffabafe8, 0xffabafe8, 0xffabafe8, 0xff4049cb, 0xff3d46ca, 0xff3a44c8, 0xff3c45c9, 0xff3b45c9, 0xff3c44c9, 0xff3c44c9, 0xff3c44c9, 0xff3c46c8, 0xff3c46c9, 0xff3d46c9, 0xff3e46ca, 0xff3e47cb, 0xff3e47cb, 0xff3c46ca, 0xff3d45ca, 0xff3b44c8, 0xff3d46cb, 0xff3c45c9, 0xff3c45c9, 0xff313bc7, 0xffa8ace7, 0xffaaaee7, 0xffabafe8, 0xffabaee8, 0xff648df6, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, 0xff000000, };
#ifndef __NM__
//массив изображений после текстурирования
image_t result_images [TRIANGLE_AMOUNT]; 


/**
Функция rawToImage выполняет преобразование массива цветов пикселей в структуру типа image_t.

\param triangles [in] Массив цветов пикселей треугольников
\param windows [in] Массив с данными о треугольниках в массиве triangles
\param images [in] Массив структур типа image_t для сохранения информации о треугольниках
\param count [in] Количество треугольников 
*/
int rawToImage (nm32s* triangles, Rectangle* windows, image_t* images, int count);

#endif

/**
Функция printPattern выполняет вывод на экран паттерны для треугольников в виде псевдографики.

\param patterns [in] Массив паттернов треугольников
\param triangles [in] Массив цветов треугольников (не используется)
\param count [in] Количество паттернов
*/
void printPattern(Pattern* patterns, int count);

/**
Функция extractTriangleByPattern затирает пиксели, находящиеся вне шаблона.

\param patterns [in] Массив паттернов треугольников
\param triangle [in] Массив, содержащий треугольник с наложенной текстурой
\param count [in] Количество паттернов
*/
void extractTriangleByPattern(Pattern* patterns, nm32s *triangle, int count);

void cropRectangle(nm32s *triangle, int count);
//Массив данных о треугольниках (координаты вершин, текстурные координаты и т.д.)
SECTION(".data_imu0") TrianglesInfo triangles;

// Паттерны треугольников. Паттерн представляет собой массив элементов из WIDTH_PTRN=32 строк и HEIGHT_PTRN=32 столбцов.
// Одна строка матрицы состоит из 32 элементов по 2 бита на элемент => каждая строка занимает 64 бита.
// Всего паттерн (WIDTH_PTRN * HEIGHT_PTRN / 16) intов на один треугольник
// 0-ой int - младшая половина 64-битной 0-ой строки паттерна
// 1-ой int - младшая половина 64-битной 0-ой строки паттерна
// 2-ой int - младшая половина 64-битной 1-ой строки паттерна
// 3-ой int - младшая половина 64-битной 2-ой строки паттерна
// 0-ая строка паттерна - верхняя строка
SECTION(".data_imu0") Pattern patterns [TRIANGLE_AMOUNT] = { 
    {0x50000000, 0x00000000, 
    0x54000000, 0x00000000, 
    0x54000000, 0x00000001, 
    0x55000000, 0x00000001, 
    0x55400000, 0x00000005, 
    0x55400000, 0x00000005, 
    0x55500000, 0x00000015, 
    0x55540000, 0x00000015, 
    0x55540000, 0x00000015, 
    0x55550000, 0x00000055, 
    0x55554000, 0x00000055, 
    0x55554000, 0x00000155, 
    0x55555000, 0x00000155, 
    0x55555400, 0x00000555, 
    0x55555400, 0x00000555, 
    0x55555500, 0x00001555, 
    0x55555500, 0x00001555, 
    0x55555540, 0x00001555, 
    0x55555550, 0x00005555, 
    0x55555550, 0x00005555, 
    0x55555555, 0x00015555, 
    0x55555540, 0x00015555, 
    0x55540000, 0x00055555, 
    0x50000000, 0x00055555, 
    0x00000000, 0x00055540, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000}, 
    
//    {0x50000000, 0x00000000, 
//    0x54000000, 0x00000000, 
//    0x54000000, 0x00000001, 
//    0x55000000, 0x00000001, 
//    0x55400000, 0x00000005, 
//    0x55400000, 0x00000005, 
//    0x55500000, 0x00000015, 
//    0x55540000, 0x00000015, 
//    0x55540000, 0x00000015, 
//    0x55550000, 0x00000055, 
//    0x55554000, 0x00000055, 
//    0x55554000, 0x00000155, 
//    0x55555000, 0x00000155, 
//    0x55555400, 0x00000555, 
//    0x55555400, 0x00000555, 
//    0x55555500, 0x00001555, 
//    0x55555500, 0x00001555, 
//    0x55555540, 0x00001555, 
//    0x55555550, 0x00005555, 
//    0x55555550, 0x00005555, 
//    0x55555555, 0x00015555, 
//    0x55555540, 0x00015555, 
//    0x55540000, 0x00055555, 
//    0x50000000, 0x00055555, 
//    0x00000000, 0x00055540, 
//    0x00000000, 0x00000000, 
//    0x00000000, 0x00000000, 
//    0x00000000, 0x00000000, 
//    0x00000000, 0x00000000, 
//    0x00000000, 0x00000000, 
//    0x00000000, 0x00000000, 
//    0x00000000, 0x00000000},
};

int counter = 0;

template<class T> inline T* myMallocT() {
	T* result = (T*)halMalloc32(sizeof32(T));
	if (result == 0) throw counter;
	counter++;
	return result;
}

template<class T> inline T* myMallocT(int count) {
	T* result = (T*)halMalloc32(count * sizeof32(T));
	if (result == 0) throw counter;
	counter++;
	return result;
}

SECTION(".data_imu0") NMGL_Context_NM0 *NMGL_Context_NM0::context;

SECTION(".text_demo3d") 
int main ()
{
	
	NMGL_Context_NM0 *test_cntxt;
	NMGLSynchroData synchroData;
	synchroData.init();
	NMGL_Context_NM0::create(&synchroData);	
	test_cntxt = NMGL_Context_NM0::getContext();
	test_cntxt->init(&synchroData);
	
    //Массивы растеризованных и закрашенных треугольников
	nm32s pSrcTriangle[WIDTH_PTRN * HEIGHT_PTRN * TRIANGLE_AMOUNT];
	nm32s pDstTriangle [WIDTH_PTRN * HEIGHT_PTRN * TRIANGLE_AMOUNT]; 
    
    //Массив значений цветов для треугольников, один цвет на треугольник
    v4nm32s colors [TRIANGLE_AMOUNT];
	((nm32s*)colors)[0] = (nm32s)255;
	((nm32s*)colors)[1] = (nm32s)0;
	((nm32s*)colors)[2] = (nm32s)255;
	((nm32s*)colors)[3] = (nm32s)255;
    //((nm32s*)colors)[4] = (nm32s)255;
	//((nm32s*)colors)[5] = (nm32s)255;
	//((nm32s*)colors)[6] = (nm32s)0;
	//((nm32s*)colors)[7] = (nm32s)255;
	
	//Информация о размещении видимой части треугольников в сегменте
    Rectangle windows [TRIANGLE_AMOUNT];
    
    int count = TRIANGLE_AMOUNT;
    int i = 0;
    int j = 0;
	
	clock_t clkStart=0;
	clock_t clkEnd=0;
	clock_t diff = 0;


	printf ("Start textureTriangle test...\n");

    windows[0].x = -1;
    windows[0].y = 0;
    windows[0].width = 32;
    windows[0].height = 32;
  
    //windows[1].x = -1;
    //windows[1].y = 0;
    //windows[1].width = 32;
    //windows[1].height = 32;

    //setup triangles parameters
    
    float x0[TRIANGLE_AMOUNT] = {0.0f};
    float y0[TRIANGLE_AMOUNT] = {0.0f};
    float x1[TRIANGLE_AMOUNT] = {0.0f};
    float y1[TRIANGLE_AMOUNT] = {31.0f};
    float x2[TRIANGLE_AMOUNT] = {31.0f};
    float y2[TRIANGLE_AMOUNT] = {31.0f};
   
	float s0[TRIANGLE_AMOUNT] = {0.0f};
    float t0[TRIANGLE_AMOUNT] = {0.0f};
    float s1[TRIANGLE_AMOUNT] = {0.0f};
    float t1[TRIANGLE_AMOUNT] = {1.0f};
    float s2[TRIANGLE_AMOUNT] = {1.0f};
    float t2[TRIANGLE_AMOUNT] = {1.0f};

    float z[TRIANGLE_AMOUNT] = {1.0f}; //minus (z in camera space)
    
	for (int counter = 0; counter < 1; counter++)
	{
		//printf ("%d\n", counter);
		triangles.x0 = x0;
		triangles.y0 = y0;
		triangles.x1 = x1;
		triangles.y1 = y1;
		triangles.x2 = x2;
		triangles.y2 = y2;
 
		triangles.s0 = s0;
		triangles.t0 = t0;
		triangles.s1 = s1;
		triangles.t1 = t1;
		triangles.s2 = s2;
		triangles.t2 = t2;
    
		triangles.z0 = z;
		triangles.z1 = z;
		triangles.z2 = z;
	
		triangles.colors = colors;
			
		//Активный текстурный модуль
		test_cntxt->texState.activeTexUnitIndex = 0;
		unsigned int activeTexUnitIndex = test_cntxt->texState.activeTexUnitIndex;
    
		//Текстурный объект, привязанный к активному текстурному модулю
		test_cntxt->texState.texUnits[activeTexUnitIndex].boundTexObject = &test_cntxt->texState.texObjects[0];
		TexObject* boundTexObject = test_cntxt->texState.texUnits[activeTexUnitIndex].boundTexObject;

		boundTexObject->texImages2D[0] = teximage_mytexture_256_256;
		boundTexObject->texImages2D[1] = teximage_128_128;
		boundTexObject->texImages2D[2] = teximage_64_64;
		boundTexObject->texImages2D[3] = teximage_32_32;
		boundTexObject->texImages2D[4] = teximage_16_16;
		boundTexObject->texImages2D[5] = teximage_8_8;
		boundTexObject->texImages2D[6] = teximage_4_4;
		boundTexObject->texImages2D[7] = teximage_2_2;
		boundTexObject->texImages2D[8] = teximage_1_1;

		//default texEnvColor = (0.0f, 0.0f, 0.0f, 0.0f)
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[0] = 0.0f;
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[1] = 0.0f;
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[2] = 0.0f;
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[3] = 0.0f;

		boundTexObject->texMagFilter = NMGL_NEAREST; //default LINEAR
		boundTexObject->texWrapS = NMGL_CLAMP_TO_EDGE; // default REPEAT
		boundTexObject->texWrapT = NMGL_CLAMP_TO_EDGE;// default REPEAT
		test_cntxt->texState.texUnits[activeTexUnitIndex].texFunctionName = NMGL_REPLACE; //default = NMGL_MODULATE
#if 0	
//texMinFilter = NMGL_NEAREST
		printf ("texMinFilter = NMGL_NEAREST\n");
		boundTexObject->texMinFilter = NMGL_NEAREST;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %lu\n",(long int)diff);

//texMinFilter = NMGL_LINEAR
		printf ("texMinFilter = NMGL_LINEAR\n");
		boundTexObject->texMinFilter = NMGL_LINEAR;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %lu\n",(long int)diff);	
	
//texMinFilter = NMGL_NEAREST_MIPMAP_LINEAR
		printf ("texMinFilter = NMGL_NEAREST_MIPMAP_LINEAR\n");
		boundTexObject->texMinFilter = NMGL_NEAREST_MIPMAP_LINEAR;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %lu\n",(long int)diff);	
	
//texMinFilter = NMGL_LINEAR_MIPMAP_LINEAR
		printf ("texMinFilter = NMGL_LINEAR_MIPMAP_LINEAR\n");
		boundTexObject->texMinFilter = NMGL_LINEAR_MIPMAP_LINEAR;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %lu\n",(long int)diff);		
#endif
// Correctness		
// texMinFilter = NMGL_NEAREST
		printf ("texMinFilter = NMGL_NEAREST\n");
		boundTexObject->texMinFilter = NMGL_NEAREST;

		textureTriangle(&triangles, pDstTriangle, count);
		//extractTriangleByPattern(patterns, pDstTriangle, 1);
		cropRectangle(pDstTriangle, 1);
		for(int i = 0; i < 32; ++i){
			for (int j = 0; j < 32; ++j){
				printf("%x ", pDstTriangle[32 * i + j]);
			}
			puts("");
		}
		//printPattern(patterns, 1);

		
}
	
#ifndef __NM__

    //convert result to image_t to compare with etalon    
    rawToImage(pDstTriangle, windows, result_images, count);

    char* fileNames [TRIANGLE_AMOUNT] = {"./result_1.bmp"};

    for (i = 0; i < count; i++)
    {
        saveToBmp (32, result_images[i], fileNames[i]);
    }
#endif //__NM__        

	int corr = compareImages(pDstTriangle, scenario_1, WIDTH_PTRN, HEIGHT_PTRN);
	printf("%d\n\r", corr);
	printf ("End textureTriangle test...\n");
    return 0;
}

void printPattern(Pattern* patterns, int count)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < count; i++)
    {
        for (int j = 0; j < 32; j++)
		{
			//sprintf("i = %d %x \n", i, context->ppSrcPackPtrns[0][i]);
			for (int k = 0; k < 32; k++)
				if (((nm64s*)patterns[i])[j] & ((nm64s)1 << (k * 2)))
					printf("1 ");
				else
					printf("0 ");
			// if (i & 1)
            printf("\n\r");
		}
    }
}

void extractTriangleByPattern(Pattern* patterns, nm32s *triangle, int count)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < count; i++)
    {
        for (int j = 0; j < 32; j++)
		{
			//sprintf("i = %d %x \n", i, context->ppSrcPackPtrns[0][i]);
			for (int k = 0; k < 32; k++)
				if (((nm64s*)patterns[i])[j] & ((nm64s)1 << (k * 2))){
					// Keep this pixel
				} else {
					// Erase this pixel
					triangle[32 * j + k] = 0xff000000;
				}
		}
    }
}
void cropRectangle(nm32s *triangle, int count)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < count; i++)
    {
        for (int j = 0; j < 32; j++)
		{
			triangle[32 * j + 31] = 0xff000000;	// Black last column
			triangle[32 * 31 + j] = 0xff000000; // Black last row
		}
    }
}

#ifndef __NM__
int rawToImage (nm32s* triangles, Rectangle* windows, image_t* images, int count)
{
    
    int i = 0;
    int srcRow = 0;
    int dstRow = 0;
    int col = 0;

    nm32s* triangle = triangles;
    
    for (i = 0; i < count; i++)
    {
        int width = windows[i].width;
        int height = windows[i].height;
        nm32s pixel_pos = 0;
        nm32s pixel_value = 0;
        
        images[i].width = width;
        images[i].height = height;
        images[i].format = RGBA;
        images[i].type = UNSIGNED_BYTE;
		images[i].alignment = 1;
        
        //copy pixels from triangles to image
        images[i].pixels = (unsigned char*) malloc(width*height*4); //TODO: nmc char type has size of 4 bytes. 
                                                                    //Perhaps it would be better to use UNSIGNED_INT_8_8_8_8
        for (srcRow = height-1, dstRow = 0; srcRow >= 0; srcRow--, dstRow++)
        {
            for (col = 0; col < width; col++)
            {
                pixel_pos = (dstRow*width + col)*4;
                pixel_value = triangle[srcRow*width + col];
				//0xARGB t0 0xRGBA
                ((unsigned char*)images[i].pixels)[pixel_pos] = (pixel_value & 0x00ff0000) >> 16;
                ((unsigned char*)images[i].pixels)[pixel_pos + 1] = (pixel_value & 0x0000ff00) >> 8;
                ((unsigned char*)images[i].pixels)[pixel_pos + 2] = (pixel_value & 0x000000ff);
                ((unsigned char*)images[i].pixels)[pixel_pos + 3] = (pixel_value & 0xff000000) >> 24;
            }
        }
        
        triangle += windows[i].height * windows[i].width;

        // for (dstRow = 0; dstRow < height; dstRow++)
        // {
            // for (col = 0; col < width; col++)
            // {
                // printf ("%08x ", ((int*)images[i].pixels)[dstRow*width + col]);
            // }
        // printf ("\n\n");            
        // }
  
        // printf ("\n\n");   
    }
    
    
    
    return 0;
}

#endif //__NM__
