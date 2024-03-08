// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg2.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF0:%.*]], <vscale x 1 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m1_tu(vfloat64m1_t *v0, vfloat64m1_t *v1, vfloat64m1_t maskedoff0, vfloat64m1_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m1_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x double>, <vscale x 2 x double> } @llvm.riscv.vlseg2.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF0:%.*]], <vscale x 2 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m2_tu(vfloat64m2_t *v0, vfloat64m2_t *v1, vfloat64m2_t maskedoff0, vfloat64m2_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m2_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x double>, <vscale x 4 x double> } @llvm.riscv.vlseg2.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF0:%.*]], <vscale x 4 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m4_tu(vfloat64m4_t *v0, vfloat64m4_t *v1, vfloat64m4_t maskedoff0, vfloat64m4_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m4_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m1_tu(vint64m1_t *v0, vint64m1_t *v1, vint64m1_t maskedoff0, vint64m1_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m1_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m2_tu(vint64m2_t *v0, vint64m2_t *v1, vint64m2_t maskedoff0, vint64m2_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m2_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m4_tu(vint64m4_t *v0, vint64m4_t *v1, vint64m4_t maskedoff0, vint64m4_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m4_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m1_tu(vuint64m1_t *v0, vuint64m1_t *v1, vuint64m1_t maskedoff0, vuint64m1_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m1_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m2_tu(vuint64m2_t *v0, vuint64m2_t *v1, vuint64m2_t maskedoff0, vuint64m2_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m2_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m4_tu(vuint64m4_t *v0, vuint64m4_t *v1, vuint64m4_t maskedoff0, vuint64m4_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m4_tu(v0, v1, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg2.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF0:%.*]], <vscale x 1 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m1_tum(vfloat64m1_t *v0, vfloat64m1_t *v1, vbool64_t mask, vfloat64m1_t maskedoff0, vfloat64m1_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m1_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x double>, <vscale x 2 x double> } @llvm.riscv.vlseg2.mask.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF0:%.*]], <vscale x 2 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m2_tum(vfloat64m2_t *v0, vfloat64m2_t *v1, vbool32_t mask, vfloat64m2_t maskedoff0, vfloat64m2_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m2_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x double>, <vscale x 4 x double> } @llvm.riscv.vlseg2.mask.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF0:%.*]], <vscale x 4 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m4_tum(vfloat64m4_t *v0, vfloat64m4_t *v1, vbool16_t mask, vfloat64m4_t maskedoff0, vfloat64m4_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m4_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m1_tum(vint64m1_t *v0, vint64m1_t *v1, vbool64_t mask, vint64m1_t maskedoff0, vint64m1_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m1_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m2_tum(vint64m2_t *v0, vint64m2_t *v1, vbool32_t mask, vint64m2_t maskedoff0, vint64m2_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m2_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m4_tum(vint64m4_t *v0, vint64m4_t *v1, vbool16_t mask, vint64m4_t maskedoff0, vint64m4_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m4_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m1_tum(vuint64m1_t *v0, vuint64m1_t *v1, vbool64_t mask, vuint64m1_t maskedoff0, vuint64m1_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m1_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m2_tum(vuint64m2_t *v0, vuint64m2_t *v1, vbool32_t mask, vuint64m2_t maskedoff0, vuint64m2_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m2_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m4_tum(vuint64m4_t *v0, vuint64m4_t *v1, vbool16_t mask, vuint64m4_t maskedoff0, vuint64m4_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m4_tum(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg2.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF0:%.*]], <vscale x 1 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m1_tumu(vfloat64m1_t *v0, vfloat64m1_t *v1, vbool64_t mask, vfloat64m1_t maskedoff0, vfloat64m1_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m1_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x double>, <vscale x 2 x double> } @llvm.riscv.vlseg2.mask.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF0:%.*]], <vscale x 2 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m2_tumu(vfloat64m2_t *v0, vfloat64m2_t *v1, vbool32_t mask, vfloat64m2_t maskedoff0, vfloat64m2_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m2_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x double>, <vscale x 4 x double> } @llvm.riscv.vlseg2.mask.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF0:%.*]], <vscale x 4 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m4_tumu(vfloat64m4_t *v0, vfloat64m4_t *v1, vbool16_t mask, vfloat64m4_t maskedoff0, vfloat64m4_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m4_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m1_tumu(vint64m1_t *v0, vint64m1_t *v1, vbool64_t mask, vint64m1_t maskedoff0, vint64m1_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m1_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m2_tumu(vint64m2_t *v0, vint64m2_t *v1, vbool32_t mask, vint64m2_t maskedoff0, vint64m2_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m2_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m4_tumu(vint64m4_t *v0, vint64m4_t *v1, vbool16_t mask, vint64m4_t maskedoff0, vint64m4_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m4_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m1_tumu(vuint64m1_t *v0, vuint64m1_t *v1, vbool64_t mask, vuint64m1_t maskedoff0, vuint64m1_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m1_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m2_tumu(vuint64m2_t *v0, vuint64m2_t *v1, vbool32_t mask, vuint64m2_t maskedoff0, vuint64m2_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m2_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m4_tumu(vuint64m4_t *v0, vuint64m4_t *v1, vbool16_t mask, vuint64m4_t maskedoff0, vuint64m4_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m4_tumu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m1_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg2.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF0:%.*]], <vscale x 1 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m1_mu(vfloat64m1_t *v0, vfloat64m1_t *v1, vbool64_t mask, vfloat64m1_t maskedoff0, vfloat64m1_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m1_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m2_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x double>, <vscale x 2 x double> } @llvm.riscv.vlseg2.mask.nxv2f64.i64(<vscale x 2 x double> [[MASKEDOFF0:%.*]], <vscale x 2 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x double>, <vscale x 2 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m2_mu(vfloat64m2_t *v0, vfloat64m2_t *v1, vbool32_t mask, vfloat64m2_t maskedoff0, vfloat64m2_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m2_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_f64m4_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x double>, <vscale x 4 x double> } @llvm.riscv.vlseg2.mask.nxv4f64.i64(<vscale x 4 x double> [[MASKEDOFF0:%.*]], <vscale x 4 x double> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x double>, <vscale x 4 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_f64m4_mu(vfloat64m4_t *v0, vfloat64m4_t *v1, vbool16_t mask, vfloat64m4_t maskedoff0, vfloat64m4_t maskedoff1, const double *base, size_t vl) {
  return __riscv_vlseg2e64_v_f64m4_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m1_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m1_mu(vint64m1_t *v0, vint64m1_t *v1, vbool64_t mask, vint64m1_t maskedoff0, vint64m1_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m1_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m2_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m2_mu(vint64m2_t *v0, vint64m2_t *v1, vbool32_t mask, vint64m2_t maskedoff0, vint64m2_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m2_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_i64m4_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_i64m4_mu(vint64m4_t *v0, vint64m4_t *v1, vbool16_t mask, vint64m4_t maskedoff0, vint64m4_t maskedoff1, const int64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_i64m4_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m1_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg2.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m1_mu(vuint64m1_t *v0, vuint64m1_t *v1, vbool64_t mask, vuint64m1_t maskedoff0, vuint64m1_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m1_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m2_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i64>, <vscale x 2 x i64> } @llvm.riscv.vlseg2.mask.nxv2i64.i64(<vscale x 2 x i64> [[MASKEDOFF0:%.*]], <vscale x 2 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i64>, <vscale x 2 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m2_mu(vuint64m2_t *v0, vuint64m2_t *v1, vbool32_t mask, vuint64m2_t maskedoff0, vuint64m2_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m2_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg2e64_v_u64m4_mu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i64>, <vscale x 4 x i64> } @llvm.riscv.vlseg2.mask.nxv4i64.i64(<vscale x 4 x i64> [[MASKEDOFF0:%.*]], <vscale x 4 x i64> [[MASKEDOFF1:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 1)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i64>, <vscale x 4 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg2e64_v_u64m4_mu(vuint64m4_t *v0, vuint64m4_t *v1, vbool16_t mask, vuint64m4_t maskedoff0, vuint64m4_t maskedoff1, const uint64_t *base, size_t vl) {
  return __riscv_vlseg2e64_v_u64m4_mu(v0, v1, mask, maskedoff0, maskedoff1, base, vl);
}

