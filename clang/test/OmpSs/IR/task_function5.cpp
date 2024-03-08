// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs
// RUN: %clang_cc1 -triple x86_64-gnu-linux -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=LIN64
// RUN: %clang_cc1 -triple ppc64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=PPC64
// RUN: %clang_cc1 -triple aarch64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=AARCH64
// expected-no-diagnostics
struct half {
  int x;
};
#pragma oss task
void foo(half a);

int main(){
    half a;
    foo(a);
    #pragma oss taskwait
}
// LIN64-LABEL: define {{[^@]+}}@main
// LIN64-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[A:%.*]] = alloca [[STRUCT_HALF:%.*]], align 4
// LIN64-NEXT:    [[CALL_ARG:%.*]] = alloca [[STRUCT_HALF]], align 4
// LIN64-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[CALL_ARG]], ptr align 4 [[A]], i64 4, i1 false), !dbg [[DBG9:![0-9]+]]
// LIN64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], [[STRUCT_HALF]] undef), "QUAL.OSS.DEVICE.DEVFUNC"([12 x i8] c"_Z3foo4half\00"), "QUAL.OSS.DECL.SOURCE"([23 x i8] c"task_function5.cpp:9:9\00") ], !dbg [[DBG10:![0-9]+]]
// LIN64-NEXT:    [[AGG_TMP:%.*]] = alloca [[STRUCT_HALF]], align 4
// LIN64-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[AGG_TMP]], ptr align 4 [[CALL_ARG]], i64 4, i1 false), !dbg [[DBG9]]
// LIN64-NEXT:    [[COERCE_DIVE:%.*]] = getelementptr inbounds [[STRUCT_HALF]], ptr [[AGG_TMP]], i32 0, i32 0, !dbg [[DBG10]]
// LIN64-NEXT:    [[TMP1:%.*]] = load i32, ptr [[COERCE_DIVE]], align 4, !dbg [[DBG10]]
// LIN64-NEXT:    call void @_Z3foo4half(i32 [[TMP1]]), !dbg [[DBG10]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG10]]
// LIN64-NEXT:    [[TMP2:%.*]] = call i1 @llvm.directive.marker() [ "DIR.OSS"([9 x i8] c"TASKWAIT\00") ], !dbg [[DBG11:![0-9]+]]
// LIN64-NEXT:    ret i32 0, !dbg [[DBG12:![0-9]+]]
//
//
// PPC64-LABEL: define {{[^@]+}}@main
// PPC64-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[A:%.*]] = alloca [[STRUCT_HALF:%.*]], align 4
// PPC64-NEXT:    [[CALL_ARG:%.*]] = alloca [[STRUCT_HALF]], align 4
// PPC64-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[CALL_ARG]], ptr align 4 [[A]], i64 4, i1 false), !dbg [[DBG9:![0-9]+]]
// PPC64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], [[STRUCT_HALF]] undef), "QUAL.OSS.DEVICE.DEVFUNC"([12 x i8] c"_Z3foo4half\00"), "QUAL.OSS.DECL.SOURCE"([23 x i8] c"task_function5.cpp:9:9\00") ], !dbg [[DBG10:![0-9]+]]
// PPC64-NEXT:    [[AGG_TMP:%.*]] = alloca [[STRUCT_HALF]], align 4
// PPC64-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[AGG_TMP]], ptr align 4 [[CALL_ARG]], i64 4, i1 false), !dbg [[DBG9]]
// PPC64-NEXT:    [[COERCE_DIVE:%.*]] = getelementptr inbounds [[STRUCT_HALF]], ptr [[AGG_TMP]], i32 0, i32 0, !dbg [[DBG10]]
// PPC64-NEXT:    [[TMP1:%.*]] = load i32, ptr [[COERCE_DIVE]], align 4, !dbg [[DBG10]]
// PPC64-NEXT:    call void @_Z3foo4half(i32 [[TMP1]]), !dbg [[DBG10]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG10]]
// PPC64-NEXT:    [[TMP2:%.*]] = call i1 @llvm.directive.marker() [ "DIR.OSS"([9 x i8] c"TASKWAIT\00") ], !dbg [[DBG11:![0-9]+]]
// PPC64-NEXT:    ret i32 0, !dbg [[DBG12:![0-9]+]]
//
//
// AARCH64-LABEL: define {{[^@]+}}@main
// AARCH64-SAME: () #[[ATTR0:[0-9]+]] !dbg [[DBG5:![0-9]+]] {
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[A:%.*]] = alloca [[STRUCT_HALF:%.*]], align 4
// AARCH64-NEXT:    [[CALL_ARG:%.*]] = alloca [[STRUCT_HALF]], align 4
// AARCH64-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[CALL_ARG]], ptr align 4 [[A]], i64 4, i1 false), !dbg [[DBG9:![0-9]+]]
// AARCH64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[CALL_ARG]], [[STRUCT_HALF]] undef), "QUAL.OSS.DEVICE.DEVFUNC"([12 x i8] c"_Z3foo4half\00"), "QUAL.OSS.DECL.SOURCE"([23 x i8] c"task_function5.cpp:9:9\00") ], !dbg [[DBG10:![0-9]+]]
// AARCH64-NEXT:    [[AGG_TMP:%.*]] = alloca [[STRUCT_HALF]], align 4
// AARCH64-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 4 [[AGG_TMP]], ptr align 4 [[CALL_ARG]], i64 4, i1 false), !dbg [[DBG9]]
// AARCH64-NEXT:    [[COERCE_DIVE:%.*]] = getelementptr inbounds [[STRUCT_HALF]], ptr [[AGG_TMP]], i32 0, i32 0, !dbg [[DBG10]]
// AARCH64-NEXT:    [[TMP1:%.*]] = load i32, ptr [[COERCE_DIVE]], align 4, !dbg [[DBG10]]
// AARCH64-NEXT:    [[COERCE_VAL_II:%.*]] = zext i32 [[TMP1]] to i64, !dbg [[DBG10]]
// AARCH64-NEXT:    call void @_Z3foo4half(i64 [[COERCE_VAL_II]]), !dbg [[DBG10]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG10]]
// AARCH64-NEXT:    [[TMP2:%.*]] = call i1 @llvm.directive.marker() [ "DIR.OSS"([9 x i8] c"TASKWAIT\00") ], !dbg [[DBG11:![0-9]+]]
// AARCH64-NEXT:    ret i32 0, !dbg [[DBG12:![0-9]+]]
//
