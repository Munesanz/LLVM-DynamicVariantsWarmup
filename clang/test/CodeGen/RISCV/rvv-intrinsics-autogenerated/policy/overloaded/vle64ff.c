// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, i64 } @llvm.riscv.vleff.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP1]]
//
vfloat64m1_t test_vle64ff_v_f64m1_tu(vfloat64m1_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x double>, i64 } @llvm.riscv.vleff.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP1]]
//
vfloat64m2_t test_vle64ff_v_f64m2_tu(vfloat64m2_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x double>, i64 } @llvm.riscv.vleff.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP1]]
//
vfloat64m4_t test_vle64ff_v_f64m4_tu(vfloat64m4_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x double>, i64 } @llvm.riscv.vleff.nxv8f64.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP1]]
//
vfloat64m8_t test_vle64ff_v_f64m8_tu(vfloat64m8_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, i64 } @llvm.riscv.vleff.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vint64m1_t test_vle64ff_v_i64m1_tu(vint64m1_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, i64 } @llvm.riscv.vleff.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vint64m2_t test_vle64ff_v_i64m2_tu(vint64m2_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, i64 } @llvm.riscv.vleff.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vint64m4_t test_vle64ff_v_i64m4_tu(vint64m4_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i64>, i64 } @llvm.riscv.vleff.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vint64m8_t test_vle64ff_v_i64m8_tu(vint64m8_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, i64 } @llvm.riscv.vleff.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vuint64m1_t test_vle64ff_v_u64m1_tu(vuint64m1_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, i64 } @llvm.riscv.vleff.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vuint64m2_t test_vle64ff_v_u64m2_tu(vuint64m2_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, i64 } @llvm.riscv.vleff.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vuint64m4_t test_vle64ff_v_u64m4_tu(vuint64m4_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i64>, i64 } @llvm.riscv.vleff.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vuint64m8_t test_vle64ff_v_u64m8_tu(vuint64m8_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tu(maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, i64 } @llvm.riscv.vleff.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP1]]
//
vfloat64m1_t test_vle64ff_v_f64m1_tum(vbool64_t mask, vfloat64m1_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x double>, i64 } @llvm.riscv.vleff.mask.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP1]]
//
vfloat64m2_t test_vle64ff_v_f64m2_tum(vbool32_t mask, vfloat64m2_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x double>, i64 } @llvm.riscv.vleff.mask.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP1]]
//
vfloat64m4_t test_vle64ff_v_f64m4_tum(vbool16_t mask, vfloat64m4_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x double>, i64 } @llvm.riscv.vleff.mask.nxv8f64.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP1]]
//
vfloat64m8_t test_vle64ff_v_f64m8_tum(vbool8_t mask, vfloat64m8_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, i64 } @llvm.riscv.vleff.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vint64m1_t test_vle64ff_v_i64m1_tum(vbool64_t mask, vint64m1_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, i64 } @llvm.riscv.vleff.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vint64m2_t test_vle64ff_v_i64m2_tum(vbool32_t mask, vint64m2_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, i64 } @llvm.riscv.vleff.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vint64m4_t test_vle64ff_v_i64m4_tum(vbool16_t mask, vint64m4_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i64>, i64 } @llvm.riscv.vleff.mask.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vint64m8_t test_vle64ff_v_i64m8_tum(vbool8_t mask, vint64m8_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, i64 } @llvm.riscv.vleff.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vuint64m1_t test_vle64ff_v_u64m1_tum(vbool64_t mask, vuint64m1_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, i64 } @llvm.riscv.vleff.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vuint64m2_t test_vle64ff_v_u64m2_tum(vbool32_t mask, vuint64m2_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, i64 } @llvm.riscv.vleff.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vuint64m4_t test_vle64ff_v_u64m4_tum(vbool16_t mask, vuint64m4_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i64>, i64 } @llvm.riscv.vleff.mask.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vuint64m8_t test_vle64ff_v_u64m8_tum(vbool8_t mask, vuint64m8_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tum(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, i64 } @llvm.riscv.vleff.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP1]]
//
vfloat64m1_t test_vle64ff_v_f64m1_tumu(vbool64_t mask, vfloat64m1_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x double>, i64 } @llvm.riscv.vleff.mask.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x double> [[TMP1]]
//
vfloat64m2_t test_vle64ff_v_f64m2_tumu(vbool32_t mask, vfloat64m2_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x double>, i64 } @llvm.riscv.vleff.mask.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x double> [[TMP1]]
//
vfloat64m4_t test_vle64ff_v_f64m4_tumu(vbool16_t mask, vfloat64m4_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_f64m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x double>, i64 } @llvm.riscv.vleff.mask.nxv8f64.i64(<vscale x 8 x double> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x double>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x double>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x double> [[TMP1]]
//
vfloat64m8_t test_vle64ff_v_f64m8_tumu(vbool8_t mask, vfloat64m8_t maskedoff, const double *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, i64 } @llvm.riscv.vleff.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vint64m1_t test_vle64ff_v_i64m1_tumu(vbool64_t mask, vint64m1_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, i64 } @llvm.riscv.vleff.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vint64m2_t test_vle64ff_v_i64m2_tumu(vbool32_t mask, vint64m2_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, i64 } @llvm.riscv.vleff.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vint64m4_t test_vle64ff_v_i64m4_tumu(vbool16_t mask, vint64m4_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_i64m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i64>, i64 } @llvm.riscv.vleff.mask.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vint64m8_t test_vle64ff_v_i64m8_tumu(vbool8_t mask, vint64m8_t maskedoff, const int64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, i64 } @llvm.riscv.vleff.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP1]]
//
vuint64m1_t test_vle64ff_v_u64m1_tumu(vbool64_t mask, vuint64m1_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, i64 } @llvm.riscv.vleff.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP1]]
//
vuint64m2_t test_vle64ff_v_u64m2_tumu(vbool32_t mask, vuint64m2_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, i64 } @llvm.riscv.vleff.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP1]]
//
vuint64m4_t test_vle64ff_v_u64m4_tumu(vbool16_t mask, vuint64m4_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

// CHECK-RV64-LABEL: @test_vle64ff_v_u64m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 8 x i64>, i64 } @llvm.riscv.vleff.mask.nxv8i64.i64(<vscale x 8 x i64> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 0
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 8 x i64>, i64 } [[TMP0]], 1
// CHECK-RV64-NEXT:    store i64 [[TMP2]], ptr [[NEW_VL:%.*]], align 8
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP1]]
//
vuint64m8_t test_vle64ff_v_u64m8_tumu(vbool8_t mask, vuint64m8_t maskedoff, const uint64_t *base, size_t *new_vl, size_t vl) {
  return __riscv_vle64ff_tumu(mask, maskedoff, base, new_vl, vl);
}

