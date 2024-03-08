// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vzext.nxv1i64.nxv1i8.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vzext_vf8_u64m1_tu(vuint64m1_t maskedoff, vuint8mf8_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m1_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vzext.nxv2i64.nxv2i8.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vzext_vf8_u64m2_tu(vuint64m2_t maskedoff, vuint8mf4_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m2_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vzext.nxv4i64.nxv4i8.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vzext_vf8_u64m4_tu(vuint64m4_t maskedoff, vuint8mf2_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m4_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vzext.nxv8i64.nxv8i8.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vzext_vf8_u64m8_tu(vuint64m8_t maskedoff, vuint8m1_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m8_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vzext.mask.nxv1i64.nxv1i8.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vzext_vf8_u64m1_tum(vbool64_t mask, vuint64m1_t maskedoff, vuint8mf8_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m1_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vzext.mask.nxv2i64.nxv2i8.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vzext_vf8_u64m2_tum(vbool32_t mask, vuint64m2_t maskedoff, vuint8mf4_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m2_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vzext.mask.nxv4i64.nxv4i8.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vzext_vf8_u64m4_tum(vbool16_t mask, vuint64m4_t maskedoff, vuint8mf2_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m4_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vzext.mask.nxv8i64.nxv8i8.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vzext_vf8_u64m8_tum(vbool8_t mask, vuint64m8_t maskedoff, vuint8m1_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m8_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vzext.mask.nxv1i64.nxv1i8.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vzext_vf8_u64m1_tumu(vbool64_t mask, vuint64m1_t maskedoff, vuint8mf8_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m1_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vzext.mask.nxv2i64.nxv2i8.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vzext_vf8_u64m2_tumu(vbool32_t mask, vuint64m2_t maskedoff, vuint8mf4_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m2_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vzext.mask.nxv4i64.nxv4i8.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vzext_vf8_u64m4_tumu(vbool16_t mask, vuint64m4_t maskedoff, vuint8mf2_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m4_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vzext.mask.nxv8i64.nxv8i8.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vzext_vf8_u64m8_tumu(vbool8_t mask, vuint64m8_t maskedoff, vuint8m1_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m8_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m1_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vzext.mask.nxv1i64.nxv1i8.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vzext_vf8_u64m1_mu(vbool64_t mask, vuint64m1_t maskedoff, vuint8mf8_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m1_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m2_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vzext.mask.nxv2i64.nxv2i8.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vzext_vf8_u64m2_mu(vbool32_t mask, vuint64m2_t maskedoff, vuint8mf4_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m2_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m4_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vzext.mask.nxv4i64.nxv4i8.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vzext_vf8_u64m4_mu(vbool16_t mask, vuint64m4_t maskedoff, vuint8mf2_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m4_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vzext_vf8_u64m8_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vzext.mask.nxv8i64.nxv8i8.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vzext_vf8_u64m8_mu(vbool8_t mask, vuint64m8_t maskedoff, vuint8m1_t op1, size_t vl) {
  return __riscv_vzext_vf8_u64m8_mu(mask, maskedoff, op1, vl);
}

