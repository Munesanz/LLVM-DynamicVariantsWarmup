// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vlseg5e64_v_f64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg5.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF0:%.*]], <vscale x 1 x double> [[MASKEDOFF1:%.*]], <vscale x 1 x double> [[MASKEDOFF2:%.*]], <vscale x 1 x double> [[MASKEDOFF3:%.*]], <vscale x 1 x double> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_f64m1_tu(vfloat64m1_t *v0, vfloat64m1_t *v1, vfloat64m1_t *v2, vfloat64m1_t *v3, vfloat64m1_t *v4, vfloat64m1_t maskedoff0, vfloat64m1_t maskedoff1, vfloat64m1_t maskedoff2, vfloat64m1_t maskedoff3, vfloat64m1_t maskedoff4, const double *base, size_t vl) {
  return __riscv_vlseg5e64_tu(v0, v1, v2, v3, v4, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_i64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], <vscale x 1 x i64> [[MASKEDOFF2:%.*]], <vscale x 1 x i64> [[MASKEDOFF3:%.*]], <vscale x 1 x i64> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_i64m1_tu(vint64m1_t *v0, vint64m1_t *v1, vint64m1_t *v2, vint64m1_t *v3, vint64m1_t *v4, vint64m1_t maskedoff0, vint64m1_t maskedoff1, vint64m1_t maskedoff2, vint64m1_t maskedoff3, vint64m1_t maskedoff4, const int64_t *base, size_t vl) {
  return __riscv_vlseg5e64_tu(v0, v1, v2, v3, v4, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_u64m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], <vscale x 1 x i64> [[MASKEDOFF2:%.*]], <vscale x 1 x i64> [[MASKEDOFF3:%.*]], <vscale x 1 x i64> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_u64m1_tu(vuint64m1_t *v0, vuint64m1_t *v1, vuint64m1_t *v2, vuint64m1_t *v3, vuint64m1_t *v4, vuint64m1_t maskedoff0, vuint64m1_t maskedoff1, vuint64m1_t maskedoff2, vuint64m1_t maskedoff3, vuint64m1_t maskedoff4, const uint64_t *base, size_t vl) {
  return __riscv_vlseg5e64_tu(v0, v1, v2, v3, v4, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_f64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg5.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF0:%.*]], <vscale x 1 x double> [[MASKEDOFF1:%.*]], <vscale x 1 x double> [[MASKEDOFF2:%.*]], <vscale x 1 x double> [[MASKEDOFF3:%.*]], <vscale x 1 x double> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_f64m1_tum(vfloat64m1_t *v0, vfloat64m1_t *v1, vfloat64m1_t *v2, vfloat64m1_t *v3, vfloat64m1_t *v4, vbool64_t mask, vfloat64m1_t maskedoff0, vfloat64m1_t maskedoff1, vfloat64m1_t maskedoff2, vfloat64m1_t maskedoff3, vfloat64m1_t maskedoff4, const double *base, size_t vl) {
  return __riscv_vlseg5e64_tum(v0, v1, v2, v3, v4, mask, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_i64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], <vscale x 1 x i64> [[MASKEDOFF2:%.*]], <vscale x 1 x i64> [[MASKEDOFF3:%.*]], <vscale x 1 x i64> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_i64m1_tum(vint64m1_t *v0, vint64m1_t *v1, vint64m1_t *v2, vint64m1_t *v3, vint64m1_t *v4, vbool64_t mask, vint64m1_t maskedoff0, vint64m1_t maskedoff1, vint64m1_t maskedoff2, vint64m1_t maskedoff3, vint64m1_t maskedoff4, const int64_t *base, size_t vl) {
  return __riscv_vlseg5e64_tum(v0, v1, v2, v3, v4, mask, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_u64m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], <vscale x 1 x i64> [[MASKEDOFF2:%.*]], <vscale x 1 x i64> [[MASKEDOFF3:%.*]], <vscale x 1 x i64> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_u64m1_tum(vuint64m1_t *v0, vuint64m1_t *v1, vuint64m1_t *v2, vuint64m1_t *v3, vuint64m1_t *v4, vbool64_t mask, vuint64m1_t maskedoff0, vuint64m1_t maskedoff1, vuint64m1_t maskedoff2, vuint64m1_t maskedoff3, vuint64m1_t maskedoff4, const uint64_t *base, size_t vl) {
  return __riscv_vlseg5e64_tum(v0, v1, v2, v3, v4, mask, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_f64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } @llvm.riscv.vlseg5.mask.nxv1f64.i64(<vscale x 1 x double> [[MASKEDOFF0:%.*]], <vscale x 1 x double> [[MASKEDOFF1:%.*]], <vscale x 1 x double> [[MASKEDOFF2:%.*]], <vscale x 1 x double> [[MASKEDOFF3:%.*]], <vscale x 1 x double> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double>, <vscale x 1 x double> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x double> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_f64m1_tumu(vfloat64m1_t *v0, vfloat64m1_t *v1, vfloat64m1_t *v2, vfloat64m1_t *v3, vfloat64m1_t *v4, vbool64_t mask, vfloat64m1_t maskedoff0, vfloat64m1_t maskedoff1, vfloat64m1_t maskedoff2, vfloat64m1_t maskedoff3, vfloat64m1_t maskedoff4, const double *base, size_t vl) {
  return __riscv_vlseg5e64_tumu(v0, v1, v2, v3, v4, mask, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_i64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], <vscale x 1 x i64> [[MASKEDOFF2:%.*]], <vscale x 1 x i64> [[MASKEDOFF3:%.*]], <vscale x 1 x i64> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_i64m1_tumu(vint64m1_t *v0, vint64m1_t *v1, vint64m1_t *v2, vint64m1_t *v3, vint64m1_t *v4, vbool64_t mask, vint64m1_t maskedoff0, vint64m1_t maskedoff1, vint64m1_t maskedoff2, vint64m1_t maskedoff3, vint64m1_t maskedoff4, const int64_t *base, size_t vl) {
  return __riscv_vlseg5e64_tumu(v0, v1, v2, v3, v4, mask, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

// CHECK-RV64-LABEL: @test_vlseg5e64_v_u64m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } @llvm.riscv.vlseg5.mask.nxv1i64.i64(<vscale x 1 x i64> [[MASKEDOFF0:%.*]], <vscale x 1 x i64> [[MASKEDOFF1:%.*]], <vscale x 1 x i64> [[MASKEDOFF2:%.*]], <vscale x 1 x i64> [[MASKEDOFF3:%.*]], <vscale x 1 x i64> [[MASKEDOFF4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP1]], ptr [[V0:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP2]], ptr [[V1:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP3]], ptr [[V2:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP4]], ptr [[V3:%.*]], align 8
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i64> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i64> [[TMP5]], ptr [[V4:%.*]], align 8
// CHECK-RV64-NEXT:    ret void
//
void test_vlseg5e64_v_u64m1_tumu(vuint64m1_t *v0, vuint64m1_t *v1, vuint64m1_t *v2, vuint64m1_t *v3, vuint64m1_t *v4, vbool64_t mask, vuint64m1_t maskedoff0, vuint64m1_t maskedoff1, vuint64m1_t maskedoff2, vuint64m1_t maskedoff3, vuint64m1_t maskedoff4, const uint64_t *base, size_t vl) {
  return __riscv_vlseg5e64_tumu(v0, v1, v2, v3, v4, mask, maskedoff0, maskedoff1, maskedoff2, maskedoff3, maskedoff4, base, vl);
}

