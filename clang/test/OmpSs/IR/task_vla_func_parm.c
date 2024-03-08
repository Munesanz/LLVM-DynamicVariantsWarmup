// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --include-generated-funcs
// RUN: %clang_cc1 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s
// expected-no-diagnostics
void foo(int sizex,
         int sizey,
         int (*p1)[sizex][sizey],
         int (**p2)[sizex][sizey],
         int *p3[sizex][sizey],
         int p4[sizex][sizey]) {
    int a;
    #pragma oss task in(p1[3], p4[2], p3[5], p2[3])
    #pragma oss task shared(p1, p4, p3, p2)
    #pragma oss task private(p1, p4, p3, p2)
    #pragma oss task firstprivate(p1, p4, p3, p2)
    {
        (*p1)[0][1] = 3;
        (*p2)[0][1][4] = 3;
        p4[2][3] = 4;
        p3[5][3] = 0;
    }
}

// Function params decay to pointer







// CHECK-LABEL: @foo(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[SIZEX_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[SIZEY_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[P1_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[P2_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[P3_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[P4_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[A:%.*]] = alloca i32, align 4
// CHECK-NEXT:    store i32 [[SIZEX:%.*]], ptr [[SIZEX_ADDR]], align 4
// CHECK-NEXT:    store i32 [[SIZEY:%.*]], ptr [[SIZEY_ADDR]], align 4
// CHECK-NEXT:    store ptr [[P1:%.*]], ptr [[P1_ADDR]], align 8
// CHECK-NEXT:    store ptr [[P2:%.*]], ptr [[P2_ADDR]], align 8
// CHECK-NEXT:    store ptr [[P3:%.*]], ptr [[P3_ADDR]], align 8
// CHECK-NEXT:    store ptr [[P4:%.*]], ptr [[P4_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[SIZEX_ADDR]], align 4, !dbg [[DBG9:![0-9]+]]
// CHECK-NEXT:    [[TMP1:%.*]] = zext i32 [[TMP0]] to i64
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[SIZEY_ADDR]], align 4, !dbg [[DBG10:![0-9]+]]
// CHECK-NEXT:    [[TMP3:%.*]] = zext i32 [[TMP2]] to i64
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[SIZEX_ADDR]], align 4, !dbg [[DBG11:![0-9]+]]
// CHECK-NEXT:    [[TMP5:%.*]] = zext i32 [[TMP4]] to i64
// CHECK-NEXT:    [[TMP6:%.*]] = load i32, ptr [[SIZEY_ADDR]], align 4, !dbg [[DBG12:![0-9]+]]
// CHECK-NEXT:    [[TMP7:%.*]] = zext i32 [[TMP6]] to i64
// CHECK-NEXT:    [[TMP8:%.*]] = load i32, ptr [[SIZEX_ADDR]], align 4, !dbg [[DBG13:![0-9]+]]
// CHECK-NEXT:    [[TMP9:%.*]] = zext i32 [[TMP8]] to i64
// CHECK-NEXT:    [[TMP10:%.*]] = load i32, ptr [[SIZEY_ADDR]], align 4, !dbg [[DBG14:![0-9]+]]
// CHECK-NEXT:    [[TMP11:%.*]] = zext i32 [[TMP10]] to i64
// CHECK-NEXT:    [[TMP12:%.*]] = load i32, ptr [[SIZEX_ADDR]], align 4, !dbg [[DBG15:![0-9]+]]
// CHECK-NEXT:    [[TMP13:%.*]] = zext i32 [[TMP12]] to i64
// CHECK-NEXT:    [[TMP14:%.*]] = load i32, ptr [[SIZEY_ADDR]], align 4, !dbg [[DBG16:![0-9]+]]
// CHECK-NEXT:    [[TMP15:%.*]] = zext i32 [[TMP14]] to i64
// CHECK-NEXT:    [[TMP16:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P1_ADDR]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P4_ADDR]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P3_ADDR]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P2_ADDR]], ptr undef), "QUAL.OSS.CAPTURED"(i64 [[TMP1]], i64 [[TMP3]], i64 [[TMP15]], i64 [[TMP11]], i64 [[TMP5]], i64 [[TMP7]]), "QUAL.OSS.DEP.IN"(ptr [[P1_ADDR]], [6 x i8] c"p1[3]\00", ptr @compute_dep, ptr [[P1_ADDR]], i64 [[TMP1]], i64 [[TMP3]]), "QUAL.OSS.DEP.IN"(ptr [[P4_ADDR]], [6 x i8] c"p4[2]\00", ptr @compute_dep.1, ptr [[P4_ADDR]], i64 [[TMP15]]), "QUAL.OSS.DEP.IN"(ptr [[P3_ADDR]], [6 x i8] c"p3[5]\00", ptr @compute_dep.2, ptr [[P3_ADDR]], i64 [[TMP11]]), "QUAL.OSS.DEP.IN"(ptr [[P2_ADDR]], [6 x i8] c"p2[3]\00", ptr @compute_dep.3, ptr [[P2_ADDR]], i64 [[TMP5]], i64 [[TMP7]]) ], !dbg [[DBG17:![0-9]+]]
// CHECK-NEXT:    [[TMP17:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[P1_ADDR]], ptr undef), "QUAL.OSS.SHARED"(ptr [[P4_ADDR]], ptr undef), "QUAL.OSS.SHARED"(ptr [[P3_ADDR]], ptr undef), "QUAL.OSS.SHARED"(ptr [[P2_ADDR]], ptr undef), "QUAL.OSS.CAPTURED"(i64 [[TMP1]], i64 [[TMP3]], i64 [[TMP15]], i64 [[TMP11]], i64 [[TMP5]], i64 [[TMP7]]) ], !dbg [[DBG18:![0-9]+]]
// CHECK-NEXT:    [[TMP18:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.PRIVATE"(ptr [[P1_ADDR]], ptr undef), "QUAL.OSS.PRIVATE"(ptr [[P4_ADDR]], ptr undef), "QUAL.OSS.PRIVATE"(ptr [[P3_ADDR]], ptr undef), "QUAL.OSS.PRIVATE"(ptr [[P2_ADDR]], ptr undef), "QUAL.OSS.CAPTURED"(i64 [[TMP1]], i64 [[TMP3]], i64 [[TMP15]], i64 [[TMP11]], i64 [[TMP5]], i64 [[TMP7]]) ], !dbg [[DBG19:![0-9]+]]
// CHECK-NEXT:    [[TMP19:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P1_ADDR]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P4_ADDR]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P3_ADDR]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P2_ADDR]], ptr undef), "QUAL.OSS.CAPTURED"(i64 [[TMP1]], i64 [[TMP3]], i64 [[TMP15]], i64 [[TMP11]], i64 [[TMP5]], i64 [[TMP7]]) ], !dbg [[DBG20:![0-9]+]]
// CHECK-NEXT:    [[TMP20:%.*]] = load ptr, ptr [[P1_ADDR]], align 8, !dbg [[DBG21:![0-9]+]]
// CHECK-NEXT:    [[TMP21:%.*]] = mul nsw i64 0, [[TMP3]], !dbg [[DBG22:![0-9]+]]
// CHECK-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds i32, ptr [[TMP20]], i64 [[TMP21]], !dbg [[DBG22]]
// CHECK-NEXT:    [[ARRAYIDX4:%.*]] = getelementptr inbounds i32, ptr [[ARRAYIDX]], i64 1, !dbg [[DBG22]]
// CHECK-NEXT:    store i32 3, ptr [[ARRAYIDX4]], align 4, !dbg [[DBG23:![0-9]+]]
// CHECK-NEXT:    [[TMP22:%.*]] = load ptr, ptr [[P2_ADDR]], align 8, !dbg [[DBG24:![0-9]+]]
// CHECK-NEXT:    [[TMP23:%.*]] = load ptr, ptr [[TMP22]], align 8, !dbg [[DBG25:![0-9]+]]
// CHECK-NEXT:    [[TMP24:%.*]] = mul nuw i64 [[TMP5]], [[TMP7]], !dbg [[DBG26:![0-9]+]]
// CHECK-NEXT:    [[TMP25:%.*]] = mul nsw i64 0, [[TMP24]], !dbg [[DBG26]]
// CHECK-NEXT:    [[ARRAYIDX5:%.*]] = getelementptr inbounds i32, ptr [[TMP23]], i64 [[TMP25]], !dbg [[DBG26]]
// CHECK-NEXT:    [[TMP26:%.*]] = mul nsw i64 1, [[TMP7]], !dbg [[DBG26]]
// CHECK-NEXT:    [[ARRAYIDX6:%.*]] = getelementptr inbounds i32, ptr [[ARRAYIDX5]], i64 [[TMP26]], !dbg [[DBG26]]
// CHECK-NEXT:    [[ARRAYIDX7:%.*]] = getelementptr inbounds i32, ptr [[ARRAYIDX6]], i64 4, !dbg [[DBG26]]
// CHECK-NEXT:    store i32 3, ptr [[ARRAYIDX7]], align 4, !dbg [[DBG27:![0-9]+]]
// CHECK-NEXT:    [[TMP27:%.*]] = load ptr, ptr [[P4_ADDR]], align 8, !dbg [[DBG28:![0-9]+]]
// CHECK-NEXT:    [[TMP28:%.*]] = mul nsw i64 2, [[TMP15]], !dbg [[DBG28]]
// CHECK-NEXT:    [[ARRAYIDX8:%.*]] = getelementptr inbounds i32, ptr [[TMP27]], i64 [[TMP28]], !dbg [[DBG28]]
// CHECK-NEXT:    [[ARRAYIDX9:%.*]] = getelementptr inbounds i32, ptr [[ARRAYIDX8]], i64 3, !dbg [[DBG28]]
// CHECK-NEXT:    store i32 4, ptr [[ARRAYIDX9]], align 4, !dbg [[DBG29:![0-9]+]]
// CHECK-NEXT:    [[TMP29:%.*]] = load ptr, ptr [[P3_ADDR]], align 8, !dbg [[DBG30:![0-9]+]]
// CHECK-NEXT:    [[TMP30:%.*]] = mul nsw i64 5, [[TMP11]], !dbg [[DBG30]]
// CHECK-NEXT:    [[ARRAYIDX10:%.*]] = getelementptr inbounds ptr, ptr [[TMP29]], i64 [[TMP30]], !dbg [[DBG30]]
// CHECK-NEXT:    [[ARRAYIDX11:%.*]] = getelementptr inbounds ptr, ptr [[ARRAYIDX10]], i64 3, !dbg [[DBG30]]
// CHECK-NEXT:    store ptr null, ptr [[ARRAYIDX11]], align 8, !dbg [[DBG31:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP19]]), !dbg [[DBG32:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP18]]), !dbg [[DBG32]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP17]]), !dbg [[DBG32]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP16]]), !dbg [[DBG32]]
// CHECK-NEXT:    ret void, !dbg [[DBG33:![0-9]+]]
//
//
// CHECK-LABEL: @compute_dep(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T:%.*]], align 8
// CHECK-NEXT:    [[P1_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTADDR1:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store ptr [[P1:%.*]], ptr [[P1_ADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP0:%.*]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP1:%.*]], ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[P1]], align 8, !dbg [[DBG35:![0-9]+]]
// CHECK-NEXT:    [[TMP3:%.*]] = mul i64 [[TMP1]], 4
// CHECK-NEXT:    [[TMP4:%.*]] = mul i64 [[TMP1]], 4
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[TMP2]], ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 1
// CHECK-NEXT:    store i64 [[TMP3]], ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 2
// CHECK-NEXT:    store i64 0, ptr [[TMP7]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 3
// CHECK-NEXT:    store i64 [[TMP4]], ptr [[TMP8]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 4
// CHECK-NEXT:    store i64 [[TMP0]], ptr [[TMP9]], align 8
// CHECK-NEXT:    [[TMP10:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 5
// CHECK-NEXT:    store i64 0, ptr [[TMP10]], align 8
// CHECK-NEXT:    [[TMP11:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 6
// CHECK-NEXT:    store i64 [[TMP0]], ptr [[TMP11]], align 8
// CHECK-NEXT:    [[TMP12:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 7
// CHECK-NEXT:    store i64 1, ptr [[TMP12]], align 8
// CHECK-NEXT:    [[TMP13:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 8
// CHECK-NEXT:    store i64 3, ptr [[TMP13]], align 8
// CHECK-NEXT:    [[TMP14:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 9
// CHECK-NEXT:    store i64 4, ptr [[TMP14]], align 8
// CHECK-NEXT:    [[TMP15:%.*]] = load [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], align 8, !dbg [[DBG35]]
// CHECK-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T]] [[TMP15]], !dbg [[DBG35]]
//
//
// CHECK-LABEL: @compute_dep.1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_0:%.*]], align 8
// CHECK-NEXT:    [[P4_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store ptr [[P4:%.*]], ptr [[P4_ADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP0:%.*]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[P4]], align 8, !dbg [[DBG38:![0-9]+]]
// CHECK-NEXT:    [[TMP2:%.*]] = mul i64 [[TMP0]], 4
// CHECK-NEXT:    [[TMP3:%.*]] = mul i64 [[TMP0]], 4
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[TMP1]], ptr [[TMP4]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 1
// CHECK-NEXT:    store i64 [[TMP2]], ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 2
// CHECK-NEXT:    store i64 0, ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 3
// CHECK-NEXT:    store i64 [[TMP3]], ptr [[TMP7]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 4
// CHECK-NEXT:    store i64 1, ptr [[TMP8]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 5
// CHECK-NEXT:    store i64 2, ptr [[TMP9]], align 8
// CHECK-NEXT:    [[TMP10:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 6
// CHECK-NEXT:    store i64 3, ptr [[TMP10]], align 8
// CHECK-NEXT:    [[TMP11:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], align 8, !dbg [[DBG38]]
// CHECK-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_0]] [[TMP11]], !dbg [[DBG38]]
//
//
// CHECK-LABEL: @compute_dep.2(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_1:%.*]], align 8
// CHECK-NEXT:    [[P3_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store ptr [[P3:%.*]], ptr [[P3_ADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP0:%.*]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[P3]], align 8, !dbg [[DBG41:![0-9]+]]
// CHECK-NEXT:    [[TMP2:%.*]] = mul i64 [[TMP0]], 8
// CHECK-NEXT:    [[TMP3:%.*]] = mul i64 [[TMP0]], 8
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[TMP1]], ptr [[TMP4]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 1
// CHECK-NEXT:    store i64 [[TMP2]], ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 2
// CHECK-NEXT:    store i64 0, ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 3
// CHECK-NEXT:    store i64 [[TMP3]], ptr [[TMP7]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 4
// CHECK-NEXT:    store i64 1, ptr [[TMP8]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 5
// CHECK-NEXT:    store i64 5, ptr [[TMP9]], align 8
// CHECK-NEXT:    [[TMP10:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 6
// CHECK-NEXT:    store i64 6, ptr [[TMP10]], align 8
// CHECK-NEXT:    [[TMP11:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], align 8, !dbg [[DBG41]]
// CHECK-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_1]] [[TMP11]], !dbg [[DBG41]]
//
//
// CHECK-LABEL: @compute_dep.3(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_2:%.*]], align 8
// CHECK-NEXT:    [[P2_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTADDR1:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store ptr [[P2:%.*]], ptr [[P2_ADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP0:%.*]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP1:%.*]], ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[P2]], align 8, !dbg [[DBG44:![0-9]+]]
// CHECK-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_2]], ptr [[RETVAL]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[TMP2]], ptr [[TMP3]], align 8
// CHECK-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_2]], ptr [[RETVAL]], i32 0, i32 1
// CHECK-NEXT:    store i64 8, ptr [[TMP4]], align 8
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_2]], ptr [[RETVAL]], i32 0, i32 2
// CHECK-NEXT:    store i64 24, ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_2]], ptr [[RETVAL]], i32 0, i32 3
// CHECK-NEXT:    store i64 32, ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_2]], ptr [[RETVAL]], align 8, !dbg [[DBG44]]
// CHECK-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_2]] [[TMP7]], !dbg [[DBG44]]
//
