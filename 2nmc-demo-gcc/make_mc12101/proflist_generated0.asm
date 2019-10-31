//****************************************************************************************
// This is automaticly generated asm-file by profiler-gcc.lua
//****************************************************************************************
import from "nmprofiler.mlb";
begin ".text_nmprofiler"
PROFILE_BEGIN(16);

FUNCTION(__Z16nmglvsSwapBufferv,"__Z16nmglvsSwapBufferv");// 0x0000000020000490 [.text]
FUNCTION(_nmppsMerge_32f, "_nmppsMerge_32f ");// 0x0000000020000b1c [.text]
FUNCTION(_MullMatrix_f,   "_MullMatrix_f   ");// 0x0000000020000b5e [.text]
/*FUNCTION(_print_32x,      "_print_32x      ");// 0x0000000020000dc8 [.text]
NONCFUNC(ARShift32,       "ARShift32       ");// 0x0000000020000e08 [.text]
NONCFUNC(DAdd,            "DAdd            ");// 0x0000000020000e94 [.text]
NONCFUNC(DFrExp,          "DFrExp          ");// 0x0000000020000f54 [.text]
NONCFUNC(DResult,         "DResult         ");// 0x0000000020000f96 [.text]
NONCFUNC(DCmp,            "DCmp            ");// 0x00000000200010a6 [.text]
NONCFUNC(DDiv,            "DDiv            ");// 0x00000000200010f8 [.text]
NONCFUNC(UDiv32,          "UDiv32          ");// 0x00000000200011bc [.text]
NONCFUNC(IDiv32,          "IDiv32          ");// 0x00000000200011ce [.text]
FUNCTION(IDiv64,          "IDiv64          ");// 0x000000002000123c [.text]
FUNCTION(UDiv64,          "UDiv64          ");// 0x00000000200012a2 [.text]
NONCFUNC(DMul,            "DMul            ");// 0x00000000200012c0 [.text]
FUNCTION(ConvDtoF,        "ConvDtoF        ");// 0x0000000020001372 [.text]
NONCFUNC(ConvDtoI32,      "ConvDtoI32      ");// 0x00000000200013a8 [.text]
FUNCTION(FAdd,            "FAdd            ");// 0x0000000020001400 [.text]
FUNCTION(FFrExp,          "FFrExp          ");// 0x00000000200014aa [.text]
FUNCTION(FResult,         "FResult         ");// 0x00000000200014ea [.text]
FUNCTION(FCmp,            "FCmp            ");// 0x00000000200015be [.text]
FUNCTION(FDiv,            "FDiv            ");// 0x0000000020001602 [.text]
FUNCTION(FMul,            "FMul            ");// 0x0000000020001690 [.text]
FUNCTION(ConvFtoD,        "ConvFtoD        ");// 0x0000000020001712 [.text]
FUNCTION(ConvFtoI32,      "ConvFtoI32      ");// 0x0000000020001746 [.text]
NONCFUNC(ConvI32toD,      "ConvI32toD      ");// 0x000000002000179c [.text]
FUNCTION(ConvI32toF,      "ConvI32toF      ");// 0x00000000200017b8 [.text]
NONCFUNC(LShift32,        "LShift32        ");// 0x00000000200017ce [.text]
FUNCTION(LShift64,        "LShift64        ");// 0x000000002000185a [.text]
NONCFUNC(UMod32,          "UMod32          ");// 0x0000000020001976 [.text]
NONCFUNC(IMod32,          "IMod32          ");// 0x00000000200019a2 [.text]
FUNCTION(UMod64,          "UMod64          ");// 0x00000000200019d8 [.text]
FUNCTION(IMod64,          "IMod64          ");// 0x0000000020001a14 [.text]
NONCFUNC(Mul32,           "Mul32           ");// 0x0000000020001a60 [.text]
NONCFUNC(RShift32,        "RShift32        ");// 0x0000000020001a7a [.text]
FUNCTION(RShift64,        "RShift64        ");// 0x0000000020001b06 [.text]
NONCFUNC(ConvU32toD,      "ConvU32toD      ");// 0x0000000020001c22 [.text]
FUNCTION(_printf,         "_printf         ");// 0x0000000020002126 [.text_printf]*/
FUNCTION(_nmblas_scopy,   "_nmblas_scopy   ");// 0x0000000000000200 [.text_int]
//FUNCTION(_nmppsExp_32f,   "_nmppsExp_32f   ");// 0x00000000000005d2 [.text_int]
//FUNCTION(_nmppsExp_32f,   "_nmppsExp_32f   ");// 0x00000000000005d2 [.text_int]
//FUNCTION(_nmppsLn_32f,    "_nmppsLn_32f    ");// 0x000000000000095c [.text_int]
//FUNCTION(__Z7pow_32fPfS_fiS_,"__Z7pow_32fPfS_fiS_");// 0x00000000200099f0 [.text_nmgl]
/*FUNCTION(__Z9nmglClearj,  "__Z9nmglClearj  ");// 0x0000000020009a32 [.text_nmgl]
FUNCTION(__Z14nmglClearColorffff,"__Z14nmglClearColorffff");// 0x0000000020009a6a [.text_nmgl]
FUNCTION(__Z15nmglClearDepthff,"__Z15nmglClearDepthff");// 0x0000000020009ae0 [.text_nmgl]
FUNCTION(__Z16nmglColorPointerijiPKv,"__Z16nmglColorPointerijiPKv");// 0x0000000020009b28 [.text_nmgl]
FUNCTION(__Z12nmglCullFacej,"__Z12nmglCullFacej");// 0x0000000020009b78 [.text_nmgl]
FUNCTION(__Z13nmglDepthFuncj,"__Z13nmglDepthFuncj");// 0x0000000020009b9e [.text_nmgl]
FUNCTION(__Z13nmglDepthMaskb,"__Z13nmglDepthMaskb");// 0x0000000020009bf2 [.text_nmgl]
FUNCTION(__Z15nmglDepthRangefff,"__Z15nmglDepthRangefff");// 0x0000000020009c2a [.text_nmgl]
FUNCTION(__Z11nmglDisablej,"__Z11nmglDisablej");// 0x0000000020009ce4 [.text_nmgl]
FUNCTION(__Z22nmglDisableClientStatej,"__Z22nmglDisableClientStatej");// 0x0000000020009e12 [.text_nmgl]*/
FUNCTION(__Z14nmglDrawArraysjii,"__Z14nmglDrawArraysjii");// 0x0000000020009e50 [.text_nmgl]
/*FUNCTION(__Z10nmglEnablej,"__Z10nmglEnablej");// 0x000000002000a910 [.text_nmgl]
FUNCTION(__Z21nmglEnableClientStatej,"__Z21nmglEnableClientStatej");// 0x000000002000aa3e [.text_nmgl]
FUNCTION(__Z10nmglFinishv,"__Z10nmglFinishv");// 0x000000002000aa7c [.text_nmgl]
FUNCTION(__Z13nmglFrontFacej,"__Z13nmglFrontFacej");// 0x000000002000aa9c [.text_nmgl]
FUNCTION(__Z12nmglFrustumfffffff,"__Z12nmglFrustumfffffff");// 0x000000002000aac2 [.text_nmgl]
FUNCTION(__Z12nmglGetErrorv,"__Z12nmglGetErrorv");// 0x000000002000ab9c [.text_nmgl]
FUNCTION(__Z13nmglGetFloatvjPf,"__Z13nmglGetFloatvjPf");// 0x000000002000aba4 [.text_nmgl]
FUNCTION(__Z15nmglGetIntegervjPi,"__Z15nmglGetIntegervjPi");// 0x000000002000ac36 [.text_nmgl]
FUNCTION(__Z10nmglLightfjjf,"__Z10nmglLightfjjf");// 0x000000002000ac40 [.text_nmgl]
FUNCTION(__Z11nmglLightfvjjPKf,"__Z11nmglLightfvjjPKf");// 0x000000002000ad2c [.text_nmgl]
FUNCTION(__Z16nmglLoadIdentityv,"__Z16nmglLoadIdentityv");// 0x000000002000af0a [.text_nmgl]
FUNCTION(__Z13nmglMaterialfjjf,"__Z13nmglMaterialfjjf");// 0x000000002000af24 [.text_nmgl]
FUNCTION(__Z14nmglMaterialfvjjPKf,"__Z14nmglMaterialfvjjPKf");// 0x000000002000af78 [.text_nmgl]
FUNCTION(__Z14nmglMatrixModej,"__Z14nmglMatrixModej");// 0x000000002000b084 [.text_nmgl]
FUNCTION(__Z15nmglMultMatrixfPKf,"__Z15nmglMultMatrixfPKf");// 0x000000002000b0c2 [.text_nmgl]
FUNCTION(__Z17nmglNormalPointerjiPKv,"__Z17nmglNormalPointerjiPKv");// 0x000000002000b0ea [.text_nmgl]
FUNCTION(__Z19nmglNormalPointerNMjiPKv,"__Z19nmglNormalPointerNMjiPKv");// 0x000000002000b128 [.text_nmgl]
FUNCTION(__Z10nmglOrthofffffff,"__Z10nmglOrthofffffff");// 0x000000002000b166 [.text_nmgl]
FUNCTION(__Z13nmglPopMatrixv,"__Z13nmglPopMatrixv");// 0x000000002000b236 [.text_nmgl]
FUNCTION(__Z14nmglPushMatrixv,"__Z14nmglPushMatrixv");// 0x000000002000b25a [.text_nmgl]
FUNCTION(__Z11nmglRotatefffff,"__Z11nmglRotatefffff");// 0x000000002000b2ae [.text_nmgl]
FUNCTION(__Z10nmglScaleffff,"__Z10nmglScaleffff");// 0x000000002000b446 [.text_nmgl]
FUNCTION(__Z14nmglTranslateffff,"__Z14nmglTranslateffff");// 0x000000002000b496 [.text_nmgl]
FUNCTION(__Z17nmglVertexPointerijiPKv,"__Z17nmglVertexPointerijiPKv");// 0x000000002000b4fe [.text_nmgl]
FUNCTION(__Z12nmglViewportiiii,"__Z12nmglViewportiiii");// 0x000000002000b548 [.text_nmgl]*/
FUNCTION(_remap_32u,      "_remap_32u      ");// 0x0000000000000d24 [.text_nmplv]
FUNCTION(_nmppsCmpGtC_v2nm32f,"_nmppsCmpGtC_v2nm32f");// 0x0000000000000d46 [.text_nmplv]
FUNCTION(_nmppsCmpLtC_v2nm32f,"_nmppsCmpLtC_v2nm32f");// 0x0000000000000d76 [.text_nmplv]
FUNCTION(_nmppsAdd_32f,   "_nmppsAdd_32f   ");// 0x0000000000000da6 [.text_nmplv]
FUNCTION(_nmppsMul_Mul_Sub_32f,"_nmppsMul_Mul_Sub_32f");// 0x0000000000000dce [.text_nmplv]
FUNCTION(_nmppsMulC_32f,  "_nmppsMulC_32f  ");// 0x0000000000000e08 [.text_nmplv]
FUNCTION(_nmppsMulC_AddC_32f,"_nmppsMulC_AddC_32f");// 0x0000000000000e3a [.text_nmplv]
FUNCTION(_nmppsSub_32f,   "_nmppsSub_32f   ");// 0x0000000000000e72 [.text_nmplv]
FUNCTION(_nmppsSubC_32f,  "_nmppsSubC_32f  ");// 0x0000000000000e9a [.text_nmplv]
FUNCTION(_nmppsSubCRev_32f,"_nmppsSubCRev_32f");// 0x0000000000000ecc [.text_nmplv]
FUNCTION(_nmppsMulC_AddV_32f,"_nmppsMulC_AddV_32f");// 0x0000000000000f04 [.text_nmplv]
FUNCTION(_nmppsMulC_AddV_AddC_32f,"_nmppsMulC_AddV_AddC_32f");// 0x0000000000000f32 [.text_nmplv]
FUNCTION(__Z12addInstrNMC1P13HalRingBufferiiiiiii,"__Z12addInstrNMC1P13HalRingBufferiiiiiii");// 0x0000000000000f6a [.text_demo3d]
FUNCTION(_copyColorByIndices_BGRA_RGBA,"_copyColorByIndices_BGRA_RGBA");// 0x0000000000000fdc [.text_demo3d]
FUNCTION(__Z21cullFaceSortTrianglesP9Trianglesi,"__Z21cullFaceSortTrianglesP9Trianglesi");// 0x0000000000001022 [.text_demo3d]
FUNCTION(__Z13fillPolygonsLP8PolygonsP5Linesiii,"__Z13fillPolygonsLP8PolygonsP5Linesiii");// 0x0000000000001320 [.text_demo3d]
FUNCTION(__Z13fillPolygonsTP8PolygonsP9Trianglesiii,"__Z13fillPolygonsTP8PolygonsP9Trianglesiii");// 0x0000000000001326 [.text_demo3d]
FUNCTION(__Z5lightP9s_v4nm32fS0_i,"__Z5lightP9s_v4nm32fS0_i");// 0x0000000000001940 [.text_demo3d]
FUNCTION(__Z17pushToTriangles_tPKfS0_S0_PK9s_v4nm32fR9Trianglesi,"__Z17pushToTriangles_tPKfS0_S0_PK9s_v4nm32fR9Trianglesi");// 0x0000000000001c4a [.text_demo3d]
FUNCTION(__Z10rasterizeLP5Linesi,"__Z10rasterizeLP5Linesi");// 0x0000000000001d94 [.text_demo3d]
FUNCTION(__Z15getPolygonsHeadv,"__Z15getPolygonsHeadv");// 0x0000000000001d9a [.text_demo3d]
FUNCTION(__Z10rasterizeTPK9TrianglesPK11SegmentMaski,"__Z10rasterizeTPK9TrianglesPK11SegmentMaski");// 0x0000000000001dd8 [.text_demo3d]
FUNCTION(_readMask,       "_readMask       ");// 0x0000000000001fd8 [.text_demo3d]
FUNCTION(__Z21reverseMatrix3x3in4x4P11s_mat4nm32fS0_,"__Z21reverseMatrix3x3in4x4P11s_mat4nm32fS0_");// 0x000000000000208c [.text_demo3d]
FUNCTION(__Z14setSegmentMaskPK9s_v2nm32fS1_P11SegmentMaski,"__Z14setSegmentMaskPK9s_v2nm32fS1_P11SegmentMaski");// 0x00000000000022b2 [.text_demo3d]
FUNCTION(_absIfNegElse0_32f,"_absIfNegElse0_32f");// 0x00000000000023f4 [.text_demo3d]
FUNCTION(_addC_v4nm32f,   "_addC_v4nm32f   ");// 0x000000000000241e [.text_demo3d]
FUNCTION(_clamp_32f,      "_clamp_32f      ");// 0x0000000000002454 [.text_demo3d]
FUNCTION(_cnv32f_v2v4,    "_cnv32f_v2v4    ");// 0x000000000000249c [.text_demo3d]
FUNCTION(_cnv32f_v3v4,    "_cnv32f_v3v4    ");// 0x00000000000024ce [.text_demo3d]
FUNCTION(_copyArraysByIndices,"_copyArraysByIndices");// 0x000000000000253e [.text_demo3d]
FUNCTION(_copyOddOffset,  "_copyOddOffset  ");// 0x0000000000002566 [.text_demo3d]
FUNCTION(_dotC_gt0_v4nm32f,"_dotC_gt0_v4nm32f");// 0x00000000000025a6 [.text_demo3d]
FUNCTION(_dotMulC_Add_v4nm32f,"_dotMulC_Add_v4nm32f");// 0x00000000000025fe [.text_demo3d]
FUNCTION(_dotMulC_AddC_v4nm32f,"_dotMulC_AddC_v4nm32f");// 0x000000000000263e [.text_demo3d]
FUNCTION(_dotV_gt0_v4nm32f,"_dotV_gt0_v4nm32f");// 0x000000000000267c [.text_demo3d]
FUNCTION(_dotV_v4nm32f,   "_dotV_v4nm32f   ");// 0x00000000000026d4 [.text_demo3d]
FUNCTION(_findMinMax2,    "_findMinMax2    ");// 0x0000000000002726 [.text_demo3d]
FUNCTION(_findMinMax3,    "_findMinMax3    ");// 0x0000000000002762 [.text_demo3d]
FUNCTION(_loadIdentify,   "_loadIdentify   ");// 0x00000000000027b2 [.text_demo3d]
FUNCTION(_maskEq0,        "_maskEq0        ");// 0x00000000000027c0 [.text_demo3d]
FUNCTION(_maskSelectionLight_RGBA_BGRA,"_maskSelectionLight_RGBA_BGRA");// 0x00000000000027fc [.text_demo3d]
FUNCTION(_meanToInt2,     "_meanToInt2     ");// 0x0000000000002856 [.text_demo3d]
FUNCTION(_meanToInt3,     "_meanToInt3     ");// 0x0000000000002888 [.text_demo3d]
FUNCTION(_mul_mat4nm32f_v4nm32f,"_mul_mat4nm32f_v4nm32f");// 0x00000000000028c0 [.text_demo3d]
FUNCTION(_mul_v4nm32f_mat4nm32f,"_mul_v4nm32f_mat4nm32f");// 0x0000000000002902 [.text_demo3d]
FUNCTION(_mulC_v4nm32f,   "_mulC_v4nm32f   ");// 0x0000000000002944 [.text_demo3d]
FUNCTION(_replaceEq0_32f, "_replaceEq0_32f ");// 0x000000000000297c [.text_demo3d]
FUNCTION(_set_v4nm32f,    "_set_v4nm32f    ");// 0x00000000000029a8 [.text_demo3d]
FUNCTION(_sortByY2,       "_sortByY2       ");// 0x00000000000029d2 [.text_demo3d]
FUNCTION(_sortByY3,       "_sortByY3       ");// 0x0000000000002a08 [.text_demo3d]
FUNCTION(_split_v2nm32f,  "_split_v2nm32f  ");// 0x0000000000002a66 [.text_demo3d]
FUNCTION(_split_v4nm32f,  "_split_v4nm32f  ");// 0x0000000000002aa6 [.text_demo3d]
FUNCTION(_subCRev_v4nm32f,"_subCRev_v4nm32f");// 0x0000000000002b12 [.text_demo3d]
FUNCTION(_ternaryLt0_AddC_AddC_32f,"_ternaryLt0_AddC_AddC_32f");// 0x0000000000002b48 [.text_demo3d]

PROFILE_END();
end ".text_nmprofiler";
