// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --full-function-signature --filter "^define |^entry:"
// RUN: %clang_cc1 -triple riscv32 -target-feature +f -target-abi ilp32f -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-C,CHECK32-C %s
// RUN: %clang_cc1 -triple riscv32 -target-feature +f -target-feature +d -target-abi ilp32d -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-C,CHECK32-C %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +f -target-abi lp64f -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-C,CHECK64-C %s
// RUN: %clang_cc1 -triple riscv64 -target-feature +f -target-feature +d -target-abi lp64d -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-C,CHECK64-C %s
// RUN: %clang_cc1 -x c++ -triple riscv32 -target-feature +f -target-abi ilp32f -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-CXX,CHECK32-CXX %s
// RUN: %clang_cc1 -x c++ -triple riscv32 -target-feature +f -target-feature +d -target-abi ilp32d -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-CXX,CHECK32-CXX %s
// RUN: %clang_cc1 -x c++ -triple riscv64 -target-feature +f -target-abi lp64f -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-CXX,CHECK64-CXX %s
// RUN: %clang_cc1 -x c++ -triple riscv64 -target-feature +f -target-feature +d -target-abi lp64d -emit-llvm %s -o - \
// RUN:   | FileCheck -check-prefixes=CHECK-CXX,CHECK64-CXX %s

#include <stdint.h>

// Fields containing empty structs or unions are ignored when flattening
// structs for the hard FP ABIs, even in C++.
// FIXME: This isn't currently respected.

struct empty { struct { struct { } e; }; };
struct s1 { struct empty e; float f; };

// CHECK-C-LABEL: define dso_local float @test_s1
// CHECK-C-SAME: (float [[TMP0:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-C:  entry:
//
// CHECK32-CXX-LABEL: define dso_local [2 x i32] @_Z7test_s12s1
// CHECK32-CXX-SAME: ([2 x i32] [[A_COERCE:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK32-CXX:  entry:
//
// CHECK64-CXX-LABEL: define dso_local i64 @_Z7test_s12s1
// CHECK64-CXX-SAME: (i64 [[A_COERCE:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK64-CXX:  entry:
//
struct s1 test_s1(struct s1 a) {
  return a;
}

struct s2 { struct empty e; int32_t i; float f; };

// CHECK-C-LABEL: define dso_local { i32, float } @test_s2
// CHECK-C-SAME: (i32 [[TMP0:%.*]], float [[TMP1:%.*]]) #[[ATTR0]] {
// CHECK-C:  entry:
//
// CHECK32-CXX-LABEL: define dso_local void @_Z7test_s22s2
// CHECK32-CXX-SAME: (ptr noalias sret([[STRUCT_S2:%.*]]) align 4 [[AGG_RESULT:%.*]], ptr noundef [[A:%.*]]) #[[ATTR0]] {
// CHECK32-CXX:  entry:
//
// CHECK64-CXX-LABEL: define dso_local [2 x i64] @_Z7test_s22s2
// CHECK64-CXX-SAME: ([2 x i64] [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK64-CXX:  entry:
//
struct s2 test_s2(struct s2 a) {
  return a;
}

struct s3 { struct empty e; float f; float g; };

// CHECK-C-LABEL: define dso_local { float, float } @test_s3
// CHECK-C-SAME: (float [[TMP0:%.*]], float [[TMP1:%.*]]) #[[ATTR0]] {
// CHECK-C:  entry:
//
// CHECK32-CXX-LABEL: define dso_local void @_Z7test_s32s3
// CHECK32-CXX-SAME: (ptr noalias sret([[STRUCT_S3:%.*]]) align 4 [[AGG_RESULT:%.*]], ptr noundef [[A:%.*]]) #[[ATTR0]] {
// CHECK32-CXX:  entry:
//
// CHECK64-CXX-LABEL: define dso_local [2 x i64] @_Z7test_s32s3
// CHECK64-CXX-SAME: ([2 x i64] [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK64-CXX:  entry:
//
struct s3 test_s3(struct s3 a) {
  return a;
}

struct s4 { struct empty e; float __complex__ c; };

// CHECK-C-LABEL: define dso_local { float, float } @test_s4
// CHECK-C-SAME: (float [[TMP0:%.*]], float [[TMP1:%.*]]) #[[ATTR0]] {
// CHECK-C:  entry:
//
// CHECK32-CXX-LABEL: define dso_local void @_Z7test_s42s4
// CHECK32-CXX-SAME: (ptr noalias sret([[STRUCT_S4:%.*]]) align 4 [[AGG_RESULT:%.*]], ptr noundef [[A:%.*]]) #[[ATTR0]] {
// CHECK32-CXX:  entry:
//
// CHECK64-CXX-LABEL: define dso_local [2 x i64] @_Z7test_s42s4
// CHECK64-CXX-SAME: ([2 x i64] [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK64-CXX:  entry:
//
struct s4 test_s4(struct s4 a) {
  return a;
}

// An array of empty fields isn't ignored in C++ (this isn't explicit in the
// psABI, but matches observed g++ behaviour).

struct s5 { struct empty e[1]; float f; };

// CHECK-C-LABEL: define dso_local float @test_s5
// CHECK-C-SAME: (float [[TMP0:%.*]]) #[[ATTR0]] {
// CHECK-C:  entry:
//
// CHECK32-CXX-LABEL: define dso_local [2 x i32] @_Z7test_s52s5
// CHECK32-CXX-SAME: ([2 x i32] [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK32-CXX:  entry:
//
// CHECK64-CXX-LABEL: define dso_local i64 @_Z7test_s52s5
// CHECK64-CXX-SAME: (i64 [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK64-CXX:  entry:
//
struct s5 test_s5(struct s5 a) {
  return a;
}

struct empty_arr { struct { struct { } e[1]; }; };
struct s6 { struct empty_arr e; float f; };

// CHECK-C-LABEL: define dso_local float @test_s6
// CHECK-C-SAME: (float [[TMP0:%.*]]) #[[ATTR0]] {
// CHECK-C:  entry:
//
// CHECK32-CXX-LABEL: define dso_local [2 x i32] @_Z7test_s62s6
// CHECK32-CXX-SAME: ([2 x i32] [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK32-CXX:  entry:
//
// CHECK64-CXX-LABEL: define dso_local i64 @_Z7test_s62s6
// CHECK64-CXX-SAME: (i64 [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK64-CXX:  entry:
//
struct s6 test_s6(struct s6 a) {
  return a;
}

struct s7 { struct empty e[0]; float f; };

// CHECK-C-LABEL: define dso_local float @test_s7
// CHECK-C-SAME: (float [[TMP0:%.*]]) #[[ATTR0]] {
// CHECK-C:  entry:
//
// CHECK-CXX-LABEL: define dso_local float @_Z7test_s72s7
// CHECK-CXX-SAME: (float [[TMP0:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-CXX:  entry:
//
struct s7 test_s7(struct s7 a) {
  return a;
}

struct empty_arr0 { struct { struct { } e[0]; }; };
struct s8 { struct empty_arr0 e; float f; };

// CHECK-C-LABEL: define dso_local float @test_s8
// CHECK-C-SAME: (float [[TMP0:%.*]]) #[[ATTR0]] {
// CHECK-C:  entry:
//
// CHECK32-CXX-LABEL: define dso_local i32 @_Z7test_s82s8
// CHECK32-CXX-SAME: (i32 [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK32-CXX:  entry:
//
// CHECK64-CXX-LABEL: define dso_local i64 @_Z7test_s82s8
// CHECK64-CXX-SAME: (i64 [[A_COERCE:%.*]]) #[[ATTR0]] {
// CHECK64-CXX:  entry:
//
struct s8 test_s8(struct s8 a) {
  return a;
}

//// NOTE: These prefixes are unused and the list is autogenerated. Do not add tests below this line:
// CHECK32-C: {{.*}}
// CHECK64-C: {{.*}}
