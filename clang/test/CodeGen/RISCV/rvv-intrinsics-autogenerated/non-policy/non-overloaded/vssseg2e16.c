// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv1f16.i64(<vscale x 1 x half> [[V0:%.*]], <vscale x 1 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf4(_Float16 *base, ptrdiff_t bstride, vfloat16mf4_t v0, vfloat16mf4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf4(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv2f16.i64(<vscale x 2 x half> [[V0:%.*]], <vscale x 2 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf2(_Float16 *base, ptrdiff_t bstride, vfloat16mf2_t v0, vfloat16mf2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf2(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv4f16.i64(<vscale x 4 x half> [[V0:%.*]], <vscale x 4 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m1(_Float16 *base, ptrdiff_t bstride, vfloat16m1_t v0, vfloat16m1_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16m1(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv8f16.i64(<vscale x 8 x half> [[V0:%.*]], <vscale x 8 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m2(_Float16 *base, ptrdiff_t bstride, vfloat16m2_t v0, vfloat16m2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16m2(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv16f16.i64(<vscale x 16 x half> [[V0:%.*]], <vscale x 16 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m4(_Float16 *base, ptrdiff_t bstride, vfloat16m4_t v0, vfloat16m4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16m4(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf4(int16_t *base, ptrdiff_t bstride, vint16mf4_t v0, vint16mf4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf4(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf2(int16_t *base, ptrdiff_t bstride, vint16mf2_t v0, vint16mf2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf2(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m1(int16_t *base, ptrdiff_t bstride, vint16m1_t v0, vint16m1_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16m1(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv8i16.i64(<vscale x 8 x i16> [[V0:%.*]], <vscale x 8 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m2(int16_t *base, ptrdiff_t bstride, vint16m2_t v0, vint16m2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16m2(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv16i16.i64(<vscale x 16 x i16> [[V0:%.*]], <vscale x 16 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m4(int16_t *base, ptrdiff_t bstride, vint16m4_t v0, vint16m4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16m4(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16mf4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf4(uint16_t *base, ptrdiff_t bstride, vuint16mf4_t v0, vuint16mf4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf4(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16mf2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf2(uint16_t *base, ptrdiff_t bstride, vuint16mf2_t v0, vuint16mf2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf2(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16m1(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m1(uint16_t *base, ptrdiff_t bstride, vuint16m1_t v0, vuint16m1_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16m1(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16m2(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv8i16.i64(<vscale x 8 x i16> [[V0:%.*]], <vscale x 8 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m2(uint16_t *base, ptrdiff_t bstride, vuint16m2_t v0, vuint16m2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16m2(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16m4(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.nxv16i16.i64(<vscale x 16 x i16> [[V0:%.*]], <vscale x 16 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m4(uint16_t *base, ptrdiff_t bstride, vuint16m4_t v0, vuint16m4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16m4(base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv1f16.i64(<vscale x 1 x half> [[V0:%.*]], <vscale x 1 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf4_m(vbool64_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16mf4_t v0, vfloat16mf4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf4_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv2f16.i64(<vscale x 2 x half> [[V0:%.*]], <vscale x 2 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16mf2_m(vbool32_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16mf2_t v0, vfloat16mf2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16mf2_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv4f16.i64(<vscale x 4 x half> [[V0:%.*]], <vscale x 4 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m1_m(vbool16_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16m1_t v0, vfloat16m1_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16m1_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv8f16.i64(<vscale x 8 x half> [[V0:%.*]], <vscale x 8 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m2_m(vbool8_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16m2_t v0, vfloat16m2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16m2_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_f16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv16f16.i64(<vscale x 16 x half> [[V0:%.*]], <vscale x 16 x half> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_f16m4_m(vbool4_t mask, _Float16 *base, ptrdiff_t bstride, vfloat16m4_t v0, vfloat16m4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_f16m4_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf4_m(vbool64_t mask, int16_t *base, ptrdiff_t bstride, vint16mf4_t v0, vint16mf4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf4_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16mf2_m(vbool32_t mask, int16_t *base, ptrdiff_t bstride, vint16mf2_t v0, vint16mf2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16mf2_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m1_m(vbool16_t mask, int16_t *base, ptrdiff_t bstride, vint16m1_t v0, vint16m1_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16m1_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv8i16.i64(<vscale x 8 x i16> [[V0:%.*]], <vscale x 8 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m2_m(vbool8_t mask, int16_t *base, ptrdiff_t bstride, vint16m2_t v0, vint16m2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16m2_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_i16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv16i16.i64(<vscale x 16 x i16> [[V0:%.*]], <vscale x 16 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_i16m4_m(vbool4_t mask, int16_t *base, ptrdiff_t bstride, vint16m4_t v0, vint16m4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_i16m4_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv1i16.i64(<vscale x 1 x i16> [[V0:%.*]], <vscale x 1 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf4_m(vbool64_t mask, uint16_t *base, ptrdiff_t bstride, vuint16mf4_t v0, vuint16mf4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf4_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv2i16.i64(<vscale x 2 x i16> [[V0:%.*]], <vscale x 2 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16mf2_m(vbool32_t mask, uint16_t *base, ptrdiff_t bstride, vuint16mf2_t v0, vuint16mf2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16mf2_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv4i16.i64(<vscale x 4 x i16> [[V0:%.*]], <vscale x 4 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m1_m(vbool16_t mask, uint16_t *base, ptrdiff_t bstride, vuint16m1_t v0, vuint16m1_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16m1_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16m2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv8i16.i64(<vscale x 8 x i16> [[V0:%.*]], <vscale x 8 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 8 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m2_m(vbool8_t mask, uint16_t *base, ptrdiff_t bstride, vuint16m2_t v0, vuint16m2_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16m2_m(mask, base, bstride, v0, v1, vl);
}

// CHECK-RV64-LABEL: @test_vssseg2e16_v_u16m4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    call void @llvm.riscv.vssseg2.mask.nxv16i16.i64(<vscale x 16 x i16> [[V0:%.*]], <vscale x 16 x i16> [[V1:%.*]], ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 16 x i1> [[MASK:%.*]], i64 [[VL:%.*]])
// CHECK-RV64-NEXT:    ret void
//
void test_vssseg2e16_v_u16m4_m(vbool4_t mask, uint16_t *base, ptrdiff_t bstride, vuint16m4_t v0, vuint16m4_t v1, size_t vl) {
  return __riscv_vssseg2e16_v_u16m4_m(mask, base, bstride, v0, v1, vl);
}

