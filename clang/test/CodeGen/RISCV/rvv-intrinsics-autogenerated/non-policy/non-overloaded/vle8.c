// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vle8_v_i8mf8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.nxv1i8.i64(<vscale x 1 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
vint8mf8_t test_vle8_v_i8mf8(const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8mf8(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.nxv2i8.i64(<vscale x 2 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
vint8mf4_t test_vle8_v_i8mf4(const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8mf4(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.nxv4i8.i64(<vscale x 4 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
vint8mf2_t test_vle8_v_i8mf2(const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8mf2(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.nxv8i8.i64(<vscale x 8 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vint8m1_t test_vle8_v_i8m1(const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m1(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.nxv16i8.i64(<vscale x 16 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vint8m2_t test_vle8_v_i8m2(const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m2(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.nxv32i8.i64(<vscale x 32 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vint8m4_t test_vle8_v_i8m4(const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m4(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.nxv64i8.i64(<vscale x 64 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
vint8m8_t test_vle8_v_i8m8(const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m8(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8mf8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.nxv1i8.i64(<vscale x 1 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
vuint8mf8_t test_vle8_v_u8mf8(const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8mf8(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.nxv2i8.i64(<vscale x 2 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
vuint8mf4_t test_vle8_v_u8mf4(const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8mf4(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.nxv4i8.i64(<vscale x 4 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
vuint8mf2_t test_vle8_v_u8mf2(const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8mf2(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.nxv8i8.i64(<vscale x 8 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vuint8m1_t test_vle8_v_u8m1(const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m1(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.nxv16i8.i64(<vscale x 16 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vuint8m2_t test_vle8_v_u8m2(const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m2(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.nxv32i8.i64(<vscale x 32 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vuint8m4_t test_vle8_v_u8m4(const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m4(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.nxv64i8.i64(<vscale x 64 x i8> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
vuint8m8_t test_vle8_v_u8m8(const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m8(base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8mf8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.mask.nxv1i8.i64(<vscale x 1 x i8> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
vint8mf8_t test_vle8_v_i8mf8_m(vbool64_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8mf8_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.mask.nxv2i8.i64(<vscale x 2 x i8> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
vint8mf4_t test_vle8_v_i8mf4_m(vbool32_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8mf4_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.mask.nxv4i8.i64(<vscale x 4 x i8> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
vint8mf2_t test_vle8_v_i8mf2_m(vbool16_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8mf2_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.mask.nxv8i8.i64(<vscale x 8 x i8> poison, ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vint8m1_t test_vle8_v_i8m1_m(vbool8_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m1_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.mask.nxv16i8.i64(<vscale x 16 x i8> poison, ptr [[BASE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vint8m2_t test_vle8_v_i8m2_m(vbool4_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m2_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.mask.nxv32i8.i64(<vscale x 32 x i8> poison, ptr [[BASE:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vint8m4_t test_vle8_v_i8m4_m(vbool2_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m4_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_i8m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.mask.nxv64i8.i64(<vscale x 64 x i8> poison, ptr [[BASE:%.*]], <vscale x 64 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
vint8m8_t test_vle8_v_i8m8_m(vbool1_t mask, const int8_t *base, size_t vl) {
  return __riscv_vle8_v_i8m8_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8mf8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i8> @llvm.riscv.vle.mask.nxv1i8.i64(<vscale x 1 x i8> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i8> [[TMP0]]
//
vuint8mf8_t test_vle8_v_u8mf8_m(vbool64_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8mf8_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i8> @llvm.riscv.vle.mask.nxv2i8.i64(<vscale x 2 x i8> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i8> [[TMP0]]
//
vuint8mf4_t test_vle8_v_u8mf4_m(vbool32_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8mf4_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i8> @llvm.riscv.vle.mask.nxv4i8.i64(<vscale x 4 x i8> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i8> [[TMP0]]
//
vuint8mf2_t test_vle8_v_u8mf2_m(vbool16_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8mf2_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i8> @llvm.riscv.vle.mask.nxv8i8.i64(<vscale x 8 x i8> poison, ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i8> [[TMP0]]
//
vuint8m1_t test_vle8_v_u8m1_m(vbool8_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m1_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i8> @llvm.riscv.vle.mask.nxv16i8.i64(<vscale x 16 x i8> poison, ptr [[BASE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i8> [[TMP0]]
//
vuint8m2_t test_vle8_v_u8m2_m(vbool4_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m2_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i8> @llvm.riscv.vle.mask.nxv32i8.i64(<vscale x 32 x i8> poison, ptr [[BASE:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i8> [[TMP0]]
//
vuint8m4_t test_vle8_v_u8m4_m(vbool2_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m4_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle8_v_u8m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 64 x i8> @llvm.riscv.vle.mask.nxv64i8.i64(<vscale x 64 x i8> poison, ptr [[BASE:%.*]], <vscale x 64 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 64 x i8> [[TMP0]]
//
vuint8m8_t test_vle8_v_u8m8_m(vbool1_t mask, const uint8_t *base, size_t vl) {
  return __riscv_vle8_v_u8m8_m(mask, base, vl);
}

