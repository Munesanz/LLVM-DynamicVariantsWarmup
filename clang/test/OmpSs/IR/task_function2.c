// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs
// RUN: %clang_cc1 -triple x86_64-gnu-linux -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=LIN64
// RUN: %clang_cc1 -triple ppc64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=PPC64
// RUN: %clang_cc1 -triple aarch64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=AARCH64
// expected-no-diagnostics

#pragma oss task depend(mutexinoutset: p[1 : 5]) concurrent(p[1 ; 5])
void foo1(int *p) {}

void bar() {
    foo1(0);
}




void bar1(int *p) {
    #pragma oss task weakcommutative(*p)
    {}
}


// LIN64-LABEL: define {{[^@]+}}@foo1
// LIN64-SAME: (ptr noundef [[P:%.*]]) #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// LIN64-NEXT:    ret void, !dbg [[DBG9:![0-9]+]]
//
//
// LIN64-LABEL: define {{[^@]+}}@bar
// LIN64-SAME: () #[[ATTR0]] !dbg [[DBG10:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[CALL_ARG:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    store ptr null, ptr [[CALL_ARG]], align 8, !dbg [[DBG11:![0-9]+]]
// LIN64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], ptr undef), "QUAL.OSS.DEVICE.DEVFUNC"([5 x i8] c"foo1\00"), "QUAL.OSS.DEP.CONCURRENT"(ptr [[CALL_ARG]], [9 x i8] c"p[1
// LIN64-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[CALL_ARG]], align 8, !dbg [[DBG11]]
// LIN64-NEXT:    call void @foo1(ptr noundef [[TMP1]]), !dbg [[DBG12:![0-9]+]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG12]]
// LIN64-NEXT:    ret void, !dbg [[DBG13:![0-9]+]]
//
//
// LIN64-LABEL: define {{[^@]+}}@compute_dep
// LIN64-SAME: (ptr [[P:%.*]]) #[[ATTR2:[0-9]+]] !dbg [[DBG14:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T:%.*]], align 8
// LIN64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// LIN64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG15:![0-9]+]]
// LIN64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 0
// LIN64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// LIN64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 1
// LIN64-NEXT:    store i64 20, ptr [[TMP2]], align 8
// LIN64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 2
// LIN64-NEXT:    store i64 4, ptr [[TMP3]], align 8
// LIN64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 3
// LIN64-NEXT:    store i64 24, ptr [[TMP4]], align 8
// LIN64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], align 8, !dbg [[DBG15]]
// LIN64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T]] [[TMP5]], !dbg [[DBG15]]
//
//
// LIN64-LABEL: define {{[^@]+}}@compute_dep.1
// LIN64-SAME: (ptr [[P:%.*]]) #[[ATTR2]] !dbg [[DBG17:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_0:%.*]], align 8
// LIN64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// LIN64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG18:![0-9]+]]
// LIN64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 0
// LIN64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// LIN64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 1
// LIN64-NEXT:    store i64 20, ptr [[TMP2]], align 8
// LIN64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 2
// LIN64-NEXT:    store i64 4, ptr [[TMP3]], align 8
// LIN64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 3
// LIN64-NEXT:    store i64 24, ptr [[TMP4]], align 8
// LIN64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], align 8, !dbg [[DBG18]]
// LIN64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_0]] [[TMP5]], !dbg [[DBG18]]
//
//
// LIN64-LABEL: define {{[^@]+}}@bar1
// LIN64-SAME: (ptr noundef [[P:%.*]]) #[[ATTR0]] !dbg [[DBG20:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// LIN64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P_ADDR]], ptr undef), "QUAL.OSS.DEP.WEAKCOMMUTATIVE"(ptr [[P_ADDR]], [3 x i8] c"*p\00", ptr @compute_dep.2, ptr [[P_ADDR]]) ], !dbg [[DBG21:![0-9]+]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG22:![0-9]+]]
// LIN64-NEXT:    ret void, !dbg [[DBG23:![0-9]+]]
//
//
// LIN64-LABEL: define {{[^@]+}}@compute_dep.2
// LIN64-SAME: (ptr [[P:%.*]]) #[[ATTR2]] !dbg [[DBG24:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_1:%.*]], align 8
// LIN64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// LIN64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG25:![0-9]+]]
// LIN64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 0
// LIN64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// LIN64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 1
// LIN64-NEXT:    store i64 4, ptr [[TMP2]], align 8
// LIN64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 2
// LIN64-NEXT:    store i64 0, ptr [[TMP3]], align 8
// LIN64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 3
// LIN64-NEXT:    store i64 4, ptr [[TMP4]], align 8
// LIN64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], align 8, !dbg [[DBG25]]
// LIN64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_1]] [[TMP5]], !dbg [[DBG25]]
//
//
// PPC64-LABEL: define {{[^@]+}}@foo1
// PPC64-SAME: (ptr noundef [[P:%.*]]) #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// PPC64-NEXT:    ret void, !dbg [[DBG9:![0-9]+]]
//
//
// PPC64-LABEL: define {{[^@]+}}@bar
// PPC64-SAME: () #[[ATTR0]] !dbg [[DBG10:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[CALL_ARG:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    store ptr null, ptr [[CALL_ARG]], align 8, !dbg [[DBG11:![0-9]+]]
// PPC64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], ptr undef), "QUAL.OSS.DEVICE.DEVFUNC"([5 x i8] c"foo1\00"), "QUAL.OSS.DEP.CONCURRENT"(ptr [[CALL_ARG]], [9 x i8] c"p[1
// PPC64-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[CALL_ARG]], align 8, !dbg [[DBG11]]
// PPC64-NEXT:    call void @foo1(ptr noundef [[TMP1]]), !dbg [[DBG12:![0-9]+]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG12]]
// PPC64-NEXT:    ret void, !dbg [[DBG13:![0-9]+]]
//
//
// PPC64-LABEL: define {{[^@]+}}@compute_dep
// PPC64-SAME: (ptr [[P:%.*]]) !dbg [[DBG14:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T:%.*]], align 8
// PPC64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// PPC64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG15:![0-9]+]]
// PPC64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 0
// PPC64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// PPC64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 1
// PPC64-NEXT:    store i64 20, ptr [[TMP2]], align 8
// PPC64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 2
// PPC64-NEXT:    store i64 4, ptr [[TMP3]], align 8
// PPC64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 3
// PPC64-NEXT:    store i64 24, ptr [[TMP4]], align 8
// PPC64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], align 8, !dbg [[DBG15]]
// PPC64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T]] [[TMP5]], !dbg [[DBG15]]
//
//
// PPC64-LABEL: define {{[^@]+}}@compute_dep.1
// PPC64-SAME: (ptr [[P:%.*]]) !dbg [[DBG17:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_0:%.*]], align 8
// PPC64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// PPC64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG18:![0-9]+]]
// PPC64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 0
// PPC64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// PPC64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 1
// PPC64-NEXT:    store i64 20, ptr [[TMP2]], align 8
// PPC64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 2
// PPC64-NEXT:    store i64 4, ptr [[TMP3]], align 8
// PPC64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 3
// PPC64-NEXT:    store i64 24, ptr [[TMP4]], align 8
// PPC64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], align 8, !dbg [[DBG18]]
// PPC64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_0]] [[TMP5]], !dbg [[DBG18]]
//
//
// PPC64-LABEL: define {{[^@]+}}@bar1
// PPC64-SAME: (ptr noundef [[P:%.*]]) #[[ATTR0]] !dbg [[DBG20:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// PPC64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P_ADDR]], ptr undef), "QUAL.OSS.DEP.WEAKCOMMUTATIVE"(ptr [[P_ADDR]], [3 x i8] c"*p\00", ptr @compute_dep.2, ptr [[P_ADDR]]) ], !dbg [[DBG21:![0-9]+]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG22:![0-9]+]]
// PPC64-NEXT:    ret void, !dbg [[DBG23:![0-9]+]]
//
//
// PPC64-LABEL: define {{[^@]+}}@compute_dep.2
// PPC64-SAME: (ptr [[P:%.*]]) !dbg [[DBG24:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_1:%.*]], align 8
// PPC64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// PPC64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG25:![0-9]+]]
// PPC64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 0
// PPC64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// PPC64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 1
// PPC64-NEXT:    store i64 4, ptr [[TMP2]], align 8
// PPC64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 2
// PPC64-NEXT:    store i64 0, ptr [[TMP3]], align 8
// PPC64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 3
// PPC64-NEXT:    store i64 4, ptr [[TMP4]], align 8
// PPC64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], align 8, !dbg [[DBG25]]
// PPC64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_1]] [[TMP5]], !dbg [[DBG25]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@foo1
// AARCH64-SAME: (ptr noundef [[P:%.*]]) #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// AARCH64-NEXT:    ret void, !dbg [[DBG9:![0-9]+]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@bar
// AARCH64-SAME: () #[[ATTR0]] !dbg [[DBG10:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[CALL_ARG:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    store ptr null, ptr [[CALL_ARG]], align 8, !dbg [[DBG11:![0-9]+]]
// AARCH64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], ptr undef), "QUAL.OSS.DEVICE.DEVFUNC"([5 x i8] c"foo1\00"), "QUAL.OSS.DEP.CONCURRENT"(ptr [[CALL_ARG]], [9 x i8] c"p[1
// AARCH64-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[CALL_ARG]], align 8, !dbg [[DBG11]]
// AARCH64-NEXT:    call void @foo1(ptr noundef [[TMP1]]), !dbg [[DBG12:![0-9]+]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG12]]
// AARCH64-NEXT:    ret void, !dbg [[DBG13:![0-9]+]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@compute_dep
// AARCH64-SAME: (ptr [[P:%.*]]) !dbg [[DBG14:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T:%.*]], align 8
// AARCH64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// AARCH64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG15:![0-9]+]]
// AARCH64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 0
// AARCH64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// AARCH64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 1
// AARCH64-NEXT:    store i64 20, ptr [[TMP2]], align 8
// AARCH64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 2
// AARCH64-NEXT:    store i64 4, ptr [[TMP3]], align 8
// AARCH64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 3
// AARCH64-NEXT:    store i64 24, ptr [[TMP4]], align 8
// AARCH64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], align 8, !dbg [[DBG15]]
// AARCH64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T]] [[TMP5]], !dbg [[DBG15]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@compute_dep.1
// AARCH64-SAME: (ptr [[P:%.*]]) !dbg [[DBG17:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_0:%.*]], align 8
// AARCH64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// AARCH64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG18:![0-9]+]]
// AARCH64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 0
// AARCH64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// AARCH64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 1
// AARCH64-NEXT:    store i64 20, ptr [[TMP2]], align 8
// AARCH64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 2
// AARCH64-NEXT:    store i64 4, ptr [[TMP3]], align 8
// AARCH64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 3
// AARCH64-NEXT:    store i64 24, ptr [[TMP4]], align 8
// AARCH64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], align 8, !dbg [[DBG18]]
// AARCH64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_0]] [[TMP5]], !dbg [[DBG18]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@bar1
// AARCH64-SAME: (ptr noundef [[P:%.*]]) #[[ATTR0]] !dbg [[DBG20:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// AARCH64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[P_ADDR]], ptr undef), "QUAL.OSS.DEP.WEAKCOMMUTATIVE"(ptr [[P_ADDR]], [3 x i8] c"*p\00", ptr @compute_dep.2, ptr [[P_ADDR]]) ], !dbg [[DBG21:![0-9]+]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG22:![0-9]+]]
// AARCH64-NEXT:    ret void, !dbg [[DBG23:![0-9]+]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@compute_dep.2
// AARCH64-SAME: (ptr [[P:%.*]]) !dbg [[DBG24:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_1:%.*]], align 8
// AARCH64-NEXT:    [[P_ADDR:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    store ptr [[P]], ptr [[P_ADDR]], align 8
// AARCH64-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[P]], align 8, !dbg [[DBG25:![0-9]+]]
// AARCH64-NEXT:    [[TMP1:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 0
// AARCH64-NEXT:    store ptr [[TMP0]], ptr [[TMP1]], align 8
// AARCH64-NEXT:    [[TMP2:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 1
// AARCH64-NEXT:    store i64 4, ptr [[TMP2]], align 8
// AARCH64-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 2
// AARCH64-NEXT:    store i64 0, ptr [[TMP3]], align 8
// AARCH64-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], i32 0, i32 3
// AARCH64-NEXT:    store i64 4, ptr [[TMP4]], align 8
// AARCH64-NEXT:    [[TMP5:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_1]], ptr [[RETVAL]], align 8, !dbg [[DBG25]]
// AARCH64-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_1]] [[TMP5]], !dbg [[DBG25]]
//
