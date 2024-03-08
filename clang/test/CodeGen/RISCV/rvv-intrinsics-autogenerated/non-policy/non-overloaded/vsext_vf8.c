// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vsext.nxv1i64.nxv1i8.i64(<vscale x 1 x i64> poison, <vscale x 1 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vsext_vf8_i64m1(vint8mf8_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m1(op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vsext.nxv2i64.nxv2i8.i64(<vscale x 2 x i64> poison, <vscale x 2 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vsext_vf8_i64m2(vint8mf4_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m2(op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vsext.nxv4i64.nxv4i8.i64(<vscale x 4 x i64> poison, <vscale x 4 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vsext_vf8_i64m4(vint8mf2_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m4(op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vsext.nxv8i64.nxv8i8.i64(<vscale x 8 x i64> poison, <vscale x 8 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vsext_vf8_i64m8(vint8m1_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m8(op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vsext.mask.nxv1i64.nxv1i8.i64(<vscale x 1 x i64> poison, <vscale x 1 x i8> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vsext_vf8_i64m1_m(vbool64_t mask, vint8mf8_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m1_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vsext.mask.nxv2i64.nxv2i8.i64(<vscale x 2 x i64> poison, <vscale x 2 x i8> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vsext_vf8_i64m2_m(vbool32_t mask, vint8mf4_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m2_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vsext.mask.nxv4i64.nxv4i8.i64(<vscale x 4 x i64> poison, <vscale x 4 x i8> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vsext_vf8_i64m4_m(vbool16_t mask, vint8mf2_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m4_m(mask, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf8_i64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vsext.mask.nxv8i64.nxv8i8.i64(<vscale x 8 x i64> poison, <vscale x 8 x i8> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vsext_vf8_i64m8_m(vbool8_t mask, vint8m1_t op1, size_t vl) {
  return __riscv_vsext_vf8_i64m8_m(mask, op1, vl);
}

