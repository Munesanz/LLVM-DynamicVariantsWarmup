// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vsseg6e64_v_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg6.nxv1f64.i64(<vscale x 1 x double> [[V0:%.*]], <vscale x 1 x double> [[V1:%.*]], <vscale x 1 x double> [[V2:%.*]], <vscale x 1 x double> [[V3:%.*]], <vscale x 1 x double> [[V4:%.*]], <vscale x 1 x double> [[V5:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg6e64_v_f64m1(double *base, vfloat64m1_t v0, vfloat64m1_t v1, vfloat64m1_t v2, vfloat64m1_t v3, vfloat64m1_t v4, vfloat64m1_t v5, size_t vl) {
  return __riscv_vsseg6e64(base, v0, v1, v2, v3, v4, v5, vl);
}

// CHECK-RV64-LABEL: @test_vsseg6e64_v_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg6.nxv1i64.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], <vscale x 1 x i64> [[V5:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg6e64_v_i64m1(int64_t *base, vint64m1_t v0, vint64m1_t v1, vint64m1_t v2, vint64m1_t v3, vint64m1_t v4, vint64m1_t v5, size_t vl) {
  return __riscv_vsseg6e64(base, v0, v1, v2, v3, v4, v5, vl);
}

// CHECK-RV64-LABEL: @test_vsseg6e64_v_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg6.nxv1i64.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], <vscale x 1 x i64> [[V5:%.*]], ptr [[BASE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg6e64_v_u64m1(uint64_t *base, vuint64m1_t v0, vuint64m1_t v1, vuint64m1_t v2, vuint64m1_t v3, vuint64m1_t v4, vuint64m1_t v5, size_t vl) {
  return __riscv_vsseg6e64(base, v0, v1, v2, v3, v4, v5, vl);
}

// CHECK-RV64-LABEL: @test_vsseg6e64_v_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg6.mask.nxv1f64.i64(<vscale x 1 x double> [[V0:%.*]], <vscale x 1 x double> [[V1:%.*]], <vscale x 1 x double> [[V2:%.*]], <vscale x 1 x double> [[V3:%.*]], <vscale x 1 x double> [[V4:%.*]], <vscale x 1 x double> [[V5:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg6e64_v_f64m1_m(vbool64_t mask, double *base, vfloat64m1_t v0, vfloat64m1_t v1, vfloat64m1_t v2, vfloat64m1_t v3, vfloat64m1_t v4, vfloat64m1_t v5, size_t vl) {
  return __riscv_vsseg6e64(mask, base, v0, v1, v2, v3, v4, v5, vl);
}

// CHECK-RV64-LABEL: @test_vsseg6e64_v_i64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg6.mask.nxv1i64.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], <vscale x 1 x i64> [[V5:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg6e64_v_i64m1_m(vbool64_t mask, int64_t *base, vint64m1_t v0, vint64m1_t v1, vint64m1_t v2, vint64m1_t v3, vint64m1_t v4, vint64m1_t v5, size_t vl) {
  return __riscv_vsseg6e64(mask, base, v0, v1, v2, v3, v4, v5, vl);
}

// CHECK-RV64-LABEL: @test_vsseg6e64_v_u64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsseg6.mask.nxv1i64.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], <vscale x 1 x i64> [[V5:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsseg6e64_v_u64m1_m(vbool64_t mask, uint64_t *base, vuint64m1_t v0, vuint64m1_t v1, vuint64m1_t v2, vuint64m1_t v3, vuint64m1_t v4, vuint64m1_t v5, size_t vl) {
  return __riscv_vsseg6e64(mask, base, v0, v1, v2, v3, v4, v5, vl);
}

