// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -disable-O0-optnone \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vsext_vf4_i32mf2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vsext.nxv1i32.nxv1i8.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vsext_vf4_i32mf2_tu(vint32mf2_t maskedoff, vint8mf8_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32mf2_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vsext.nxv2i32.nxv2i8.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vsext_vf4_i32m1_tu(vint32m1_t maskedoff, vint8mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m1_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vsext.nxv4i32.nxv4i8.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vsext_vf4_i32m2_tu(vint32m2_t maskedoff, vint8mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m2_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vsext.nxv8i32.nxv8i8.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vsext_vf4_i32m4_tu(vint32m4_t maskedoff, vint8m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m4_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vsext.nxv16i32.nxv16i8.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i8> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vsext_vf4_i32m8_tu(vint32m8_t maskedoff, vint8m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m8_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vsext.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i16> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vsext_vf4_i64m1_tu(vint64m1_t maskedoff, vint16mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m1_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vsext.nxv2i64.nxv2i16.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i16> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vsext_vf4_i64m2_tu(vint64m2_t maskedoff, vint16mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m2_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vsext.nxv4i64.nxv4i16.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i16> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vsext_vf4_i64m4_tu(vint64m4_t maskedoff, vint16m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m4_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vsext.nxv8i64.nxv8i16.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i16> [[OP1:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vsext_vf4_i64m8_tu(vint64m8_t maskedoff, vint16m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m8_tu(maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32mf2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vsext.mask.nxv1i32.nxv1i8.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vsext_vf4_i32mf2_tum(vbool64_t mask, vint32mf2_t maskedoff, vint8mf8_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32mf2_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vsext.mask.nxv2i32.nxv2i8.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vsext_vf4_i32m1_tum(vbool32_t mask, vint32m1_t maskedoff, vint8mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m1_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vsext.mask.nxv4i32.nxv4i8.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vsext_vf4_i32m2_tum(vbool16_t mask, vint32m2_t maskedoff, vint8mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m2_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vsext.mask.nxv8i32.nxv8i8.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vsext_vf4_i32m4_tum(vbool8_t mask, vint32m4_t maskedoff, vint8m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m4_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vsext.mask.nxv16i32.nxv16i8.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vsext_vf4_i32m8_tum(vbool4_t mask, vint32m8_t maskedoff, vint8m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m8_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vsext.mask.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i16> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vsext_vf4_i64m1_tum(vbool64_t mask, vint64m1_t maskedoff, vint16mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m1_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vsext.mask.nxv2i64.nxv2i16.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i16> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vsext_vf4_i64m2_tum(vbool32_t mask, vint64m2_t maskedoff, vint16mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m2_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vsext.mask.nxv4i64.nxv4i16.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i16> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vsext_vf4_i64m4_tum(vbool16_t mask, vint64m4_t maskedoff, vint16m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m4_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vsext.mask.nxv8i64.nxv8i16.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vsext_vf4_i64m8_tum(vbool8_t mask, vint64m8_t maskedoff, vint16m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m8_tum(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32mf2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vsext.mask.nxv1i32.nxv1i8.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vsext_vf4_i32mf2_tumu(vbool64_t mask, vint32mf2_t maskedoff, vint8mf8_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32mf2_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vsext.mask.nxv2i32.nxv2i8.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vsext_vf4_i32m1_tumu(vbool32_t mask, vint32m1_t maskedoff, vint8mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m1_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vsext.mask.nxv4i32.nxv4i8.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vsext_vf4_i32m2_tumu(vbool16_t mask, vint32m2_t maskedoff, vint8mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m2_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vsext.mask.nxv8i32.nxv8i8.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vsext_vf4_i32m4_tumu(vbool8_t mask, vint32m4_t maskedoff, vint8m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m4_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vsext.mask.nxv16i32.nxv16i8.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vsext_vf4_i32m8_tumu(vbool4_t mask, vint32m8_t maskedoff, vint8m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m8_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vsext.mask.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i16> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vsext_vf4_i64m1_tumu(vbool64_t mask, vint64m1_t maskedoff, vint16mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m1_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vsext.mask.nxv2i64.nxv2i16.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i16> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vsext_vf4_i64m2_tumu(vbool32_t mask, vint64m2_t maskedoff, vint16mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m2_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vsext.mask.nxv4i64.nxv4i16.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i16> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vsext_vf4_i64m4_tumu(vbool16_t mask, vint64m4_t maskedoff, vint16m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m4_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vsext.mask.nxv8i64.nxv8i16.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vsext_vf4_i64m8_tumu(vbool8_t mask, vint64m8_t maskedoff, vint16m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m8_tumu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32mf2_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vsext.mask.nxv1i32.nxv1i8.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], <vscale x 1 x i8> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vsext_vf4_i32mf2_mu(vbool64_t mask, vint32mf2_t maskedoff, vint8mf8_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32mf2_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m1_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vsext.mask.nxv2i32.nxv2i8.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], <vscale x 2 x i8> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vsext_vf4_i32m1_mu(vbool32_t mask, vint32m1_t maskedoff, vint8mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m1_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m2_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vsext.mask.nxv4i32.nxv4i8.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], <vscale x 4 x i8> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vsext_vf4_i32m2_mu(vbool16_t mask, vint32m2_t maskedoff, vint8mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m2_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m4_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vsext.mask.nxv8i32.nxv8i8.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], <vscale x 8 x i8> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vsext_vf4_i32m4_mu(vbool8_t mask, vint32m4_t maskedoff, vint8m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m4_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i32m8_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vsext.mask.nxv16i32.nxv16i8.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], <vscale x 16 x i8> [[OP1:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vsext_vf4_i32m8_mu(vbool4_t mask, vint32m8_t maskedoff, vint8m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i32m8_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m1_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vsext.mask.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], <vscale x 1 x i16> [[OP1:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vsext_vf4_i64m1_mu(vbool64_t mask, vint64m1_t maskedoff, vint16mf4_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m1_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m2_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vsext.mask.nxv2i64.nxv2i16.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], <vscale x 2 x i16> [[OP1:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vsext_vf4_i64m2_mu(vbool32_t mask, vint64m2_t maskedoff, vint16mf2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m2_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m4_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vsext.mask.nxv4i64.nxv4i16.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], <vscale x 4 x i16> [[OP1:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vsext_vf4_i64m4_mu(vbool16_t mask, vint64m4_t maskedoff, vint16m1_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m4_mu(mask, maskedoff, op1, vl);
}

// CHECK-RV64-LABEL: @test_vsext_vf4_i64m8_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vsext.mask.nxv8i64.nxv8i16.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], <vscale x 8 x i16> [[OP1:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vsext_vf4_i64m8_mu(vbool8_t mask, vint64m8_t maskedoff, vint16m2_t op1, size_t vl) {
  return __riscv_vsext_vf4_i64m8_mu(mask, maskedoff, op1, vl);
}

