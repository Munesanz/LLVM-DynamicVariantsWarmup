// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vle64_v_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vle.nxv1f64.i64(<vscale x 1 x double> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vle64_v_f64m1(const double *base, size_t vl) {
  return __riscv_vle64_v_f64m1(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_f64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vle.nxv2f64.i64(<vscale x 2 x double> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vle64_v_f64m2(const double *base, size_t vl) {
  return __riscv_vle64_v_f64m2(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_f64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vle.nxv4f64.i64(<vscale x 4 x double> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vle64_v_f64m4(const double *base, size_t vl) {
  return __riscv_vle64_v_f64m4(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_f64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vle.nxv8f64.i64(<vscale x 8 x double> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vle64_v_f64m8(const double *base, size_t vl) {
  return __riscv_vle64_v_f64m8(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vle.nxv1i64.i64(<vscale x 1 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vle64_v_i64m1(const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m1(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vle.nxv2i64.i64(<vscale x 2 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vle64_v_i64m2(const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m2(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vle.nxv4i64.i64(<vscale x 4 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vle64_v_i64m4(const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m4(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vle.nxv8i64.i64(<vscale x 8 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vle64_v_i64m8(const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m8(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vle.nxv1i64.i64(<vscale x 1 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vle64_v_u64m1(const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m1(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vle.nxv2i64.i64(<vscale x 2 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vle64_v_u64m2(const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m2(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vle.nxv4i64.i64(<vscale x 4 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vle64_v_u64m4(const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m4(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vle.nxv8i64.i64(<vscale x 8 x i64> poison, ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vle64_v_u64m8(const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m8(base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vle.mask.nxv1f64.i64(<vscale x 1 x double> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vle64_v_f64m1_m(vbool64_t mask, const double *base, size_t vl) {
  return __riscv_vle64_v_f64m1_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_f64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x double> @llvm.riscv.vle.mask.nxv2f64.i64(<vscale x 2 x double> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP0]]
//
vfloat64m2_t test_vle64_v_f64m2_m(vbool32_t mask, const double *base, size_t vl) {
  return __riscv_vle64_v_f64m2_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_f64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x double> @llvm.riscv.vle.mask.nxv4f64.i64(<vscale x 4 x double> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP0]]
//
vfloat64m4_t test_vle64_v_f64m4_m(vbool16_t mask, const double *base, size_t vl) {
  return __riscv_vle64_v_f64m4_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_f64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x double> @llvm.riscv.vle.mask.nxv8f64.i64(<vscale x 8 x double> poison, ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP0]]
//
vfloat64m8_t test_vle64_v_f64m8_m(vbool8_t mask, const double *base, size_t vl) {
  return __riscv_vle64_v_f64m8_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vle.mask.nxv1i64.i64(<vscale x 1 x i64> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vle64_v_i64m1_m(vbool64_t mask, const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m1_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vle.mask.nxv2i64.i64(<vscale x 2 x i64> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vle64_v_i64m2_m(vbool32_t mask, const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m2_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vle.mask.nxv4i64.i64(<vscale x 4 x i64> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vle64_v_i64m4_m(vbool16_t mask, const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m4_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_i64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vle.mask.nxv8i64.i64(<vscale x 8 x i64> poison, ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vle64_v_i64m8_m(vbool8_t mask, const int64_t *base, size_t vl) {
  return __riscv_vle64_v_i64m8_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vle.mask.nxv1i64.i64(<vscale x 1 x i64> poison, ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vuint64m1_t test_vle64_v_u64m1_m(vbool64_t mask, const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m1_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vle.mask.nxv2i64.i64(<vscale x 2 x i64> poison, ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vuint64m2_t test_vle64_v_u64m2_m(vbool32_t mask, const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m2_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vle.mask.nxv4i64.i64(<vscale x 4 x i64> poison, ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vle64_v_u64m4_m(vbool16_t mask, const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m4_m(mask, base, vl);
}

// CHECK-RV64-LABEL: @test_vle64_v_u64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vle.mask.nxv8i64.i64(<vscale x 8 x i64> poison, ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vuint64m8_t test_vle64_v_u64m8_m(vbool8_t mask, const uint64_t *base, size_t vl) {
  return __riscv_vle64_v_u64m8_m(mask, base, vl);
}

