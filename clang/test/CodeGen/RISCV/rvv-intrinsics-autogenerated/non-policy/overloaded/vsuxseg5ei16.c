// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1f16.nxv1i16.i64(<vscale x 1 x half> [[V0:%.*]], <vscale x 1 x half> [[V1:%.*]], <vscale x 1 x half> [[V2:%.*]], <vscale x 1 x half> [[V3:%.*]], <vscale x 1 x half> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f16mf4(_Float16 *base, vuint16mf4_t bindex, vfloat16mf4_t v0, vfloat16mf4_t v1, vfloat16mf4_t v2, vfloat16mf4_t v3, vfloat16mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2f16.nxv2i16.i64(<vscale x 2 x half> [[V0:%.*]], <vscale x 2 x half> [[V1:%.*]], <vscale x 2 x half> [[V2:%.*]], <vscale x 2 x half> [[V3:%.*]], <vscale x 2 x half> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f16mf2(_Float16 *base, vuint16mf2_t bindex, vfloat16mf2_t v0, vfloat16mf2_t v1, vfloat16mf2_t v2, vfloat16mf2_t v3, vfloat16mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv4f16.nxv4i16.i64(<vscale x 4 x half> [[V0:%.*]], <vscale x 4 x half> [[V1:%.*]], <vscale x 4 x half> [[V2:%.*]], <vscale x 4 x half> [[V3:%.*]], <vscale x 4 x half> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f16m1(_Float16 *base, vuint16m1_t bindex, vfloat16m1_t v0, vfloat16m1_t v1, vfloat16m1_t v2, vfloat16m1_t v3, vfloat16m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f32mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1f32.nxv1i16.i64(<vscale x 1 x float> [[V0:%.*]], <vscale x 1 x float> [[V1:%.*]], <vscale x 1 x float> [[V2:%.*]], <vscale x 1 x float> [[V3:%.*]], <vscale x 1 x float> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f32mf2(float *base, vuint16mf4_t bindex, vfloat32mf2_t v0, vfloat32mf2_t v1, vfloat32mf2_t v2, vfloat32mf2_t v3, vfloat32mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2f32.nxv2i16.i64(<vscale x 2 x float> [[V0:%.*]], <vscale x 2 x float> [[V1:%.*]], <vscale x 2 x float> [[V2:%.*]], <vscale x 2 x float> [[V3:%.*]], <vscale x 2 x float> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f32m1(float *base, vuint16mf2_t bindex, vfloat32m1_t v0, vfloat32m1_t v1, vfloat32m1_t v2, vfloat32m1_t v3, vfloat32m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1f64.nxv1i16.i64(<vscale x 1 x double> [[V0:%.*]], <vscale x 1 x double> [[V1:%.*]], <vscale x 1 x double> [[V2:%.*]], <vscale x 1 x double> [[V3:%.*]], <vscale x 1 x double> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f64m1(double *base, vuint16mf4_t bindex, vfloat64m1_t v0, vfloat64m1_t v1, vfloat64m1_t v2, vfloat64m1_t v3, vfloat64m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8mf8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i8.nxv1i16.i64(<vscale x 1 x i8> [[V0:%.*]], <vscale x 1 x i8> [[V1:%.*]], <vscale x 1 x i8> [[V2:%.*]], <vscale x 1 x i8> [[V3:%.*]], <vscale x 1 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8mf8(int8_t *base, vuint16mf4_t bindex, vint8mf8_t v0, vint8mf8_t v1, vint8mf8_t v2, vint8mf8_t v3, vint8mf8_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2i8.nxv2i16.i64(<vscale x 2 x i8> [[V0:%.*]], <vscale x 2 x i8> [[V1:%.*]], <vscale x 2 x i8> [[V2:%.*]], <vscale x 2 x i8> [[V3:%.*]], <vscale x 2 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8mf4(int8_t *base, vuint16mf2_t bindex, vint8mf4_t v0, vint8mf4_t v1, vint8mf4_t v2, vint8mf4_t v3, vint8mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv4i8.nxv4i16.i64(<vscale x 4 x i8> [[V0:%.*]], <vscale x 4 x i8> [[V1:%.*]], <vscale x 4 x i8> [[V2:%.*]], <vscale x 4 x i8> [[V3:%.*]], <vscale x 4 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8mf2(int8_t *base, vuint16m1_t bindex, vint8mf2_t v0, vint8mf2_t v1, vint8mf2_t v2, vint8mf2_t v3, vint8mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv8i8.nxv8i16.i64(<vscale x 8 x i8> [[V0:%.*]], <vscale x 8 x i8> [[V1:%.*]], <vscale x 8 x i8> [[V2:%.*]], <vscale x 8 x i8> [[V3:%.*]], <vscale x 8 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8m1(int8_t *base, vuint16m2_t bindex, vint8m1_t v0, vint8m1_t v1, vint8m1_t v2, vint8m1_t v3, vint8m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i16.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], <vscale x 1 x i16> [[V2:%.*]], <vscale x 1 x i16> [[V3:%.*]], <vscale x 1 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i16mf4(int16_t *base, vuint16mf4_t bindex, vint16mf4_t v0, vint16mf4_t v1, vint16mf4_t v2, vint16mf4_t v3, vint16mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2i16.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], <vscale x 2 x i16> [[V2:%.*]], <vscale x 2 x i16> [[V3:%.*]], <vscale x 2 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i16mf2(int16_t *base, vuint16mf2_t bindex, vint16mf2_t v0, vint16mf2_t v1, vint16mf2_t v2, vint16mf2_t v3, vint16mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv4i16.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], <vscale x 4 x i16> [[V2:%.*]], <vscale x 4 x i16> [[V3:%.*]], <vscale x 4 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i16m1(int16_t *base, vuint16m1_t bindex, vint16m1_t v0, vint16m1_t v1, vint16m1_t v2, vint16m1_t v3, vint16m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i32mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i32.nxv1i16.i64(<vscale x 1 x i32> [[V0:%.*]], <vscale x 1 x i32> [[V1:%.*]], <vscale x 1 x i32> [[V2:%.*]], <vscale x 1 x i32> [[V3:%.*]], <vscale x 1 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i32mf2(int32_t *base, vuint16mf4_t bindex, vint32mf2_t v0, vint32mf2_t v1, vint32mf2_t v2, vint32mf2_t v3, vint32mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2i32.nxv2i16.i64(<vscale x 2 x i32> [[V0:%.*]], <vscale x 2 x i32> [[V1:%.*]], <vscale x 2 x i32> [[V2:%.*]], <vscale x 2 x i32> [[V3:%.*]], <vscale x 2 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i32m1(int32_t *base, vuint16mf2_t bindex, vint32m1_t v0, vint32m1_t v1, vint32m1_t v2, vint32m1_t v3, vint32m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i64m1(int64_t *base, vuint16mf4_t bindex, vint64m1_t v0, vint64m1_t v1, vint64m1_t v2, vint64m1_t v3, vint64m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8mf8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i8.nxv1i16.i64(<vscale x 1 x i8> [[V0:%.*]], <vscale x 1 x i8> [[V1:%.*]], <vscale x 1 x i8> [[V2:%.*]], <vscale x 1 x i8> [[V3:%.*]], <vscale x 1 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8mf8(uint8_t *base, vuint16mf4_t bindex, vuint8mf8_t v0, vuint8mf8_t v1, vuint8mf8_t v2, vuint8mf8_t v3, vuint8mf8_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2i8.nxv2i16.i64(<vscale x 2 x i8> [[V0:%.*]], <vscale x 2 x i8> [[V1:%.*]], <vscale x 2 x i8> [[V2:%.*]], <vscale x 2 x i8> [[V3:%.*]], <vscale x 2 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8mf4(uint8_t *base, vuint16mf2_t bindex, vuint8mf4_t v0, vuint8mf4_t v1, vuint8mf4_t v2, vuint8mf4_t v3, vuint8mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv4i8.nxv4i16.i64(<vscale x 4 x i8> [[V0:%.*]], <vscale x 4 x i8> [[V1:%.*]], <vscale x 4 x i8> [[V2:%.*]], <vscale x 4 x i8> [[V3:%.*]], <vscale x 4 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8mf2(uint8_t *base, vuint16m1_t bindex, vuint8mf2_t v0, vuint8mf2_t v1, vuint8mf2_t v2, vuint8mf2_t v3, vuint8mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv8i8.nxv8i16.i64(<vscale x 8 x i8> [[V0:%.*]], <vscale x 8 x i8> [[V1:%.*]], <vscale x 8 x i8> [[V2:%.*]], <vscale x 8 x i8> [[V3:%.*]], <vscale x 8 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8m1(uint8_t *base, vuint16m2_t bindex, vuint8m1_t v0, vuint8m1_t v1, vuint8m1_t v2, vuint8m1_t v3, vuint8m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i16.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], <vscale x 1 x i16> [[V2:%.*]], <vscale x 1 x i16> [[V3:%.*]], <vscale x 1 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u16mf4(uint16_t *base, vuint16mf4_t bindex, vuint16mf4_t v0, vuint16mf4_t v1, vuint16mf4_t v2, vuint16mf4_t v3, vuint16mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2i16.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], <vscale x 2 x i16> [[V2:%.*]], <vscale x 2 x i16> [[V3:%.*]], <vscale x 2 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u16mf2(uint16_t *base, vuint16mf2_t bindex, vuint16mf2_t v0, vuint16mf2_t v1, vuint16mf2_t v2, vuint16mf2_t v3, vuint16mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv4i16.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], <vscale x 4 x i16> [[V2:%.*]], <vscale x 4 x i16> [[V3:%.*]], <vscale x 4 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u16m1(uint16_t *base, vuint16m1_t bindex, vuint16m1_t v0, vuint16m1_t v1, vuint16m1_t v2, vuint16m1_t v3, vuint16m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u32mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i32.nxv1i16.i64(<vscale x 1 x i32> [[V0:%.*]], <vscale x 1 x i32> [[V1:%.*]], <vscale x 1 x i32> [[V2:%.*]], <vscale x 1 x i32> [[V3:%.*]], <vscale x 1 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u32mf2(uint32_t *base, vuint16mf4_t bindex, vuint32mf2_t v0, vuint32mf2_t v1, vuint32mf2_t v2, vuint32mf2_t v3, vuint32mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv2i32.nxv2i16.i64(<vscale x 2 x i32> [[V0:%.*]], <vscale x 2 x i32> [[V1:%.*]], <vscale x 2 x i32> [[V2:%.*]], <vscale x 2 x i32> [[V3:%.*]], <vscale x 2 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u32m1(uint32_t *base, vuint16mf2_t bindex, vuint32m1_t v0, vuint32m1_t v1, vuint32m1_t v2, vuint32m1_t v3, vuint32m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u64m1(uint64_t *base, vuint16mf4_t bindex, vuint64m1_t v0, vuint64m1_t v1, vuint64m1_t v2, vuint64m1_t v3, vuint64m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1f16.nxv1i16.i64(<vscale x 1 x half> [[V0:%.*]], <vscale x 1 x half> [[V1:%.*]], <vscale x 1 x half> [[V2:%.*]], <vscale x 1 x half> [[V3:%.*]], <vscale x 1 x half> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f16mf4_m(vbool64_t mask, _Float16 *base, vuint16mf4_t bindex, vfloat16mf4_t v0, vfloat16mf4_t v1, vfloat16mf4_t v2, vfloat16mf4_t v3, vfloat16mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2f16.nxv2i16.i64(<vscale x 2 x half> [[V0:%.*]], <vscale x 2 x half> [[V1:%.*]], <vscale x 2 x half> [[V2:%.*]], <vscale x 2 x half> [[V3:%.*]], <vscale x 2 x half> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f16mf2_m(vbool32_t mask, _Float16 *base, vuint16mf2_t bindex, vfloat16mf2_t v0, vfloat16mf2_t v1, vfloat16mf2_t v2, vfloat16mf2_t v3, vfloat16mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv4f16.nxv4i16.i64(<vscale x 4 x half> [[V0:%.*]], <vscale x 4 x half> [[V1:%.*]], <vscale x 4 x half> [[V2:%.*]], <vscale x 4 x half> [[V3:%.*]], <vscale x 4 x half> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f16m1_m(vbool16_t mask, _Float16 *base, vuint16m1_t bindex, vfloat16m1_t v0, vfloat16m1_t v1, vfloat16m1_t v2, vfloat16m1_t v3, vfloat16m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1f32.nxv1i16.i64(<vscale x 1 x float> [[V0:%.*]], <vscale x 1 x float> [[V1:%.*]], <vscale x 1 x float> [[V2:%.*]], <vscale x 1 x float> [[V3:%.*]], <vscale x 1 x float> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f32mf2_m(vbool64_t mask, float *base, vuint16mf4_t bindex, vfloat32mf2_t v0, vfloat32mf2_t v1, vfloat32mf2_t v2, vfloat32mf2_t v3, vfloat32mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2f32.nxv2i16.i64(<vscale x 2 x float> [[V0:%.*]], <vscale x 2 x float> [[V1:%.*]], <vscale x 2 x float> [[V2:%.*]], <vscale x 2 x float> [[V3:%.*]], <vscale x 2 x float> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f32m1_m(vbool32_t mask, float *base, vuint16mf2_t bindex, vfloat32m1_t v0, vfloat32m1_t v1, vfloat32m1_t v2, vfloat32m1_t v3, vfloat32m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_f64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1f64.nxv1i16.i64(<vscale x 1 x double> [[V0:%.*]], <vscale x 1 x double> [[V1:%.*]], <vscale x 1 x double> [[V2:%.*]], <vscale x 1 x double> [[V3:%.*]], <vscale x 1 x double> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_f64m1_m(vbool64_t mask, double *base, vuint16mf4_t bindex, vfloat64m1_t v0, vfloat64m1_t v1, vfloat64m1_t v2, vfloat64m1_t v3, vfloat64m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8mf8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i8.nxv1i16.i64(<vscale x 1 x i8> [[V0:%.*]], <vscale x 1 x i8> [[V1:%.*]], <vscale x 1 x i8> [[V2:%.*]], <vscale x 1 x i8> [[V3:%.*]], <vscale x 1 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8mf8_m(vbool64_t mask, int8_t *base, vuint16mf4_t bindex, vint8mf8_t v0, vint8mf8_t v1, vint8mf8_t v2, vint8mf8_t v3, vint8mf8_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2i8.nxv2i16.i64(<vscale x 2 x i8> [[V0:%.*]], <vscale x 2 x i8> [[V1:%.*]], <vscale x 2 x i8> [[V2:%.*]], <vscale x 2 x i8> [[V3:%.*]], <vscale x 2 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8mf4_m(vbool32_t mask, int8_t *base, vuint16mf2_t bindex, vint8mf4_t v0, vint8mf4_t v1, vint8mf4_t v2, vint8mf4_t v3, vint8mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv4i8.nxv4i16.i64(<vscale x 4 x i8> [[V0:%.*]], <vscale x 4 x i8> [[V1:%.*]], <vscale x 4 x i8> [[V2:%.*]], <vscale x 4 x i8> [[V3:%.*]], <vscale x 4 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8mf2_m(vbool16_t mask, int8_t *base, vuint16m1_t bindex, vint8mf2_t v0, vint8mf2_t v1, vint8mf2_t v2, vint8mf2_t v3, vint8mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i8m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv8i8.nxv8i16.i64(<vscale x 8 x i8> [[V0:%.*]], <vscale x 8 x i8> [[V1:%.*]], <vscale x 8 x i8> [[V2:%.*]], <vscale x 8 x i8> [[V3:%.*]], <vscale x 8 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i16> [[BINDEX:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i8m1_m(vbool8_t mask, int8_t *base, vuint16m2_t bindex, vint8m1_t v0, vint8m1_t v1, vint8m1_t v2, vint8m1_t v3, vint8m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i16.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], <vscale x 1 x i16> [[V2:%.*]], <vscale x 1 x i16> [[V3:%.*]], <vscale x 1 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i16mf4_m(vbool64_t mask, int16_t *base, vuint16mf4_t bindex, vint16mf4_t v0, vint16mf4_t v1, vint16mf4_t v2, vint16mf4_t v3, vint16mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2i16.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], <vscale x 2 x i16> [[V2:%.*]], <vscale x 2 x i16> [[V3:%.*]], <vscale x 2 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i16mf2_m(vbool32_t mask, int16_t *base, vuint16mf2_t bindex, vint16mf2_t v0, vint16mf2_t v1, vint16mf2_t v2, vint16mf2_t v3, vint16mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv4i16.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], <vscale x 4 x i16> [[V2:%.*]], <vscale x 4 x i16> [[V3:%.*]], <vscale x 4 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i16m1_m(vbool16_t mask, int16_t *base, vuint16m1_t bindex, vint16m1_t v0, vint16m1_t v1, vint16m1_t v2, vint16m1_t v3, vint16m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i32.nxv1i16.i64(<vscale x 1 x i32> [[V0:%.*]], <vscale x 1 x i32> [[V1:%.*]], <vscale x 1 x i32> [[V2:%.*]], <vscale x 1 x i32> [[V3:%.*]], <vscale x 1 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i32mf2_m(vbool64_t mask, int32_t *base, vuint16mf4_t bindex, vint32mf2_t v0, vint32mf2_t v1, vint32mf2_t v2, vint32mf2_t v3, vint32mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2i32.nxv2i16.i64(<vscale x 2 x i32> [[V0:%.*]], <vscale x 2 x i32> [[V1:%.*]], <vscale x 2 x i32> [[V2:%.*]], <vscale x 2 x i32> [[V3:%.*]], <vscale x 2 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i32m1_m(vbool32_t mask, int32_t *base, vuint16mf2_t bindex, vint32m1_t v0, vint32m1_t v1, vint32m1_t v2, vint32m1_t v3, vint32m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_i64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_i64m1_m(vbool64_t mask, int64_t *base, vuint16mf4_t bindex, vint64m1_t v0, vint64m1_t v1, vint64m1_t v2, vint64m1_t v3, vint64m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8mf8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i8.nxv1i16.i64(<vscale x 1 x i8> [[V0:%.*]], <vscale x 1 x i8> [[V1:%.*]], <vscale x 1 x i8> [[V2:%.*]], <vscale x 1 x i8> [[V3:%.*]], <vscale x 1 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8mf8_m(vbool64_t mask, uint8_t *base, vuint16mf4_t bindex, vuint8mf8_t v0, vuint8mf8_t v1, vuint8mf8_t v2, vuint8mf8_t v3, vuint8mf8_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2i8.nxv2i16.i64(<vscale x 2 x i8> [[V0:%.*]], <vscale x 2 x i8> [[V1:%.*]], <vscale x 2 x i8> [[V2:%.*]], <vscale x 2 x i8> [[V3:%.*]], <vscale x 2 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8mf4_m(vbool32_t mask, uint8_t *base, vuint16mf2_t bindex, vuint8mf4_t v0, vuint8mf4_t v1, vuint8mf4_t v2, vuint8mf4_t v3, vuint8mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv4i8.nxv4i16.i64(<vscale x 4 x i8> [[V0:%.*]], <vscale x 4 x i8> [[V1:%.*]], <vscale x 4 x i8> [[V2:%.*]], <vscale x 4 x i8> [[V3:%.*]], <vscale x 4 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8mf2_m(vbool16_t mask, uint8_t *base, vuint16m1_t bindex, vuint8mf2_t v0, vuint8mf2_t v1, vuint8mf2_t v2, vuint8mf2_t v3, vuint8mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u8m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv8i8.nxv8i16.i64(<vscale x 8 x i8> [[V0:%.*]], <vscale x 8 x i8> [[V1:%.*]], <vscale x 8 x i8> [[V2:%.*]], <vscale x 8 x i8> [[V3:%.*]], <vscale x 8 x i8> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 8 x i16> [[BINDEX:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u8m1_m(vbool8_t mask, uint8_t *base, vuint16m2_t bindex, vuint8m1_t v0, vuint8m1_t v1, vuint8m1_t v2, vuint8m1_t v3, vuint8m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i16.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], <vscale x 1 x i16> [[V2:%.*]], <vscale x 1 x i16> [[V3:%.*]], <vscale x 1 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u16mf4_m(vbool64_t mask, uint16_t *base, vuint16mf4_t bindex, vuint16mf4_t v0, vuint16mf4_t v1, vuint16mf4_t v2, vuint16mf4_t v3, vuint16mf4_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2i16.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], <vscale x 2 x i16> [[V2:%.*]], <vscale x 2 x i16> [[V3:%.*]], <vscale x 2 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u16mf2_m(vbool32_t mask, uint16_t *base, vuint16mf2_t bindex, vuint16mf2_t v0, vuint16mf2_t v1, vuint16mf2_t v2, vuint16mf2_t v3, vuint16mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv4i16.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], <vscale x 4 x i16> [[V2:%.*]], <vscale x 4 x i16> [[V3:%.*]], <vscale x 4 x i16> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 4 x i16> [[BINDEX:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u16m1_m(vbool16_t mask, uint16_t *base, vuint16m1_t bindex, vuint16m1_t v0, vuint16m1_t v1, vuint16m1_t v2, vuint16m1_t v3, vuint16m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i32.nxv1i16.i64(<vscale x 1 x i32> [[V0:%.*]], <vscale x 1 x i32> [[V1:%.*]], <vscale x 1 x i32> [[V2:%.*]], <vscale x 1 x i32> [[V3:%.*]], <vscale x 1 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u32mf2_m(vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2_t v0, vuint32mf2_t v1, vuint32mf2_t v2, vuint32mf2_t v3, vuint32mf2_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv2i32.nxv2i16.i64(<vscale x 2 x i32> [[V0:%.*]], <vscale x 2 x i32> [[V1:%.*]], <vscale x 2 x i32> [[V2:%.*]], <vscale x 2 x i32> [[V3:%.*]], <vscale x 2 x i32> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 2 x i16> [[BINDEX:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u32m1_m(vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1_t v0, vuint32m1_t v1, vuint32m1_t v2, vuint32m1_t v3, vuint32m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

// CHECK-RV64-LABEL: @test_vsuxseg5ei16_v_u64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vsuxseg5.mask.nxv1i64.nxv1i16.i64(<vscale x 1 x i64> [[V0:%.*]], <vscale x 1 x i64> [[V1:%.*]], <vscale x 1 x i64> [[V2:%.*]], <vscale x 1 x i64> [[V3:%.*]], <vscale x 1 x i64> [[V4:%.*]], ptr [[BASE:%.*]], <vscale x 1 x i16> [[BINDEX:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vsuxseg5ei16_v_u64m1_m(vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1_t v0, vuint64m1_t v1, vuint64m1_t v2, vuint64m1_t v3, vuint64m1_t v4, size_t vl) {
  return __riscv_vsuxseg5ei16(mask, base, bindex, v0, v1, v2, v3, v4, vl);
}

