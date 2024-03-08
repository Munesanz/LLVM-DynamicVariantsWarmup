// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature
// RUN: %clang_cc1 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s
// expected-no-diagnostics

#pragma oss task device(cuda) ndrange(1, 1, 1)
void foo();
#pragma oss task device(cuda) ndrange(N, *x, *y)
template <int N, typename T>
void foo1(T *x, T *y);
#pragma oss task device(cuda) ndrange(1, *x, *y)
void foo2(int *x, int *y);

// CHECK-LABEL: define {{[^@]+}}@_Z3barv
// CHECK-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[X:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[Y:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[CALL_ARG:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[CALL_ARG1:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[CALL_ARG2:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[CALL_ARG3:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.DEVICE"(i32 1), "QUAL.OSS.DEVICE.DEVFUNC"([8 x i8] c"_Z3foov\00"), "QUAL.OSS.DEVICE.NDRANGE"(i32 1, i32 1, i32 1), "QUAL.OSS.DECL.SOURCE"([21 x i8] c"task_ndrange.cpp:5:9\00") ], !dbg [[DBG9:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG9]]
// CHECK-NEXT:    store ptr [[X]], ptr [[CALL_ARG]], align 8, !dbg [[DBG10:![0-9]+]]
// CHECK-NEXT:    store ptr [[Y]], ptr [[CALL_ARG1]], align 8, !dbg [[DBG11:![0-9]+]]
// CHECK-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[CALL_ARG]], align 8, !dbg [[DBG12:![0-9]+]]
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[TMP1]], align 4, !dbg [[DBG13:![0-9]+]]
// CHECK-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[CALL_ARG1]], align 8, !dbg [[DBG14:![0-9]+]]
// CHECK-NEXT:    [[TMP4:%.*]] = load i32, ptr [[TMP3]], align 4, !dbg [[DBG15:![0-9]+]]
// CHECK-NEXT:    [[TMP5:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG1]], ptr undef), "QUAL.OSS.DEVICE"(i32 1), "QUAL.OSS.DEVICE.DEVFUNC"([23 x i8] c"_Z4foo1ILi1EiEvPT0_S1_\00"), "QUAL.OSS.DEVICE.NDRANGE"(i32 1, i32 [[TMP2]], i32 [[TMP4]]), "QUAL.OSS.DECL.SOURCE"([21 x i8] c"task_ndrange.cpp:7:9\00") ], !dbg [[DBG16:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP5]]), !dbg [[DBG16]]
// CHECK-NEXT:    store ptr [[X]], ptr [[CALL_ARG2]], align 8, !dbg [[DBG17:![0-9]+]]
// CHECK-NEXT:    store ptr [[Y]], ptr [[CALL_ARG3]], align 8, !dbg [[DBG18:![0-9]+]]
// CHECK-NEXT:    [[TMP6:%.*]] = load ptr, ptr [[CALL_ARG2]], align 8, !dbg [[DBG19:![0-9]+]]
// CHECK-NEXT:    [[TMP7:%.*]] = load i32, ptr [[TMP6]], align 4, !dbg [[DBG20:![0-9]+]]
// CHECK-NEXT:    [[TMP8:%.*]] = load ptr, ptr [[CALL_ARG3]], align 8, !dbg [[DBG21:![0-9]+]]
// CHECK-NEXT:    [[TMP9:%.*]] = load i32, ptr [[TMP8]], align 4, !dbg [[DBG22:![0-9]+]]
// CHECK-NEXT:    [[TMP10:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG2]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG3]], ptr undef), "QUAL.OSS.DEVICE"(i32 1), "QUAL.OSS.DEVICE.DEVFUNC"([12 x i8] c"_Z4foo2PiS_\00"), "QUAL.OSS.DEVICE.NDRANGE"(i32 1, i32 [[TMP7]], i32 [[TMP9]]), "QUAL.OSS.DECL.SOURCE"([22 x i8] c"task_ndrange.cpp:10:9\00") ], !dbg [[DBG23:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP10]]), !dbg [[DBG23]]
// CHECK-NEXT:    ret void, !dbg [[DBG24:![0-9]+]]
//
void bar() {
    foo();
    int x, y;
    foo1<1>(&x, &y);
    foo2(&x, &y);
}


