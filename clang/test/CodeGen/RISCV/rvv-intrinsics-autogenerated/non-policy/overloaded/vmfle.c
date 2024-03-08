// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vmfle_vv_f16mf4_b64(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.nxv1f16.nxv1f16.i64(<vscale x 1 x half> [[OP1:%.*]], <vscale x 1 x half> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vv_f16mf4_b64(vfloat16mf4_t op1, vfloat16mf4_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16mf4_b64(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.nxv1f16.f16.i64(<vscale x 1 x half> [[OP1:%.*]], half [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vf_f16mf4_b64(vfloat16mf4_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16mf2_b32(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.nxv2f16.nxv2f16.i64(<vscale x 2 x half> [[OP1:%.*]], <vscale x 2 x half> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vv_f16mf2_b32(vfloat16mf2_t op1, vfloat16mf2_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16mf2_b32(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.nxv2f16.f16.i64(<vscale x 2 x half> [[OP1:%.*]], half [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vf_f16mf2_b32(vfloat16mf2_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m1_b16(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.nxv4f16.nxv4f16.i64(<vscale x 4 x half> [[OP1:%.*]], <vscale x 4 x half> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vv_f16m1_b16(vfloat16m1_t op1, vfloat16m1_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m1_b16(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.nxv4f16.f16.i64(<vscale x 4 x half> [[OP1:%.*]], half [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vf_f16m1_b16(vfloat16m1_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m2_b8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.nxv8f16.nxv8f16.i64(<vscale x 8 x half> [[OP1:%.*]], <vscale x 8 x half> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vv_f16m2_b8(vfloat16m2_t op1, vfloat16m2_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m2_b8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.nxv8f16.f16.i64(<vscale x 8 x half> [[OP1:%.*]], half [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vf_f16m2_b8(vfloat16m2_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m4_b4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.nxv16f16.nxv16f16.i64(<vscale x 16 x half> [[OP1:%.*]], <vscale x 16 x half> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vv_f16m4_b4(vfloat16m4_t op1, vfloat16m4_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m4_b4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.nxv16f16.f16.i64(<vscale x 16 x half> [[OP1:%.*]], half [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vf_f16m4_b4(vfloat16m4_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m8_b2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i1> @llvm.riscv.vmfle.nxv32f16.nxv32f16.i64(<vscale x 32 x half> [[OP1:%.*]], <vscale x 32 x half> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
vbool2_t test_vmfle_vv_f16m8_b2(vfloat16m8_t op1, vfloat16m8_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m8_b2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i1> @llvm.riscv.vmfle.nxv32f16.f16.i64(<vscale x 32 x half> [[OP1:%.*]], half [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
vbool2_t test_vmfle_vf_f16m8_b2(vfloat16m8_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32mf2_b64(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.nxv1f32.nxv1f32.i64(<vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vv_f32mf2_b64(vfloat32mf2_t op1, vfloat32mf2_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32mf2_b64(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.nxv1f32.f32.i64(<vscale x 1 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vf_f32mf2_b64(vfloat32mf2_t op1, float op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m1_b32(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.nxv2f32.nxv2f32.i64(<vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vv_f32m1_b32(vfloat32m1_t op1, vfloat32m1_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m1_b32(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.nxv2f32.f32.i64(<vscale x 2 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vf_f32m1_b32(vfloat32m1_t op1, float op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m2_b16(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.nxv4f32.nxv4f32.i64(<vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vv_f32m2_b16(vfloat32m2_t op1, vfloat32m2_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m2_b16(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.nxv4f32.f32.i64(<vscale x 4 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vf_f32m2_b16(vfloat32m2_t op1, float op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m4_b8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.nxv8f32.nxv8f32.i64(<vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vv_f32m4_b8(vfloat32m4_t op1, vfloat32m4_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m4_b8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.nxv8f32.f32.i64(<vscale x 8 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vf_f32m4_b8(vfloat32m4_t op1, float op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m8_b4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.nxv16f32.nxv16f32.i64(<vscale x 16 x float> [[OP1:%.*]], <vscale x 16 x float> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vv_f32m8_b4(vfloat32m8_t op1, vfloat32m8_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m8_b4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.nxv16f32.f32.i64(<vscale x 16 x float> [[OP1:%.*]], float [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vf_f32m8_b4(vfloat32m8_t op1, float op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m1_b64(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.nxv1f64.nxv1f64.i64(<vscale x 1 x double> [[OP1:%.*]], <vscale x 1 x double> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vv_f64m1_b64(vfloat64m1_t op1, vfloat64m1_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m1_b64(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.nxv1f64.f64.i64(<vscale x 1 x double> [[OP1:%.*]], double [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vf_f64m1_b64(vfloat64m1_t op1, double op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m2_b32(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.nxv2f64.nxv2f64.i64(<vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vv_f64m2_b32(vfloat64m2_t op1, vfloat64m2_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m2_b32(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.nxv2f64.f64.i64(<vscale x 2 x double> [[OP1:%.*]], double [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vf_f64m2_b32(vfloat64m2_t op1, double op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m4_b16(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.nxv4f64.nxv4f64.i64(<vscale x 4 x double> [[OP1:%.*]], <vscale x 4 x double> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vv_f64m4_b16(vfloat64m4_t op1, vfloat64m4_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m4_b16(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.nxv4f64.f64.i64(<vscale x 4 x double> [[OP1:%.*]], double [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vf_f64m4_b16(vfloat64m4_t op1, double op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m8_b8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.nxv8f64.nxv8f64.i64(<vscale x 8 x double> [[OP1:%.*]], <vscale x 8 x double> [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vv_f64m8_b8(vfloat64m8_t op1, vfloat64m8_t op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m8_b8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.nxv8f64.f64.i64(<vscale x 8 x double> [[OP1:%.*]], double [[OP2:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vf_f64m8_b8(vfloat64m8_t op1, double op2, size_t vl) {
  return __riscv_vmfle(op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16mf4_b64_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.mask.nxv1f16.nxv1f16.i64(<vscale x 1 x i1> poison, <vscale x 1 x half> [[OP1:%.*]], <vscale x 1 x half> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vv_f16mf4_b64_m(vbool64_t mask, vfloat16mf4_t op1, vfloat16mf4_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16mf4_b64_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.mask.nxv1f16.f16.i64(<vscale x 1 x i1> poison, <vscale x 1 x half> [[OP1:%.*]], half [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vf_f16mf4_b64_m(vbool64_t mask, vfloat16mf4_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16mf2_b32_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.mask.nxv2f16.nxv2f16.i64(<vscale x 2 x i1> poison, <vscale x 2 x half> [[OP1:%.*]], <vscale x 2 x half> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vv_f16mf2_b32_m(vbool32_t mask, vfloat16mf2_t op1, vfloat16mf2_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16mf2_b32_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.mask.nxv2f16.f16.i64(<vscale x 2 x i1> poison, <vscale x 2 x half> [[OP1:%.*]], half [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vf_f16mf2_b32_m(vbool32_t mask, vfloat16mf2_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m1_b16_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.mask.nxv4f16.nxv4f16.i64(<vscale x 4 x i1> poison, <vscale x 4 x half> [[OP1:%.*]], <vscale x 4 x half> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vv_f16m1_b16_m(vbool16_t mask, vfloat16m1_t op1, vfloat16m1_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m1_b16_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.mask.nxv4f16.f16.i64(<vscale x 4 x i1> poison, <vscale x 4 x half> [[OP1:%.*]], half [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vf_f16m1_b16_m(vbool16_t mask, vfloat16m1_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m2_b8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.mask.nxv8f16.nxv8f16.i64(<vscale x 8 x i1> poison, <vscale x 8 x half> [[OP1:%.*]], <vscale x 8 x half> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vv_f16m2_b8_m(vbool8_t mask, vfloat16m2_t op1, vfloat16m2_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m2_b8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.mask.nxv8f16.f16.i64(<vscale x 8 x i1> poison, <vscale x 8 x half> [[OP1:%.*]], half [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vf_f16m2_b8_m(vbool8_t mask, vfloat16m2_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m4_b4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.mask.nxv16f16.nxv16f16.i64(<vscale x 16 x i1> poison, <vscale x 16 x half> [[OP1:%.*]], <vscale x 16 x half> [[OP2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vv_f16m4_b4_m(vbool4_t mask, vfloat16m4_t op1, vfloat16m4_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m4_b4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.mask.nxv16f16.f16.i64(<vscale x 16 x i1> poison, <vscale x 16 x half> [[OP1:%.*]], half [[OP2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vf_f16m4_b4_m(vbool4_t mask, vfloat16m4_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f16m8_b2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i1> @llvm.riscv.vmfle.mask.nxv32f16.nxv32f16.i64(<vscale x 32 x i1> poison, <vscale x 32 x half> [[OP1:%.*]], <vscale x 32 x half> [[OP2:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
vbool2_t test_vmfle_vv_f16m8_b2_m(vbool2_t mask, vfloat16m8_t op1, vfloat16m8_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f16m8_b2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i1> @llvm.riscv.vmfle.mask.nxv32f16.f16.i64(<vscale x 32 x i1> poison, <vscale x 32 x half> [[OP1:%.*]], half [[OP2:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 32 x i1> [[TMP0]]
//
vbool2_t test_vmfle_vf_f16m8_b2_m(vbool2_t mask, vfloat16m8_t op1, _Float16 op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32mf2_b64_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.mask.nxv1f32.nxv1f32.i64(<vscale x 1 x i1> poison, <vscale x 1 x float> [[OP1:%.*]], <vscale x 1 x float> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vv_f32mf2_b64_m(vbool64_t mask, vfloat32mf2_t op1, vfloat32mf2_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32mf2_b64_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.mask.nxv1f32.f32.i64(<vscale x 1 x i1> poison, <vscale x 1 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vf_f32mf2_b64_m(vbool64_t mask, vfloat32mf2_t op1, float op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m1_b32_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.mask.nxv2f32.nxv2f32.i64(<vscale x 2 x i1> poison, <vscale x 2 x float> [[OP1:%.*]], <vscale x 2 x float> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vv_f32m1_b32_m(vbool32_t mask, vfloat32m1_t op1, vfloat32m1_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m1_b32_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.mask.nxv2f32.f32.i64(<vscale x 2 x i1> poison, <vscale x 2 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vf_f32m1_b32_m(vbool32_t mask, vfloat32m1_t op1, float op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m2_b16_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.mask.nxv4f32.nxv4f32.i64(<vscale x 4 x i1> poison, <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vv_f32m2_b16_m(vbool16_t mask, vfloat32m2_t op1, vfloat32m2_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m2_b16_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.mask.nxv4f32.f32.i64(<vscale x 4 x i1> poison, <vscale x 4 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vf_f32m2_b16_m(vbool16_t mask, vfloat32m2_t op1, float op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m4_b8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.mask.nxv8f32.nxv8f32.i64(<vscale x 8 x i1> poison, <vscale x 8 x float> [[OP1:%.*]], <vscale x 8 x float> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vv_f32m4_b8_m(vbool8_t mask, vfloat32m4_t op1, vfloat32m4_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m4_b8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.mask.nxv8f32.f32.i64(<vscale x 8 x i1> poison, <vscale x 8 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vf_f32m4_b8_m(vbool8_t mask, vfloat32m4_t op1, float op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f32m8_b4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.mask.nxv16f32.nxv16f32.i64(<vscale x 16 x i1> poison, <vscale x 16 x float> [[OP1:%.*]], <vscale x 16 x float> [[OP2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vv_f32m8_b4_m(vbool4_t mask, vfloat32m8_t op1, vfloat32m8_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f32m8_b4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i1> @llvm.riscv.vmfle.mask.nxv16f32.f32.i64(<vscale x 16 x i1> poison, <vscale x 16 x float> [[OP1:%.*]], float [[OP2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i1> [[TMP0]]
//
vbool4_t test_vmfle_vf_f32m8_b4_m(vbool4_t mask, vfloat32m8_t op1, float op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m1_b64_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.mask.nxv1f64.nxv1f64.i64(<vscale x 1 x i1> poison, <vscale x 1 x double> [[OP1:%.*]], <vscale x 1 x double> [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vv_f64m1_b64_m(vbool64_t mask, vfloat64m1_t op1, vfloat64m1_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m1_b64_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i1> @llvm.riscv.vmfle.mask.nxv1f64.f64.i64(<vscale x 1 x i1> poison, <vscale x 1 x double> [[OP1:%.*]], double [[OP2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i1> [[TMP0]]
//
vbool64_t test_vmfle_vf_f64m1_b64_m(vbool64_t mask, vfloat64m1_t op1, double op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m2_b32_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.mask.nxv2f64.nxv2f64.i64(<vscale x 2 x i1> poison, <vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vv_f64m2_b32_m(vbool32_t mask, vfloat64m2_t op1, vfloat64m2_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m2_b32_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i1> @llvm.riscv.vmfle.mask.nxv2f64.f64.i64(<vscale x 2 x i1> poison, <vscale x 2 x double> [[OP1:%.*]], double [[OP2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i1> [[TMP0]]
//
vbool32_t test_vmfle_vf_f64m2_b32_m(vbool32_t mask, vfloat64m2_t op1, double op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m4_b16_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.mask.nxv4f64.nxv4f64.i64(<vscale x 4 x i1> poison, <vscale x 4 x double> [[OP1:%.*]], <vscale x 4 x double> [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vv_f64m4_b16_m(vbool16_t mask, vfloat64m4_t op1, vfloat64m4_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m4_b16_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i1> @llvm.riscv.vmfle.mask.nxv4f64.f64.i64(<vscale x 4 x i1> poison, <vscale x 4 x double> [[OP1:%.*]], double [[OP2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i1> [[TMP0]]
//
vbool16_t test_vmfle_vf_f64m4_b16_m(vbool16_t mask, vfloat64m4_t op1, double op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vv_f64m8_b8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.mask.nxv8f64.nxv8f64.i64(<vscale x 8 x i1> poison, <vscale x 8 x double> [[OP1:%.*]], <vscale x 8 x double> [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vv_f64m8_b8_m(vbool8_t mask, vfloat64m8_t op1, vfloat64m8_t op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

// CHECK-RV64-LABEL: @test_vmfle_vf_f64m8_b8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i1> @llvm.riscv.vmfle.mask.nxv8f64.f64.i64(<vscale x 8 x i1> poison, <vscale x 8 x double> [[OP1:%.*]], double [[OP2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i1> [[TMP0]]
//
vbool8_t test_vmfle_vf_f64m8_b8_m(vbool8_t mask, vfloat64m8_t op1, double op2, size_t vl) {
  return __riscv_vmfle(mask, op1, op2, vl);
}

