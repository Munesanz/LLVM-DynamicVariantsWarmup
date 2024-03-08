// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +experimental-zvfh -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_f16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } @llvm.riscv.vlsseg8.mask.nxv1f16.i64(<vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, <vscale x 1 x half> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half>, <vscale x 1 x half> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 1 x half> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_f16mf4_m(vfloat16mf4_t *v0, vfloat16mf4_t *v1, vfloat16mf4_t *v2, vfloat16mf4_t *v3, vfloat16mf4_t *v4, vfloat16mf4_t *v5, vfloat16mf4_t *v6, vfloat16mf4_t *v7, vbool64_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_f16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } @llvm.riscv.vlsseg8.mask.nxv2f16.i64(<vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, <vscale x 2 x half> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half>, <vscale x 2 x half> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 2 x half> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_f16mf2_m(vfloat16mf2_t *v0, vfloat16mf2_t *v1, vfloat16mf2_t *v2, vfloat16mf2_t *v3, vfloat16mf2_t *v4, vfloat16mf2_t *v5, vfloat16mf2_t *v6, vfloat16mf2_t *v7, vbool32_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_f16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } @llvm.riscv.vlsseg8.mask.nxv4f16.i64(<vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, <vscale x 4 x half> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half>, <vscale x 4 x half> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 4 x half> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_f16m1_m(vfloat16m1_t *v0, vfloat16m1_t *v1, vfloat16m1_t *v2, vfloat16m1_t *v3, vfloat16m1_t *v4, vfloat16m1_t *v5, vfloat16m1_t *v6, vfloat16m1_t *v7, vbool16_t mask, const _Float16 *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_i16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlsseg8.mask.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_i16mf4_m(vint16mf4_t *v0, vint16mf4_t *v1, vint16mf4_t *v2, vint16mf4_t *v3, vint16mf4_t *v4, vint16mf4_t *v5, vint16mf4_t *v6, vint16mf4_t *v7, vbool64_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_i16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlsseg8.mask.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_i16mf2_m(vint16mf2_t *v0, vint16mf2_t *v1, vint16mf2_t *v2, vint16mf2_t *v3, vint16mf2_t *v4, vint16mf2_t *v5, vint16mf2_t *v6, vint16mf2_t *v7, vbool32_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_i16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlsseg8.mask.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_i16m1_m(vint16m1_t *v0, vint16m1_t *v1, vint16m1_t *v2, vint16m1_t *v3, vint16m1_t *v4, vint16m1_t *v5, vint16m1_t *v6, vint16m1_t *v7, vbool16_t mask, const int16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_u16mf4_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } @llvm.riscv.vlsseg8.mask.nxv1i16.i64(<vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, <vscale x 1 x i16> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 1 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i16> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 1 x i16> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_u16mf4_m(vuint16mf4_t *v0, vuint16mf4_t *v1, vuint16mf4_t *v2, vuint16mf4_t *v3, vuint16mf4_t *v4, vuint16mf4_t *v5, vuint16mf4_t *v6, vuint16mf4_t *v7, vbool64_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_u16mf2_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } @llvm.riscv.vlsseg8.mask.nxv2i16.i64(<vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, <vscale x 2 x i16> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 2 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i16> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 2 x i16> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_u16mf2_m(vuint16mf2_t *v0, vuint16mf2_t *v1, vuint16mf2_t *v2, vuint16mf2_t *v3, vuint16mf2_t *v4, vuint16mf2_t *v5, vuint16mf2_t *v6, vuint16mf2_t *v7, vbool32_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

// CHECK-RV64-LABEL: @test_vlsseg8e16_v_u16m1_m(
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } @llvm.riscv.vlsseg8.mask.nxv4i16.i64(<vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, <vscale x 4 x i16> poison, ptr [[BASE:%.*]], i64 [[BSTRIDE:%.*]], <vscale x 4 x i1> [[MASK:%.*]], i64 [[VL:%.*]], i64 3)
// CHECK-RV64-NEXT:    [[TMP1:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 0
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP1]], ptr [[V0:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP2:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 1
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP2]], ptr [[V1:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP3:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 2
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP3]], ptr [[V2:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP4:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 3
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP4]], ptr [[V3:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP5:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 4
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP5]], ptr [[V4:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP6:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 5
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP6]], ptr [[V5:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP7:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 6
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP7]], ptr [[V6:%.*]], align 2
// CHECK-RV64-NEXT:    [[TMP8:%.*]] = extractvalue { <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i16> } [[TMP0]], 7
// CHECK-RV64-NEXT:    store <vscale x 4 x i16> [[TMP8]], ptr [[V7:%.*]], align 2
// CHECK-RV64-NEXT:    ret void
//
void test_vlsseg8e16_v_u16m1_m(vuint16m1_t *v0, vuint16m1_t *v1, vuint16m1_t *v2, vuint16m1_t *v3, vuint16m1_t *v4, vuint16m1_t *v5, vuint16m1_t *v6, vuint16m1_t *v7, vbool16_t mask, const uint16_t *base, ptrdiff_t bstride, size_t vl) {
  return __riscv_vlsseg8e16(v0, v1, v2, v3, v4, v5, v6, v7, mask, base, bstride, vl);
}

