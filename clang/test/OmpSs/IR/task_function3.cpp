// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs
// RUN: %clang_cc1 -triple x86_64-gnu-linux -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=LIN64
// RUN: %clang_cc1 -triple ppc64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=PPC64
// RUN: %clang_cc1 -triple aarch64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=AARCH64
// expected-no-diagnostics

struct S {
    int x;
    #pragma oss task
    void foo1(int x) {}
};

void bar() {
    S s;
    s.foo1(1 + 2);
    S *p;
    p->foo1(1 + 2);
}

// LIN64-LABEL: define {{[^@]+}}@_Z3barv
// LIN64-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[S:%.*]] = alloca [[STRUCT_S:%.*]], align 4
// LIN64-NEXT:    [[CALL_ARG:%.*]] = alloca i32, align 4
// LIN64-NEXT:    [[CALL_ARG1:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    [[P:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    [[CALL_ARG2:%.*]] = alloca i32, align 4
// LIN64-NEXT:    [[CALL_ARG3:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    store i32 3, ptr [[CALL_ARG]], align 4, !dbg [[DBG9:![0-9]+]]
// LIN64-NEXT:    store ptr [[S]], ptr [[CALL_ARG1]], align 8, !dbg [[DBG10:![0-9]+]]
// LIN64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[CALL_ARG1]], align 8, !dbg [[DBG10]]
// LIN64-NEXT:    [[TMP1:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[TMP0]], [[STRUCT_S]] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], i32 undef), "QUAL.OSS.DEVICE.DEVFUNC"([13 x i8] c"_ZN1S4foo1Ei\00"), "QUAL.OSS.DECL.SOURCE"([24 x i8] c"task_function3.cpp:9:13\00") ], !dbg [[DBG11:![0-9]+]]
// LIN64-NEXT:    [[TMP2:%.*]] = load i32, ptr [[CALL_ARG]], align 4, !dbg [[DBG9]]
// LIN64-NEXT:    call void @_ZN1S4foo1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[TMP0]], i32 noundef [[TMP2]]), !dbg [[DBG11]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP1]]), !dbg [[DBG11]]
// LIN64-NEXT:    store i32 3, ptr [[CALL_ARG2]], align 4, !dbg [[DBG12:![0-9]+]]
// LIN64-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG13:![0-9]+]]
// LIN64-NEXT:    store ptr [[TMP3]], ptr [[CALL_ARG3]], align 8, !dbg [[DBG13]]
// LIN64-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[CALL_ARG3]], align 8, !dbg [[DBG13]]
// LIN64-NEXT:    [[TMP5:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[TMP4]], [[STRUCT_S]] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG2]], i32 undef), "QUAL.OSS.DEVICE.DEVFUNC"([13 x i8] c"_ZN1S4foo1Ei\00"), "QUAL.OSS.DECL.SOURCE"([24 x i8] c"task_function3.cpp:9:13\00") ], !dbg [[DBG14:![0-9]+]]
// LIN64-NEXT:    [[TMP6:%.*]] = load i32, ptr [[CALL_ARG2]], align 4, !dbg [[DBG12]]
// LIN64-NEXT:    call void @_ZN1S4foo1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[TMP4]], i32 noundef [[TMP6]]), !dbg [[DBG14]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP5]]), !dbg [[DBG14]]
// LIN64-NEXT:    ret void, !dbg [[DBG15:![0-9]+]]
//
//
// LIN64-LABEL: define {{[^@]+}}@_ZN1S4foo1Ei
// LIN64-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]], i32 noundef [[X:%.*]]) #[[ATTR0]] comdat align 2 !dbg [[DBG16:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    [[X_ADDR:%.*]] = alloca i32, align 4
// LIN64-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// LIN64-NEXT:    store i32 [[X]], ptr [[X_ADDR]], align 4
// LIN64-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// LIN64-NEXT:    ret void, !dbg [[DBG17:![0-9]+]]
//
//
// PPC64-LABEL: define {{[^@]+}}@_Z3barv
// PPC64-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[S:%.*]] = alloca [[STRUCT_S:%.*]], align 4
// PPC64-NEXT:    [[CALL_ARG:%.*]] = alloca i32, align 4
// PPC64-NEXT:    [[CALL_ARG1:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    [[P:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    [[CALL_ARG2:%.*]] = alloca i32, align 4
// PPC64-NEXT:    [[CALL_ARG3:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    store i32 3, ptr [[CALL_ARG]], align 4, !dbg [[DBG9:![0-9]+]]
// PPC64-NEXT:    store ptr [[S]], ptr [[CALL_ARG1]], align 8, !dbg [[DBG10:![0-9]+]]
// PPC64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[CALL_ARG1]], align 8, !dbg [[DBG10]]
// PPC64-NEXT:    [[TMP1:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[TMP0]], [[STRUCT_S]] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], i32 undef), "QUAL.OSS.DEVICE.DEVFUNC"([13 x i8] c"_ZN1S4foo1Ei\00"), "QUAL.OSS.DECL.SOURCE"([24 x i8] c"task_function3.cpp:9:13\00") ], !dbg [[DBG11:![0-9]+]]
// PPC64-NEXT:    [[TMP2:%.*]] = load i32, ptr [[CALL_ARG]], align 4, !dbg [[DBG9]]
// PPC64-NEXT:    call void @_ZN1S4foo1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[TMP0]], i32 noundef signext [[TMP2]]), !dbg [[DBG11]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP1]]), !dbg [[DBG11]]
// PPC64-NEXT:    store i32 3, ptr [[CALL_ARG2]], align 4, !dbg [[DBG12:![0-9]+]]
// PPC64-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG13:![0-9]+]]
// PPC64-NEXT:    store ptr [[TMP3]], ptr [[CALL_ARG3]], align 8, !dbg [[DBG13]]
// PPC64-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[CALL_ARG3]], align 8, !dbg [[DBG13]]
// PPC64-NEXT:    [[TMP5:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[TMP4]], [[STRUCT_S]] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG2]], i32 undef), "QUAL.OSS.DEVICE.DEVFUNC"([13 x i8] c"_ZN1S4foo1Ei\00"), "QUAL.OSS.DECL.SOURCE"([24 x i8] c"task_function3.cpp:9:13\00") ], !dbg [[DBG14:![0-9]+]]
// PPC64-NEXT:    [[TMP6:%.*]] = load i32, ptr [[CALL_ARG2]], align 4, !dbg [[DBG12]]
// PPC64-NEXT:    call void @_ZN1S4foo1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[TMP4]], i32 noundef signext [[TMP6]]), !dbg [[DBG14]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP5]]), !dbg [[DBG14]]
// PPC64-NEXT:    ret void, !dbg [[DBG15:![0-9]+]]
//
//
// PPC64-LABEL: define {{[^@]+}}@_ZN1S4foo1Ei
// PPC64-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]], i32 noundef signext [[X:%.*]]) #[[ATTR0]] comdat align 2 !dbg [[DBG16:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    [[X_ADDR:%.*]] = alloca i32, align 4
// PPC64-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// PPC64-NEXT:    store i32 [[X]], ptr [[X_ADDR]], align 4
// PPC64-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// PPC64-NEXT:    ret void, !dbg [[DBG17:![0-9]+]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@_Z3barv
// AARCH64-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[S:%.*]] = alloca [[STRUCT_S:%.*]], align 4
// AARCH64-NEXT:    [[CALL_ARG:%.*]] = alloca i32, align 4
// AARCH64-NEXT:    [[CALL_ARG1:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    [[P:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    [[CALL_ARG2:%.*]] = alloca i32, align 4
// AARCH64-NEXT:    [[CALL_ARG3:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    store i32 3, ptr [[CALL_ARG]], align 4, !dbg [[DBG9:![0-9]+]]
// AARCH64-NEXT:    store ptr [[S]], ptr [[CALL_ARG1]], align 8, !dbg [[DBG10:![0-9]+]]
// AARCH64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[CALL_ARG1]], align 8, !dbg [[DBG10]]
// AARCH64-NEXT:    [[TMP1:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[TMP0]], [[STRUCT_S]] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], i32 undef), "QUAL.OSS.DEVICE.DEVFUNC"([13 x i8] c"_ZN1S4foo1Ei\00"), "QUAL.OSS.DECL.SOURCE"([24 x i8] c"task_function3.cpp:9:13\00") ], !dbg [[DBG11:![0-9]+]]
// AARCH64-NEXT:    [[TMP2:%.*]] = load i32, ptr [[CALL_ARG]], align 4, !dbg [[DBG9]]
// AARCH64-NEXT:    call void @_ZN1S4foo1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[TMP0]], i32 noundef [[TMP2]]), !dbg [[DBG11]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP1]]), !dbg [[DBG11]]
// AARCH64-NEXT:    store i32 3, ptr [[CALL_ARG2]], align 4, !dbg [[DBG12:![0-9]+]]
// AARCH64-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG13:![0-9]+]]
// AARCH64-NEXT:    store ptr [[TMP3]], ptr [[CALL_ARG3]], align 8, !dbg [[DBG13]]
// AARCH64-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[CALL_ARG3]], align 8, !dbg [[DBG13]]
// AARCH64-NEXT:    [[TMP5:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[TMP4]], [[STRUCT_S]] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG2]], i32 undef), "QUAL.OSS.DEVICE.DEVFUNC"([13 x i8] c"_ZN1S4foo1Ei\00"), "QUAL.OSS.DECL.SOURCE"([24 x i8] c"task_function3.cpp:9:13\00") ], !dbg [[DBG14:![0-9]+]]
// AARCH64-NEXT:    [[TMP6:%.*]] = load i32, ptr [[CALL_ARG2]], align 4, !dbg [[DBG12]]
// AARCH64-NEXT:    call void @_ZN1S4foo1Ei(ptr noundef nonnull align 4 dereferenceable(4) [[TMP4]], i32 noundef [[TMP6]]), !dbg [[DBG14]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP5]]), !dbg [[DBG14]]
// AARCH64-NEXT:    ret void, !dbg [[DBG15:![0-9]+]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@_ZN1S4foo1Ei
// AARCH64-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[THIS:%.*]], i32 noundef [[X:%.*]]) #[[ATTR0]] comdat align 2 !dbg [[DBG16:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[THIS_ADDR:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    [[X_ADDR:%.*]] = alloca i32, align 4
// AARCH64-NEXT:    store ptr [[THIS]], ptr [[THIS_ADDR]], align 8
// AARCH64-NEXT:    store i32 [[X]], ptr [[X_ADDR]], align 4
// AARCH64-NEXT:    [[THIS1:%.*]] = load ptr, ptr [[THIS_ADDR]], align 8
// AARCH64-NEXT:    ret void, !dbg [[DBG17:![0-9]+]]
//