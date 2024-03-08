// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vlse32_v_f32mf2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vlse.nxv1f32.i64(<vscale x 1 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vlse32_v_f32mf2_tu(vfloat32mf2_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vlse.nxv2f32.i64(<vscale x 2 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vlse32_v_f32m1_tu(vfloat32m1_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vlse.nxv4f32.i64(<vscale x 4 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vlse32_v_f32m2_tu(vfloat32m2_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vlse.nxv8f32.i64(<vscale x 8 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vlse32_v_f32m4_tu(vfloat32m4_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vlse.nxv16f32.i64(<vscale x 16 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vlse32_v_f32m8_tu(vfloat32m8_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32mf2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vlse.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vlse32_v_i32mf2_tu(vint32mf2_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vlse.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vlse32_v_i32m1_tu(vint32m1_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vlse.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vlse32_v_i32m2_tu(vint32m2_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vlse.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vlse32_v_i32m4_tu(vint32m4_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vlse.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vlse32_v_i32m8_tu(vint32m8_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32mf2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vlse.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vlse32_v_u32mf2_tu(vuint32mf2_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m1_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vlse.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vlse32_v_u32m1_tu(vuint32m1_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m2_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vlse.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vlse32_v_u32m2_tu(vuint32m2_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m4_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vlse.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vlse32_v_u32m4_tu(vuint32m4_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m8_tu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vlse.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vlse32_v_u32m8_tu(vuint32m8_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tu(maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32mf2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vlse.mask.nxv1f32.i64(<vscale x 1 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vlse32_v_f32mf2_tum(vbool64_t mask, vfloat32mf2_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vlse.mask.nxv2f32.i64(<vscale x 2 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vlse32_v_f32m1_tum(vbool32_t mask, vfloat32m1_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vlse.mask.nxv4f32.i64(<vscale x 4 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vlse32_v_f32m2_tum(vbool16_t mask, vfloat32m2_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vlse.mask.nxv8f32.i64(<vscale x 8 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vlse32_v_f32m4_tum(vbool8_t mask, vfloat32m4_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vlse.mask.nxv16f32.i64(<vscale x 16 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vlse32_v_f32m8_tum(vbool4_t mask, vfloat32m8_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32mf2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vlse.mask.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vlse32_v_i32mf2_tum(vbool64_t mask, vint32mf2_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vlse.mask.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vlse32_v_i32m1_tum(vbool32_t mask, vint32m1_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vlse.mask.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vlse32_v_i32m2_tum(vbool16_t mask, vint32m2_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vlse.mask.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vlse32_v_i32m4_tum(vbool8_t mask, vint32m4_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vlse.mask.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vlse32_v_i32m8_tum(vbool4_t mask, vint32m8_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32mf2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vlse.mask.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vlse32_v_u32mf2_tum(vbool64_t mask, vuint32mf2_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m1_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vlse.mask.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vlse32_v_u32m1_tum(vbool32_t mask, vuint32m1_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m2_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vlse.mask.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vlse32_v_u32m2_tum(vbool16_t mask, vuint32m2_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m4_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vlse.mask.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vlse32_v_u32m4_tum(vbool8_t mask, vuint32m4_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m8_tum(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vlse.mask.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 2)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vlse32_v_u32m8_tum(vbool4_t mask, vuint32m8_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tum(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32mf2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x float> @llvm.riscv.vlse.mask.nxv1f32.i64(<vscale x 1 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x float> [[TMP0]]
//
vfloat32mf2_t test_vlse32_v_f32mf2_tumu(vbool64_t mask, vfloat32mf2_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x float> @llvm.riscv.vlse.mask.nxv2f32.i64(<vscale x 2 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x float> [[TMP0]]
//
vfloat32m1_t test_vlse32_v_f32m1_tumu(vbool32_t mask, vfloat32m1_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x float> @llvm.riscv.vlse.mask.nxv4f32.i64(<vscale x 4 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x float> [[TMP0]]
//
vfloat32m2_t test_vlse32_v_f32m2_tumu(vbool16_t mask, vfloat32m2_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x float> @llvm.riscv.vlse.mask.nxv8f32.i64(<vscale x 8 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x float> [[TMP0]]
//
vfloat32m4_t test_vlse32_v_f32m4_tumu(vbool8_t mask, vfloat32m4_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_f32m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x float> @llvm.riscv.vlse.mask.nxv16f32.i64(<vscale x 16 x float> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x float> [[TMP0]]
//
vfloat32m8_t test_vlse32_v_f32m8_tumu(vbool4_t mask, vfloat32m8_t maskedoff, const float *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32mf2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vlse.mask.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vint32mf2_t test_vlse32_v_i32mf2_tumu(vbool64_t mask, vint32mf2_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vlse.mask.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vint32m1_t test_vlse32_v_i32m1_tumu(vbool32_t mask, vint32m1_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vlse.mask.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vint32m2_t test_vlse32_v_i32m2_tumu(vbool16_t mask, vint32m2_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vlse.mask.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vint32m4_t test_vlse32_v_i32m4_tumu(vbool8_t mask, vint32m4_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_i32m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vlse.mask.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vint32m8_t test_vlse32_v_i32m8_tumu(vbool4_t mask, vint32m8_t maskedoff, const int32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32mf2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 1 x i32> @llvm.riscv.vlse.mask.nxv1i32.i64(<vscale x 1 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 1 x i32> [[TMP0]]
//
vuint32mf2_t test_vlse32_v_u32mf2_tumu(vbool64_t mask, vuint32mf2_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m1_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 2 x i32> @llvm.riscv.vlse.mask.nxv2i32.i64(<vscale x 2 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 2 x i32> [[TMP0]]
//
vuint32m1_t test_vlse32_v_u32m1_tumu(vbool32_t mask, vuint32m1_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m2_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i32> @llvm.riscv.vlse.mask.nxv4i32.i64(<vscale x 4 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i32> [[TMP0]]
//
vuint32m2_t test_vlse32_v_u32m2_tumu(vbool16_t mask, vuint32m2_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m4_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 8 x i32> @llvm.riscv.vlse.mask.nxv8i32.i64(<vscale x 8 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 8 x i32> [[TMP0]]
//
vuint32m4_t test_vlse32_v_u32m4_tumu(vbool8_t mask, vuint32m4_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlse32_v_u32m8_tumu(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 16 x i32> @llvm.riscv.vlse.mask.nxv16i32.i64(<vscale x 16 x i32> [[MASKEDOFF:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 0)
// CHECK-RV64-NEXT:    ret <vscale x 16 x i32> [[TMP0]]
//
vuint32m8_t test_vlse32_v_u32m8_tumu(vbool4_t mask, vuint32m8_t maskedoff, const uint32_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlse32_tumu(mask, maskedoff, base, bstride, vl);
}

