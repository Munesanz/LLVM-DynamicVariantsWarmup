// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s
// expected-no-diagnostics

// CHECK-LABEL: @main(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[TMP0:%.*]] = call i1 @llvm.directive.marker() [ "DIR.OSS"([9 x i8] c"TASKWAIT\00") ], !dbg [[DBG9:![0-9]+]]
// CHECK-NEXT:    [[TMP1:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.IF"(i1 false), "QUAL.OSS.SHARED"(ptr [[A]], i32 undef), "QUAL.OSS.DEP.IN"(ptr [[A]], [2 x i8] c"a\00", ptr @compute_dep, ptr [[A]]) ], !dbg [[DBG10:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP1]]), !dbg [[DBG10]]
// CHECK-NEXT:    [[TMP2:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.IF"(i1 false), "QUAL.OSS.SHARED"(ptr [[A]], i32 undef), "QUAL.OSS.DEP.INOUT"(ptr [[A]], [2 x i8] c"a\00", ptr @compute_dep.1, ptr [[A]]) ], !dbg [[DBG11:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP2]]), !dbg [[DBG11]]
// CHECK-NEXT:    ret i32 0, !dbg [[DBG12:![0-9]+]]
//
int main(void) {
  int a;
  #pragma oss taskwait
  #pragma oss taskwait in(a)
  #pragma oss taskwait on(a)
}

