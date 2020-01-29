//****************************************************************************************
// This is automaticly generated asm-file by profiler-gcc.lua
//****************************************************************************************
import from "nmprofiler.mlb";
begin ".text_nmprofiler"
PROFILE_BEGIN(16);

/* FUNCTION(__ZN11DepthBuffer6updateEv,"__ZN11DepthBuffer6updateEv");// 0x0000000027000210 [.text]
FUNCTION(_halCopyRISC,    "_halCopyRISC    ");// 0x0000000027000396 [.text]
FUNCTION(_print_32x,      "_print_32x      ");// 0x00000000270003be [.text]
NONCFUNC(LShift32,        "LShift32        ");// 0x0000000027000c66 [.text]
FUNCTION(LShift64,        "LShift64        ");// 0x0000000027000cf2 [.text]
NONCFUNC(Mul32,           "Mul32           ");// 0x0000000027000e0e [.text]
NONCFUNC(Mul32Ex,         "Mul32Ex         ");// 0x0000000027000e28 [.text]
FUNCTION(Mul64,           "Mul64           ");// 0x0000000027000e44 [.text]
NONCFUNC(ARShift32,       "ARShift32       ");// 0x0000000027000ef0 [.text]
NONCFUNC(DAdd,            "DAdd            ");// 0x0000000027000f7c [.text]
NONCFUNC(DFrExp,          "DFrExp          ");// 0x000000002700103c [.text]
NONCFUNC(DResult,         "DResult         ");// 0x000000002700107e [.text]
NONCFUNC(DCmp,            "DCmp            ");// 0x000000002700118e [.text]
NONCFUNC(DDiv,            "DDiv            ");// 0x00000000270011e0 [.text]
NONCFUNC(UDiv32,          "UDiv32          ");// 0x00000000270012a4 [.text]
NONCFUNC(IDiv32,          "IDiv32          ");// 0x00000000270012b6 [.text]
FUNCTION(IDiv64,          "IDiv64          ");// 0x0000000027001324 [.text]
FUNCTION(UDiv64,          "UDiv64          ");// 0x000000002700138a [.text]
NONCFUNC(DMul,            "DMul            ");// 0x00000000270013a8 [.text]
NONCFUNC(ConvDtoI32,      "ConvDtoI32      ");// 0x000000002700145a [.text]
NONCFUNC(ConvI32toD,      "ConvI32toD      ");// 0x00000000270014ba [.text]
NONCFUNC(UMod32,          "UMod32          ");// 0x00000000270014d6 [.text]
NONCFUNC(IMod32,          "IMod32          ");// 0x0000000027001502 [.text]
FUNCTION(UMod64,          "UMod64          ");// 0x0000000027001538 [.text]
FUNCTION(IMod64,          "IMod64          ");// 0x0000000027001574 [.text]
NONCFUNC(RShift32,        "RShift32        ");// 0x00000000270015c0 [.text]
FUNCTION(RShift64,        "RShift64        ");// 0x000000002700164c [.text]
NONCFUNC(ConvU32toD,      "ConvU32toD      ");// 0x0000000027001768 [.text]
FUNCTION(__open,          "__open          ");// 0x0000000027001780 [.text]
FUNCTION(__close,         "__close         ");// 0x00000000270017ca [.text]
FUNCTION(__read,          "__read          ");// 0x00000000270017e0 [.text]
FUNCTION(__write,         "__write         ");// 0x000000002700180c [.text]
FUNCTION(__kill,          "__kill          ");// 0x0000000027001888 [.text]
FUNCTION(__getpid,        "__getpid        ");// 0x0000000027001892 [.text]
FUNCTION(__lseek,         "__lseek         ");// 0x000000002700189c [.text]
FUNCTION(__stat,          "__stat          ");// 0x00000000270018da [.text]
FUNCTION(__fstat,         "__fstat         ");// 0x00000000270019de [.text]
FUNCTION(__isatty,        "__isatty        ");// 0x0000000027001a7e [.text]
FUNCTION(__link,          "__link          ");// 0x0000000027001a88 [.text]
FUNCTION(__unlink,        "__unlink        ");// 0x0000000027001a92 [.text]
FUNCTION(_printf,         "_printf         ");// 0x0000000027001d9c [.text_printf] */
FUNCTION(__Z9drawLinesP16NMGL_Context_NM1,"__Z9drawLinesP16NMGL_Context_NM1");// 0x0000000000000200 [.text_demo3d]
FUNCTION(__Z13drawTrianglesP16NMGL_Context_NM1,"__Z13drawTrianglesP16NMGL_Context_NM1");// 0x00000000000005a6 [.text_demo3d]
FUNCTION(__Z13getAddrPtrnsLP16NMGL_Context_NM1P8PatternsP8Polygons,"__Z13getAddrPtrnsLP16NMGL_Context_NM1P8PatternsP8Polygons");// 0x0000000000000922 [.text_demo3d]
FUNCTION(__Z13getAddrPtrnsTP16NMGL_Context_NM1P8PatternsP8Polygons,"__Z13getAddrPtrnsTP16NMGL_Context_NM1P8PatternsP8Polygons");// 0x000000000000092a [.text_demo3d]
FUNCTION(__Z8cbUpdatev,   "__Z8cbUpdatev   ");// 0x0000000000000d4e [.text_demo3d]
FUNCTION(__Z7msdInitv,    "__Z7msdInitv    ");// 0x0000000000000dd4 [.text_demo3d]
FUNCTION(__Z6msdAddPKvPvi,"__Z6msdAddPKvPvi");// 0x0000000000000e22 [.text_demo3d]
FUNCTION(__Z8msdAdd2DPKvPvjjjj,"__Z8msdAdd2DPKvPvjjjj");// 0x0000000000000ed6 [.text_demo3d]
FUNCTION(__Z16msdGetStatusCopyi,"__Z16msdGetStatusCopyi");// 0x0000000000000fa2 [.text_demo3d]
FUNCTION(__Z10msdWaitDmav,"__Z10msdWaitDmav");// 0x0000000000000fbc [.text_demo3d]
FUNCTION(__Z14selectPatternsPiS_S_S_S_PS_iS_,"__Z14selectPatternsPiS_S_S_S_PS_iS_");// 0x0000000000000fe6 [.text_demo3d]
FUNCTION(_absIfNegElse0,  "_absIfNegElse0  ");// 0x0000000000001062 [.text_demo3d]
FUNCTION(_copyPacket_32u, "_copyPacket_32u ");// 0x0000000000001100 [.text_demo3d]
//FUNCTION(_copyPacket_32s, "_copyPacket_32s ");// 0x0000000000001100 [.text_demo3d]
FUNCTION(_depthTest,      "_depthTest      ");// 0x000000000000119e [.text_demo3d]
FUNCTION(_totalSum,       "_totalSum       ");// 0x00000000000011d0 [.text_demo3d]
FUNCTION(_mAndVxN_32u,    "_mAndVxN_32u    ");// 0x00000000000011e2 [.text_demo3d]
FUNCTION(_mergePtrnsAddr2,"_mergePtrnsAddr2");// 0x000000000000132e [.text_demo3d]
FUNCTION(_mergePtrnsAddr3,"_mergePtrnsAddr3");// 0x0000000000001420 [.text_demo3d]
FUNCTION(_mMaskVxN_32s,   "_mMaskVxN_32s   ");// 0x0000000000001554 [.text_demo3d]
FUNCTION(_mMulCVxN_2s_v4nm8sExt,"_mMulCVxN_2s_v4nm8sExt");// 0x00000000000019a2 [.text_demo3d]
FUNCTION(_mMulCVxN_2s32sExt,"_mMulCVxN_2s32sExt");// 0x00000000000019ba [.text_demo3d]
FUNCTION(_selectColorChannel,"_selectColorChannel");// 0x0000000000001e1a [.text_demo3d]
FUNCTION(_selectPaintSide,"_selectPaintSide");// 0x0000000000001f5c [.text_demo3d]
FUNCTION(__Z13nmglvsNm1InitR16NMGL_Context_NM1,"__Z13nmglvsNm1InitR16NMGL_Context_NM1");// 0x000000002700fefc [.text_nmglvs]
FUNCTION(__Z12nmglvsNm1RunR16NMGL_Context_NM1,"__Z12nmglvsNm1RunR16NMGL_Context_NM1");// 0x0000000027010196 [.text_nmglvs]
FUNCTION(__Z13nmglvsNm1StepR16NMGL_Context_NM1,"__Z13nmglvsNm1StepR16NMGL_Context_NM1");// 0x00000000270101a8 [.text_nmglvs]
/* FUNCTION(_depthTestCore_A_r,"_depthTestCore_A_r");// 0x0000000027011700 [.text_demo3dExt]
FUNCTION(_depthTestCore_A_rw,"_depthTestCore_A_rw");// 0x0000000027011b2e [.text_demo3dExt]
FUNCTION(_depthTestCore_Gt_r,"_depthTestCore_Gt_r");// 0x0000000027011f5c [.text_demo3dExt]
FUNCTION(_depthTestCore_Gt_rw,"_depthTestCore_Gt_rw");// 0x000000002701238a [.text_demo3dExt]
FUNCTION(_depthTestCore_Lt_r,"_depthTestCore_Lt_r");// 0x00000000270127b8 [.text_demo3dExt]
FUNCTION(_depthTestCore_Lt_rw,"_depthTestCore_Lt_rw");// 0x0000000027012be6 [.text_demo3dExt]
FUNCTION(_depthTestCore_N_r,"_depthTestCore_N_r");// 0x0000000027013014 [.text_demo3dExt]
FUNCTION(_depthTestCore_N_rw,"_depthTestCore_N_rw");// 0x0000000027013442 [.text_demo3dExt] */
FUNCTION(_nmppsAddC_32s,  "_nmppsAddC_32s  ");// 0x0000000000003f74 [.text_nmplv]
FUNCTION(_nmppsAdd_32s,   "_nmppsAdd_32s   ");// 0x0000000000003f96 [.text_nmplv]
FUNCTION(_nmppsMulC_AddC32s,"_nmppsMulC_AddC32s");// 0x0000000000003fb0 [.text_nmplv]
//FUNCTION(_nmppsMulC_AddC_32s,"_nmppsMulC_AddC_32s");// 0x0000000000003fb0 [.text_nmplv]
FUNCTION(_nmppsMulC_AddV_AddC_32s,"_nmppsMulC_AddV_AddC_32s");// 0x0000000000003fd8 [.text_nmplv]
//FUNCTION(_nmppsMulC_AddV_AddC32s,"_nmppsMulC_AddV_AddC32s");// 0x0000000000003fd8 [.text_nmplv]
FUNCTION(_nmppsSub_32s,   "_nmppsSub_32s   ");// 0x0000000000004006 [.text_nmplv]
FUNCTION(_nmppsAnd_32u,   "_nmppsAnd_32u   ");// 0x0000000000004020 [.text_nmplv]
FUNCTION(_nmppsAndC_32u,  "_nmppsAndC_32u  ");// 0x0000000000004036 [.text_nmplv]
FUNCTION(_nmppsOr_32u,    "_nmppsOr_32u    ");// 0x000000000000404e [.text_nmplv]
FUNCTION(_nmppsAnd4V_64u, "_nmppsAnd4V_64u ");// 0x0000000000004064 [.text_nmplv]
FUNCTION(_nmppsSet_32s,   "_nmppsSet_32s   ");// 0x0000000000004080 [.text_nmplv]
FUNCTION(_nmppsConvert_32s8s,"_nmppsConvert_32s8s");// 0x0000000000004094 [.text_nmplv]
FUNCTION(_nmppsCopy_32s,  "_nmppsCopy_32s  ");// 0x00000000000040c4 [.text_nmplv]
FUNCTION(_nmppsRemap_32u, "_nmppsRemap_32u ");// 0x00000000000040d4 [.text_nmplv]
FUNCTION(mtr_CpyCore_nm64,"mtr_CpyCore_nm64");// 0x00000000000040f8 [.text_nmplm]
FUNCTION(_nmppmCopy_32u,  "_nmppmCopy_32u  ");// 0x0000000000004120 [.text_nmplm]
//FUNCTION(_nmppmCopy_32s,  "_nmppmCopy_32s  ");// 0x0000000000004120 [.text_nmplm]

PROFILE_END();
end ".text_nmprofiler";
