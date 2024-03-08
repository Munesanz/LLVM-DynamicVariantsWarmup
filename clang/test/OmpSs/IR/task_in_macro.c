// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s
// expected-no-diagnostics

#define N(a) _Pragma("oss task in(a)") \
{}

// CHECK-LABEL: @main(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[A:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[A]], i32 undef), "QUAL.OSS.DEP.IN"(ptr [[A]], [5 x i8] c"N(a)\00", ptr @compute_dep, ptr [[A]]) ], !dbg [[DBG9:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG9]]
// CHECK-NEXT:    ret i32 0, !dbg [[DBG10:![0-9]+]]
//
int main() {
    int a;
    N(a);
}


