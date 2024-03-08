// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple armv8.1a-linux-gnu -target-abi apcs-gnu -target-feature +neon \
// RUN:  -S -emit-llvm -o - %s -disable-O0-optnone | opt -passes=mem2reg,dce -S \
// RUN:  | FileCheck %s --check-prefix=CHECK-ARM

// RUN: %clang_cc1 -triple aarch64-linux-gnu -target-feature +neon \
// RUN:  -target-feature +v8.1a -S -emit-llvm -o - %s -disable-O0-optnone | opt -passes=mem2reg,dce -S \
// RUN:  | FileCheck %s --check-prefix=CHECK-AARCH64

// REQUIRES: arm-registered-target,aarch64-registered-target

#include <arm_neon.h>

// CHECK-ARM-LABEL: @test_vqrdmlah_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrdmlah.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <4 x i16> [[VQRDMLAH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlah_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqrdmlah.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <4 x i16> [[VQRDMLAH_V3_I]]
//
int16x4_t test_vqrdmlah_s16(int16x4_t a, int16x4_t b, int16x4_t c) {

  return vqrdmlah_s16(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlah_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrdmlah.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <2 x i32> [[VQRDMLAH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlah_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <2 x i32> @llvm.aarch64.neon.sqrdmlah.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <2 x i32> [[VQRDMLAH_V3_I]]
//
int32x2_t test_vqrdmlah_s32(int32x2_t a, int32x2_t b, int32x2_t c) {

  return vqrdmlah_s32(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlahq_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrdmlah.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <8 x i16> [[VQRDMLAHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlahq_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <8 x i16> @llvm.aarch64.neon.sqrdmlah.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <8 x i16> [[VQRDMLAHQ_V3_I]]
//
int16x8_t test_vqrdmlahq_s16(int16x8_t a, int16x8_t b, int16x8_t c) {

  return vqrdmlahq_s16(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlahq_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrdmlah.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <4 x i32> [[VQRDMLAHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlahq_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqrdmlah.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <4 x i32> [[VQRDMLAHQ_V3_I]]
//
int32x4_t test_vqrdmlahq_s32(int32x4_t a, int32x4_t b, int32x4_t c) {

  return vqrdmlahq_s32(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlah_lane_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK-ARM-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrdmlah.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[LANE]])
// CHECK-ARM-NEXT:    ret <4 x i16> [[VQRDMLAH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlah_lane_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK-AARCH64-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqrdmlah.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <4 x i16> [[VQRDMLAH_V3_I]]
//
int16x4_t test_vqrdmlah_lane_s16(int16x4_t a, int16x4_t b, int16x4_t c) {

  return vqrdmlah_lane_s16(a, b, c, 3);
}

// CHECK-ARM-LABEL: @test_vqrdmlah_lane_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK-ARM-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrdmlah.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[LANE]])
// CHECK-ARM-NEXT:    ret <2 x i32> [[VQRDMLAH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlah_lane_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK-AARCH64-NEXT:    [[VQRDMLAH_V3_I:%.*]] = call <2 x i32> @llvm.aarch64.neon.sqrdmlah.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <2 x i32> [[VQRDMLAH_V3_I]]
//
int32x2_t test_vqrdmlah_lane_s32(int32x2_t a, int32x2_t b, int32x2_t c) {

  return vqrdmlah_lane_s32(a, b, c, 1);
}

// CHECK-ARM-LABEL: @test_vqrdmlahq_lane_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK-ARM-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrdmlah.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[LANE]])
// CHECK-ARM-NEXT:    ret <8 x i16> [[VQRDMLAHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlahq_lane_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK-AARCH64-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <8 x i16> @llvm.aarch64.neon.sqrdmlah.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <8 x i16> [[VQRDMLAHQ_V3_I]]
//
int16x8_t test_vqrdmlahq_lane_s16(int16x8_t a, int16x8_t b, int16x4_t c) {

  return vqrdmlahq_lane_s16(a, b, c, 3);
}

// CHECK-ARM-LABEL: @test_vqrdmlahq_lane_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK-ARM-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrdmlah.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[LANE]])
// CHECK-ARM-NEXT:    ret <4 x i32> [[VQRDMLAHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlahq_lane_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK-AARCH64-NEXT:    [[VQRDMLAHQ_V3_I:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqrdmlah.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <4 x i32> [[VQRDMLAHQ_V3_I]]
//
int32x4_t test_vqrdmlahq_lane_s32(int32x4_t a, int32x4_t b, int32x2_t c) {

  return vqrdmlahq_lane_s32(a, b, c, 1);
}

// CHECK-ARM-LABEL: @test_vqrdmlsh_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrdmlsh.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <4 x i16> [[VQRDMLSH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlsh_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqrdmlsh.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <4 x i16> [[VQRDMLSH_V3_I]]
//
int16x4_t test_vqrdmlsh_s16(int16x4_t a, int16x4_t b, int16x4_t c) {

  return vqrdmlsh_s16(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlsh_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrdmlsh.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <2 x i32> [[VQRDMLSH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlsh_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <2 x i32> @llvm.aarch64.neon.sqrdmlsh.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <2 x i32> [[VQRDMLSH_V3_I]]
//
int32x2_t test_vqrdmlsh_s32(int32x2_t a, int32x2_t b, int32x2_t c) {

  return vqrdmlsh_s32(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlshq_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrdmlsh.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <8 x i16> [[VQRDMLSHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlshq_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <8 x i16> @llvm.aarch64.neon.sqrdmlsh.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <8 x i16> [[VQRDMLSHQ_V3_I]]
//
int16x8_t test_vqrdmlshq_s16(int16x8_t a, int16x8_t b, int16x8_t c) {

  return vqrdmlshq_s16(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlshq_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrdmlsh.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[C:%.*]])
// CHECK-ARM-NEXT:    ret <4 x i32> [[VQRDMLSHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlshq_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqrdmlsh.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[C:%.*]])
// CHECK-AARCH64-NEXT:    ret <4 x i32> [[VQRDMLSHQ_V3_I]]
//
int32x4_t test_vqrdmlshq_s32(int32x4_t a, int32x4_t b, int32x4_t c) {

  return vqrdmlshq_s32(a, b, c);
}

// CHECK-ARM-LABEL: @test_vqrdmlsh_lane_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK-ARM-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrdmlsh.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[LANE]])
// CHECK-ARM-NEXT:    ret <4 x i16> [[VQRDMLSH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlsh_lane_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK-AARCH64-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <4 x i16> @llvm.aarch64.neon.sqrdmlsh.v4i16(<4 x i16> [[A:%.*]], <4 x i16> [[B:%.*]], <4 x i16> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <4 x i16> [[VQRDMLSH_V3_I]]
//
int16x4_t test_vqrdmlsh_lane_s16(int16x4_t a, int16x4_t b, int16x4_t c) {

  return vqrdmlsh_lane_s16(a, b, c, 3);
}

// CHECK-ARM-LABEL: @test_vqrdmlsh_lane_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK-ARM-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrdmlsh.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[LANE]])
// CHECK-ARM-NEXT:    ret <2 x i32> [[VQRDMLSH_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlsh_lane_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK-AARCH64-NEXT:    [[VQRDMLSH_V3_I:%.*]] = call <2 x i32> @llvm.aarch64.neon.sqrdmlsh.v2i32(<2 x i32> [[A:%.*]], <2 x i32> [[B:%.*]], <2 x i32> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <2 x i32> [[VQRDMLSH_V3_I]]
//
int32x2_t test_vqrdmlsh_lane_s32(int32x2_t a, int32x2_t b, int32x2_t c) {

  return vqrdmlsh_lane_s32(a, b, c, 1);
}

// CHECK-ARM-LABEL: @test_vqrdmlshq_lane_s16(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK-ARM-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrdmlsh.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[LANE]])
// CHECK-ARM-NEXT:    ret <8 x i16> [[VQRDMLSHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlshq_lane_s16(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK-AARCH64-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <8 x i16> @llvm.aarch64.neon.sqrdmlsh.v8i16(<8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i16> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <8 x i16> [[VQRDMLSHQ_V3_I]]
//
int16x8_t test_vqrdmlshq_lane_s16(int16x8_t a, int16x8_t b, int16x4_t c) {

  return vqrdmlshq_lane_s16(a, b, c, 3);
}

// CHECK-ARM-LABEL: @test_vqrdmlshq_lane_s32(
// CHECK-ARM-NEXT:  entry:
// CHECK-ARM-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-ARM-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-ARM-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK-ARM-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrdmlsh.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[LANE]])
// CHECK-ARM-NEXT:    ret <4 x i32> [[VQRDMLSHQ_V3_I]]
//
// CHECK-AARCH64-LABEL: @test_vqrdmlshq_lane_s32(
// CHECK-AARCH64-NEXT:  entry:
// CHECK-AARCH64-NEXT:    [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK-AARCH64-NEXT:    [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK-AARCH64-NEXT:    [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK-AARCH64-NEXT:    [[VQRDMLSHQ_V3_I:%.*]] = call <4 x i32> @llvm.aarch64.neon.sqrdmlsh.v4i32(<4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i32> [[LANE]])
// CHECK-AARCH64-NEXT:    ret <4 x i32> [[VQRDMLSHQ_V3_I]]
//
int32x4_t test_vqrdmlshq_lane_s32(int32x4_t a, int32x4_t b, int32x2_t c) {

  return vqrdmlshq_lane_s32(a, b, c, 1);
}
