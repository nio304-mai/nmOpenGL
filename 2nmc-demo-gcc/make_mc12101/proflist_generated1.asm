//****************************************************************************************
// This is automaticly generated asm-file by profiler-gcc.lua
//****************************************************************************************
import from "nmprofiler.mlb";
begin ".text_nmprofiler"
PROFILE_BEGIN(16);

FUNCTION(__ZN11DepthBuffer6updateEv,"__ZN11DepthBuffer6updateEv");// 0x00000000220004c4 [.text]
FUNCTION(_halCopyRISC,    "_halCopyRISC    ");// 0x00000000220005a0 [.text]
/* FUNCTION(_print_32x,      "_print_32x      ");// 0x00000000220005c8 [.text]
NONCFUNC(LShift32,        "LShift32        ");// 0x0000000022000e70 [.text]
FUNCTION(LShift64,        "LShift64        ");// 0x0000000022000efc [.text]
NONCFUNC(Mul32,           "Mul32           ");// 0x0000000022001018 [.text]
NONCFUNC(Mul32Ex,         "Mul32Ex         ");// 0x0000000022001032 [.text]
FUNCTION(Mul64,           "Mul64           ");// 0x000000002200104e [.text]
NONCFUNC(ARShift32,       "ARShift32       ");// 0x00000000220010fa [.text]
NONCFUNC(DAdd,            "DAdd            ");// 0x0000000022001186 [.text]
NONCFUNC(DFrExp,          "DFrExp          ");// 0x0000000022001246 [.text]
NONCFUNC(DResult,         "DResult         ");// 0x0000000022001288 [.text]
NONCFUNC(DCmp,            "DCmp            ");// 0x0000000022001398 [.text]
NONCFUNC(DDiv,            "DDiv            ");// 0x00000000220013ea [.text]
NONCFUNC(UDiv32,          "UDiv32          ");// 0x00000000220014ae [.text]
NONCFUNC(IDiv32,          "IDiv32          ");// 0x00000000220014c0 [.text]
FUNCTION(IDiv64,          "IDiv64          ");// 0x000000002200152e [.text]
FUNCTION(UDiv64,          "UDiv64          ");// 0x0000000022001594 [.text]
NONCFUNC(DMul,            "DMul            ");// 0x00000000220015b2 [.text]
NONCFUNC(ConvDtoI32,      "ConvDtoI32      ");// 0x0000000022001664 [.text]
NONCFUNC(ConvI32toD,      "ConvI32toD      ");// 0x00000000220016c4 [.text]
NONCFUNC(UMod32,          "UMod32          ");// 0x00000000220016e0 [.text]
NONCFUNC(IMod32,          "IMod32          ");// 0x000000002200170c [.text]
FUNCTION(UMod64,          "UMod64          ");// 0x0000000022001742 [.text]
FUNCTION(IMod64,          "IMod64          ");// 0x000000002200177e [.text]
NONCFUNC(RShift32,        "RShift32        ");// 0x00000000220017ca [.text]
FUNCTION(RShift64,        "RShift64        ");// 0x0000000022001856 [.text]
NONCFUNC(ConvU32toD,      "ConvU32toD      ");// 0x0000000022001972 [.text]
FUNCTION(__open,          "__open          ");// 0x000000002200198a [.text]
FUNCTION(__close,         "__close         ");// 0x00000000220019d4 [.text]
FUNCTION(__read,          "__read          ");// 0x00000000220019ea [.text]
FUNCTION(__write,         "__write         ");// 0x0000000022001a16 [.text]
FUNCTION(__kill,          "__kill          ");// 0x0000000022001a92 [.text]
FUNCTION(__getpid,        "__getpid        ");// 0x0000000022001a9c [.text]
FUNCTION(__lseek,         "__lseek         ");// 0x0000000022001aa6 [.text]
FUNCTION(__stat,          "__stat          ");// 0x0000000022001ae4 [.text]
FUNCTION(__fstat,         "__fstat         ");// 0x0000000022001be8 [.text]
FUNCTION(__isatty,        "__isatty        ");// 0x0000000022001c88 [.text]
FUNCTION(__link,          "__link          ");// 0x0000000022001c92 [.text]
FUNCTION(__unlink,        "__unlink        ");// 0x0000000022001c9c [.text]
FUNCTION(_printf,         "_printf         ");// 0x000000002200222e [.text_printf] */
FUNCTION(__Z16copyCounterColorv,"__Z16copyCounterColorv");// 0x0000000000000200 [.text_demo3d]
FUNCTION(__Z16copyCounterDepthv,"__Z16copyCounterDepthv");// 0x0000000000000212 [.text_demo3d]
FUNCTION(__Z9drawLinesP16NMGL_Context_NM1,"__Z9drawLinesP16NMGL_Context_NM1");// 0x0000000000000224 [.text_demo3d]
FUNCTION(__Z13drawTrianglesP16NMGL_Context_NM1,"__Z13drawTrianglesP16NMGL_Context_NM1");// 0x000000000000022a [.text_demo3d]
FUNCTION(__Z13getAddrPtrnsLP16NMGL_Context_NM1P8Polygons,"__Z13getAddrPtrnsLP16NMGL_Context_NM1P8Polygons");// 0x00000000000005ba [.text_demo3d]
FUNCTION(__Z13getAddrPtrnsTP16NMGL_Context_NM1P8Polygons,"__Z13getAddrPtrnsTP16NMGL_Context_NM1P8Polygons");// 0x00000000000005c2 [.text_demo3d]
FUNCTION(__Z8cbUpdatev,   "__Z8cbUpdatev   ");// 0x0000000000000a2a [.text_demo3d]
FUNCTION(__Z7msdInitv,    "__Z7msdInitv    ");// 0x0000000000000b70 [.text_demo3d]
FUNCTION(__Z6msdAddPKvPvii,"__Z6msdAddPKvPvii");// 0x0000000000000c70 [.text_demo3d]
FUNCTION(__Z8msdAdd2DPKvPvjjjji,"__Z8msdAdd2DPKvPvjjjji");// 0x0000000000000e52 [.text_demo3d]
FUNCTION(__Z6msdAddR9MyDmaTaski,"__Z6msdAddR9MyDmaTaski");// 0x000000000000104e [.text_demo3d]
FUNCTION(__Z16msdGetStatusCopyii,"__Z16msdGetStatusCopyii");// 0x000000000000133e [.text_demo3d]
FUNCTION(__Z10msdWaitDmav,"__Z10msdWaitDmav");// 0x0000000000001362 [.text_demo3d]
FUNCTION(__Z10msdWaitDmai,"__Z10msdWaitDmai");// 0x0000000000001432 [.text_demo3d]
FUNCTION(__Z14selectPatternsPiS_S_S_S_PS_iS_,"__Z14selectPatternsPiS_S_S_S_PS_iS_");// 0x00000000000014e2 [.text_demo3d]
FUNCTION(_absIfNegElse0,  "_absIfNegElse0  ");// 0x000000000000155e [.text_demo3d]
FUNCTION(_copyPacket_32u, "_copyPacket_32u ");// 0x00000000000015fc [.text_demo3d]
//FUNCTION(_copyPacket_32s, "_copyPacket_32s ");// 0x00000000000015fc [.text_demo3d]
FUNCTION(_depthTest,      "_depthTest      ");// 0x000000000000169a [.text_demo3d]
FUNCTION(_totalSum,       "_totalSum       ");// 0x00000000000016cc [.text_demo3d]
FUNCTION(_mAndVxN_32u,    "_mAndVxN_32u    ");// 0x00000000000016de [.text_demo3d]
FUNCTION(_merge_v4nm32s,  "_merge_v4nm32s  ");// 0x0000000000001788 [.text_demo3d]
FUNCTION(_mergePtrnsAddr2,"_mergePtrnsAddr2");// 0x00000000000017d6 [.text_demo3d]
FUNCTION(_mergePtrnsAddr3,"_mergePtrnsAddr3");// 0x00000000000018c8 [.text_demo3d]
FUNCTION(_mMaskVxN_32s,   "_mMaskVxN_32s   ");// 0x00000000000019fc [.text_demo3d]
FUNCTION(_mMulCVxN_2s_RGB8888,"_mMulCVxN_2s_RGB8888");// 0x0000000000001e4a [.text_demo3d]
FUNCTION(_mMulCVxN_2s32s, "_mMulCVxN_2s32s ");// 0x0000000000001e60 [.text_demo3d]
FUNCTION(_selectColorChannel,"_selectColorChannel");// 0x000000000000273c [.text_demo3d]
FUNCTION(_selectPaintSide,"_selectPaintSide");// 0x000000000000287e [.text_demo3d]
FUNCTION(__Z13nmglvsNm1Initv,"__Z13nmglvsNm1Initv");// 0x00000000220105de [.text_nmglvs]
FUNCTION(__Z12nmglvsNm1Runv,"__Z12nmglvsNm1Runv");// 0x0000000022010a52 [.text_nmglvs]
FUNCTION(__Z13nmglvsNm1Stepv,"__Z13nmglvsNm1Stepv");// 0x0000000022010a64 [.text_nmglvs]
FUNCTION(_depthTestCore_A_r,"_depthTestCore_A_r");// 0x000000002201204e [.text_demo3dExt]
FUNCTION(_depthTestCore_A_rw,"_depthTestCore_A_rw");// 0x000000002201247c [.text_demo3dExt]
FUNCTION(_depthTestCore_Gt_r,"_depthTestCore_Gt_r");// 0x00000000220128aa [.text_demo3dExt]
FUNCTION(_depthTestCore_Gt_rw,"_depthTestCore_Gt_rw");// 0x0000000022012cd8 [.text_demo3dExt]
FUNCTION(_depthTestCore_Lt_r,"_depthTestCore_Lt_r");// 0x0000000022013106 [.text_demo3dExt]
FUNCTION(_depthTestCore_Lt_rw,"_depthTestCore_Lt_rw");// 0x0000000022013534 [.text_demo3dExt]
FUNCTION(_depthTestCore_N_r,"_depthTestCore_N_r");// 0x0000000022013962 [.text_demo3dExt]
FUNCTION(_depthTestCore_N_rw,"_depthTestCore_N_rw");// 0x0000000022013d90 [.text_demo3dExt]
FUNCTION(_nmppsAddC_32s,  "_nmppsAddC_32s  ");// 0x0000000000004570 [.text_nmplv]
FUNCTION(_nmppsAdd_32s,   "_nmppsAdd_32s   ");// 0x0000000000004592 [.text_nmplv]
FUNCTION(_nmppsMulC_AddC32s,"_nmppsMulC_AddC32s");// 0x00000000000045ac [.text_nmplv]
//FUNCTION(_nmppsMulC_AddC_32s,"_nmppsMulC_AddC_32s");// 0x00000000000045ac [.text_nmplv]
FUNCTION(_nmppsMulC_AddV_AddC_32s,"_nmppsMulC_AddV_AddC_32s");// 0x00000000000045d4 [.text_nmplv]
//FUNCTION(_nmppsMulC_AddV_AddC32s,"_nmppsMulC_AddV_AddC32s");// 0x00000000000045d4 [.text_nmplv]
FUNCTION(_nmppsSub_32s,   "_nmppsSub_32s   ");// 0x0000000000004602 [.text_nmplv]
FUNCTION(_nmppsAnd_32u,   "_nmppsAnd_32u   ");// 0x000000000000461c [.text_nmplv]
FUNCTION(_nmppsAndC_32u,  "_nmppsAndC_32u  ");// 0x0000000000004632 [.text_nmplv]
FUNCTION(_nmppsOr_32u,    "_nmppsOr_32u    ");// 0x000000000000464a [.text_nmplv]
FUNCTION(_nmppsAnd4V_64u, "_nmppsAnd4V_64u ");// 0x0000000000004660 [.text_nmplv]
FUNCTION(_nmppsSet_32s,   "_nmppsSet_32s   ");// 0x000000000000467c [.text_nmplv]
FUNCTION(_nmppsConvert_32s8s,"_nmppsConvert_32s8s");// 0x0000000000004690 [.text_nmplv]
FUNCTION(_nmppsCopy_32s,  "_nmppsCopy_32s  ");// 0x00000000000046c0 [.text_nmplv]
FUNCTION(_nmppsRemap_32u, "_nmppsRemap_32u ");// 0x00000000000046d0 [.text_nmplv]
FUNCTION(_nmppmCopy_32u,  "_nmppmCopy_32u  ");// 0x00000000000046f4 [.text_nmplm]
//FUNCTION(_nmppmCopy_32s,  "_nmppmCopy_32s  ");// 0x00000000000046f4 [.text_nmplm]
FUNCTION(mtr_CpyCore_nm64,"mtr_CpyCore_nm64");// 0x0000000000004712 [.text_nmplm]

PROFILE_END();
end ".text_nmprofiler";
