// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16mf4_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.nxv4f16.nxv1f16.i64(<vscale x 4 x half> poison, <vscale x 1 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16mf4_f16m1(vfloat16mf4_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16mf4_f16m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16mf2_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.nxv4f16.nxv2f16.i64(<vscale x 4 x half> poison, <vscale x 2 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16mf2_f16m1(vfloat16mf2_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16mf2_f16m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m1_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.nxv4f16.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m1_f16m1(vfloat16m1_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m1_f16m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m2_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.nxv4f16.nxv8f16.i64(<vscale x 4 x half> poison, <vscale x 8 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m2_f16m1(vfloat16m2_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m2_f16m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m4_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.nxv4f16.nxv16f16.i64(<vscale x 4 x half> poison, <vscale x 16 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m4_f16m1(vfloat16m4_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m4_f16m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m8_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.nxv4f16.nxv32f16.i64(<vscale x 4 x half> poison, <vscale x 32 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m8_f16m1(vfloat16m8_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m8_f16m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32mf2_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.nxv2f32.nxv1f32.i64(<vscale x 2 x float> poison, <vscale x 1 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32mf2_f32m1(vfloat32mf2_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32mf2_f32m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m1_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.nxv2f32.nxv2f32.i64(<vscale x 2 x float> poison, <vscale x 2 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m1_f32m1(vfloat32m1_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m1_f32m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m2_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.nxv2f32.nxv4f32.i64(<vscale x 2 x float> poison, <vscale x 4 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m2_f32m1(vfloat32m2_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m2_f32m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m4_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.nxv2f32.nxv8f32.i64(<vscale x 2 x float> poison, <vscale x 8 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m4_f32m1(vfloat32m4_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m4_f32m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m8_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.nxv2f32.nxv16f32.i64(<vscale x 2 x float> poison, <vscale x 16 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m8_f32m1(vfloat32m8_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m8_f32m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m1_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.nxv1f64.nxv1f64.i64(<vscale x 1 x double> poison, <vscale x 1 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m1_f64m1(vfloat64m1_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m1_f64m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m2_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.nxv1f64.nxv2f64.i64(<vscale x 1 x double> poison, <vscale x 2 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m2_f64m1(vfloat64m2_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m2_f64m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m4_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.nxv1f64.nxv4f64.i64(<vscale x 1 x double> poison, <vscale x 4 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m4_f64m1(vfloat64m4_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m4_f64m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m8_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.nxv1f64.nxv8f64.i64(<vscale x 1 x double> poison, <vscale x 8 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m8_f64m1(vfloat64m8_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m8_f64m1(vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16mf4_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.mask.nxv4f16.nxv1f16.i64(<vscale x 4 x half> poison, <vscale x 1 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16mf4_f16m1_m(vbool64_t mask, vfloat16mf4_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16mf4_f16m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16mf2_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.mask.nxv4f16.nxv2f16.i64(<vscale x 4 x half> poison, <vscale x 2 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16mf2_f16m1_m(vbool32_t mask, vfloat16mf2_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16mf2_f16m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m1_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.mask.nxv4f16.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m1_f16m1_m(vbool16_t mask, vfloat16m1_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m1_f16m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m2_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.mask.nxv4f16.nxv8f16.i64(<vscale x 4 x half> poison, <vscale x 8 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m2_f16m1_m(vbool8_t mask, vfloat16m2_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m2_f16m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m4_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.mask.nxv4f16.nxv16f16.i64(<vscale x 4 x half> poison, <vscale x 16 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m4_f16m1_m(vbool4_t mask, vfloat16m4_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m4_f16m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f16m8_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x half> @llvm.riscv.vfredosum.mask.nxv4f16.nxv32f16.i64(<vscale x 4 x half> poison, <vscale x 32 x half> [[VECTOR:%.*]], <vscale x 4 x half> [[SCALAR:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x half> [[TMP0]]
//
vfloat16m1_t test_vfredosum_vs_f16m8_f16m1_m(vbool2_t mask, vfloat16m8_t vector, vfloat16m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f16m8_f16m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32mf2_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.mask.nxv2f32.nxv1f32.i64(<vscale x 2 x float> poison, <vscale x 1 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32mf2_f32m1_m(vbool64_t mask, vfloat32mf2_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32mf2_f32m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m1_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.mask.nxv2f32.nxv2f32.i64(<vscale x 2 x float> poison, <vscale x 2 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m1_f32m1_m(vbool32_t mask, vfloat32m1_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m1_f32m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m2_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.mask.nxv2f32.nxv4f32.i64(<vscale x 2 x float> poison, <vscale x 4 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m2_f32m1_m(vbool16_t mask, vfloat32m2_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m2_f32m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m4_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.mask.nxv2f32.nxv8f32.i64(<vscale x 2 x float> poison, <vscale x 8 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m4_f32m1_m(vbool8_t mask, vfloat32m4_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m4_f32m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f32m8_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vfredosum.mask.nxv2f32.nxv16f32.i64(<vscale x 2 x float> poison, <vscale x 16 x float> [[VECTOR:%.*]], <vscale x 2 x float> [[SCALAR:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vfredosum_vs_f32m8_f32m1_m(vbool4_t mask, vfloat32m8_t vector, vfloat32m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f32m8_f32m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m1_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.mask.nxv1f64.nxv1f64.i64(<vscale x 1 x double> poison, <vscale x 1 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m1_f64m1_m(vbool64_t mask, vfloat64m1_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m1_f64m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m2_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.mask.nxv1f64.nxv2f64.i64(<vscale x 1 x double> poison, <vscale x 2 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m2_f64m1_m(vbool32_t mask, vfloat64m2_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m2_f64m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m4_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.mask.nxv1f64.nxv4f64.i64(<vscale x 1 x double> poison, <vscale x 4 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m4_f64m1_m(vbool16_t mask, vfloat64m4_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m4_f64m1_m(mask, vector, scalar, vl);
}

// CHECK-RV64-LABEL: @test_vfredosum_vs_f64m8_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x double> @llvm.riscv.vfredosum.mask.nxv1f64.nxv8f64.i64(<vscale x 1 x double> poison, <vscale x 8 x double> [[VECTOR:%.*]], <vscale x 1 x double> [[SCALAR:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x double> [[TMP0]]
//
vfloat64m1_t test_vfredosum_vs_f64m8_f64m1_m(vbool8_t mask, vfloat64m8_t vector, vfloat64m1_t scalar, size_t vl) {
  return __riscv_vfredosum_vs_f64m8_f64m1_m(mask, vector, scalar, vl);
}

