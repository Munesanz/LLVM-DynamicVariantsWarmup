// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwmacc.nxv1i16.nxv1i8.nxv1i8.i64(<vscale x 1 x i16> [[VD:%.*]], <vscale x 1 x i8> [[VS1:%.*]], <vscale x 1 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vint16mf4_t test_vwmacc_vv_i16mf4(vint16mf4_t vd, vint8mf8_t vs1, vint8mf8_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16mf4(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwmacc.nxv1i16.i8.nxv1i8.i64(<vscale x 1 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 1 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vint16mf4_t test_vwmacc_vx_i16mf4(vint16mf4_t vd, int8_t rs1, vint8mf8_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16mf4(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwmacc.nxv2i16.nxv2i8.nxv2i8.i64(<vscale x 2 x i16> [[VD:%.*]], <vscale x 2 x i8> [[VS1:%.*]], <vscale x 2 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vint16mf2_t test_vwmacc_vv_i16mf2(vint16mf2_t vd, vint8mf4_t vs1, vint8mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16mf2(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwmacc.nxv2i16.i8.nxv2i8.i64(<vscale x 2 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 2 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vint16mf2_t test_vwmacc_vx_i16mf2(vint16mf2_t vd, int8_t rs1, vint8mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16mf2(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwmacc.nxv4i16.nxv4i8.nxv4i8.i64(<vscale x 4 x i16> [[VD:%.*]], <vscale x 4 x i8> [[VS1:%.*]], <vscale x 4 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vwmacc_vv_i16m1(vint16m1_t vd, vint8mf2_t vs1, vint8mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m1(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwmacc.nxv4i16.i8.nxv4i8.i64(<vscale x 4 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 4 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vwmacc_vx_i16m1(vint16m1_t vd, int8_t rs1, vint8mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m1(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwmacc.nxv8i16.nxv8i8.nxv8i8.i64(<vscale x 8 x i16> [[VD:%.*]], <vscale x 8 x i8> [[VS1:%.*]], <vscale x 8 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vint16m2_t test_vwmacc_vv_i16m2(vint16m2_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m2(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwmacc.nxv8i16.i8.nxv8i8.i64(<vscale x 8 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 8 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vint16m2_t test_vwmacc_vx_i16m2(vint16m2_t vd, int8_t rs1, vint8m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m2(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwmacc.nxv16i16.nxv16i8.nxv16i8.i64(<vscale x 16 x i16> [[VD:%.*]], <vscale x 16 x i8> [[VS1:%.*]], <vscale x 16 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vint16m4_t test_vwmacc_vv_i16m4(vint16m4_t vd, vint8m2_t vs1, vint8m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m4(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwmacc.nxv16i16.i8.nxv16i8.i64(<vscale x 16 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 16 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vint16m4_t test_vwmacc_vx_i16m4(vint16m4_t vd, int8_t rs1, vint8m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m4(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwmacc.nxv32i16.nxv32i8.nxv32i8.i64(<vscale x 32 x i16> [[VD:%.*]], <vscale x 32 x i8> [[VS1:%.*]], <vscale x 32 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vint16m8_t test_vwmacc_vv_i16m8(vint16m8_t vd, vint8m4_t vs1, vint8m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m8(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwmacc.nxv32i16.i8.nxv32i8.i64(<vscale x 32 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 32 x i8> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vint16m8_t test_vwmacc_vx_i16m8(vint16m8_t vd, int8_t rs1, vint8m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m8(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwmacc.nxv1i32.nxv1i16.nxv1i16.i64(<vscale x 1 x i32> [[VD:%.*]], <vscale x 1 x i16> [[VS1:%.*]], <vscale x 1 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vwmacc_vv_i32mf2(vint32mf2_t vd, vint16mf4_t vs1, vint16mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32mf2(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwmacc.nxv1i32.i16.nxv1i16.i64(<vscale x 1 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 1 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vwmacc_vx_i32mf2(vint32mf2_t vd, int16_t rs1, vint16mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32mf2(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwmacc.nxv2i32.nxv2i16.nxv2i16.i64(<vscale x 2 x i32> [[VD:%.*]], <vscale x 2 x i16> [[VS1:%.*]], <vscale x 2 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vwmacc_vv_i32m1(vint32m1_t vd, vint16mf2_t vs1, vint16mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m1(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwmacc.nxv2i32.i16.nxv2i16.i64(<vscale x 2 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 2 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vwmacc_vx_i32m1(vint32m1_t vd, int16_t rs1, vint16mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m1(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwmacc.nxv4i32.nxv4i16.nxv4i16.i64(<vscale x 4 x i32> [[VD:%.*]], <vscale x 4 x i16> [[VS1:%.*]], <vscale x 4 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vwmacc_vv_i32m2(vint32m2_t vd, vint16m1_t vs1, vint16m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m2(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwmacc.nxv4i32.i16.nxv4i16.i64(<vscale x 4 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 4 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vwmacc_vx_i32m2(vint32m2_t vd, int16_t rs1, vint16m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m2(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwmacc.nxv8i32.nxv8i16.nxv8i16.i64(<vscale x 8 x i32> [[VD:%.*]], <vscale x 8 x i16> [[VS1:%.*]], <vscale x 8 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vwmacc_vv_i32m4(vint32m4_t vd, vint16m2_t vs1, vint16m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m4(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwmacc.nxv8i32.i16.nxv8i16.i64(<vscale x 8 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 8 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vwmacc_vx_i32m4(vint32m4_t vd, int16_t rs1, vint16m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m4(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwmacc.nxv16i32.nxv16i16.nxv16i16.i64(<vscale x 16 x i32> [[VD:%.*]], <vscale x 16 x i16> [[VS1:%.*]], <vscale x 16 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vwmacc_vv_i32m8(vint32m8_t vd, vint16m4_t vs1, vint16m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m8(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwmacc.nxv16i32.i16.nxv16i16.i64(<vscale x 16 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 16 x i16> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vwmacc_vx_i32m8(vint32m8_t vd, int16_t rs1, vint16m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m8(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwmacc.nxv1i64.nxv1i32.nxv1i32.i64(<vscale x 1 x i64> [[VD:%.*]], <vscale x 1 x i32> [[VS1:%.*]], <vscale x 1 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vwmacc_vv_i64m1(vint64m1_t vd, vint32mf2_t vs1, vint32mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m1(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwmacc.nxv1i64.i32.nxv1i32.i64(<vscale x 1 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 1 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vwmacc_vx_i64m1(vint64m1_t vd, int32_t rs1, vint32mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m1(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwmacc.nxv2i64.nxv2i32.nxv2i32.i64(<vscale x 2 x i64> [[VD:%.*]], <vscale x 2 x i32> [[VS1:%.*]], <vscale x 2 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vwmacc_vv_i64m2(vint64m2_t vd, vint32m1_t vs1, vint32m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m2(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwmacc.nxv2i64.i32.nxv2i32.i64(<vscale x 2 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 2 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vwmacc_vx_i64m2(vint64m2_t vd, int32_t rs1, vint32m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m2(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwmacc.nxv4i64.nxv4i32.nxv4i32.i64(<vscale x 4 x i64> [[VD:%.*]], <vscale x 4 x i32> [[VS1:%.*]], <vscale x 4 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vwmacc_vv_i64m4(vint64m4_t vd, vint32m2_t vs1, vint32m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m4(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwmacc.nxv4i64.i32.nxv4i32.i64(<vscale x 4 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 4 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vwmacc_vx_i64m4(vint64m4_t vd, int32_t rs1, vint32m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m4(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwmacc.nxv8i64.nxv8i32.nxv8i32.i64(<vscale x 8 x i64> [[VD:%.*]], <vscale x 8 x i32> [[VS1:%.*]], <vscale x 8 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vwmacc_vv_i64m8(vint64m8_t vd, vint32m4_t vs1, vint32m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m8(vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m8(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwmacc.nxv8i64.i32.nxv8i32.i64(<vscale x 8 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 8 x i32> [[VS2:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vwmacc_vx_i64m8(vint64m8_t vd, int32_t rs1, vint32m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m8(vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwmacc.mask.nxv1i16.nxv1i8.nxv1i8.i64(<vscale x 1 x i16> [[VD:%.*]], <vscale x 1 x i8> [[VS1:%.*]], <vscale x 1 x i8> [[VS2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vint16mf4_t test_vwmacc_vv_i16mf4_m(vbool64_t mask, vint16mf4_t vd, vint8mf8_t vs1, vint8mf8_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16mf4_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i16> @llvm.riscv.vwmacc.mask.nxv1i16.i8.nxv1i8.i64(<vscale x 1 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 1 x i8> [[VS2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i16> [[TMP0]]
//
vint16mf4_t test_vwmacc_vx_i16mf4_m(vbool64_t mask, vint16mf4_t vd, int8_t rs1, vint8mf8_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16mf4_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwmacc.mask.nxv2i16.nxv2i8.nxv2i8.i64(<vscale x 2 x i16> [[VD:%.*]], <vscale x 2 x i8> [[VS1:%.*]], <vscale x 2 x i8> [[VS2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vint16mf2_t test_vwmacc_vv_i16mf2_m(vbool32_t mask, vint16mf2_t vd, vint8mf4_t vs1, vint8mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16mf2_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i16> @llvm.riscv.vwmacc.mask.nxv2i16.i8.nxv2i8.i64(<vscale x 2 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 2 x i8> [[VS2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i16> [[TMP0]]
//
vint16mf2_t test_vwmacc_vx_i16mf2_m(vbool32_t mask, vint16mf2_t vd, int8_t rs1, vint8mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16mf2_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwmacc.mask.nxv4i16.nxv4i8.nxv4i8.i64(<vscale x 4 x i16> [[VD:%.*]], <vscale x 4 x i8> [[VS1:%.*]], <vscale x 4 x i8> [[VS2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vwmacc_vv_i16m1_m(vbool16_t mask, vint16m1_t vd, vint8mf2_t vs1, vint8mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m1_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i16> @llvm.riscv.vwmacc.mask.nxv4i16.i8.nxv4i8.i64(<vscale x 4 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 4 x i8> [[VS2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i16> [[TMP0]]
//
vint16m1_t test_vwmacc_vx_i16m1_m(vbool16_t mask, vint16m1_t vd, int8_t rs1, vint8mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m1_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwmacc.mask.nxv8i16.nxv8i8.nxv8i8.i64(<vscale x 8 x i16> [[VD:%.*]], <vscale x 8 x i8> [[VS1:%.*]], <vscale x 8 x i8> [[VS2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vint16m2_t test_vwmacc_vv_i16m2_m(vbool8_t mask, vint16m2_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m2_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i16> @llvm.riscv.vwmacc.mask.nxv8i16.i8.nxv8i8.i64(<vscale x 8 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 8 x i8> [[VS2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i16> [[TMP0]]
//
vint16m2_t test_vwmacc_vx_i16m2_m(vbool8_t mask, vint16m2_t vd, int8_t rs1, vint8m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m2_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwmacc.mask.nxv16i16.nxv16i8.nxv16i8.i64(<vscale x 16 x i16> [[VD:%.*]], <vscale x 16 x i8> [[VS1:%.*]], <vscale x 16 x i8> [[VS2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vint16m4_t test_vwmacc_vv_i16m4_m(vbool4_t mask, vint16m4_t vd, vint8m2_t vs1, vint8m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m4_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i16> @llvm.riscv.vwmacc.mask.nxv16i16.i8.nxv16i8.i64(<vscale x 16 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 16 x i8> [[VS2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i16> [[TMP0]]
//
vint16m4_t test_vwmacc_vx_i16m4_m(vbool4_t mask, vint16m4_t vd, int8_t rs1, vint8m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m4_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i16m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwmacc.mask.nxv32i16.nxv32i8.nxv32i8.i64(<vscale x 32 x i16> [[VD:%.*]], <vscale x 32 x i8> [[VS1:%.*]], <vscale x 32 x i8> [[VS2:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vint16m8_t test_vwmacc_vv_i16m8_m(vbool2_t mask, vint16m8_t vd, vint8m4_t vs1, vint8m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i16m8_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i16m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 32 x i16> @llvm.riscv.vwmacc.mask.nxv32i16.i8.nxv32i8.i64(<vscale x 32 x i16> [[VD:%.*]], i8 [[RS1:%.*]], <vscale x 32 x i8> [[VS2:%.*]], <vscale x 32 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 32 x i16> [[TMP0]]
//
vint16m8_t test_vwmacc_vx_i16m8_m(vbool2_t mask, vint16m8_t vd, int8_t rs1, vint8m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i16m8_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwmacc.mask.nxv1i32.nxv1i16.nxv1i16.i64(<vscale x 1 x i32> [[VD:%.*]], <vscale x 1 x i16> [[VS1:%.*]], <vscale x 1 x i16> [[VS2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vwmacc_vv_i32mf2_m(vbool64_t mask, vint32mf2_t vd, vint16mf4_t vs1, vint16mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32mf2_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vwmacc.mask.nxv1i32.i16.nxv1i16.i64(<vscale x 1 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 1 x i16> [[VS2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vwmacc_vx_i32mf2_m(vbool64_t mask, vint32mf2_t vd, int16_t rs1, vint16mf4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32mf2_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwmacc.mask.nxv2i32.nxv2i16.nxv2i16.i64(<vscale x 2 x i32> [[VD:%.*]], <vscale x 2 x i16> [[VS1:%.*]], <vscale x 2 x i16> [[VS2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vwmacc_vv_i32m1_m(vbool32_t mask, vint32m1_t vd, vint16mf2_t vs1, vint16mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m1_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vwmacc.mask.nxv2i32.i16.nxv2i16.i64(<vscale x 2 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 2 x i16> [[VS2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vwmacc_vx_i32m1_m(vbool32_t mask, vint32m1_t vd, int16_t rs1, vint16mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m1_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwmacc.mask.nxv4i32.nxv4i16.nxv4i16.i64(<vscale x 4 x i32> [[VD:%.*]], <vscale x 4 x i16> [[VS1:%.*]], <vscale x 4 x i16> [[VS2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vwmacc_vv_i32m2_m(vbool16_t mask, vint32m2_t vd, vint16m1_t vs1, vint16m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m2_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vwmacc.mask.nxv4i32.i16.nxv4i16.i64(<vscale x 4 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 4 x i16> [[VS2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vwmacc_vx_i32m2_m(vbool16_t mask, vint32m2_t vd, int16_t rs1, vint16m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m2_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwmacc.mask.nxv8i32.nxv8i16.nxv8i16.i64(<vscale x 8 x i32> [[VD:%.*]], <vscale x 8 x i16> [[VS1:%.*]], <vscale x 8 x i16> [[VS2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vwmacc_vv_i32m4_m(vbool8_t mask, vint32m4_t vd, vint16m2_t vs1, vint16m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m4_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vwmacc.mask.nxv8i32.i16.nxv8i16.i64(<vscale x 8 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 8 x i16> [[VS2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vwmacc_vx_i32m4_m(vbool8_t mask, vint32m4_t vd, int16_t rs1, vint16m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m4_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i32m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwmacc.mask.nxv16i32.nxv16i16.nxv16i16.i64(<vscale x 16 x i32> [[VD:%.*]], <vscale x 16 x i16> [[VS1:%.*]], <vscale x 16 x i16> [[VS2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vwmacc_vv_i32m8_m(vbool4_t mask, vint32m8_t vd, vint16m4_t vs1, vint16m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i32m8_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i32m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vwmacc.mask.nxv16i32.i16.nxv16i16.i64(<vscale x 16 x i32> [[VD:%.*]], i16 [[RS1:%.*]], <vscale x 16 x i16> [[VS2:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vwmacc_vx_i32m8_m(vbool4_t mask, vint32m8_t vd, int16_t rs1, vint16m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i32m8_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwmacc.mask.nxv1i64.nxv1i32.nxv1i32.i64(<vscale x 1 x i64> [[VD:%.*]], <vscale x 1 x i32> [[VS1:%.*]], <vscale x 1 x i32> [[VS2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vwmacc_vv_i64m1_m(vbool64_t mask, vint64m1_t vd, vint32mf2_t vs1, vint32mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m1_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i64> @llvm.riscv.vwmacc.mask.nxv1i64.i32.nxv1i32.i64(<vscale x 1 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 1 x i32> [[VS2:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i64> [[TMP0]]
//
vint64m1_t test_vwmacc_vx_i64m1_m(vbool64_t mask, vint64m1_t vd, int32_t rs1, vint32mf2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m1_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwmacc.mask.nxv2i64.nxv2i32.nxv2i32.i64(<vscale x 2 x i64> [[VD:%.*]], <vscale x 2 x i32> [[VS1:%.*]], <vscale x 2 x i32> [[VS2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vwmacc_vv_i64m2_m(vbool32_t mask, vint64m2_t vd, vint32m1_t vs1, vint32m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m2_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i64> @llvm.riscv.vwmacc.mask.nxv2i64.i32.nxv2i32.i64(<vscale x 2 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 2 x i32> [[VS2:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i64> [[TMP0]]
//
vint64m2_t test_vwmacc_vx_i64m2_m(vbool32_t mask, vint64m2_t vd, int32_t rs1, vint32m1_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m2_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwmacc.mask.nxv4i64.nxv4i32.nxv4i32.i64(<vscale x 4 x i64> [[VD:%.*]], <vscale x 4 x i32> [[VS1:%.*]], <vscale x 4 x i32> [[VS2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vwmacc_vv_i64m4_m(vbool16_t mask, vint64m4_t vd, vint32m2_t vs1, vint32m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m4_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.vwmacc.mask.nxv4i64.i32.nxv4i32.i64(<vscale x 4 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 4 x i32> [[VS2:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vint64m4_t test_vwmacc_vx_i64m4_m(vbool16_t mask, vint64m4_t vd, int32_t rs1, vint32m2_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m4_m(mask, vd, rs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vv_i64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwmacc.mask.nxv8i64.nxv8i32.nxv8i32.i64(<vscale x 8 x i64> [[VD:%.*]], <vscale x 8 x i32> [[VS1:%.*]], <vscale x 8 x i32> [[VS2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vwmacc_vv_i64m8_m(vbool8_t mask, vint64m8_t vd, vint32m4_t vs1, vint32m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vv_i64m8_m(mask, vd, vs1, vs2, vl);
}

// CHECK-RV64-LABEL: @test_vwmacc_vx_i64m8_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i64> @llvm.riscv.vwmacc.mask.nxv8i64.i32.nxv8i32.i64(<vscale x 8 x i64> [[VD:%.*]], i32 [[RS1:%.*]], <vscale x 8 x i32> [[VS2:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i64> [[TMP0]]
//
vint64m8_t test_vwmacc_vx_i64m8_m(vbool8_t mask, vint64m8_t vd, int32_t rs1, vint32m4_t vs2, size_t vl) {
  return __riscv_vwmacc_vx_i64m8_m(mask, vd, rs1, vs2, vl);
}

