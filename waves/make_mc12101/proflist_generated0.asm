//****************************************************************************************
// This is automaticly generated asm-file by profiler-gcc.lua
//****************************************************************************************
import from "nmprofiler.mlb";
begin ".text_nmprofiler"
PROFILE_BEGIN(16);

FUNCTION(__Z18nmglvsExit_mc12101v,"__Z18nmglvsExit_mc12101v");// 0x0000000020000206 [.text]
FUNCTION(__Z12nmglvsNm0Runv,"__Z12nmglvsNm0Runv");// 0x0000000020000300 [.text]
FUNCTION(__Z16nmglvsSwapBufferv,"__Z16nmglvsSwapBufferv");// 0x0000000020000340 [.text]
FUNCTION(__Z13computeNormalPK8TrianglePfi,"__Z13computeNormalPK8TrianglePfi");// 0x000000002000069e [.text]
FUNCTION(__Z11halCopy_32sPvS_i,"__Z11halCopy_32sPvS_i");// 0x0000000020000796 [.text]
FUNCTION(__Z6FillXyP8Triangleii,"__Z6FillXyP8Triangleii");// 0x00000000200007c4 [.text]
FUNCTION(__Z11printMatrixv,"__Z11printMatrixv");// 0x00000000200008aa [.text]
FUNCTION(__Z6FillZwPKfP8Triangleii,"__Z6FillZwPKfP8Triangleii");// 0x0000000020000910 [.text]
FUNCTION(_nmppsFFT256FwdInitAlloc_32fcr,"_nmppsFFT256FwdInitAlloc_32fcr");// 0x0000000020000de0 [.text]
FUNCTION(_nmppsMerge_32f, "_nmppsMerge_32f ");// 0x0000000020001064 [.text]
FUNCTION(_nmppsFFT256Inv_32fcr,"_nmppsFFT256Inv_32fcr");// 0x00000000200010a6 [.text]
//FUNCTION(_nmppsFFT256Fwd_32fcr,"_nmppsFFT256Fwd_32fcr");// 0x00000000200010a6 [.text]
/* FUNCTION(_halCopyRISC,    "_halCopyRISC    ");// 0x000000002000115c [.text]
FUNCTION(_print_32x,      "_print_32x      ");// 0x0000000020001184 [.text]
NONCFUNC(ARShift32,       "ARShift32       ");// 0x0000000020001a2c [.text]
NONCFUNC(DDiv,            "DDiv            ");// 0x0000000020001ab8 [.text]
NONCFUNC(UDiv32,          "UDiv32          ");// 0x0000000020001b7c [.text]
NONCFUNC(IDiv32,          "IDiv32          ");// 0x0000000020001b8e [.text]
NONCFUNC(DMul,            "DMul            ");// 0x0000000020001bd4 [.text]
FUNCTION(ConvDtoF,        "ConvDtoF        ");// 0x0000000020001c86 [.text]
FUNCTION(FAdd,            "FAdd            ");// 0x0000000020001cbc [.text]
FUNCTION(FFrExp,          "FFrExp          ");// 0x0000000020001d66 [.text]
FUNCTION(FResult,         "FResult         ");// 0x0000000020001da6 [.text]
FUNCTION(FCmp,            "FCmp            ");// 0x0000000020001e7a [.text]
FUNCTION(FDiv,            "FDiv            ");// 0x0000000020001ebe [.text]
FUNCTION(FMul,            "FMul            ");// 0x0000000020001f4c [.text]
FUNCTION(ConvFtoD,        "ConvFtoD        ");// 0x0000000020001fce [.text]
FUNCTION(ConvFtoI32,      "ConvFtoI32      ");// 0x0000000020002002 [.text]
FUNCTION(ConvFtoU32,      "ConvFtoU32      ");// 0x0000000020002058 [.text]
FUNCTION(ConvI32toF,      "ConvI32toF      ");// 0x0000000020002092 [.text]
NONCFUNC(LShift32,        "LShift32        ");// 0x00000000200020a8 [.text]
FUNCTION(LShift64,        "LShift64        ");// 0x0000000020002134 [.text]
NONCFUNC(Mul32,           "Mul32           ");// 0x0000000020002250 [.text]
NONCFUNC(Mul32Ex,         "Mul32Ex         ");// 0x000000002000226a [.text]
FUNCTION(Mul64,           "Mul64           ");// 0x0000000020002286 [.text]
NONCFUNC(RShift32,        "RShift32        ");// 0x00000000200022aa [.text]
FUNCTION(RShift64,        "RShift64        ");// 0x0000000020002336 [.text]
NONCFUNC(DFrExp,          "DFrExp          ");// 0x0000000020002452 [.text]
NONCFUNC(DResult,         "DResult         ");// 0x0000000020002494 [.text]
NONCFUNC(DAdd,            "DAdd            ");// 0x000000002000262c [.text]
NONCFUNC(DCmp,            "DCmp            ");// 0x00000000200026ec [.text]
FUNCTION(IDiv64,          "IDiv64          ");// 0x0000000020002766 [.text]
FUNCTION(UDiv64,          "UDiv64          ");// 0x00000000200027cc [.text]
NONCFUNC(ConvDtoI32,      "ConvDtoI32      ");// 0x00000000200027ea [.text]
NONCFUNC(ConvI32toD,      "ConvI32toD      ");// 0x0000000020002842 [.text]
NONCFUNC(UMod32,          "UMod32          ");// 0x000000002000285e [.text]
NONCFUNC(IMod32,          "IMod32          ");// 0x000000002000288a [.text]
FUNCTION(UMod64,          "UMod64          ");// 0x00000000200028c0 [.text]
FUNCTION(IMod64,          "IMod64          ");// 0x00000000200028fc [.text]
NONCFUNC(ConvU32toD,      "ConvU32toD      ");// 0x0000000020002948 [.text]
FUNCTION(__open,          "__open          ");// 0x0000000020002960 [.text]
FUNCTION(__close,         "__close         ");// 0x00000000200029aa [.text]
FUNCTION(__read,          "__read          ");// 0x00000000200029c0 [.text]
FUNCTION(__write,         "__write         ");// 0x00000000200029ec [.text]
FUNCTION(__kill,          "__kill          ");// 0x0000000020002a68 [.text]
FUNCTION(__getpid,        "__getpid        ");// 0x0000000020002a72 [.text]
FUNCTION(__lseek,         "__lseek         ");// 0x0000000020002a7c [.text]
FUNCTION(__stat,          "__stat          ");// 0x0000000020002aba [.text]
FUNCTION(__fstat,         "__fstat         ");// 0x0000000020002bbe [.text]
FUNCTION(__isatty,        "__isatty        ");// 0x0000000020002c5e [.text]
FUNCTION(__link,          "__link          ");// 0x0000000020002c68 [.text]
FUNCTION(__unlink,        "__unlink        ");// 0x0000000020002c72 [.text]
FUNCTION(__Z13nmglvsNm0Initv,"__Z13nmglvsNm0Initv");// 0x0000000020002d80 [.text_nmglvs]
FUNCTION(_printf,         "_printf         ");// 0x0000000020003664 [.text_printf]
FUNCTION(_nmppsCos_32f,   "_nmppsCos_32f   ");// 0x0000000000000200 [.text_int]
FUNCTION(_nmppsDiv_32f,   "_nmppsDiv_32f   ");// 0x000000000000055a [.text_int]
FUNCTION(_nmppsExp_32f,   "_nmppsExp_32f   ");// 0x000000000000092c [.text_int]
FUNCTION(_nmppsLn_32f,    "_nmppsLn_32f    ");// 0x0000000000000cb6 [.text_int]
FUNCTION(_nmppsSin_32f,   "_nmppsSin_32f   ");// 0x000000000000107e [.text_int]
FUNCTION(_set_fp_ccr,     "_set_fp_ccr     ");// 0x00000000000013dc [.text_int] */
//FUNCTION(__Z9nmglClearj,  "__Z9nmglClearj  ");// 0x0000000020012b90 [.text_nmgl]
//FUNCTION(__Z14nmglClearColorffff,"__Z14nmglClearColorffff");// 0x0000000020012c56 [.text_nmgl]
//FUNCTION(__Z15nmglClearDepthff,"__Z15nmglClearDepthff");// 0x0000000020012d52 [.text_nmgl]
//FUNCTION(__Z16nmglColorPointerijiPKv,"__Z16nmglColorPointerijiPKv");// 0x0000000020012e3a [.text_nmgl]
//FUNCTION(__Z12nmglCullFacej,"__Z12nmglCullFacej");// 0x0000000020012e8a [.text_nmgl]
//FUNCTION(__Z13nmglDepthFuncj,"__Z13nmglDepthFuncj");// 0x0000000020012eb0 [.text_nmgl]
//FUNCTION(__Z13nmglDepthMaskb,"__Z13nmglDepthMaskb");// 0x0000000020012f90 [.text_nmgl]
//FUNCTION(__Z15nmglDepthRangefff,"__Z15nmglDepthRangefff");// 0x0000000020013056 [.text_nmgl]
//FUNCTION(__Z11nmglDisablej,"__Z11nmglDisablej");// 0x0000000020013112 [.text_nmgl]
//FUNCTION(__Z22nmglDisableClientStatej,"__Z22nmglDisableClientStatej");// 0x00000000200132e2 [.text_nmgl]
FUNCTION(__Z14nmglDrawArraysjii,"__Z14nmglDrawArraysjii");// 0x0000000020013318 [.text_nmgl]
//FUNCTION(__Z10nmglEnablej,"__Z10nmglEnablej");// 0x000000002001393c [.text_nmgl]
//FUNCTION(__Z21nmglEnableClientStatej,"__Z21nmglEnableClientStatej");// 0x0000000020013b0a [.text_nmgl]
//FUNCTION(__Z10nmglFinishv,"__Z10nmglFinishv");// 0x0000000020013b40 [.text_nmgl]
//FUNCTION(__Z13nmglFrontFacej,"__Z13nmglFrontFacej");// 0x0000000020013c4a [.text_nmgl]
//FUNCTION(__Z12nmglFrustumfffffff,"__Z12nmglFrustumfffffff");// 0x0000000020013c70 [.text_nmgl]
//FUNCTION(__Z12nmglGetErrorv,"__Z12nmglGetErrorv");// 0x0000000020013d4a [.text_nmgl]
//FUNCTION(__Z13nmglGetFloatvjPf,"__Z13nmglGetFloatvjPf");// 0x0000000020013d52 [.text_nmgl]
//FUNCTION(__Z15nmglGetIntegervjPi,"__Z15nmglGetIntegervjPi");// 0x0000000020013de4 [.text_nmgl]
//FUNCTION(__Z10nmglLightfjjf,"__Z10nmglLightfjjf");// 0x0000000020013dee [.text_nmgl]
//FUNCTION(__Z11nmglLightfvjjPKf,"__Z11nmglLightfvjjPKf");// 0x0000000020013eda [.text_nmgl]
//FUNCTION(__Z16nmglLoadIdentityv,"__Z16nmglLoadIdentityv");// 0x00000000200140b8 [.text_nmgl]
//FUNCTION(__Z13nmglMaterialfjjf,"__Z13nmglMaterialfjjf");// 0x00000000200140d2 [.text_nmgl]
//FUNCTION(__Z14nmglMaterialfvjjPKf,"__Z14nmglMaterialfvjjPKf");// 0x0000000020014126 [.text_nmgl]
//FUNCTION(__Z14nmglMatrixModej,"__Z14nmglMatrixModej");// 0x0000000020014232 [.text_nmgl]
//FUNCTION(__Z15nmglMultMatrixfPKf,"__Z15nmglMultMatrixfPKf");// 0x0000000020014268 [.text_nmgl]
//FUNCTION(__Z17nmglNormalPointerjiPKv,"__Z17nmglNormalPointerjiPKv");// 0x0000000020014290 [.text_nmgl]
//FUNCTION(__Z19nmglNormalPointerNMjiPKv,"__Z19nmglNormalPointerNMjiPKv");// 0x00000000200142ce [.text_nmgl]
//FUNCTION(__Z10nmglOrthofffffff,"__Z10nmglOrthofffffff");// 0x000000002001430c [.text_nmgl]
//FUNCTION(__Z13nmglPopMatrixv,"__Z13nmglPopMatrixv");// 0x00000000200143dc [.text_nmgl]
//FUNCTION(__Z14nmglPushMatrixv,"__Z14nmglPushMatrixv");// 0x0000000020014400 [.text_nmgl]
//FUNCTION(__Z11nmglRotatefffff,"__Z11nmglRotatefffff");// 0x0000000020014454 [.text_nmgl]
//FUNCTION(__Z10nmglScaleffff,"__Z10nmglScaleffff");// 0x00000000200145ec [.text_nmgl]
//FUNCTION(__Z14nmglTranslateffff,"__Z14nmglTranslateffff");// 0x000000002001463c [.text_nmgl]
//FUNCTION(__Z17nmglVertexPointerijiPKv,"__Z17nmglVertexPointerijiPKv");// 0x00000000200146a4 [.text_nmgl]
//FUNCTION(__Z12nmglViewportiiii,"__Z12nmglViewportiiii");// 0x00000000200146ee [.text_nmgl]
FUNCTION(_firstNonZeroIndx_32s,"_firstNonZeroIndx_32s");// 0x0000000000001406 [.text_nmplv]
FUNCTION(_remap_32u,      "_remap_32u      ");// 0x0000000000001420 [.text_nmplv]
FUNCTION(_nmppsSqrt_32f,  "_nmppsSqrt_32f  ");// 0x0000000000001442 [.text_nmplv]
FUNCTION(_nmppsCmpGtC_v2nm32f,"_nmppsCmpGtC_v2nm32f");// 0x00000000000014e4 [.text_nmplv]
FUNCTION(_nmppsCmpLtC_v2nm32f,"_nmppsCmpLtC_v2nm32f");// 0x0000000000001514 [.text_nmplv]
FUNCTION(_nmppsAdd_32f,   "_nmppsAdd_32f   ");// 0x0000000000001544 [.text_nmplv]
FUNCTION(_nmppsMul_32f,   "_nmppsMul_32f   ");// 0x000000000000156c [.text_nmplv]
FUNCTION(_nmppsMul_ConjMul_Add_32fcr,"_nmppsMul_ConjMul_Add_32fcr");// 0x0000000000001594 [.text_nmplv]
FUNCTION(_nmppsMul_Mul_Sub_32f,"_nmppsMul_Mul_Sub_32f");// 0x00000000000015d4 [.text_nmplv]
FUNCTION(_nmppsMulC_32f,  "_nmppsMulC_32f  ");// 0x000000000000160e [.text_nmplv]
FUNCTION(_nmppsMulC_AddC_32f,"_nmppsMulC_AddC_32f");// 0x0000000000001640 [.text_nmplv]
FUNCTION(_nmppsSub_32f,   "_nmppsSub_32f   ");// 0x0000000000001678 [.text_nmplv]
FUNCTION(_nmppsSubCRev_32f,"_nmppsSubCRev_32f");// 0x00000000000016a0 [.text_nmplv]
FUNCTION(_nmppsMulC_AddV_32f,"_nmppsMulC_AddV_32f");// 0x00000000000016d8 [.text_nmplv]
FUNCTION(_nmppsMulC_AddV_AddC_32f,"_nmppsMulC_AddV_AddC_32f");// 0x0000000000001706 [.text_nmplv]
FUNCTION(_copyColorByIndices_BGRA_RGBA,"_copyColorByIndices_BGRA_RGBA");// 0x000000000000173e [.text_demo3d]
FUNCTION(__Z13copyTrianglesRK9TrianglesiRS_ii,"__Z13copyTrianglesRK9TrianglesiRS_ii");// 0x0000000000001784 [.text_demo3d]
FUNCTION(__Z21cullFaceSortTrianglesR9Triangles,"__Z21cullFaceSortTrianglesR9Triangles");// 0x0000000000001858 [.text_demo3d]
FUNCTION(__Z13fillPolygonsLP8PolygonsP5Linesiii,"__Z13fillPolygonsLP8PolygonsP5Linesiii");// 0x0000000000001b5e [.text_demo3d]
FUNCTION(__Z13fillPolygonsTP8PolygonsP9Trianglesiii,"__Z13fillPolygonsTP8PolygonsP9Trianglesiii");// 0x0000000000001b64 [.text_demo3d]
FUNCTION(__Z5lightP9s_v4nm32fS0_i,"__Z5lightP9s_v4nm32fS0_i");// 0x00000000000020d0 [.text_demo3d]
FUNCTION(__Z7pow_32fPfS_fiS_,"__Z7pow_32fPfS_fiS_");// 0x0000000000002306 [.text_demo3d]
FUNCTION(__Z17pushToTriangles_tPKfS0_S0_PK9s_v4nm32fR9Trianglesi,"__Z17pushToTriangles_tPKfS0_S0_PK9s_v4nm32fR9Trianglesi");// 0x0000000000002348 [.text_demo3d]
FUNCTION(__Z10rasterizeLP5Linesi,"__Z10rasterizeLP5Linesi");// 0x000000000000249e [.text_demo3d]
FUNCTION(__Z12waitPolygonsR22HalRingBufferConnectorI8PolygonsLi128EE,"__Z12waitPolygonsR22HalRingBufferConnectorI8PolygonsLi128EE");// 0x00000000000024a4 [.text_demo3d]
FUNCTION(__Z10rasterizeTPK9TrianglesPK11SegmentMask,"__Z10rasterizeTPK9TrianglesPK11SegmentMask");// 0x0000000000002550 [.text_demo3d]
FUNCTION(_readMaskToLimitDst,"_readMaskToLimitDst");// 0x0000000000002aa2 [.text_demo3d]
FUNCTION(__Z21reverseMatrix3x3in4x4P11s_mat4nm32fS0_,"__Z21reverseMatrix3x3in4x4P11s_mat4nm32fS0_");// 0x0000000000002b7e [.text_demo3d]
FUNCTION(__Z14setSegmentMaskR16NMGL_Context_NM0R9TrianglesP11SegmentMask,"__Z14setSegmentMaskR16NMGL_Context_NM0R9TrianglesP11SegmentMask");// 0x0000000000002da4 [.text_demo3d]
FUNCTION(_absIfNegElse0_32f,"_absIfNegElse0_32f");// 0x0000000000003016 [.text_demo3d]
FUNCTION(_addC_v4nm32f,   "_addC_v4nm32f   ");// 0x0000000000003040 [.text_demo3d]
FUNCTION(_clamp_32f,      "_clamp_32f      ");// 0x0000000000003076 [.text_demo3d]
FUNCTION(_cnv32f_v2v4,    "_cnv32f_v2v4    ");// 0x00000000000030be [.text_demo3d]
FUNCTION(_cnv32f_v3v4,    "_cnv32f_v3v4    ");// 0x00000000000030f0 [.text_demo3d]
FUNCTION(_copyArraysByIndices,"_copyArraysByIndices");// 0x0000000000003160 [.text_demo3d]
FUNCTION(_copyOddOffset,  "_copyOddOffset  ");// 0x0000000000003186 [.text_demo3d]
FUNCTION(_dotC_gt0_v4nm32f,"_dotC_gt0_v4nm32f");// 0x00000000000031c6 [.text_demo3d]
FUNCTION(_dotMulC_Add_v4nm32f,"_dotMulC_Add_v4nm32f");// 0x000000000000321e [.text_demo3d]
FUNCTION(_dotMulC_AddC_v4nm32f,"_dotMulC_AddC_v4nm32f");// 0x000000000000325e [.text_demo3d]
FUNCTION(_dotMulV_v4nm32f,"_dotMulV_v4nm32f");// 0x000000000000329c [.text_demo3d]
FUNCTION(_dotV_gt0_v4nm32f,"_dotV_gt0_v4nm32f");// 0x00000000000032d6 [.text_demo3d]
FUNCTION(_dotV_v4nm32f,   "_dotV_v4nm32f   ");// 0x000000000000332e [.text_demo3d]
FUNCTION(_doubleAbsIfNegElse0_32f,"_doubleAbsIfNegElse0_32f");// 0x0000000000003380 [.text_demo3d]
FUNCTION(_doubleAdd_32f,  "_doubleAdd_32f  ");// 0x00000000000033ba [.text_demo3d]
FUNCTION(_doubleClamp_32f,"_doubleClamp_32f");// 0x00000000000033f2 [.text_demo3d]
FUNCTION(_doubleMulC_32f, "_doubleMulC_32f ");// 0x000000000000344c [.text_demo3d]
FUNCTION(_doubleSub_32f,  "_doubleSub_32f  ");// 0x0000000000003484 [.text_demo3d]
FUNCTION(_doubleSubC_32f, "_doubleSubC_32f ");// 0x00000000000034bc [.text_demo3d]
FUNCTION(_fastInvSqrt,    "_fastInvSqrt    ");// 0x00000000000034f4 [.text_demo3d]
FUNCTION(_findMinMax2,    "_findMinMax2    ");// 0x0000000000003544 [.text_demo3d]
FUNCTION(_findMinMax3,    "_findMinMax3    ");// 0x0000000000003580 [.text_demo3d]
FUNCTION(_loadIdentify,   "_loadIdentify   ");// 0x00000000000035d0 [.text_demo3d]
FUNCTION(_maskEq0,        "_maskEq0        ");// 0x00000000000035de [.text_demo3d]
FUNCTION(_maskSelectionLight_RGBA_BGRA,"_maskSelectionLight_RGBA_BGRA");// 0x000000000000361a [.text_demo3d]
FUNCTION(_meanToInt2,     "_meanToInt2     ");// 0x0000000000003674 [.text_demo3d]
FUNCTION(_meanToInt3,     "_meanToInt3     ");// 0x00000000000036a8 [.text_demo3d]
FUNCTION(_mul_mat4nm32f_v4nm32f,"_mul_mat4nm32f_v4nm32f");// 0x00000000000036e4 [.text_demo3d]
FUNCTION(_mul_v4nm32f_mat4nm32f,"_mul_v4nm32f_mat4nm32f");// 0x0000000000003726 [.text_demo3d]
FUNCTION(_mulC_v4nm32f,   "_mulC_v4nm32f   ");// 0x0000000000003768 [.text_demo3d]
FUNCTION(_readMask,       "_readMask       ");// 0x00000000000037a0 [.text_demo3d]
FUNCTION(_replaceEq0_32f, "_replaceEq0_32f ");// 0x00000000000037d2 [.text_demo3d]
FUNCTION(_set_v4nm32f,    "_set_v4nm32f    ");// 0x00000000000037fe [.text_demo3d]
FUNCTION(_sortByY2,       "_sortByY2       ");// 0x0000000000003828 [.text_demo3d]
FUNCTION(_sortByY3,       "_sortByY3       ");// 0x000000000000385e [.text_demo3d]
FUNCTION(_split_v2nm32f,  "_split_v2nm32f  ");// 0x00000000000038bc [.text_demo3d]
FUNCTION(_split_v4nm32f,  "_split_v4nm32f  ");// 0x00000000000038fc [.text_demo3d]
FUNCTION(_subCRev_v4nm32f,"_subCRev_v4nm32f");// 0x0000000000003968 [.text_demo3d]
FUNCTION(_ternaryLt0_AddC_AddC_32f,"_ternaryLt0_AddC_AddC_32f");// 0x000000000000399e [.text_demo3d]
FUNCTION(_tripleMulC_32f, "_tripleMulC_32f ");// 0x00000000000039ec [.text_demo3d]

PROFILE_END();
end ".text_nmprofiler";
