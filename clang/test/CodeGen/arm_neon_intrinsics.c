// RUN: %clang_cc1 -triple thumbv7s-apple-darwin -target-abi apcs-gnu\
// RUN:  -target-cpu swift \
// RUN:  -target-feature +fullfp16 -ffreestanding \
// RUN:  -flax-vector-conversions=none \
// RUN:  -disable-O0-optnone -emit-llvm -o - %s \
// RUN:  | opt -S -passes=mem2reg | FileCheck %s

// REQUIRES: aarch64-registered-target || arm-registered-target

#include <arm_neon.h>

// CHECK-LABEL: @test_vaba_s8(
// CHECK:   [[VABD_V_I_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabds.v8i8(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[ADD_I:%.*]] = add <8 x i8> %a, [[VABD_V_I_I]]
// CHECK:   ret <8 x i8> [[ADD_I]]
int8x8_t test_vaba_s8(int8x8_t a, int8x8_t b, int8x8_t c) {
  return vaba_s8(a, b, c);
}

// CHECK-LABEL: @test_vaba_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabds.v4i16(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, [[VABD_V2_I_I]]
// CHECK:   ret <4 x i16> [[ADD_I]]
int16x4_t test_vaba_s16(int16x4_t a, int16x4_t b, int16x4_t c) {
  return vaba_s16(a, b, c);
}

// CHECK-LABEL: @test_vaba_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabds.v2i32(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, [[VABD_V2_I_I]]
// CHECK:   ret <2 x i32> [[ADD_I]]
int32x2_t test_vaba_s32(int32x2_t a, int32x2_t b, int32x2_t c) {
  return vaba_s32(a, b, c);
}

// CHECK-LABEL: @test_vaba_u8(
// CHECK:   [[VABD_V_I_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabdu.v8i8(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[ADD_I:%.*]] = add <8 x i8> %a, [[VABD_V_I_I]]
// CHECK:   ret <8 x i8> [[ADD_I]]
uint8x8_t test_vaba_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c) {
  return vaba_u8(a, b, c);
}

// CHECK-LABEL: @test_vaba_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabdu.v4i16(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, [[VABD_V2_I_I]]
// CHECK:   ret <4 x i16> [[ADD_I]]
uint16x4_t test_vaba_u16(uint16x4_t a, uint16x4_t b, uint16x4_t c) {
  return vaba_u16(a, b, c);
}

// CHECK-LABEL: @test_vaba_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabdu.v2i32(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, [[VABD_V2_I_I]]
// CHECK:   ret <2 x i32> [[ADD_I]]
uint32x2_t test_vaba_u32(uint32x2_t a, uint32x2_t b, uint32x2_t c) {
  return vaba_u32(a, b, c);
}

// CHECK-LABEL: @test_vabaq_s8(
// CHECK:   [[VABDQ_V_I_I:%.*]] = call <16 x i8> @llvm.arm.neon.vabds.v16i8(<16 x i8> %b, <16 x i8> %c)
// CHECK:   [[ADD_I:%.*]] = add <16 x i8> %a, [[VABDQ_V_I_I]]
// CHECK:   ret <16 x i8> [[ADD_I]]
int8x16_t test_vabaq_s8(int8x16_t a, int8x16_t b, int8x16_t c) {
  return vabaq_s8(a, b, c);
}

// CHECK-LABEL: @test_vabaq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %c to <16 x i8>
// CHECK:   [[VABDQ_V2_I_I:%.*]] = call <8 x i16> @llvm.arm.neon.vabds.v8i16(<8 x i16> %b, <8 x i16> %c)
// CHECK:   [[VABDQ_V3_I_I:%.*]] = bitcast <8 x i16> [[VABDQ_V2_I_I]] to <16 x i8>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VABDQ_V2_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vabaq_s16(int16x8_t a, int16x8_t b, int16x8_t c) {
  return vabaq_s16(a, b, c);
}

// CHECK-LABEL: @test_vabaq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %c to <16 x i8>
// CHECK:   [[VABDQ_V2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vabds.v4i32(<4 x i32> %b, <4 x i32> %c)
// CHECK:   [[VABDQ_V3_I_I:%.*]] = bitcast <4 x i32> [[VABDQ_V2_I_I]] to <16 x i8>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VABDQ_V2_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vabaq_s32(int32x4_t a, int32x4_t b, int32x4_t c) {
  return vabaq_s32(a, b, c);
}

// CHECK-LABEL: @test_vabaq_u8(
// CHECK:   [[VABDQ_V_I_I:%.*]] = call <16 x i8> @llvm.arm.neon.vabdu.v16i8(<16 x i8> %b, <16 x i8> %c)
// CHECK:   [[ADD_I:%.*]] = add <16 x i8> %a, [[VABDQ_V_I_I]]
// CHECK:   ret <16 x i8> [[ADD_I]]
uint8x16_t test_vabaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c) {
  return vabaq_u8(a, b, c);
}

// CHECK-LABEL: @test_vabaq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %c to <16 x i8>
// CHECK:   [[VABDQ_V2_I_I:%.*]] = call <8 x i16> @llvm.arm.neon.vabdu.v8i16(<8 x i16> %b, <8 x i16> %c)
// CHECK:   [[VABDQ_V3_I_I:%.*]] = bitcast <8 x i16> [[VABDQ_V2_I_I]] to <16 x i8>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VABDQ_V2_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vabaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c) {
  return vabaq_u16(a, b, c);
}

// CHECK-LABEL: @test_vabaq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %c to <16 x i8>
// CHECK:   [[VABDQ_V2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vabdu.v4i32(<4 x i32> %b, <4 x i32> %c)
// CHECK:   [[VABDQ_V3_I_I:%.*]] = bitcast <4 x i32> [[VABDQ_V2_I_I]] to <16 x i8>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VABDQ_V2_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vabaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  return vabaq_u32(a, b, c);
}

// CHECK-LABEL: @test_vabal_s8(
// CHECK:   [[VABD_V_I_I_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabds.v8i8(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[VMOVL_I_I_I:%.*]] = zext <8 x i8> [[VABD_V_I_I_I]] to <8 x i16>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VMOVL_I_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vabal_s8(int16x8_t a, int8x8_t b, int8x8_t c) {
  return vabal_s8(a, b, c);
}

// CHECK-LABEL: @test_vabal_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabds.v4i16(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[VABD_V3_I_I_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I_I:%.*]] = zext <4 x i16> [[VABD_V2_I_I_I]] to <4 x i32>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMOVL_I_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vabal_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vabal_s16(a, b, c);
}

// CHECK-LABEL: @test_vabal_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabds.v2i32(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[VABD_V3_I_I_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I_I:%.*]] = zext <2 x i32> [[VABD_V2_I_I_I]] to <2 x i64>
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMOVL_I_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
int64x2_t test_vabal_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vabal_s32(a, b, c);
}

// CHECK-LABEL: @test_vabal_u8(
// CHECK:   [[VABD_V_I_I_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabdu.v8i8(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[VMOVL_I_I_I:%.*]] = zext <8 x i8> [[VABD_V_I_I_I]] to <8 x i16>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VMOVL_I_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vabal_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c) {
  return vabal_u8(a, b, c);
}

// CHECK-LABEL: @test_vabal_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabdu.v4i16(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[VABD_V3_I_I_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I_I:%.*]] = zext <4 x i16> [[VABD_V2_I_I_I]] to <4 x i32>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMOVL_I_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vabal_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  return vabal_u16(a, b, c);
}

// CHECK-LABEL: @test_vabal_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VABD_V2_I_I_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabdu.v2i32(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[VABD_V3_I_I_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I_I:%.*]] = zext <2 x i32> [[VABD_V2_I_I_I]] to <2 x i64>
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMOVL_I_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
uint64x2_t test_vabal_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  return vabal_u32(a, b, c);
}

// CHECK-LABEL: @test_vabd_s8(
// CHECK:   [[VABD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabds.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VABD_V_I]]
int8x8_t test_vabd_s8(int8x8_t a, int8x8_t b) {
  return vabd_s8(a, b);
}

// CHECK-LABEL: @test_vabd_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VABD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabds.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VABD_V3_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VABD_V2_I]]
int16x4_t test_vabd_s16(int16x4_t a, int16x4_t b) {
  return vabd_s16(a, b);
}

// CHECK-LABEL: @test_vabd_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VABD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabds.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VABD_V3_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VABD_V2_I]]
int32x2_t test_vabd_s32(int32x2_t a, int32x2_t b) {
  return vabd_s32(a, b);
}

// CHECK-LABEL: @test_vabd_u8(
// CHECK:   [[VABD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabdu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VABD_V_I]]
uint8x8_t test_vabd_u8(uint8x8_t a, uint8x8_t b) {
  return vabd_u8(a, b);
}

// CHECK-LABEL: @test_vabd_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VABD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabdu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VABD_V3_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VABD_V2_I]]
uint16x4_t test_vabd_u16(uint16x4_t a, uint16x4_t b) {
  return vabd_u16(a, b);
}

// CHECK-LABEL: @test_vabd_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VABD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabdu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VABD_V3_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VABD_V2_I]]
uint32x2_t test_vabd_u32(uint32x2_t a, uint32x2_t b) {
  return vabd_u32(a, b);
}

// CHECK-LABEL: @test_vabd_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VABD_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vabds.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VABD_V3_I:%.*]] = bitcast <2 x float> [[VABD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VABD_V2_I]]
float32x2_t test_vabd_f32(float32x2_t a, float32x2_t b) {
  return vabd_f32(a, b);
}

// CHECK-LABEL: @test_vabdq_s8(
// CHECK:   [[VABDQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vabds.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VABDQ_V_I]]
int8x16_t test_vabdq_s8(int8x16_t a, int8x16_t b) {
  return vabdq_s8(a, b);
}

// CHECK-LABEL: @test_vabdq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VABDQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vabds.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VABDQ_V3_I:%.*]] = bitcast <8 x i16> [[VABDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VABDQ_V2_I]]
int16x8_t test_vabdq_s16(int16x8_t a, int16x8_t b) {
  return vabdq_s16(a, b);
}

// CHECK-LABEL: @test_vabdq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VABDQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vabds.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VABDQ_V3_I:%.*]] = bitcast <4 x i32> [[VABDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VABDQ_V2_I]]
int32x4_t test_vabdq_s32(int32x4_t a, int32x4_t b) {
  return vabdq_s32(a, b);
}

// CHECK-LABEL: @test_vabdq_u8(
// CHECK:   [[VABDQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vabdu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VABDQ_V_I]]
uint8x16_t test_vabdq_u8(uint8x16_t a, uint8x16_t b) {
  return vabdq_u8(a, b);
}

// CHECK-LABEL: @test_vabdq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VABDQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vabdu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VABDQ_V3_I:%.*]] = bitcast <8 x i16> [[VABDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VABDQ_V2_I]]
uint16x8_t test_vabdq_u16(uint16x8_t a, uint16x8_t b) {
  return vabdq_u16(a, b);
}

// CHECK-LABEL: @test_vabdq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VABDQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vabdu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VABDQ_V3_I:%.*]] = bitcast <4 x i32> [[VABDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VABDQ_V2_I]]
uint32x4_t test_vabdq_u32(uint32x4_t a, uint32x4_t b) {
  return vabdq_u32(a, b);
}

// CHECK-LABEL: @test_vabdq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VABDQ_V2_I:%.*]] = call <4 x float> @llvm.arm.neon.vabds.v4f32(<4 x float> %a, <4 x float> %b)
// CHECK:   [[VABDQ_V3_I:%.*]] = bitcast <4 x float> [[VABDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x float> [[VABDQ_V2_I]]
float32x4_t test_vabdq_f32(float32x4_t a, float32x4_t b) {
  return vabdq_f32(a, b);
}

// CHECK-LABEL: @test_vabdl_s8(
// CHECK:   [[VABD_V_I_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabds.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   [[VMOVL_I_I:%.*]] = zext <8 x i8> [[VABD_V_I_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[VMOVL_I_I]]
int16x8_t test_vabdl_s8(int8x8_t a, int8x8_t b) {
  return vabdl_s8(a, b);
}

// CHECK-LABEL: @test_vabdl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabds.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <4 x i16> [[VABD_V2_I_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[VMOVL_I_I]]
int32x4_t test_vabdl_s16(int16x4_t a, int16x4_t b) {
  return vabdl_s16(a, b);
}

// CHECK-LABEL: @test_vabdl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabds.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <2 x i32> [[VABD_V2_I_I]] to <2 x i64>
// CHECK:   ret <2 x i64> [[VMOVL_I_I]]
int64x2_t test_vabdl_s32(int32x2_t a, int32x2_t b) {
  return vabdl_s32(a, b);
}

// CHECK-LABEL: @test_vabdl_u8(
// CHECK:   [[VABD_V_I_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabdu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   [[VMOVL_I_I:%.*]] = zext <8 x i8> [[VABD_V_I_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[VMOVL_I_I]]
uint16x8_t test_vabdl_u8(uint8x8_t a, uint8x8_t b) {
  return vabdl_u8(a, b);
}

// CHECK-LABEL: @test_vabdl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabdu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <4 x i16> [[VABD_V2_I_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[VMOVL_I_I]]
uint32x4_t test_vabdl_u16(uint16x4_t a, uint16x4_t b) {
  return vabdl_u16(a, b);
}

// CHECK-LABEL: @test_vabdl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VABD_V2_I_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabdu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VABD_V3_I_I:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[VABD_V2_I_I]] to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <2 x i32> [[VABD_V2_I_I]] to <2 x i64>
// CHECK:   ret <2 x i64> [[VMOVL_I_I]]
uint64x2_t test_vabdl_u32(uint32x2_t a, uint32x2_t b) {
  return vabdl_u32(a, b);
}

// CHECK-LABEL: @test_vabs_s8(
// CHECK:   [[VABS_I:%.*]] = call <8 x i8> @llvm.arm.neon.vabs.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VABS_I]]
int8x8_t test_vabs_s8(int8x8_t a) {
  return vabs_s8(a);
}

// CHECK-LABEL: @test_vabs_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VABS1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vabs.v4i16(<4 x i16> %a)
// CHECK:   ret <4 x i16> [[VABS1_I]]
int16x4_t test_vabs_s16(int16x4_t a) {
  return vabs_s16(a);
}

// CHECK-LABEL: @test_vabs_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VABS1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vabs.v2i32(<2 x i32> %a)
// CHECK:   ret <2 x i32> [[VABS1_I]]
int32x2_t test_vabs_s32(int32x2_t a) {
  return vabs_s32(a);
}

// CHECK-LABEL: @test_vabs_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[VABS1_I:%.*]] = call <2 x float> @llvm.fabs.v2f32(<2 x float> %a)
// CHECK:   ret <2 x float> [[VABS1_I]]
float32x2_t test_vabs_f32(float32x2_t a) {
  return vabs_f32(a);
}

// CHECK-LABEL: @test_vabsq_s8(
// CHECK:   [[VABS_I:%.*]] = call <16 x i8> @llvm.arm.neon.vabs.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VABS_I]]
int8x16_t test_vabsq_s8(int8x16_t a) {
  return vabsq_s8(a);
}

// CHECK-LABEL: @test_vabsq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VABS1_I:%.*]] = call <8 x i16> @llvm.arm.neon.vabs.v8i16(<8 x i16> %a)
// CHECK:   ret <8 x i16> [[VABS1_I]]
int16x8_t test_vabsq_s16(int16x8_t a) {
  return vabsq_s16(a);
}

// CHECK-LABEL: @test_vabsq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VABS1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vabs.v4i32(<4 x i32> %a)
// CHECK:   ret <4 x i32> [[VABS1_I]]
int32x4_t test_vabsq_s32(int32x4_t a) {
  return vabsq_s32(a);
}

// CHECK-LABEL: @test_vabsq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VABS1_I:%.*]] = call <4 x float> @llvm.fabs.v4f32(<4 x float> %a)
// CHECK:   ret <4 x float> [[VABS1_I]]
float32x4_t test_vabsq_f32(float32x4_t a) {
  return vabsq_f32(a);
}

// CHECK-LABEL: @test_vadd_s8(
// CHECK:   [[ADD_I:%.*]] = add <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[ADD_I]]
int8x8_t test_vadd_s8(int8x8_t a, int8x8_t b) {
  return vadd_s8(a, b);
}

// CHECK-LABEL: @test_vadd_s16(
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[ADD_I]]
int16x4_t test_vadd_s16(int16x4_t a, int16x4_t b) {
  return vadd_s16(a, b);
}

// CHECK-LABEL: @test_vadd_s32(
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[ADD_I]]
int32x2_t test_vadd_s32(int32x2_t a, int32x2_t b) {
  return vadd_s32(a, b);
}

// CHECK-LABEL: @test_vadd_s64(
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[ADD_I]]
int64x1_t test_vadd_s64(int64x1_t a, int64x1_t b) {
  return vadd_s64(a, b);
}

// CHECK-LABEL: @test_vadd_f32(
// CHECK:   [[ADD_I:%.*]] = fadd <2 x float> %a, %b
// CHECK:   ret <2 x float> [[ADD_I]]
float32x2_t test_vadd_f32(float32x2_t a, float32x2_t b) {
  return vadd_f32(a, b);
}

// CHECK-LABEL: @test_vadd_u8(
// CHECK:   [[ADD_I:%.*]] = add <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[ADD_I]]
uint8x8_t test_vadd_u8(uint8x8_t a, uint8x8_t b) {
  return vadd_u8(a, b);
}

// CHECK-LABEL: @test_vadd_u16(
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[ADD_I]]
uint16x4_t test_vadd_u16(uint16x4_t a, uint16x4_t b) {
  return vadd_u16(a, b);
}

// CHECK-LABEL: @test_vadd_u32(
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[ADD_I]]
uint32x2_t test_vadd_u32(uint32x2_t a, uint32x2_t b) {
  return vadd_u32(a, b);
}

// CHECK-LABEL: @test_vadd_u64(
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[ADD_I]]
uint64x1_t test_vadd_u64(uint64x1_t a, uint64x1_t b) {
  return vadd_u64(a, b);
}

// CHECK-LABEL: @test_vaddq_s8(
// CHECK:   [[ADD_I:%.*]] = add <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[ADD_I]]
int8x16_t test_vaddq_s8(int8x16_t a, int8x16_t b) {
  return vaddq_s8(a, b);
}

// CHECK-LABEL: @test_vaddq_s16(
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vaddq_s16(int16x8_t a, int16x8_t b) {
  return vaddq_s16(a, b);
}

// CHECK-LABEL: @test_vaddq_s32(
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vaddq_s32(int32x4_t a, int32x4_t b) {
  return vaddq_s32(a, b);
}

// CHECK-LABEL: @test_vaddq_s64(
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[ADD_I]]
int64x2_t test_vaddq_s64(int64x2_t a, int64x2_t b) {
  return vaddq_s64(a, b);
}

// CHECK-LABEL: @test_vaddq_f32(
// CHECK:   [[ADD_I:%.*]] = fadd <4 x float> %a, %b
// CHECK:   ret <4 x float> [[ADD_I]]
float32x4_t test_vaddq_f32(float32x4_t a, float32x4_t b) {
  return vaddq_f32(a, b);
}

// CHECK-LABEL: @test_vaddq_u8(
// CHECK:   [[ADD_I:%.*]] = add <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[ADD_I]]
uint8x16_t test_vaddq_u8(uint8x16_t a, uint8x16_t b) {
  return vaddq_u8(a, b);
}

// CHECK-LABEL: @test_vaddq_u16(
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vaddq_u16(uint16x8_t a, uint16x8_t b) {
  return vaddq_u16(a, b);
}

// CHECK-LABEL: @test_vaddq_u32(
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vaddq_u32(uint32x4_t a, uint32x4_t b) {
  return vaddq_u32(a, b);
}

// CHECK-LABEL: @test_vaddq_u64(
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[ADD_I]]
uint64x2_t test_vaddq_u64(uint64x2_t a, uint64x2_t b) {
  return vaddq_u64(a, b);
}

// CHECK-LABEL: @test_vaddhn_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VADDHN_I:%.*]] = add <8 x i16> %a, %b
// CHECK:   [[VADDHN1_I:%.*]] = lshr <8 x i16> [[VADDHN_I]], <i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
// CHECK:   [[VADDHN2_I:%.*]] = trunc <8 x i16> [[VADDHN1_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VADDHN2_I]]
int8x8_t test_vaddhn_s16(int16x8_t a, int16x8_t b) {
  return vaddhn_s16(a, b);
}

// CHECK-LABEL: @test_vaddhn_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VADDHN_I:%.*]] = add <4 x i32> %a, %b
// CHECK:   [[VADDHN1_I:%.*]] = lshr <4 x i32> [[VADDHN_I]], <i32 16, i32 16, i32 16, i32 16>
// CHECK:   [[VADDHN2_I:%.*]] = trunc <4 x i32> [[VADDHN1_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VADDHN2_I]]
int16x4_t test_vaddhn_s32(int32x4_t a, int32x4_t b) {
  return vaddhn_s32(a, b);
}

// CHECK-LABEL: @test_vaddhn_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VADDHN_I:%.*]] = add <2 x i64> %a, %b
// CHECK:   [[VADDHN1_I:%.*]] = lshr <2 x i64> [[VADDHN_I]], <i64 32, i64 32>
// CHECK:   [[VADDHN2_I:%.*]] = trunc <2 x i64> [[VADDHN1_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VADDHN2_I]]
int32x2_t test_vaddhn_s64(int64x2_t a, int64x2_t b) {
  return vaddhn_s64(a, b);
}

// CHECK-LABEL: @test_vaddhn_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VADDHN_I:%.*]] = add <8 x i16> %a, %b
// CHECK:   [[VADDHN1_I:%.*]] = lshr <8 x i16> [[VADDHN_I]], <i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
// CHECK:   [[VADDHN2_I:%.*]] = trunc <8 x i16> [[VADDHN1_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VADDHN2_I]]
uint8x8_t test_vaddhn_u16(uint16x8_t a, uint16x8_t b) {
  return vaddhn_u16(a, b);
}

// CHECK-LABEL: @test_vaddhn_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VADDHN_I:%.*]] = add <4 x i32> %a, %b
// CHECK:   [[VADDHN1_I:%.*]] = lshr <4 x i32> [[VADDHN_I]], <i32 16, i32 16, i32 16, i32 16>
// CHECK:   [[VADDHN2_I:%.*]] = trunc <4 x i32> [[VADDHN1_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VADDHN2_I]]
uint16x4_t test_vaddhn_u32(uint32x4_t a, uint32x4_t b) {
  return vaddhn_u32(a, b);
}

// CHECK-LABEL: @test_vaddhn_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VADDHN_I:%.*]] = add <2 x i64> %a, %b
// CHECK:   [[VADDHN1_I:%.*]] = lshr <2 x i64> [[VADDHN_I]], <i64 32, i64 32>
// CHECK:   [[VADDHN2_I:%.*]] = trunc <2 x i64> [[VADDHN1_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VADDHN2_I]]
uint32x2_t test_vaddhn_u64(uint64x2_t a, uint64x2_t b) {
  return vaddhn_u64(a, b);
}

// CHECK-LABEL: @test_vaddl_s8(
// CHECK:   [[VMOVL_I_I:%.*]] = sext <8 x i8> %a to <8 x i16>
// CHECK:   [[VMOVL_I4_I:%.*]] = sext <8 x i8> %b to <8 x i16>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vaddl_s8(int8x8_t a, int8x8_t b) {
  return vaddl_s8(a, b);
}

// CHECK-LABEL: @test_vaddl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <4 x i16> %a to <4 x i32>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = sext <4 x i16> %b to <4 x i32>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vaddl_s16(int16x4_t a, int16x4_t b) {
  return vaddl_s16(a, b);
}

// CHECK-LABEL: @test_vaddl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <2 x i32> %a to <2 x i64>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = sext <2 x i32> %b to <2 x i64>
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
int64x2_t test_vaddl_s32(int32x2_t a, int32x2_t b) {
  return vaddl_s32(a, b);
}

// CHECK-LABEL: @test_vaddl_u8(
// CHECK:   [[VMOVL_I_I:%.*]] = zext <8 x i8> %a to <8 x i16>
// CHECK:   [[VMOVL_I4_I:%.*]] = zext <8 x i8> %b to <8 x i16>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vaddl_u8(uint8x8_t a, uint8x8_t b) {
  return vaddl_u8(a, b);
}

// CHECK-LABEL: @test_vaddl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <4 x i16> %a to <4 x i32>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = zext <4 x i16> %b to <4 x i32>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vaddl_u16(uint16x4_t a, uint16x4_t b) {
  return vaddl_u16(a, b);
}

// CHECK-LABEL: @test_vaddl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <2 x i32> %a to <2 x i64>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = zext <2 x i32> %b to <2 x i64>
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
uint64x2_t test_vaddl_u32(uint32x2_t a, uint32x2_t b) {
  return vaddl_u32(a, b);
}

// CHECK-LABEL: @test_vaddw_s8(
// CHECK:   [[VMOVL_I_I:%.*]] = sext <8 x i8> %b to <8 x i16>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VMOVL_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vaddw_s8(int16x8_t a, int8x8_t b) {
  return vaddw_s8(a, b);
}

// CHECK-LABEL: @test_vaddw_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <4 x i16> %b to <4 x i32>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMOVL_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vaddw_s16(int32x4_t a, int16x4_t b) {
  return vaddw_s16(a, b);
}

// CHECK-LABEL: @test_vaddw_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <2 x i32> %b to <2 x i64>
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMOVL_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
int64x2_t test_vaddw_s32(int64x2_t a, int32x2_t b) {
  return vaddw_s32(a, b);
}

// CHECK-LABEL: @test_vaddw_u8(
// CHECK:   [[VMOVL_I_I:%.*]] = zext <8 x i8> %b to <8 x i16>
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VMOVL_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vaddw_u8(uint16x8_t a, uint8x8_t b) {
  return vaddw_u8(a, b);
}

// CHECK-LABEL: @test_vaddw_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <4 x i16> %b to <4 x i32>
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMOVL_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vaddw_u16(uint32x4_t a, uint16x4_t b) {
  return vaddw_u16(a, b);
}

// CHECK-LABEL: @test_vaddw_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <2 x i32> %b to <2 x i64>
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMOVL_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
uint64x2_t test_vaddw_u32(uint64x2_t a, uint32x2_t b) {
  return vaddw_u32(a, b);
}

// CHECK-LABEL: @test_vand_s8(
// CHECK:   [[AND_I:%.*]] = and <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[AND_I]]
int8x8_t test_vand_s8(int8x8_t a, int8x8_t b) {
  return vand_s8(a, b);
}

// CHECK-LABEL: @test_vand_s16(
// CHECK:   [[AND_I:%.*]] = and <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[AND_I]]
int16x4_t test_vand_s16(int16x4_t a, int16x4_t b) {
  return vand_s16(a, b);
}

// CHECK-LABEL: @test_vand_s32(
// CHECK:   [[AND_I:%.*]] = and <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[AND_I]]
int32x2_t test_vand_s32(int32x2_t a, int32x2_t b) {
  return vand_s32(a, b);
}

// CHECK-LABEL: @test_vand_s64(
// CHECK:   [[AND_I:%.*]] = and <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[AND_I]]
int64x1_t test_vand_s64(int64x1_t a, int64x1_t b) {
  return vand_s64(a, b);
}

// CHECK-LABEL: @test_vand_u8(
// CHECK:   [[AND_I:%.*]] = and <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[AND_I]]
uint8x8_t test_vand_u8(uint8x8_t a, uint8x8_t b) {
  return vand_u8(a, b);
}

// CHECK-LABEL: @test_vand_u16(
// CHECK:   [[AND_I:%.*]] = and <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[AND_I]]
uint16x4_t test_vand_u16(uint16x4_t a, uint16x4_t b) {
  return vand_u16(a, b);
}

// CHECK-LABEL: @test_vand_u32(
// CHECK:   [[AND_I:%.*]] = and <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[AND_I]]
uint32x2_t test_vand_u32(uint32x2_t a, uint32x2_t b) {
  return vand_u32(a, b);
}

// CHECK-LABEL: @test_vand_u64(
// CHECK:   [[AND_I:%.*]] = and <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[AND_I]]
uint64x1_t test_vand_u64(uint64x1_t a, uint64x1_t b) {
  return vand_u64(a, b);
}

// CHECK-LABEL: @test_vandq_s8(
// CHECK:   [[AND_I:%.*]] = and <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[AND_I]]
int8x16_t test_vandq_s8(int8x16_t a, int8x16_t b) {
  return vandq_s8(a, b);
}

// CHECK-LABEL: @test_vandq_s16(
// CHECK:   [[AND_I:%.*]] = and <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[AND_I]]
int16x8_t test_vandq_s16(int16x8_t a, int16x8_t b) {
  return vandq_s16(a, b);
}

// CHECK-LABEL: @test_vandq_s32(
// CHECK:   [[AND_I:%.*]] = and <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[AND_I]]
int32x4_t test_vandq_s32(int32x4_t a, int32x4_t b) {
  return vandq_s32(a, b);
}

// CHECK-LABEL: @test_vandq_s64(
// CHECK:   [[AND_I:%.*]] = and <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[AND_I]]
int64x2_t test_vandq_s64(int64x2_t a, int64x2_t b) {
  return vandq_s64(a, b);
}

// CHECK-LABEL: @test_vandq_u8(
// CHECK:   [[AND_I:%.*]] = and <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[AND_I]]
uint8x16_t test_vandq_u8(uint8x16_t a, uint8x16_t b) {
  return vandq_u8(a, b);
}

// CHECK-LABEL: @test_vandq_u16(
// CHECK:   [[AND_I:%.*]] = and <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[AND_I]]
uint16x8_t test_vandq_u16(uint16x8_t a, uint16x8_t b) {
  return vandq_u16(a, b);
}

// CHECK-LABEL: @test_vandq_u32(
// CHECK:   [[AND_I:%.*]] = and <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[AND_I]]
uint32x4_t test_vandq_u32(uint32x4_t a, uint32x4_t b) {
  return vandq_u32(a, b);
}

// CHECK-LABEL: @test_vandq_u64(
// CHECK:   [[AND_I:%.*]] = and <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[AND_I]]
uint64x2_t test_vandq_u64(uint64x2_t a, uint64x2_t b) {
  return vandq_u64(a, b);
}

// CHECK-LABEL: @test_vbic_s8(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[AND_I:%.*]] = and <8 x i8> %a, [[NEG_I]]
// CHECK:   ret <8 x i8> [[AND_I]]
int8x8_t test_vbic_s8(int8x8_t a, int8x8_t b) {
  return vbic_s8(a, b);
}

// CHECK-LABEL: @test_vbic_s16(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[AND_I:%.*]] = and <4 x i16> %a, [[NEG_I]]
// CHECK:   ret <4 x i16> [[AND_I]]
int16x4_t test_vbic_s16(int16x4_t a, int16x4_t b) {
  return vbic_s16(a, b);
}

// CHECK-LABEL: @test_vbic_s32(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i32> %b, <i32 -1, i32 -1>
// CHECK:   [[AND_I:%.*]] = and <2 x i32> %a, [[NEG_I]]
// CHECK:   ret <2 x i32> [[AND_I]]
int32x2_t test_vbic_s32(int32x2_t a, int32x2_t b) {
  return vbic_s32(a, b);
}

// CHECK-LABEL: @test_vbic_s64(
// CHECK:   [[NEG_I:%.*]] = xor <1 x i64> %b, <i64 -1>
// CHECK:   [[AND_I:%.*]] = and <1 x i64> %a, [[NEG_I]]
// CHECK:   ret <1 x i64> [[AND_I]]
int64x1_t test_vbic_s64(int64x1_t a, int64x1_t b) {
  return vbic_s64(a, b);
}

// CHECK-LABEL: @test_vbic_u8(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[AND_I:%.*]] = and <8 x i8> %a, [[NEG_I]]
// CHECK:   ret <8 x i8> [[AND_I]]
uint8x8_t test_vbic_u8(uint8x8_t a, uint8x8_t b) {
  return vbic_u8(a, b);
}

// CHECK-LABEL: @test_vbic_u16(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[AND_I:%.*]] = and <4 x i16> %a, [[NEG_I]]
// CHECK:   ret <4 x i16> [[AND_I]]
uint16x4_t test_vbic_u16(uint16x4_t a, uint16x4_t b) {
  return vbic_u16(a, b);
}

// CHECK-LABEL: @test_vbic_u32(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i32> %b, <i32 -1, i32 -1>
// CHECK:   [[AND_I:%.*]] = and <2 x i32> %a, [[NEG_I]]
// CHECK:   ret <2 x i32> [[AND_I]]
uint32x2_t test_vbic_u32(uint32x2_t a, uint32x2_t b) {
  return vbic_u32(a, b);
}

// CHECK-LABEL: @test_vbic_u64(
// CHECK:   [[NEG_I:%.*]] = xor <1 x i64> %b, <i64 -1>
// CHECK:   [[AND_I:%.*]] = and <1 x i64> %a, [[NEG_I]]
// CHECK:   ret <1 x i64> [[AND_I]]
uint64x1_t test_vbic_u64(uint64x1_t a, uint64x1_t b) {
  return vbic_u64(a, b);
}

// CHECK-LABEL: @test_vbicq_s8(
// CHECK:   [[NEG_I:%.*]] = xor <16 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[AND_I:%.*]] = and <16 x i8> %a, [[NEG_I]]
// CHECK:   ret <16 x i8> [[AND_I]]
int8x16_t test_vbicq_s8(int8x16_t a, int8x16_t b) {
  return vbicq_s8(a, b);
}

// CHECK-LABEL: @test_vbicq_s16(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[AND_I:%.*]] = and <8 x i16> %a, [[NEG_I]]
// CHECK:   ret <8 x i16> [[AND_I]]
int16x8_t test_vbicq_s16(int16x8_t a, int16x8_t b) {
  return vbicq_s16(a, b);
}

// CHECK-LABEL: @test_vbicq_s32(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i32> %b, <i32 -1, i32 -1, i32 -1, i32 -1>
// CHECK:   [[AND_I:%.*]] = and <4 x i32> %a, [[NEG_I]]
// CHECK:   ret <4 x i32> [[AND_I]]
int32x4_t test_vbicq_s32(int32x4_t a, int32x4_t b) {
  return vbicq_s32(a, b);
}

// CHECK-LABEL: @test_vbicq_s64(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i64> %b, <i64 -1, i64 -1>
// CHECK:   [[AND_I:%.*]] = and <2 x i64> %a, [[NEG_I]]
// CHECK:   ret <2 x i64> [[AND_I]]
int64x2_t test_vbicq_s64(int64x2_t a, int64x2_t b) {
  return vbicq_s64(a, b);
}

// CHECK-LABEL: @test_vbicq_u8(
// CHECK:   [[NEG_I:%.*]] = xor <16 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[AND_I:%.*]] = and <16 x i8> %a, [[NEG_I]]
// CHECK:   ret <16 x i8> [[AND_I]]
uint8x16_t test_vbicq_u8(uint8x16_t a, uint8x16_t b) {
  return vbicq_u8(a, b);
}

// CHECK-LABEL: @test_vbicq_u16(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[AND_I:%.*]] = and <8 x i16> %a, [[NEG_I]]
// CHECK:   ret <8 x i16> [[AND_I]]
uint16x8_t test_vbicq_u16(uint16x8_t a, uint16x8_t b) {
  return vbicq_u16(a, b);
}

// CHECK-LABEL: @test_vbicq_u32(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i32> %b, <i32 -1, i32 -1, i32 -1, i32 -1>
// CHECK:   [[AND_I:%.*]] = and <4 x i32> %a, [[NEG_I]]
// CHECK:   ret <4 x i32> [[AND_I]]
uint32x4_t test_vbicq_u32(uint32x4_t a, uint32x4_t b) {
  return vbicq_u32(a, b);
}

// CHECK-LABEL: @test_vbicq_u64(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i64> %b, <i64 -1, i64 -1>
// CHECK:   [[AND_I:%.*]] = and <2 x i64> %a, [[NEG_I]]
// CHECK:   ret <2 x i64> [[AND_I]]
uint64x2_t test_vbicq_u64(uint64x2_t a, uint64x2_t b) {
  return vbicq_u64(a, b);
}

// CHECK-LABEL: @test_vbsl_s8(
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VBSL_V_I]]
int8x8_t test_vbsl_s8(uint8x8_t a, int8x8_t b, int8x8_t c) {
  return vbsl_s8(a, b, c);
}

// CHECK-LABEL: @test_vbsl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP3]]
int16x4_t test_vbsl_s16(uint16x4_t a, int16x4_t b, int16x4_t c) {
  return vbsl_s16(a, b, c);
}

// CHECK-LABEL: @test_vbsl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP3]]
int32x2_t test_vbsl_s32(uint32x2_t a, int32x2_t b, int32x2_t c) {
  return vbsl_s32(a, b, c);
}

// CHECK-LABEL: @test_vbsl_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <1 x i64> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP3]]
int64x1_t test_vbsl_s64(uint64x1_t a, int64x1_t b, int64x1_t c) {
  return vbsl_s64(a, b, c);
}

// CHECK-LABEL: @test_vbsl_u8(
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VBSL_V_I]]
uint8x8_t test_vbsl_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c) {
  return vbsl_u8(a, b, c);
}

// CHECK-LABEL: @test_vbsl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP3]]
uint16x4_t test_vbsl_u16(uint16x4_t a, uint16x4_t b, uint16x4_t c) {
  return vbsl_u16(a, b, c);
}

// CHECK-LABEL: @test_vbsl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP3]]
uint32x2_t test_vbsl_u32(uint32x2_t a, uint32x2_t b, uint32x2_t c) {
  return vbsl_u32(a, b, c);
}

// CHECK-LABEL: @test_vbsl_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <1 x i64> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP3]]
uint64x1_t test_vbsl_u64(uint64x1_t a, uint64x1_t b, uint64x1_t c) {
  return vbsl_u64(a, b, c);
}

// CHECK-LABEL: @test_vbsl_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x float> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <2 x float>
// CHECK:   ret <2 x float> [[TMP3]]
float32x2_t test_vbsl_f32(uint32x2_t a, float32x2_t b, float32x2_t c) {
  return vbsl_f32(a, b, c);
}

// CHECK-LABEL: @test_vbsl_p8(
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VBSL_V_I]]
poly8x8_t test_vbsl_p8(uint8x8_t a, poly8x8_t b, poly8x8_t c) {
  return vbsl_p8(a, b, c);
}

// CHECK-LABEL: @test_vbsl_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP0]], <8 x i8> [[TMP1]], <8 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP3]]
poly16x4_t test_vbsl_p16(uint16x4_t a, poly16x4_t b, poly16x4_t c) {
  return vbsl_p16(a, b, c);
}

// CHECK-LABEL: @test_vbslq_s8(
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> %c)
// CHECK:   ret <16 x i8> [[VBSLQ_V_I]]
int8x16_t test_vbslq_s8(uint8x16_t a, int8x16_t b, int8x16_t c) {
  return vbslq_s8(a, b, c);
}

// CHECK-LABEL: @test_vbslq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP3]]
int16x8_t test_vbslq_s16(uint16x8_t a, int16x8_t b, int16x8_t c) {
  return vbslq_s16(a, b, c);
}

// CHECK-LABEL: @test_vbslq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP3]]
int32x4_t test_vbslq_s32(uint32x4_t a, int32x4_t b, int32x4_t c) {
  return vbslq_s32(a, b, c);
}

// CHECK-LABEL: @test_vbslq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i64> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP3]]
int64x2_t test_vbslq_s64(uint64x2_t a, int64x2_t b, int64x2_t c) {
  return vbslq_s64(a, b, c);
}

// CHECK-LABEL: @test_vbslq_u8(
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> %c)
// CHECK:   ret <16 x i8> [[VBSLQ_V_I]]
uint8x16_t test_vbslq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c) {
  return vbslq_u8(a, b, c);
}

// CHECK-LABEL: @test_vbslq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP3]]
uint16x8_t test_vbslq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c) {
  return vbslq_u16(a, b, c);
}

// CHECK-LABEL: @test_vbslq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP3]]
uint32x4_t test_vbslq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  return vbslq_u32(a, b, c);
}

// CHECK-LABEL: @test_vbslq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i64> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP3]]
uint64x2_t test_vbslq_u64(uint64x2_t a, uint64x2_t b, uint64x2_t c) {
  return vbslq_u64(a, b, c);
}

// CHECK-LABEL: @test_vbslq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x float> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <4 x float>
// CHECK:   ret <4 x float> [[TMP3]]
float32x4_t test_vbslq_f32(uint32x4_t a, float32x4_t b, float32x4_t c) {
  return vbslq_f32(a, b, c);
}

// CHECK-LABEL: @test_vbslq_p8(
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> %c)
// CHECK:   ret <16 x i8> [[VBSLQ_V_I]]
poly8x16_t test_vbslq_p8(uint8x16_t a, poly8x16_t b, poly8x16_t c) {
  return vbslq_p8(a, b, c);
}

// CHECK-LABEL: @test_vbslq_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %c to <16 x i8>
// CHECK:   [[VBSLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vbsl.v16i8(<16 x i8> [[TMP0]], <16 x i8> [[TMP1]], <16 x i8> [[TMP2]])
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[VBSLQ_V_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP3]]
poly16x8_t test_vbslq_p16(uint16x8_t a, poly16x8_t b, poly16x8_t c) {
  return vbslq_p16(a, b, c);
}

// CHECK-LABEL: @test_vcage_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VCAGE_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vacge.v2i32.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   ret <2 x i32> [[VCAGE_V2_I]]
uint32x2_t test_vcage_f32(float32x2_t a, float32x2_t b) {
  return vcage_f32(a, b);
}

// CHECK-LABEL: @test_vcageq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VCAGEQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vacge.v4i32.v4f32(<4 x float> %a, <4 x float> %b)
// CHECK:   ret <4 x i32> [[VCAGEQ_V2_I]]
uint32x4_t test_vcageq_f32(float32x4_t a, float32x4_t b) {
  return vcageq_f32(a, b);
}

// CHECK-LABEL: @test_vcagt_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VCAGT_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vacgt.v2i32.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   ret <2 x i32> [[VCAGT_V2_I]]
uint32x2_t test_vcagt_f32(float32x2_t a, float32x2_t b) {
  return vcagt_f32(a, b);
}

// CHECK-LABEL: @test_vcagtq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VCAGTQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vacgt.v4i32.v4f32(<4 x float> %a, <4 x float> %b)
// CHECK:   ret <4 x i32> [[VCAGTQ_V2_I]]
uint32x4_t test_vcagtq_f32(float32x4_t a, float32x4_t b) {
  return vcagtq_f32(a, b);
}

// CHECK-LABEL: @test_vcale_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VCALE_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vacge.v2i32.v2f32(<2 x float> %b, <2 x float> %a)
// CHECK:   ret <2 x i32> [[VCALE_V2_I]]
uint32x2_t test_vcale_f32(float32x2_t a, float32x2_t b) {
  return vcale_f32(a, b);
}

// CHECK-LABEL: @test_vcaleq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VCALEQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vacge.v4i32.v4f32(<4 x float> %b, <4 x float> %a)
// CHECK:   ret <4 x i32> [[VCALEQ_V2_I]]
uint32x4_t test_vcaleq_f32(float32x4_t a, float32x4_t b) {
  return vcaleq_f32(a, b);
}

// CHECK-LABEL: @test_vcalt_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VCALT_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vacgt.v2i32.v2f32(<2 x float> %b, <2 x float> %a)
// CHECK:   ret <2 x i32> [[VCALT_V2_I]]
uint32x2_t test_vcalt_f32(float32x2_t a, float32x2_t b) {
  return vcalt_f32(a, b);
}

// CHECK-LABEL: @test_vcaltq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VCALTQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vacgt.v4i32.v4f32(<4 x float> %b, <4 x float> %a)
// CHECK:   ret <4 x i32> [[VCALTQ_V2_I]]
uint32x4_t test_vcaltq_f32(float32x4_t a, float32x4_t b) {
  return vcaltq_f32(a, b);
}

// CHECK-LABEL: @test_vceq_s8(
// CHECK:   [[CMP_I:%.*]] = icmp eq <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vceq_s8(int8x8_t a, int8x8_t b) {
  return vceq_s8(a, b);
}

// CHECK-LABEL: @test_vceq_s16(
// CHECK:   [[CMP_I:%.*]] = icmp eq <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vceq_s16(int16x4_t a, int16x4_t b) {
  return vceq_s16(a, b);
}

// CHECK-LABEL: @test_vceq_s32(
// CHECK:   [[CMP_I:%.*]] = icmp eq <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vceq_s32(int32x2_t a, int32x2_t b) {
  return vceq_s32(a, b);
}

// CHECK-LABEL: @test_vceq_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp oeq <2 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vceq_f32(float32x2_t a, float32x2_t b) {
  return vceq_f32(a, b);
}

// CHECK-LABEL: @test_vceq_u8(
// CHECK:   [[CMP_I:%.*]] = icmp eq <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vceq_u8(uint8x8_t a, uint8x8_t b) {
  return vceq_u8(a, b);
}

// CHECK-LABEL: @test_vceq_u16(
// CHECK:   [[CMP_I:%.*]] = icmp eq <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vceq_u16(uint16x4_t a, uint16x4_t b) {
  return vceq_u16(a, b);
}

// CHECK-LABEL: @test_vceq_u32(
// CHECK:   [[CMP_I:%.*]] = icmp eq <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vceq_u32(uint32x2_t a, uint32x2_t b) {
  return vceq_u32(a, b);
}

// CHECK-LABEL: @test_vceq_p8(
// CHECK:   [[CMP_I:%.*]] = icmp eq <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vceq_p8(poly8x8_t a, poly8x8_t b) {
  return vceq_p8(a, b);
}

// CHECK-LABEL: @test_vceqq_s8(
// CHECK:   [[CMP_I:%.*]] = icmp eq <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vceqq_s8(int8x16_t a, int8x16_t b) {
  return vceqq_s8(a, b);
}

// CHECK-LABEL: @test_vceqq_s16(
// CHECK:   [[CMP_I:%.*]] = icmp eq <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vceqq_s16(int16x8_t a, int16x8_t b) {
  return vceqq_s16(a, b);
}

// CHECK-LABEL: @test_vceqq_s32(
// CHECK:   [[CMP_I:%.*]] = icmp eq <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vceqq_s32(int32x4_t a, int32x4_t b) {
  return vceqq_s32(a, b);
}

// CHECK-LABEL: @test_vceqq_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp oeq <4 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vceqq_f32(float32x4_t a, float32x4_t b) {
  return vceqq_f32(a, b);
}

// CHECK-LABEL: @test_vceqq_u8(
// CHECK:   [[CMP_I:%.*]] = icmp eq <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vceqq_u8(uint8x16_t a, uint8x16_t b) {
  return vceqq_u8(a, b);
}

// CHECK-LABEL: @test_vceqq_u16(
// CHECK:   [[CMP_I:%.*]] = icmp eq <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vceqq_u16(uint16x8_t a, uint16x8_t b) {
  return vceqq_u16(a, b);
}

// CHECK-LABEL: @test_vceqq_u32(
// CHECK:   [[CMP_I:%.*]] = icmp eq <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vceqq_u32(uint32x4_t a, uint32x4_t b) {
  return vceqq_u32(a, b);
}

// CHECK-LABEL: @test_vceqq_p8(
// CHECK:   [[CMP_I:%.*]] = icmp eq <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vceqq_p8(poly8x16_t a, poly8x16_t b) {
  return vceqq_p8(a, b);
}

// CHECK-LABEL: @test_vcge_s8(
// CHECK:   [[CMP_I:%.*]] = icmp sge <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vcge_s8(int8x8_t a, int8x8_t b) {
  return vcge_s8(a, b);
}

// CHECK-LABEL: @test_vcge_s16(
// CHECK:   [[CMP_I:%.*]] = icmp sge <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vcge_s16(int16x4_t a, int16x4_t b) {
  return vcge_s16(a, b);
}

// CHECK-LABEL: @test_vcge_s32(
// CHECK:   [[CMP_I:%.*]] = icmp sge <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcge_s32(int32x2_t a, int32x2_t b) {
  return vcge_s32(a, b);
}

// CHECK-LABEL: @test_vcge_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp oge <2 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcge_f32(float32x2_t a, float32x2_t b) {
  return vcge_f32(a, b);
}

// CHECK-LABEL: @test_vcge_u8(
// CHECK:   [[CMP_I:%.*]] = icmp uge <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vcge_u8(uint8x8_t a, uint8x8_t b) {
  return vcge_u8(a, b);
}

// CHECK-LABEL: @test_vcge_u16(
// CHECK:   [[CMP_I:%.*]] = icmp uge <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vcge_u16(uint16x4_t a, uint16x4_t b) {
  return vcge_u16(a, b);
}

// CHECK-LABEL: @test_vcge_u32(
// CHECK:   [[CMP_I:%.*]] = icmp uge <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcge_u32(uint32x2_t a, uint32x2_t b) {
  return vcge_u32(a, b);
}

// CHECK-LABEL: @test_vcgeq_s8(
// CHECK:   [[CMP_I:%.*]] = icmp sge <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcgeq_s8(int8x16_t a, int8x16_t b) {
  return vcgeq_s8(a, b);
}

// CHECK-LABEL: @test_vcgeq_s16(
// CHECK:   [[CMP_I:%.*]] = icmp sge <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcgeq_s16(int16x8_t a, int16x8_t b) {
  return vcgeq_s16(a, b);
}

// CHECK-LABEL: @test_vcgeq_s32(
// CHECK:   [[CMP_I:%.*]] = icmp sge <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcgeq_s32(int32x4_t a, int32x4_t b) {
  return vcgeq_s32(a, b);
}

// CHECK-LABEL: @test_vcgeq_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp oge <4 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcgeq_f32(float32x4_t a, float32x4_t b) {
  return vcgeq_f32(a, b);
}

// CHECK-LABEL: @test_vcgeq_u8(
// CHECK:   [[CMP_I:%.*]] = icmp uge <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcgeq_u8(uint8x16_t a, uint8x16_t b) {
  return vcgeq_u8(a, b);
}

// CHECK-LABEL: @test_vcgeq_u16(
// CHECK:   [[CMP_I:%.*]] = icmp uge <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcgeq_u16(uint16x8_t a, uint16x8_t b) {
  return vcgeq_u16(a, b);
}

// CHECK-LABEL: @test_vcgeq_u32(
// CHECK:   [[CMP_I:%.*]] = icmp uge <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcgeq_u32(uint32x4_t a, uint32x4_t b) {
  return vcgeq_u32(a, b);
}

// CHECK-LABEL: @test_vcgt_s8(
// CHECK:   [[CMP_I:%.*]] = icmp sgt <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vcgt_s8(int8x8_t a, int8x8_t b) {
  return vcgt_s8(a, b);
}

// CHECK-LABEL: @test_vcgt_s16(
// CHECK:   [[CMP_I:%.*]] = icmp sgt <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vcgt_s16(int16x4_t a, int16x4_t b) {
  return vcgt_s16(a, b);
}

// CHECK-LABEL: @test_vcgt_s32(
// CHECK:   [[CMP_I:%.*]] = icmp sgt <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcgt_s32(int32x2_t a, int32x2_t b) {
  return vcgt_s32(a, b);
}

// CHECK-LABEL: @test_vcgt_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp ogt <2 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcgt_f32(float32x2_t a, float32x2_t b) {
  return vcgt_f32(a, b);
}

// CHECK-LABEL: @test_vcgt_u8(
// CHECK:   [[CMP_I:%.*]] = icmp ugt <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vcgt_u8(uint8x8_t a, uint8x8_t b) {
  return vcgt_u8(a, b);
}

// CHECK-LABEL: @test_vcgt_u16(
// CHECK:   [[CMP_I:%.*]] = icmp ugt <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vcgt_u16(uint16x4_t a, uint16x4_t b) {
  return vcgt_u16(a, b);
}

// CHECK-LABEL: @test_vcgt_u32(
// CHECK:   [[CMP_I:%.*]] = icmp ugt <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcgt_u32(uint32x2_t a, uint32x2_t b) {
  return vcgt_u32(a, b);
}

// CHECK-LABEL: @test_vcgtq_s8(
// CHECK:   [[CMP_I:%.*]] = icmp sgt <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcgtq_s8(int8x16_t a, int8x16_t b) {
  return vcgtq_s8(a, b);
}

// CHECK-LABEL: @test_vcgtq_s16(
// CHECK:   [[CMP_I:%.*]] = icmp sgt <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcgtq_s16(int16x8_t a, int16x8_t b) {
  return vcgtq_s16(a, b);
}

// CHECK-LABEL: @test_vcgtq_s32(
// CHECK:   [[CMP_I:%.*]] = icmp sgt <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcgtq_s32(int32x4_t a, int32x4_t b) {
  return vcgtq_s32(a, b);
}

// CHECK-LABEL: @test_vcgtq_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp ogt <4 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcgtq_f32(float32x4_t a, float32x4_t b) {
  return vcgtq_f32(a, b);
}

// CHECK-LABEL: @test_vcgtq_u8(
// CHECK:   [[CMP_I:%.*]] = icmp ugt <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcgtq_u8(uint8x16_t a, uint8x16_t b) {
  return vcgtq_u8(a, b);
}

// CHECK-LABEL: @test_vcgtq_u16(
// CHECK:   [[CMP_I:%.*]] = icmp ugt <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcgtq_u16(uint16x8_t a, uint16x8_t b) {
  return vcgtq_u16(a, b);
}

// CHECK-LABEL: @test_vcgtq_u32(
// CHECK:   [[CMP_I:%.*]] = icmp ugt <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcgtq_u32(uint32x4_t a, uint32x4_t b) {
  return vcgtq_u32(a, b);
}

// CHECK-LABEL: @test_vcle_s8(
// CHECK:   [[CMP_I:%.*]] = icmp sle <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vcle_s8(int8x8_t a, int8x8_t b) {
  return vcle_s8(a, b);
}

// CHECK-LABEL: @test_vcle_s16(
// CHECK:   [[CMP_I:%.*]] = icmp sle <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vcle_s16(int16x4_t a, int16x4_t b) {
  return vcle_s16(a, b);
}

// CHECK-LABEL: @test_vcle_s32(
// CHECK:   [[CMP_I:%.*]] = icmp sle <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcle_s32(int32x2_t a, int32x2_t b) {
  return vcle_s32(a, b);
}

// CHECK-LABEL: @test_vcle_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp ole <2 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcle_f32(float32x2_t a, float32x2_t b) {
  return vcle_f32(a, b);
}

// CHECK-LABEL: @test_vcle_u8(
// CHECK:   [[CMP_I:%.*]] = icmp ule <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vcle_u8(uint8x8_t a, uint8x8_t b) {
  return vcle_u8(a, b);
}

// CHECK-LABEL: @test_vcle_u16(
// CHECK:   [[CMP_I:%.*]] = icmp ule <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vcle_u16(uint16x4_t a, uint16x4_t b) {
  return vcle_u16(a, b);
}

// CHECK-LABEL: @test_vcle_u32(
// CHECK:   [[CMP_I:%.*]] = icmp ule <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vcle_u32(uint32x2_t a, uint32x2_t b) {
  return vcle_u32(a, b);
}

// CHECK-LABEL: @test_vcleq_s8(
// CHECK:   [[CMP_I:%.*]] = icmp sle <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcleq_s8(int8x16_t a, int8x16_t b) {
  return vcleq_s8(a, b);
}

// CHECK-LABEL: @test_vcleq_s16(
// CHECK:   [[CMP_I:%.*]] = icmp sle <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcleq_s16(int16x8_t a, int16x8_t b) {
  return vcleq_s16(a, b);
}

// CHECK-LABEL: @test_vcleq_s32(
// CHECK:   [[CMP_I:%.*]] = icmp sle <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcleq_s32(int32x4_t a, int32x4_t b) {
  return vcleq_s32(a, b);
}

// CHECK-LABEL: @test_vcleq_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp ole <4 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcleq_f32(float32x4_t a, float32x4_t b) {
  return vcleq_f32(a, b);
}

// CHECK-LABEL: @test_vcleq_u8(
// CHECK:   [[CMP_I:%.*]] = icmp ule <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcleq_u8(uint8x16_t a, uint8x16_t b) {
  return vcleq_u8(a, b);
}

// CHECK-LABEL: @test_vcleq_u16(
// CHECK:   [[CMP_I:%.*]] = icmp ule <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcleq_u16(uint16x8_t a, uint16x8_t b) {
  return vcleq_u16(a, b);
}

// CHECK-LABEL: @test_vcleq_u32(
// CHECK:   [[CMP_I:%.*]] = icmp ule <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcleq_u32(uint32x4_t a, uint32x4_t b) {
  return vcleq_u32(a, b);
}

// CHECK-LABEL: @test_vcls_s8(
// CHECK:   [[VCLS_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vcls.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VCLS_V_I]]
int8x8_t test_vcls_s8(int8x8_t a) {
  return vcls_s8(a);
}

// CHECK-LABEL: @test_vcls_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VCLS_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vcls.v4i16(<4 x i16> %a)
// CHECK:   [[VCLS_V2_I:%.*]] = bitcast <4 x i16> [[VCLS_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VCLS_V1_I]]
int16x4_t test_vcls_s16(int16x4_t a) {
  return vcls_s16(a);
}

// CHECK-LABEL: @test_vcls_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCLS_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vcls.v2i32(<2 x i32> %a)
// CHECK:   [[VCLS_V2_I:%.*]] = bitcast <2 x i32> [[VCLS_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VCLS_V1_I]]
int32x2_t test_vcls_s32(int32x2_t a) {
  return vcls_s32(a);
}

// CHECK-LABEL: @test_vcls_u8(
// CHECK:   [[VCLS_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vcls.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VCLS_V_I]]
int8x8_t test_vcls_u8(uint8x8_t a) {
  return vcls_u8(a);
}

// CHECK-LABEL: @test_vcls_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VCLS_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vcls.v4i16(<4 x i16> %a)
// CHECK:   [[VCLS_V2_I:%.*]] = bitcast <4 x i16> [[VCLS_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VCLS_V1_I]]
int16x4_t test_vcls_u16(uint16x4_t a) {
  return vcls_u16(a);
}

// CHECK-LABEL: @test_vcls_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCLS_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vcls.v2i32(<2 x i32> %a)
// CHECK:   [[VCLS_V2_I:%.*]] = bitcast <2 x i32> [[VCLS_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VCLS_V1_I]]
int32x2_t test_vcls_u32(uint32x2_t a) {
  return vcls_u32(a);
}

// CHECK-LABEL: @test_vclsq_s8(
// CHECK:   [[VCLSQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vcls.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VCLSQ_V_I]]
int8x16_t test_vclsq_s8(int8x16_t a) {
  return vclsq_s8(a);
}

// CHECK-LABEL: @test_vclsq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VCLSQ_V1_I:%.*]] = call <8 x i16> @llvm.arm.neon.vcls.v8i16(<8 x i16> %a)
// CHECK:   [[VCLSQ_V2_I:%.*]] = bitcast <8 x i16> [[VCLSQ_V1_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VCLSQ_V1_I]]
int16x8_t test_vclsq_s16(int16x8_t a) {
  return vclsq_s16(a);
}

// CHECK-LABEL: @test_vclsq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCLSQ_V1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vcls.v4i32(<4 x i32> %a)
// CHECK:   [[VCLSQ_V2_I:%.*]] = bitcast <4 x i32> [[VCLSQ_V1_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VCLSQ_V1_I]]
int32x4_t test_vclsq_s32(int32x4_t a) {
  return vclsq_s32(a);
}

// CHECK-LABEL: @test_vclsq_u8(
// CHECK:   [[VCLSQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vcls.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VCLSQ_V_I]]
int8x16_t test_vclsq_u8(uint8x16_t a) {
  return vclsq_u8(a);
}

// CHECK-LABEL: @test_vclsq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VCLSQ_V1_I:%.*]] = call <8 x i16> @llvm.arm.neon.vcls.v8i16(<8 x i16> %a)
// CHECK:   [[VCLSQ_V2_I:%.*]] = bitcast <8 x i16> [[VCLSQ_V1_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VCLSQ_V1_I]]
int16x8_t test_vclsq_u16(uint16x8_t a) {
  return vclsq_u16(a);
}

// CHECK-LABEL: @test_vclsq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCLSQ_V1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vcls.v4i32(<4 x i32> %a)
// CHECK:   [[VCLSQ_V2_I:%.*]] = bitcast <4 x i32> [[VCLSQ_V1_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VCLSQ_V1_I]]
int32x4_t test_vclsq_u32(uint32x4_t a) {
  return vclsq_u32(a);
}

// CHECK-LABEL: @test_vclt_s8(
// CHECK:   [[CMP_I:%.*]] = icmp slt <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vclt_s8(int8x8_t a, int8x8_t b) {
  return vclt_s8(a, b);
}

// CHECK-LABEL: @test_vclt_s16(
// CHECK:   [[CMP_I:%.*]] = icmp slt <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vclt_s16(int16x4_t a, int16x4_t b) {
  return vclt_s16(a, b);
}

// CHECK-LABEL: @test_vclt_s32(
// CHECK:   [[CMP_I:%.*]] = icmp slt <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vclt_s32(int32x2_t a, int32x2_t b) {
  return vclt_s32(a, b);
}

// CHECK-LABEL: @test_vclt_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp olt <2 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vclt_f32(float32x2_t a, float32x2_t b) {
  return vclt_f32(a, b);
}

// CHECK-LABEL: @test_vclt_u8(
// CHECK:   [[CMP_I:%.*]] = icmp ult <8 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[SEXT_I]]
uint8x8_t test_vclt_u8(uint8x8_t a, uint8x8_t b) {
  return vclt_u8(a, b);
}

// CHECK-LABEL: @test_vclt_u16(
// CHECK:   [[CMP_I:%.*]] = icmp ult <4 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[SEXT_I]]
uint16x4_t test_vclt_u16(uint16x4_t a, uint16x4_t b) {
  return vclt_u16(a, b);
}

// CHECK-LABEL: @test_vclt_u32(
// CHECK:   [[CMP_I:%.*]] = icmp ult <2 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <2 x i1> [[CMP_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[SEXT_I]]
uint32x2_t test_vclt_u32(uint32x2_t a, uint32x2_t b) {
  return vclt_u32(a, b);
}

// CHECK-LABEL: @test_vcltq_s8(
// CHECK:   [[CMP_I:%.*]] = icmp slt <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcltq_s8(int8x16_t a, int8x16_t b) {
  return vcltq_s8(a, b);
}

// CHECK-LABEL: @test_vcltq_s16(
// CHECK:   [[CMP_I:%.*]] = icmp slt <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcltq_s16(int16x8_t a, int16x8_t b) {
  return vcltq_s16(a, b);
}

// CHECK-LABEL: @test_vcltq_s32(
// CHECK:   [[CMP_I:%.*]] = icmp slt <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcltq_s32(int32x4_t a, int32x4_t b) {
  return vcltq_s32(a, b);
}

// CHECK-LABEL: @test_vcltq_f32(
// CHECK:   [[CMP_I:%.*]] = fcmp olt <4 x float> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcltq_f32(float32x4_t a, float32x4_t b) {
  return vcltq_f32(a, b);
}

// CHECK-LABEL: @test_vcltq_u8(
// CHECK:   [[CMP_I:%.*]] = icmp ult <16 x i8> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <16 x i1> [[CMP_I]] to <16 x i8>
// CHECK:   ret <16 x i8> [[SEXT_I]]
uint8x16_t test_vcltq_u8(uint8x16_t a, uint8x16_t b) {
  return vcltq_u8(a, b);
}

// CHECK-LABEL: @test_vcltq_u16(
// CHECK:   [[CMP_I:%.*]] = icmp ult <8 x i16> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <8 x i1> [[CMP_I]] to <8 x i16>
// CHECK:   ret <8 x i16> [[SEXT_I]]
uint16x8_t test_vcltq_u16(uint16x8_t a, uint16x8_t b) {
  return vcltq_u16(a, b);
}

// CHECK-LABEL: @test_vcltq_u32(
// CHECK:   [[CMP_I:%.*]] = icmp ult <4 x i32> %a, %b
// CHECK:   [[SEXT_I:%.*]] = sext <4 x i1> [[CMP_I]] to <4 x i32>
// CHECK:   ret <4 x i32> [[SEXT_I]]
uint32x4_t test_vcltq_u32(uint32x4_t a, uint32x4_t b) {
  return vcltq_u32(a, b);
}

// CHECK-LABEL: @test_vclz_s8(
// CHECK:   [[VCLZ_V_I:%.*]] = call <8 x i8> @llvm.ctlz.v8i8(<8 x i8> %a, i1 false)
// CHECK:   ret <8 x i8> [[VCLZ_V_I]]
int8x8_t test_vclz_s8(int8x8_t a) {
  return vclz_s8(a);
}

// CHECK-LABEL: @test_vclz_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <4 x i16> @llvm.ctlz.v4i16(<4 x i16> %a, i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <4 x i16> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VCLZ_V1_I]]
int16x4_t test_vclz_s16(int16x4_t a) {
  return vclz_s16(a);
}

// CHECK-LABEL: @test_vclz_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <2 x i32> @llvm.ctlz.v2i32(<2 x i32> %a, i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <2 x i32> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VCLZ_V1_I]]
int32x2_t test_vclz_s32(int32x2_t a) {
  return vclz_s32(a);
}

// CHECK-LABEL: @test_vclz_u8(
// CHECK:   [[VCLZ_V_I:%.*]] = call <8 x i8> @llvm.ctlz.v8i8(<8 x i8> %a, i1 false)
// CHECK:   ret <8 x i8> [[VCLZ_V_I]]
uint8x8_t test_vclz_u8(uint8x8_t a) {
  return vclz_u8(a);
}

// CHECK-LABEL: @test_vclz_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <4 x i16> @llvm.ctlz.v4i16(<4 x i16> %a, i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <4 x i16> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VCLZ_V1_I]]
uint16x4_t test_vclz_u16(uint16x4_t a) {
  return vclz_u16(a);
}

// CHECK-LABEL: @test_vclz_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <2 x i32> @llvm.ctlz.v2i32(<2 x i32> %a, i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <2 x i32> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VCLZ_V1_I]]
uint32x2_t test_vclz_u32(uint32x2_t a) {
  return vclz_u32(a);
}

// CHECK-LABEL: @test_vclzq_s8(
// CHECK:   [[VCLZQ_V_I:%.*]] = call <16 x i8> @llvm.ctlz.v16i8(<16 x i8> %a, i1 false)
// CHECK:   ret <16 x i8> [[VCLZQ_V_I]]
int8x16_t test_vclzq_s8(int8x16_t a) {
  return vclzq_s8(a);
}

// CHECK-LABEL: @test_vclzq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VCLZQ_V1_I:%.*]] = call <8 x i16> @llvm.ctlz.v8i16(<8 x i16> %a, i1 false)
// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast <8 x i16> [[VCLZQ_V1_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VCLZQ_V1_I]]
int16x8_t test_vclzq_s16(int16x8_t a) {
  return vclzq_s16(a);
}

// CHECK-LABEL: @test_vclzq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCLZQ_V1_I:%.*]] = call <4 x i32> @llvm.ctlz.v4i32(<4 x i32> %a, i1 false)
// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast <4 x i32> [[VCLZQ_V1_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VCLZQ_V1_I]]
int32x4_t test_vclzq_s32(int32x4_t a) {
  return vclzq_s32(a);
}

// CHECK-LABEL: @test_vclzq_u8(
// CHECK:   [[VCLZQ_V_I:%.*]] = call <16 x i8> @llvm.ctlz.v16i8(<16 x i8> %a, i1 false)
// CHECK:   ret <16 x i8> [[VCLZQ_V_I]]
uint8x16_t test_vclzq_u8(uint8x16_t a) {
  return vclzq_u8(a);
}

// CHECK-LABEL: @test_vclzq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VCLZQ_V1_I:%.*]] = call <8 x i16> @llvm.ctlz.v8i16(<8 x i16> %a, i1 false)
// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast <8 x i16> [[VCLZQ_V1_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VCLZQ_V1_I]]
uint16x8_t test_vclzq_u16(uint16x8_t a) {
  return vclzq_u16(a);
}

// CHECK-LABEL: @test_vclzq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCLZQ_V1_I:%.*]] = call <4 x i32> @llvm.ctlz.v4i32(<4 x i32> %a, i1 false)
// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast <4 x i32> [[VCLZQ_V1_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VCLZQ_V1_I]]
uint32x4_t test_vclzq_u32(uint32x4_t a) {
  return vclzq_u32(a);
}

// CHECK-LABEL: @test_vcnt_u8(
// CHECK:   [[VCNT_V_I:%.*]] = call <8 x i8> @llvm.ctpop.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VCNT_V_I]]
uint8x8_t test_vcnt_u8(uint8x8_t a) {
  return vcnt_u8(a);
}

// CHECK-LABEL: @test_vcnt_s8(
// CHECK:   [[VCNT_V_I:%.*]] = call <8 x i8> @llvm.ctpop.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VCNT_V_I]]
int8x8_t test_vcnt_s8(int8x8_t a) {
  return vcnt_s8(a);
}

// CHECK-LABEL: @test_vcnt_p8(
// CHECK:   [[VCNT_V_I:%.*]] = call <8 x i8> @llvm.ctpop.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VCNT_V_I]]
poly8x8_t test_vcnt_p8(poly8x8_t a) {
  return vcnt_p8(a);
}

// CHECK-LABEL: @test_vcntq_u8(
// CHECK:   [[VCNTQ_V_I:%.*]] = call <16 x i8> @llvm.ctpop.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VCNTQ_V_I]]
uint8x16_t test_vcntq_u8(uint8x16_t a) {
  return vcntq_u8(a);
}

// CHECK-LABEL: @test_vcntq_s8(
// CHECK:   [[VCNTQ_V_I:%.*]] = call <16 x i8> @llvm.ctpop.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VCNTQ_V_I]]
int8x16_t test_vcntq_s8(int8x16_t a) {
  return vcntq_s8(a);
}

// CHECK-LABEL: @test_vcntq_p8(
// CHECK:   [[VCNTQ_V_I:%.*]] = call <16 x i8> @llvm.ctpop.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VCNTQ_V_I]]
poly8x16_t test_vcntq_p8(poly8x16_t a) {
  return vcntq_p8(a);
}

// CHECK-LABEL: @test_vcombine_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <16 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
int8x16_t test_vcombine_s8(int8x8_t a, int8x8_t b) {
  return vcombine_s8(a, b);
}

// CHECK-LABEL: @test_vcombine_s16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
int16x8_t test_vcombine_s16(int16x4_t a, int16x4_t b) {
  return vcombine_s16(a, b);
}

// CHECK-LABEL: @test_vcombine_s32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
// CHECK:   ret <4 x i32> [[SHUFFLE_I]]
int32x4_t test_vcombine_s32(int32x2_t a, int32x2_t b) {
  return vcombine_s32(a, b);
}

// CHECK-LABEL: @test_vcombine_s64(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <1 x i64> %a, <1 x i64> %b, <2 x i32> <i32 0, i32 1>
// CHECK:   ret <2 x i64> [[SHUFFLE_I]]
int64x2_t test_vcombine_s64(int64x1_t a, int64x1_t b) {
  return vcombine_s64(a, b);
}

// CHECK-LABEL: @test_vcombine_f16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x half> %a, <4 x half> %b, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <8 x half> [[SHUFFLE_I]]
float16x8_t test_vcombine_f16(float16x4_t a, float16x4_t b) {
  return vcombine_f16(a, b);
}

// CHECK-LABEL: @test_vcombine_f32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %b, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
// CHECK:   ret <4 x float> [[SHUFFLE_I]]
float32x4_t test_vcombine_f32(float32x2_t a, float32x2_t b) {
  return vcombine_f32(a, b);
}

// CHECK-LABEL: @test_vcombine_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <16 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
uint8x16_t test_vcombine_u8(uint8x8_t a, uint8x8_t b) {
  return vcombine_u8(a, b);
}

// CHECK-LABEL: @test_vcombine_u16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
uint16x8_t test_vcombine_u16(uint16x4_t a, uint16x4_t b) {
  return vcombine_u16(a, b);
}

// CHECK-LABEL: @test_vcombine_u32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
// CHECK:   ret <4 x i32> [[SHUFFLE_I]]
uint32x4_t test_vcombine_u32(uint32x2_t a, uint32x2_t b) {
  return vcombine_u32(a, b);
}

// CHECK-LABEL: @test_vcombine_u64(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <1 x i64> %a, <1 x i64> %b, <2 x i32> <i32 0, i32 1>
// CHECK:   ret <2 x i64> [[SHUFFLE_I]]
uint64x2_t test_vcombine_u64(uint64x1_t a, uint64x1_t b) {
  return vcombine_u64(a, b);
}

// CHECK-LABEL: @test_vcombine_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <16 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
poly8x16_t test_vcombine_p8(poly8x8_t a, poly8x8_t b) {
  return vcombine_p8(a, b);
}

// CHECK-LABEL: @test_vcombine_p16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
poly16x8_t test_vcombine_p16(poly16x4_t a, poly16x4_t b) {
  return vcombine_p16(a, b);
}

// CHECK-LABEL: @test_vcreate_s8(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <8 x i8>
// CHECK:   [[VCLZ_V_I:%.*]] = call <8 x i8> @llvm.ctlz.v8i8(<8 x i8> [[TMP0]], i1 false)
// CHECK:   ret <8 x i8> [[VCLZ_V_I]]
int8x8_t test_vcreate_s8(uint64_t a) {
  return vclz_s8(vcreate_s8(a));
}

// CHECK-LABEL: @test_vcreate_imm
// CHECK: [[RES:%.*]] = bitcast i64 0 to <4 x i16>
// CHECK: ret <4 x i16> [[RES]]
int16x4_t test_vcreate_imm(void) {
  return vcreate_s16(0);
}

// CHECK-LABEL: @test_vcreate_s16(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <4 x i16>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[TMP0]] to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <4 x i16> @llvm.ctlz.v4i16(<4 x i16> [[TMP0]], i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <4 x i16> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VCLZ_V1_I]]
int16x4_t test_vcreate_s16(uint64_t a) {
  return vclz_s16(vcreate_s16(a));
}

// CHECK-LABEL: @test_vcreate_s32(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <2 x i32>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[TMP0]] to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <2 x i32> @llvm.ctlz.v2i32(<2 x i32> [[TMP0]], i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <2 x i32> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VCLZ_V1_I]]
int32x2_t test_vcreate_s32(uint64_t a) {
  return vclz_s32(vcreate_s32(a));
}

// CHECK-LABEL: @test_vcreate_f16(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vcreate_f16(uint64_t a) {
  return vcreate_f16(a);
}

// CHECK-LABEL: @test_vcreate_f32(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vcreate_f32(uint64_t a) {
  return vcreate_f32(a);
}

// CHECK-LABEL: @test_vcreate_u8(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <8 x i8>
// CHECK:   [[VCLZ_V_I:%.*]] = call <8 x i8> @llvm.ctlz.v8i8(<8 x i8> [[TMP0]], i1 false)
// CHECK:   ret <8 x i8> [[VCLZ_V_I]]
int8x8_t test_vcreate_u8(uint64_t a) {
  return vclz_s8((int8x8_t)vcreate_u8(a));
}

// CHECK-LABEL: @test_vcreate_u16(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <4 x i16>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[TMP0]] to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <4 x i16> @llvm.ctlz.v4i16(<4 x i16> [[TMP0]], i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <4 x i16> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VCLZ_V1_I]]
int16x4_t test_vcreate_u16(uint64_t a) {
  return vclz_s16((int16x4_t)vcreate_u16(a));
}

// CHECK-LABEL: @test_vcreate_u32(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <2 x i32>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[TMP0]] to <8 x i8>
// CHECK:   [[VCLZ_V1_I:%.*]] = call <2 x i32> @llvm.ctlz.v2i32(<2 x i32> [[TMP0]], i1 false)
// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast <2 x i32> [[VCLZ_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VCLZ_V1_I]]
int32x2_t test_vcreate_u32(uint64_t a) {
  return vclz_s32((int32x2_t)vcreate_u32(a));
}

// CHECK-LABEL: @test_vcreate_u64(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <1 x i64>
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> [[TMP0]], [[TMP0]]
// CHECK:   ret <1 x i64> [[ADD_I]]
uint64x1_t test_vcreate_u64(uint64_t a) {
  uint64x1_t tmp = vcreate_u64(a);
  return vadd_u64(tmp, tmp);
}

// CHECK-LABEL: @test_vcreate_p8(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <8 x i8>
// CHECK:   [[VCNT_V_I:%.*]] = call <8 x i8> @llvm.ctpop.v8i8(<8 x i8> [[TMP0]])
// CHECK:   ret <8 x i8> [[VCNT_V_I]]
poly8x8_t test_vcreate_p8(uint64_t a) {
  return vcnt_p8(vcreate_p8(a));
}

// CHECK-LABEL: @test_vcreate_p16(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <4 x i16>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[TMP0]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[TMP0]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[TMP0]] to <8 x i8>
// CHECK:   [[VBSL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vbsl.v8i8(<8 x i8> [[TMP1]], <8 x i8> [[TMP2]], <8 x i8> [[TMP3]])
// CHECK:   [[TMP4:%.*]] = bitcast <8 x i8> [[VBSL_V_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP4]]
poly16x4_t test_vcreate_p16(uint64_t a) {
  poly16x4_t tmp = vcreate_p16(a);
  return vbsl_p16((uint16x4_t)tmp, tmp, tmp);
}

// CHECK-LABEL: @test_vcreate_s64(
// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to <1 x i64>
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> [[TMP0]], [[TMP0]]
// CHECK:   ret <1 x i64> [[ADD_I]]
int64x1_t test_vcreate_s64(uint64_t a) {
  int64x1_t tmp = vcreate_s64(a);
  return vadd_s64(tmp, tmp);
}

// CHECK-LABEL: @test_vcvt_f16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VCVT_F16_F321_I:%.*]] = call <4 x i16> @llvm.arm.neon.vcvtfp2hf(<4 x float> %a)
// CHECK:   [[VCVT_F16_F322_I:%.*]] = bitcast <4 x i16> [[VCVT_F16_F321_I]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[VCVT_F16_F322_I]] to <4 x half>
// CHECK:   ret <4 x half> [[TMP1]]
float16x4_t test_vcvt_f16_f32(float32x4_t a) {
  return vcvt_f16_f32(a);
}

// CHECK-LABEL: @test_vcvt_f32_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCVT_I:%.*]] = sitofp <2 x i32> %a to <2 x float>
// CHECK:   ret <2 x float> [[VCVT_I]]
float32x2_t test_vcvt_f32_s32(int32x2_t a) {
  return vcvt_f32_s32(a);
}

// CHECK-LABEL: @test_vcvt_f32_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCVT_I:%.*]] = uitofp <2 x i32> %a to <2 x float>
// CHECK:   ret <2 x float> [[VCVT_I]]
float32x2_t test_vcvt_f32_u32(uint32x2_t a) {
  return vcvt_f32_u32(a);
}

// CHECK-LABEL: @test_vcvtq_f32_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCVT_I:%.*]] = sitofp <4 x i32> %a to <4 x float>
// CHECK:   ret <4 x float> [[VCVT_I]]
float32x4_t test_vcvtq_f32_s32(int32x4_t a) {
  return vcvtq_f32_s32(a);
}

// CHECK-LABEL: @test_vcvtq_f32_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCVT_I:%.*]] = uitofp <4 x i32> %a to <4 x float>
// CHECK:   ret <4 x float> [[VCVT_I]]
float32x4_t test_vcvtq_f32_u32(uint32x4_t a) {
  return vcvtq_f32_u32(a);
}

// CHECK-LABEL: @test_vcvt_f32_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <8 x i8>
// CHECK:   [[VCVT_F32_F16_I:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VCVT_F32_F161_I:%.*]] = call <4 x float> @llvm.arm.neon.vcvthf2fp(<4 x i16> [[VCVT_F32_F16_I]])
// CHECK:   [[VCVT_F32_F162_I:%.*]] = bitcast <4 x float> [[VCVT_F32_F161_I]] to <16 x i8>
// CHECK:   ret <4 x float> [[VCVT_F32_F161_I]]
float32x4_t test_vcvt_f32_f16(float16x4_t a) {
  return vcvt_f32_f16(a);
}

// CHECK-LABEL: @test_vcvt_n_f32_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VCVT_N1:%.*]] = call <2 x float> @llvm.arm.neon.vcvtfxs2fp.v2f32.v2i32(<2 x i32> [[VCVT_N]], i32 1)
// CHECK:   ret <2 x float> [[VCVT_N1]]
float32x2_t test_vcvt_n_f32_s32(int32x2_t a) {
  return vcvt_n_f32_s32(a, 1);
}

// CHECK-LABEL: @test_vcvt_n_f32_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VCVT_N1:%.*]] = call <2 x float> @llvm.arm.neon.vcvtfxu2fp.v2f32.v2i32(<2 x i32> [[VCVT_N]], i32 1)
// CHECK:   ret <2 x float> [[VCVT_N1]]
float32x2_t test_vcvt_n_f32_u32(uint32x2_t a) {
  return vcvt_n_f32_u32(a, 1);
}

// CHECK-LABEL: @test_vcvtq_n_f32_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VCVT_N1:%.*]] = call <4 x float> @llvm.arm.neon.vcvtfxs2fp.v4f32.v4i32(<4 x i32> [[VCVT_N]], i32 3)
// CHECK:   ret <4 x float> [[VCVT_N1]]
float32x4_t test_vcvtq_n_f32_s32(int32x4_t a) {
  return vcvtq_n_f32_s32(a, 3);
}

// CHECK-LABEL: @test_vcvtq_n_f32_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VCVT_N1:%.*]] = call <4 x float> @llvm.arm.neon.vcvtfxu2fp.v4f32.v4i32(<4 x i32> [[VCVT_N]], i32 3)
// CHECK:   ret <4 x float> [[VCVT_N1]]
float32x4_t test_vcvtq_n_f32_u32(uint32x4_t a) {
  return vcvtq_n_f32_u32(a, 3);
}

// CHECK-LABEL: @test_vcvt_n_s32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[VCVT_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vcvtfp2fxs.v2i32.v2f32(<2 x float> [[VCVT_N]], i32 1)
// CHECK:   ret <2 x i32> [[VCVT_N1]]
int32x2_t test_vcvt_n_s32_f32(float32x2_t a) {
  return vcvt_n_s32_f32(a, 1);
}

// CHECK-LABEL: @test_vcvtq_n_s32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK:   [[VCVT_N1:%.*]] = call <4 x i32> @llvm.arm.neon.vcvtfp2fxs.v4i32.v4f32(<4 x float> [[VCVT_N]], i32 3)
// CHECK:   ret <4 x i32> [[VCVT_N1]]
int32x4_t test_vcvtq_n_s32_f32(float32x4_t a) {
  return vcvtq_n_s32_f32(a, 3);
}

// CHECK-LABEL: @test_vcvt_n_u32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[VCVT_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vcvtfp2fxu.v2i32.v2f32(<2 x float> [[VCVT_N]], i32 1)
// CHECK:   ret <2 x i32> [[VCVT_N1]]
uint32x2_t test_vcvt_n_u32_f32(float32x2_t a) {
  return vcvt_n_u32_f32(a, 1);
}

// CHECK-LABEL: @test_vcvtq_n_u32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VCVT_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK:   [[VCVT_N1:%.*]] = call <4 x i32> @llvm.arm.neon.vcvtfp2fxu.v4i32.v4f32(<4 x float> [[VCVT_N]], i32 3)
// CHECK:   ret <4 x i32> [[VCVT_N1]]
uint32x4_t test_vcvtq_n_u32_f32(float32x4_t a) {
  return vcvtq_n_u32_f32(a, 3);
}

// CHECK-LABEL: @test_vcvt_s32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[VCVT_I:%.*]] = fptosi <2 x float> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[VCVT_I]]
int32x2_t test_vcvt_s32_f32(float32x2_t a) {
  return vcvt_s32_f32(a);
}

// CHECK-LABEL: @test_vcvtq_s32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VCVT_I:%.*]] = fptosi <4 x float> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[VCVT_I]]
int32x4_t test_vcvtq_s32_f32(float32x4_t a) {
  return vcvtq_s32_f32(a);
}

// CHECK-LABEL: @test_vcvt_u32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[VCVT_I:%.*]] = fptoui <2 x float> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[VCVT_I]]
uint32x2_t test_vcvt_u32_f32(float32x2_t a) {
  return vcvt_u32_f32(a);
}

// CHECK-LABEL: @test_vcvtq_u32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VCVT_I:%.*]] = fptoui <4 x float> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[VCVT_I]]
uint32x4_t test_vcvtq_u32_f32(float32x4_t a) {
  return vcvtq_u32_f32(a);
}

// CHECK-LABEL: @test_vdup_lane_u8(
// CHECK:   [[SHUFFLE:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
// CHECK:   ret <8 x i8> [[SHUFFLE]]
uint8x8_t test_vdup_lane_u8(uint8x8_t a) {
  return vdup_lane_u8(a, 7);
}

// CHECK-LABEL: @test_vdup_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   ret <4 x i16> [[LANE]]
uint16x4_t test_vdup_lane_u16(uint16x4_t a) {
  return vdup_lane_u16(a, 3);
}

// CHECK-LABEL: @test_vdup_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   ret <2 x i32> [[LANE]]
uint32x2_t test_vdup_lane_u32(uint32x2_t a) {
  return vdup_lane_u32(a, 1);
}

// CHECK-LABEL: @test_vdup_lane_s8(
// CHECK:   [[SHUFFLE:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
// CHECK:   ret <8 x i8> [[SHUFFLE]]
int8x8_t test_vdup_lane_s8(int8x8_t a) {
  return vdup_lane_s8(a, 7);
}

// CHECK-LABEL: @test_vdup_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   ret <4 x i16> [[LANE]]
int16x4_t test_vdup_lane_s16(int16x4_t a) {
  return vdup_lane_s16(a, 3);
}

// CHECK-LABEL: @test_vdup_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   ret <2 x i32> [[LANE]]
int32x2_t test_vdup_lane_s32(int32x2_t a) {
  return vdup_lane_s32(a, 1);
}

// CHECK-LABEL: @test_vdup_lane_p8(
// CHECK:   [[SHUFFLE:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
// CHECK:   ret <8 x i8> [[SHUFFLE]]
poly8x8_t test_vdup_lane_p8(poly8x8_t a) {
  return vdup_lane_p8(a, 7);
}

// CHECK-LABEL: @test_vdup_lane_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   ret <4 x i16> [[LANE]]
poly16x4_t test_vdup_lane_p16(poly16x4_t a) {
  return vdup_lane_p16(a, 3);
}

// CHECK-LABEL: @test_vdup_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   ret <2 x float> [[LANE]]
float32x2_t test_vdup_lane_f32(float32x2_t a) {
  return vdup_lane_f32(a, 1);
}

// CHECK-LABEL: @test_vdupq_lane_u8(
// CHECK:   [[SHUFFLE:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <16 x i32> <i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
// CHECK:   ret <16 x i8> [[SHUFFLE]]
uint8x16_t test_vdupq_lane_u8(uint8x8_t a) {
  return vdupq_lane_u8(a, 7);
}

// CHECK-LABEL: @test_vdupq_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   ret <8 x i16> [[LANE]]
uint16x8_t test_vdupq_lane_u16(uint16x4_t a) {
  return vdupq_lane_u16(a, 3);
}

// CHECK-LABEL: @test_vdupq_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[LANE]]
uint32x4_t test_vdupq_lane_u32(uint32x2_t a) {
  return vdupq_lane_u32(a, 1);
}

// CHECK-LABEL: @test_vdupq_lane_s8(
// CHECK:   [[SHUFFLE:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <16 x i32> <i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
// CHECK:   ret <16 x i8> [[SHUFFLE]]
int8x16_t test_vdupq_lane_s8(int8x8_t a) {
  return vdupq_lane_s8(a, 7);
}

// CHECK-LABEL: @test_vdupq_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   ret <8 x i16> [[LANE]]
int16x8_t test_vdupq_lane_s16(int16x4_t a) {
  return vdupq_lane_s16(a, 3);
}

// CHECK-LABEL: @test_vdupq_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[LANE]]
int32x4_t test_vdupq_lane_s32(int32x2_t a) {
  return vdupq_lane_s32(a, 1);
}

// CHECK-LABEL: @test_vdupq_lane_p8(
// CHECK:   [[SHUFFLE:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <16 x i32> <i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
// CHECK:   ret <16 x i8> [[SHUFFLE]]
poly8x16_t test_vdupq_lane_p8(poly8x8_t a) {
  return vdupq_lane_p8(a, 7);
}

// CHECK-LABEL: @test_vdupq_lane_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   ret <8 x i16> [[LANE]]
poly16x8_t test_vdupq_lane_p16(poly16x4_t a) {
  return vdupq_lane_p16(a, 3);
}

// CHECK-LABEL: @test_vdupq_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x float> [[LANE]]
float32x4_t test_vdupq_lane_f32(float32x2_t a) {
  return vdupq_lane_f32(a, 1);
}

// CHECK-LABEL: @test_vdup_lane_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[LANE:%.*]] = shufflevector <1 x i64> [[TMP1]], <1 x i64> [[TMP1]], <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[LANE]]
int64x1_t test_vdup_lane_s64(int64x1_t a) {
  return vdup_lane_s64(a, 0);
}

// CHECK-LABEL: @test_vdup_lane_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[LANE:%.*]] = shufflevector <1 x i64> [[TMP1]], <1 x i64> [[TMP1]], <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[LANE]]
uint64x1_t test_vdup_lane_u64(uint64x1_t a) {
  return vdup_lane_u64(a, 0);
}

// CHECK-LABEL: @test_vdupq_lane_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[LANE:%.*]] = shufflevector <1 x i64> [[TMP1]], <1 x i64> [[TMP1]], <2 x i32> zeroinitializer
// CHECK:   ret <2 x i64> [[LANE]]
int64x2_t test_vdupq_lane_s64(int64x1_t a) {
  return vdupq_lane_s64(a, 0);
}

// CHECK-LABEL: @test_vdupq_lane_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[LANE:%.*]] = shufflevector <1 x i64> [[TMP1]], <1 x i64> [[TMP1]], <2 x i32> zeroinitializer
// CHECK:   ret <2 x i64> [[LANE]]
uint64x2_t test_vdupq_lane_u64(uint64x1_t a) {
  return vdupq_lane_u64(a, 0);
}

// CHECK-LABEL: @test_vdup_n_u8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VECINIT7_I]]
uint8x8_t test_vdup_n_u8(uint8_t a) {
  return vdup_n_u8(a);
}

// CHECK-LABEL: @test_vdup_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VECINIT3_I]]
uint16x4_t test_vdup_n_u16(uint16_t a) {
  return vdup_n_u16(a);
}

// CHECK-LABEL: @test_vdup_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   ret <2 x i32> [[VECINIT1_I]]
uint32x2_t test_vdup_n_u32(uint32_t a) {
  return vdup_n_u32(a);
}

// CHECK-LABEL: @test_vdup_n_s8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VECINIT7_I]]
int8x8_t test_vdup_n_s8(int8_t a) {
  return vdup_n_s8(a);
}

// CHECK-LABEL: @test_vdup_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VECINIT3_I]]
int16x4_t test_vdup_n_s16(int16_t a) {
  return vdup_n_s16(a);
}

// CHECK-LABEL: @test_vdup_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   ret <2 x i32> [[VECINIT1_I]]
int32x2_t test_vdup_n_s32(int32_t a) {
  return vdup_n_s32(a);
}

// CHECK-LABEL: @test_vdup_n_p8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VECINIT7_I]]
poly8x8_t test_vdup_n_p8(poly8_t a) {
  return vdup_n_p8(a);
}

// CHECK-LABEL: @test_vdup_n_p16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VECINIT3_I]]
poly16x4_t test_vdup_n_p16(poly16_t a) {
  return vdup_n_p16(a);
}

// CHECK-LABEL: @test_vdup_n_f16(
// CHECK:   [[TMP0:%.*]] = load half, ptr %a, align 2
// CHECK:   [[VECINIT:%.*]] = insertelement <4 x half> undef, half [[TMP0]], i32 0
// CHECK:   [[VECINIT1:%.*]] = insertelement <4 x half> [[VECINIT]], half [[TMP0]], i32 1
// CHECK:   [[VECINIT2:%.*]] = insertelement <4 x half> [[VECINIT1]], half [[TMP0]], i32 2
// CHECK:   [[VECINIT3:%.*]] = insertelement <4 x half> [[VECINIT2]], half [[TMP0]], i32 3
// CHECK:   ret <4 x half> [[VECINIT3]]
float16x4_t test_vdup_n_f16(float16_t *a) {
  return vdup_n_f16(*a);
}

// CHECK-LABEL: @test_vdup_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x float> undef, float %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x float> [[VECINIT_I]], float %a, i32 1
// CHECK:   ret <2 x float> [[VECINIT1_I]]
float32x2_t test_vdup_n_f32(float32_t a) {
  return vdup_n_f32(a);
}

// CHECK-LABEL: @test_vdupq_n_u8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <16 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <16 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <16 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <16 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <16 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <16 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <16 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <16 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   [[VECINIT8_I:%.*]] = insertelement <16 x i8> [[VECINIT7_I]], i8 %a, i32 8
// CHECK:   [[VECINIT9_I:%.*]] = insertelement <16 x i8> [[VECINIT8_I]], i8 %a, i32 9
// CHECK:   [[VECINIT10_I:%.*]] = insertelement <16 x i8> [[VECINIT9_I]], i8 %a, i32 10
// CHECK:   [[VECINIT11_I:%.*]] = insertelement <16 x i8> [[VECINIT10_I]], i8 %a, i32 11
// CHECK:   [[VECINIT12_I:%.*]] = insertelement <16 x i8> [[VECINIT11_I]], i8 %a, i32 12
// CHECK:   [[VECINIT13_I:%.*]] = insertelement <16 x i8> [[VECINIT12_I]], i8 %a, i32 13
// CHECK:   [[VECINIT14_I:%.*]] = insertelement <16 x i8> [[VECINIT13_I]], i8 %a, i32 14
// CHECK:   [[VECINIT15_I:%.*]] = insertelement <16 x i8> [[VECINIT14_I]], i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VECINIT15_I]]
uint8x16_t test_vdupq_n_u8(uint8_t a) {
  return vdupq_n_u8(a);
}

// CHECK-LABEL: @test_vdupq_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VECINIT7_I]]
uint16x8_t test_vdupq_n_u16(uint16_t a) {
  return vdupq_n_u16(a);
}

// CHECK-LABEL: @test_vdupq_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %a, i32 3
// CHECK:   ret <4 x i32> [[VECINIT3_I]]
uint32x4_t test_vdupq_n_u32(uint32_t a) {
  return vdupq_n_u32(a);
}

// CHECK-LABEL: @test_vdupq_n_s8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <16 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <16 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <16 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <16 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <16 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <16 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <16 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <16 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   [[VECINIT8_I:%.*]] = insertelement <16 x i8> [[VECINIT7_I]], i8 %a, i32 8
// CHECK:   [[VECINIT9_I:%.*]] = insertelement <16 x i8> [[VECINIT8_I]], i8 %a, i32 9
// CHECK:   [[VECINIT10_I:%.*]] = insertelement <16 x i8> [[VECINIT9_I]], i8 %a, i32 10
// CHECK:   [[VECINIT11_I:%.*]] = insertelement <16 x i8> [[VECINIT10_I]], i8 %a, i32 11
// CHECK:   [[VECINIT12_I:%.*]] = insertelement <16 x i8> [[VECINIT11_I]], i8 %a, i32 12
// CHECK:   [[VECINIT13_I:%.*]] = insertelement <16 x i8> [[VECINIT12_I]], i8 %a, i32 13
// CHECK:   [[VECINIT14_I:%.*]] = insertelement <16 x i8> [[VECINIT13_I]], i8 %a, i32 14
// CHECK:   [[VECINIT15_I:%.*]] = insertelement <16 x i8> [[VECINIT14_I]], i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VECINIT15_I]]
int8x16_t test_vdupq_n_s8(int8_t a) {
  return vdupq_n_s8(a);
}

// CHECK-LABEL: @test_vdupq_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VECINIT7_I]]
int16x8_t test_vdupq_n_s16(int16_t a) {
  return vdupq_n_s16(a);
}

// CHECK-LABEL: @test_vdupq_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %a, i32 3
// CHECK:   ret <4 x i32> [[VECINIT3_I]]
int32x4_t test_vdupq_n_s32(int32_t a) {
  return vdupq_n_s32(a);
}

// CHECK-LABEL: @test_vdupq_n_p8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <16 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <16 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <16 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <16 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <16 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <16 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <16 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <16 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   [[VECINIT8_I:%.*]] = insertelement <16 x i8> [[VECINIT7_I]], i8 %a, i32 8
// CHECK:   [[VECINIT9_I:%.*]] = insertelement <16 x i8> [[VECINIT8_I]], i8 %a, i32 9
// CHECK:   [[VECINIT10_I:%.*]] = insertelement <16 x i8> [[VECINIT9_I]], i8 %a, i32 10
// CHECK:   [[VECINIT11_I:%.*]] = insertelement <16 x i8> [[VECINIT10_I]], i8 %a, i32 11
// CHECK:   [[VECINIT12_I:%.*]] = insertelement <16 x i8> [[VECINIT11_I]], i8 %a, i32 12
// CHECK:   [[VECINIT13_I:%.*]] = insertelement <16 x i8> [[VECINIT12_I]], i8 %a, i32 13
// CHECK:   [[VECINIT14_I:%.*]] = insertelement <16 x i8> [[VECINIT13_I]], i8 %a, i32 14
// CHECK:   [[VECINIT15_I:%.*]] = insertelement <16 x i8> [[VECINIT14_I]], i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VECINIT15_I]]
poly8x16_t test_vdupq_n_p8(poly8_t a) {
  return vdupq_n_p8(a);
}

// CHECK-LABEL: @test_vdupq_n_p16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VECINIT7_I]]
poly16x8_t test_vdupq_n_p16(poly16_t a) {
  return vdupq_n_p16(a);
}

// CHECK-LABEL: @test_vdupq_n_f16(
// CHECK:   [[TMP0:%.*]] = load half, ptr %a, align 2
// CHECK:   [[VECINIT:%.*]] = insertelement <8 x half> undef, half [[TMP0]], i32 0
// CHECK:   [[VECINIT1:%.*]] = insertelement <8 x half> [[VECINIT]], half [[TMP0]], i32 1
// CHECK:   [[VECINIT2:%.*]] = insertelement <8 x half> [[VECINIT1]], half [[TMP0]], i32 2
// CHECK:   [[VECINIT3:%.*]] = insertelement <8 x half> [[VECINIT2]], half [[TMP0]], i32 3
// CHECK:   [[VECINIT4:%.*]] = insertelement <8 x half> [[VECINIT3]], half [[TMP0]], i32 4
// CHECK:   [[VECINIT5:%.*]] = insertelement <8 x half> [[VECINIT4]], half [[TMP0]], i32 5
// CHECK:   [[VECINIT6:%.*]] = insertelement <8 x half> [[VECINIT5]], half [[TMP0]], i32 6
// CHECK:   [[VECINIT7:%.*]] = insertelement <8 x half> [[VECINIT6]], half [[TMP0]], i32 7
// CHECK:   ret <8 x half> [[VECINIT7]]
float16x8_t test_vdupq_n_f16(float16_t *a) {
  return vdupq_n_f16(*a);
}

// CHECK-LABEL: @test_vdupq_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x float> undef, float %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x float> [[VECINIT_I]], float %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x float> [[VECINIT1_I]], float %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x float> [[VECINIT2_I]], float %a, i32 3
// CHECK:   ret <4 x float> [[VECINIT3_I]]
float32x4_t test_vdupq_n_f32(float32_t a) {
  return vdupq_n_f32(a);
}

// CHECK-LABEL: @test_vdup_n_s64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <1 x i64> undef, i64 %a, i32 0
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> [[VECINIT_I]], [[VECINIT_I]]
// CHECK:   ret <1 x i64> [[ADD_I]]
int64x1_t test_vdup_n_s64(int64_t a) {
  int64x1_t tmp = vdup_n_s64(a);
  return vadd_s64(tmp, tmp);
}

// CHECK-LABEL: @test_vdup_n_u64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <1 x i64> undef, i64 %a, i32 0
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> [[VECINIT_I]], [[VECINIT_I]]
// CHECK:   ret <1 x i64> [[ADD_I]]
int64x1_t test_vdup_n_u64(uint64_t a) {
  int64x1_t tmp = (int64x1_t)vdup_n_u64(a);
  return vadd_s64(tmp, tmp);
}

// CHECK-LABEL: @test_vdupq_n_s64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i64> undef, i64 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i64> [[VECINIT_I]], i64 %a, i32 1
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> [[VECINIT1_I]], [[VECINIT1_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
int64x2_t test_vdupq_n_s64(int64_t a) {
  int64x2_t tmp = vdupq_n_s64(a);
  return vaddq_s64(tmp, tmp);
}

// CHECK-LABEL: @test_vdupq_n_u64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i64> undef, i64 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i64> [[VECINIT_I]], i64 %a, i32 1
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> [[VECINIT1_I]], [[VECINIT1_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
uint64x2_t test_vdupq_n_u64(uint64_t a) {
  uint64x2_t tmp = vdupq_n_u64(a);
  return vaddq_u64(tmp, tmp);
}

// CHECK-LABEL: @test_veor_s8(
// CHECK:   [[XOR_I:%.*]] = xor <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[XOR_I]]
int8x8_t test_veor_s8(int8x8_t a, int8x8_t b) {
  return veor_s8(a, b);
}

// CHECK-LABEL: @test_veor_s16(
// CHECK:   [[XOR_I:%.*]] = xor <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[XOR_I]]
int16x4_t test_veor_s16(int16x4_t a, int16x4_t b) {
  return veor_s16(a, b);
}

// CHECK-LABEL: @test_veor_s32(
// CHECK:   [[XOR_I:%.*]] = xor <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[XOR_I]]
int32x2_t test_veor_s32(int32x2_t a, int32x2_t b) {
  return veor_s32(a, b);
}

// CHECK-LABEL: @test_veor_s64(
// CHECK:   [[XOR_I:%.*]] = xor <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[XOR_I]]
int64x1_t test_veor_s64(int64x1_t a, int64x1_t b) {
  return veor_s64(a, b);
}

// CHECK-LABEL: @test_veor_u8(
// CHECK:   [[XOR_I:%.*]] = xor <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[XOR_I]]
uint8x8_t test_veor_u8(uint8x8_t a, uint8x8_t b) {
  return veor_u8(a, b);
}

// CHECK-LABEL: @test_veor_u16(
// CHECK:   [[XOR_I:%.*]] = xor <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[XOR_I]]
uint16x4_t test_veor_u16(uint16x4_t a, uint16x4_t b) {
  return veor_u16(a, b);
}

// CHECK-LABEL: @test_veor_u32(
// CHECK:   [[XOR_I:%.*]] = xor <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[XOR_I]]
uint32x2_t test_veor_u32(uint32x2_t a, uint32x2_t b) {
  return veor_u32(a, b);
}

// CHECK-LABEL: @test_veor_u64(
// CHECK:   [[XOR_I:%.*]] = xor <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[XOR_I]]
uint64x1_t test_veor_u64(uint64x1_t a, uint64x1_t b) {
  return veor_u64(a, b);
}

// CHECK-LABEL: @test_veorq_s8(
// CHECK:   [[XOR_I:%.*]] = xor <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[XOR_I]]
int8x16_t test_veorq_s8(int8x16_t a, int8x16_t b) {
  return veorq_s8(a, b);
}

// CHECK-LABEL: @test_veorq_s16(
// CHECK:   [[XOR_I:%.*]] = xor <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[XOR_I]]
int16x8_t test_veorq_s16(int16x8_t a, int16x8_t b) {
  return veorq_s16(a, b);
}

// CHECK-LABEL: @test_veorq_s32(
// CHECK:   [[XOR_I:%.*]] = xor <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[XOR_I]]
int32x4_t test_veorq_s32(int32x4_t a, int32x4_t b) {
  return veorq_s32(a, b);
}

// CHECK-LABEL: @test_veorq_s64(
// CHECK:   [[XOR_I:%.*]] = xor <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[XOR_I]]
int64x2_t test_veorq_s64(int64x2_t a, int64x2_t b) {
  return veorq_s64(a, b);
}

// CHECK-LABEL: @test_veorq_u8(
// CHECK:   [[XOR_I:%.*]] = xor <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[XOR_I]]
uint8x16_t test_veorq_u8(uint8x16_t a, uint8x16_t b) {
  return veorq_u8(a, b);
}

// CHECK-LABEL: @test_veorq_u16(
// CHECK:   [[XOR_I:%.*]] = xor <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[XOR_I]]
uint16x8_t test_veorq_u16(uint16x8_t a, uint16x8_t b) {
  return veorq_u16(a, b);
}

// CHECK-LABEL: @test_veorq_u32(
// CHECK:   [[XOR_I:%.*]] = xor <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[XOR_I]]
uint32x4_t test_veorq_u32(uint32x4_t a, uint32x4_t b) {
  return veorq_u32(a, b);
}

// CHECK-LABEL: @test_veorq_u64(
// CHECK:   [[XOR_I:%.*]] = xor <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[XOR_I]]
uint64x2_t test_veorq_u64(uint64x2_t a, uint64x2_t b) {
  return veorq_u64(a, b);
}

// CHECK-LABEL: @test_vext_s8(
// CHECK:   [[VEXT:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14>
// CHECK:   ret <8 x i8> [[VEXT]]
int8x8_t test_vext_s8(int8x8_t a, int8x8_t b) {
  return vext_s8(a, b, 7);
}

// CHECK-LABEL: @test_vext_u8(
// CHECK:   [[VEXT:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14>
// CHECK:   ret <8 x i8> [[VEXT]]
uint8x8_t test_vext_u8(uint8x8_t a, uint8x8_t b) {
  return vext_u8(a, b, 7);
}

// CHECK-LABEL: @test_vext_p8(
// CHECK:   [[VEXT:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14>
// CHECK:   ret <8 x i8> [[VEXT]]
poly8x8_t test_vext_p8(poly8x8_t a, poly8x8_t b) {
  return vext_p8(a, b, 7);
}

// CHECK-LABEL: @test_vext_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VEXT:%.*]] = shufflevector <4 x i16> [[TMP2]], <4 x i16> [[TMP3]], <4 x i32> <i32 3, i32 4, i32 5, i32 6>
// CHECK:   ret <4 x i16> [[VEXT]]
int16x4_t test_vext_s16(int16x4_t a, int16x4_t b) {
  return vext_s16(a, b, 3);
}

// CHECK-LABEL: @test_vext_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VEXT:%.*]] = shufflevector <4 x i16> [[TMP2]], <4 x i16> [[TMP3]], <4 x i32> <i32 3, i32 4, i32 5, i32 6>
// CHECK:   ret <4 x i16> [[VEXT]]
uint16x4_t test_vext_u16(uint16x4_t a, uint16x4_t b) {
  return vext_u16(a, b, 3);
}

// CHECK-LABEL: @test_vext_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VEXT:%.*]] = shufflevector <4 x i16> [[TMP2]], <4 x i16> [[TMP3]], <4 x i32> <i32 3, i32 4, i32 5, i32 6>
// CHECK:   ret <4 x i16> [[VEXT]]
poly16x4_t test_vext_p16(poly16x4_t a, poly16x4_t b) {
  return vext_p16(a, b, 3);
}

// CHECK-LABEL: @test_vext_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VEXT:%.*]] = shufflevector <2 x i32> [[TMP2]], <2 x i32> [[TMP3]], <2 x i32> <i32 1, i32 2>
// CHECK:   ret <2 x i32> [[VEXT]]
int32x2_t test_vext_s32(int32x2_t a, int32x2_t b) {
  return vext_s32(a, b, 1);
}

// CHECK-LABEL: @test_vext_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VEXT:%.*]] = shufflevector <2 x i32> [[TMP2]], <2 x i32> [[TMP3]], <2 x i32> <i32 1, i32 2>
// CHECK:   ret <2 x i32> [[VEXT]]
uint32x2_t test_vext_u32(uint32x2_t a, uint32x2_t b) {
  return vext_u32(a, b, 1);
}

// CHECK-LABEL: @test_vext_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VEXT:%.*]] = shufflevector <1 x i64> [[TMP2]], <1 x i64> [[TMP3]], <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[VEXT]]
int64x1_t test_vext_s64(int64x1_t a, int64x1_t b) {
  return vext_s64(a, b, 0);
}

// CHECK-LABEL: @test_vext_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VEXT:%.*]] = shufflevector <1 x i64> [[TMP2]], <1 x i64> [[TMP3]], <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[VEXT]]
uint64x1_t test_vext_u64(uint64x1_t a, uint64x1_t b) {
  return vext_u64(a, b, 0);
}

// CHECK-LABEL: @test_vext_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x float>
// CHECK:   [[VEXT:%.*]] = shufflevector <2 x float> [[TMP2]], <2 x float> [[TMP3]], <2 x i32> <i32 1, i32 2>
// CHECK:   ret <2 x float> [[VEXT]]
float32x2_t test_vext_f32(float32x2_t a, float32x2_t b) {
  return vext_f32(a, b, 1);
}

// CHECK-LABEL: @test_vextq_s8(
// CHECK:   [[VEXT:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 15, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30>
// CHECK:   ret <16 x i8> [[VEXT]]
int8x16_t test_vextq_s8(int8x16_t a, int8x16_t b) {
  return vextq_s8(a, b, 15);
}

// CHECK-LABEL: @test_vextq_u8(
// CHECK:   [[VEXT:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 15, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30>
// CHECK:   ret <16 x i8> [[VEXT]]
uint8x16_t test_vextq_u8(uint8x16_t a, uint8x16_t b) {
  return vextq_u8(a, b, 15);
}

// CHECK-LABEL: @test_vextq_p8(
// CHECK:   [[VEXT:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 15, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30>
// CHECK:   ret <16 x i8> [[VEXT]]
poly8x16_t test_vextq_p8(poly8x16_t a, poly8x16_t b) {
  return vextq_p8(a, b, 15);
}

// CHECK-LABEL: @test_vextq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VEXT:%.*]] = shufflevector <8 x i16> [[TMP2]], <8 x i16> [[TMP3]], <8 x i32> <i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14>
// CHECK:   ret <8 x i16> [[VEXT]]
int16x8_t test_vextq_s16(int16x8_t a, int16x8_t b) {
  return vextq_s16(a, b, 7);
}

// CHECK-LABEL: @test_vextq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VEXT:%.*]] = shufflevector <8 x i16> [[TMP2]], <8 x i16> [[TMP3]], <8 x i32> <i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14>
// CHECK:   ret <8 x i16> [[VEXT]]
uint16x8_t test_vextq_u16(uint16x8_t a, uint16x8_t b) {
  return vextq_u16(a, b, 7);
}

// CHECK-LABEL: @test_vextq_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VEXT:%.*]] = shufflevector <8 x i16> [[TMP2]], <8 x i16> [[TMP3]], <8 x i32> <i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14>
// CHECK:   ret <8 x i16> [[VEXT]]
poly16x8_t test_vextq_p16(poly16x8_t a, poly16x8_t b) {
  return vextq_p16(a, b, 7);
}

// CHECK-LABEL: @test_vextq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VEXT:%.*]] = shufflevector <4 x i32> [[TMP2]], <4 x i32> [[TMP3]], <4 x i32> <i32 3, i32 4, i32 5, i32 6>
// CHECK:   ret <4 x i32> [[VEXT]]
int32x4_t test_vextq_s32(int32x4_t a, int32x4_t b) {
  return vextq_s32(a, b, 3);
}

// CHECK-LABEL: @test_vextq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VEXT:%.*]] = shufflevector <4 x i32> [[TMP2]], <4 x i32> [[TMP3]], <4 x i32> <i32 3, i32 4, i32 5, i32 6>
// CHECK:   ret <4 x i32> [[VEXT]]
uint32x4_t test_vextq_u32(uint32x4_t a, uint32x4_t b) {
  return vextq_u32(a, b, 3);
}

// CHECK-LABEL: @test_vextq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VEXT:%.*]] = shufflevector <2 x i64> [[TMP2]], <2 x i64> [[TMP3]], <2 x i32> <i32 1, i32 2>
// CHECK:   ret <2 x i64> [[VEXT]]
int64x2_t test_vextq_s64(int64x2_t a, int64x2_t b) {
  return vextq_s64(a, b, 1);
}

// CHECK-LABEL: @test_vextq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VEXT:%.*]] = shufflevector <2 x i64> [[TMP2]], <2 x i64> [[TMP3]], <2 x i32> <i32 1, i32 2>
// CHECK:   ret <2 x i64> [[VEXT]]
uint64x2_t test_vextq_u64(uint64x2_t a, uint64x2_t b) {
  return vextq_u64(a, b, 1);
}

// CHECK-LABEL: @test_vextq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x float>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x float>
// CHECK:   [[VEXT:%.*]] = shufflevector <4 x float> [[TMP2]], <4 x float> [[TMP3]], <4 x i32> <i32 3, i32 4, i32 5, i32 6>
// CHECK:   ret <4 x float> [[VEXT]]
float32x4_t test_vextq_f32(float32x4_t a, float32x4_t b) {
  return vextq_f32(a, b, 3);
}

// CHECK-LABEL: @test_vfma_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x float> %c to <8 x i8>
// CHECK:   [[TMP3:%.*]] = call <2 x float> @llvm.fma.v2f32(<2 x float> %b, <2 x float> %c, <2 x float> %a)
// CHECK:   ret <2 x float> [[TMP3]]
float32x2_t test_vfma_f32(float32x2_t a, float32x2_t b, float32x2_t c) {
  return vfma_f32(a, b, c);
}

// CHECK-LABEL: @test_vfmaq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x float> %c to <16 x i8>
// CHECK:   [[TMP3:%.*]] = call <4 x float> @llvm.fma.v4f32(<4 x float> %b, <4 x float> %c, <4 x float> %a)
// CHECK:   ret <4 x float> [[TMP3]]
float32x4_t test_vfmaq_f32(float32x4_t a, float32x4_t b, float32x4_t c) {
  return vfmaq_f32(a, b, c);
}

// CHECK-LABEL: @test_vfms_f32(
// CHECK:   [[SUB_I:%.*]] = fneg <2 x float> %b
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> [[SUB_I]] to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x float> %c to <8 x i8>
// CHECK:   [[TMP3:%.*]] = call <2 x float> @llvm.fma.v2f32(<2 x float> [[SUB_I]], <2 x float> %c, <2 x float> %a)
// CHECK:   ret <2 x float> [[TMP3]]
float32x2_t test_vfms_f32(float32x2_t a, float32x2_t b, float32x2_t c) {
  return vfms_f32(a, b, c);
}

// CHECK-LABEL: @test_vfmsq_f32(
// CHECK:   [[SUB_I:%.*]] = fneg <4 x float> %b
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> [[SUB_I]] to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x float> %c to <16 x i8>
// CHECK:   [[TMP3:%.*]] = call <4 x float> @llvm.fma.v4f32(<4 x float> [[SUB_I]], <4 x float> %c, <4 x float> %a)
// CHECK:   ret <4 x float> [[TMP3]]
float32x4_t test_vfmsq_f32(float32x4_t a, float32x4_t b, float32x4_t c) {
  return vfmsq_f32(a, b, c);
}

// CHECK-LABEL: @test_vget_high_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <8 x i32> <i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
int8x8_t test_vget_high_s8(int8x16_t a) {
  return vget_high_s8(a);
}

// CHECK-LABEL: @test_vget_high_s16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <4 x i32> <i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
int16x4_t test_vget_high_s16(int16x8_t a) {
  return vget_high_s16(a);
}

// CHECK-LABEL: @test_vget_high_s32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %a, <2 x i32> <i32 2, i32 3>
// CHECK:   ret <2 x i32> [[SHUFFLE_I]]
int32x2_t test_vget_high_s32(int32x4_t a) {
  return vget_high_s32(a);
}

// CHECK-LABEL: @test_vget_high_s64(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i64> %a, <2 x i64> %a, <1 x i32> <i32 1>
// CHECK:   ret <1 x i64> [[SHUFFLE_I]]
int64x1_t test_vget_high_s64(int64x2_t a) {
  return vget_high_s64(a);
}

// CHECK-LABEL: @test_vget_high_f16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x half> %a, <8 x half> %a, <4 x i32> <i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <4 x half> [[SHUFFLE_I]]
float16x4_t test_vget_high_f16(float16x8_t a) {
  return vget_high_f16(a);
}

// CHECK-LABEL: @test_vget_high_f32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %a, <2 x i32> <i32 2, i32 3>
// CHECK:   ret <2 x float> [[SHUFFLE_I]]
float32x2_t test_vget_high_f32(float32x4_t a) {
  return vget_high_f32(a);
}

// CHECK-LABEL: @test_vget_high_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <8 x i32> <i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
uint8x8_t test_vget_high_u8(uint8x16_t a) {
  return vget_high_u8(a);
}

// CHECK-LABEL: @test_vget_high_u16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <4 x i32> <i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
uint16x4_t test_vget_high_u16(uint16x8_t a) {
  return vget_high_u16(a);
}

// CHECK-LABEL: @test_vget_high_u32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %a, <2 x i32> <i32 2, i32 3>
// CHECK:   ret <2 x i32> [[SHUFFLE_I]]
uint32x2_t test_vget_high_u32(uint32x4_t a) {
  return vget_high_u32(a);
}

// CHECK-LABEL: @test_vget_high_u64(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i64> %a, <2 x i64> %a, <1 x i32> <i32 1>
// CHECK:   ret <1 x i64> [[SHUFFLE_I]]
uint64x1_t test_vget_high_u64(uint64x2_t a) {
  return vget_high_u64(a);
}

// CHECK-LABEL: @test_vget_high_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <8 x i32> <i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
poly8x8_t test_vget_high_p8(poly8x16_t a) {
  return vget_high_p8(a);
}

// CHECK-LABEL: @test_vget_high_p16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <4 x i32> <i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
poly16x4_t test_vget_high_p16(poly16x8_t a) {
  return vget_high_p16(a);
}

// CHECK-LABEL: @test_vget_lane_u8(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <8 x i8> %a, i32 7
// CHECK:   ret i8 [[VGET_LANE]]
uint8_t test_vget_lane_u8(uint8x8_t a) {
  return vget_lane_u8(a, 7);
}

// CHECK-LABEL: @test_vget_lane_u16(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <4 x i16> %a, i32 3
// CHECK:   ret i16 [[VGET_LANE]]
uint16_t test_vget_lane_u16(uint16x4_t a) {
  return vget_lane_u16(a, 3);
}

// CHECK-LABEL: @test_vget_lane_u32(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <2 x i32> %a, i32 1
// CHECK:   ret i32 [[VGET_LANE]]
uint32_t test_vget_lane_u32(uint32x2_t a) {
  return vget_lane_u32(a, 1);
}

// CHECK-LABEL: @test_vget_lane_s8(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <8 x i8> %a, i32 7
// CHECK:   ret i8 [[VGET_LANE]]
int8_t test_vget_lane_s8(int8x8_t a) {
  return vget_lane_s8(a, 7);
}

// CHECK-LABEL: @test_vget_lane_s16(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <4 x i16> %a, i32 3
// CHECK:   ret i16 [[VGET_LANE]]
int16_t test_vget_lane_s16(int16x4_t a) {
  return vget_lane_s16(a, 3);
}

// CHECK-LABEL: @test_vget_lane_s32(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <2 x i32> %a, i32 1
// CHECK:   ret i32 [[VGET_LANE]]
int32_t test_vget_lane_s32(int32x2_t a) {
  return vget_lane_s32(a, 1);
}

// CHECK-LABEL: @test_vget_lane_p8(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <8 x i8> %a, i32 7
// CHECK:   ret i8 [[VGET_LANE]]
poly8_t test_vget_lane_p8(poly8x8_t a) {
  return vget_lane_p8(a, 7);
}

// CHECK-LABEL: @test_vget_lane_p16(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <4 x i16> %a, i32 3
// CHECK:   ret i16 [[VGET_LANE]]
poly16_t test_vget_lane_p16(poly16x4_t a) {
  return vget_lane_p16(a, 3);
}

// CHECK-LABEL: @test_vget_lane_f32(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <2 x float> %a, i32 1
// CHECK:   ret float [[VGET_LANE]]
float32_t test_vget_lane_f32(float32x2_t a) {
  return vget_lane_f32(a, 1);
}

// CHECK-LABEL: @test_vget_lane_f16(
// CHECK:   [[__REINT_242:%.*]] = alloca <4 x half>, align 8
// CHECK:   [[__REINT1_242:%.*]] = alloca i16, align 2
// CHECK:   store <4 x half> %a, ptr [[__REINT_242]], align 8
// CHECK:   [[TMP1:%.*]] = load <4 x i16>, ptr [[__REINT_242]], align 8
// CHECK:   [[VGET_LANE:%.*]] = extractelement <4 x i16> [[TMP1]], i32 1
// CHECK:   store i16 [[VGET_LANE]], ptr [[__REINT1_242]], align 2
// CHECK:   [[TMP5:%.*]] = load half, ptr [[__REINT1_242]], align 2
// CHECK:   [[CONV:%.*]] = fpext half [[TMP5]] to float
// CHECK:   ret float [[CONV]]
float32_t test_vget_lane_f16(float16x4_t a) {
  return vget_lane_f16(a, 1);
}

// CHECK-LABEL: @test_vgetq_lane_u8(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <16 x i8> %a, i32 15
// CHECK:   ret i8 [[VGET_LANE]]
uint8_t test_vgetq_lane_u8(uint8x16_t a) {
  return vgetq_lane_u8(a, 15);
}

// CHECK-LABEL: @test_vgetq_lane_u16(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <8 x i16> %a, i32 7
// CHECK:   ret i16 [[VGET_LANE]]
uint16_t test_vgetq_lane_u16(uint16x8_t a) {
  return vgetq_lane_u16(a, 7);
}

// CHECK-LABEL: @test_vgetq_lane_u32(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <4 x i32> %a, i32 3
// CHECK:   ret i32 [[VGET_LANE]]
uint32_t test_vgetq_lane_u32(uint32x4_t a) {
  return vgetq_lane_u32(a, 3);
}

// CHECK-LABEL: @test_vgetq_lane_s8(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <16 x i8> %a, i32 15
// CHECK:   ret i8 [[VGET_LANE]]
int8_t test_vgetq_lane_s8(int8x16_t a) {
  return vgetq_lane_s8(a, 15);
}

// CHECK-LABEL: @test_vgetq_lane_s16(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <8 x i16> %a, i32 7
// CHECK:   ret i16 [[VGET_LANE]]
int16_t test_vgetq_lane_s16(int16x8_t a) {
  return vgetq_lane_s16(a, 7);
}

// CHECK-LABEL: @test_vgetq_lane_s32(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <4 x i32> %a, i32 3
// CHECK:   ret i32 [[VGET_LANE]]
int32_t test_vgetq_lane_s32(int32x4_t a) {
  return vgetq_lane_s32(a, 3);
}

// CHECK-LABEL: @test_vgetq_lane_p8(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <16 x i8> %a, i32 15
// CHECK:   ret i8 [[VGET_LANE]]
poly8_t test_vgetq_lane_p8(poly8x16_t a) {
  return vgetq_lane_p8(a, 15);
}

// CHECK-LABEL: @test_vgetq_lane_p16(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <8 x i16> %a, i32 7
// CHECK:   ret i16 [[VGET_LANE]]
poly16_t test_vgetq_lane_p16(poly16x8_t a) {
  return vgetq_lane_p16(a, 7);
}

// CHECK-LABEL: @test_vgetq_lane_f32(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <4 x float> %a, i32 3
// CHECK:   ret float [[VGET_LANE]]
float32_t test_vgetq_lane_f32(float32x4_t a) {
  return vgetq_lane_f32(a, 3);
}

// CHECK-LABEL: @test_vgetq_lane_f16(
// CHECK:   [[__REINT_244:%.*]] = alloca <8 x half>, align 16
// CHECK:   [[__REINT1_244:%.*]] = alloca i16, align 2
// CHECK:   store <8 x half> %a, ptr [[__REINT_244]], align 16
// CHECK:   [[TMP1:%.*]] = load <8 x i16>, ptr [[__REINT_244]], align 16
// CHECK:   [[VGET_LANE:%.*]] = extractelement <8 x i16> [[TMP1]], i32 3
// CHECK:   store i16 [[VGET_LANE]], ptr [[__REINT1_244]], align 2
// CHECK:   [[TMP5:%.*]] = load half, ptr [[__REINT1_244]], align 2
// CHECK:   [[CONV:%.*]] = fpext half [[TMP5]] to float
// CHECK:   ret float [[CONV]]
float32_t test_vgetq_lane_f16(float16x8_t a) {
  return vgetq_lane_f16(a, 3);
}

// CHECK-LABEL: @test_vget_lane_s64(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <1 x i64> %a, i32 0
// CHECK:   ret i64 [[VGET_LANE]]
int64_t test_vget_lane_s64(int64x1_t a) {
  return vget_lane_s64(a, 0);
}

// CHECK-LABEL: @test_vget_lane_u64(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <1 x i64> %a, i32 0
// CHECK:   ret i64 [[VGET_LANE]]
uint64_t test_vget_lane_u64(uint64x1_t a) {
  return vget_lane_u64(a, 0);
}

// CHECK-LABEL: @test_vgetq_lane_s64(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <2 x i64> %a, i32 1
// CHECK:   ret i64 [[VGET_LANE]]
int64_t test_vgetq_lane_s64(int64x2_t a) {
  return vgetq_lane_s64(a, 1);
}

// CHECK-LABEL: @test_vgetq_lane_u64(
// CHECK:   [[VGET_LANE:%.*]] = extractelement <2 x i64> %a, i32 1
// CHECK:   ret i64 [[VGET_LANE]]
uint64_t test_vgetq_lane_u64(uint64x2_t a) {
  return vgetq_lane_u64(a, 1);
}

// CHECK-LABEL: @test_vget_low_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
int8x8_t test_vget_low_s8(int8x16_t a) {
  return vget_low_s8(a);
}

// CHECK-LABEL: @test_vget_low_s16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
int16x4_t test_vget_low_s16(int16x8_t a) {
  return vget_low_s16(a);
}

// CHECK-LABEL: @test_vget_low_s32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %a, <2 x i32> <i32 0, i32 1>
// CHECK:   ret <2 x i32> [[SHUFFLE_I]]
int32x2_t test_vget_low_s32(int32x4_t a) {
  return vget_low_s32(a);
}

// CHECK-LABEL: @test_vget_low_s64(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i64> %a, <2 x i64> %a, <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[SHUFFLE_I]]
int64x1_t test_vget_low_s64(int64x2_t a) {
  return vget_low_s64(a);
}

// CHECK-LABEL: @test_vget_low_f16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x half> %a, <8 x half> %a, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
// CHECK:   ret <4 x half> [[SHUFFLE_I]]
float16x4_t test_vget_low_f16(float16x8_t a) {
  return vget_low_f16(a);
}

// CHECK-LABEL: @test_vget_low_f32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %a, <2 x i32> <i32 0, i32 1>
// CHECK:   ret <2 x float> [[SHUFFLE_I]]
float32x2_t test_vget_low_f32(float32x4_t a) {
  return vget_low_f32(a);
}

// CHECK-LABEL: @test_vget_low_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
uint8x8_t test_vget_low_u8(uint8x16_t a) {
  return vget_low_u8(a);
}

// CHECK-LABEL: @test_vget_low_u16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
uint16x4_t test_vget_low_u16(uint16x8_t a) {
  return vget_low_u16(a);
}

// CHECK-LABEL: @test_vget_low_u32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %a, <2 x i32> <i32 0, i32 1>
// CHECK:   ret <2 x i32> [[SHUFFLE_I]]
uint32x2_t test_vget_low_u32(uint32x4_t a) {
  return vget_low_u32(a);
}

// CHECK-LABEL: @test_vget_low_u64(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i64> %a, <2 x i64> %a, <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[SHUFFLE_I]]
uint64x1_t test_vget_low_u64(uint64x2_t a) {
  return vget_low_u64(a);
}

// CHECK-LABEL: @test_vget_low_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
poly8x8_t test_vget_low_p8(poly8x16_t a) {
  return vget_low_p8(a);
}

// CHECK-LABEL: @test_vget_low_p16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <4 x i32> <i32 0, i32 1, i32 2, i32 3>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
poly16x4_t test_vget_low_p16(poly16x8_t a) {
  return vget_low_p16(a);
}

// CHECK-LABEL: @test_vhadd_s8(
// CHECK:   [[VHADD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vhadds.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VHADD_V_I]]
int8x8_t test_vhadd_s8(int8x8_t a, int8x8_t b) {
  return vhadd_s8(a, b);
}

// CHECK-LABEL: @test_vhadd_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VHADD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vhadds.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VHADD_V3_I:%.*]] = bitcast <4 x i16> [[VHADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VHADD_V2_I]]
int16x4_t test_vhadd_s16(int16x4_t a, int16x4_t b) {
  return vhadd_s16(a, b);
}

// CHECK-LABEL: @test_vhadd_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VHADD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vhadds.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VHADD_V3_I:%.*]] = bitcast <2 x i32> [[VHADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VHADD_V2_I]]
int32x2_t test_vhadd_s32(int32x2_t a, int32x2_t b) {
  return vhadd_s32(a, b);
}

// CHECK-LABEL: @test_vhadd_u8(
// CHECK:   [[VHADD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vhaddu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VHADD_V_I]]
uint8x8_t test_vhadd_u8(uint8x8_t a, uint8x8_t b) {
  return vhadd_u8(a, b);
}

// CHECK-LABEL: @test_vhadd_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VHADD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vhaddu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VHADD_V3_I:%.*]] = bitcast <4 x i16> [[VHADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VHADD_V2_I]]
uint16x4_t test_vhadd_u16(uint16x4_t a, uint16x4_t b) {
  return vhadd_u16(a, b);
}

// CHECK-LABEL: @test_vhadd_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VHADD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vhaddu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VHADD_V3_I:%.*]] = bitcast <2 x i32> [[VHADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VHADD_V2_I]]
uint32x2_t test_vhadd_u32(uint32x2_t a, uint32x2_t b) {
  return vhadd_u32(a, b);
}

// CHECK-LABEL: @test_vhaddq_s8(
// CHECK:   [[VHADDQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vhadds.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VHADDQ_V_I]]
int8x16_t test_vhaddq_s8(int8x16_t a, int8x16_t b) {
  return vhaddq_s8(a, b);
}

// CHECK-LABEL: @test_vhaddq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VHADDQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vhadds.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VHADDQ_V3_I:%.*]] = bitcast <8 x i16> [[VHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VHADDQ_V2_I]]
int16x8_t test_vhaddq_s16(int16x8_t a, int16x8_t b) {
  return vhaddq_s16(a, b);
}

// CHECK-LABEL: @test_vhaddq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VHADDQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vhadds.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VHADDQ_V3_I:%.*]] = bitcast <4 x i32> [[VHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VHADDQ_V2_I]]
int32x4_t test_vhaddq_s32(int32x4_t a, int32x4_t b) {
  return vhaddq_s32(a, b);
}

// CHECK-LABEL: @test_vhaddq_u8(
// CHECK:   [[VHADDQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vhaddu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VHADDQ_V_I]]
uint8x16_t test_vhaddq_u8(uint8x16_t a, uint8x16_t b) {
  return vhaddq_u8(a, b);
}

// CHECK-LABEL: @test_vhaddq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VHADDQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vhaddu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VHADDQ_V3_I:%.*]] = bitcast <8 x i16> [[VHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VHADDQ_V2_I]]
uint16x8_t test_vhaddq_u16(uint16x8_t a, uint16x8_t b) {
  return vhaddq_u16(a, b);
}

// CHECK-LABEL: @test_vhaddq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VHADDQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vhaddu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VHADDQ_V3_I:%.*]] = bitcast <4 x i32> [[VHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VHADDQ_V2_I]]
uint32x4_t test_vhaddq_u32(uint32x4_t a, uint32x4_t b) {
  return vhaddq_u32(a, b);
}

// CHECK-LABEL: @test_vhsub_s8(
// CHECK:   [[VHSUB_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vhsubs.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VHSUB_V_I]]
int8x8_t test_vhsub_s8(int8x8_t a, int8x8_t b) {
  return vhsub_s8(a, b);
}

// CHECK-LABEL: @test_vhsub_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VHSUB_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vhsubs.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VHSUB_V3_I:%.*]] = bitcast <4 x i16> [[VHSUB_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VHSUB_V2_I]]
int16x4_t test_vhsub_s16(int16x4_t a, int16x4_t b) {
  return vhsub_s16(a, b);
}

// CHECK-LABEL: @test_vhsub_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VHSUB_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vhsubs.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VHSUB_V3_I:%.*]] = bitcast <2 x i32> [[VHSUB_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VHSUB_V2_I]]
int32x2_t test_vhsub_s32(int32x2_t a, int32x2_t b) {
  return vhsub_s32(a, b);
}

// CHECK-LABEL: @test_vhsub_u8(
// CHECK:   [[VHSUB_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vhsubu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VHSUB_V_I]]
uint8x8_t test_vhsub_u8(uint8x8_t a, uint8x8_t b) {
  return vhsub_u8(a, b);
}

// CHECK-LABEL: @test_vhsub_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VHSUB_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vhsubu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VHSUB_V3_I:%.*]] = bitcast <4 x i16> [[VHSUB_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VHSUB_V2_I]]
uint16x4_t test_vhsub_u16(uint16x4_t a, uint16x4_t b) {
  return vhsub_u16(a, b);
}

// CHECK-LABEL: @test_vhsub_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VHSUB_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vhsubu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VHSUB_V3_I:%.*]] = bitcast <2 x i32> [[VHSUB_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VHSUB_V2_I]]
uint32x2_t test_vhsub_u32(uint32x2_t a, uint32x2_t b) {
  return vhsub_u32(a, b);
}

// CHECK-LABEL: @test_vhsubq_s8(
// CHECK:   [[VHSUBQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vhsubs.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VHSUBQ_V_I]]
int8x16_t test_vhsubq_s8(int8x16_t a, int8x16_t b) {
  return vhsubq_s8(a, b);
}

// CHECK-LABEL: @test_vhsubq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VHSUBQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vhsubs.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VHSUBQ_V3_I:%.*]] = bitcast <8 x i16> [[VHSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VHSUBQ_V2_I]]
int16x8_t test_vhsubq_s16(int16x8_t a, int16x8_t b) {
  return vhsubq_s16(a, b);
}

// CHECK-LABEL: @test_vhsubq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VHSUBQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vhsubs.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VHSUBQ_V3_I:%.*]] = bitcast <4 x i32> [[VHSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VHSUBQ_V2_I]]
int32x4_t test_vhsubq_s32(int32x4_t a, int32x4_t b) {
  return vhsubq_s32(a, b);
}

// CHECK-LABEL: @test_vhsubq_u8(
// CHECK:   [[VHSUBQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vhsubu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VHSUBQ_V_I]]
uint8x16_t test_vhsubq_u8(uint8x16_t a, uint8x16_t b) {
  return vhsubq_u8(a, b);
}

// CHECK-LABEL: @test_vhsubq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VHSUBQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vhsubu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VHSUBQ_V3_I:%.*]] = bitcast <8 x i16> [[VHSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VHSUBQ_V2_I]]
uint16x8_t test_vhsubq_u16(uint16x8_t a, uint16x8_t b) {
  return vhsubq_u16(a, b);
}

// CHECK-LABEL: @test_vhsubq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VHSUBQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vhsubu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VHSUBQ_V3_I:%.*]] = bitcast <4 x i32> [[VHSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VHSUBQ_V2_I]]
uint32x4_t test_vhsubq_u32(uint32x4_t a, uint32x4_t b) {
  return vhsubq_u32(a, b);
}

// CHECK-LABEL: @test_vld1q_u8(
// CHECK:   [[VLD1:%.*]] = call <16 x i8> @llvm.arm.neon.vld1.v16i8.p0(ptr %a, i32 1)
// CHECK:   ret <16 x i8> [[VLD1]]
uint8x16_t test_vld1q_u8(uint8_t const * a) {
  return vld1q_u8(a);
}

// CHECK-LABEL: @test_vld1q_u16(
// CHECK:   [[VLD1:%.*]] = call <8 x i16> @llvm.arm.neon.vld1.v8i16.p0(ptr %a, i32 2)
// CHECK:   ret <8 x i16> [[VLD1]]
uint16x8_t test_vld1q_u16(uint16_t const * a) {
  return vld1q_u16(a);
}

// CHECK-LABEL: @test_vld1q_u32(
// CHECK:   [[VLD1:%.*]] = call <4 x i32> @llvm.arm.neon.vld1.v4i32.p0(ptr %a, i32 4)
// CHECK:   ret <4 x i32> [[VLD1]]
uint32x4_t test_vld1q_u32(uint32_t const * a) {
  return vld1q_u32(a);
}

// CHECK-LABEL: @test_vld1q_u64(
// CHECK:   [[VLD1:%.*]] = call <2 x i64> @llvm.arm.neon.vld1.v2i64.p0(ptr %a, i32 4)
// CHECK:   ret <2 x i64> [[VLD1]]
uint64x2_t test_vld1q_u64(uint64_t const * a) {
  return vld1q_u64(a);
}

// CHECK-LABEL: @test_vld1q_s8(
// CHECK:   [[VLD1:%.*]] = call <16 x i8> @llvm.arm.neon.vld1.v16i8.p0(ptr %a, i32 1)
// CHECK:   ret <16 x i8> [[VLD1]]
int8x16_t test_vld1q_s8(int8_t const * a) {
  return vld1q_s8(a);
}

// CHECK-LABEL: @test_vld1q_s16(
// CHECK:   [[VLD1:%.*]] = call <8 x i16> @llvm.arm.neon.vld1.v8i16.p0(ptr %a, i32 2)
// CHECK:   ret <8 x i16> [[VLD1]]
int16x8_t test_vld1q_s16(int16_t const * a) {
  return vld1q_s16(a);
}

// CHECK-LABEL: @test_vld1q_s32(
// CHECK:   [[VLD1:%.*]] = call <4 x i32> @llvm.arm.neon.vld1.v4i32.p0(ptr %a, i32 4)
// CHECK:   ret <4 x i32> [[VLD1]]
int32x4_t test_vld1q_s32(int32_t const * a) {
  return vld1q_s32(a);
}

// CHECK-LABEL: @test_vld1q_s64(
// CHECK:   [[VLD1:%.*]] = call <2 x i64> @llvm.arm.neon.vld1.v2i64.p0(ptr %a, i32 4)
// CHECK:   ret <2 x i64> [[VLD1]]
int64x2_t test_vld1q_s64(int64_t const * a) {
  return vld1q_s64(a);
}

// CHECK-LABEL: @test_vld1q_f16(
// CHECK:   [[VLD1:%.*]] = call <8 x half> @llvm.arm.neon.vld1.v8f16.p0(ptr %a, i32 2)
// CHECK:   ret <8 x half> [[VLD1]]
float16x8_t test_vld1q_f16(float16_t const * a) {
  return vld1q_f16(a);
}

// CHECK-LABEL: @test_vld1q_f32(
// CHECK:   [[VLD1:%.*]] = call <4 x float> @llvm.arm.neon.vld1.v4f32.p0(ptr %a, i32 4)
// CHECK:   ret <4 x float> [[VLD1]]
float32x4_t test_vld1q_f32(float32_t const * a) {
  return vld1q_f32(a);
}

// CHECK-LABEL: @test_vld1q_p8(
// CHECK:   [[VLD1:%.*]] = call <16 x i8> @llvm.arm.neon.vld1.v16i8.p0(ptr %a, i32 1)
// CHECK:   ret <16 x i8> [[VLD1]]
poly8x16_t test_vld1q_p8(poly8_t const * a) {
  return vld1q_p8(a);
}

// CHECK-LABEL: @test_vld1q_p16(
// CHECK:   [[VLD1:%.*]] = call <8 x i16> @llvm.arm.neon.vld1.v8i16.p0(ptr %a, i32 2)
// CHECK:   ret <8 x i16> [[VLD1]]
poly16x8_t test_vld1q_p16(poly16_t const * a) {
  return vld1q_p16(a);
}

// CHECK-LABEL: @test_vld1_u8(
// CHECK:   [[VLD1:%.*]] = call <8 x i8> @llvm.arm.neon.vld1.v8i8.p0(ptr %a, i32 1)
// CHECK:   ret <8 x i8> [[VLD1]]
uint8x8_t test_vld1_u8(uint8_t const * a) {
  return vld1_u8(a);
}

// CHECK-LABEL: @test_vld1_u16(
// CHECK:   [[VLD1:%.*]] = call <4 x i16> @llvm.arm.neon.vld1.v4i16.p0(ptr %a, i32 2)
// CHECK:   ret <4 x i16> [[VLD1]]
uint16x4_t test_vld1_u16(uint16_t const * a) {
  return vld1_u16(a);
}

// CHECK-LABEL: @test_vld1_u32(
// CHECK:   [[VLD1:%.*]] = call <2 x i32> @llvm.arm.neon.vld1.v2i32.p0(ptr %a, i32 4)
// CHECK:   ret <2 x i32> [[VLD1]]
uint32x2_t test_vld1_u32(uint32_t const * a) {
  return vld1_u32(a);
}

// CHECK-LABEL: @test_vld1_u64(
// CHECK:   [[VLD1:%.*]] = call <1 x i64> @llvm.arm.neon.vld1.v1i64.p0(ptr %a, i32 4)
// CHECK:   ret <1 x i64> [[VLD1]]
uint64x1_t test_vld1_u64(uint64_t const * a) {
  return vld1_u64(a);
}

// CHECK-LABEL: @test_vld1_s8(
// CHECK:   [[VLD1:%.*]] = call <8 x i8> @llvm.arm.neon.vld1.v8i8.p0(ptr %a, i32 1)
// CHECK:   ret <8 x i8> [[VLD1]]
int8x8_t test_vld1_s8(int8_t const * a) {
  return vld1_s8(a);
}

// CHECK-LABEL: @test_vld1_s16(
// CHECK:   [[VLD1:%.*]] = call <4 x i16> @llvm.arm.neon.vld1.v4i16.p0(ptr %a, i32 2)
// CHECK:   ret <4 x i16> [[VLD1]]
int16x4_t test_vld1_s16(int16_t const * a) {
  return vld1_s16(a);
}

// CHECK-LABEL: @test_vld1_s32(
// CHECK:   [[VLD1:%.*]] = call <2 x i32> @llvm.arm.neon.vld1.v2i32.p0(ptr %a, i32 4)
// CHECK:   ret <2 x i32> [[VLD1]]
int32x2_t test_vld1_s32(int32_t const * a) {
  return vld1_s32(a);
}

// CHECK-LABEL: @test_vld1_s64(
// CHECK:   [[VLD1:%.*]] = call <1 x i64> @llvm.arm.neon.vld1.v1i64.p0(ptr %a, i32 4)
// CHECK:   ret <1 x i64> [[VLD1]]
int64x1_t test_vld1_s64(int64_t const * a) {
  return vld1_s64(a);
}

// CHECK-LABEL: @test_vld1_f16(
// CHECK:   [[VLD1:%.*]] = call <4 x half> @llvm.arm.neon.vld1.v4f16.p0(ptr %a, i32 2)
// CHECK:   ret <4 x half> [[VLD1]]
float16x4_t test_vld1_f16(float16_t const * a) {
  return vld1_f16(a);
}

// CHECK-LABEL: @test_vld1_f32(
// CHECK:   [[VLD1:%.*]] = call <2 x float> @llvm.arm.neon.vld1.v2f32.p0(ptr %a, i32 4)
// CHECK:   ret <2 x float> [[VLD1]]
float32x2_t test_vld1_f32(float32_t const * a) {
  return vld1_f32(a);
}

// CHECK-LABEL: @test_vld1_p8(
// CHECK:   [[VLD1:%.*]] = call <8 x i8> @llvm.arm.neon.vld1.v8i8.p0(ptr %a, i32 1)
// CHECK:   ret <8 x i8> [[VLD1]]
poly8x8_t test_vld1_p8(poly8_t const * a) {
  return vld1_p8(a);
}

// CHECK-LABEL: @test_vld1_p16(
// CHECK:   [[VLD1:%.*]] = call <4 x i16> @llvm.arm.neon.vld1.v4i16.p0(ptr %a, i32 2)
// CHECK:   ret <4 x i16> [[VLD1]]
poly16x4_t test_vld1_p16(poly16_t const * a) {
  return vld1_p16(a);
}

// CHECK-LABEL: @test_vld1q_dup_u8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[TMP1:%.*]] = insertelement <16 x i8> poison, i8 [[TMP0]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <16 x i8> [[TMP1]], <16 x i8> [[TMP1]], <16 x i32> zeroinitializer
// CHECK:   ret <16 x i8> [[LANE]]
uint8x16_t test_vld1q_dup_u8(uint8_t const * a) {
  return vld1q_dup_u8(a);
}

// CHECK-LABEL: @test_vld1q_dup_u16(
// CHECK:   [[TMP2:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <8 x i16> poison, i16 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <8 x i16> [[TMP3]], <8 x i16> [[TMP3]], <8 x i32> zeroinitializer
// CHECK:   ret <8 x i16> [[LANE]]
uint16x8_t test_vld1q_dup_u16(uint16_t const * a) {
  return vld1q_dup_u16(a);
}

// CHECK-LABEL: @test_vld1q_dup_u32(
// CHECK:   [[TMP2:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <4 x i32> poison, i32 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i32> [[TMP3]], <4 x i32> [[TMP3]], <4 x i32> zeroinitializer
// CHECK:   ret <4 x i32> [[LANE]]
uint32x4_t test_vld1q_dup_u32(uint32_t const * a) {
  return vld1q_dup_u32(a);
}

// CHECK-LABEL: @test_vld1q_dup_u64(
// CHECK:   [[TMP2:%.*]] = load i64, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <2 x i64> poison, i64 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i64> [[TMP3]], <2 x i64> [[TMP3]], <2 x i32> zeroinitializer
// CHECK:   ret <2 x i64> [[LANE]]
uint64x2_t test_vld1q_dup_u64(uint64_t const * a) {
  return vld1q_dup_u64(a);
}

// CHECK-LABEL: @test_vld1q_dup_s8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[TMP1:%.*]] = insertelement <16 x i8> poison, i8 [[TMP0]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <16 x i8> [[TMP1]], <16 x i8> [[TMP1]], <16 x i32> zeroinitializer
// CHECK:   ret <16 x i8> [[LANE]]
int8x16_t test_vld1q_dup_s8(int8_t const * a) {
  return vld1q_dup_s8(a);
}

// CHECK-LABEL: @test_vld1q_dup_s16(
// CHECK:   [[TMP2:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <8 x i16> poison, i16 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <8 x i16> [[TMP3]], <8 x i16> [[TMP3]], <8 x i32> zeroinitializer
// CHECK:   ret <8 x i16> [[LANE]]
int16x8_t test_vld1q_dup_s16(int16_t const * a) {
  return vld1q_dup_s16(a);
}

// CHECK-LABEL: @test_vld1q_dup_s32(
// CHECK:   [[TMP2:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <4 x i32> poison, i32 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i32> [[TMP3]], <4 x i32> [[TMP3]], <4 x i32> zeroinitializer
// CHECK:   ret <4 x i32> [[LANE]]
int32x4_t test_vld1q_dup_s32(int32_t const * a) {
  return vld1q_dup_s32(a);
}

// CHECK-LABEL: @test_vld1q_dup_s64(
// CHECK:   [[TMP2:%.*]] = load i64, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <2 x i64> poison, i64 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i64> [[TMP3]], <2 x i64> [[TMP3]], <2 x i32> zeroinitializer
// CHECK:   ret <2 x i64> [[LANE]]
int64x2_t test_vld1q_dup_s64(int64_t const * a) {
  return vld1q_dup_s64(a);
}

// CHECK-LABEL: @test_vld1q_dup_f16(
// CHECK:   [[TMP2:%.*]] = load half, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <8 x half> poison, half [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <8 x half> [[TMP3]], <8 x half> [[TMP3]], <8 x i32> zeroinitializer
// CHECK:   ret <8 x half> [[LANE]]
float16x8_t test_vld1q_dup_f16(float16_t const * a) {
  return vld1q_dup_f16(a);
}

// CHECK-LABEL: @test_vld1q_dup_f32(
// CHECK:   [[TMP2:%.*]] = load float, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <4 x float> poison, float [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <4 x float> [[TMP3]], <4 x float> [[TMP3]], <4 x i32> zeroinitializer
// CHECK:   ret <4 x float> [[LANE]]
float32x4_t test_vld1q_dup_f32(float32_t const * a) {
  return vld1q_dup_f32(a);
}

// CHECK-LABEL: @test_vld1q_dup_p8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[TMP1:%.*]] = insertelement <16 x i8> poison, i8 [[TMP0]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <16 x i8> [[TMP1]], <16 x i8> [[TMP1]], <16 x i32> zeroinitializer
// CHECK:   ret <16 x i8> [[LANE]]
poly8x16_t test_vld1q_dup_p8(poly8_t const * a) {
  return vld1q_dup_p8(a);
}

// CHECK-LABEL: @test_vld1q_dup_p16(
// CHECK:   [[TMP2:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <8 x i16> poison, i16 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <8 x i16> [[TMP3]], <8 x i16> [[TMP3]], <8 x i32> zeroinitializer
// CHECK:   ret <8 x i16> [[LANE]]
poly16x8_t test_vld1q_dup_p16(poly16_t const * a) {
  return vld1q_dup_p16(a);
}

// CHECK-LABEL: @test_vld1_dup_u8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[TMP1:%.*]] = insertelement <8 x i8> poison, i8 [[TMP0]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <8 x i8> [[TMP1]], <8 x i8> [[TMP1]], <8 x i32> zeroinitializer
// CHECK:   ret <8 x i8> [[LANE]]
uint8x8_t test_vld1_dup_u8(uint8_t const * a) {
  return vld1_dup_u8(a);
}

// CHECK-LABEL: @test_vld1_dup_u16(
// CHECK:   [[TMP2:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <4 x i16> poison, i16 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP3]], <4 x i16> [[TMP3]], <4 x i32> zeroinitializer
// CHECK:   ret <4 x i16> [[LANE]]
uint16x4_t test_vld1_dup_u16(uint16_t const * a) {
  return vld1_dup_u16(a);
}

// CHECK-LABEL: @test_vld1_dup_u32(
// CHECK:   [[TMP2:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <2 x i32> poison, i32 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP3]], <2 x i32> [[TMP3]], <2 x i32> zeroinitializer
// CHECK:   ret <2 x i32> [[LANE]]
uint32x2_t test_vld1_dup_u32(uint32_t const * a) {
  return vld1_dup_u32(a);
}

// CHECK-LABEL: @test_vld1_dup_u64(
// CHECK:   [[TMP2:%.*]] = load i64, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <1 x i64> poison, i64 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <1 x i64> [[TMP3]], <1 x i64> [[TMP3]], <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[LANE]]
uint64x1_t test_vld1_dup_u64(uint64_t const * a) {
  return vld1_dup_u64(a);
}

// CHECK-LABEL: @test_vld1_dup_s8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[TMP1:%.*]] = insertelement <8 x i8> poison, i8 [[TMP0]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <8 x i8> [[TMP1]], <8 x i8> [[TMP1]], <8 x i32> zeroinitializer
// CHECK:   ret <8 x i8> [[LANE]]
int8x8_t test_vld1_dup_s8(int8_t const * a) {
  return vld1_dup_s8(a);
}

// CHECK-LABEL: @test_vld1_dup_s16(
// CHECK:   [[TMP2:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <4 x i16> poison, i16 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP3]], <4 x i16> [[TMP3]], <4 x i32> zeroinitializer
// CHECK:   ret <4 x i16> [[LANE]]
int16x4_t test_vld1_dup_s16(int16_t const * a) {
  return vld1_dup_s16(a);
}

// CHECK-LABEL: @test_vld1_dup_s32(
// CHECK:   [[TMP2:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <2 x i32> poison, i32 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP3]], <2 x i32> [[TMP3]], <2 x i32> zeroinitializer
// CHECK:   ret <2 x i32> [[LANE]]
int32x2_t test_vld1_dup_s32(int32_t const * a) {
  return vld1_dup_s32(a);
}

// CHECK-LABEL: @test_vld1_dup_s64(
// CHECK:   [[TMP2:%.*]] = load i64, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <1 x i64> poison, i64 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <1 x i64> [[TMP3]], <1 x i64> [[TMP3]], <1 x i32> zeroinitializer
// CHECK:   ret <1 x i64> [[LANE]]
int64x1_t test_vld1_dup_s64(int64_t const * a) {
  return vld1_dup_s64(a);
}

// CHECK-LABEL: @test_vld1_dup_f16(
// CHECK:   [[TMP2:%.*]] = load half, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <4 x half> poison, half [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <4 x half> [[TMP3]], <4 x half> [[TMP3]], <4 x i32> zeroinitializer
// CHECK:   ret <4 x half> [[LANE]]
float16x4_t test_vld1_dup_f16(float16_t const * a) {
  return vld1_dup_f16(a);
}

// CHECK-LABEL: @test_vld1_dup_f32(
// CHECK:   [[TMP2:%.*]] = load float, ptr %a, align 4
// CHECK:   [[TMP3:%.*]] = insertelement <2 x float> poison, float [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP3]], <2 x float> [[TMP3]], <2 x i32> zeroinitializer
// CHECK:   ret <2 x float> [[LANE]]
float32x2_t test_vld1_dup_f32(float32_t const * a) {
  return vld1_dup_f32(a);
}

// CHECK-LABEL: @test_vld1_dup_p8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[TMP1:%.*]] = insertelement <8 x i8> poison, i8 [[TMP0]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <8 x i8> [[TMP1]], <8 x i8> [[TMP1]], <8 x i32> zeroinitializer
// CHECK:   ret <8 x i8> [[LANE]]
poly8x8_t test_vld1_dup_p8(poly8_t const * a) {
  return vld1_dup_p8(a);
}

// CHECK-LABEL: @test_vld1_dup_p16(
// CHECK:   [[TMP2:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[TMP3:%.*]] = insertelement <4 x i16> poison, i16 [[TMP2]], i32 0
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP3]], <4 x i16> [[TMP3]], <4 x i32> zeroinitializer
// CHECK:   ret <4 x i16> [[LANE]]
poly16x4_t test_vld1_dup_p16(poly16_t const * a) {
  return vld1_dup_p16(a);
}

// CHECK-LABEL: @test_vld1q_lane_u8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <16 x i8> %b, i8 [[TMP0]], i32 15
// CHECK:   ret <16 x i8> [[VLD1_LANE]]
uint8x16_t test_vld1q_lane_u8(uint8_t const * a, uint8x16_t b) {
  return vld1q_lane_u8(a, b, 15);
}

// CHECK-LABEL: @test_vld1q_lane_u16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP4:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <8 x i16> [[TMP2]], i16 [[TMP4]], i32 7
// CHECK:   ret <8 x i16> [[VLD1_LANE]]
uint16x8_t test_vld1q_lane_u16(uint16_t const * a, uint16x8_t b) {
  return vld1q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vld1q_lane_u32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[TMP4:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <4 x i32> [[TMP2]], i32 [[TMP4]], i32 3
// CHECK:   ret <4 x i32> [[VLD1_LANE]]
uint32x4_t test_vld1q_lane_u32(uint32_t const * a, uint32x4_t b) {
  return vld1q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vld1q_lane_u64(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = shufflevector <2 x i64> [[TMP2]], <2 x i64> [[TMP2]], <1 x i32> zeroinitializer
// CHECK:   [[TMP4:%.*]] = call <1 x i64> @llvm.arm.neon.vld1.v1i64.p0(ptr %a, i32 4)
// CHECK:   [[VLD1Q_LANE:%.*]] = shufflevector <1 x i64> [[TMP3]], <1 x i64> [[TMP4]], <2 x i32> <i32 0, i32 1>
// CHECK:   ret <2 x i64> [[VLD1Q_LANE]]
uint64x2_t test_vld1q_lane_u64(uint64_t const * a, uint64x2_t b) {
  return vld1q_lane_u64(a, b, 1);
}

// CHECK-LABEL: @test_vld1q_lane_s8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <16 x i8> %b, i8 [[TMP0]], i32 15
// CHECK:   ret <16 x i8> [[VLD1_LANE]]
int8x16_t test_vld1q_lane_s8(int8_t const * a, int8x16_t b) {
  return vld1q_lane_s8(a, b, 15);
}

// CHECK-LABEL: @test_vld1q_lane_s16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP4:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <8 x i16> [[TMP2]], i16 [[TMP4]], i32 7
// CHECK:   ret <8 x i16> [[VLD1_LANE]]
int16x8_t test_vld1q_lane_s16(int16_t const * a, int16x8_t b) {
  return vld1q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vld1q_lane_s32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[TMP4:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <4 x i32> [[TMP2]], i32 [[TMP4]], i32 3
// CHECK:   ret <4 x i32> [[VLD1_LANE]]
int32x4_t test_vld1q_lane_s32(int32_t const * a, int32x4_t b) {
  return vld1q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vld1q_lane_s64(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = shufflevector <2 x i64> [[TMP2]], <2 x i64> [[TMP2]], <1 x i32> zeroinitializer
// CHECK:   [[TMP4:%.*]] = call <1 x i64> @llvm.arm.neon.vld1.v1i64.p0(ptr %a, i32 4)
// CHECK:   [[VLD1Q_LANE:%.*]] = shufflevector <1 x i64> [[TMP3]], <1 x i64> [[TMP4]], <2 x i32> <i32 0, i32 1>
// CHECK:   ret <2 x i64> [[VLD1Q_LANE]]
int64x2_t test_vld1q_lane_s64(int64_t const * a, int64x2_t b) {
  return vld1q_lane_s64(a, b, 1);
}

// CHECK-LABEL: @test_vld1q_lane_f16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x half> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x half>
// CHECK:   [[TMP4:%.*]] = load half, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <8 x half> [[TMP2]], half [[TMP4]], i32 7
// CHECK:   ret <8 x half> [[VLD1_LANE]]
float16x8_t test_vld1q_lane_f16(float16_t const * a, float16x8_t b) {
  return vld1q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vld1q_lane_f32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x float>
// CHECK:   [[TMP4:%.*]] = load float, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <4 x float> [[TMP2]], float [[TMP4]], i32 3
// CHECK:   ret <4 x float> [[VLD1_LANE]]
float32x4_t test_vld1q_lane_f32(float32_t const * a, float32x4_t b) {
  return vld1q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vld1q_lane_p8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <16 x i8> %b, i8 [[TMP0]], i32 15
// CHECK:   ret <16 x i8> [[VLD1_LANE]]
poly8x16_t test_vld1q_lane_p8(poly8_t const * a, poly8x16_t b) {
  return vld1q_lane_p8(a, b, 15);
}

// CHECK-LABEL: @test_vld1q_lane_p16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP4:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <8 x i16> [[TMP2]], i16 [[TMP4]], i32 7
// CHECK:   ret <8 x i16> [[VLD1_LANE]]
poly16x8_t test_vld1q_lane_p16(poly16_t const * a, poly16x8_t b) {
  return vld1q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vld1_lane_u8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <8 x i8> %b, i8 [[TMP0]], i32 7
// CHECK:   ret <8 x i8> [[VLD1_LANE]]
uint8x8_t test_vld1_lane_u8(uint8_t const * a, uint8x8_t b) {
  return vld1_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vld1_lane_u16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP4:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <4 x i16> [[TMP2]], i16 [[TMP4]], i32 3
// CHECK:   ret <4 x i16> [[VLD1_LANE]]
uint16x4_t test_vld1_lane_u16(uint16_t const * a, uint16x4_t b) {
  return vld1_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vld1_lane_u32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[TMP4:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <2 x i32> [[TMP2]], i32 [[TMP4]], i32 1
// CHECK:   ret <2 x i32> [[VLD1_LANE]]
uint32x2_t test_vld1_lane_u32(uint32_t const * a, uint32x2_t b) {
  return vld1_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vld1_lane_u64(
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[TMP4:%.*]] = load i64, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <1 x i64> [[TMP2]], i64 [[TMP4]], i32 0
// CHECK:   ret <1 x i64> [[VLD1_LANE]]
uint64x1_t test_vld1_lane_u64(uint64_t const * a, uint64x1_t b) {
  return vld1_lane_u64(a, b, 0);
}

// CHECK-LABEL: @test_vld1_lane_s8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <8 x i8> %b, i8 [[TMP0]], i32 7
// CHECK:   ret <8 x i8> [[VLD1_LANE]]
int8x8_t test_vld1_lane_s8(int8_t const * a, int8x8_t b) {
  return vld1_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vld1_lane_s16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP4:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <4 x i16> [[TMP2]], i16 [[TMP4]], i32 3
// CHECK:   ret <4 x i16> [[VLD1_LANE]]
int16x4_t test_vld1_lane_s16(int16_t const * a, int16x4_t b) {
  return vld1_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vld1_lane_s32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[TMP4:%.*]] = load i32, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <2 x i32> [[TMP2]], i32 [[TMP4]], i32 1
// CHECK:   ret <2 x i32> [[VLD1_LANE]]
int32x2_t test_vld1_lane_s32(int32_t const * a, int32x2_t b) {
  return vld1_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vld1_lane_s64(
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[TMP4:%.*]] = load i64, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <1 x i64> [[TMP2]], i64 [[TMP4]], i32 0
// CHECK:   ret <1 x i64> [[VLD1_LANE]]
int64x1_t test_vld1_lane_s64(int64_t const * a, int64x1_t b) {
  return vld1_lane_s64(a, b, 0);
}

// CHECK-LABEL: @test_vld1_lane_f16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x half> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x half>
// CHECK:   [[TMP4:%.*]] = load half, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <4 x half> [[TMP2]], half [[TMP4]], i32 3
// CHECK:   ret <4 x half> [[VLD1_LANE]]
float16x4_t test_vld1_lane_f16(float16_t const * a, float16x4_t b) {
  return vld1_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vld1_lane_f32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x float>
// CHECK:   [[TMP4:%.*]] = load float, ptr %a, align 4
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <2 x float> [[TMP2]], float [[TMP4]], i32 1
// CHECK:   ret <2 x float> [[VLD1_LANE]]
float32x2_t test_vld1_lane_f32(float32_t const * a, float32x2_t b) {
  return vld1_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vld1_lane_p8(
// CHECK:   [[TMP0:%.*]] = load i8, ptr %a, align 1
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <8 x i8> %b, i8 [[TMP0]], i32 7
// CHECK:   ret <8 x i8> [[VLD1_LANE]]
poly8x8_t test_vld1_lane_p8(poly8_t const * a, poly8x8_t b) {
  return vld1_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vld1_lane_p16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP4:%.*]] = load i16, ptr %a, align 2
// CHECK:   [[VLD1_LANE:%.*]] = insertelement <4 x i16> [[TMP2]], i16 [[TMP4]], i32 3
// CHECK:   ret <4 x i16> [[VLD1_LANE]]
poly16x4_t test_vld1_lane_p16(poly16_t const * a, poly16x4_t b) {
  return vld1_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vld2q_u8(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x16x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <16 x i8>, <16 x i8>
uint8x16x2_t test_vld2q_u8(uint8_t const * a) {
  return vld2q_u8(a);
}

// CHECK-LABEL: @test_vld2q_u16(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <8 x i16>, <8 x i16>
uint16x8x2_t test_vld2q_u16(uint16_t const * a) {
  return vld2q_u16(a);
}

// CHECK-LABEL: @test_vld2q_u32(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <4 x i32>, <4 x i32>
uint32x4x2_t test_vld2q_u32(uint32_t const * a) {
  return vld2q_u32(a);
}

// CHECK-LABEL: @test_vld2q_s8(
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x16x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <16 x i8>, <16 x i8>
int8x16x2_t test_vld2q_s8(int8_t const * a) {
  return vld2q_s8(a);
}

// CHECK-LABEL: @test_vld2q_s16(
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <8 x i16>, <8 x i16>
int16x8x2_t test_vld2q_s16(int16_t const * a) {
  return vld2q_s16(a);
}

// CHECK-LABEL: @test_vld2q_s32(
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <4 x i32>, <4 x i32>
int32x4x2_t test_vld2q_s32(int32_t const * a) {
  return vld2q_s32(a);
}

// CHECK-LABEL: @test_vld2q_f16(
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <8 x half>, <8 x half>
float16x8x2_t test_vld2q_f16(float16_t const * a) {
  return vld2q_f16(a);
}

// CHECK-LABEL: @test_vld2q_f32(
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <4 x float>, <4 x float>
float32x4x2_t test_vld2q_f32(float32_t const * a) {
  return vld2q_f32(a);
}

// CHECK-LABEL: @test_vld2q_p8(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x16x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <16 x i8>, <16 x i8>
poly8x16x2_t test_vld2q_p8(poly8_t const * a) {
  return vld2q_p8(a);
}

// CHECK-LABEL: @test_vld2q_p16(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[VLD2Q_V:%.*]] = call { <8 x i16>, <8 x i16>
poly16x8x2_t test_vld2q_p16(poly16_t const * a) {
  return vld2q_p16(a);
}

// CHECK-LABEL: @test_vld2_u8(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <8 x i8>, <8 x i8>
uint8x8x2_t test_vld2_u8(uint8_t const * a) {
  return vld2_u8(a);
}

// CHECK-LABEL: @test_vld2_u16(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <4 x i16>, <4 x i16>
uint16x4x2_t test_vld2_u16(uint16_t const * a) {
  return vld2_u16(a);
}

// CHECK-LABEL: @test_vld2_u32(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <2 x i32>, <2 x i32>
uint32x2x2_t test_vld2_u32(uint32_t const * a) {
  return vld2_u32(a);
}

// CHECK-LABEL: @test_vld2_u64(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint64x1x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <1 x i64>, <1 x i64>
uint64x1x2_t test_vld2_u64(uint64_t const * a) {
  return vld2_u64(a);
}

// CHECK-LABEL: @test_vld2_s8(
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <8 x i8>, <8 x i8>
int8x8x2_t test_vld2_s8(int8_t const * a) {
  return vld2_s8(a);
}

// CHECK-LABEL: @test_vld2_s16(
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <4 x i16>, <4 x i16>
int16x4x2_t test_vld2_s16(int16_t const * a) {
  return vld2_s16(a);
}

// CHECK-LABEL: @test_vld2_s32(
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <2 x i32>, <2 x i32>
int32x2x2_t test_vld2_s32(int32_t const * a) {
  return vld2_s32(a);
}

// CHECK-LABEL: @test_vld2_s64(
// CHECK:   [[__RET:%.*]] = alloca %struct.int64x1x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <1 x i64>, <1 x i64>
int64x1x2_t test_vld2_s64(int64_t const * a) {
  return vld2_s64(a);
}

// CHECK-LABEL: @test_vld2_f16(
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <4 x half>, <4 x half>
float16x4x2_t test_vld2_f16(float16_t const * a) {
  return vld2_f16(a);
}

// CHECK-LABEL: @test_vld2_f32(
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <2 x float>, <2 x float>
float32x2x2_t test_vld2_f32(float32_t const * a) {
  return vld2_f32(a);
}

// CHECK-LABEL: @test_vld2_p8(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <8 x i8>, <8 x i8>
poly8x8x2_t test_vld2_p8(poly8_t const * a) {
  return vld2_p8(a);
}

// CHECK-LABEL: @test_vld2_p16(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[VLD2_V:%.*]] = call { <4 x i16>, <4 x i16>
poly16x4x2_t test_vld2_p16(poly16_t const * a) {
  return vld2_p16(a);
}

// CHECK-LABEL: @test_vld2q_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[VLD2Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>
uint16x8x2_t test_vld2q_lane_u16(uint16_t const * a, uint16x8x2_t b) {
  return vld2q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vld2q_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i32> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i32> [[TMP7]] to <16 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x i32>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x i32>
// CHECK:   [[VLD2Q_LANE_V:%.*]] = call { <4 x i32>, <4 x i32>
uint32x4x2_t test_vld2q_lane_u32(uint32_t const * a, uint32x4x2_t b) {
  return vld2q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vld2q_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[VLD2Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>
int16x8x2_t test_vld2q_lane_s16(int16_t const * a, int16x8x2_t b) {
  return vld2q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vld2q_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i32> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i32> [[TMP7]] to <16 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x i32>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x i32>
// CHECK:   [[VLD2Q_LANE_V:%.*]] = call { <4 x i32>, <4 x i32>
int32x4x2_t test_vld2q_lane_s32(int32_t const * a, int32x4x2_t b) {
  return vld2q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vld2q_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x half> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x half> [[TMP7]] to <16 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x half>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x half>
// CHECK:   [[VLD2Q_LANE_V:%.*]] = call { <8 x half>, <8 x half>
float16x8x2_t test_vld2q_lane_f16(float16_t const * a, float16x8x2_t b) {
  return vld2q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vld2q_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x float> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x float> [[TMP7]] to <16 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x float>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x float>
// CHECK:   [[VLD2Q_LANE_V:%.*]] = call { <4 x float>, <4 x float>
float32x4x2_t test_vld2q_lane_f32(float32_t const * a, float32x4x2_t b) {
  return vld2q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vld2q_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[VLD2Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>
poly16x8x2_t test_vld2q_lane_p16(poly16_t const * a, poly16x8x2_t b) {
  return vld2q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vld2_lane_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>
uint8x8x2_t test_vld2_lane_u8(uint8_t const * a, uint8x8x2_t b) {
  return vld2_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vld2_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>
uint16x4x2_t test_vld2_lane_u16(uint16_t const * a, uint16x4x2_t b) {
  return vld2_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vld2_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x i32> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x i32> [[TMP7]] to <8 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x i32>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x i32>
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <2 x i32>, <2 x i32>
uint32x2x2_t test_vld2_lane_u32(uint32_t const * a, uint32x2x2_t b) {
  return vld2_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vld2_lane_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>
int8x8x2_t test_vld2_lane_s8(int8_t const * a, int8x8x2_t b) {
  return vld2_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vld2_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>
int16x4x2_t test_vld2_lane_s16(int16_t const * a, int16x4x2_t b) {
  return vld2_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vld2_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x i32> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x i32> [[TMP7]] to <8 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x i32>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x i32>
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <2 x i32>, <2 x i32>
int32x2x2_t test_vld2_lane_s32(int32_t const * a, int32x2x2_t b) {
  return vld2_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vld2_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x half> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x half> [[TMP7]] to <8 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x half>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x half>
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <4 x half>, <4 x half>
float16x4x2_t test_vld2_lane_f16(float16_t const * a, float16x4x2_t b) {
  return vld2_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vld2_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x float> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x float> [[TMP7]] to <8 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x float>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x float>
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <2 x float>, <2 x float>
float32x2x2_t test_vld2_lane_f32(float32_t const * a, float32x2x2_t b) {
  return vld2_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vld2_lane_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>
poly8x8x2_t test_vld2_lane_p8(poly8_t const * a, poly8x8x2_t b) {
  return vld2_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vld2_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[VLD2_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>
poly16x4x2_t test_vld2_lane_p16(poly16_t const * a, poly16x4x2_t b) {
  return vld2_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vld3q_u8(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x16x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <16 x i8>, <16 x i8>, <16 x i8>
uint8x16x3_t test_vld3q_u8(uint8_t const * a) {
  return vld3q_u8(a);
}

// CHECK-LABEL: @test_vld3q_u16(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>
uint16x8x3_t test_vld3q_u16(uint16_t const * a) {
  return vld3q_u16(a);
}

// CHECK-LABEL: @test_vld3q_u32(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>
uint32x4x3_t test_vld3q_u32(uint32_t const * a) {
  return vld3q_u32(a);
}

// CHECK-LABEL: @test_vld3q_s8(
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x16x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <16 x i8>, <16 x i8>, <16 x i8>
int8x16x3_t test_vld3q_s8(int8_t const * a) {
  return vld3q_s8(a);
}

// CHECK-LABEL: @test_vld3q_s16(
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>
int16x8x3_t test_vld3q_s16(int16_t const * a) {
  return vld3q_s16(a);
}

// CHECK-LABEL: @test_vld3q_s32(
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>
int32x4x3_t test_vld3q_s32(int32_t const * a) {
  return vld3q_s32(a);
}

// CHECK-LABEL: @test_vld3q_f16(
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <8 x half>, <8 x half>, <8 x half>
float16x8x3_t test_vld3q_f16(float16_t const * a) {
  return vld3q_f16(a);
}

// CHECK-LABEL: @test_vld3q_f32(
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <4 x float>, <4 x float>, <4 x float>
float32x4x3_t test_vld3q_f32(float32_t const * a) {
  return vld3q_f32(a);
}

// CHECK-LABEL: @test_vld3q_p8(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x16x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <16 x i8>, <16 x i8>, <16 x i8>
poly8x16x3_t test_vld3q_p8(poly8_t const * a) {
  return vld3q_p8(a);
}

// CHECK-LABEL: @test_vld3q_p16(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[VLD3Q_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>
poly16x8x3_t test_vld3q_p16(poly16_t const * a) {
  return vld3q_p16(a);
}

// CHECK-LABEL: @test_vld3_u8(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>
uint8x8x3_t test_vld3_u8(uint8_t const * a) {
  return vld3_u8(a);
}

// CHECK-LABEL: @test_vld3_u16(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>
uint16x4x3_t test_vld3_u16(uint16_t const * a) {
  return vld3_u16(a);
}

// CHECK-LABEL: @test_vld3_u32(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>
uint32x2x3_t test_vld3_u32(uint32_t const * a) {
  return vld3_u32(a);
}

// CHECK-LABEL: @test_vld3_u64(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint64x1x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <1 x i64>, <1 x i64>, <1 x i64>
uint64x1x3_t test_vld3_u64(uint64_t const * a) {
  return vld3_u64(a);
}

// CHECK-LABEL: @test_vld3_s8(
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>
int8x8x3_t test_vld3_s8(int8_t const * a) {
  return vld3_s8(a);
}

// CHECK-LABEL: @test_vld3_s16(
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>
int16x4x3_t test_vld3_s16(int16_t const * a) {
  return vld3_s16(a);
}

// CHECK-LABEL: @test_vld3_s32(
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>
int32x2x3_t test_vld3_s32(int32_t const * a) {
  return vld3_s32(a);
}

// CHECK-LABEL: @test_vld3_s64(
// CHECK:   [[__RET:%.*]] = alloca %struct.int64x1x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <1 x i64>, <1 x i64>, <1 x i64>
int64x1x3_t test_vld3_s64(int64_t const * a) {
  return vld3_s64(a);
}

// CHECK-LABEL: @test_vld3_f16(
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <4 x half>, <4 x half>, <4 x half>
float16x4x3_t test_vld3_f16(float16_t const * a) {
  return vld3_f16(a);
}

// CHECK-LABEL: @test_vld3_f32(
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <2 x float>, <2 x float>, <2 x float>
float32x2x3_t test_vld3_f32(float32_t const * a) {
  return vld3_f32(a);
}

// CHECK-LABEL: @test_vld3_p8(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>
poly8x8x3_t test_vld3_p8(poly8_t const * a) {
  return vld3_p8(a);
}

// CHECK-LABEL: @test_vld3_p16(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[VLD3_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>
poly16x4x3_t test_vld3_p16(poly16_t const * a) {
  return vld3_p16(a);
}

// CHECK-LABEL: @test_vld3q_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i16> [[TMP9]] to <16 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x i16>
// CHECK:   [[VLD3Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>
uint16x8x3_t test_vld3q_lane_u16(uint16_t const * a, uint16x8x3_t b) {
  return vld3q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vld3q_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i32> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i32> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i32> [[TMP9]] to <16 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP10]] to <4 x i32>
// CHECK:   [[VLD3Q_LANE_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>
uint32x4x3_t test_vld3q_lane_u32(uint32_t const * a, uint32x4x3_t b) {
  return vld3q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vld3q_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i16> [[TMP9]] to <16 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x i16>
// CHECK:   [[VLD3Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>
int16x8x3_t test_vld3q_lane_s16(int16_t const * a, int16x8x3_t b) {
  return vld3q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vld3q_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i32> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i32> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i32> [[TMP9]] to <16 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP10]] to <4 x i32>
// CHECK:   [[VLD3Q_LANE_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>
int32x4x3_t test_vld3q_lane_s32(int32_t const * a, int32x4x3_t b) {
  return vld3q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vld3q_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x half> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x half> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x half>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x half> [[TMP9]] to <16 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x half>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x half>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x half>
// CHECK:   [[VLD3Q_LANE_V:%.*]] = call { <8 x half>, <8 x half>, <8 x half>
float16x8x3_t test_vld3q_lane_f16(float16_t const * a, float16x8x3_t b) {
  return vld3q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vld3q_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x float> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x float> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x float>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <4 x float> [[TMP9]] to <16 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x float>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x float>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP10]] to <4 x float>
// CHECK:   [[VLD3Q_LANE_V:%.*]] = call { <4 x float>, <4 x float>, <4 x float>
float32x4x3_t test_vld3q_lane_f32(float32_t const * a, float32x4x3_t b) {
  return vld3q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vld3q_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i16> [[TMP9]] to <16 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x i16>
// CHECK:   [[VLD3Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>
poly16x8x3_t test_vld3q_lane_p16(poly16_t const * a, poly16x8x3_t b) {
  return vld3q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vld3_lane_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>
uint8x8x3_t test_vld3_lane_u8(uint8_t const * a, uint8x8x3_t b) {
  return vld3_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vld3_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i16> [[TMP9]] to <8 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x i16>
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>
uint16x4x3_t test_vld3_lane_u16(uint16_t const * a, uint16x4x3_t b) {
  return vld3_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vld3_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x i32> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x i32> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <2 x i32> [[TMP9]] to <8 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP10]] to <2 x i32>
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>
uint32x2x3_t test_vld3_lane_u32(uint32_t const * a, uint32x2x3_t b) {
  return vld3_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vld3_lane_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>
int8x8x3_t test_vld3_lane_s8(int8_t const * a, int8x8x3_t b) {
  return vld3_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vld3_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i16> [[TMP9]] to <8 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x i16>
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>
int16x4x3_t test_vld3_lane_s16(int16_t const * a, int16x4x3_t b) {
  return vld3_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vld3_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x i32> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x i32> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <2 x i32> [[TMP9]] to <8 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP10]] to <2 x i32>
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>
int32x2x3_t test_vld3_lane_s32(int32_t const * a, int32x2x3_t b) {
  return vld3_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vld3_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x half> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x half> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x half>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x half> [[TMP9]] to <8 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x half>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x half>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x half>
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <4 x half>, <4 x half>, <4 x half>
float16x4x3_t test_vld3_lane_f16(float16_t const * a, float16x4x3_t b) {
  return vld3_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vld3_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x float> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x float> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <2 x float>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <2 x float> [[TMP9]] to <8 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x float>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x float>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP10]] to <2 x float>
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <2 x float>, <2 x float>, <2 x float>
float32x2x3_t test_vld3_lane_f32(float32_t const * a, float32x2x3_t b) {
  return vld3_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vld3_lane_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>
poly8x8x3_t test_vld3_lane_p8(poly8_t const * a, poly8x8x3_t b) {
  return vld3_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vld3_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i16> [[TMP9]] to <8 x i8>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x i16>
// CHECK:   [[VLD3_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>
poly16x4x3_t test_vld3_lane_p16(poly16_t const * a, poly16x4x3_t b) {
  return vld3_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vld4q_u8(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x16x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <16 x i8>, <16 x i8>, <16 x i8>, <16 x i8>
uint8x16x4_t test_vld4q_u8(uint8_t const * a) {
  return vld4q_u8(a);
}

// CHECK-LABEL: @test_vld4q_u16(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>, <8 x i16>
uint16x8x4_t test_vld4q_u16(uint16_t const * a) {
  return vld4q_u16(a);
}

// CHECK-LABEL: @test_vld4q_u32(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>, <4 x i32>
uint32x4x4_t test_vld4q_u32(uint32_t const * a) {
  return vld4q_u32(a);
}

// CHECK-LABEL: @test_vld4q_s8(
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x16x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <16 x i8>, <16 x i8>, <16 x i8>, <16 x i8>
int8x16x4_t test_vld4q_s8(int8_t const * a) {
  return vld4q_s8(a);
}

// CHECK-LABEL: @test_vld4q_s16(
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>, <8 x i16>
int16x8x4_t test_vld4q_s16(int16_t const * a) {
  return vld4q_s16(a);
}

// CHECK-LABEL: @test_vld4q_s32(
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>, <4 x i32>
int32x4x4_t test_vld4q_s32(int32_t const * a) {
  return vld4q_s32(a);
}

// CHECK-LABEL: @test_vld4q_f16(
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <8 x half>, <8 x half>, <8 x half>, <8 x half>
float16x8x4_t test_vld4q_f16(float16_t const * a) {
  return vld4q_f16(a);
}

// CHECK-LABEL: @test_vld4q_f32(
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <4 x float>, <4 x float>, <4 x float>, <4 x float>
float32x4x4_t test_vld4q_f32(float32_t const * a) {
  return vld4q_f32(a);
}

// CHECK-LABEL: @test_vld4q_p8(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x16x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <16 x i8>, <16 x i8>, <16 x i8>, <16 x i8>
poly8x16x4_t test_vld4q_p8(poly8_t const * a) {
  return vld4q_p8(a);
}

// CHECK-LABEL: @test_vld4q_p16(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[VLD4Q_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>, <8 x i16>
poly16x8x4_t test_vld4q_p16(poly16_t const * a) {
  return vld4q_p16(a);
}

// CHECK-LABEL: @test_vld4_u8(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>, <8 x i8>
uint8x8x4_t test_vld4_u8(uint8_t const * a) {
  return vld4_u8(a);
}

// CHECK-LABEL: @test_vld4_u16(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>, <4 x i16>
uint16x4x4_t test_vld4_u16(uint16_t const * a) {
  return vld4_u16(a);
}

// CHECK-LABEL: @test_vld4_u32(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>, <2 x i32>
uint32x2x4_t test_vld4_u32(uint32_t const * a) {
  return vld4_u32(a);
}

// CHECK-LABEL: @test_vld4_u64(
// CHECK:   [[__RET:%.*]] = alloca %struct.uint64x1x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <1 x i64>, <1 x i64>, <1 x i64>, <1 x i64>
uint64x1x4_t test_vld4_u64(uint64_t const * a) {
  return vld4_u64(a);
}

// CHECK-LABEL: @test_vld4_s8(
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>, <8 x i8>
int8x8x4_t test_vld4_s8(int8_t const * a) {
  return vld4_s8(a);
}

// CHECK-LABEL: @test_vld4_s16(
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>, <4 x i16>
int16x4x4_t test_vld4_s16(int16_t const * a) {
  return vld4_s16(a);
}

// CHECK-LABEL: @test_vld4_s32(
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>, <2 x i32>
int32x2x4_t test_vld4_s32(int32_t const * a) {
  return vld4_s32(a);
}

// CHECK-LABEL: @test_vld4_s64(
// CHECK:   [[__RET:%.*]] = alloca %struct.int64x1x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <1 x i64>, <1 x i64>, <1 x i64>, <1 x i64>
int64x1x4_t test_vld4_s64(int64_t const * a) {
  return vld4_s64(a);
}

// CHECK-LABEL: @test_vld4_f16(
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <4 x half>, <4 x half>, <4 x half>, <4 x half>
float16x4x4_t test_vld4_f16(float16_t const * a) {
  return vld4_f16(a);
}

// CHECK-LABEL: @test_vld4_f32(
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <2 x float>, <2 x float>, <2 x float>, <2 x float>
float32x2x4_t test_vld4_f32(float32_t const * a) {
  return vld4_f32(a);
}

// CHECK-LABEL: @test_vld4_p8(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>, <8 x i8>
poly8x8x4_t test_vld4_p8(poly8_t const * a) {
  return vld4_p8(a);
}

// CHECK-LABEL: @test_vld4_p16(
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[VLD4_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>, <4 x i16>
poly16x4x4_t test_vld4_p16(poly16_t const * a) {
  return vld4_p16(a);
}

// CHECK-LABEL: @test_vld4q_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i16> [[TMP9]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i16> [[TMP11]] to <16 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x i16>
// CHECK:   [[TMP16:%.*]] = bitcast <16 x i8> [[TMP12]] to <8 x i16>
// CHECK:   [[VLD4Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>, <8 x i16>
uint16x8x4_t test_vld4q_lane_u16(uint16_t const * a, uint16x8x4_t b) {
  return vld4q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vld4q_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i32> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i32> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i32> [[TMP9]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <4 x i32>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP12:%.*]] = bitcast <4 x i32> [[TMP11]] to <16 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP10]] to <4 x i32>
// CHECK:   [[TMP16:%.*]] = bitcast <16 x i8> [[TMP12]] to <4 x i32>
// CHECK:   [[VLD4Q_LANE_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>, <4 x i32>
uint32x4x4_t test_vld4q_lane_u32(uint32_t const * a, uint32x4x4_t b) {
  return vld4q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vld4q_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i16> [[TMP9]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i16> [[TMP11]] to <16 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x i16>
// CHECK:   [[TMP16:%.*]] = bitcast <16 x i8> [[TMP12]] to <8 x i16>
// CHECK:   [[VLD4Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>, <8 x i16>
int16x8x4_t test_vld4q_lane_s16(int16_t const * a, int16x8x4_t b) {
  return vld4q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vld4q_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i32> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i32> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i32> [[TMP9]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <4 x i32>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP12:%.*]] = bitcast <4 x i32> [[TMP11]] to <16 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP10]] to <4 x i32>
// CHECK:   [[TMP16:%.*]] = bitcast <16 x i8> [[TMP12]] to <4 x i32>
// CHECK:   [[VLD4Q_LANE_V:%.*]] = call { <4 x i32>, <4 x i32>, <4 x i32>, <4 x i32>
int32x4x4_t test_vld4q_lane_s32(int32_t const * a, int32x4x4_t b) {
  return vld4q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vld4q_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x half> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x half> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x half>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x half> [[TMP9]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <8 x half>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP12:%.*]] = bitcast <8 x half> [[TMP11]] to <16 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x half>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x half>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x half>
// CHECK:   [[TMP16:%.*]] = bitcast <16 x i8> [[TMP12]] to <8 x half>
// CHECK:   [[VLD4Q_LANE_V:%.*]] = call { <8 x half>, <8 x half>, <8 x half>, <8 x half>
float16x8x4_t test_vld4q_lane_f16(float16_t const * a, float16x8x4_t b) {
  return vld4q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vld4q_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <4 x float> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <4 x float> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x float>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <4 x float> [[TMP9]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <4 x float>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP12:%.*]] = bitcast <4 x float> [[TMP11]] to <16 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP6]] to <4 x float>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP8]] to <4 x float>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP10]] to <4 x float>
// CHECK:   [[TMP16:%.*]] = bitcast <16 x i8> [[TMP12]] to <4 x float>
// CHECK:   [[VLD4Q_LANE_V:%.*]] = call { <4 x float>, <4 x float>, <4 x float>, <4 x float>
float32x4x4_t test_vld4q_lane_f32(float32_t const * a, float32x4x4_t b) {
  return vld4q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vld4q_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP6:%.*]] = bitcast <8 x i16> [[TMP5]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i16> [[TMP7]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i16> [[TMP9]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i16> [[TMP11]] to <16 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP6]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP8]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP10]] to <8 x i16>
// CHECK:   [[TMP16:%.*]] = bitcast <16 x i8> [[TMP12]] to <8 x i16>
// CHECK:   [[VLD4Q_LANE_V:%.*]] = call { <8 x i16>, <8 x i16>, <8 x i16>, <8 x i16>
poly16x8x4_t test_vld4q_lane_p16(poly16_t const * a, poly16x8x4_t b) {
  return vld4q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vld4_lane_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>, <8 x i8>
uint8x8x4_t test_vld4_lane_u8(uint8_t const * a, uint8x8x4_t b) {
  return vld4_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vld4_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i16> [[TMP9]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP12:%.*]] = bitcast <4 x i16> [[TMP11]] to <8 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x i16>
// CHECK:   [[TMP16:%.*]] = bitcast <8 x i8> [[TMP12]] to <4 x i16>
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>, <4 x i16>
uint16x4x4_t test_vld4_lane_u16(uint16_t const * a, uint16x4x4_t b) {
  return vld4_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vld4_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x i32> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x i32> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <2 x i32> [[TMP9]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <2 x i32>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP12:%.*]] = bitcast <2 x i32> [[TMP11]] to <8 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP10]] to <2 x i32>
// CHECK:   [[TMP16:%.*]] = bitcast <8 x i8> [[TMP12]] to <2 x i32>
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>, <2 x i32>
uint32x2x4_t test_vld4_lane_u32(uint32_t const * a, uint32x2x4_t b) {
  return vld4_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vld4_lane_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>, <8 x i8>
int8x8x4_t test_vld4_lane_s8(int8_t const * a, int8x8x4_t b) {
  return vld4_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vld4_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i16> [[TMP9]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP12:%.*]] = bitcast <4 x i16> [[TMP11]] to <8 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x i16>
// CHECK:   [[TMP16:%.*]] = bitcast <8 x i8> [[TMP12]] to <4 x i16>
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>, <4 x i16>
int16x4x4_t test_vld4_lane_s16(int16_t const * a, int16x4x4_t b) {
  return vld4_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vld4_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x i32> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x i32> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <2 x i32> [[TMP9]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <2 x i32>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP12:%.*]] = bitcast <2 x i32> [[TMP11]] to <8 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP10]] to <2 x i32>
// CHECK:   [[TMP16:%.*]] = bitcast <8 x i8> [[TMP12]] to <2 x i32>
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <2 x i32>, <2 x i32>, <2 x i32>, <2 x i32>
int32x2x4_t test_vld4_lane_s32(int32_t const * a, int32x2x4_t b) {
  return vld4_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vld4_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x half> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x half> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x half>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x half> [[TMP9]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <4 x half>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP12:%.*]] = bitcast <4 x half> [[TMP11]] to <8 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x half>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x half>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x half>
// CHECK:   [[TMP16:%.*]] = bitcast <8 x i8> [[TMP12]] to <4 x half>
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <4 x half>, <4 x half>, <4 x half>, <4 x half>
float16x4x4_t test_vld4_lane_f16(float16_t const * a, float16x4x4_t b) {
  return vld4_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vld4_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <2 x float> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <2 x float> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <2 x float>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <2 x float> [[TMP9]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <2 x float>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP12:%.*]] = bitcast <2 x float> [[TMP11]] to <8 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP6]] to <2 x float>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP8]] to <2 x float>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP10]] to <2 x float>
// CHECK:   [[TMP16:%.*]] = bitcast <8 x i8> [[TMP12]] to <2 x float>
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <2 x float>, <2 x float>, <2 x float>, <2 x float>
float32x2x4_t test_vld4_lane_f32(float32_t const * a, float32x2x4_t b) {
  return vld4_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vld4_lane_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <8 x i8>, <8 x i8>, <8 x i8>, <8 x i8>
poly8x8x4_t test_vld4_lane_p8(poly8_t const * a, poly8x8x4_t b) {
  return vld4_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vld4_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[__RET:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP5:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP6:%.*]] = bitcast <4 x i16> [[TMP5]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP7:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP8:%.*]] = bitcast <4 x i16> [[TMP7]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP9:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP10:%.*]] = bitcast <4 x i16> [[TMP9]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP11:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP12:%.*]] = bitcast <4 x i16> [[TMP11]] to <8 x i8>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP6]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP8]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP10]] to <4 x i16>
// CHECK:   [[TMP16:%.*]] = bitcast <8 x i8> [[TMP12]] to <4 x i16>
// CHECK:   [[VLD4_LANE_V:%.*]] = call { <4 x i16>, <4 x i16>, <4 x i16>, <4 x i16>
poly16x4x4_t test_vld4_lane_p16(poly16_t const * a, poly16x4x4_t b) {
  return vld4_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vmax_s8(
// CHECK:   [[VMAX_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vmaxs.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VMAX_V_I]]
int8x8_t test_vmax_s8(int8x8_t a, int8x8_t b) {
  return vmax_s8(a, b);
}

// CHECK-LABEL: @test_vmax_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMAX_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vmaxs.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VMAX_V3_I:%.*]] = bitcast <4 x i16> [[VMAX_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VMAX_V2_I]]
int16x4_t test_vmax_s16(int16x4_t a, int16x4_t b) {
  return vmax_s16(a, b);
}

// CHECK-LABEL: @test_vmax_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMAX_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vmaxs.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VMAX_V3_I:%.*]] = bitcast <2 x i32> [[VMAX_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VMAX_V2_I]]
int32x2_t test_vmax_s32(int32x2_t a, int32x2_t b) {
  return vmax_s32(a, b);
}

// CHECK-LABEL: @test_vmax_u8(
// CHECK:   [[VMAX_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vmaxu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VMAX_V_I]]
uint8x8_t test_vmax_u8(uint8x8_t a, uint8x8_t b) {
  return vmax_u8(a, b);
}

// CHECK-LABEL: @test_vmax_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMAX_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vmaxu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VMAX_V3_I:%.*]] = bitcast <4 x i16> [[VMAX_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VMAX_V2_I]]
uint16x4_t test_vmax_u16(uint16x4_t a, uint16x4_t b) {
  return vmax_u16(a, b);
}

// CHECK-LABEL: @test_vmax_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMAX_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vmaxu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VMAX_V3_I:%.*]] = bitcast <2 x i32> [[VMAX_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VMAX_V2_I]]
uint32x2_t test_vmax_u32(uint32x2_t a, uint32x2_t b) {
  return vmax_u32(a, b);
}

// CHECK-LABEL: @test_vmax_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VMAX_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vmaxs.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VMAX_V3_I:%.*]] = bitcast <2 x float> [[VMAX_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VMAX_V2_I]]
float32x2_t test_vmax_f32(float32x2_t a, float32x2_t b) {
  return vmax_f32(a, b);
}

// CHECK-LABEL: @test_vmaxq_s8(
// CHECK:   [[VMAXQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vmaxs.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VMAXQ_V_I]]
int8x16_t test_vmaxq_s8(int8x16_t a, int8x16_t b) {
  return vmaxq_s8(a, b);
}

// CHECK-LABEL: @test_vmaxq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VMAXQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmaxs.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VMAXQ_V3_I:%.*]] = bitcast <8 x i16> [[VMAXQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VMAXQ_V2_I]]
int16x8_t test_vmaxq_s16(int16x8_t a, int16x8_t b) {
  return vmaxq_s16(a, b);
}

// CHECK-LABEL: @test_vmaxq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VMAXQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmaxs.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VMAXQ_V3_I:%.*]] = bitcast <4 x i32> [[VMAXQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VMAXQ_V2_I]]
int32x4_t test_vmaxq_s32(int32x4_t a, int32x4_t b) {
  return vmaxq_s32(a, b);
}

// CHECK-LABEL: @test_vmaxq_u8(
// CHECK:   [[VMAXQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vmaxu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VMAXQ_V_I]]
uint8x16_t test_vmaxq_u8(uint8x16_t a, uint8x16_t b) {
  return vmaxq_u8(a, b);
}

// CHECK-LABEL: @test_vmaxq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VMAXQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmaxu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VMAXQ_V3_I:%.*]] = bitcast <8 x i16> [[VMAXQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VMAXQ_V2_I]]
uint16x8_t test_vmaxq_u16(uint16x8_t a, uint16x8_t b) {
  return vmaxq_u16(a, b);
}

// CHECK-LABEL: @test_vmaxq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VMAXQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmaxu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VMAXQ_V3_I:%.*]] = bitcast <4 x i32> [[VMAXQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VMAXQ_V2_I]]
uint32x4_t test_vmaxq_u32(uint32x4_t a, uint32x4_t b) {
  return vmaxq_u32(a, b);
}

// CHECK-LABEL: @test_vmaxq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VMAXQ_V2_I:%.*]] = call <4 x float> @llvm.arm.neon.vmaxs.v4f32(<4 x float> %a, <4 x float> %b)
// CHECK:   [[VMAXQ_V3_I:%.*]] = bitcast <4 x float> [[VMAXQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x float> [[VMAXQ_V2_I]]
float32x4_t test_vmaxq_f32(float32x4_t a, float32x4_t b) {
  return vmaxq_f32(a, b);
}

// CHECK-LABEL: @test_vmin_s8(
// CHECK:   [[VMIN_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vmins.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VMIN_V_I]]
int8x8_t test_vmin_s8(int8x8_t a, int8x8_t b) {
  return vmin_s8(a, b);
}

// CHECK-LABEL: @test_vmin_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMIN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vmins.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VMIN_V3_I:%.*]] = bitcast <4 x i16> [[VMIN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VMIN_V2_I]]
int16x4_t test_vmin_s16(int16x4_t a, int16x4_t b) {
  return vmin_s16(a, b);
}

// CHECK-LABEL: @test_vmin_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMIN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vmins.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VMIN_V3_I:%.*]] = bitcast <2 x i32> [[VMIN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VMIN_V2_I]]
int32x2_t test_vmin_s32(int32x2_t a, int32x2_t b) {
  return vmin_s32(a, b);
}

// CHECK-LABEL: @test_vmin_u8(
// CHECK:   [[VMIN_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vminu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VMIN_V_I]]
uint8x8_t test_vmin_u8(uint8x8_t a, uint8x8_t b) {
  return vmin_u8(a, b);
}

// CHECK-LABEL: @test_vmin_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMIN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vminu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VMIN_V3_I:%.*]] = bitcast <4 x i16> [[VMIN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VMIN_V2_I]]
uint16x4_t test_vmin_u16(uint16x4_t a, uint16x4_t b) {
  return vmin_u16(a, b);
}

// CHECK-LABEL: @test_vmin_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMIN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vminu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VMIN_V3_I:%.*]] = bitcast <2 x i32> [[VMIN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VMIN_V2_I]]
uint32x2_t test_vmin_u32(uint32x2_t a, uint32x2_t b) {
  return vmin_u32(a, b);
}

// CHECK-LABEL: @test_vmin_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VMIN_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vmins.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VMIN_V3_I:%.*]] = bitcast <2 x float> [[VMIN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VMIN_V2_I]]
float32x2_t test_vmin_f32(float32x2_t a, float32x2_t b) {
  return vmin_f32(a, b);
}

// CHECK-LABEL: @test_vminq_s8(
// CHECK:   [[VMINQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vmins.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VMINQ_V_I]]
int8x16_t test_vminq_s8(int8x16_t a, int8x16_t b) {
  return vminq_s8(a, b);
}

// CHECK-LABEL: @test_vminq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VMINQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmins.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VMINQ_V3_I:%.*]] = bitcast <8 x i16> [[VMINQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VMINQ_V2_I]]
int16x8_t test_vminq_s16(int16x8_t a, int16x8_t b) {
  return vminq_s16(a, b);
}

// CHECK-LABEL: @test_vminq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VMINQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmins.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VMINQ_V3_I:%.*]] = bitcast <4 x i32> [[VMINQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VMINQ_V2_I]]
int32x4_t test_vminq_s32(int32x4_t a, int32x4_t b) {
  return vminq_s32(a, b);
}

// CHECK-LABEL: @test_vminq_u8(
// CHECK:   [[VMINQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vminu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VMINQ_V_I]]
uint8x16_t test_vminq_u8(uint8x16_t a, uint8x16_t b) {
  return vminq_u8(a, b);
}

// CHECK-LABEL: @test_vminq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VMINQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vminu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VMINQ_V3_I:%.*]] = bitcast <8 x i16> [[VMINQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VMINQ_V2_I]]
uint16x8_t test_vminq_u16(uint16x8_t a, uint16x8_t b) {
  return vminq_u16(a, b);
}

// CHECK-LABEL: @test_vminq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VMINQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vminu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VMINQ_V3_I:%.*]] = bitcast <4 x i32> [[VMINQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VMINQ_V2_I]]
uint32x4_t test_vminq_u32(uint32x4_t a, uint32x4_t b) {
  return vminq_u32(a, b);
}

// CHECK-LABEL: @test_vminq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VMINQ_V2_I:%.*]] = call <4 x float> @llvm.arm.neon.vmins.v4f32(<4 x float> %a, <4 x float> %b)
// CHECK:   [[VMINQ_V3_I:%.*]] = bitcast <4 x float> [[VMINQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x float> [[VMINQ_V2_I]]
float32x4_t test_vminq_f32(float32x4_t a, float32x4_t b) {
  return vminq_f32(a, b);
}

// CHECK-LABEL: @test_vmla_s8(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i8> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <8 x i8> %a, [[MUL_I]]
// CHECK:   ret <8 x i8> [[ADD_I]]
int8x8_t test_vmla_s8(int8x8_t a, int8x8_t b, int8x8_t c) {
  return vmla_s8(a, b, c);
}

// CHECK-LABEL: @test_vmla_s16(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[ADD_I]]
int16x4_t test_vmla_s16(int16x4_t a, int16x4_t b, int16x4_t c) {
  return vmla_s16(a, b, c);
}

// CHECK-LABEL: @test_vmla_s32(
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[ADD_I]]
int32x2_t test_vmla_s32(int32x2_t a, int32x2_t b, int32x2_t c) {
  return vmla_s32(a, b, c);
}

// CHECK-LABEL: @test_vmla_f32(
// CHECK:   [[MUL_I:%.*]] = fmul <2 x float> %b, %c
// CHECK:   [[ADD_I:%.*]] = fadd <2 x float> %a, [[MUL_I]]
// CHECK:   ret <2 x float> [[ADD_I]]
float32x2_t test_vmla_f32(float32x2_t a, float32x2_t b, float32x2_t c) {
  return vmla_f32(a, b, c);
}

// CHECK-LABEL: @test_vmla_u8(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i8> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <8 x i8> %a, [[MUL_I]]
// CHECK:   ret <8 x i8> [[ADD_I]]
uint8x8_t test_vmla_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c) {
  return vmla_u8(a, b, c);
}

// CHECK-LABEL: @test_vmla_u16(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[ADD_I]]
uint16x4_t test_vmla_u16(uint16x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmla_u16(a, b, c);
}

// CHECK-LABEL: @test_vmla_u32(
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[ADD_I]]
uint32x2_t test_vmla_u32(uint32x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmla_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_s8(
// CHECK:   [[MUL_I:%.*]] = mul <16 x i8> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <16 x i8> %a, [[MUL_I]]
// CHECK:   ret <16 x i8> [[ADD_I]]
int8x16_t test_vmlaq_s8(int8x16_t a, int8x16_t b, int8x16_t c) {
  return vmlaq_s8(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_s16(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vmlaq_s16(int16x8_t a, int16x8_t b, int16x8_t c) {
  return vmlaq_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_s32(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vmlaq_s32(int32x4_t a, int32x4_t b, int32x4_t c) {
  return vmlaq_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_f32(
// CHECK:   [[MUL_I:%.*]] = fmul <4 x float> %b, %c
// CHECK:   [[ADD_I:%.*]] = fadd <4 x float> %a, [[MUL_I]]
// CHECK:   ret <4 x float> [[ADD_I]]
float32x4_t test_vmlaq_f32(float32x4_t a, float32x4_t b, float32x4_t c) {
  return vmlaq_f32(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_u8(
// CHECK:   [[MUL_I:%.*]] = mul <16 x i8> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <16 x i8> %a, [[MUL_I]]
// CHECK:   ret <16 x i8> [[ADD_I]]
uint8x16_t test_vmlaq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c) {
  return vmlaq_u8(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_u16(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vmlaq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c) {
  return vmlaq_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_u32(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, %c
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vmlaq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  return vmlaq_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlal_s8(
// CHECK:   [[VMULL_I_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmulls.v8i16(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VMULL_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vmlal_s8(int16x8_t a, int8x8_t b, int8x8_t c) {
  return vmlal_s8(a, b, c);
}

// CHECK-LABEL: @test_vmlal_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vmlal_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vmlal_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlal_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
int64x2_t test_vmlal_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vmlal_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlal_u8(
// CHECK:   [[VMULL_I_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmullu.v8i16(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[VMULL_I_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vmlal_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c) {
  return vmlal_u8(a, b, c);
}

// CHECK-LABEL: @test_vmlal_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vmlal_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmlal_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlal_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
uint64x2_t test_vmlal_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmlal_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlal_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> [[B]], <4 x i16> [[LANE]])
// CHECK:   [[ADD:%.*]] = add <4 x i32> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <4 x i32> [[ADD]]
int32x4_t test_vmlal_lane_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vmlal_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlal_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> [[B]], <2 x i32> [[LANE]])
// CHECK:   [[ADD:%.*]] = add <2 x i64> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <2 x i64> [[ADD]]
int64x2_t test_vmlal_lane_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vmlal_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlal_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> [[B]], <4 x i16> [[LANE]])
// CHECK:   [[ADD:%.*]] = add <4 x i32> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <4 x i32> [[ADD]]
uint32x4_t test_vmlal_lane_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmlal_lane_u16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlal_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> [[B]], <2 x i32> [[LANE]])
// CHECK:   [[ADD:%.*]] = add <2 x i64> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <2 x i64> [[ADD]]
uint64x2_t test_vmlal_lane_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmlal_lane_u32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlal_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> %b, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vmlal_n_s16(int32x4_t a, int16x4_t b, int16_t c) {
  return vmlal_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlal_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> %b, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
int64x2_t test_vmlal_n_s32(int64x2_t a, int32x2_t b, int32_t c) {
  return vmlal_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlal_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> %b, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vmlal_n_u16(uint32x4_t a, uint16x4_t b, uint16_t c) {
  return vmlal_n_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlal_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> %b, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[ADD_I:%.*]] = add <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[ADD_I]]
uint64x2_t test_vmlal_n_u32(uint64x2_t a, uint32x2_t b, uint32_t c) {
  return vmlal_n_u32(a, b, c);
}

// CHECK-LABEL: @test_vmla_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <4 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <4 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i16> [[ADD]]
int16x4_t test_vmla_lane_s16(int16x4_t a, int16x4_t b, int16x4_t c) {
  return vmla_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmla_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <2 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <2 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <2 x i32> [[ADD]]
int32x2_t test_vmla_lane_s32(int32x2_t a, int32x2_t b, int32x2_t c) {
  return vmla_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmla_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <4 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <4 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i16> [[ADD]]
uint16x4_t test_vmla_lane_u16(uint16x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmla_lane_u16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmla_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <2 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <2 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <2 x i32> [[ADD]]
uint32x2_t test_vmla_lane_u32(uint32x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmla_lane_u32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmla_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = fmul <2 x float> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = fadd <2 x float> [[A:%.*]], [[MUL]]
// CHECK:   ret <2 x float> [[ADD]]
float32x2_t test_vmla_lane_f32(float32x2_t a, float32x2_t b, float32x2_t c) {
  return vmla_lane_f32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlaq_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <8 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <8 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <8 x i16> [[ADD]]
int16x8_t test_vmlaq_lane_s16(int16x8_t a, int16x8_t b, int16x4_t c) {
  return vmlaq_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlaq_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <4 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <4 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i32> [[ADD]]
int32x4_t test_vmlaq_lane_s32(int32x4_t a, int32x4_t b, int32x2_t c) {
  return vmlaq_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlaq_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <8 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <8 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <8 x i16> [[ADD]]
uint16x8_t test_vmlaq_lane_u16(uint16x8_t a, uint16x8_t b, uint16x4_t c) {
  return vmlaq_lane_u16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlaq_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <4 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = add <4 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i32> [[ADD]]
uint32x4_t test_vmlaq_lane_u32(uint32x4_t a, uint32x4_t b, uint32x2_t c) {
  return vmlaq_lane_u32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlaq_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = fmul <4 x float> [[B:%.*]], [[LANE]]
// CHECK:   [[ADD:%.*]] = fadd <4 x float> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x float> [[ADD]]
float32x4_t test_vmlaq_lane_f32(float32x4_t a, float32x4_t b, float32x2_t c) {
  return vmlaq_lane_f32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmla_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, [[VECINIT3_I]]
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[ADD_I]]
int16x4_t test_vmla_n_s16(int16x4_t a, int16x4_t b, int16_t c) {
  return vmla_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vmla_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, [[VECINIT1_I]]
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[ADD_I]]
int32x2_t test_vmla_n_s32(int32x2_t a, int32x2_t b, int32_t c) {
  return vmla_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vmla_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, [[VECINIT3_I]]
// CHECK:   [[ADD_I:%.*]] = add <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[ADD_I]]
uint16x4_t test_vmla_n_u16(uint16x4_t a, uint16x4_t b, uint16_t c) {
  return vmla_n_u16(a, b, c);
}

// CHECK-LABEL: @test_vmla_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, [[VECINIT1_I]]
// CHECK:   [[ADD_I:%.*]] = add <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[ADD_I]]
uint32x2_t test_vmla_n_u32(uint32x2_t a, uint32x2_t b, uint32_t c) {
  return vmla_n_u32(a, b, c);
}

// CHECK-LABEL: @test_vmla_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x float> undef, float %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x float> [[VECINIT_I]], float %c, i32 1
// CHECK:   [[MUL_I:%.*]] = fmul <2 x float> %b, [[VECINIT1_I]]
// CHECK:   [[ADD_I:%.*]] = fadd <2 x float> %a, [[MUL_I]]
// CHECK:   ret <2 x float> [[ADD_I]]
float32x2_t test_vmla_n_f32(float32x2_t a, float32x2_t b, float32_t c) {
  return vmla_n_f32(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %c, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %c, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %c, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %c, i32 7
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, [[VECINIT7_I]]
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
int16x8_t test_vmlaq_n_s16(int16x8_t a, int16x8_t b, int16_t c) {
  return vmlaq_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, [[VECINIT3_I]]
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
int32x4_t test_vmlaq_n_s32(int32x4_t a, int32x4_t b, int32_t c) {
  return vmlaq_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %c, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %c, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %c, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %c, i32 7
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, [[VECINIT7_I]]
// CHECK:   [[ADD_I:%.*]] = add <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[ADD_I]]
uint16x8_t test_vmlaq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c) {
  return vmlaq_n_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, [[VECINIT3_I]]
// CHECK:   [[ADD_I:%.*]] = add <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[ADD_I]]
uint32x4_t test_vmlaq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c) {
  return vmlaq_n_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlaq_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x float> undef, float %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x float> [[VECINIT_I]], float %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x float> [[VECINIT1_I]], float %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x float> [[VECINIT2_I]], float %c, i32 3
// CHECK:   [[MUL_I:%.*]] = fmul <4 x float> %b, [[VECINIT3_I]]
// CHECK:   [[ADD_I:%.*]] = fadd <4 x float> %a, [[MUL_I]]
// CHECK:   ret <4 x float> [[ADD_I]]
float32x4_t test_vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c) {
  return vmlaq_n_f32(a, b, c);
}

// CHECK-LABEL: @test_vmls_s8(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i8> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <8 x i8> %a, [[MUL_I]]
// CHECK:   ret <8 x i8> [[SUB_I]]
int8x8_t test_vmls_s8(int8x8_t a, int8x8_t b, int8x8_t c) {
  return vmls_s8(a, b, c);
}

// CHECK-LABEL: @test_vmls_s16(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[SUB_I]]
int16x4_t test_vmls_s16(int16x4_t a, int16x4_t b, int16x4_t c) {
  return vmls_s16(a, b, c);
}

// CHECK-LABEL: @test_vmls_s32(
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[SUB_I]]
int32x2_t test_vmls_s32(int32x2_t a, int32x2_t b, int32x2_t c) {
  return vmls_s32(a, b, c);
}

// CHECK-LABEL: @test_vmls_f32(
// CHECK:   [[MUL_I:%.*]] = fmul <2 x float> %b, %c
// CHECK:   [[SUB_I:%.*]] = fsub <2 x float> %a, [[MUL_I]]
// CHECK:   ret <2 x float> [[SUB_I]]
float32x2_t test_vmls_f32(float32x2_t a, float32x2_t b, float32x2_t c) {
  return vmls_f32(a, b, c);
}

// CHECK-LABEL: @test_vmls_u8(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i8> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <8 x i8> %a, [[MUL_I]]
// CHECK:   ret <8 x i8> [[SUB_I]]
uint8x8_t test_vmls_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c) {
  return vmls_u8(a, b, c);
}

// CHECK-LABEL: @test_vmls_u16(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[SUB_I]]
uint16x4_t test_vmls_u16(uint16x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmls_u16(a, b, c);
}

// CHECK-LABEL: @test_vmls_u32(
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[SUB_I]]
uint32x2_t test_vmls_u32(uint32x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmls_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_s8(
// CHECK:   [[MUL_I:%.*]] = mul <16 x i8> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <16 x i8> %a, [[MUL_I]]
// CHECK:   ret <16 x i8> [[SUB_I]]
int8x16_t test_vmlsq_s8(int8x16_t a, int8x16_t b, int8x16_t c) {
  return vmlsq_s8(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_s16(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
int16x8_t test_vmlsq_s16(int16x8_t a, int16x8_t b, int16x8_t c) {
  return vmlsq_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_s32(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vmlsq_s32(int32x4_t a, int32x4_t b, int32x4_t c) {
  return vmlsq_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_f32(
// CHECK:   [[MUL_I:%.*]] = fmul <4 x float> %b, %c
// CHECK:   [[SUB_I:%.*]] = fsub <4 x float> %a, [[MUL_I]]
// CHECK:   ret <4 x float> [[SUB_I]]
float32x4_t test_vmlsq_f32(float32x4_t a, float32x4_t b, float32x4_t c) {
  return vmlsq_f32(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_u8(
// CHECK:   [[MUL_I:%.*]] = mul <16 x i8> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <16 x i8> %a, [[MUL_I]]
// CHECK:   ret <16 x i8> [[SUB_I]]
uint8x16_t test_vmlsq_u8(uint8x16_t a, uint8x16_t b, uint8x16_t c) {
  return vmlsq_u8(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_u16(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
uint16x8_t test_vmlsq_u16(uint16x8_t a, uint16x8_t b, uint16x8_t c) {
  return vmlsq_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_u32(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, %c
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
uint32x4_t test_vmlsq_u32(uint32x4_t a, uint32x4_t b, uint32x4_t c) {
  return vmlsq_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_s8(
// CHECK:   [[VMULL_I_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmulls.v8i16(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[VMULL_I_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
int16x8_t test_vmlsl_s8(int16x8_t a, int8x8_t b, int8x8_t c) {
  return vmlsl_s8(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vmlsl_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vmlsl_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
int64x2_t test_vmlsl_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vmlsl_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_u8(
// CHECK:   [[VMULL_I_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmullu.v8i16(<8 x i8> %b, <8 x i8> %c)
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[VMULL_I_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
uint16x8_t test_vmlsl_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c) {
  return vmlsl_u8(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
uint32x4_t test_vmlsl_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmlsl_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
uint64x2_t test_vmlsl_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmlsl_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> [[B]], <4 x i16> [[LANE]])
// CHECK:   [[SUB:%.*]] = sub <4 x i32> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <4 x i32> [[SUB]]
int32x4_t test_vmlsl_lane_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vmlsl_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlsl_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> [[B]], <2 x i32> [[LANE]])
// CHECK:   [[SUB:%.*]] = sub <2 x i64> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <2 x i64> [[SUB]]
int64x2_t test_vmlsl_lane_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vmlsl_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlsl_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> [[B]], <4 x i16> [[LANE]])
// CHECK:   [[SUB:%.*]] = sub <4 x i32> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <4 x i32> [[SUB]]
uint32x4_t test_vmlsl_lane_u16(uint32x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmlsl_lane_u16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlsl_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> [[B]], <2 x i32> [[LANE]])
// CHECK:   [[SUB:%.*]] = sub <2 x i64> [[A:%.*]], [[VMULL2_I]]
// CHECK:   ret <2 x i64> [[SUB]]
uint64x2_t test_vmlsl_lane_u32(uint64x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmlsl_lane_u32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlsl_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> %b, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vmlsl_n_s16(int32x4_t a, int16x4_t b, int16_t c) {
  return vmlsl_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> %b, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
int64x2_t test_vmlsl_n_s32(int64x2_t a, int32x2_t b, int32_t c) {
  return vmlsl_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> %b, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[VMULL2_I_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
uint32x4_t test_vmlsl_n_u16(uint32x4_t a, uint16x4_t b, uint16_t c) {
  return vmlsl_n_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlsl_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VMULL2_I_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> %b, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, [[VMULL2_I_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
uint64x2_t test_vmlsl_n_u32(uint64x2_t a, uint32x2_t b, uint32_t c) {
  return vmlsl_n_u32(a, b, c);
}

// CHECK-LABEL: @test_vmls_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <4 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <4 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i16> [[SUB]]
int16x4_t test_vmls_lane_s16(int16x4_t a, int16x4_t b, int16x4_t c) {
  return vmls_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmls_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <2 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <2 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <2 x i32> [[SUB]]
int32x2_t test_vmls_lane_s32(int32x2_t a, int32x2_t b, int32x2_t c) {
  return vmls_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmls_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <4 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <4 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i16> [[SUB]]
uint16x4_t test_vmls_lane_u16(uint16x4_t a, uint16x4_t b, uint16x4_t c) {
  return vmls_lane_u16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmls_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <2 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <2 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <2 x i32> [[SUB]]
uint32x2_t test_vmls_lane_u32(uint32x2_t a, uint32x2_t b, uint32x2_t c) {
  return vmls_lane_u32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmls_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = fmul <2 x float> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = fsub <2 x float> [[A:%.*]], [[MUL]]
// CHECK:   ret <2 x float> [[SUB]]
float32x2_t test_vmls_lane_f32(float32x2_t a, float32x2_t b, float32x2_t c) {
  return vmls_lane_f32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlsq_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <8 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <8 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <8 x i16> [[SUB]]
int16x8_t test_vmlsq_lane_s16(int16x8_t a, int16x8_t b, int16x4_t c) {
  return vmlsq_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlsq_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <4 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <4 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i32> [[SUB]]
int32x4_t test_vmlsq_lane_s32(int32x4_t a, int32x4_t b, int32x2_t c) {
  return vmlsq_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlsq_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <8 x i16> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <8 x i16> [[A:%.*]], [[MUL]]
// CHECK:   ret <8 x i16> [[SUB]]
uint16x8_t test_vmlsq_lane_u16(uint16x8_t a, uint16x8_t b, uint16x4_t c) {
  return vmlsq_lane_u16(a, b, c, 3);
}

// CHECK-LABEL: @test_vmlsq_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <4 x i32> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = sub <4 x i32> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x i32> [[SUB]]
uint32x4_t test_vmlsq_lane_u32(uint32x4_t a, uint32x4_t b, uint32x2_t c) {
  return vmlsq_lane_u32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmlsq_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = fmul <4 x float> [[B:%.*]], [[LANE]]
// CHECK:   [[SUB:%.*]] = fsub <4 x float> [[A:%.*]], [[MUL]]
// CHECK:   ret <4 x float> [[SUB]]
float32x4_t test_vmlsq_lane_f32(float32x4_t a, float32x4_t b, float32x2_t c) {
  return vmlsq_lane_f32(a, b, c, 1);
}

// CHECK-LABEL: @test_vmls_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, [[VECINIT3_I]]
// CHECK:   [[SUB_I:%.*]] = sub <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[SUB_I]]
int16x4_t test_vmls_n_s16(int16x4_t a, int16x4_t b, int16_t c) {
  return vmls_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vmls_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, [[VECINIT1_I]]
// CHECK:   [[SUB_I:%.*]] = sub <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[SUB_I]]
int32x2_t test_vmls_n_s32(int32x2_t a, int32x2_t b, int32_t c) {
  return vmls_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vmls_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %b, [[VECINIT3_I]]
// CHECK:   [[SUB_I:%.*]] = sub <4 x i16> %a, [[MUL_I]]
// CHECK:   ret <4 x i16> [[SUB_I]]
uint16x4_t test_vmls_n_u16(uint16x4_t a, uint16x4_t b, uint16_t c) {
  return vmls_n_u16(a, b, c);
}

// CHECK-LABEL: @test_vmls_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %b, [[VECINIT1_I]]
// CHECK:   [[SUB_I:%.*]] = sub <2 x i32> %a, [[MUL_I]]
// CHECK:   ret <2 x i32> [[SUB_I]]
uint32x2_t test_vmls_n_u32(uint32x2_t a, uint32x2_t b, uint32_t c) {
  return vmls_n_u32(a, b, c);
}

// CHECK-LABEL: @test_vmls_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x float> undef, float %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x float> [[VECINIT_I]], float %c, i32 1
// CHECK:   [[MUL_I:%.*]] = fmul <2 x float> %b, [[VECINIT1_I]]
// CHECK:   [[SUB_I:%.*]] = fsub <2 x float> %a, [[MUL_I]]
// CHECK:   ret <2 x float> [[SUB_I]]
float32x2_t test_vmls_n_f32(float32x2_t a, float32x2_t b, float32_t c) {
  return vmls_n_f32(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %c, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %c, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %c, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %c, i32 7
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, [[VECINIT7_I]]
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
int16x8_t test_vmlsq_n_s16(int16x8_t a, int16x8_t b, int16_t c) {
  return vmlsq_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, [[VECINIT3_I]]
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vmlsq_n_s32(int32x4_t a, int32x4_t b, int32_t c) {
  return vmlsq_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %c, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %c, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %c, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %c, i32 7
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %b, [[VECINIT7_I]]
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[MUL_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
uint16x8_t test_vmlsq_n_u16(uint16x8_t a, uint16x8_t b, uint16_t c) {
  return vmlsq_n_u16(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %c, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %b, [[VECINIT3_I]]
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[MUL_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
uint32x4_t test_vmlsq_n_u32(uint32x4_t a, uint32x4_t b, uint32_t c) {
  return vmlsq_n_u32(a, b, c);
}

// CHECK-LABEL: @test_vmlsq_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x float> undef, float %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x float> [[VECINIT_I]], float %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x float> [[VECINIT1_I]], float %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x float> [[VECINIT2_I]], float %c, i32 3
// CHECK:   [[MUL_I:%.*]] = fmul <4 x float> %b, [[VECINIT3_I]]
// CHECK:   [[SUB_I:%.*]] = fsub <4 x float> %a, [[MUL_I]]
// CHECK:   ret <4 x float> [[SUB_I]]
float32x4_t test_vmlsq_n_f32(float32x4_t a, float32x4_t b, float32_t c) {
  return vmlsq_n_f32(a, b, c);
}

// CHECK-LABEL: @test_vmovl_s8(
// CHECK:   [[VMOVL_I:%.*]] = sext <8 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[VMOVL_I]]
int16x8_t test_vmovl_s8(int8x8_t a) {
  return vmovl_s8(a);
}

// CHECK-LABEL: @test_vmovl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VMOVL_I:%.*]] = sext <4 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[VMOVL_I]]
int32x4_t test_vmovl_s16(int16x4_t a) {
  return vmovl_s16(a);
}

// CHECK-LABEL: @test_vmovl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VMOVL_I:%.*]] = sext <2 x i32> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[VMOVL_I]]
int64x2_t test_vmovl_s32(int32x2_t a) {
  return vmovl_s32(a);
}

// CHECK-LABEL: @test_vmovl_u8(
// CHECK:   [[VMOVL_I:%.*]] = zext <8 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[VMOVL_I]]
uint16x8_t test_vmovl_u8(uint8x8_t a) {
  return vmovl_u8(a);
}

// CHECK-LABEL: @test_vmovl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VMOVL_I:%.*]] = zext <4 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[VMOVL_I]]
uint32x4_t test_vmovl_u16(uint16x4_t a) {
  return vmovl_u16(a);
}

// CHECK-LABEL: @test_vmovl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VMOVL_I:%.*]] = zext <2 x i32> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[VMOVL_I]]
uint64x2_t test_vmovl_u32(uint32x2_t a) {
  return vmovl_u32(a);
}

// CHECK-LABEL: @test_vmovn_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VMOVN_I:%.*]] = trunc <8 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[VMOVN_I]]
int8x8_t test_vmovn_s16(int16x8_t a) {
  return vmovn_s16(a);
}

// CHECK-LABEL: @test_vmovn_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VMOVN_I:%.*]] = trunc <4 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[VMOVN_I]]
int16x4_t test_vmovn_s32(int32x4_t a) {
  return vmovn_s32(a);
}

// CHECK-LABEL: @test_vmovn_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VMOVN_I:%.*]] = trunc <2 x i64> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[VMOVN_I]]
int32x2_t test_vmovn_s64(int64x2_t a) {
  return vmovn_s64(a);
}

// CHECK-LABEL: @test_vmovn_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VMOVN_I:%.*]] = trunc <8 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[VMOVN_I]]
uint8x8_t test_vmovn_u16(uint16x8_t a) {
  return vmovn_u16(a);
}

// CHECK-LABEL: @test_vmovn_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VMOVN_I:%.*]] = trunc <4 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[VMOVN_I]]
uint16x4_t test_vmovn_u32(uint32x4_t a) {
  return vmovn_u32(a);
}

// CHECK-LABEL: @test_vmovn_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VMOVN_I:%.*]] = trunc <2 x i64> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[VMOVN_I]]
uint32x2_t test_vmovn_u64(uint64x2_t a) {
  return vmovn_u64(a);
}

// CHECK-LABEL: @test_vmov_n_u8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VECINIT7_I]]
uint8x8_t test_vmov_n_u8(uint8_t a) {
  return vmov_n_u8(a);
}

// CHECK-LABEL: @test_vmov_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VECINIT3_I]]
uint16x4_t test_vmov_n_u16(uint16_t a) {
  return vmov_n_u16(a);
}

// CHECK-LABEL: @test_vmov_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   ret <2 x i32> [[VECINIT1_I]]
uint32x2_t test_vmov_n_u32(uint32_t a) {
  return vmov_n_u32(a);
}

// CHECK-LABEL: @test_vmov_n_s8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VECINIT7_I]]
int8x8_t test_vmov_n_s8(int8_t a) {
  return vmov_n_s8(a);
}

// CHECK-LABEL: @test_vmov_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VECINIT3_I]]
int16x4_t test_vmov_n_s16(int16_t a) {
  return vmov_n_s16(a);
}

// CHECK-LABEL: @test_vmov_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   ret <2 x i32> [[VECINIT1_I]]
int32x2_t test_vmov_n_s32(int32_t a) {
  return vmov_n_s32(a);
}

// CHECK-LABEL: @test_vmov_n_p8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VECINIT7_I]]
poly8x8_t test_vmov_n_p8(poly8_t a) {
  return vmov_n_p8(a);
}

// CHECK-LABEL: @test_vmov_n_p16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VECINIT3_I]]
poly16x4_t test_vmov_n_p16(poly16_t a) {
  return vmov_n_p16(a);
}

// CHECK-LABEL: @test_vmov_n_f16(
// CHECK:   [[TMP0:%.*]] = load half, ptr %a, align 2
// CHECK:   [[VECINIT:%.*]] = insertelement <4 x half> undef, half [[TMP0]], i32 0
// CHECK:   [[VECINIT1:%.*]] = insertelement <4 x half> [[VECINIT]], half [[TMP0]], i32 1
// CHECK:   [[VECINIT2:%.*]] = insertelement <4 x half> [[VECINIT1]], half [[TMP0]], i32 2
// CHECK:   [[VECINIT3:%.*]] = insertelement <4 x half> [[VECINIT2]], half [[TMP0]], i32 3
// CHECK:   ret <4 x half> [[VECINIT3]]
float16x4_t test_vmov_n_f16(float16_t *a) {
  return vmov_n_f16(*a);
}

// CHECK-LABEL: @test_vmov_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x float> undef, float %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x float> [[VECINIT_I]], float %a, i32 1
// CHECK:   ret <2 x float> [[VECINIT1_I]]
float32x2_t test_vmov_n_f32(float32_t a) {
  return vmov_n_f32(a);
}

// CHECK-LABEL: @test_vmovq_n_u8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <16 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <16 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <16 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <16 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <16 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <16 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <16 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <16 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   [[VECINIT8_I:%.*]] = insertelement <16 x i8> [[VECINIT7_I]], i8 %a, i32 8
// CHECK:   [[VECINIT9_I:%.*]] = insertelement <16 x i8> [[VECINIT8_I]], i8 %a, i32 9
// CHECK:   [[VECINIT10_I:%.*]] = insertelement <16 x i8> [[VECINIT9_I]], i8 %a, i32 10
// CHECK:   [[VECINIT11_I:%.*]] = insertelement <16 x i8> [[VECINIT10_I]], i8 %a, i32 11
// CHECK:   [[VECINIT12_I:%.*]] = insertelement <16 x i8> [[VECINIT11_I]], i8 %a, i32 12
// CHECK:   [[VECINIT13_I:%.*]] = insertelement <16 x i8> [[VECINIT12_I]], i8 %a, i32 13
// CHECK:   [[VECINIT14_I:%.*]] = insertelement <16 x i8> [[VECINIT13_I]], i8 %a, i32 14
// CHECK:   [[VECINIT15_I:%.*]] = insertelement <16 x i8> [[VECINIT14_I]], i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VECINIT15_I]]
uint8x16_t test_vmovq_n_u8(uint8_t a) {
  return vmovq_n_u8(a);
}

// CHECK-LABEL: @test_vmovq_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VECINIT7_I]]
uint16x8_t test_vmovq_n_u16(uint16_t a) {
  return vmovq_n_u16(a);
}

// CHECK-LABEL: @test_vmovq_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %a, i32 3
// CHECK:   ret <4 x i32> [[VECINIT3_I]]
uint32x4_t test_vmovq_n_u32(uint32_t a) {
  return vmovq_n_u32(a);
}

// CHECK-LABEL: @test_vmovq_n_s8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <16 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <16 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <16 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <16 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <16 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <16 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <16 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <16 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   [[VECINIT8_I:%.*]] = insertelement <16 x i8> [[VECINIT7_I]], i8 %a, i32 8
// CHECK:   [[VECINIT9_I:%.*]] = insertelement <16 x i8> [[VECINIT8_I]], i8 %a, i32 9
// CHECK:   [[VECINIT10_I:%.*]] = insertelement <16 x i8> [[VECINIT9_I]], i8 %a, i32 10
// CHECK:   [[VECINIT11_I:%.*]] = insertelement <16 x i8> [[VECINIT10_I]], i8 %a, i32 11
// CHECK:   [[VECINIT12_I:%.*]] = insertelement <16 x i8> [[VECINIT11_I]], i8 %a, i32 12
// CHECK:   [[VECINIT13_I:%.*]] = insertelement <16 x i8> [[VECINIT12_I]], i8 %a, i32 13
// CHECK:   [[VECINIT14_I:%.*]] = insertelement <16 x i8> [[VECINIT13_I]], i8 %a, i32 14
// CHECK:   [[VECINIT15_I:%.*]] = insertelement <16 x i8> [[VECINIT14_I]], i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VECINIT15_I]]
int8x16_t test_vmovq_n_s8(int8_t a) {
  return vmovq_n_s8(a);
}

// CHECK-LABEL: @test_vmovq_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VECINIT7_I]]
int16x8_t test_vmovq_n_s16(int16_t a) {
  return vmovq_n_s16(a);
}

// CHECK-LABEL: @test_vmovq_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %a, i32 3
// CHECK:   ret <4 x i32> [[VECINIT3_I]]
int32x4_t test_vmovq_n_s32(int32_t a) {
  return vmovq_n_s32(a);
}

// CHECK-LABEL: @test_vmovq_n_p8(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <16 x i8> undef, i8 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <16 x i8> [[VECINIT_I]], i8 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <16 x i8> [[VECINIT1_I]], i8 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <16 x i8> [[VECINIT2_I]], i8 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <16 x i8> [[VECINIT3_I]], i8 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <16 x i8> [[VECINIT4_I]], i8 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <16 x i8> [[VECINIT5_I]], i8 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <16 x i8> [[VECINIT6_I]], i8 %a, i32 7
// CHECK:   [[VECINIT8_I:%.*]] = insertelement <16 x i8> [[VECINIT7_I]], i8 %a, i32 8
// CHECK:   [[VECINIT9_I:%.*]] = insertelement <16 x i8> [[VECINIT8_I]], i8 %a, i32 9
// CHECK:   [[VECINIT10_I:%.*]] = insertelement <16 x i8> [[VECINIT9_I]], i8 %a, i32 10
// CHECK:   [[VECINIT11_I:%.*]] = insertelement <16 x i8> [[VECINIT10_I]], i8 %a, i32 11
// CHECK:   [[VECINIT12_I:%.*]] = insertelement <16 x i8> [[VECINIT11_I]], i8 %a, i32 12
// CHECK:   [[VECINIT13_I:%.*]] = insertelement <16 x i8> [[VECINIT12_I]], i8 %a, i32 13
// CHECK:   [[VECINIT14_I:%.*]] = insertelement <16 x i8> [[VECINIT13_I]], i8 %a, i32 14
// CHECK:   [[VECINIT15_I:%.*]] = insertelement <16 x i8> [[VECINIT14_I]], i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VECINIT15_I]]
poly8x16_t test_vmovq_n_p8(poly8_t a) {
  return vmovq_n_p8(a);
}

// CHECK-LABEL: @test_vmovq_n_p16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %a, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %a, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %a, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %a, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VECINIT7_I]]
poly16x8_t test_vmovq_n_p16(poly16_t a) {
  return vmovq_n_p16(a);
}

// CHECK-LABEL: @test_vmovq_n_f16(
// CHECK:   [[TMP0:%.*]] = load half, ptr %a, align 2
// CHECK:   [[VECINIT:%.*]] = insertelement <8 x half> undef, half [[TMP0]], i32 0
// CHECK:   [[VECINIT1:%.*]] = insertelement <8 x half> [[VECINIT]], half [[TMP0]], i32 1
// CHECK:   [[VECINIT2:%.*]] = insertelement <8 x half> [[VECINIT1]], half [[TMP0]], i32 2
// CHECK:   [[VECINIT3:%.*]] = insertelement <8 x half> [[VECINIT2]], half [[TMP0]], i32 3
// CHECK:   [[VECINIT4:%.*]] = insertelement <8 x half> [[VECINIT3]], half [[TMP0]], i32 4
// CHECK:   [[VECINIT5:%.*]] = insertelement <8 x half> [[VECINIT4]], half [[TMP0]], i32 5
// CHECK:   [[VECINIT6:%.*]] = insertelement <8 x half> [[VECINIT5]], half [[TMP0]], i32 6
// CHECK:   [[VECINIT7:%.*]] = insertelement <8 x half> [[VECINIT6]], half [[TMP0]], i32 7
// CHECK:   ret <8 x half> [[VECINIT7]]
float16x8_t test_vmovq_n_f16(float16_t *a) {
  return vmovq_n_f16(*a);
}

// CHECK-LABEL: @test_vmovq_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x float> undef, float %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x float> [[VECINIT_I]], float %a, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x float> [[VECINIT1_I]], float %a, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x float> [[VECINIT2_I]], float %a, i32 3
// CHECK:   ret <4 x float> [[VECINIT3_I]]
float32x4_t test_vmovq_n_f32(float32_t a) {
  return vmovq_n_f32(a);
}

// CHECK-LABEL: @test_vmov_n_s64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <1 x i64> undef, i64 %a, i32 0
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> [[VECINIT_I]], [[VECINIT_I]]
// CHECK:   ret <1 x i64> [[ADD_I]]
int64x1_t test_vmov_n_s64(int64_t a) {
  int64x1_t tmp = vmov_n_s64(a);
  return vadd_s64(tmp, tmp);
}

// CHECK-LABEL: @test_vmov_n_u64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <1 x i64> undef, i64 %a, i32 0
// CHECK:   [[ADD_I:%.*]] = add <1 x i64> [[VECINIT_I]], [[VECINIT_I]]
// CHECK:   ret <1 x i64> [[ADD_I]]
uint64x1_t test_vmov_n_u64(uint64_t a) {
  uint64x1_t tmp = vmov_n_u64(a);
  return vadd_u64(tmp, tmp);
}

// CHECK-LABEL: @test_vmovq_n_s64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i64> undef, i64 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i64> [[VECINIT_I]], i64 %a, i32 1
// CHECK:   ret <2 x i64> [[VECINIT1_I]]
int64x2_t test_vmovq_n_s64(int64_t a) {
  return vmovq_n_s64(a);
}

// CHECK-LABEL: @test_vmovq_n_u64(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i64> undef, i64 %a, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i64> [[VECINIT_I]], i64 %a, i32 1
// CHECK:   ret <2 x i64> [[VECINIT1_I]]
uint64x2_t test_vmovq_n_u64(uint64_t a) {
  return vmovq_n_u64(a);
}

// CHECK-LABEL: @test_vmul_s8(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[MUL_I]]
int8x8_t test_vmul_s8(int8x8_t a, int8x8_t b) {
  return vmul_s8(a, b);
}

// CHECK-LABEL: @test_vmul_s16(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[MUL_I]]
int16x4_t test_vmul_s16(int16x4_t a, int16x4_t b) {
  return vmul_s16(a, b);
}

// CHECK-LABEL: @test_vmul_s32(
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[MUL_I]]
int32x2_t test_vmul_s32(int32x2_t a, int32x2_t b) {
  return vmul_s32(a, b);
}

// CHECK-LABEL: @test_vmul_f32(
// CHECK:   [[MUL_I:%.*]] = fmul <2 x float> %a, %b
// CHECK:   ret <2 x float> [[MUL_I]]
float32x2_t test_vmul_f32(float32x2_t a, float32x2_t b) {
  return vmul_f32(a, b);
}

// CHECK-LABEL: @test_vmul_u8(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[MUL_I]]
uint8x8_t test_vmul_u8(uint8x8_t a, uint8x8_t b) {
  return vmul_u8(a, b);
}

// CHECK-LABEL: @test_vmul_u16(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[MUL_I]]
uint16x4_t test_vmul_u16(uint16x4_t a, uint16x4_t b) {
  return vmul_u16(a, b);
}

// CHECK-LABEL: @test_vmul_u32(
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[MUL_I]]
uint32x2_t test_vmul_u32(uint32x2_t a, uint32x2_t b) {
  return vmul_u32(a, b);
}

// CHECK-LABEL: @test_vmulq_s8(
// CHECK:   [[MUL_I:%.*]] = mul <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[MUL_I]]
int8x16_t test_vmulq_s8(int8x16_t a, int8x16_t b) {
  return vmulq_s8(a, b);
}

// CHECK-LABEL: @test_vmulq_s16(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[MUL_I]]
int16x8_t test_vmulq_s16(int16x8_t a, int16x8_t b) {
  return vmulq_s16(a, b);
}

// CHECK-LABEL: @test_vmulq_s32(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[MUL_I]]
int32x4_t test_vmulq_s32(int32x4_t a, int32x4_t b) {
  return vmulq_s32(a, b);
}

// CHECK-LABEL: @test_vmulq_f32(
// CHECK:   [[MUL_I:%.*]] = fmul <4 x float> %a, %b
// CHECK:   ret <4 x float> [[MUL_I]]
float32x4_t test_vmulq_f32(float32x4_t a, float32x4_t b) {
  return vmulq_f32(a, b);
}

// CHECK-LABEL: @test_vmulq_u8(
// CHECK:   [[MUL_I:%.*]] = mul <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[MUL_I]]
uint8x16_t test_vmulq_u8(uint8x16_t a, uint8x16_t b) {
  return vmulq_u8(a, b);
}

// CHECK-LABEL: @test_vmulq_u16(
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[MUL_I]]
uint16x8_t test_vmulq_u16(uint16x8_t a, uint16x8_t b) {
  return vmulq_u16(a, b);
}

// CHECK-LABEL: @test_vmulq_u32(
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[MUL_I]]
uint32x4_t test_vmulq_u32(uint32x4_t a, uint32x4_t b) {
  return vmulq_u32(a, b);
}

// CHECK-LABEL: @test_vmull_s8(
// CHECK:   [[VMULL_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmulls.v8i16(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i16> [[VMULL_I]]
int16x8_t test_vmull_s8(int8x8_t a, int8x8_t b) {
  return vmull_s8(a, b);
}

// CHECK-LABEL: @test_vmull_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> %a, <4 x i16> %b)
// CHECK:   ret <4 x i32> [[VMULL2_I]]
int32x4_t test_vmull_s16(int16x4_t a, int16x4_t b) {
  return vmull_s16(a, b);
}

// CHECK-LABEL: @test_vmull_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> %a, <2 x i32> %b)
// CHECK:   ret <2 x i64> [[VMULL2_I]]
int64x2_t test_vmull_s32(int32x2_t a, int32x2_t b) {
  return vmull_s32(a, b);
}

// CHECK-LABEL: @test_vmull_u8(
// CHECK:   [[VMULL_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmullu.v8i16(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i16> [[VMULL_I]]
uint16x8_t test_vmull_u8(uint8x8_t a, uint8x8_t b) {
  return vmull_u8(a, b);
}

// CHECK-LABEL: @test_vmull_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> %a, <4 x i16> %b)
// CHECK:   ret <4 x i32> [[VMULL2_I]]
uint32x4_t test_vmull_u16(uint16x4_t a, uint16x4_t b) {
  return vmull_u16(a, b);
}

// CHECK-LABEL: @test_vmull_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> %a, <2 x i32> %b)
// CHECK:   ret <2 x i64> [[VMULL2_I]]
uint64x2_t test_vmull_u32(uint32x2_t a, uint32x2_t b) {
  return vmull_u32(a, b);
}

// CHECK-LABEL: @test_vmull_p8(
// CHECK:   [[VMULL_I:%.*]] = call <8 x i16> @llvm.arm.neon.vmullp.v8i16(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i16> [[VMULL_I]]
poly16x8_t test_vmull_p8(poly8x8_t a, poly8x8_t b) {
  return vmull_p8(a, b);
}

// CHECK-LABEL: @test_vmull_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> [[A]], <4 x i16> [[LANE]])
// CHECK:   ret <4 x i32> [[VMULL2_I]]
int32x4_t test_vmull_lane_s16(int16x4_t a, int16x4_t b) {
  return vmull_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vmull_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> [[A]], <2 x i32> [[LANE]])
// CHECK:   ret <2 x i64> [[VMULL2_I]]
int64x2_t test_vmull_lane_s32(int32x2_t a, int32x2_t b) {
  return vmull_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vmull_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> [[A]], <4 x i16> [[LANE]])
// CHECK:   ret <4 x i32> [[VMULL2_I]]
uint32x4_t test_vmull_lane_u16(uint16x4_t a, uint16x4_t b) {
  return vmull_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vmull_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VMULL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> [[A]], <2 x i32> [[LANE]])
// CHECK:   ret <2 x i64> [[VMULL2_I]]
uint64x2_t test_vmull_lane_u32(uint32x2_t a, uint32x2_t b) {
  return vmull_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vmull_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VMULL5_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmulls.v4i32(<4 x i16> %a, <4 x i16> [[VECINIT3_I]])
// CHECK:   ret <4 x i32> [[VMULL5_I]]
int32x4_t test_vmull_n_s16(int16x4_t a, int16_t b) {
  return vmull_n_s16(a, b);
}

// CHECK-LABEL: @test_vmull_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VMULL3_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmulls.v2i64(<2 x i32> %a, <2 x i32> [[VECINIT1_I]])
// CHECK:   ret <2 x i64> [[VMULL3_I]]
int64x2_t test_vmull_n_s32(int32x2_t a, int32_t b) {
  return vmull_n_s32(a, b);
}

// CHECK-LABEL: @test_vmull_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VMULL5_I:%.*]] = call <4 x i32> @llvm.arm.neon.vmullu.v4i32(<4 x i16> %a, <4 x i16> [[VECINIT3_I]])
// CHECK:   ret <4 x i32> [[VMULL5_I]]
uint32x4_t test_vmull_n_u16(uint16x4_t a, uint16_t b) {
  return vmull_n_u16(a, b);
}

// CHECK-LABEL: @test_vmull_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VMULL3_I:%.*]] = call <2 x i64> @llvm.arm.neon.vmullu.v2i64(<2 x i32> %a, <2 x i32> [[VECINIT1_I]])
// CHECK:   ret <2 x i64> [[VMULL3_I]]
uint64x2_t test_vmull_n_u32(uint32x2_t a, uint32_t b) {
  return vmull_n_u32(a, b);
}

// CHECK-LABEL: @test_vmul_p8(
// CHECK:   [[VMUL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vmulp.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VMUL_V_I]]
poly8x8_t test_vmul_p8(poly8x8_t a, poly8x8_t b) {
  return vmul_p8(a, b);
}

// CHECK-LABEL: @test_vmulq_p8(
// CHECK:   [[VMULQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vmulp.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VMULQ_V_I]]
poly8x16_t test_vmulq_p8(poly8x16_t a, poly8x16_t b) {
  return vmulq_p8(a, b);
}

// CHECK-LABEL: @test_vmul_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <4 x i16> [[A:%.*]], [[LANE]]
// CHECK:   ret <4 x i16> [[MUL]]
int16x4_t test_vmul_lane_s16(int16x4_t a, int16x4_t b) {
  return vmul_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vmul_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <2 x i32> [[A:%.*]], [[LANE]]
// CHECK:   ret <2 x i32> [[MUL]]
int32x2_t test_vmul_lane_s32(int32x2_t a, int32x2_t b) {
  return vmul_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vmul_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = fmul <2 x float> [[A:%.*]], [[LANE]]
// CHECK:   ret <2 x float> [[MUL]]
float32x2_t test_vmul_lane_f32(float32x2_t a, float32x2_t b) {
  return vmul_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vmul_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <4 x i16> [[A:%.*]], [[LANE]]
// CHECK:   ret <4 x i16> [[MUL]]
uint16x4_t test_vmul_lane_u16(uint16x4_t a, uint16x4_t b) {
  return vmul_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vmul_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <2 x i32> [[A:%.*]], [[LANE]]
// CHECK:   ret <2 x i32> [[MUL]]
uint32x2_t test_vmul_lane_u32(uint32x2_t a, uint32x2_t b) {
  return vmul_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vmulq_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <8 x i16> [[A:%.*]], [[LANE]]
// CHECK:   ret <8 x i16> [[MUL]]
int16x8_t test_vmulq_lane_s16(int16x8_t a, int16x4_t b) {
  return vmulq_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vmulq_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <4 x i32> [[A:%.*]], [[LANE]]
// CHECK:   ret <4 x i32> [[MUL]]
int32x4_t test_vmulq_lane_s32(int32x4_t a, int32x2_t b) {
  return vmulq_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vmulq_lane_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x float>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x float> [[TMP1]], <2 x float> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = fmul <4 x float> [[A:%.*]], [[LANE]]
// CHECK:   ret <4 x float> [[MUL]]
float32x4_t test_vmulq_lane_f32(float32x4_t a, float32x2_t b) {
  return vmulq_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vmulq_lane_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[MUL:%.*]] = mul <8 x i16> [[A:%.*]], [[LANE]]
// CHECK:   ret <8 x i16> [[MUL]]
uint16x8_t test_vmulq_lane_u16(uint16x8_t a, uint16x4_t b) {
  return vmulq_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vmulq_lane_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[MUL:%.*]] = mul <4 x i32> [[A:%.*]], [[LANE]]
// CHECK:   ret <4 x i32> [[MUL]]
uint32x4_t test_vmulq_lane_u32(uint32x4_t a, uint32x2_t b) {
  return vmulq_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vmul_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %a, [[VECINIT3_I]]
// CHECK:   ret <4 x i16> [[MUL_I]]
int16x4_t test_vmul_n_s16(int16x4_t a, int16_t b) {
  return vmul_n_s16(a, b);
}

// CHECK-LABEL: @test_vmul_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %a, [[VECINIT1_I]]
// CHECK:   ret <2 x i32> [[MUL_I]]
int32x2_t test_vmul_n_s32(int32x2_t a, int32_t b) {
  return vmul_n_s32(a, b);
}

// CHECK-LABEL: @test_vmul_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x float> undef, float %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x float> [[VECINIT_I]], float %b, i32 1
// CHECK:   [[MUL_I:%.*]] = fmul <2 x float> %a, [[VECINIT1_I]]
// CHECK:   ret <2 x float> [[MUL_I]]
float32x2_t test_vmul_n_f32(float32x2_t a, float32_t b) {
  return vmul_n_f32(a, b);
}

// CHECK-LABEL: @test_vmul_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i16> %a, [[VECINIT3_I]]
// CHECK:   ret <4 x i16> [[MUL_I]]
uint16x4_t test_vmul_n_u16(uint16x4_t a, uint16_t b) {
  return vmul_n_u16(a, b);
}

// CHECK-LABEL: @test_vmul_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[MUL_I:%.*]] = mul <2 x i32> %a, [[VECINIT1_I]]
// CHECK:   ret <2 x i32> [[MUL_I]]
uint32x2_t test_vmul_n_u32(uint32x2_t a, uint32_t b) {
  return vmul_n_u32(a, b);
}

// CHECK-LABEL: @test_vmulq_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %b, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %b, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %b, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %b, i32 7
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %a, [[VECINIT7_I]]
// CHECK:   ret <8 x i16> [[MUL_I]]
int16x8_t test_vmulq_n_s16(int16x8_t a, int16_t b) {
  return vmulq_n_s16(a, b);
}

// CHECK-LABEL: @test_vmulq_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %b, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %a, [[VECINIT3_I]]
// CHECK:   ret <4 x i32> [[MUL_I]]
int32x4_t test_vmulq_n_s32(int32x4_t a, int32_t b) {
  return vmulq_n_s32(a, b);
}

// CHECK-LABEL: @test_vmulq_n_f32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x float> undef, float %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x float> [[VECINIT_I]], float %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x float> [[VECINIT1_I]], float %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x float> [[VECINIT2_I]], float %b, i32 3
// CHECK:   [[MUL_I:%.*]] = fmul <4 x float> %a, [[VECINIT3_I]]
// CHECK:   ret <4 x float> [[MUL_I]]
float32x4_t test_vmulq_n_f32(float32x4_t a, float32_t b) {
  return vmulq_n_f32(a, b);
}

// CHECK-LABEL: @test_vmulq_n_u16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %b, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %b, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %b, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %b, i32 7
// CHECK:   [[MUL_I:%.*]] = mul <8 x i16> %a, [[VECINIT7_I]]
// CHECK:   ret <8 x i16> [[MUL_I]]
uint16x8_t test_vmulq_n_u16(uint16x8_t a, uint16_t b) {
  return vmulq_n_u16(a, b);
}

// CHECK-LABEL: @test_vmulq_n_u32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %b, i32 3
// CHECK:   [[MUL_I:%.*]] = mul <4 x i32> %a, [[VECINIT3_I]]
// CHECK:   ret <4 x i32> [[MUL_I]]
uint32x4_t test_vmulq_n_u32(uint32x4_t a, uint32_t b) {
  return vmulq_n_u32(a, b);
}

// CHECK-LABEL: @test_vmvn_s8(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i8> %a, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   ret <8 x i8> [[NEG_I]]
int8x8_t test_vmvn_s8(int8x8_t a) {
  return vmvn_s8(a);
}

// CHECK-LABEL: @test_vmvn_s16(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i16> %a, <i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   ret <4 x i16> [[NEG_I]]
int16x4_t test_vmvn_s16(int16x4_t a) {
  return vmvn_s16(a);
}

// CHECK-LABEL: @test_vmvn_s32(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i32> %a, <i32 -1, i32 -1>
// CHECK:   ret <2 x i32> [[NEG_I]]
int32x2_t test_vmvn_s32(int32x2_t a) {
  return vmvn_s32(a);
}

// CHECK-LABEL: @test_vmvn_u8(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i8> %a, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   ret <8 x i8> [[NEG_I]]
uint8x8_t test_vmvn_u8(uint8x8_t a) {
  return vmvn_u8(a);
}

// CHECK-LABEL: @test_vmvn_u16(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i16> %a, <i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   ret <4 x i16> [[NEG_I]]
uint16x4_t test_vmvn_u16(uint16x4_t a) {
  return vmvn_u16(a);
}

// CHECK-LABEL: @test_vmvn_u32(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i32> %a, <i32 -1, i32 -1>
// CHECK:   ret <2 x i32> [[NEG_I]]
uint32x2_t test_vmvn_u32(uint32x2_t a) {
  return vmvn_u32(a);
}

// CHECK-LABEL: @test_vmvn_p8(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i8> %a, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   ret <8 x i8> [[NEG_I]]
poly8x8_t test_vmvn_p8(poly8x8_t a) {
  return vmvn_p8(a);
}

// CHECK-LABEL: @test_vmvnq_s8(
// CHECK:   [[NEG_I:%.*]] = xor <16 x i8> %a, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   ret <16 x i8> [[NEG_I]]
int8x16_t test_vmvnq_s8(int8x16_t a) {
  return vmvnq_s8(a);
}

// CHECK-LABEL: @test_vmvnq_s16(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i16> %a, <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   ret <8 x i16> [[NEG_I]]
int16x8_t test_vmvnq_s16(int16x8_t a) {
  return vmvnq_s16(a);
}

// CHECK-LABEL: @test_vmvnq_s32(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i32> %a, <i32 -1, i32 -1, i32 -1, i32 -1>
// CHECK:   ret <4 x i32> [[NEG_I]]
int32x4_t test_vmvnq_s32(int32x4_t a) {
  return vmvnq_s32(a);
}

// CHECK-LABEL: @test_vmvnq_u8(
// CHECK:   [[NEG_I:%.*]] = xor <16 x i8> %a, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   ret <16 x i8> [[NEG_I]]
uint8x16_t test_vmvnq_u8(uint8x16_t a) {
  return vmvnq_u8(a);
}

// CHECK-LABEL: @test_vmvnq_u16(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i16> %a, <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   ret <8 x i16> [[NEG_I]]
uint16x8_t test_vmvnq_u16(uint16x8_t a) {
  return vmvnq_u16(a);
}

// CHECK-LABEL: @test_vmvnq_u32(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i32> %a, <i32 -1, i32 -1, i32 -1, i32 -1>
// CHECK:   ret <4 x i32> [[NEG_I]]
uint32x4_t test_vmvnq_u32(uint32x4_t a) {
  return vmvnq_u32(a);
}

// CHECK-LABEL: @test_vmvnq_p8(
// CHECK:   [[NEG_I:%.*]] = xor <16 x i8> %a, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   ret <16 x i8> [[NEG_I]]
poly8x16_t test_vmvnq_p8(poly8x16_t a) {
  return vmvnq_p8(a);
}

// CHECK-LABEL: @test_vneg_s8(
// CHECK:   [[SUB_I:%.*]] = sub <8 x i8> zeroinitializer, %a
// CHECK:   ret <8 x i8> [[SUB_I]]
int8x8_t test_vneg_s8(int8x8_t a) {
  return vneg_s8(a);
}

// CHECK-LABEL: @test_vneg_s16(
// CHECK:   [[SUB_I:%.*]] = sub <4 x i16> zeroinitializer, %a
// CHECK:   ret <4 x i16> [[SUB_I]]
int16x4_t test_vneg_s16(int16x4_t a) {
  return vneg_s16(a);
}

// CHECK-LABEL: @test_vneg_s32(
// CHECK:   [[SUB_I:%.*]] = sub <2 x i32> zeroinitializer, %a
// CHECK:   ret <2 x i32> [[SUB_I]]
int32x2_t test_vneg_s32(int32x2_t a) {
  return vneg_s32(a);
}

// CHECK-LABEL: @test_vneg_f32(
// CHECK:   [[SUB_I:%.*]] = fneg <2 x float> %a
// CHECK:   ret <2 x float> [[SUB_I]]
float32x2_t test_vneg_f32(float32x2_t a) {
  return vneg_f32(a);
}

// CHECK-LABEL: @test_vnegq_s8(
// CHECK:   [[SUB_I:%.*]] = sub <16 x i8> zeroinitializer, %a
// CHECK:   ret <16 x i8> [[SUB_I]]
int8x16_t test_vnegq_s8(int8x16_t a) {
  return vnegq_s8(a);
}

// CHECK-LABEL: @test_vnegq_s16(
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> zeroinitializer, %a
// CHECK:   ret <8 x i16> [[SUB_I]]
int16x8_t test_vnegq_s16(int16x8_t a) {
  return vnegq_s16(a);
}

// CHECK-LABEL: @test_vnegq_s32(
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> zeroinitializer, %a
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vnegq_s32(int32x4_t a) {
  return vnegq_s32(a);
}

// CHECK-LABEL: @test_vnegq_f32(
// CHECK:   [[SUB_I:%.*]] = fneg <4 x float> %a
// CHECK:   ret <4 x float> [[SUB_I]]
float32x4_t test_vnegq_f32(float32x4_t a) {
  return vnegq_f32(a);
}

// CHECK-LABEL: @test_vorn_s8(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[OR_I:%.*]] = or <8 x i8> %a, [[NEG_I]]
// CHECK:   ret <8 x i8> [[OR_I]]
int8x8_t test_vorn_s8(int8x8_t a, int8x8_t b) {
  return vorn_s8(a, b);
}

// CHECK-LABEL: @test_vorn_s16(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[OR_I:%.*]] = or <4 x i16> %a, [[NEG_I]]
// CHECK:   ret <4 x i16> [[OR_I]]
int16x4_t test_vorn_s16(int16x4_t a, int16x4_t b) {
  return vorn_s16(a, b);
}

// CHECK-LABEL: @test_vorn_s32(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i32> %b, <i32 -1, i32 -1>
// CHECK:   [[OR_I:%.*]] = or <2 x i32> %a, [[NEG_I]]
// CHECK:   ret <2 x i32> [[OR_I]]
int32x2_t test_vorn_s32(int32x2_t a, int32x2_t b) {
  return vorn_s32(a, b);
}

// CHECK-LABEL: @test_vorn_s64(
// CHECK:   [[NEG_I:%.*]] = xor <1 x i64> %b, <i64 -1>
// CHECK:   [[OR_I:%.*]] = or <1 x i64> %a, [[NEG_I]]
// CHECK:   ret <1 x i64> [[OR_I]]
int64x1_t test_vorn_s64(int64x1_t a, int64x1_t b) {
  return vorn_s64(a, b);
}

// CHECK-LABEL: @test_vorn_u8(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[OR_I:%.*]] = or <8 x i8> %a, [[NEG_I]]
// CHECK:   ret <8 x i8> [[OR_I]]
uint8x8_t test_vorn_u8(uint8x8_t a, uint8x8_t b) {
  return vorn_u8(a, b);
}

// CHECK-LABEL: @test_vorn_u16(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[OR_I:%.*]] = or <4 x i16> %a, [[NEG_I]]
// CHECK:   ret <4 x i16> [[OR_I]]
uint16x4_t test_vorn_u16(uint16x4_t a, uint16x4_t b) {
  return vorn_u16(a, b);
}

// CHECK-LABEL: @test_vorn_u32(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i32> %b, <i32 -1, i32 -1>
// CHECK:   [[OR_I:%.*]] = or <2 x i32> %a, [[NEG_I]]
// CHECK:   ret <2 x i32> [[OR_I]]
uint32x2_t test_vorn_u32(uint32x2_t a, uint32x2_t b) {
  return vorn_u32(a, b);
}

// CHECK-LABEL: @test_vorn_u64(
// CHECK:   [[NEG_I:%.*]] = xor <1 x i64> %b, <i64 -1>
// CHECK:   [[OR_I:%.*]] = or <1 x i64> %a, [[NEG_I]]
// CHECK:   ret <1 x i64> [[OR_I]]
uint64x1_t test_vorn_u64(uint64x1_t a, uint64x1_t b) {
  return vorn_u64(a, b);
}

// CHECK-LABEL: @test_vornq_s8(
// CHECK:   [[NEG_I:%.*]] = xor <16 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[OR_I:%.*]] = or <16 x i8> %a, [[NEG_I]]
// CHECK:   ret <16 x i8> [[OR_I]]
int8x16_t test_vornq_s8(int8x16_t a, int8x16_t b) {
  return vornq_s8(a, b);
}

// CHECK-LABEL: @test_vornq_s16(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[OR_I:%.*]] = or <8 x i16> %a, [[NEG_I]]
// CHECK:   ret <8 x i16> [[OR_I]]
int16x8_t test_vornq_s16(int16x8_t a, int16x8_t b) {
  return vornq_s16(a, b);
}

// CHECK-LABEL: @test_vornq_s32(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i32> %b, <i32 -1, i32 -1, i32 -1, i32 -1>
// CHECK:   [[OR_I:%.*]] = or <4 x i32> %a, [[NEG_I]]
// CHECK:   ret <4 x i32> [[OR_I]]
int32x4_t test_vornq_s32(int32x4_t a, int32x4_t b) {
  return vornq_s32(a, b);
}

// CHECK-LABEL: @test_vornq_s64(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i64> %b, <i64 -1, i64 -1>
// CHECK:   [[OR_I:%.*]] = or <2 x i64> %a, [[NEG_I]]
// CHECK:   ret <2 x i64> [[OR_I]]
int64x2_t test_vornq_s64(int64x2_t a, int64x2_t b) {
  return vornq_s64(a, b);
}

// CHECK-LABEL: @test_vornq_u8(
// CHECK:   [[NEG_I:%.*]] = xor <16 x i8> %b, <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
// CHECK:   [[OR_I:%.*]] = or <16 x i8> %a, [[NEG_I]]
// CHECK:   ret <16 x i8> [[OR_I]]
uint8x16_t test_vornq_u8(uint8x16_t a, uint8x16_t b) {
  return vornq_u8(a, b);
}

// CHECK-LABEL: @test_vornq_u16(
// CHECK:   [[NEG_I:%.*]] = xor <8 x i16> %b, <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
// CHECK:   [[OR_I:%.*]] = or <8 x i16> %a, [[NEG_I]]
// CHECK:   ret <8 x i16> [[OR_I]]
uint16x8_t test_vornq_u16(uint16x8_t a, uint16x8_t b) {
  return vornq_u16(a, b);
}

// CHECK-LABEL: @test_vornq_u32(
// CHECK:   [[NEG_I:%.*]] = xor <4 x i32> %b, <i32 -1, i32 -1, i32 -1, i32 -1>
// CHECK:   [[OR_I:%.*]] = or <4 x i32> %a, [[NEG_I]]
// CHECK:   ret <4 x i32> [[OR_I]]
uint32x4_t test_vornq_u32(uint32x4_t a, uint32x4_t b) {
  return vornq_u32(a, b);
}

// CHECK-LABEL: @test_vornq_u64(
// CHECK:   [[NEG_I:%.*]] = xor <2 x i64> %b, <i64 -1, i64 -1>
// CHECK:   [[OR_I:%.*]] = or <2 x i64> %a, [[NEG_I]]
// CHECK:   ret <2 x i64> [[OR_I]]
uint64x2_t test_vornq_u64(uint64x2_t a, uint64x2_t b) {
  return vornq_u64(a, b);
}

// CHECK-LABEL: @test_vorr_s8(
// CHECK:   [[OR_I:%.*]] = or <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[OR_I]]
int8x8_t test_vorr_s8(int8x8_t a, int8x8_t b) {
  return vorr_s8(a, b);
}

// CHECK-LABEL: @test_vorr_s16(
// CHECK:   [[OR_I:%.*]] = or <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[OR_I]]
int16x4_t test_vorr_s16(int16x4_t a, int16x4_t b) {
  return vorr_s16(a, b);
}

// CHECK-LABEL: @test_vorr_s32(
// CHECK:   [[OR_I:%.*]] = or <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[OR_I]]
int32x2_t test_vorr_s32(int32x2_t a, int32x2_t b) {
  return vorr_s32(a, b);
}

// CHECK-LABEL: @test_vorr_s64(
// CHECK:   [[OR_I:%.*]] = or <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[OR_I]]
int64x1_t test_vorr_s64(int64x1_t a, int64x1_t b) {
  return vorr_s64(a, b);
}

// CHECK-LABEL: @test_vorr_u8(
// CHECK:   [[OR_I:%.*]] = or <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[OR_I]]
uint8x8_t test_vorr_u8(uint8x8_t a, uint8x8_t b) {
  return vorr_u8(a, b);
}

// CHECK-LABEL: @test_vorr_u16(
// CHECK:   [[OR_I:%.*]] = or <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[OR_I]]
uint16x4_t test_vorr_u16(uint16x4_t a, uint16x4_t b) {
  return vorr_u16(a, b);
}

// CHECK-LABEL: @test_vorr_u32(
// CHECK:   [[OR_I:%.*]] = or <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[OR_I]]
uint32x2_t test_vorr_u32(uint32x2_t a, uint32x2_t b) {
  return vorr_u32(a, b);
}

// CHECK-LABEL: @test_vorr_u64(
// CHECK:   [[OR_I:%.*]] = or <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[OR_I]]
uint64x1_t test_vorr_u64(uint64x1_t a, uint64x1_t b) {
  return vorr_u64(a, b);
}

// CHECK-LABEL: @test_vorrq_s8(
// CHECK:   [[OR_I:%.*]] = or <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[OR_I]]
int8x16_t test_vorrq_s8(int8x16_t a, int8x16_t b) {
  return vorrq_s8(a, b);
}

// CHECK-LABEL: @test_vorrq_s16(
// CHECK:   [[OR_I:%.*]] = or <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[OR_I]]
int16x8_t test_vorrq_s16(int16x8_t a, int16x8_t b) {
  return vorrq_s16(a, b);
}

// CHECK-LABEL: @test_vorrq_s32(
// CHECK:   [[OR_I:%.*]] = or <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[OR_I]]
int32x4_t test_vorrq_s32(int32x4_t a, int32x4_t b) {
  return vorrq_s32(a, b);
}

// CHECK-LABEL: @test_vorrq_s64(
// CHECK:   [[OR_I:%.*]] = or <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[OR_I]]
int64x2_t test_vorrq_s64(int64x2_t a, int64x2_t b) {
  return vorrq_s64(a, b);
}

// CHECK-LABEL: @test_vorrq_u8(
// CHECK:   [[OR_I:%.*]] = or <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[OR_I]]
uint8x16_t test_vorrq_u8(uint8x16_t a, uint8x16_t b) {
  return vorrq_u8(a, b);
}

// CHECK-LABEL: @test_vorrq_u16(
// CHECK:   [[OR_I:%.*]] = or <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[OR_I]]
uint16x8_t test_vorrq_u16(uint16x8_t a, uint16x8_t b) {
  return vorrq_u16(a, b);
}

// CHECK-LABEL: @test_vorrq_u32(
// CHECK:   [[OR_I:%.*]] = or <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[OR_I]]
uint32x4_t test_vorrq_u32(uint32x4_t a, uint32x4_t b) {
  return vorrq_u32(a, b);
}

// CHECK-LABEL: @test_vorrq_u64(
// CHECK:   [[OR_I:%.*]] = or <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[OR_I]]
uint64x2_t test_vorrq_u64(uint64x2_t a, uint64x2_t b) {
  return vorrq_u64(a, b);
}

// CHECK-LABEL: @test_vpadal_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VPADAL_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpadals.v4i16.v8i8(<4 x i16> %a, <8 x i8> %b)
// CHECK:   ret <4 x i16> [[VPADAL_V1_I]]
int16x4_t test_vpadal_s8(int16x4_t a, int8x8_t b) {
  return vpadal_s8(a, b);
}

// CHECK-LABEL: @test_vpadal_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPADAL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpadals.v2i32.v4i16(<2 x i32> %a, <4 x i16> %b)
// CHECK:   ret <2 x i32> [[VPADAL_V2_I]]
int32x2_t test_vpadal_s16(int32x2_t a, int16x4_t b) {
  return vpadal_s16(a, b);
}

// CHECK-LABEL: @test_vpadal_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPADAL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vpadals.v1i64.v2i32(<1 x i64> %a, <2 x i32> %b)
// CHECK:   ret <1 x i64> [[VPADAL_V2_I]]
int64x1_t test_vpadal_s32(int64x1_t a, int32x2_t b) {
  return vpadal_s32(a, b);
}

// CHECK-LABEL: @test_vpadal_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VPADAL_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpadalu.v4i16.v8i8(<4 x i16> %a, <8 x i8> %b)
// CHECK:   ret <4 x i16> [[VPADAL_V1_I]]
uint16x4_t test_vpadal_u8(uint16x4_t a, uint8x8_t b) {
  return vpadal_u8(a, b);
}

// CHECK-LABEL: @test_vpadal_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPADAL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpadalu.v2i32.v4i16(<2 x i32> %a, <4 x i16> %b)
// CHECK:   ret <2 x i32> [[VPADAL_V2_I]]
uint32x2_t test_vpadal_u16(uint32x2_t a, uint16x4_t b) {
  return vpadal_u16(a, b);
}

// CHECK-LABEL: @test_vpadal_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPADAL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vpadalu.v1i64.v2i32(<1 x i64> %a, <2 x i32> %b)
// CHECK:   ret <1 x i64> [[VPADAL_V2_I]]
uint64x1_t test_vpadal_u32(uint64x1_t a, uint32x2_t b) {
  return vpadal_u32(a, b);
}

// CHECK-LABEL: @test_vpadalq_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VPADALQ_V1_I:%.*]] = call <8 x i16> @llvm.arm.neon.vpadals.v8i16.v16i8(<8 x i16> %a, <16 x i8> %b)
// CHECK:   ret <8 x i16> [[VPADALQ_V1_I]]
int16x8_t test_vpadalq_s8(int16x8_t a, int8x16_t b) {
  return vpadalq_s8(a, b);
}

// CHECK-LABEL: @test_vpadalq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VPADALQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vpadals.v4i32.v8i16(<4 x i32> %a, <8 x i16> %b)
// CHECK:   ret <4 x i32> [[VPADALQ_V2_I]]
int32x4_t test_vpadalq_s16(int32x4_t a, int16x8_t b) {
  return vpadalq_s16(a, b);
}

// CHECK-LABEL: @test_vpadalq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VPADALQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vpadals.v2i64.v4i32(<2 x i64> %a, <4 x i32> %b)
// CHECK:   ret <2 x i64> [[VPADALQ_V2_I]]
int64x2_t test_vpadalq_s32(int64x2_t a, int32x4_t b) {
  return vpadalq_s32(a, b);
}

// CHECK-LABEL: @test_vpadalq_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VPADALQ_V1_I:%.*]] = call <8 x i16> @llvm.arm.neon.vpadalu.v8i16.v16i8(<8 x i16> %a, <16 x i8> %b)
// CHECK:   ret <8 x i16> [[VPADALQ_V1_I]]
uint16x8_t test_vpadalq_u8(uint16x8_t a, uint8x16_t b) {
  return vpadalq_u8(a, b);
}

// CHECK-LABEL: @test_vpadalq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VPADALQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vpadalu.v4i32.v8i16(<4 x i32> %a, <8 x i16> %b)
// CHECK:   ret <4 x i32> [[VPADALQ_V2_I]]
uint32x4_t test_vpadalq_u16(uint32x4_t a, uint16x8_t b) {
  return vpadalq_u16(a, b);
}

// CHECK-LABEL: @test_vpadalq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VPADALQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vpadalu.v2i64.v4i32(<2 x i64> %a, <4 x i32> %b)
// CHECK:   ret <2 x i64> [[VPADALQ_V2_I]]
uint64x2_t test_vpadalq_u32(uint64x2_t a, uint32x4_t b) {
  return vpadalq_u32(a, b);
}

// CHECK-LABEL: @test_vpadd_s8(
// CHECK:   [[VPADD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vpadd.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VPADD_V_I]]
int8x8_t test_vpadd_s8(int8x8_t a, int8x8_t b) {
  return vpadd_s8(a, b);
}

// CHECK-LABEL: @test_vpadd_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPADD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpadd.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VPADD_V3_I:%.*]] = bitcast <4 x i16> [[VPADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VPADD_V2_I]]
int16x4_t test_vpadd_s16(int16x4_t a, int16x4_t b) {
  return vpadd_s16(a, b);
}

// CHECK-LABEL: @test_vpadd_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPADD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpadd.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VPADD_V3_I:%.*]] = bitcast <2 x i32> [[VPADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VPADD_V2_I]]
int32x2_t test_vpadd_s32(int32x2_t a, int32x2_t b) {
  return vpadd_s32(a, b);
}

// CHECK-LABEL: @test_vpadd_u8(
// CHECK:   [[VPADD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vpadd.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VPADD_V_I]]
uint8x8_t test_vpadd_u8(uint8x8_t a, uint8x8_t b) {
  return vpadd_u8(a, b);
}

// CHECK-LABEL: @test_vpadd_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPADD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpadd.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VPADD_V3_I:%.*]] = bitcast <4 x i16> [[VPADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VPADD_V2_I]]
uint16x4_t test_vpadd_u16(uint16x4_t a, uint16x4_t b) {
  return vpadd_u16(a, b);
}

// CHECK-LABEL: @test_vpadd_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPADD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpadd.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VPADD_V3_I:%.*]] = bitcast <2 x i32> [[VPADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VPADD_V2_I]]
uint32x2_t test_vpadd_u32(uint32x2_t a, uint32x2_t b) {
  return vpadd_u32(a, b);
}

// CHECK-LABEL: @test_vpadd_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VPADD_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vpadd.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VPADD_V3_I:%.*]] = bitcast <2 x float> [[VPADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VPADD_V2_I]]
float32x2_t test_vpadd_f32(float32x2_t a, float32x2_t b) {
  return vpadd_f32(a, b);
}

// CHECK-LABEL: @test_vpaddl_s8(
// CHECK:   [[VPADDL_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpaddls.v4i16.v8i8(<8 x i8> %a)
// CHECK:   ret <4 x i16> [[VPADDL_I]]
int16x4_t test_vpaddl_s8(int8x8_t a) {
  return vpaddl_s8(a);
}

// CHECK-LABEL: @test_vpaddl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpaddls.v2i32.v4i16(<4 x i16> %a)
// CHECK:   ret <2 x i32> [[VPADDL1_I]]
int32x2_t test_vpaddl_s16(int16x4_t a) {
  return vpaddl_s16(a);
}

// CHECK-LABEL: @test_vpaddl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <1 x i64> @llvm.arm.neon.vpaddls.v1i64.v2i32(<2 x i32> %a)
// CHECK:   ret <1 x i64> [[VPADDL1_I]]
int64x1_t test_vpaddl_s32(int32x2_t a) {
  return vpaddl_s32(a);
}

// CHECK-LABEL: @test_vpaddl_u8(
// CHECK:   [[VPADDL_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpaddlu.v4i16.v8i8(<8 x i8> %a)
// CHECK:   ret <4 x i16> [[VPADDL_I]]
uint16x4_t test_vpaddl_u8(uint8x8_t a) {
  return vpaddl_u8(a);
}

// CHECK-LABEL: @test_vpaddl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpaddlu.v2i32.v4i16(<4 x i16> %a)
// CHECK:   ret <2 x i32> [[VPADDL1_I]]
uint32x2_t test_vpaddl_u16(uint16x4_t a) {
  return vpaddl_u16(a);
}

// CHECK-LABEL: @test_vpaddl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <1 x i64> @llvm.arm.neon.vpaddlu.v1i64.v2i32(<2 x i32> %a)
// CHECK:   ret <1 x i64> [[VPADDL1_I]]
uint64x1_t test_vpaddl_u32(uint32x2_t a) {
  return vpaddl_u32(a);
}

// CHECK-LABEL: @test_vpaddlq_s8(
// CHECK:   [[VPADDL_I:%.*]] = call <8 x i16> @llvm.arm.neon.vpaddls.v8i16.v16i8(<16 x i8> %a)
// CHECK:   ret <8 x i16> [[VPADDL_I]]
int16x8_t test_vpaddlq_s8(int8x16_t a) {
  return vpaddlq_s8(a);
}

// CHECK-LABEL: @test_vpaddlq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vpaddls.v4i32.v8i16(<8 x i16> %a)
// CHECK:   ret <4 x i32> [[VPADDL1_I]]
int32x4_t test_vpaddlq_s16(int16x8_t a) {
  return vpaddlq_s16(a);
}

// CHECK-LABEL: @test_vpaddlq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <2 x i64> @llvm.arm.neon.vpaddls.v2i64.v4i32(<4 x i32> %a)
// CHECK:   ret <2 x i64> [[VPADDL1_I]]
int64x2_t test_vpaddlq_s32(int32x4_t a) {
  return vpaddlq_s32(a);
}

// CHECK-LABEL: @test_vpaddlq_u8(
// CHECK:   [[VPADDL_I:%.*]] = call <8 x i16> @llvm.arm.neon.vpaddlu.v8i16.v16i8(<16 x i8> %a)
// CHECK:   ret <8 x i16> [[VPADDL_I]]
uint16x8_t test_vpaddlq_u8(uint8x16_t a) {
  return vpaddlq_u8(a);
}

// CHECK-LABEL: @test_vpaddlq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vpaddlu.v4i32.v8i16(<8 x i16> %a)
// CHECK:   ret <4 x i32> [[VPADDL1_I]]
uint32x4_t test_vpaddlq_u16(uint16x8_t a) {
  return vpaddlq_u16(a);
}

// CHECK-LABEL: @test_vpaddlq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VPADDL1_I:%.*]] = call <2 x i64> @llvm.arm.neon.vpaddlu.v2i64.v4i32(<4 x i32> %a)
// CHECK:   ret <2 x i64> [[VPADDL1_I]]
uint64x2_t test_vpaddlq_u32(uint32x4_t a) {
  return vpaddlq_u32(a);
}

// CHECK-LABEL: @test_vpmax_s8(
// CHECK:   [[VPMAX_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vpmaxs.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VPMAX_V_I]]
int8x8_t test_vpmax_s8(int8x8_t a, int8x8_t b) {
  return vpmax_s8(a, b);
}

// CHECK-LABEL: @test_vpmax_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPMAX_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpmaxs.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VPMAX_V3_I:%.*]] = bitcast <4 x i16> [[VPMAX_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VPMAX_V2_I]]
int16x4_t test_vpmax_s16(int16x4_t a, int16x4_t b) {
  return vpmax_s16(a, b);
}

// CHECK-LABEL: @test_vpmax_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPMAX_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpmaxs.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VPMAX_V3_I:%.*]] = bitcast <2 x i32> [[VPMAX_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VPMAX_V2_I]]
int32x2_t test_vpmax_s32(int32x2_t a, int32x2_t b) {
  return vpmax_s32(a, b);
}

// CHECK-LABEL: @test_vpmax_u8(
// CHECK:   [[VPMAX_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vpmaxu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VPMAX_V_I]]
uint8x8_t test_vpmax_u8(uint8x8_t a, uint8x8_t b) {
  return vpmax_u8(a, b);
}

// CHECK-LABEL: @test_vpmax_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPMAX_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpmaxu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VPMAX_V3_I:%.*]] = bitcast <4 x i16> [[VPMAX_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VPMAX_V2_I]]
uint16x4_t test_vpmax_u16(uint16x4_t a, uint16x4_t b) {
  return vpmax_u16(a, b);
}

// CHECK-LABEL: @test_vpmax_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPMAX_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpmaxu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VPMAX_V3_I:%.*]] = bitcast <2 x i32> [[VPMAX_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VPMAX_V2_I]]
uint32x2_t test_vpmax_u32(uint32x2_t a, uint32x2_t b) {
  return vpmax_u32(a, b);
}

// CHECK-LABEL: @test_vpmax_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VPMAX_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vpmaxs.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VPMAX_V3_I:%.*]] = bitcast <2 x float> [[VPMAX_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VPMAX_V2_I]]
float32x2_t test_vpmax_f32(float32x2_t a, float32x2_t b) {
  return vpmax_f32(a, b);
}

// CHECK-LABEL: @test_vpmin_s8(
// CHECK:   [[VPMIN_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vpmins.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VPMIN_V_I]]
int8x8_t test_vpmin_s8(int8x8_t a, int8x8_t b) {
  return vpmin_s8(a, b);
}

// CHECK-LABEL: @test_vpmin_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPMIN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpmins.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VPMIN_V3_I:%.*]] = bitcast <4 x i16> [[VPMIN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VPMIN_V2_I]]
int16x4_t test_vpmin_s16(int16x4_t a, int16x4_t b) {
  return vpmin_s16(a, b);
}

// CHECK-LABEL: @test_vpmin_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPMIN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpmins.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VPMIN_V3_I:%.*]] = bitcast <2 x i32> [[VPMIN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VPMIN_V2_I]]
int32x2_t test_vpmin_s32(int32x2_t a, int32x2_t b) {
  return vpmin_s32(a, b);
}

// CHECK-LABEL: @test_vpmin_u8(
// CHECK:   [[VPMIN_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vpminu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VPMIN_V_I]]
uint8x8_t test_vpmin_u8(uint8x8_t a, uint8x8_t b) {
  return vpmin_u8(a, b);
}

// CHECK-LABEL: @test_vpmin_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VPMIN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vpminu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VPMIN_V3_I:%.*]] = bitcast <4 x i16> [[VPMIN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VPMIN_V2_I]]
uint16x4_t test_vpmin_u16(uint16x4_t a, uint16x4_t b) {
  return vpmin_u16(a, b);
}

// CHECK-LABEL: @test_vpmin_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VPMIN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vpminu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VPMIN_V3_I:%.*]] = bitcast <2 x i32> [[VPMIN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VPMIN_V2_I]]
uint32x2_t test_vpmin_u32(uint32x2_t a, uint32x2_t b) {
  return vpmin_u32(a, b);
}

// CHECK-LABEL: @test_vpmin_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VPMIN_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vpmins.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VPMIN_V3_I:%.*]] = bitcast <2 x float> [[VPMIN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VPMIN_V2_I]]
float32x2_t test_vpmin_f32(float32x2_t a, float32x2_t b) {
  return vpmin_f32(a, b);
}

// CHECK-LABEL: @test_vqabs_s8(
// CHECK:   [[VQABS_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqabs.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VQABS_V_I]]
int8x8_t test_vqabs_s8(int8x8_t a) {
  return vqabs_s8(a);
}

// CHECK-LABEL: @test_vqabs_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VQABS_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqabs.v4i16(<4 x i16> %a)
// CHECK:   [[VQABS_V2_I:%.*]] = bitcast <4 x i16> [[VQABS_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQABS_V1_I]]
int16x4_t test_vqabs_s16(int16x4_t a) {
  return vqabs_s16(a);
}

// CHECK-LABEL: @test_vqabs_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VQABS_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqabs.v2i32(<2 x i32> %a)
// CHECK:   [[VQABS_V2_I:%.*]] = bitcast <2 x i32> [[VQABS_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQABS_V1_I]]
int32x2_t test_vqabs_s32(int32x2_t a) {
  return vqabs_s32(a);
}

// CHECK-LABEL: @test_vqabsq_s8(
// CHECK:   [[VQABSQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vqabs.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VQABSQ_V_I]]
int8x16_t test_vqabsq_s8(int8x16_t a) {
  return vqabsq_s8(a);
}

// CHECK-LABEL: @test_vqabsq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQABSQ_V1_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqabs.v8i16(<8 x i16> %a)
// CHECK:   [[VQABSQ_V2_I:%.*]] = bitcast <8 x i16> [[VQABSQ_V1_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQABSQ_V1_I]]
int16x8_t test_vqabsq_s16(int16x8_t a) {
  return vqabsq_s16(a);
}

// CHECK-LABEL: @test_vqabsq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQABSQ_V1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqabs.v4i32(<4 x i32> %a)
// CHECK:   [[VQABSQ_V2_I:%.*]] = bitcast <4 x i32> [[VQABSQ_V1_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQABSQ_V1_I]]
int32x4_t test_vqabsq_s32(int32x4_t a) {
  return vqabsq_s32(a);
}

// CHECK-LABEL: @test_vqadd_s8(
// CHECK:   [[VQADD_V_I:%.*]] = call <8 x i8> @llvm.sadd.sat.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQADD_V_I]]
int8x8_t test_vqadd_s8(int8x8_t a, int8x8_t b) {
  return vqadd_s8(a, b);
}

// CHECK-LABEL: @test_vqadd_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQADD_V2_I:%.*]] = call <4 x i16> @llvm.sadd.sat.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQADD_V3_I:%.*]] = bitcast <4 x i16> [[VQADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQADD_V2_I]]
int16x4_t test_vqadd_s16(int16x4_t a, int16x4_t b) {
  return vqadd_s16(a, b);
}

// CHECK-LABEL: @test_vqadd_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQADD_V2_I:%.*]] = call <2 x i32> @llvm.sadd.sat.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQADD_V3_I:%.*]] = bitcast <2 x i32> [[VQADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQADD_V2_I]]
int32x2_t test_vqadd_s32(int32x2_t a, int32x2_t b) {
  return vqadd_s32(a, b);
}

// CHECK-LABEL: @test_vqadd_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQADD_V2_I:%.*]] = call <1 x i64> @llvm.sadd.sat.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQADD_V3_I:%.*]] = bitcast <1 x i64> [[VQADD_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQADD_V2_I]]
int64x1_t test_vqadd_s64(int64x1_t a, int64x1_t b) {
  return vqadd_s64(a, b);
}

// CHECK-LABEL: @test_vqadd_u8(
// CHECK:   [[VQADD_V_I:%.*]] = call <8 x i8> @llvm.uadd.sat.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQADD_V_I]]
uint8x8_t test_vqadd_u8(uint8x8_t a, uint8x8_t b) {
  return vqadd_u8(a, b);
}

// CHECK-LABEL: @test_vqadd_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQADD_V2_I:%.*]] = call <4 x i16> @llvm.uadd.sat.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQADD_V3_I:%.*]] = bitcast <4 x i16> [[VQADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQADD_V2_I]]
uint16x4_t test_vqadd_u16(uint16x4_t a, uint16x4_t b) {
  return vqadd_u16(a, b);
}

// CHECK-LABEL: @test_vqadd_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQADD_V2_I:%.*]] = call <2 x i32> @llvm.uadd.sat.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQADD_V3_I:%.*]] = bitcast <2 x i32> [[VQADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQADD_V2_I]]
uint32x2_t test_vqadd_u32(uint32x2_t a, uint32x2_t b) {
  return vqadd_u32(a, b);
}

// CHECK-LABEL: @test_vqadd_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQADD_V2_I:%.*]] = call <1 x i64> @llvm.uadd.sat.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQADD_V3_I:%.*]] = bitcast <1 x i64> [[VQADD_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQADD_V2_I]]
uint64x1_t test_vqadd_u64(uint64x1_t a, uint64x1_t b) {
  return vqadd_u64(a, b);
}

// CHECK-LABEL: @test_vqaddq_s8(
// CHECK:   [[VQADDQ_V_I:%.*]] = call <16 x i8> @llvm.sadd.sat.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQADDQ_V_I]]
int8x16_t test_vqaddq_s8(int8x16_t a, int8x16_t b) {
  return vqaddq_s8(a, b);
}

// CHECK-LABEL: @test_vqaddq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQADDQ_V2_I:%.*]] = call <8 x i16> @llvm.sadd.sat.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQADDQ_V3_I:%.*]] = bitcast <8 x i16> [[VQADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQADDQ_V2_I]]
int16x8_t test_vqaddq_s16(int16x8_t a, int16x8_t b) {
  return vqaddq_s16(a, b);
}

// CHECK-LABEL: @test_vqaddq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQADDQ_V2_I:%.*]] = call <4 x i32> @llvm.sadd.sat.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQADDQ_V3_I:%.*]] = bitcast <4 x i32> [[VQADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQADDQ_V2_I]]
int32x4_t test_vqaddq_s32(int32x4_t a, int32x4_t b) {
  return vqaddq_s32(a, b);
}

// CHECK-LABEL: @test_vqaddq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQADDQ_V2_I:%.*]] = call <2 x i64> @llvm.sadd.sat.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQADDQ_V3_I:%.*]] = bitcast <2 x i64> [[VQADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQADDQ_V2_I]]
int64x2_t test_vqaddq_s64(int64x2_t a, int64x2_t b) {
  return vqaddq_s64(a, b);
}

// CHECK-LABEL: @test_vqaddq_u8(
// CHECK:   [[VQADDQ_V_I:%.*]] = call <16 x i8> @llvm.uadd.sat.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQADDQ_V_I]]
uint8x16_t test_vqaddq_u8(uint8x16_t a, uint8x16_t b) {
  return vqaddq_u8(a, b);
}

// CHECK-LABEL: @test_vqaddq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQADDQ_V2_I:%.*]] = call <8 x i16> @llvm.uadd.sat.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQADDQ_V3_I:%.*]] = bitcast <8 x i16> [[VQADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQADDQ_V2_I]]
uint16x8_t test_vqaddq_u16(uint16x8_t a, uint16x8_t b) {
  return vqaddq_u16(a, b);
}

// CHECK-LABEL: @test_vqaddq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQADDQ_V2_I:%.*]] = call <4 x i32> @llvm.uadd.sat.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQADDQ_V3_I:%.*]] = bitcast <4 x i32> [[VQADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQADDQ_V2_I]]
uint32x4_t test_vqaddq_u32(uint32x4_t a, uint32x4_t b) {
  return vqaddq_u32(a, b);
}

// CHECK-LABEL: @test_vqaddq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQADDQ_V2_I:%.*]] = call <2 x i64> @llvm.uadd.sat.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQADDQ_V3_I:%.*]] = bitcast <2 x i64> [[VQADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQADDQ_V2_I]]
uint64x2_t test_vqaddq_u64(uint64x2_t a, uint64x2_t b) {
  return vqaddq_u64(a, b);
}

// CHECK-LABEL: @test_vqdmlal_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[VQDMLAL_V3_I:%.*]] = call <4 x i32> @llvm.sadd.sat.v4i32(<4 x i32> %a, <4 x i32> [[VQDMLAL2_I]])
// CHECK:   ret <4 x i32> [[VQDMLAL_V3_I]]
int32x4_t test_vqdmlal_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vqdmlal_s16(a, b, c);
}

// CHECK-LABEL: @test_vqdmlal_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[VQDMLAL_V3_I:%.*]] = call <2 x i64> @llvm.sadd.sat.v2i64(<2 x i64> %a, <2 x i64> [[VQDMLAL2_I]])
// CHECK:   ret <2 x i64> [[VQDMLAL_V3_I]]
int64x2_t test_vqdmlal_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vqdmlal_s32(a, b, c);
}

// CHECK-LABEL: @test_vqdmlal_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP4:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> [[B]], <4 x i16> [[LANE]])
// CHECK:   [[VQDMLAL_V3_I:%.*]] = call <4 x i32> @llvm.sadd.sat.v4i32(<4 x i32> [[A]], <4 x i32> [[VQDMLAL2_I]])
// CHECK:   ret <4 x i32> [[VQDMLAL_V3_I]]
int32x4_t test_vqdmlal_lane_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vqdmlal_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vqdmlal_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i64> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP4:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> [[B]], <2 x i32> [[LANE]])
// CHECK:   [[VQDMLAL_V3_I:%.*]] = call <2 x i64> @llvm.sadd.sat.v2i64(<2 x i64> [[A]], <2 x i64> [[VQDMLAL2_I]])
// CHECK:   ret <2 x i64> [[VQDMLAL_V3_I]]
int64x2_t test_vqdmlal_lane_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vqdmlal_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vqdmlal_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VQDMLAL5_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> %b, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[VQDMLAL_V6_I:%.*]] = call <4 x i32> @llvm.sadd.sat.v4i32(<4 x i32> %a, <4 x i32> [[VQDMLAL5_I]])
// CHECK:   ret <4 x i32> [[VQDMLAL_V6_I]]
int32x4_t test_vqdmlal_n_s16(int32x4_t a, int16x4_t b, int16_t c) {
  return vqdmlal_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vqdmlal_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VQDMLAL3_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> %b, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[VQDMLAL_V4_I:%.*]] = call <2 x i64> @llvm.sadd.sat.v2i64(<2 x i64> %a, <2 x i64> [[VQDMLAL3_I]])
// CHECK:   ret <2 x i64> [[VQDMLAL_V4_I]]
int64x2_t test_vqdmlal_n_s32(int64x2_t a, int32x2_t b, int32_t c) {
  return vqdmlal_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vqdmlsl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %c to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> %b, <4 x i16> %c)
// CHECK:   [[VQDMLSL_V3_I:%.*]] = call <4 x i32> @llvm.ssub.sat.v4i32(<4 x i32> %a, <4 x i32> [[VQDMLAL2_I]])
// CHECK:   ret <4 x i32> [[VQDMLSL_V3_I]]
int32x4_t test_vqdmlsl_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vqdmlsl_s16(a, b, c);
}

// CHECK-LABEL: @test_vqdmlsl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %c to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> %b, <2 x i32> %c)
// CHECK:   [[VQDMLSL_V3_I:%.*]] = call <2 x i64> @llvm.ssub.sat.v2i64(<2 x i64> %a, <2 x i64> [[VQDMLAL2_I]])
// CHECK:   ret <2 x i64> [[VQDMLSL_V3_I]]
int64x2_t test_vqdmlsl_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vqdmlsl_s32(a, b, c);
}

// CHECK-LABEL: @test_vqdmlsl_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP4:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> [[B]], <4 x i16> [[LANE]])
// CHECK:   [[VQDMLSL_V3_I:%.*]] = call <4 x i32> @llvm.ssub.sat.v4i32(<4 x i32> [[A]], <4 x i32> [[VQDMLAL2_I]])
// CHECK:   ret <4 x i32> [[VQDMLSL_V3_I]]
int32x4_t test_vqdmlsl_lane_s16(int32x4_t a, int16x4_t b, int16x4_t c) {
  return vqdmlsl_lane_s16(a, b, c, 3);
}

// CHECK-LABEL: @test_vqdmlsl_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[C:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i64> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP4:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMLAL2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> [[B]], <2 x i32> [[LANE]])
// CHECK:   [[VQDMLSL_V3_I:%.*]] = call <2 x i64> @llvm.ssub.sat.v2i64(<2 x i64> [[A]], <2 x i64> [[VQDMLAL2_I]])
// CHECK:   ret <2 x i64> [[VQDMLSL_V3_I]]
int64x2_t test_vqdmlsl_lane_s32(int64x2_t a, int32x2_t b, int32x2_t c) {
  return vqdmlsl_lane_s32(a, b, c, 1);
}

// CHECK-LABEL: @test_vqdmlsl_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %c, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %c, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %c, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VQDMLAL5_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> %b, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[VQDMLSL_V6_I:%.*]] = call <4 x i32> @llvm.ssub.sat.v4i32(<4 x i32> %a, <4 x i32> [[VQDMLAL5_I]])
// CHECK:   ret <4 x i32> [[VQDMLSL_V6_I]]
int32x4_t test_vqdmlsl_n_s16(int32x4_t a, int16x4_t b, int16_t c) {
  return vqdmlsl_n_s16(a, b, c);
}

// CHECK-LABEL: @test_vqdmlsl_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %c, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %c, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VQDMLAL3_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> %b, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[VQDMLSL_V4_I:%.*]] = call <2 x i64> @llvm.ssub.sat.v2i64(<2 x i64> %a, <2 x i64> [[VQDMLAL3_I]])
// CHECK:   ret <2 x i64> [[VQDMLSL_V4_I]]
int64x2_t test_vqdmlsl_n_s32(int64x2_t a, int32x2_t b, int32_t c) {
  return vqdmlsl_n_s32(a, b, c);
}

// CHECK-LABEL: @test_vqdmulh_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQDMULH_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqdmulh.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast <4 x i16> [[VQDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQDMULH_V2_I]]
int16x4_t test_vqdmulh_s16(int16x4_t a, int16x4_t b) {
  return vqdmulh_s16(a, b);
}

// CHECK-LABEL: @test_vqdmulh_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQDMULH_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqdmulh.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast <2 x i32> [[VQDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQDMULH_V2_I]]
int32x2_t test_vqdmulh_s32(int32x2_t a, int32x2_t b) {
  return vqdmulh_s32(a, b);
}

// CHECK-LABEL: @test_vqdmulhq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqdmulh.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast <8 x i16> [[VQDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQDMULHQ_V2_I]]
int16x8_t test_vqdmulhq_s16(int16x8_t a, int16x8_t b) {
  return vqdmulhq_s16(a, b);
}

// CHECK-LABEL: @test_vqdmulhq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmulh.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast <4 x i32> [[VQDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQDMULHQ_V2_I]]
int32x4_t test_vqdmulhq_s32(int32x4_t a, int32x4_t b) {
  return vqdmulhq_s32(a, b);
}

// CHECK-LABEL: @test_vqdmulh_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMULH_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqdmulh.v4i16(<4 x i16> [[A]], <4 x i16> [[LANE]])
// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast <4 x i16> [[VQDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQDMULH_V2_I]]
int16x4_t test_vqdmulh_lane_s16(int16x4_t a, int16x4_t b) {
  return vqdmulh_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqdmulh_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMULH_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqdmulh.v2i32(<2 x i32> [[A]], <2 x i32> [[LANE]])
// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast <2 x i32> [[VQDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQDMULH_V2_I]]
int32x2_t test_vqdmulh_lane_s32(int32x2_t a, int32x2_t b) {
  return vqdmulh_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vqdmulhq_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i16> [[LANE]] to <16 x i8>
// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqdmulh.v8i16(<8 x i16> [[A]], <8 x i16> [[LANE]])
// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast <8 x i16> [[VQDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQDMULHQ_V2_I]]
int16x8_t test_vqdmulhq_lane_s16(int16x8_t a, int16x4_t b) {
  return vqdmulhq_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqdmulhq_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i32> [[LANE]] to <16 x i8>
// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmulh.v4i32(<4 x i32> [[A]], <4 x i32> [[LANE]])
// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast <4 x i32> [[VQDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQDMULHQ_V2_I]]
int32x4_t test_vqdmulhq_lane_s32(int32x4_t a, int32x2_t b) {
  return vqdmulhq_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vqdmulh_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VQDMULH_V5_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqdmulh.v4i16(<4 x i16> %a, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[VQDMULH_V6_I:%.*]] = bitcast <4 x i16> [[VQDMULH_V5_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQDMULH_V5_I]]
int16x4_t test_vqdmulh_n_s16(int16x4_t a, int16_t b) {
  return vqdmulh_n_s16(a, b);
}

// CHECK-LABEL: @test_vqdmulh_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VQDMULH_V3_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqdmulh.v2i32(<2 x i32> %a, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[VQDMULH_V4_I:%.*]] = bitcast <2 x i32> [[VQDMULH_V3_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQDMULH_V3_I]]
int32x2_t test_vqdmulh_n_s32(int32x2_t a, int32_t b) {
  return vqdmulh_n_s32(a, b);
}

// CHECK-LABEL: @test_vqdmulhq_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %b, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %b, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %b, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %b, i32 7
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> [[VECINIT7_I]] to <16 x i8>
// CHECK:   [[VQDMULHQ_V9_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqdmulh.v8i16(<8 x i16> %a, <8 x i16> [[VECINIT7_I]])
// CHECK:   [[VQDMULHQ_V10_I:%.*]] = bitcast <8 x i16> [[VQDMULHQ_V9_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQDMULHQ_V9_I]]
int16x8_t test_vqdmulhq_n_s16(int16x8_t a, int16_t b) {
  return vqdmulhq_n_s16(a, b);
}

// CHECK-LABEL: @test_vqdmulhq_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %b, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> [[VECINIT3_I]] to <16 x i8>
// CHECK:   [[VQDMULHQ_V5_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmulh.v4i32(<4 x i32> %a, <4 x i32> [[VECINIT3_I]])
// CHECK:   [[VQDMULHQ_V6_I:%.*]] = bitcast <4 x i32> [[VQDMULHQ_V5_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQDMULHQ_V5_I]]
int32x4_t test_vqdmulhq_n_s32(int32x4_t a, int32_t b) {
  return vqdmulhq_n_s32(a, b);
}

// CHECK-LABEL: @test_vqdmull_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQDMULL_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast <4 x i32> [[VQDMULL_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQDMULL_V2_I]]
int32x4_t test_vqdmull_s16(int16x4_t a, int16x4_t b) {
  return vqdmull_s16(a, b);
}

// CHECK-LABEL: @test_vqdmull_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQDMULL_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast <2 x i64> [[VQDMULL_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQDMULL_V2_I]]
int64x2_t test_vqdmull_s32(int32x2_t a, int32x2_t b) {
  return vqdmull_s32(a, b);
}

// CHECK-LABEL: @test_vqdmull_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMULL_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> [[A]], <4 x i16> [[LANE]])
// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast <4 x i32> [[VQDMULL_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQDMULL_V2_I]]
int32x4_t test_vqdmull_lane_s16(int16x4_t a, int16x4_t b) {
  return vqdmull_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqdmull_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VQDMULL_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> [[A]], <2 x i32> [[LANE]])
// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast <2 x i64> [[VQDMULL_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQDMULL_V2_I]]
int64x2_t test_vqdmull_lane_s32(int32x2_t a, int32x2_t b) {
  return vqdmull_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vqdmull_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VQDMULL_V5_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqdmull.v4i32(<4 x i16> %a, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[VQDMULL_V6_I:%.*]] = bitcast <4 x i32> [[VQDMULL_V5_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQDMULL_V5_I]]
int32x4_t test_vqdmull_n_s16(int16x4_t a, int16_t b) {
  return vqdmull_n_s16(a, b);
}

// CHECK-LABEL: @test_vqdmull_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VQDMULL_V3_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqdmull.v2i64(<2 x i32> %a, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[VQDMULL_V4_I:%.*]] = bitcast <2 x i64> [[VQDMULL_V3_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQDMULL_V3_I]]
int64x2_t test_vqdmull_n_s32(int32x2_t a, int32_t b) {
  return vqdmull_n_s32(a, b);
}

// CHECK-LABEL: @test_vqmovn_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQMOVN_V1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqmovns.v8i8(<8 x i16> %a)
// CHECK:   ret <8 x i8> [[VQMOVN_V1_I]]
int8x8_t test_vqmovn_s16(int16x8_t a) {
  return vqmovn_s16(a);
}

// CHECK-LABEL: @test_vqmovn_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQMOVN_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqmovns.v4i16(<4 x i32> %a)
// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast <4 x i16> [[VQMOVN_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQMOVN_V1_I]]
int16x4_t test_vqmovn_s32(int32x4_t a) {
  return vqmovn_s32(a);
}

// CHECK-LABEL: @test_vqmovn_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQMOVN_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqmovns.v2i32(<2 x i64> %a)
// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast <2 x i32> [[VQMOVN_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQMOVN_V1_I]]
int32x2_t test_vqmovn_s64(int64x2_t a) {
  return vqmovn_s64(a);
}

// CHECK-LABEL: @test_vqmovn_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQMOVN_V1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqmovnu.v8i8(<8 x i16> %a)
// CHECK:   ret <8 x i8> [[VQMOVN_V1_I]]
uint8x8_t test_vqmovn_u16(uint16x8_t a) {
  return vqmovn_u16(a);
}

// CHECK-LABEL: @test_vqmovn_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQMOVN_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqmovnu.v4i16(<4 x i32> %a)
// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast <4 x i16> [[VQMOVN_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQMOVN_V1_I]]
uint16x4_t test_vqmovn_u32(uint32x4_t a) {
  return vqmovn_u32(a);
}

// CHECK-LABEL: @test_vqmovn_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQMOVN_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqmovnu.v2i32(<2 x i64> %a)
// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast <2 x i32> [[VQMOVN_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQMOVN_V1_I]]
uint32x2_t test_vqmovn_u64(uint64x2_t a) {
  return vqmovn_u64(a);
}

// CHECK-LABEL: @test_vqmovun_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQMOVUN_V1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqmovnsu.v8i8(<8 x i16> %a)
// CHECK:   ret <8 x i8> [[VQMOVUN_V1_I]]
uint8x8_t test_vqmovun_s16(int16x8_t a) {
  return vqmovun_s16(a);
}

// CHECK-LABEL: @test_vqmovun_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQMOVUN_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqmovnsu.v4i16(<4 x i32> %a)
// CHECK:   [[VQMOVUN_V2_I:%.*]] = bitcast <4 x i16> [[VQMOVUN_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQMOVUN_V1_I]]
uint16x4_t test_vqmovun_s32(int32x4_t a) {
  return vqmovun_s32(a);
}

// CHECK-LABEL: @test_vqmovun_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQMOVUN_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqmovnsu.v2i32(<2 x i64> %a)
// CHECK:   [[VQMOVUN_V2_I:%.*]] = bitcast <2 x i32> [[VQMOVUN_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQMOVUN_V1_I]]
uint32x2_t test_vqmovun_s64(int64x2_t a) {
  return vqmovun_s64(a);
}

// CHECK-LABEL: @test_vqneg_s8(
// CHECK:   [[VQNEG_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqneg.v8i8(<8 x i8> %a)
// CHECK:   ret <8 x i8> [[VQNEG_V_I]]
int8x8_t test_vqneg_s8(int8x8_t a) {
  return vqneg_s8(a);
}

// CHECK-LABEL: @test_vqneg_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VQNEG_V1_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqneg.v4i16(<4 x i16> %a)
// CHECK:   [[VQNEG_V2_I:%.*]] = bitcast <4 x i16> [[VQNEG_V1_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQNEG_V1_I]]
int16x4_t test_vqneg_s16(int16x4_t a) {
  return vqneg_s16(a);
}

// CHECK-LABEL: @test_vqneg_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VQNEG_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqneg.v2i32(<2 x i32> %a)
// CHECK:   [[VQNEG_V2_I:%.*]] = bitcast <2 x i32> [[VQNEG_V1_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQNEG_V1_I]]
int32x2_t test_vqneg_s32(int32x2_t a) {
  return vqneg_s32(a);
}

// CHECK-LABEL: @test_vqnegq_s8(
// CHECK:   [[VQNEGQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vqneg.v16i8(<16 x i8> %a)
// CHECK:   ret <16 x i8> [[VQNEGQ_V_I]]
int8x16_t test_vqnegq_s8(int8x16_t a) {
  return vqnegq_s8(a);
}

// CHECK-LABEL: @test_vqnegq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQNEGQ_V1_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqneg.v8i16(<8 x i16> %a)
// CHECK:   [[VQNEGQ_V2_I:%.*]] = bitcast <8 x i16> [[VQNEGQ_V1_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQNEGQ_V1_I]]
int16x8_t test_vqnegq_s16(int16x8_t a) {
  return vqnegq_s16(a);
}

// CHECK-LABEL: @test_vqnegq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQNEGQ_V1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqneg.v4i32(<4 x i32> %a)
// CHECK:   [[VQNEGQ_V2_I:%.*]] = bitcast <4 x i32> [[VQNEGQ_V1_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQNEGQ_V1_I]]
int32x4_t test_vqnegq_s32(int32x4_t a) {
  return vqnegq_s32(a);
}

// CHECK-LABEL: @test_vqrdmulh_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQRDMULH_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrdmulh.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast <4 x i16> [[VQRDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQRDMULH_V2_I]]
int16x4_t test_vqrdmulh_s16(int16x4_t a, int16x4_t b) {
  return vqrdmulh_s16(a, b);
}

// CHECK-LABEL: @test_vqrdmulh_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQRDMULH_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrdmulh.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast <2 x i32> [[VQRDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQRDMULH_V2_I]]
int32x2_t test_vqrdmulh_s32(int32x2_t a, int32x2_t b) {
  return vqrdmulh_s32(a, b);
}

// CHECK-LABEL: @test_vqrdmulhq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrdmulh.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast <8 x i16> [[VQRDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQRDMULHQ_V2_I]]
int16x8_t test_vqrdmulhq_s16(int16x8_t a, int16x8_t b) {
  return vqrdmulhq_s16(a, b);
}

// CHECK-LABEL: @test_vqrdmulhq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrdmulh.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast <4 x i32> [[VQRDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQRDMULHQ_V2_I]]
int32x4_t test_vqrdmulhq_s32(int32x4_t a, int32x4_t b) {
  return vqrdmulhq_s32(a, b);
}

// CHECK-LABEL: @test_vqrdmulh_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <4 x i32> <i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i16> [[LANE]] to <8 x i8>
// CHECK:   [[VQRDMULH_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrdmulh.v4i16(<4 x i16> [[A]], <4 x i16> [[LANE]])
// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast <4 x i16> [[VQRDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQRDMULH_V2_I]]
int16x4_t test_vqrdmulh_lane_s16(int16x4_t a, int16x4_t b) {
  return vqrdmulh_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqrdmulh_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <2 x i32> <i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> [[A:%.*]] to <8 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <2 x i32> [[LANE]] to <8 x i8>
// CHECK:   [[VQRDMULH_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrdmulh.v2i32(<2 x i32> [[A]], <2 x i32> [[LANE]])
// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast <2 x i32> [[VQRDMULH_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQRDMULH_V2_I]]
int32x2_t test_vqrdmulh_lane_s32(int32x2_t a, int32x2_t b) {
  return vqrdmulh_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vqrdmulhq_lane_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[LANE:%.*]] = shufflevector <4 x i16> [[TMP1]], <4 x i16> [[TMP1]], <8 x i32> <i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i16> [[LANE]] to <16 x i8>
// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrdmulh.v8i16(<8 x i16> [[A]], <8 x i16> [[LANE]])
// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast <8 x i16> [[VQRDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQRDMULHQ_V2_I]]
int16x8_t test_vqrdmulhq_lane_s16(int16x8_t a, int16x4_t b) {
  return vqrdmulhq_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vqrdmulhq_lane_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> [[B:%.*]] to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[LANE:%.*]] = shufflevector <2 x i32> [[TMP1]], <2 x i32> [[TMP1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> [[A:%.*]] to <16 x i8>
// CHECK:   [[TMP3:%.*]] = bitcast <4 x i32> [[LANE]] to <16 x i8>
// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrdmulh.v4i32(<4 x i32> [[A]], <4 x i32> [[LANE]])
// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast <4 x i32> [[VQRDMULHQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQRDMULHQ_V2_I]]
int32x4_t test_vqrdmulhq_lane_s32(int32x4_t a, int32x2_t b) {
  return vqrdmulhq_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vqrdmulh_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> [[VECINIT3_I]] to <8 x i8>
// CHECK:   [[VQRDMULH_V5_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrdmulh.v4i16(<4 x i16> %a, <4 x i16> [[VECINIT3_I]])
// CHECK:   [[VQRDMULH_V6_I:%.*]] = bitcast <4 x i16> [[VQRDMULH_V5_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQRDMULH_V5_I]]
int16x4_t test_vqrdmulh_n_s16(int16x4_t a, int16_t b) {
  return vqrdmulh_n_s16(a, b);
}

// CHECK-LABEL: @test_vqrdmulh_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <2 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <2 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> [[VECINIT1_I]] to <8 x i8>
// CHECK:   [[VQRDMULH_V3_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrdmulh.v2i32(<2 x i32> %a, <2 x i32> [[VECINIT1_I]])
// CHECK:   [[VQRDMULH_V4_I:%.*]] = bitcast <2 x i32> [[VQRDMULH_V3_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQRDMULH_V3_I]]
int32x2_t test_vqrdmulh_n_s32(int32x2_t a, int32_t b) {
  return vqrdmulh_n_s32(a, b);
}

// CHECK-LABEL: @test_vqrdmulhq_n_s16(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <8 x i16> undef, i16 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <8 x i16> [[VECINIT_I]], i16 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <8 x i16> [[VECINIT1_I]], i16 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <8 x i16> [[VECINIT2_I]], i16 %b, i32 3
// CHECK:   [[VECINIT4_I:%.*]] = insertelement <8 x i16> [[VECINIT3_I]], i16 %b, i32 4
// CHECK:   [[VECINIT5_I:%.*]] = insertelement <8 x i16> [[VECINIT4_I]], i16 %b, i32 5
// CHECK:   [[VECINIT6_I:%.*]] = insertelement <8 x i16> [[VECINIT5_I]], i16 %b, i32 6
// CHECK:   [[VECINIT7_I:%.*]] = insertelement <8 x i16> [[VECINIT6_I]], i16 %b, i32 7
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> [[VECINIT7_I]] to <16 x i8>
// CHECK:   [[VQRDMULHQ_V9_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrdmulh.v8i16(<8 x i16> %a, <8 x i16> [[VECINIT7_I]])
// CHECK:   [[VQRDMULHQ_V10_I:%.*]] = bitcast <8 x i16> [[VQRDMULHQ_V9_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQRDMULHQ_V9_I]]
int16x8_t test_vqrdmulhq_n_s16(int16x8_t a, int16_t b) {
  return vqrdmulhq_n_s16(a, b);
}

// CHECK-LABEL: @test_vqrdmulhq_n_s32(
// CHECK:   [[VECINIT_I:%.*]] = insertelement <4 x i32> undef, i32 %b, i32 0
// CHECK:   [[VECINIT1_I:%.*]] = insertelement <4 x i32> [[VECINIT_I]], i32 %b, i32 1
// CHECK:   [[VECINIT2_I:%.*]] = insertelement <4 x i32> [[VECINIT1_I]], i32 %b, i32 2
// CHECK:   [[VECINIT3_I:%.*]] = insertelement <4 x i32> [[VECINIT2_I]], i32 %b, i32 3
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> [[VECINIT3_I]] to <16 x i8>
// CHECK:   [[VQRDMULHQ_V5_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrdmulh.v4i32(<4 x i32> %a, <4 x i32> [[VECINIT3_I]])
// CHECK:   [[VQRDMULHQ_V6_I:%.*]] = bitcast <4 x i32> [[VQRDMULHQ_V5_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQRDMULHQ_V5_I]]
int32x4_t test_vqrdmulhq_n_s32(int32x4_t a, int32_t b) {
  return vqrdmulhq_n_s32(a, b);
}

// CHECK-LABEL: @test_vqrshl_s8(
// CHECK:   [[VQRSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqrshifts.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQRSHL_V_I]]
int8x8_t test_vqrshl_s8(int8x8_t a, int8x8_t b) {
  return vqrshl_s8(a, b);
}

// CHECK-LABEL: @test_vqrshl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQRSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrshifts.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQRSHL_V3_I:%.*]] = bitcast <4 x i16> [[VQRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQRSHL_V2_I]]
int16x4_t test_vqrshl_s16(int16x4_t a, int16x4_t b) {
  return vqrshl_s16(a, b);
}

// CHECK-LABEL: @test_vqrshl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQRSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrshifts.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQRSHL_V3_I:%.*]] = bitcast <2 x i32> [[VQRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQRSHL_V2_I]]
int32x2_t test_vqrshl_s32(int32x2_t a, int32x2_t b) {
  return vqrshl_s32(a, b);
}

// CHECK-LABEL: @test_vqrshl_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQRSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vqrshifts.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQRSHL_V3_I:%.*]] = bitcast <1 x i64> [[VQRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQRSHL_V2_I]]
int64x1_t test_vqrshl_s64(int64x1_t a, int64x1_t b) {
  return vqrshl_s64(a, b);
}

// CHECK-LABEL: @test_vqrshl_u8(
// CHECK:   [[VQRSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqrshiftu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQRSHL_V_I]]
uint8x8_t test_vqrshl_u8(uint8x8_t a, int8x8_t b) {
  return vqrshl_u8(a, b);
}

// CHECK-LABEL: @test_vqrshl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQRSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqrshiftu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQRSHL_V3_I:%.*]] = bitcast <4 x i16> [[VQRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQRSHL_V2_I]]
uint16x4_t test_vqrshl_u16(uint16x4_t a, int16x4_t b) {
  return vqrshl_u16(a, b);
}

// CHECK-LABEL: @test_vqrshl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQRSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqrshiftu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQRSHL_V3_I:%.*]] = bitcast <2 x i32> [[VQRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQRSHL_V2_I]]
uint32x2_t test_vqrshl_u32(uint32x2_t a, int32x2_t b) {
  return vqrshl_u32(a, b);
}

// CHECK-LABEL: @test_vqrshl_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQRSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vqrshiftu.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQRSHL_V3_I:%.*]] = bitcast <1 x i64> [[VQRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQRSHL_V2_I]]
uint64x1_t test_vqrshl_u64(uint64x1_t a, int64x1_t b) {
  return vqrshl_u64(a, b);
}

// CHECK-LABEL: @test_vqrshlq_s8(
// CHECK:   [[VQRSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vqrshifts.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQRSHLQ_V_I]]
int8x16_t test_vqrshlq_s8(int8x16_t a, int8x16_t b) {
  return vqrshlq_s8(a, b);
}

// CHECK-LABEL: @test_vqrshlq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQRSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrshifts.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQRSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VQRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQRSHLQ_V2_I]]
int16x8_t test_vqrshlq_s16(int16x8_t a, int16x8_t b) {
  return vqrshlq_s16(a, b);
}

// CHECK-LABEL: @test_vqrshlq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQRSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrshifts.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQRSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VQRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQRSHLQ_V2_I]]
int32x4_t test_vqrshlq_s32(int32x4_t a, int32x4_t b) {
  return vqrshlq_s32(a, b);
}

// CHECK-LABEL: @test_vqrshlq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQRSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqrshifts.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQRSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VQRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQRSHLQ_V2_I]]
int64x2_t test_vqrshlq_s64(int64x2_t a, int64x2_t b) {
  return vqrshlq_s64(a, b);
}

// CHECK-LABEL: @test_vqrshlq_u8(
// CHECK:   [[VQRSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vqrshiftu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQRSHLQ_V_I]]
uint8x16_t test_vqrshlq_u8(uint8x16_t a, int8x16_t b) {
  return vqrshlq_u8(a, b);
}

// CHECK-LABEL: @test_vqrshlq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQRSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqrshiftu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQRSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VQRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQRSHLQ_V2_I]]
uint16x8_t test_vqrshlq_u16(uint16x8_t a, int16x8_t b) {
  return vqrshlq_u16(a, b);
}

// CHECK-LABEL: @test_vqrshlq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQRSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqrshiftu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQRSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VQRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQRSHLQ_V2_I]]
uint32x4_t test_vqrshlq_u32(uint32x4_t a, int32x4_t b) {
  return vqrshlq_u32(a, b);
}

// CHECK-LABEL: @test_vqrshlq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQRSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqrshiftu.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQRSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VQRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQRSHLQ_V2_I]]
uint64x2_t test_vqrshlq_u64(uint64x2_t a, int64x2_t b) {
  return vqrshlq_u64(a, b);
}

// CHECK-LABEL: @test_vqrshrn_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQRSHRN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vqrshiftns.v8i8(<8 x i16> [[VQRSHRN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VQRSHRN_N1]]
int8x8_t test_vqrshrn_n_s16(int16x8_t a) {
  return vqrshrn_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqrshrn_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQRSHRN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqrshiftns.v4i16(<4 x i32> [[VQRSHRN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VQRSHRN_N1]]
int16x4_t test_vqrshrn_n_s32(int32x4_t a) {
  return vqrshrn_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqrshrn_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQRSHRN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqrshiftns.v2i32(<2 x i64> [[VQRSHRN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VQRSHRN_N1]]
int32x2_t test_vqrshrn_n_s64(int64x2_t a) {
  return vqrshrn_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqrshrn_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQRSHRN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vqrshiftnu.v8i8(<8 x i16> [[VQRSHRN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VQRSHRN_N1]]
uint8x8_t test_vqrshrn_n_u16(uint16x8_t a) {
  return vqrshrn_n_u16(a, 1);
}

// CHECK-LABEL: @test_vqrshrn_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQRSHRN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqrshiftnu.v4i16(<4 x i32> [[VQRSHRN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VQRSHRN_N1]]
uint16x4_t test_vqrshrn_n_u32(uint32x4_t a) {
  return vqrshrn_n_u32(a, 1);
}

// CHECK-LABEL: @test_vqrshrn_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQRSHRN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqrshiftnu.v2i32(<2 x i64> [[VQRSHRN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VQRSHRN_N1]]
uint32x2_t test_vqrshrn_n_u64(uint64x2_t a) {
  return vqrshrn_n_u64(a, 1);
}

// CHECK-LABEL: @test_vqrshrun_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQRSHRUN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQRSHRUN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vqrshiftnsu.v8i8(<8 x i16> [[VQRSHRUN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VQRSHRUN_N1]]
uint8x8_t test_vqrshrun_n_s16(int16x8_t a) {
  return vqrshrun_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqrshrun_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQRSHRUN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQRSHRUN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqrshiftnsu.v4i16(<4 x i32> [[VQRSHRUN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VQRSHRUN_N1]]
uint16x4_t test_vqrshrun_n_s32(int32x4_t a) {
  return vqrshrun_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqrshrun_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQRSHRUN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQRSHRUN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqrshiftnsu.v2i32(<2 x i64> [[VQRSHRUN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VQRSHRUN_N1]]
uint32x2_t test_vqrshrun_n_s64(int64x2_t a) {
  return vqrshrun_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqshl_s8(
// CHECK:   [[VQSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqshifts.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQSHL_V_I]]
int8x8_t test_vqshl_s8(int8x8_t a, int8x8_t b) {
  return vqshl_s8(a, b);
}

// CHECK-LABEL: @test_vqshl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqshifts.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQSHL_V3_I:%.*]] = bitcast <4 x i16> [[VQSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQSHL_V2_I]]
int16x4_t test_vqshl_s16(int16x4_t a, int16x4_t b) {
  return vqshl_s16(a, b);
}

// CHECK-LABEL: @test_vqshl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqshifts.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQSHL_V3_I:%.*]] = bitcast <2 x i32> [[VQSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQSHL_V2_I]]
int32x2_t test_vqshl_s32(int32x2_t a, int32x2_t b) {
  return vqshl_s32(a, b);
}

// CHECK-LABEL: @test_vqshl_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vqshifts.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQSHL_V3_I:%.*]] = bitcast <1 x i64> [[VQSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQSHL_V2_I]]
int64x1_t test_vqshl_s64(int64x1_t a, int64x1_t b) {
  return vqshl_s64(a, b);
}

// CHECK-LABEL: @test_vqshl_u8(
// CHECK:   [[VQSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vqshiftu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQSHL_V_I]]
uint8x8_t test_vqshl_u8(uint8x8_t a, int8x8_t b) {
  return vqshl_u8(a, b);
}

// CHECK-LABEL: @test_vqshl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vqshiftu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQSHL_V3_I:%.*]] = bitcast <4 x i16> [[VQSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQSHL_V2_I]]
uint16x4_t test_vqshl_u16(uint16x4_t a, int16x4_t b) {
  return vqshl_u16(a, b);
}

// CHECK-LABEL: @test_vqshl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vqshiftu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQSHL_V3_I:%.*]] = bitcast <2 x i32> [[VQSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQSHL_V2_I]]
uint32x2_t test_vqshl_u32(uint32x2_t a, int32x2_t b) {
  return vqshl_u32(a, b);
}

// CHECK-LABEL: @test_vqshl_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vqshiftu.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQSHL_V3_I:%.*]] = bitcast <1 x i64> [[VQSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQSHL_V2_I]]
uint64x1_t test_vqshl_u64(uint64x1_t a, int64x1_t b) {
  return vqshl_u64(a, b);
}

// CHECK-LABEL: @test_vqshlq_s8(
// CHECK:   [[VQSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vqshifts.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQSHLQ_V_I]]
int8x16_t test_vqshlq_s8(int8x16_t a, int8x16_t b) {
  return vqshlq_s8(a, b);
}

// CHECK-LABEL: @test_vqshlq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqshifts.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VQSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQSHLQ_V2_I]]
int16x8_t test_vqshlq_s16(int16x8_t a, int16x8_t b) {
  return vqshlq_s16(a, b);
}

// CHECK-LABEL: @test_vqshlq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqshifts.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VQSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQSHLQ_V2_I]]
int32x4_t test_vqshlq_s32(int32x4_t a, int32x4_t b) {
  return vqshlq_s32(a, b);
}

// CHECK-LABEL: @test_vqshlq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqshifts.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VQSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQSHLQ_V2_I]]
int64x2_t test_vqshlq_s64(int64x2_t a, int64x2_t b) {
  return vqshlq_s64(a, b);
}

// CHECK-LABEL: @test_vqshlq_u8(
// CHECK:   [[VQSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vqshiftu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQSHLQ_V_I]]
uint8x16_t test_vqshlq_u8(uint8x16_t a, int8x16_t b) {
  return vqshlq_u8(a, b);
}

// CHECK-LABEL: @test_vqshlq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vqshiftu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VQSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQSHLQ_V2_I]]
uint16x8_t test_vqshlq_u16(uint16x8_t a, int16x8_t b) {
  return vqshlq_u16(a, b);
}

// CHECK-LABEL: @test_vqshlq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vqshiftu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VQSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQSHLQ_V2_I]]
uint32x4_t test_vqshlq_u32(uint32x4_t a, int32x4_t b) {
  return vqshlq_u32(a, b);
}

// CHECK-LABEL: @test_vqshlq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vqshiftu.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VQSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQSHLQ_V2_I]]
uint64x2_t test_vqshlq_u64(uint64x2_t a, int64x2_t b) {
  return vqshlq_u64(a, b);
}

// CHECK-LABEL: @test_vqshlu_n_s8(
// CHECK:   [[VQSHLU_N:%.*]] = call <8 x i8> @llvm.arm.neon.vqshiftsu.v8i8(<8 x i8> %a, <8 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <8 x i8> [[VQSHLU_N]]
uint8x8_t test_vqshlu_n_s8(int8x8_t a) {
  return vqshlu_n_s8(a, 1);
}

// CHECK-LABEL: @test_vqshlu_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VQSHLU_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VQSHLU_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqshiftsu.v4i16(<4 x i16> [[VQSHLU_N]], <4 x i16> <i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <4 x i16> [[VQSHLU_N1]]
uint16x4_t test_vqshlu_n_s16(int16x4_t a) {
  return vqshlu_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqshlu_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VQSHLU_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VQSHLU_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqshiftsu.v2i32(<2 x i32> [[VQSHLU_N]], <2 x i32> <i32 1, i32 1>)
// CHECK:   ret <2 x i32> [[VQSHLU_N1]]
uint32x2_t test_vqshlu_n_s32(int32x2_t a) {
  return vqshlu_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqshlu_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[VQSHLU_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VQSHLU_N1:%.*]] = call <1 x i64> @llvm.arm.neon.vqshiftsu.v1i64(<1 x i64> [[VQSHLU_N]], <1 x i64> <i64 1>)
// CHECK:   ret <1 x i64> [[VQSHLU_N1]]
uint64x1_t test_vqshlu_n_s64(int64x1_t a) {
  return vqshlu_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqshluq_n_s8(
// CHECK:   [[VQSHLU_N:%.*]] = call <16 x i8> @llvm.arm.neon.vqshiftsu.v16i8(<16 x i8> %a, <16 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <16 x i8> [[VQSHLU_N]]
uint8x16_t test_vqshluq_n_s8(int8x16_t a) {
  return vqshluq_n_s8(a, 1);
}

// CHECK-LABEL: @test_vqshluq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQSHLU_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQSHLU_N1:%.*]] = call <8 x i16> @llvm.arm.neon.vqshiftsu.v8i16(<8 x i16> [[VQSHLU_N]], <8 x i16> <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <8 x i16> [[VQSHLU_N1]]
uint16x8_t test_vqshluq_n_s16(int16x8_t a) {
  return vqshluq_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqshluq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQSHLU_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQSHLU_N1:%.*]] = call <4 x i32> @llvm.arm.neon.vqshiftsu.v4i32(<4 x i32> [[VQSHLU_N]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>)
// CHECK:   ret <4 x i32> [[VQSHLU_N1]]
uint32x4_t test_vqshluq_n_s32(int32x4_t a) {
  return vqshluq_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqshluq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQSHLU_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQSHLU_N1:%.*]] = call <2 x i64> @llvm.arm.neon.vqshiftsu.v2i64(<2 x i64> [[VQSHLU_N]], <2 x i64> <i64 1, i64 1>)
// CHECK:   ret <2 x i64> [[VQSHLU_N1]]
uint64x2_t test_vqshluq_n_s64(int64x2_t a) {
  return vqshluq_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_s8(
// CHECK:   [[VQSHL_N:%.*]] = call <8 x i8> @llvm.arm.neon.vqshifts.v8i8(<8 x i8> %a, <8 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <8 x i8> [[VQSHL_N]]
int8x8_t test_vqshl_n_s8(int8x8_t a) {
  return vqshl_n_s8(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VQSHL_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqshifts.v4i16(<4 x i16> [[VQSHL_N]], <4 x i16> <i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <4 x i16> [[VQSHL_N1]]
int16x4_t test_vqshl_n_s16(int16x4_t a) {
  return vqshl_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VQSHL_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqshifts.v2i32(<2 x i32> [[VQSHL_N]], <2 x i32> <i32 1, i32 1>)
// CHECK:   ret <2 x i32> [[VQSHL_N1]]
int32x2_t test_vqshl_n_s32(int32x2_t a) {
  return vqshl_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VQSHL_N1:%.*]] = call <1 x i64> @llvm.arm.neon.vqshifts.v1i64(<1 x i64> [[VQSHL_N]], <1 x i64> <i64 1>)
// CHECK:   ret <1 x i64> [[VQSHL_N1]]
int64x1_t test_vqshl_n_s64(int64x1_t a) {
  return vqshl_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_u8(
// CHECK:   [[VQSHL_N:%.*]] = call <8 x i8> @llvm.arm.neon.vqshiftu.v8i8(<8 x i8> %a, <8 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <8 x i8> [[VQSHL_N]]
uint8x8_t test_vqshl_n_u8(uint8x8_t a) {
  return vqshl_n_u8(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VQSHL_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqshiftu.v4i16(<4 x i16> [[VQSHL_N]], <4 x i16> <i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <4 x i16> [[VQSHL_N1]]
uint16x4_t test_vqshl_n_u16(uint16x4_t a) {
  return vqshl_n_u16(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VQSHL_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqshiftu.v2i32(<2 x i32> [[VQSHL_N]], <2 x i32> <i32 1, i32 1>)
// CHECK:   ret <2 x i32> [[VQSHL_N1]]
uint32x2_t test_vqshl_n_u32(uint32x2_t a) {
  return vqshl_n_u32(a, 1);
}

// CHECK-LABEL: @test_vqshl_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VQSHL_N1:%.*]] = call <1 x i64> @llvm.arm.neon.vqshiftu.v1i64(<1 x i64> [[VQSHL_N]], <1 x i64> <i64 1>)
// CHECK:   ret <1 x i64> [[VQSHL_N1]]
uint64x1_t test_vqshl_n_u64(uint64x1_t a) {
  return vqshl_n_u64(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_s8(
// CHECK:   [[VQSHL_N:%.*]] = call <16 x i8> @llvm.arm.neon.vqshifts.v16i8(<16 x i8> %a, <16 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <16 x i8> [[VQSHL_N]]
int8x16_t test_vqshlq_n_s8(int8x16_t a) {
  return vqshlq_n_s8(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQSHL_N1:%.*]] = call <8 x i16> @llvm.arm.neon.vqshifts.v8i16(<8 x i16> [[VQSHL_N]], <8 x i16> <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <8 x i16> [[VQSHL_N1]]
int16x8_t test_vqshlq_n_s16(int16x8_t a) {
  return vqshlq_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQSHL_N1:%.*]] = call <4 x i32> @llvm.arm.neon.vqshifts.v4i32(<4 x i32> [[VQSHL_N]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>)
// CHECK:   ret <4 x i32> [[VQSHL_N1]]
int32x4_t test_vqshlq_n_s32(int32x4_t a) {
  return vqshlq_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQSHL_N1:%.*]] = call <2 x i64> @llvm.arm.neon.vqshifts.v2i64(<2 x i64> [[VQSHL_N]], <2 x i64> <i64 1, i64 1>)
// CHECK:   ret <2 x i64> [[VQSHL_N1]]
int64x2_t test_vqshlq_n_s64(int64x2_t a) {
  return vqshlq_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_u8(
// CHECK:   [[VQSHL_N:%.*]] = call <16 x i8> @llvm.arm.neon.vqshiftu.v16i8(<16 x i8> %a, <16 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <16 x i8> [[VQSHL_N]]
uint8x16_t test_vqshlq_n_u8(uint8x16_t a) {
  return vqshlq_n_u8(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQSHL_N1:%.*]] = call <8 x i16> @llvm.arm.neon.vqshiftu.v8i16(<8 x i16> [[VQSHL_N]], <8 x i16> <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <8 x i16> [[VQSHL_N1]]
uint16x8_t test_vqshlq_n_u16(uint16x8_t a) {
  return vqshlq_n_u16(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQSHL_N1:%.*]] = call <4 x i32> @llvm.arm.neon.vqshiftu.v4i32(<4 x i32> [[VQSHL_N]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>)
// CHECK:   ret <4 x i32> [[VQSHL_N1]]
uint32x4_t test_vqshlq_n_u32(uint32x4_t a) {
  return vqshlq_n_u32(a, 1);
}

// CHECK-LABEL: @test_vqshlq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQSHL_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQSHL_N1:%.*]] = call <2 x i64> @llvm.arm.neon.vqshiftu.v2i64(<2 x i64> [[VQSHL_N]], <2 x i64> <i64 1, i64 1>)
// CHECK:   ret <2 x i64> [[VQSHL_N1]]
uint64x2_t test_vqshlq_n_u64(uint64x2_t a) {
  return vqshlq_n_u64(a, 1);
}

// CHECK-LABEL: @test_vqshrn_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQSHRN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vqshiftns.v8i8(<8 x i16> [[VQSHRN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VQSHRN_N1]]
int8x8_t test_vqshrn_n_s16(int16x8_t a) {
  return vqshrn_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqshrn_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQSHRN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqshiftns.v4i16(<4 x i32> [[VQSHRN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VQSHRN_N1]]
int16x4_t test_vqshrn_n_s32(int32x4_t a) {
  return vqshrn_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqshrn_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQSHRN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqshiftns.v2i32(<2 x i64> [[VQSHRN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VQSHRN_N1]]
int32x2_t test_vqshrn_n_s64(int64x2_t a) {
  return vqshrn_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqshrn_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQSHRN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vqshiftnu.v8i8(<8 x i16> [[VQSHRN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VQSHRN_N1]]
uint8x8_t test_vqshrn_n_u16(uint16x8_t a) {
  return vqshrn_n_u16(a, 1);
}

// CHECK-LABEL: @test_vqshrn_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQSHRN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqshiftnu.v4i16(<4 x i32> [[VQSHRN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VQSHRN_N1]]
uint16x4_t test_vqshrn_n_u32(uint32x4_t a) {
  return vqshrn_n_u32(a, 1);
}

// CHECK-LABEL: @test_vqshrn_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQSHRN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqshiftnu.v2i32(<2 x i64> [[VQSHRN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VQSHRN_N1]]
uint32x2_t test_vqshrn_n_u64(uint64x2_t a) {
  return vqshrn_n_u64(a, 1);
}

// CHECK-LABEL: @test_vqshrun_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VQSHRUN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VQSHRUN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vqshiftnsu.v8i8(<8 x i16> [[VQSHRUN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VQSHRUN_N1]]
uint8x8_t test_vqshrun_n_s16(int16x8_t a) {
  return vqshrun_n_s16(a, 1);
}

// CHECK-LABEL: @test_vqshrun_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VQSHRUN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VQSHRUN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vqshiftnsu.v4i16(<4 x i32> [[VQSHRUN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VQSHRUN_N1]]
uint16x4_t test_vqshrun_n_s32(int32x4_t a) {
  return vqshrun_n_s32(a, 1);
}

// CHECK-LABEL: @test_vqshrun_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VQSHRUN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VQSHRUN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vqshiftnsu.v2i32(<2 x i64> [[VQSHRUN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VQSHRUN_N1]]
uint32x2_t test_vqshrun_n_s64(int64x2_t a) {
  return vqshrun_n_s64(a, 1);
}

// CHECK-LABEL: @test_vqsub_s8(
// CHECK:   [[VQSUB_V_I:%.*]] = call <8 x i8> @llvm.ssub.sat.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQSUB_V_I]]
int8x8_t test_vqsub_s8(int8x8_t a, int8x8_t b) {
  return vqsub_s8(a, b);
}

// CHECK-LABEL: @test_vqsub_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQSUB_V2_I:%.*]] = call <4 x i16> @llvm.ssub.sat.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQSUB_V3_I:%.*]] = bitcast <4 x i16> [[VQSUB_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQSUB_V2_I]]
int16x4_t test_vqsub_s16(int16x4_t a, int16x4_t b) {
  return vqsub_s16(a, b);
}

// CHECK-LABEL: @test_vqsub_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQSUB_V2_I:%.*]] = call <2 x i32> @llvm.ssub.sat.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQSUB_V3_I:%.*]] = bitcast <2 x i32> [[VQSUB_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQSUB_V2_I]]
int32x2_t test_vqsub_s32(int32x2_t a, int32x2_t b) {
  return vqsub_s32(a, b);
}

// CHECK-LABEL: @test_vqsub_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQSUB_V2_I:%.*]] = call <1 x i64> @llvm.ssub.sat.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQSUB_V3_I:%.*]] = bitcast <1 x i64> [[VQSUB_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQSUB_V2_I]]
int64x1_t test_vqsub_s64(int64x1_t a, int64x1_t b) {
  return vqsub_s64(a, b);
}

// CHECK-LABEL: @test_vqsub_u8(
// CHECK:   [[VQSUB_V_I:%.*]] = call <8 x i8> @llvm.usub.sat.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VQSUB_V_I]]
uint8x8_t test_vqsub_u8(uint8x8_t a, uint8x8_t b) {
  return vqsub_u8(a, b);
}

// CHECK-LABEL: @test_vqsub_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VQSUB_V2_I:%.*]] = call <4 x i16> @llvm.usub.sat.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VQSUB_V3_I:%.*]] = bitcast <4 x i16> [[VQSUB_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VQSUB_V2_I]]
uint16x4_t test_vqsub_u16(uint16x4_t a, uint16x4_t b) {
  return vqsub_u16(a, b);
}

// CHECK-LABEL: @test_vqsub_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VQSUB_V2_I:%.*]] = call <2 x i32> @llvm.usub.sat.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VQSUB_V3_I:%.*]] = bitcast <2 x i32> [[VQSUB_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VQSUB_V2_I]]
uint32x2_t test_vqsub_u32(uint32x2_t a, uint32x2_t b) {
  return vqsub_u32(a, b);
}

// CHECK-LABEL: @test_vqsub_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VQSUB_V2_I:%.*]] = call <1 x i64> @llvm.usub.sat.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VQSUB_V3_I:%.*]] = bitcast <1 x i64> [[VQSUB_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VQSUB_V2_I]]
uint64x1_t test_vqsub_u64(uint64x1_t a, uint64x1_t b) {
  return vqsub_u64(a, b);
}

// CHECK-LABEL: @test_vqsubq_s8(
// CHECK:   [[VQSUBQ_V_I:%.*]] = call <16 x i8> @llvm.ssub.sat.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQSUBQ_V_I]]
int8x16_t test_vqsubq_s8(int8x16_t a, int8x16_t b) {
  return vqsubq_s8(a, b);
}

// CHECK-LABEL: @test_vqsubq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQSUBQ_V2_I:%.*]] = call <8 x i16> @llvm.ssub.sat.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQSUBQ_V3_I:%.*]] = bitcast <8 x i16> [[VQSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQSUBQ_V2_I]]
int16x8_t test_vqsubq_s16(int16x8_t a, int16x8_t b) {
  return vqsubq_s16(a, b);
}

// CHECK-LABEL: @test_vqsubq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQSUBQ_V2_I:%.*]] = call <4 x i32> @llvm.ssub.sat.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQSUBQ_V3_I:%.*]] = bitcast <4 x i32> [[VQSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQSUBQ_V2_I]]
int32x4_t test_vqsubq_s32(int32x4_t a, int32x4_t b) {
  return vqsubq_s32(a, b);
}

// CHECK-LABEL: @test_vqsubq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQSUBQ_V2_I:%.*]] = call <2 x i64> @llvm.ssub.sat.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQSUBQ_V3_I:%.*]] = bitcast <2 x i64> [[VQSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQSUBQ_V2_I]]
int64x2_t test_vqsubq_s64(int64x2_t a, int64x2_t b) {
  return vqsubq_s64(a, b);
}

// CHECK-LABEL: @test_vqsubq_u8(
// CHECK:   [[VQSUBQ_V_I:%.*]] = call <16 x i8> @llvm.usub.sat.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VQSUBQ_V_I]]
uint8x16_t test_vqsubq_u8(uint8x16_t a, uint8x16_t b) {
  return vqsubq_u8(a, b);
}

// CHECK-LABEL: @test_vqsubq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VQSUBQ_V2_I:%.*]] = call <8 x i16> @llvm.usub.sat.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VQSUBQ_V3_I:%.*]] = bitcast <8 x i16> [[VQSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VQSUBQ_V2_I]]
uint16x8_t test_vqsubq_u16(uint16x8_t a, uint16x8_t b) {
  return vqsubq_u16(a, b);
}

// CHECK-LABEL: @test_vqsubq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VQSUBQ_V2_I:%.*]] = call <4 x i32> @llvm.usub.sat.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VQSUBQ_V3_I:%.*]] = bitcast <4 x i32> [[VQSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VQSUBQ_V2_I]]
uint32x4_t test_vqsubq_u32(uint32x4_t a, uint32x4_t b) {
  return vqsubq_u32(a, b);
}

// CHECK-LABEL: @test_vqsubq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VQSUBQ_V2_I:%.*]] = call <2 x i64> @llvm.usub.sat.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VQSUBQ_V3_I:%.*]] = bitcast <2 x i64> [[VQSUBQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VQSUBQ_V2_I]]
uint64x2_t test_vqsubq_u64(uint64x2_t a, uint64x2_t b) {
  return vqsubq_u64(a, b);
}

// CHECK-LABEL: @test_vraddhn_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRADDHN_V2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vraddhn.v8i8(<8 x i16> %a, <8 x i16> %b)
// CHECK:   ret <8 x i8> [[VRADDHN_V2_I]]
int8x8_t test_vraddhn_s16(int16x8_t a, int16x8_t b) {
  return vraddhn_s16(a, b);
}

// CHECK-LABEL: @test_vraddhn_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRADDHN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vraddhn.v4i16(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRADDHN_V3_I:%.*]] = bitcast <4 x i16> [[VRADDHN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRADDHN_V2_I]]
int16x4_t test_vraddhn_s32(int32x4_t a, int32x4_t b) {
  return vraddhn_s32(a, b);
}

// CHECK-LABEL: @test_vraddhn_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VRADDHN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vraddhn.v2i32(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VRADDHN_V3_I:%.*]] = bitcast <2 x i32> [[VRADDHN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRADDHN_V2_I]]
int32x2_t test_vraddhn_s64(int64x2_t a, int64x2_t b) {
  return vraddhn_s64(a, b);
}

// CHECK-LABEL: @test_vraddhn_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRADDHN_V2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vraddhn.v8i8(<8 x i16> %a, <8 x i16> %b)
// CHECK:   ret <8 x i8> [[VRADDHN_V2_I]]
uint8x8_t test_vraddhn_u16(uint16x8_t a, uint16x8_t b) {
  return vraddhn_u16(a, b);
}

// CHECK-LABEL: @test_vraddhn_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRADDHN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vraddhn.v4i16(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRADDHN_V3_I:%.*]] = bitcast <4 x i16> [[VRADDHN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRADDHN_V2_I]]
uint16x4_t test_vraddhn_u32(uint32x4_t a, uint32x4_t b) {
  return vraddhn_u32(a, b);
}

// CHECK-LABEL: @test_vraddhn_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VRADDHN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vraddhn.v2i32(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VRADDHN_V3_I:%.*]] = bitcast <2 x i32> [[VRADDHN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRADDHN_V2_I]]
uint32x2_t test_vraddhn_u64(uint64x2_t a, uint64x2_t b) {
  return vraddhn_u64(a, b);
}

// CHECK-LABEL: @test_vrecpe_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[VRECPE_V1_I:%.*]] = call <2 x float> @llvm.arm.neon.vrecpe.v2f32(<2 x float> %a)
// CHECK:   ret <2 x float> [[VRECPE_V1_I]]
float32x2_t test_vrecpe_f32(float32x2_t a) {
  return vrecpe_f32(a);
}

// CHECK-LABEL: @test_vrecpe_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VRECPE_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrecpe.v2i32(<2 x i32> %a)
// CHECK:   ret <2 x i32> [[VRECPE_V1_I]]
uint32x2_t test_vrecpe_u32(uint32x2_t a) {
  return vrecpe_u32(a);
}

// CHECK-LABEL: @test_vrecpeq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VRECPEQ_V1_I:%.*]] = call <4 x float> @llvm.arm.neon.vrecpe.v4f32(<4 x float> %a)
// CHECK:   ret <4 x float> [[VRECPEQ_V1_I]]
float32x4_t test_vrecpeq_f32(float32x4_t a) {
  return vrecpeq_f32(a);
}

// CHECK-LABEL: @test_vrecpeq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VRECPEQ_V1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vrecpe.v4i32(<4 x i32> %a)
// CHECK:   ret <4 x i32> [[VRECPEQ_V1_I]]
uint32x4_t test_vrecpeq_u32(uint32x4_t a) {
  return vrecpeq_u32(a);
}

// CHECK-LABEL: @test_vrecps_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VRECPS_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vrecps.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VRECPS_V3_I:%.*]] = bitcast <2 x float> [[VRECPS_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VRECPS_V2_I]]
float32x2_t test_vrecps_f32(float32x2_t a, float32x2_t b) {
  return vrecps_f32(a, b);
}

// CHECK-LABEL: @test_vrecpsq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VRECPSQ_V2_I:%.*]] = call <4 x float> @llvm.arm.neon.vrecps.v4f32(<4 x float> %a, <4 x float> %b)
// CHECK:   [[VRECPSQ_V3_I:%.*]] = bitcast <4 x float> [[VRECPSQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x float> [[VRECPSQ_V2_I]]
float32x4_t test_vrecpsq_f32(float32x4_t a, float32x4_t b) {
  return vrecpsq_f32(a, b);
}

// CHECK-LABEL: @test_vreinterpret_s8_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_s16(int16x4_t a) {
  return vreinterpret_s8_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_s32(int32x2_t a) {
  return vreinterpret_s8_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_s64(int64x1_t a) {
  return vreinterpret_s8_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_u8(
// CHECK:   ret <8 x i8> %a
int8x8_t test_vreinterpret_s8_u8(uint8x8_t a) {
  return vreinterpret_s8_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_u16(uint16x4_t a) {
  return vreinterpret_s8_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_u32(uint32x2_t a) {
  return vreinterpret_s8_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_u64(uint64x1_t a) {
  return vreinterpret_s8_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_f16(float16x4_t a) {
  return vreinterpret_s8_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_f32(float32x2_t a) {
  return vreinterpret_s8_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_p8(
// CHECK:   ret <8 x i8> %a
int8x8_t test_vreinterpret_s8_p8(poly8x8_t a) {
  return vreinterpret_s8_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_s8_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vreinterpret_s8_p16(poly16x4_t a) {
  return vreinterpret_s8_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_s8(int8x8_t a) {
  return vreinterpret_s16_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_s32(int32x2_t a) {
  return vreinterpret_s16_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_s64(int64x1_t a) {
  return vreinterpret_s16_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_u8(uint8x8_t a) {
  return vreinterpret_s16_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_u16(
// CHECK:   ret <4 x i16> %a
int16x4_t test_vreinterpret_s16_u16(uint16x4_t a) {
  return vreinterpret_s16_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_u32(uint32x2_t a) {
  return vreinterpret_s16_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_u64(uint64x1_t a) {
  return vreinterpret_s16_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_f16(float16x4_t a) {
  return vreinterpret_s16_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_f32(float32x2_t a) {
  return vreinterpret_s16_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
int16x4_t test_vreinterpret_s16_p8(poly8x8_t a) {
  return vreinterpret_s16_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_s16_p16(
// CHECK:   ret <4 x i16> %a
int16x4_t test_vreinterpret_s16_p16(poly16x4_t a) {
  return vreinterpret_s16_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_s8(int8x8_t a) {
  return vreinterpret_s32_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_s16(int16x4_t a) {
  return vreinterpret_s32_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_s64(int64x1_t a) {
  return vreinterpret_s32_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_u8(uint8x8_t a) {
  return vreinterpret_s32_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_u16(uint16x4_t a) {
  return vreinterpret_s32_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_u32(
// CHECK:   ret <2 x i32> %a
int32x2_t test_vreinterpret_s32_u32(uint32x2_t a) {
  return vreinterpret_s32_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_u64(uint64x1_t a) {
  return vreinterpret_s32_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_f16(float16x4_t a) {
  return vreinterpret_s32_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_f32(float32x2_t a) {
  return vreinterpret_s32_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_p8(poly8x8_t a) {
  return vreinterpret_s32_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_s32_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
int32x2_t test_vreinterpret_s32_p16(poly16x4_t a) {
  return vreinterpret_s32_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_s8(int8x8_t a) {
  return vreinterpret_s64_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_s16(int16x4_t a) {
  return vreinterpret_s64_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_s32(int32x2_t a) {
  return vreinterpret_s64_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_u8(uint8x8_t a) {
  return vreinterpret_s64_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_u16(uint16x4_t a) {
  return vreinterpret_s64_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_u32(uint32x2_t a) {
  return vreinterpret_s64_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_u64(
// CHECK:   ret <1 x i64> %a
int64x1_t test_vreinterpret_s64_u64(uint64x1_t a) {
  return vreinterpret_s64_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_f16(float16x4_t a) {
  return vreinterpret_s64_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_f32(float32x2_t a) {
  return vreinterpret_s64_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_p8(poly8x8_t a) {
  return vreinterpret_s64_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_s64_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
int64x1_t test_vreinterpret_s64_p16(poly16x4_t a) {
  return vreinterpret_s64_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_s8(
// CHECK:   ret <8 x i8> %a
uint8x8_t test_vreinterpret_u8_s8(int8x8_t a) {
  return vreinterpret_u8_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_s16(int16x4_t a) {
  return vreinterpret_u8_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_s32(int32x2_t a) {
  return vreinterpret_u8_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_s64(int64x1_t a) {
  return vreinterpret_u8_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_u16(uint16x4_t a) {
  return vreinterpret_u8_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_u32(uint32x2_t a) {
  return vreinterpret_u8_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_u64(uint64x1_t a) {
  return vreinterpret_u8_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_f16(float16x4_t a) {
  return vreinterpret_u8_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_f32(float32x2_t a) {
  return vreinterpret_u8_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_p8(
// CHECK:   ret <8 x i8> %a
uint8x8_t test_vreinterpret_u8_p8(poly8x8_t a) {
  return vreinterpret_u8_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_u8_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vreinterpret_u8_p16(poly16x4_t a) {
  return vreinterpret_u8_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_s8(int8x8_t a) {
  return vreinterpret_u16_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_s16(
// CHECK:   ret <4 x i16> %a
uint16x4_t test_vreinterpret_u16_s16(int16x4_t a) {
  return vreinterpret_u16_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_s32(int32x2_t a) {
  return vreinterpret_u16_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_s64(int64x1_t a) {
  return vreinterpret_u16_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_u8(uint8x8_t a) {
  return vreinterpret_u16_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_u32(uint32x2_t a) {
  return vreinterpret_u16_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_u64(uint64x1_t a) {
  return vreinterpret_u16_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_f16(float16x4_t a) {
  return vreinterpret_u16_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_f32(float32x2_t a) {
  return vreinterpret_u16_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
uint16x4_t test_vreinterpret_u16_p8(poly8x8_t a) {
  return vreinterpret_u16_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_u16_p16(
// CHECK:   ret <4 x i16> %a
uint16x4_t test_vreinterpret_u16_p16(poly16x4_t a) {
  return vreinterpret_u16_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_s8(int8x8_t a) {
  return vreinterpret_u32_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_s16(int16x4_t a) {
  return vreinterpret_u32_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_s32(
// CHECK:   ret <2 x i32> %a
uint32x2_t test_vreinterpret_u32_s32(int32x2_t a) {
  return vreinterpret_u32_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_s64(int64x1_t a) {
  return vreinterpret_u32_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_u8(uint8x8_t a) {
  return vreinterpret_u32_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_u16(uint16x4_t a) {
  return vreinterpret_u32_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_u64(uint64x1_t a) {
  return vreinterpret_u32_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_f16(float16x4_t a) {
  return vreinterpret_u32_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_f32(float32x2_t a) {
  return vreinterpret_u32_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_p8(poly8x8_t a) {
  return vreinterpret_u32_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_u32_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x i32>
// CHECK:   ret <2 x i32> [[TMP0]]
uint32x2_t test_vreinterpret_u32_p16(poly16x4_t a) {
  return vreinterpret_u32_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_s8(int8x8_t a) {
  return vreinterpret_u64_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_s16(int16x4_t a) {
  return vreinterpret_u64_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_s32(int32x2_t a) {
  return vreinterpret_u64_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_s64(
// CHECK:   ret <1 x i64> %a
uint64x1_t test_vreinterpret_u64_s64(int64x1_t a) {
  return vreinterpret_u64_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_u8(uint8x8_t a) {
  return vreinterpret_u64_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_u16(uint16x4_t a) {
  return vreinterpret_u64_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_u32(uint32x2_t a) {
  return vreinterpret_u64_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_f16(float16x4_t a) {
  return vreinterpret_u64_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_f32(float32x2_t a) {
  return vreinterpret_u64_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_p8(poly8x8_t a) {
  return vreinterpret_u64_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_u64_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <1 x i64>
// CHECK:   ret <1 x i64> [[TMP0]]
uint64x1_t test_vreinterpret_u64_p16(poly16x4_t a) {
  return vreinterpret_u64_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_s8(int8x8_t a) {
  return vreinterpret_f16_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_s16(int16x4_t a) {
  return vreinterpret_f16_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_s32(int32x2_t a) {
  return vreinterpret_f16_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_s64(int64x1_t a) {
  return vreinterpret_f16_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_u8(uint8x8_t a) {
  return vreinterpret_f16_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_u16(uint16x4_t a) {
  return vreinterpret_f16_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_u32(uint32x2_t a) {
  return vreinterpret_f16_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_u64(uint64x1_t a) {
  return vreinterpret_f16_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_f32(float32x2_t a) {
  return vreinterpret_f16_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_p8(poly8x8_t a) {
  return vreinterpret_f16_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_f16_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <4 x half>
// CHECK:   ret <4 x half> [[TMP0]]
float16x4_t test_vreinterpret_f16_p16(poly16x4_t a) {
  return vreinterpret_f16_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_s8(int8x8_t a) {
  return vreinterpret_f32_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_s16(int16x4_t a) {
  return vreinterpret_f32_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_s32(int32x2_t a) {
  return vreinterpret_f32_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_s64(int64x1_t a) {
  return vreinterpret_f32_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_u8(uint8x8_t a) {
  return vreinterpret_f32_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_u16(uint16x4_t a) {
  return vreinterpret_f32_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_u32(uint32x2_t a) {
  return vreinterpret_f32_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_u64(uint64x1_t a) {
  return vreinterpret_f32_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_f16(float16x4_t a) {
  return vreinterpret_f32_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_p8(poly8x8_t a) {
  return vreinterpret_f32_p8(a);
}

// CHECK-LABEL: @test_vreinterpret_f32_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <2 x float>
// CHECK:   ret <2 x float> [[TMP0]]
float32x2_t test_vreinterpret_f32_p16(poly16x4_t a) {
  return vreinterpret_f32_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_s8(
// CHECK:   ret <8 x i8> %a
poly8x8_t test_vreinterpret_p8_s8(int8x8_t a) {
  return vreinterpret_p8_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_s16(int16x4_t a) {
  return vreinterpret_p8_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_s32(int32x2_t a) {
  return vreinterpret_p8_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_s64(int64x1_t a) {
  return vreinterpret_p8_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_u8(
// CHECK:   ret <8 x i8> %a
poly8x8_t test_vreinterpret_p8_u8(uint8x8_t a) {
  return vreinterpret_p8_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_u16(uint16x4_t a) {
  return vreinterpret_p8_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_u32(uint32x2_t a) {
  return vreinterpret_p8_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_u64(uint64x1_t a) {
  return vreinterpret_p8_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_f16(float16x4_t a) {
  return vreinterpret_p8_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_f32(float32x2_t a) {
  return vreinterpret_p8_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_p8_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   ret <8 x i8> [[TMP0]]
poly8x8_t test_vreinterpret_p8_p16(poly16x4_t a) {
  return vreinterpret_p8_p16(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_s8(int8x8_t a) {
  return vreinterpret_p16_s8(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_s16(
// CHECK:   ret <4 x i16> %a
poly16x4_t test_vreinterpret_p16_s16(int16x4_t a) {
  return vreinterpret_p16_s16(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_s32(int32x2_t a) {
  return vreinterpret_p16_s32(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_s64(int64x1_t a) {
  return vreinterpret_p16_s64(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_u8(uint8x8_t a) {
  return vreinterpret_p16_u8(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_u16(
// CHECK:   ret <4 x i16> %a
poly16x4_t test_vreinterpret_p16_u16(uint16x4_t a) {
  return vreinterpret_p16_u16(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_u32(uint32x2_t a) {
  return vreinterpret_p16_u32(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_u64(uint64x1_t a) {
  return vreinterpret_p16_u64(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x half> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_f16(float16x4_t a) {
  return vreinterpret_p16_f16(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_f32(float32x2_t a) {
  return vreinterpret_p16_f32(a);
}

// CHECK-LABEL: @test_vreinterpret_p16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i8> %a to <4 x i16>
// CHECK:   ret <4 x i16> [[TMP0]]
poly16x4_t test_vreinterpret_p16_p8(poly8x8_t a) {
  return vreinterpret_p16_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_s16(int16x8_t a) {
  return vreinterpretq_s8_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_s32(int32x4_t a) {
  return vreinterpretq_s8_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_s64(int64x2_t a) {
  return vreinterpretq_s8_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_u8(
// CHECK:   ret <16 x i8> %a
int8x16_t test_vreinterpretq_s8_u8(uint8x16_t a) {
  return vreinterpretq_s8_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_u16(uint16x8_t a) {
  return vreinterpretq_s8_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_u32(uint32x4_t a) {
  return vreinterpretq_s8_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_u64(uint64x2_t a) {
  return vreinterpretq_s8_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_f16(float16x8_t a) {
  return vreinterpretq_s8_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_f32(float32x4_t a) {
  return vreinterpretq_s8_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_p8(
// CHECK:   ret <16 x i8> %a
int8x16_t test_vreinterpretq_s8_p8(poly8x16_t a) {
  return vreinterpretq_s8_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s8_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vreinterpretq_s8_p16(poly16x8_t a) {
  return vreinterpretq_s8_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_s8(int8x16_t a) {
  return vreinterpretq_s16_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_s32(int32x4_t a) {
  return vreinterpretq_s16_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_s64(int64x2_t a) {
  return vreinterpretq_s16_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_u8(uint8x16_t a) {
  return vreinterpretq_s16_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_u16(
// CHECK:   ret <8 x i16> %a
int16x8_t test_vreinterpretq_s16_u16(uint16x8_t a) {
  return vreinterpretq_s16_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_u32(uint32x4_t a) {
  return vreinterpretq_s16_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_u64(uint64x2_t a) {
  return vreinterpretq_s16_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_f16(float16x8_t a) {
  return vreinterpretq_s16_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_f32(float32x4_t a) {
  return vreinterpretq_s16_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
int16x8_t test_vreinterpretq_s16_p8(poly8x16_t a) {
  return vreinterpretq_s16_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s16_p16(
// CHECK:   ret <8 x i16> %a
int16x8_t test_vreinterpretq_s16_p16(poly16x8_t a) {
  return vreinterpretq_s16_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_s8(int8x16_t a) {
  return vreinterpretq_s32_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_s16(int16x8_t a) {
  return vreinterpretq_s32_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_s64(int64x2_t a) {
  return vreinterpretq_s32_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_u8(uint8x16_t a) {
  return vreinterpretq_s32_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_u16(uint16x8_t a) {
  return vreinterpretq_s32_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_u32(
// CHECK:   ret <4 x i32> %a
int32x4_t test_vreinterpretq_s32_u32(uint32x4_t a) {
  return vreinterpretq_s32_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_u64(uint64x2_t a) {
  return vreinterpretq_s32_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_f16(float16x8_t a) {
  return vreinterpretq_s32_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_f32(float32x4_t a) {
  return vreinterpretq_s32_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_p8(poly8x16_t a) {
  return vreinterpretq_s32_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s32_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
int32x4_t test_vreinterpretq_s32_p16(poly16x8_t a) {
  return vreinterpretq_s32_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_s8(int8x16_t a) {
  return vreinterpretq_s64_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_s16(int16x8_t a) {
  return vreinterpretq_s64_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_s32(int32x4_t a) {
  return vreinterpretq_s64_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_u8(uint8x16_t a) {
  return vreinterpretq_s64_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_u16(uint16x8_t a) {
  return vreinterpretq_s64_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_u32(uint32x4_t a) {
  return vreinterpretq_s64_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_u64(
// CHECK:   ret <2 x i64> %a
int64x2_t test_vreinterpretq_s64_u64(uint64x2_t a) {
  return vreinterpretq_s64_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_f16(float16x8_t a) {
  return vreinterpretq_s64_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_f32(float32x4_t a) {
  return vreinterpretq_s64_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_p8(poly8x16_t a) {
  return vreinterpretq_s64_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_s64_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
int64x2_t test_vreinterpretq_s64_p16(poly16x8_t a) {
  return vreinterpretq_s64_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_s8(
// CHECK:   ret <16 x i8> %a
uint8x16_t test_vreinterpretq_u8_s8(int8x16_t a) {
  return vreinterpretq_u8_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_s16(int16x8_t a) {
  return vreinterpretq_u8_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_s32(int32x4_t a) {
  return vreinterpretq_u8_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_s64(int64x2_t a) {
  return vreinterpretq_u8_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_u16(uint16x8_t a) {
  return vreinterpretq_u8_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_u32(uint32x4_t a) {
  return vreinterpretq_u8_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_u64(uint64x2_t a) {
  return vreinterpretq_u8_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_f16(float16x8_t a) {
  return vreinterpretq_u8_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_f32(float32x4_t a) {
  return vreinterpretq_u8_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_p8(
// CHECK:   ret <16 x i8> %a
uint8x16_t test_vreinterpretq_u8_p8(poly8x16_t a) {
  return vreinterpretq_u8_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u8_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vreinterpretq_u8_p16(poly16x8_t a) {
  return vreinterpretq_u8_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_s8(int8x16_t a) {
  return vreinterpretq_u16_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_s16(
// CHECK:   ret <8 x i16> %a
uint16x8_t test_vreinterpretq_u16_s16(int16x8_t a) {
  return vreinterpretq_u16_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_s32(int32x4_t a) {
  return vreinterpretq_u16_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_s64(int64x2_t a) {
  return vreinterpretq_u16_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_u8(uint8x16_t a) {
  return vreinterpretq_u16_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_u32(uint32x4_t a) {
  return vreinterpretq_u16_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_u64(uint64x2_t a) {
  return vreinterpretq_u16_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_f16(float16x8_t a) {
  return vreinterpretq_u16_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_f32(float32x4_t a) {
  return vreinterpretq_u16_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
uint16x8_t test_vreinterpretq_u16_p8(poly8x16_t a) {
  return vreinterpretq_u16_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u16_p16(
// CHECK:   ret <8 x i16> %a
uint16x8_t test_vreinterpretq_u16_p16(poly16x8_t a) {
  return vreinterpretq_u16_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_s8(int8x16_t a) {
  return vreinterpretq_u32_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_s16(int16x8_t a) {
  return vreinterpretq_u32_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_s32(
// CHECK:   ret <4 x i32> %a
uint32x4_t test_vreinterpretq_u32_s32(int32x4_t a) {
  return vreinterpretq_u32_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_s64(int64x2_t a) {
  return vreinterpretq_u32_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_u8(uint8x16_t a) {
  return vreinterpretq_u32_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_u16(uint16x8_t a) {
  return vreinterpretq_u32_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_u64(uint64x2_t a) {
  return vreinterpretq_u32_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_f16(float16x8_t a) {
  return vreinterpretq_u32_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_f32(float32x4_t a) {
  return vreinterpretq_u32_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_p8(poly8x16_t a) {
  return vreinterpretq_u32_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u32_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x i32>
// CHECK:   ret <4 x i32> [[TMP0]]
uint32x4_t test_vreinterpretq_u32_p16(poly16x8_t a) {
  return vreinterpretq_u32_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_s8(int8x16_t a) {
  return vreinterpretq_u64_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_s16(int16x8_t a) {
  return vreinterpretq_u64_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_s32(int32x4_t a) {
  return vreinterpretq_u64_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_s64(
// CHECK:   ret <2 x i64> %a
uint64x2_t test_vreinterpretq_u64_s64(int64x2_t a) {
  return vreinterpretq_u64_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_u8(uint8x16_t a) {
  return vreinterpretq_u64_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_u16(uint16x8_t a) {
  return vreinterpretq_u64_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_u32(uint32x4_t a) {
  return vreinterpretq_u64_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_f16(float16x8_t a) {
  return vreinterpretq_u64_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_f32(float32x4_t a) {
  return vreinterpretq_u64_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_p8(poly8x16_t a) {
  return vreinterpretq_u64_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_u64_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <2 x i64>
// CHECK:   ret <2 x i64> [[TMP0]]
uint64x2_t test_vreinterpretq_u64_p16(poly16x8_t a) {
  return vreinterpretq_u64_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_s8(int8x16_t a) {
  return vreinterpretq_f16_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_s16(int16x8_t a) {
  return vreinterpretq_f16_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_s32(int32x4_t a) {
  return vreinterpretq_f16_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_s64(int64x2_t a) {
  return vreinterpretq_f16_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_u8(uint8x16_t a) {
  return vreinterpretq_f16_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_u16(uint16x8_t a) {
  return vreinterpretq_f16_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_u32(uint32x4_t a) {
  return vreinterpretq_f16_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_u64(uint64x2_t a) {
  return vreinterpretq_f16_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_f32(float32x4_t a) {
  return vreinterpretq_f16_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_p8(poly8x16_t a) {
  return vreinterpretq_f16_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_f16_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <8 x half>
// CHECK:   ret <8 x half> [[TMP0]]
float16x8_t test_vreinterpretq_f16_p16(poly16x8_t a) {
  return vreinterpretq_f16_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_s8(int8x16_t a) {
  return vreinterpretq_f32_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_s16(int16x8_t a) {
  return vreinterpretq_f32_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_s32(int32x4_t a) {
  return vreinterpretq_f32_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_s64(int64x2_t a) {
  return vreinterpretq_f32_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_u8(uint8x16_t a) {
  return vreinterpretq_f32_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_u16(uint16x8_t a) {
  return vreinterpretq_f32_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_u32(uint32x4_t a) {
  return vreinterpretq_f32_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_u64(uint64x2_t a) {
  return vreinterpretq_f32_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_f16(float16x8_t a) {
  return vreinterpretq_f32_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_p8(poly8x16_t a) {
  return vreinterpretq_f32_p8(a);
}

// CHECK-LABEL: @test_vreinterpretq_f32_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <4 x float>
// CHECK:   ret <4 x float> [[TMP0]]
float32x4_t test_vreinterpretq_f32_p16(poly16x8_t a) {
  return vreinterpretq_f32_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_s8(
// CHECK:   ret <16 x i8> %a
poly8x16_t test_vreinterpretq_p8_s8(int8x16_t a) {
  return vreinterpretq_p8_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_s16(int16x8_t a) {
  return vreinterpretq_p8_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_s32(int32x4_t a) {
  return vreinterpretq_p8_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_s64(int64x2_t a) {
  return vreinterpretq_p8_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_u8(
// CHECK:   ret <16 x i8> %a
poly8x16_t test_vreinterpretq_p8_u8(uint8x16_t a) {
  return vreinterpretq_p8_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_u16(uint16x8_t a) {
  return vreinterpretq_p8_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_u32(uint32x4_t a) {
  return vreinterpretq_p8_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_u64(uint64x2_t a) {
  return vreinterpretq_p8_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_f16(float16x8_t a) {
  return vreinterpretq_p8_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_f32(float32x4_t a) {
  return vreinterpretq_p8_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p8_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   ret <16 x i8> [[TMP0]]
poly8x16_t test_vreinterpretq_p8_p16(poly16x8_t a) {
  return vreinterpretq_p8_p16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_s8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_s8(int8x16_t a) {
  return vreinterpretq_p16_s8(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_s16(
// CHECK:   ret <8 x i16> %a
poly16x8_t test_vreinterpretq_p16_s16(int16x8_t a) {
  return vreinterpretq_p16_s16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_s32(int32x4_t a) {
  return vreinterpretq_p16_s32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_s64(int64x2_t a) {
  return vreinterpretq_p16_s64(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_u8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_u8(uint8x16_t a) {
  return vreinterpretq_p16_u8(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_u16(
// CHECK:   ret <8 x i16> %a
poly16x8_t test_vreinterpretq_p16_u16(uint16x8_t a) {
  return vreinterpretq_p16_u16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_u32(uint32x4_t a) {
  return vreinterpretq_p16_u32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_u64(uint64x2_t a) {
  return vreinterpretq_p16_u64(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_f16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x half> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_f16(float16x8_t a) {
  return vreinterpretq_p16_f16(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_f32(float32x4_t a) {
  return vreinterpretq_p16_f32(a);
}

// CHECK-LABEL: @test_vreinterpretq_p16_p8(
// CHECK:   [[TMP0:%.*]] = bitcast <16 x i8> %a to <8 x i16>
// CHECK:   ret <8 x i16> [[TMP0]]
poly16x8_t test_vreinterpretq_p16_p8(poly8x16_t a) {
  return vreinterpretq_p16_p8(a);
}

// CHECK-LABEL: @test_vrev16_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
int8x8_t test_vrev16_s8(int8x8_t a) {
  return vrev16_s8(a);
}

// CHECK-LABEL: @test_vrev16_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
uint8x8_t test_vrev16_u8(uint8x8_t a) {
  return vrev16_u8(a);
}

// CHECK-LABEL: @test_vrev16_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
poly8x8_t test_vrev16_p8(poly8x8_t a) {
  return vrev16_p8(a);
}

// CHECK-LABEL: @test_vrev16q_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6, i32 9, i32 8, i32 11, i32 10, i32 13, i32 12, i32 15, i32 14>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
int8x16_t test_vrev16q_s8(int8x16_t a) {
  return vrev16q_s8(a);
}

// CHECK-LABEL: @test_vrev16q_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6, i32 9, i32 8, i32 11, i32 10, i32 13, i32 12, i32 15, i32 14>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
uint8x16_t test_vrev16q_u8(uint8x16_t a) {
  return vrev16q_u8(a);
}

// CHECK-LABEL: @test_vrev16q_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6, i32 9, i32 8, i32 11, i32 10, i32 13, i32 12, i32 15, i32 14>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
poly8x16_t test_vrev16q_p8(poly8x16_t a) {
  return vrev16q_p8(a);
}

// CHECK-LABEL: @test_vrev32_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
int8x8_t test_vrev32_s8(int8x8_t a) {
  return vrev32_s8(a);
}

// CHECK-LABEL: @test_vrev32_s16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %a, <4 x i32> <i32 1, i32 0, i32 3, i32 2>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
int16x4_t test_vrev32_s16(int16x4_t a) {
  return vrev32_s16(a);
}

// CHECK-LABEL: @test_vrev32_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
uint8x8_t test_vrev32_u8(uint8x8_t a) {
  return vrev32_u8(a);
}

// CHECK-LABEL: @test_vrev32_u16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %a, <4 x i32> <i32 1, i32 0, i32 3, i32 2>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
uint16x4_t test_vrev32_u16(uint16x4_t a) {
  return vrev32_u16(a);
}

// CHECK-LABEL: @test_vrev32_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
poly8x8_t test_vrev32_p8(poly8x8_t a) {
  return vrev32_p8(a);
}

// CHECK-LABEL: @test_vrev32_p16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %a, <4 x i32> <i32 1, i32 0, i32 3, i32 2>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
poly16x4_t test_vrev32_p16(poly16x4_t a) {
  return vrev32_p16(a);
}

// CHECK-LABEL: @test_vrev32q_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4, i32 11, i32 10, i32 9, i32 8, i32 15, i32 14, i32 13, i32 12>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
int8x16_t test_vrev32q_s8(int8x16_t a) {
  return vrev32q_s8(a);
}

// CHECK-LABEL: @test_vrev32q_s16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <8 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
int16x8_t test_vrev32q_s16(int16x8_t a) {
  return vrev32q_s16(a);
}

// CHECK-LABEL: @test_vrev32q_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4, i32 11, i32 10, i32 9, i32 8, i32 15, i32 14, i32 13, i32 12>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
uint8x16_t test_vrev32q_u8(uint8x16_t a) {
  return vrev32q_u8(a);
}

// CHECK-LABEL: @test_vrev32q_u16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <8 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
uint16x8_t test_vrev32q_u16(uint16x8_t a) {
  return vrev32q_u16(a);
}

// CHECK-LABEL: @test_vrev32q_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4, i32 11, i32 10, i32 9, i32 8, i32 15, i32 14, i32 13, i32 12>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
poly8x16_t test_vrev32q_p8(poly8x16_t a) {
  return vrev32q_p8(a);
}

// CHECK-LABEL: @test_vrev32q_p16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <8 x i32> <i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
poly16x8_t test_vrev32q_p16(poly16x8_t a) {
  return vrev32q_p16(a);
}

// CHECK-LABEL: @test_vrev64_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
int8x8_t test_vrev64_s8(int8x8_t a) {
  return vrev64_s8(a);
}

// CHECK-LABEL: @test_vrev64_s16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %a, <4 x i32> <i32 3, i32 2, i32 1, i32 0>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
int16x4_t test_vrev64_s16(int16x4_t a) {
  return vrev64_s16(a);
}

// CHECK-LABEL: @test_vrev64_s32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %a, <2 x i32> <i32 1, i32 0>
// CHECK:   ret <2 x i32> [[SHUFFLE_I]]
int32x2_t test_vrev64_s32(int32x2_t a) {
  return vrev64_s32(a);
}

// CHECK-LABEL: @test_vrev64_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
uint8x8_t test_vrev64_u8(uint8x8_t a) {
  return vrev64_u8(a);
}

// CHECK-LABEL: @test_vrev64_u16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %a, <4 x i32> <i32 3, i32 2, i32 1, i32 0>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
uint16x4_t test_vrev64_u16(uint16x4_t a) {
  return vrev64_u16(a);
}

// CHECK-LABEL: @test_vrev64_u32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %a, <2 x i32> <i32 1, i32 0>
// CHECK:   ret <2 x i32> [[SHUFFLE_I]]
uint32x2_t test_vrev64_u32(uint32x2_t a) {
  return vrev64_u32(a);
}

// CHECK-LABEL: @test_vrev64_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %a, <8 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
// CHECK:   ret <8 x i8> [[SHUFFLE_I]]
poly8x8_t test_vrev64_p8(poly8x8_t a) {
  return vrev64_p8(a);
}

// CHECK-LABEL: @test_vrev64_p16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %a, <4 x i32> <i32 3, i32 2, i32 1, i32 0>
// CHECK:   ret <4 x i16> [[SHUFFLE_I]]
poly16x4_t test_vrev64_p16(poly16x4_t a) {
  return vrev64_p16(a);
}

// CHECK-LABEL: @test_vrev64_f32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %a, <2 x i32> <i32 1, i32 0>
// CHECK:   ret <2 x float> [[SHUFFLE_I]]
float32x2_t test_vrev64_f32(float32x2_t a) {
  return vrev64_f32(a);
}

// CHECK-LABEL: @test_vrev64q_s8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
int8x16_t test_vrev64q_s8(int8x16_t a) {
  return vrev64q_s8(a);
}

// CHECK-LABEL: @test_vrev64q_s16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <8 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
int16x8_t test_vrev64q_s16(int16x8_t a) {
  return vrev64q_s16(a);
}

// CHECK-LABEL: @test_vrev64q_s32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %a, <4 x i32> <i32 1, i32 0, i32 3, i32 2>
// CHECK:   ret <4 x i32> [[SHUFFLE_I]]
int32x4_t test_vrev64q_s32(int32x4_t a) {
  return vrev64q_s32(a);
}

// CHECK-LABEL: @test_vrev64q_u8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
uint8x16_t test_vrev64q_u8(uint8x16_t a) {
  return vrev64q_u8(a);
}

// CHECK-LABEL: @test_vrev64q_u16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <8 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
uint16x8_t test_vrev64q_u16(uint16x8_t a) {
  return vrev64q_u16(a);
}

// CHECK-LABEL: @test_vrev64q_u32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %a, <4 x i32> <i32 1, i32 0, i32 3, i32 2>
// CHECK:   ret <4 x i32> [[SHUFFLE_I]]
uint32x4_t test_vrev64q_u32(uint32x4_t a) {
  return vrev64q_u32(a);
}

// CHECK-LABEL: @test_vrev64q_p8(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %a, <16 x i32> <i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
// CHECK:   ret <16 x i8> [[SHUFFLE_I]]
poly8x16_t test_vrev64q_p8(poly8x16_t a) {
  return vrev64q_p8(a);
}

// CHECK-LABEL: @test_vrev64q_p16(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %a, <8 x i32> <i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
// CHECK:   ret <8 x i16> [[SHUFFLE_I]]
poly16x8_t test_vrev64q_p16(poly16x8_t a) {
  return vrev64q_p16(a);
}

// CHECK-LABEL: @test_vrev64q_f32(
// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %a, <4 x i32> <i32 1, i32 0, i32 3, i32 2>
// CHECK:   ret <4 x float> [[SHUFFLE_I]]
float32x4_t test_vrev64q_f32(float32x4_t a) {
  return vrev64q_f32(a);
}

// CHECK-LABEL: @test_vrhadd_s8(
// CHECK:   [[VRHADD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vrhadds.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VRHADD_V_I]]
int8x8_t test_vrhadd_s8(int8x8_t a, int8x8_t b) {
  return vrhadd_s8(a, b);
}

// CHECK-LABEL: @test_vrhadd_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VRHADD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vrhadds.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VRHADD_V3_I:%.*]] = bitcast <4 x i16> [[VRHADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRHADD_V2_I]]
int16x4_t test_vrhadd_s16(int16x4_t a, int16x4_t b) {
  return vrhadd_s16(a, b);
}

// CHECK-LABEL: @test_vrhadd_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VRHADD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrhadds.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VRHADD_V3_I:%.*]] = bitcast <2 x i32> [[VRHADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRHADD_V2_I]]
int32x2_t test_vrhadd_s32(int32x2_t a, int32x2_t b) {
  return vrhadd_s32(a, b);
}

// CHECK-LABEL: @test_vrhadd_u8(
// CHECK:   [[VRHADD_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vrhaddu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VRHADD_V_I]]
uint8x8_t test_vrhadd_u8(uint8x8_t a, uint8x8_t b) {
  return vrhadd_u8(a, b);
}

// CHECK-LABEL: @test_vrhadd_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VRHADD_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vrhaddu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VRHADD_V3_I:%.*]] = bitcast <4 x i16> [[VRHADD_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRHADD_V2_I]]
uint16x4_t test_vrhadd_u16(uint16x4_t a, uint16x4_t b) {
  return vrhadd_u16(a, b);
}

// CHECK-LABEL: @test_vrhadd_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VRHADD_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrhaddu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VRHADD_V3_I:%.*]] = bitcast <2 x i32> [[VRHADD_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRHADD_V2_I]]
uint32x2_t test_vrhadd_u32(uint32x2_t a, uint32x2_t b) {
  return vrhadd_u32(a, b);
}

// CHECK-LABEL: @test_vrhaddq_s8(
// CHECK:   [[VRHADDQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vrhadds.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VRHADDQ_V_I]]
int8x16_t test_vrhaddq_s8(int8x16_t a, int8x16_t b) {
  return vrhaddq_s8(a, b);
}

// CHECK-LABEL: @test_vrhaddq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRHADDQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vrhadds.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VRHADDQ_V3_I:%.*]] = bitcast <8 x i16> [[VRHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VRHADDQ_V2_I]]
int16x8_t test_vrhaddq_s16(int16x8_t a, int16x8_t b) {
  return vrhaddq_s16(a, b);
}

// CHECK-LABEL: @test_vrhaddq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRHADDQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vrhadds.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRHADDQ_V3_I:%.*]] = bitcast <4 x i32> [[VRHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VRHADDQ_V2_I]]
int32x4_t test_vrhaddq_s32(int32x4_t a, int32x4_t b) {
  return vrhaddq_s32(a, b);
}

// CHECK-LABEL: @test_vrhaddq_u8(
// CHECK:   [[VRHADDQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vrhaddu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VRHADDQ_V_I]]
uint8x16_t test_vrhaddq_u8(uint8x16_t a, uint8x16_t b) {
  return vrhaddq_u8(a, b);
}

// CHECK-LABEL: @test_vrhaddq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRHADDQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vrhaddu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VRHADDQ_V3_I:%.*]] = bitcast <8 x i16> [[VRHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VRHADDQ_V2_I]]
uint16x8_t test_vrhaddq_u16(uint16x8_t a, uint16x8_t b) {
  return vrhaddq_u16(a, b);
}

// CHECK-LABEL: @test_vrhaddq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRHADDQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vrhaddu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRHADDQ_V3_I:%.*]] = bitcast <4 x i32> [[VRHADDQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VRHADDQ_V2_I]]
uint32x4_t test_vrhaddq_u32(uint32x4_t a, uint32x4_t b) {
  return vrhaddq_u32(a, b);
}

// CHECK-LABEL: @test_vrshl_s8(
// CHECK:   [[VRSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vrshifts.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VRSHL_V_I]]
int8x8_t test_vrshl_s8(int8x8_t a, int8x8_t b) {
  return vrshl_s8(a, b);
}

// CHECK-LABEL: @test_vrshl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VRSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vrshifts.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VRSHL_V3_I:%.*]] = bitcast <4 x i16> [[VRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRSHL_V2_I]]
int16x4_t test_vrshl_s16(int16x4_t a, int16x4_t b) {
  return vrshl_s16(a, b);
}

// CHECK-LABEL: @test_vrshl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VRSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrshifts.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VRSHL_V3_I:%.*]] = bitcast <2 x i32> [[VRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRSHL_V2_I]]
int32x2_t test_vrshl_s32(int32x2_t a, int32x2_t b) {
  return vrshl_s32(a, b);
}

// CHECK-LABEL: @test_vrshl_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VRSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vrshifts.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VRSHL_V3_I:%.*]] = bitcast <1 x i64> [[VRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VRSHL_V2_I]]
int64x1_t test_vrshl_s64(int64x1_t a, int64x1_t b) {
  return vrshl_s64(a, b);
}

// CHECK-LABEL: @test_vrshl_u8(
// CHECK:   [[VRSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vrshiftu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VRSHL_V_I]]
uint8x8_t test_vrshl_u8(uint8x8_t a, int8x8_t b) {
  return vrshl_u8(a, b);
}

// CHECK-LABEL: @test_vrshl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VRSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vrshiftu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VRSHL_V3_I:%.*]] = bitcast <4 x i16> [[VRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRSHL_V2_I]]
uint16x4_t test_vrshl_u16(uint16x4_t a, int16x4_t b) {
  return vrshl_u16(a, b);
}

// CHECK-LABEL: @test_vrshl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VRSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrshiftu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VRSHL_V3_I:%.*]] = bitcast <2 x i32> [[VRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRSHL_V2_I]]
uint32x2_t test_vrshl_u32(uint32x2_t a, int32x2_t b) {
  return vrshl_u32(a, b);
}

// CHECK-LABEL: @test_vrshl_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VRSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vrshiftu.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VRSHL_V3_I:%.*]] = bitcast <1 x i64> [[VRSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VRSHL_V2_I]]
uint64x1_t test_vrshl_u64(uint64x1_t a, int64x1_t b) {
  return vrshl_u64(a, b);
}

// CHECK-LABEL: @test_vrshlq_s8(
// CHECK:   [[VRSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vrshifts.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VRSHLQ_V_I]]
int8x16_t test_vrshlq_s8(int8x16_t a, int8x16_t b) {
  return vrshlq_s8(a, b);
}

// CHECK-LABEL: @test_vrshlq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vrshifts.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VRSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VRSHLQ_V2_I]]
int16x8_t test_vrshlq_s16(int16x8_t a, int16x8_t b) {
  return vrshlq_s16(a, b);
}

// CHECK-LABEL: @test_vrshlq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vrshifts.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VRSHLQ_V2_I]]
int32x4_t test_vrshlq_s32(int32x4_t a, int32x4_t b) {
  return vrshlq_s32(a, b);
}

// CHECK-LABEL: @test_vrshlq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VRSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vrshifts.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VRSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VRSHLQ_V2_I]]
int64x2_t test_vrshlq_s64(int64x2_t a, int64x2_t b) {
  return vrshlq_s64(a, b);
}

// CHECK-LABEL: @test_vrshlq_u8(
// CHECK:   [[VRSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vrshiftu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VRSHLQ_V_I]]
uint8x16_t test_vrshlq_u8(uint8x16_t a, int8x16_t b) {
  return vrshlq_u8(a, b);
}

// CHECK-LABEL: @test_vrshlq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vrshiftu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VRSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VRSHLQ_V2_I]]
uint16x8_t test_vrshlq_u16(uint16x8_t a, int16x8_t b) {
  return vrshlq_u16(a, b);
}

// CHECK-LABEL: @test_vrshlq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vrshiftu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VRSHLQ_V2_I]]
uint32x4_t test_vrshlq_u32(uint32x4_t a, int32x4_t b) {
  return vrshlq_u32(a, b);
}

// CHECK-LABEL: @test_vrshlq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VRSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vrshiftu.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VRSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VRSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VRSHLQ_V2_I]]
uint64x2_t test_vrshlq_u64(uint64x2_t a, int64x2_t b) {
  return vrshlq_u64(a, b);
}

// CHECK-LABEL: @test_vrshrn_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VRSHRN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vrshiftn.v8i8(<8 x i16> [[VRSHRN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VRSHRN_N1]]
int8x8_t test_vrshrn_n_s16(int16x8_t a) {
  return vrshrn_n_s16(a, 1);
}

// CHECK-LABEL: @test_vrshrn_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VRSHRN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vrshiftn.v4i16(<4 x i32> [[VRSHRN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VRSHRN_N1]]
int16x4_t test_vrshrn_n_s32(int32x4_t a) {
  return vrshrn_n_s32(a, 1);
}

// CHECK-LABEL: @test_vrshrn_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VRSHRN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vrshiftn.v2i32(<2 x i64> [[VRSHRN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VRSHRN_N1]]
int32x2_t test_vrshrn_n_s64(int64x2_t a) {
  return vrshrn_n_s64(a, 1);
}

// CHECK-LABEL: @test_vrshrn_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VRSHRN_N1:%.*]] = call <8 x i8> @llvm.arm.neon.vrshiftn.v8i8(<8 x i16> [[VRSHRN_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i8> [[VRSHRN_N1]]
uint8x8_t test_vrshrn_n_u16(uint16x8_t a) {
  return vrshrn_n_u16(a, 1);
}

// CHECK-LABEL: @test_vrshrn_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VRSHRN_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vrshiftn.v4i16(<4 x i32> [[VRSHRN_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i16> [[VRSHRN_N1]]
uint16x4_t test_vrshrn_n_u32(uint32x4_t a) {
  return vrshrn_n_u32(a, 1);
}

// CHECK-LABEL: @test_vrshrn_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VRSHRN_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VRSHRN_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vrshiftn.v2i32(<2 x i64> [[VRSHRN_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i32> [[VRSHRN_N1]]
uint32x2_t test_vrshrn_n_u64(uint64x2_t a) {
  return vrshrn_n_u64(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_s8(
// CHECK:   [[VRSHR_N:%.*]] = call <8 x i8> @llvm.arm.neon.vrshifts.v8i8(<8 x i8> %a, <8 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <8 x i8> [[VRSHR_N]]
int8x8_t test_vrshr_n_s8(int8x8_t a) {
  return vrshr_n_s8(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VRSHR_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vrshifts.v4i16(<4 x i16> [[VRSHR_N]], <4 x i16> <i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <4 x i16> [[VRSHR_N1]]
int16x4_t test_vrshr_n_s16(int16x4_t a) {
  return vrshr_n_s16(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VRSHR_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vrshifts.v2i32(<2 x i32> [[VRSHR_N]], <2 x i32> <i32 -1, i32 -1>)
// CHECK:   ret <2 x i32> [[VRSHR_N1]]
int32x2_t test_vrshr_n_s32(int32x2_t a) {
  return vrshr_n_s32(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VRSHR_N1:%.*]] = call <1 x i64> @llvm.arm.neon.vrshifts.v1i64(<1 x i64> [[VRSHR_N]], <1 x i64> <i64 -1>)
// CHECK:   ret <1 x i64> [[VRSHR_N1]]
int64x1_t test_vrshr_n_s64(int64x1_t a) {
  return vrshr_n_s64(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_u8(
// CHECK:   [[VRSHR_N:%.*]] = call <8 x i8> @llvm.arm.neon.vrshiftu.v8i8(<8 x i8> %a, <8 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <8 x i8> [[VRSHR_N]]
uint8x8_t test_vrshr_n_u8(uint8x8_t a) {
  return vrshr_n_u8(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VRSHR_N1:%.*]] = call <4 x i16> @llvm.arm.neon.vrshiftu.v4i16(<4 x i16> [[VRSHR_N]], <4 x i16> <i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <4 x i16> [[VRSHR_N1]]
uint16x4_t test_vrshr_n_u16(uint16x4_t a) {
  return vrshr_n_u16(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VRSHR_N1:%.*]] = call <2 x i32> @llvm.arm.neon.vrshiftu.v2i32(<2 x i32> [[VRSHR_N]], <2 x i32> <i32 -1, i32 -1>)
// CHECK:   ret <2 x i32> [[VRSHR_N1]]
uint32x2_t test_vrshr_n_u32(uint32x2_t a) {
  return vrshr_n_u32(a, 1);
}

// CHECK-LABEL: @test_vrshr_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VRSHR_N1:%.*]] = call <1 x i64> @llvm.arm.neon.vrshiftu.v1i64(<1 x i64> [[VRSHR_N]], <1 x i64> <i64 -1>)
// CHECK:   ret <1 x i64> [[VRSHR_N1]]
uint64x1_t test_vrshr_n_u64(uint64x1_t a) {
  return vrshr_n_u64(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_s8(
// CHECK:   [[VRSHR_N:%.*]] = call <16 x i8> @llvm.arm.neon.vrshifts.v16i8(<16 x i8> %a, <16 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <16 x i8> [[VRSHR_N]]
int8x16_t test_vrshrq_n_s8(int8x16_t a) {
  return vrshrq_n_s8(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VRSHR_N1:%.*]] = call <8 x i16> @llvm.arm.neon.vrshifts.v8i16(<8 x i16> [[VRSHR_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i16> [[VRSHR_N1]]
int16x8_t test_vrshrq_n_s16(int16x8_t a) {
  return vrshrq_n_s16(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VRSHR_N1:%.*]] = call <4 x i32> @llvm.arm.neon.vrshifts.v4i32(<4 x i32> [[VRSHR_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i32> [[VRSHR_N1]]
int32x4_t test_vrshrq_n_s32(int32x4_t a) {
  return vrshrq_n_s32(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VRSHR_N1:%.*]] = call <2 x i64> @llvm.arm.neon.vrshifts.v2i64(<2 x i64> [[VRSHR_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i64> [[VRSHR_N1]]
int64x2_t test_vrshrq_n_s64(int64x2_t a) {
  return vrshrq_n_s64(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_u8(
// CHECK:   [[VRSHR_N:%.*]] = call <16 x i8> @llvm.arm.neon.vrshiftu.v16i8(<16 x i8> %a, <16 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <16 x i8> [[VRSHR_N]]
uint8x16_t test_vrshrq_n_u8(uint8x16_t a) {
  return vrshrq_n_u8(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VRSHR_N1:%.*]] = call <8 x i16> @llvm.arm.neon.vrshiftu.v8i16(<8 x i16> [[VRSHR_N]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i16> [[VRSHR_N1]]
uint16x8_t test_vrshrq_n_u16(uint16x8_t a) {
  return vrshrq_n_u16(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VRSHR_N1:%.*]] = call <4 x i32> @llvm.arm.neon.vrshiftu.v4i32(<4 x i32> [[VRSHR_N]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i32> [[VRSHR_N1]]
uint32x4_t test_vrshrq_n_u32(uint32x4_t a) {
  return vrshrq_n_u32(a, 1);
}

// CHECK-LABEL: @test_vrshrq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[VRSHR_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VRSHR_N1:%.*]] = call <2 x i64> @llvm.arm.neon.vrshiftu.v2i64(<2 x i64> [[VRSHR_N]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i64> [[VRSHR_N1]]
uint64x2_t test_vrshrq_n_u64(uint64x2_t a) {
  return vrshrq_n_u64(a, 1);
}

// CHECK-LABEL: @test_vrsqrte_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[VRSQRTE_V1_I:%.*]] = call <2 x float> @llvm.arm.neon.vrsqrte.v2f32(<2 x float> %a)
// CHECK:   ret <2 x float> [[VRSQRTE_V1_I]]
float32x2_t test_vrsqrte_f32(float32x2_t a) {
  return vrsqrte_f32(a);
}

// CHECK-LABEL: @test_vrsqrte_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VRSQRTE_V1_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrsqrte.v2i32(<2 x i32> %a)
// CHECK:   ret <2 x i32> [[VRSQRTE_V1_I]]
uint32x2_t test_vrsqrte_u32(uint32x2_t a) {
  return vrsqrte_u32(a);
}

// CHECK-LABEL: @test_vrsqrteq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[VRSQRTEQ_V1_I:%.*]] = call <4 x float> @llvm.arm.neon.vrsqrte.v4f32(<4 x float> %a)
// CHECK:   ret <4 x float> [[VRSQRTEQ_V1_I]]
float32x4_t test_vrsqrteq_f32(float32x4_t a) {
  return vrsqrteq_f32(a);
}

// CHECK-LABEL: @test_vrsqrteq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[VRSQRTEQ_V1_I:%.*]] = call <4 x i32> @llvm.arm.neon.vrsqrte.v4i32(<4 x i32> %a)
// CHECK:   ret <4 x i32> [[VRSQRTEQ_V1_I]]
uint32x4_t test_vrsqrteq_u32(uint32x4_t a) {
  return vrsqrteq_u32(a);
}

// CHECK-LABEL: @test_vrsqrts_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VRSQRTS_V2_I:%.*]] = call <2 x float> @llvm.arm.neon.vrsqrts.v2f32(<2 x float> %a, <2 x float> %b)
// CHECK:   [[VRSQRTS_V3_I:%.*]] = bitcast <2 x float> [[VRSQRTS_V2_I]] to <8 x i8>
// CHECK:   ret <2 x float> [[VRSQRTS_V2_I]]
float32x2_t test_vrsqrts_f32(float32x2_t a, float32x2_t b) {
  return vrsqrts_f32(a, b);
}

// CHECK-LABEL: @test_vrsqrtsq_f32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VRSQRTSQ_V2_I:%.*]] = call <4 x float> @llvm.arm.neon.vrsqrts.v4f32(<4 x float> %a, <4 x float> %b)
// CHECK:   [[VRSQRTSQ_V3_I:%.*]] = bitcast <4 x float> [[VRSQRTSQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x float> [[VRSQRTSQ_V2_I]]
float32x4_t test_vrsqrtsq_f32(float32x4_t a, float32x4_t b) {
  return vrsqrtsq_f32(a, b);
}

// CHECK-LABEL: @test_vrsra_n_s8(
// CHECK:   [[TMP0:%.*]] = call <8 x i8> @llvm.arm.neon.vrshifts.v8i8(<8 x i8> %b, <8 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <8 x i8> %a, [[TMP0]]
// CHECK:   ret <8 x i8> [[VRSRA_N]]
int8x8_t test_vrsra_n_s8(int8x8_t a, int8x8_t b) {
  return vrsra_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vrsra_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP4:%.*]] = call <4 x i16> @llvm.arm.neon.vrshifts.v4i16(<4 x i16> [[TMP3]], <4 x i16> <i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <4 x i16> [[TMP2]], [[TMP4]]
// CHECK:   ret <4 x i16> [[VRSRA_N]]
int16x4_t test_vrsra_n_s16(int16x4_t a, int16x4_t b) {
  return vrsra_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vrsra_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[TMP4:%.*]] = call <2 x i32> @llvm.arm.neon.vrshifts.v2i32(<2 x i32> [[TMP3]], <2 x i32> <i32 -1, i32 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <2 x i32> [[TMP2]], [[TMP4]]
// CHECK:   ret <2 x i32> [[VRSRA_N]]
int32x2_t test_vrsra_n_s32(int32x2_t a, int32x2_t b) {
  return vrsra_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vrsra_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[TMP4:%.*]] = call <1 x i64> @llvm.arm.neon.vrshifts.v1i64(<1 x i64> [[TMP3]], <1 x i64> <i64 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <1 x i64> [[TMP2]], [[TMP4]]
// CHECK:   ret <1 x i64> [[VRSRA_N]]
int64x1_t test_vrsra_n_s64(int64x1_t a, int64x1_t b) {
  return vrsra_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vrsra_n_u8(
// CHECK:   [[TMP0:%.*]] = call <8 x i8> @llvm.arm.neon.vrshiftu.v8i8(<8 x i8> %b, <8 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <8 x i8> %a, [[TMP0]]
// CHECK:   ret <8 x i8> [[VRSRA_N]]
uint8x8_t test_vrsra_n_u8(uint8x8_t a, uint8x8_t b) {
  return vrsra_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vrsra_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP4:%.*]] = call <4 x i16> @llvm.arm.neon.vrshiftu.v4i16(<4 x i16> [[TMP3]], <4 x i16> <i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <4 x i16> [[TMP2]], [[TMP4]]
// CHECK:   ret <4 x i16> [[VRSRA_N]]
uint16x4_t test_vrsra_n_u16(uint16x4_t a, uint16x4_t b) {
  return vrsra_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vrsra_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[TMP4:%.*]] = call <2 x i32> @llvm.arm.neon.vrshiftu.v2i32(<2 x i32> [[TMP3]], <2 x i32> <i32 -1, i32 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <2 x i32> [[TMP2]], [[TMP4]]
// CHECK:   ret <2 x i32> [[VRSRA_N]]
uint32x2_t test_vrsra_n_u32(uint32x2_t a, uint32x2_t b) {
  return vrsra_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vrsra_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[TMP4:%.*]] = call <1 x i64> @llvm.arm.neon.vrshiftu.v1i64(<1 x i64> [[TMP3]], <1 x i64> <i64 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <1 x i64> [[TMP2]], [[TMP4]]
// CHECK:   ret <1 x i64> [[VRSRA_N]]
uint64x1_t test_vrsra_n_u64(uint64x1_t a, uint64x1_t b) {
  return vrsra_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_s8(
// CHECK:   [[TMP0:%.*]] = call <16 x i8> @llvm.arm.neon.vrshifts.v16i8(<16 x i8> %b, <16 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <16 x i8> %a, [[TMP0]]
// CHECK:   ret <16 x i8> [[VRSRA_N]]
int8x16_t test_vrsraq_n_s8(int8x16_t a, int8x16_t b) {
  return vrsraq_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP4:%.*]] = call <8 x i16> @llvm.arm.neon.vrshifts.v8i16(<8 x i16> [[TMP3]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <8 x i16> [[TMP2]], [[TMP4]]
// CHECK:   ret <8 x i16> [[VRSRA_N]]
int16x8_t test_vrsraq_n_s16(int16x8_t a, int16x8_t b) {
  return vrsraq_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[TMP4:%.*]] = call <4 x i32> @llvm.arm.neon.vrshifts.v4i32(<4 x i32> [[TMP3]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <4 x i32> [[TMP2]], [[TMP4]]
// CHECK:   ret <4 x i32> [[VRSRA_N]]
int32x4_t test_vrsraq_n_s32(int32x4_t a, int32x4_t b) {
  return vrsraq_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[TMP4:%.*]] = call <2 x i64> @llvm.arm.neon.vrshifts.v2i64(<2 x i64> [[TMP3]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <2 x i64> [[TMP2]], [[TMP4]]
// CHECK:   ret <2 x i64> [[VRSRA_N]]
int64x2_t test_vrsraq_n_s64(int64x2_t a, int64x2_t b) {
  return vrsraq_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_u8(
// CHECK:   [[TMP0:%.*]] = call <16 x i8> @llvm.arm.neon.vrshiftu.v16i8(<16 x i8> %b, <16 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <16 x i8> %a, [[TMP0]]
// CHECK:   ret <16 x i8> [[VRSRA_N]]
uint8x16_t test_vrsraq_n_u8(uint8x16_t a, uint8x16_t b) {
  return vrsraq_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP4:%.*]] = call <8 x i16> @llvm.arm.neon.vrshiftu.v8i16(<8 x i16> [[TMP3]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <8 x i16> [[TMP2]], [[TMP4]]
// CHECK:   ret <8 x i16> [[VRSRA_N]]
uint16x8_t test_vrsraq_n_u16(uint16x8_t a, uint16x8_t b) {
  return vrsraq_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[TMP4:%.*]] = call <4 x i32> @llvm.arm.neon.vrshiftu.v4i32(<4 x i32> [[TMP3]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <4 x i32> [[TMP2]], [[TMP4]]
// CHECK:   ret <4 x i32> [[VRSRA_N]]
uint32x4_t test_vrsraq_n_u32(uint32x4_t a, uint32x4_t b) {
  return vrsraq_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vrsraq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[TMP4:%.*]] = call <2 x i64> @llvm.arm.neon.vrshiftu.v2i64(<2 x i64> [[TMP3]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   [[VRSRA_N:%.*]] = add <2 x i64> [[TMP2]], [[TMP4]]
// CHECK:   ret <2 x i64> [[VRSRA_N]]
uint64x2_t test_vrsraq_n_u64(uint64x2_t a, uint64x2_t b) {
  return vrsraq_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vrsubhn_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRSUBHN_V2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vrsubhn.v8i8(<8 x i16> %a, <8 x i16> %b)
// CHECK:   ret <8 x i8> [[VRSUBHN_V2_I]]
int8x8_t test_vrsubhn_s16(int16x8_t a, int16x8_t b) {
  return vrsubhn_s16(a, b);
}

// CHECK-LABEL: @test_vrsubhn_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRSUBHN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vrsubhn.v4i16(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRSUBHN_V3_I:%.*]] = bitcast <4 x i16> [[VRSUBHN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRSUBHN_V2_I]]
int16x4_t test_vrsubhn_s32(int32x4_t a, int32x4_t b) {
  return vrsubhn_s32(a, b);
}

// CHECK-LABEL: @test_vrsubhn_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VRSUBHN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrsubhn.v2i32(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VRSUBHN_V3_I:%.*]] = bitcast <2 x i32> [[VRSUBHN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRSUBHN_V2_I]]
int32x2_t test_vrsubhn_s64(int64x2_t a, int64x2_t b) {
  return vrsubhn_s64(a, b);
}

// CHECK-LABEL: @test_vrsubhn_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VRSUBHN_V2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vrsubhn.v8i8(<8 x i16> %a, <8 x i16> %b)
// CHECK:   ret <8 x i8> [[VRSUBHN_V2_I]]
uint8x8_t test_vrsubhn_u16(uint16x8_t a, uint16x8_t b) {
  return vrsubhn_u16(a, b);
}

// CHECK-LABEL: @test_vrsubhn_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VRSUBHN_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vrsubhn.v4i16(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VRSUBHN_V3_I:%.*]] = bitcast <4 x i16> [[VRSUBHN_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VRSUBHN_V2_I]]
uint16x4_t test_vrsubhn_u32(uint32x4_t a, uint32x4_t b) {
  return vrsubhn_u32(a, b);
}

// CHECK-LABEL: @test_vrsubhn_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VRSUBHN_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vrsubhn.v2i32(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VRSUBHN_V3_I:%.*]] = bitcast <2 x i32> [[VRSUBHN_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VRSUBHN_V2_I]]
uint32x2_t test_vrsubhn_u64(uint64x2_t a, uint64x2_t b) {
  return vrsubhn_u64(a, b);
}

// CHECK-LABEL: @test_vset_lane_u8(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <8 x i8> %b, i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VSET_LANE]]
uint8x8_t test_vset_lane_u8(uint8_t a, uint8x8_t b) {
  return vset_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vset_lane_u16(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <4 x i16> %b, i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VSET_LANE]]
uint16x4_t test_vset_lane_u16(uint16_t a, uint16x4_t b) {
  return vset_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vset_lane_u32(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <2 x i32> %b, i32 %a, i32 1
// CHECK:   ret <2 x i32> [[VSET_LANE]]
uint32x2_t test_vset_lane_u32(uint32_t a, uint32x2_t b) {
  return vset_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vset_lane_s8(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <8 x i8> %b, i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VSET_LANE]]
int8x8_t test_vset_lane_s8(int8_t a, int8x8_t b) {
  return vset_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vset_lane_s16(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <4 x i16> %b, i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VSET_LANE]]
int16x4_t test_vset_lane_s16(int16_t a, int16x4_t b) {
  return vset_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vset_lane_s32(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <2 x i32> %b, i32 %a, i32 1
// CHECK:   ret <2 x i32> [[VSET_LANE]]
int32x2_t test_vset_lane_s32(int32_t a, int32x2_t b) {
  return vset_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vset_lane_p8(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <8 x i8> %b, i8 %a, i32 7
// CHECK:   ret <8 x i8> [[VSET_LANE]]
poly8x8_t test_vset_lane_p8(poly8_t a, poly8x8_t b) {
  return vset_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vset_lane_p16(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <4 x i16> %b, i16 %a, i32 3
// CHECK:   ret <4 x i16> [[VSET_LANE]]
poly16x4_t test_vset_lane_p16(poly16_t a, poly16x4_t b) {
  return vset_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vset_lane_f32(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <2 x float> %b, float %a, i32 1
// CHECK:   ret <2 x float> [[VSET_LANE]]
float32x2_t test_vset_lane_f32(float32_t a, float32x2_t b) {
  return vset_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vset_lane_f16(
// CHECK:   [[__REINT_246:%.*]] = alloca half, align 2
// CHECK:   [[__REINT1_246:%.*]] = alloca <4 x half>, align 8
// CHECK:   [[__REINT2_246:%.*]] = alloca <4 x i16>, align 8
// CHECK:   [[TMP0:%.*]] = load half, ptr %a, align 2
// CHECK:   store half [[TMP0]], ptr [[__REINT_246]], align 2
// CHECK:   store <4 x half> %b, ptr [[__REINT1_246]], align 8
// CHECK:   [[TMP2:%.*]] = load i16, ptr [[__REINT_246]], align 2
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[__REINT1_246]], align 8
// CHECK:   [[VSET_LANE:%.*]] = insertelement <4 x i16> [[TMP4]], i16 [[TMP2]], i32 1
// CHECK:   store <4 x i16> [[VSET_LANE]], ptr [[__REINT2_246]], align 8
// CHECK:   [[TMP8:%.*]] = load <4 x half>, ptr [[__REINT2_246]], align 8
// CHECK:   ret <4 x half> [[TMP8]]
float16x4_t test_vset_lane_f16(float16_t *a, float16x4_t b) {
  return vset_lane_f16(*a, b, 1);
}

// CHECK-LABEL: @test_vsetq_lane_u8(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <16 x i8> %b, i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VSET_LANE]]
uint8x16_t test_vsetq_lane_u8(uint8_t a, uint8x16_t b) {
  return vsetq_lane_u8(a, b, 15);
}

// CHECK-LABEL: @test_vsetq_lane_u16(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <8 x i16> %b, i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VSET_LANE]]
uint16x8_t test_vsetq_lane_u16(uint16_t a, uint16x8_t b) {
  return vsetq_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vsetq_lane_u32(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <4 x i32> %b, i32 %a, i32 3
// CHECK:   ret <4 x i32> [[VSET_LANE]]
uint32x4_t test_vsetq_lane_u32(uint32_t a, uint32x4_t b) {
  return vsetq_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vsetq_lane_s8(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <16 x i8> %b, i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VSET_LANE]]
int8x16_t test_vsetq_lane_s8(int8_t a, int8x16_t b) {
  return vsetq_lane_s8(a, b, 15);
}

// CHECK-LABEL: @test_vsetq_lane_s16(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <8 x i16> %b, i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VSET_LANE]]
int16x8_t test_vsetq_lane_s16(int16_t a, int16x8_t b) {
  return vsetq_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vsetq_lane_s32(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <4 x i32> %b, i32 %a, i32 3
// CHECK:   ret <4 x i32> [[VSET_LANE]]
int32x4_t test_vsetq_lane_s32(int32_t a, int32x4_t b) {
  return vsetq_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vsetq_lane_p8(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <16 x i8> %b, i8 %a, i32 15
// CHECK:   ret <16 x i8> [[VSET_LANE]]
poly8x16_t test_vsetq_lane_p8(poly8_t a, poly8x16_t b) {
  return vsetq_lane_p8(a, b, 15);
}

// CHECK-LABEL: @test_vsetq_lane_p16(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <8 x i16> %b, i16 %a, i32 7
// CHECK:   ret <8 x i16> [[VSET_LANE]]
poly16x8_t test_vsetq_lane_p16(poly16_t a, poly16x8_t b) {
  return vsetq_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vsetq_lane_f32(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <4 x float> %b, float %a, i32 3
// CHECK:   ret <4 x float> [[VSET_LANE]]
float32x4_t test_vsetq_lane_f32(float32_t a, float32x4_t b) {
  return vsetq_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vsetq_lane_f16(
// CHECK:   [[__REINT_248:%.*]] = alloca half, align 2
// CHECK:   [[__REINT1_248:%.*]] = alloca <8 x half>, align 16
// CHECK:   [[__REINT2_248:%.*]] = alloca <8 x i16>, align 16
// CHECK:   [[TMP0:%.*]] = load half, ptr %a, align 2
// CHECK:   store half [[TMP0]], ptr [[__REINT_248]], align 2
// CHECK:   store <8 x half> %b, ptr [[__REINT1_248]], align 16
// CHECK:   [[TMP2:%.*]] = load i16, ptr [[__REINT_248]], align 2
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[__REINT1_248]], align 16
// CHECK:   [[VSET_LANE:%.*]] = insertelement <8 x i16> [[TMP4]], i16 [[TMP2]], i32 3
// CHECK:   store <8 x i16> [[VSET_LANE]], ptr [[__REINT2_248]], align 16
// CHECK:   [[TMP8:%.*]] = load <8 x half>, ptr [[__REINT2_248]], align 16
// CHECK:   ret <8 x half> [[TMP8]]
float16x8_t test_vsetq_lane_f16(float16_t *a, float16x8_t b) {
  return vsetq_lane_f16(*a, b, 3);
}

// CHECK-LABEL: @test_vset_lane_s64(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <1 x i64> %b, i64 %a, i32 0
// CHECK:   ret <1 x i64> [[VSET_LANE]]
int64x1_t test_vset_lane_s64(int64_t a, int64x1_t b) {
  return vset_lane_s64(a, b, 0);
}

// CHECK-LABEL: @test_vset_lane_u64(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <1 x i64> %b, i64 %a, i32 0
// CHECK:   ret <1 x i64> [[VSET_LANE]]
uint64x1_t test_vset_lane_u64(uint64_t a, uint64x1_t b) {
  return vset_lane_u64(a, b, 0);
}

// CHECK-LABEL: @test_vsetq_lane_s64(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <2 x i64> %b, i64 %a, i32 1
// CHECK:   ret <2 x i64> [[VSET_LANE]]
int64x2_t test_vsetq_lane_s64(int64_t a, int64x2_t b) {
  return vsetq_lane_s64(a, b, 1);
}

// CHECK-LABEL: @test_vsetq_lane_u64(
// CHECK:   [[VSET_LANE:%.*]] = insertelement <2 x i64> %b, i64 %a, i32 1
// CHECK:   ret <2 x i64> [[VSET_LANE]]
uint64x2_t test_vsetq_lane_u64(uint64_t a, uint64x2_t b) {
  return vsetq_lane_u64(a, b, 1);
}

// CHECK-LABEL: @test_vshl_s8(
// CHECK:   [[VSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vshifts.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VSHL_V_I]]
int8x8_t test_vshl_s8(int8x8_t a, int8x8_t b) {
  return vshl_s8(a, b);
}

// CHECK-LABEL: @test_vshl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vshifts.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VSHL_V3_I:%.*]] = bitcast <4 x i16> [[VSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VSHL_V2_I]]
int16x4_t test_vshl_s16(int16x4_t a, int16x4_t b) {
  return vshl_s16(a, b);
}

// CHECK-LABEL: @test_vshl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vshifts.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VSHL_V3_I:%.*]] = bitcast <2 x i32> [[VSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VSHL_V2_I]]
int32x2_t test_vshl_s32(int32x2_t a, int32x2_t b) {
  return vshl_s32(a, b);
}

// CHECK-LABEL: @test_vshl_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vshifts.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VSHL_V3_I:%.*]] = bitcast <1 x i64> [[VSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VSHL_V2_I]]
int64x1_t test_vshl_s64(int64x1_t a, int64x1_t b) {
  return vshl_s64(a, b);
}

// CHECK-LABEL: @test_vshl_u8(
// CHECK:   [[VSHL_V_I:%.*]] = call <8 x i8> @llvm.arm.neon.vshiftu.v8i8(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VSHL_V_I]]
uint8x8_t test_vshl_u8(uint8x8_t a, int8x8_t b) {
  return vshl_u8(a, b);
}

// CHECK-LABEL: @test_vshl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSHL_V2_I:%.*]] = call <4 x i16> @llvm.arm.neon.vshiftu.v4i16(<4 x i16> %a, <4 x i16> %b)
// CHECK:   [[VSHL_V3_I:%.*]] = bitcast <4 x i16> [[VSHL_V2_I]] to <8 x i8>
// CHECK:   ret <4 x i16> [[VSHL_V2_I]]
uint16x4_t test_vshl_u16(uint16x4_t a, int16x4_t b) {
  return vshl_u16(a, b);
}

// CHECK-LABEL: @test_vshl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VSHL_V2_I:%.*]] = call <2 x i32> @llvm.arm.neon.vshiftu.v2i32(<2 x i32> %a, <2 x i32> %b)
// CHECK:   [[VSHL_V3_I:%.*]] = bitcast <2 x i32> [[VSHL_V2_I]] to <8 x i8>
// CHECK:   ret <2 x i32> [[VSHL_V2_I]]
uint32x2_t test_vshl_u32(uint32x2_t a, int32x2_t b) {
  return vshl_u32(a, b);
}

// CHECK-LABEL: @test_vshl_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VSHL_V2_I:%.*]] = call <1 x i64> @llvm.arm.neon.vshiftu.v1i64(<1 x i64> %a, <1 x i64> %b)
// CHECK:   [[VSHL_V3_I:%.*]] = bitcast <1 x i64> [[VSHL_V2_I]] to <8 x i8>
// CHECK:   ret <1 x i64> [[VSHL_V2_I]]
uint64x1_t test_vshl_u64(uint64x1_t a, int64x1_t b) {
  return vshl_u64(a, b);
}

// CHECK-LABEL: @test_vshlq_s8(
// CHECK:   [[VSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vshifts.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VSHLQ_V_I]]
int8x16_t test_vshlq_s8(int8x16_t a, int8x16_t b) {
  return vshlq_s8(a, b);
}

// CHECK-LABEL: @test_vshlq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vshifts.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VSHLQ_V2_I]]
int16x8_t test_vshlq_s16(int16x8_t a, int16x8_t b) {
  return vshlq_s16(a, b);
}

// CHECK-LABEL: @test_vshlq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vshifts.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VSHLQ_V2_I]]
int32x4_t test_vshlq_s32(int32x4_t a, int32x4_t b) {
  return vshlq_s32(a, b);
}

// CHECK-LABEL: @test_vshlq_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vshifts.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VSHLQ_V2_I]]
int64x2_t test_vshlq_s64(int64x2_t a, int64x2_t b) {
  return vshlq_s64(a, b);
}

// CHECK-LABEL: @test_vshlq_u8(
// CHECK:   [[VSHLQ_V_I:%.*]] = call <16 x i8> @llvm.arm.neon.vshiftu.v16i8(<16 x i8> %a, <16 x i8> %b)
// CHECK:   ret <16 x i8> [[VSHLQ_V_I]]
uint8x16_t test_vshlq_u8(uint8x16_t a, int8x16_t b) {
  return vshlq_u8(a, b);
}

// CHECK-LABEL: @test_vshlq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSHLQ_V2_I:%.*]] = call <8 x i16> @llvm.arm.neon.vshiftu.v8i16(<8 x i16> %a, <8 x i16> %b)
// CHECK:   [[VSHLQ_V3_I:%.*]] = bitcast <8 x i16> [[VSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <8 x i16> [[VSHLQ_V2_I]]
uint16x8_t test_vshlq_u16(uint16x8_t a, int16x8_t b) {
  return vshlq_u16(a, b);
}

// CHECK-LABEL: @test_vshlq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSHLQ_V2_I:%.*]] = call <4 x i32> @llvm.arm.neon.vshiftu.v4i32(<4 x i32> %a, <4 x i32> %b)
// CHECK:   [[VSHLQ_V3_I:%.*]] = bitcast <4 x i32> [[VSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <4 x i32> [[VSHLQ_V2_I]]
uint32x4_t test_vshlq_u32(uint32x4_t a, int32x4_t b) {
  return vshlq_u32(a, b);
}

// CHECK-LABEL: @test_vshlq_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSHLQ_V2_I:%.*]] = call <2 x i64> @llvm.arm.neon.vshiftu.v2i64(<2 x i64> %a, <2 x i64> %b)
// CHECK:   [[VSHLQ_V3_I:%.*]] = bitcast <2 x i64> [[VSHLQ_V2_I]] to <16 x i8>
// CHECK:   ret <2 x i64> [[VSHLQ_V2_I]]
uint64x2_t test_vshlq_u64(uint64x2_t a, int64x2_t b) {
  return vshlq_u64(a, b);
}

// CHECK-LABEL: @test_vshll_n_s8(
// CHECK:   [[TMP0:%.*]] = sext <8 x i8> %a to <8 x i16>
// CHECK:   [[VSHLL_N:%.*]] = shl <8 x i16> [[TMP0]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <8 x i16> [[VSHLL_N]]
int16x8_t test_vshll_n_s8(int8x8_t a) {
  return vshll_n_s8(a, 1);
}

// CHECK-LABEL: @test_vshll_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP2:%.*]] = sext <4 x i16> [[TMP1]] to <4 x i32>
// CHECK:   [[VSHLL_N:%.*]] = shl <4 x i32> [[TMP2]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[VSHLL_N]]
int32x4_t test_vshll_n_s16(int16x4_t a) {
  return vshll_n_s16(a, 1);
}

// CHECK-LABEL: @test_vshll_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP2:%.*]] = sext <2 x i32> [[TMP1]] to <2 x i64>
// CHECK:   [[VSHLL_N:%.*]] = shl <2 x i64> [[TMP2]], <i64 1, i64 1>
// CHECK:   ret <2 x i64> [[VSHLL_N]]
int64x2_t test_vshll_n_s32(int32x2_t a) {
  return vshll_n_s32(a, 1);
}

// CHECK-LABEL: @test_vshll_n_u8(
// CHECK:   [[TMP0:%.*]] = zext <8 x i8> %a to <8 x i16>
// CHECK:   [[VSHLL_N:%.*]] = shl <8 x i16> [[TMP0]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <8 x i16> [[VSHLL_N]]
uint16x8_t test_vshll_n_u8(uint8x8_t a) {
  return vshll_n_u8(a, 1);
}

// CHECK-LABEL: @test_vshll_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP2:%.*]] = zext <4 x i16> [[TMP1]] to <4 x i32>
// CHECK:   [[VSHLL_N:%.*]] = shl <4 x i32> [[TMP2]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[VSHLL_N]]
uint32x4_t test_vshll_n_u16(uint16x4_t a) {
  return vshll_n_u16(a, 1);
}

// CHECK-LABEL: @test_vshll_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP2:%.*]] = zext <2 x i32> [[TMP1]] to <2 x i64>
// CHECK:   [[VSHLL_N:%.*]] = shl <2 x i64> [[TMP2]], <i64 1, i64 1>
// CHECK:   ret <2 x i64> [[VSHLL_N]]
uint64x2_t test_vshll_n_u32(uint32x2_t a) {
  return vshll_n_u32(a, 1);
}

// CHECK-LABEL: @test_vshl_n_s8(
// CHECK:   [[VSHL_N:%.*]] = shl <8 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <8 x i8> [[VSHL_N]]
int8x8_t test_vshl_n_s8(int8x8_t a) {
  return vshl_n_s8(a, 1);
}

// CHECK-LABEL: @test_vshl_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSHL_N:%.*]] = shl <4 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <4 x i16> [[VSHL_N]]
int16x4_t test_vshl_n_s16(int16x4_t a) {
  return vshl_n_s16(a, 1);
}

// CHECK-LABEL: @test_vshl_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSHL_N:%.*]] = shl <2 x i32> [[TMP1]], <i32 1, i32 1>
// CHECK:   ret <2 x i32> [[VSHL_N]]
int32x2_t test_vshl_n_s32(int32x2_t a) {
  return vshl_n_s32(a, 1);
}

// CHECK-LABEL: @test_vshl_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSHL_N:%.*]] = shl <1 x i64> [[TMP1]], <i64 1>
// CHECK:   ret <1 x i64> [[VSHL_N]]
int64x1_t test_vshl_n_s64(int64x1_t a) {
  return vshl_n_s64(a, 1);
}

// CHECK-LABEL: @test_vshl_n_u8(
// CHECK:   [[VSHL_N:%.*]] = shl <8 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <8 x i8> [[VSHL_N]]
uint8x8_t test_vshl_n_u8(uint8x8_t a) {
  return vshl_n_u8(a, 1);
}

// CHECK-LABEL: @test_vshl_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSHL_N:%.*]] = shl <4 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <4 x i16> [[VSHL_N]]
uint16x4_t test_vshl_n_u16(uint16x4_t a) {
  return vshl_n_u16(a, 1);
}

// CHECK-LABEL: @test_vshl_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSHL_N:%.*]] = shl <2 x i32> [[TMP1]], <i32 1, i32 1>
// CHECK:   ret <2 x i32> [[VSHL_N]]
uint32x2_t test_vshl_n_u32(uint32x2_t a) {
  return vshl_n_u32(a, 1);
}

// CHECK-LABEL: @test_vshl_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSHL_N:%.*]] = shl <1 x i64> [[TMP1]], <i64 1>
// CHECK:   ret <1 x i64> [[VSHL_N]]
uint64x1_t test_vshl_n_u64(uint64x1_t a) {
  return vshl_n_u64(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_s8(
// CHECK:   [[VSHL_N:%.*]] = shl <16 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <16 x i8> [[VSHL_N]]
int8x16_t test_vshlq_n_s8(int8x16_t a) {
  return vshlq_n_s8(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSHL_N:%.*]] = shl <8 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <8 x i16> [[VSHL_N]]
int16x8_t test_vshlq_n_s16(int16x8_t a) {
  return vshlq_n_s16(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSHL_N:%.*]] = shl <4 x i32> [[TMP1]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[VSHL_N]]
int32x4_t test_vshlq_n_s32(int32x4_t a) {
  return vshlq_n_s32(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSHL_N:%.*]] = shl <2 x i64> [[TMP1]], <i64 1, i64 1>
// CHECK:   ret <2 x i64> [[VSHL_N]]
int64x2_t test_vshlq_n_s64(int64x2_t a) {
  return vshlq_n_s64(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_u8(
// CHECK:   [[VSHL_N:%.*]] = shl <16 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <16 x i8> [[VSHL_N]]
uint8x16_t test_vshlq_n_u8(uint8x16_t a) {
  return vshlq_n_u8(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSHL_N:%.*]] = shl <8 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <8 x i16> [[VSHL_N]]
uint16x8_t test_vshlq_n_u16(uint16x8_t a) {
  return vshlq_n_u16(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSHL_N:%.*]] = shl <4 x i32> [[TMP1]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[VSHL_N]]
uint32x4_t test_vshlq_n_u32(uint32x4_t a) {
  return vshlq_n_u32(a, 1);
}

// CHECK-LABEL: @test_vshlq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSHL_N:%.*]] = shl <2 x i64> [[TMP1]], <i64 1, i64 1>
// CHECK:   ret <2 x i64> [[VSHL_N]]
uint64x2_t test_vshlq_n_u64(uint64x2_t a) {
  return vshlq_n_u64(a, 1);
}

// CHECK-LABEL: @test_vshrn_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP2:%.*]] = ashr <8 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   [[VSHRN_N:%.*]] = trunc <8 x i16> [[TMP2]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VSHRN_N]]
int8x8_t test_vshrn_n_s16(int16x8_t a) {
  return vshrn_n_s16(a, 1);
}

// CHECK-LABEL: @test_vshrn_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP2:%.*]] = ashr <4 x i32> [[TMP1]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[VSHRN_N:%.*]] = trunc <4 x i32> [[TMP2]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VSHRN_N]]
int16x4_t test_vshrn_n_s32(int32x4_t a) {
  return vshrn_n_s32(a, 1);
}

// CHECK-LABEL: @test_vshrn_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP2:%.*]] = ashr <2 x i64> [[TMP1]], <i64 1, i64 1>
// CHECK:   [[VSHRN_N:%.*]] = trunc <2 x i64> [[TMP2]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VSHRN_N]]
int32x2_t test_vshrn_n_s64(int64x2_t a) {
  return vshrn_n_s64(a, 1);
}

// CHECK-LABEL: @test_vshrn_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP2:%.*]] = lshr <8 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   [[VSHRN_N:%.*]] = trunc <8 x i16> [[TMP2]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VSHRN_N]]
uint8x8_t test_vshrn_n_u16(uint16x8_t a) {
  return vshrn_n_u16(a, 1);
}

// CHECK-LABEL: @test_vshrn_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP2:%.*]] = lshr <4 x i32> [[TMP1]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[VSHRN_N:%.*]] = trunc <4 x i32> [[TMP2]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VSHRN_N]]
uint16x4_t test_vshrn_n_u32(uint32x4_t a) {
  return vshrn_n_u32(a, 1);
}

// CHECK-LABEL: @test_vshrn_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP2:%.*]] = lshr <2 x i64> [[TMP1]], <i64 1, i64 1>
// CHECK:   [[VSHRN_N:%.*]] = trunc <2 x i64> [[TMP2]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VSHRN_N]]
uint32x2_t test_vshrn_n_u64(uint64x2_t a) {
  return vshrn_n_u64(a, 1);
}

// CHECK-LABEL: @test_vshr_n_s8(
// CHECK:   [[VSHR_N:%.*]] = ashr <8 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <8 x i8> [[VSHR_N]]
int8x8_t test_vshr_n_s8(int8x8_t a) {
  return vshr_n_s8(a, 1);
}

// CHECK-LABEL: @test_vshr_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSHR_N:%.*]] = ashr <4 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <4 x i16> [[VSHR_N]]
int16x4_t test_vshr_n_s16(int16x4_t a) {
  return vshr_n_s16(a, 1);
}

// CHECK-LABEL: @test_vshr_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSHR_N:%.*]] = ashr <2 x i32> [[TMP1]], <i32 1, i32 1>
// CHECK:   ret <2 x i32> [[VSHR_N]]
int32x2_t test_vshr_n_s32(int32x2_t a) {
  return vshr_n_s32(a, 1);
}

// CHECK-LABEL: @test_vshr_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSHR_N:%.*]] = ashr <1 x i64> [[TMP1]], <i64 1>
// CHECK:   ret <1 x i64> [[VSHR_N]]
int64x1_t test_vshr_n_s64(int64x1_t a) {
  return vshr_n_s64(a, 1);
}

// CHECK-LABEL: @test_vshr_n_u8(
// CHECK:   [[VSHR_N:%.*]] = lshr <8 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <8 x i8> [[VSHR_N]]
uint8x8_t test_vshr_n_u8(uint8x8_t a) {
  return vshr_n_u8(a, 1);
}

// CHECK-LABEL: @test_vshr_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSHR_N:%.*]] = lshr <4 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <4 x i16> [[VSHR_N]]
uint16x4_t test_vshr_n_u16(uint16x4_t a) {
  return vshr_n_u16(a, 1);
}

// CHECK-LABEL: @test_vshr_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSHR_N:%.*]] = lshr <2 x i32> [[TMP1]], <i32 1, i32 1>
// CHECK:   ret <2 x i32> [[VSHR_N]]
uint32x2_t test_vshr_n_u32(uint32x2_t a) {
  return vshr_n_u32(a, 1);
}

// CHECK-LABEL: @test_vshr_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSHR_N:%.*]] = lshr <1 x i64> [[TMP1]], <i64 1>
// CHECK:   ret <1 x i64> [[VSHR_N]]
uint64x1_t test_vshr_n_u64(uint64x1_t a) {
  return vshr_n_u64(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_s8(
// CHECK:   [[VSHR_N:%.*]] = ashr <16 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <16 x i8> [[VSHR_N]]
int8x16_t test_vshrq_n_s8(int8x16_t a) {
  return vshrq_n_s8(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSHR_N:%.*]] = ashr <8 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <8 x i16> [[VSHR_N]]
int16x8_t test_vshrq_n_s16(int16x8_t a) {
  return vshrq_n_s16(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSHR_N:%.*]] = ashr <4 x i32> [[TMP1]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[VSHR_N]]
int32x4_t test_vshrq_n_s32(int32x4_t a) {
  return vshrq_n_s32(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSHR_N:%.*]] = ashr <2 x i64> [[TMP1]], <i64 1, i64 1>
// CHECK:   ret <2 x i64> [[VSHR_N]]
int64x2_t test_vshrq_n_s64(int64x2_t a) {
  return vshrq_n_s64(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_u8(
// CHECK:   [[VSHR_N:%.*]] = lshr <16 x i8> %a, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   ret <16 x i8> [[VSHR_N]]
uint8x16_t test_vshrq_n_u8(uint8x16_t a) {
  return vshrq_n_u8(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSHR_N:%.*]] = lshr <8 x i16> [[TMP1]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   ret <8 x i16> [[VSHR_N]]
uint16x8_t test_vshrq_n_u16(uint16x8_t a) {
  return vshrq_n_u16(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSHR_N:%.*]] = lshr <4 x i32> [[TMP1]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   ret <4 x i32> [[VSHR_N]]
uint32x4_t test_vshrq_n_u32(uint32x4_t a) {
  return vshrq_n_u32(a, 1);
}

// CHECK-LABEL: @test_vshrq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSHR_N:%.*]] = lshr <2 x i64> [[TMP1]], <i64 1, i64 1>
// CHECK:   ret <2 x i64> [[VSHR_N]]
uint64x2_t test_vshrq_n_u64(uint64x2_t a) {
  return vshrq_n_u64(a, 1);
}

// CHECK-LABEL: @test_vsli_n_s8(
// CHECK:   [[VSLI_N:%.*]] = call <8 x i8> @llvm.arm.neon.vshiftins.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <8 x i8> [[VSLI_N]]
int8x8_t test_vsli_n_s8(int8x8_t a, int8x8_t b) {
  return vsli_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i16> @llvm.arm.neon.vshiftins.v4i16(<4 x i16> [[VSLI_N]], <4 x i16> [[VSLI_N1]], <4 x i16> <i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <4 x i16> [[VSLI_N2]]
int16x4_t test_vsli_n_s16(int16x4_t a, int16x4_t b) {
  return vsli_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i32> @llvm.arm.neon.vshiftins.v2i32(<2 x i32> [[VSLI_N]], <2 x i32> [[VSLI_N1]], <2 x i32> <i32 1, i32 1>)
// CHECK:   ret <2 x i32> [[VSLI_N2]]
int32x2_t test_vsli_n_s32(int32x2_t a, int32x2_t b) {
  return vsli_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <1 x i64> @llvm.arm.neon.vshiftins.v1i64(<1 x i64> [[VSLI_N]], <1 x i64> [[VSLI_N1]], <1 x i64> <i64 1>)
// CHECK:   ret <1 x i64> [[VSLI_N2]]
int64x1_t test_vsli_n_s64(int64x1_t a, int64x1_t b) {
  return vsli_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_u8(
// CHECK:   [[VSLI_N:%.*]] = call <8 x i8> @llvm.arm.neon.vshiftins.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <8 x i8> [[VSLI_N]]
uint8x8_t test_vsli_n_u8(uint8x8_t a, uint8x8_t b) {
  return vsli_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i16> @llvm.arm.neon.vshiftins.v4i16(<4 x i16> [[VSLI_N]], <4 x i16> [[VSLI_N1]], <4 x i16> <i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <4 x i16> [[VSLI_N2]]
uint16x4_t test_vsli_n_u16(uint16x4_t a, uint16x4_t b) {
  return vsli_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i32> @llvm.arm.neon.vshiftins.v2i32(<2 x i32> [[VSLI_N]], <2 x i32> [[VSLI_N1]], <2 x i32> <i32 1, i32 1>)
// CHECK:   ret <2 x i32> [[VSLI_N2]]
uint32x2_t test_vsli_n_u32(uint32x2_t a, uint32x2_t b) {
  return vsli_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <1 x i64> @llvm.arm.neon.vshiftins.v1i64(<1 x i64> [[VSLI_N]], <1 x i64> [[VSLI_N1]], <1 x i64> <i64 1>)
// CHECK:   ret <1 x i64> [[VSLI_N2]]
uint64x1_t test_vsli_n_u64(uint64x1_t a, uint64x1_t b) {
  return vsli_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_p8(
// CHECK:   [[VSLI_N:%.*]] = call <8 x i8> @llvm.arm.neon.vshiftins.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <8 x i8> [[VSLI_N]]
poly8x8_t test_vsli_n_p8(poly8x8_t a, poly8x8_t b) {
  return vsli_n_p8(a, b, 1);
}

// CHECK-LABEL: @test_vsli_n_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i16> @llvm.arm.neon.vshiftins.v4i16(<4 x i16> [[VSLI_N]], <4 x i16> [[VSLI_N1]], <4 x i16> <i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <4 x i16> [[VSLI_N2]]
poly16x4_t test_vsli_n_p16(poly16x4_t a, poly16x4_t b) {
  return vsli_n_p16(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_s8(
// CHECK:   [[VSLI_N:%.*]] = call <16 x i8> @llvm.arm.neon.vshiftins.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <16 x i8> [[VSLI_N]]
int8x16_t test_vsliq_n_s8(int8x16_t a, int8x16_t b) {
  return vsliq_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <8 x i16> @llvm.arm.neon.vshiftins.v8i16(<8 x i16> [[VSLI_N]], <8 x i16> [[VSLI_N1]], <8 x i16> <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <8 x i16> [[VSLI_N2]]
int16x8_t test_vsliq_n_s16(int16x8_t a, int16x8_t b) {
  return vsliq_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i32> @llvm.arm.neon.vshiftins.v4i32(<4 x i32> [[VSLI_N]], <4 x i32> [[VSLI_N1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>)
// CHECK:   ret <4 x i32> [[VSLI_N2]]
int32x4_t test_vsliq_n_s32(int32x4_t a, int32x4_t b) {
  return vsliq_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i64> @llvm.arm.neon.vshiftins.v2i64(<2 x i64> [[VSLI_N]], <2 x i64> [[VSLI_N1]], <2 x i64> <i64 1, i64 1>)
// CHECK:   ret <2 x i64> [[VSLI_N2]]
int64x2_t test_vsliq_n_s64(int64x2_t a, int64x2_t b) {
  return vsliq_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_u8(
// CHECK:   [[VSLI_N:%.*]] = call <16 x i8> @llvm.arm.neon.vshiftins.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <16 x i8> [[VSLI_N]]
uint8x16_t test_vsliq_n_u8(uint8x16_t a, uint8x16_t b) {
  return vsliq_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <8 x i16> @llvm.arm.neon.vshiftins.v8i16(<8 x i16> [[VSLI_N]], <8 x i16> [[VSLI_N1]], <8 x i16> <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <8 x i16> [[VSLI_N2]]
uint16x8_t test_vsliq_n_u16(uint16x8_t a, uint16x8_t b) {
  return vsliq_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i32> @llvm.arm.neon.vshiftins.v4i32(<4 x i32> [[VSLI_N]], <4 x i32> [[VSLI_N1]], <4 x i32> <i32 1, i32 1, i32 1, i32 1>)
// CHECK:   ret <4 x i32> [[VSLI_N2]]
uint32x4_t test_vsliq_n_u32(uint32x4_t a, uint32x4_t b) {
  return vsliq_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i64> @llvm.arm.neon.vshiftins.v2i64(<2 x i64> [[VSLI_N]], <2 x i64> [[VSLI_N1]], <2 x i64> <i64 1, i64 1>)
// CHECK:   ret <2 x i64> [[VSLI_N2]]
uint64x2_t test_vsliq_n_u64(uint64x2_t a, uint64x2_t b) {
  return vsliq_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_p8(
// CHECK:   [[VSLI_N:%.*]] = call <16 x i8> @llvm.arm.neon.vshiftins.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
// CHECK:   ret <16 x i8> [[VSLI_N]]
poly8x16_t test_vsliq_n_p8(poly8x16_t a, poly8x16_t b) {
  return vsliq_n_p8(a, b, 1);
}

// CHECK-LABEL: @test_vsliq_n_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <8 x i16> @llvm.arm.neon.vshiftins.v8i16(<8 x i16> [[VSLI_N]], <8 x i16> [[VSLI_N1]], <8 x i16> <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
// CHECK:   ret <8 x i16> [[VSLI_N2]]
poly16x8_t test_vsliq_n_p16(poly16x8_t a, poly16x8_t b) {
  return vsliq_n_p16(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_s8(
// CHECK:   [[VSRA_N:%.*]] = ashr <8 x i8> %b, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   [[TMP0:%.*]] = add <8 x i8> %a, [[VSRA_N]]
// CHECK:   ret <8 x i8> [[TMP0]]
int8x8_t test_vsra_n_s8(int8x8_t a, int8x8_t b) {
  return vsra_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSRA_N:%.*]] = ashr <4 x i16> [[TMP3]], <i16 1, i16 1, i16 1, i16 1>
// CHECK:   [[TMP4:%.*]] = add <4 x i16> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <4 x i16> [[TMP4]]
int16x4_t test_vsra_n_s16(int16x4_t a, int16x4_t b) {
  return vsra_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VSRA_N:%.*]] = ashr <2 x i32> [[TMP3]], <i32 1, i32 1>
// CHECK:   [[TMP4:%.*]] = add <2 x i32> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <2 x i32> [[TMP4]]
int32x2_t test_vsra_n_s32(int32x2_t a, int32x2_t b) {
  return vsra_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VSRA_N:%.*]] = ashr <1 x i64> [[TMP3]], <i64 1>
// CHECK:   [[TMP4:%.*]] = add <1 x i64> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <1 x i64> [[TMP4]]
int64x1_t test_vsra_n_s64(int64x1_t a, int64x1_t b) {
  return vsra_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_u8(
// CHECK:   [[VSRA_N:%.*]] = lshr <8 x i8> %b, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   [[TMP0:%.*]] = add <8 x i8> %a, [[VSRA_N]]
// CHECK:   ret <8 x i8> [[TMP0]]
uint8x8_t test_vsra_n_u8(uint8x8_t a, uint8x8_t b) {
  return vsra_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSRA_N:%.*]] = lshr <4 x i16> [[TMP3]], <i16 1, i16 1, i16 1, i16 1>
// CHECK:   [[TMP4:%.*]] = add <4 x i16> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <4 x i16> [[TMP4]]
uint16x4_t test_vsra_n_u16(uint16x4_t a, uint16x4_t b) {
  return vsra_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VSRA_N:%.*]] = lshr <2 x i32> [[TMP3]], <i32 1, i32 1>
// CHECK:   [[TMP4:%.*]] = add <2 x i32> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <2 x i32> [[TMP4]]
uint32x2_t test_vsra_n_u32(uint32x2_t a, uint32x2_t b) {
  return vsra_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vsra_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VSRA_N:%.*]] = lshr <1 x i64> [[TMP3]], <i64 1>
// CHECK:   [[TMP4:%.*]] = add <1 x i64> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <1 x i64> [[TMP4]]
uint64x1_t test_vsra_n_u64(uint64x1_t a, uint64x1_t b) {
  return vsra_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_s8(
// CHECK:   [[VSRA_N:%.*]] = ashr <16 x i8> %b, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   [[TMP0:%.*]] = add <16 x i8> %a, [[VSRA_N]]
// CHECK:   ret <16 x i8> [[TMP0]]
int8x16_t test_vsraq_n_s8(int8x16_t a, int8x16_t b) {
  return vsraq_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSRA_N:%.*]] = ashr <8 x i16> [[TMP3]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   [[TMP4:%.*]] = add <8 x i16> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <8 x i16> [[TMP4]]
int16x8_t test_vsraq_n_s16(int16x8_t a, int16x8_t b) {
  return vsraq_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VSRA_N:%.*]] = ashr <4 x i32> [[TMP3]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[TMP4:%.*]] = add <4 x i32> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <4 x i32> [[TMP4]]
int32x4_t test_vsraq_n_s32(int32x4_t a, int32x4_t b) {
  return vsraq_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VSRA_N:%.*]] = ashr <2 x i64> [[TMP3]], <i64 1, i64 1>
// CHECK:   [[TMP4:%.*]] = add <2 x i64> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <2 x i64> [[TMP4]]
int64x2_t test_vsraq_n_s64(int64x2_t a, int64x2_t b) {
  return vsraq_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_u8(
// CHECK:   [[VSRA_N:%.*]] = lshr <16 x i8> %b, <i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
// CHECK:   [[TMP0:%.*]] = add <16 x i8> %a, [[VSRA_N]]
// CHECK:   ret <16 x i8> [[TMP0]]
uint8x16_t test_vsraq_n_u8(uint8x16_t a, uint8x16_t b) {
  return vsraq_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSRA_N:%.*]] = lshr <8 x i16> [[TMP3]], <i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
// CHECK:   [[TMP4:%.*]] = add <8 x i16> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <8 x i16> [[TMP4]]
uint16x8_t test_vsraq_n_u16(uint16x8_t a, uint16x8_t b) {
  return vsraq_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VSRA_N:%.*]] = lshr <4 x i32> [[TMP3]], <i32 1, i32 1, i32 1, i32 1>
// CHECK:   [[TMP4:%.*]] = add <4 x i32> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <4 x i32> [[TMP4]]
uint32x4_t test_vsraq_n_u32(uint32x4_t a, uint32x4_t b) {
  return vsraq_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vsraq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VSRA_N:%.*]] = lshr <2 x i64> [[TMP3]], <i64 1, i64 1>
// CHECK:   [[TMP4:%.*]] = add <2 x i64> [[TMP2]], [[VSRA_N]]
// CHECK:   ret <2 x i64> [[TMP4]]
uint64x2_t test_vsraq_n_u64(uint64x2_t a, uint64x2_t b) {
  return vsraq_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_s8(
// CHECK:   [[VSLI_N:%.*]] = call <8 x i8> @llvm.arm.neon.vshiftins.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <8 x i8> [[VSLI_N]]
int8x8_t test_vsri_n_s8(int8x8_t a, int8x8_t b) {
  return vsri_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i16> @llvm.arm.neon.vshiftins.v4i16(<4 x i16> [[VSLI_N]], <4 x i16> [[VSLI_N1]], <4 x i16> <i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <4 x i16> [[VSLI_N2]]
int16x4_t test_vsri_n_s16(int16x4_t a, int16x4_t b) {
  return vsri_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i32> @llvm.arm.neon.vshiftins.v2i32(<2 x i32> [[VSLI_N]], <2 x i32> [[VSLI_N1]], <2 x i32> <i32 -1, i32 -1>)
// CHECK:   ret <2 x i32> [[VSLI_N2]]
int32x2_t test_vsri_n_s32(int32x2_t a, int32x2_t b) {
  return vsri_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <1 x i64> @llvm.arm.neon.vshiftins.v1i64(<1 x i64> [[VSLI_N]], <1 x i64> [[VSLI_N1]], <1 x i64> <i64 -1>)
// CHECK:   ret <1 x i64> [[VSLI_N2]]
int64x1_t test_vsri_n_s64(int64x1_t a, int64x1_t b) {
  return vsri_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_u8(
// CHECK:   [[VSLI_N:%.*]] = call <8 x i8> @llvm.arm.neon.vshiftins.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <8 x i8> [[VSLI_N]]
uint8x8_t test_vsri_n_u8(uint8x8_t a, uint8x8_t b) {
  return vsri_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i16> @llvm.arm.neon.vshiftins.v4i16(<4 x i16> [[VSLI_N]], <4 x i16> [[VSLI_N1]], <4 x i16> <i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <4 x i16> [[VSLI_N2]]
uint16x4_t test_vsri_n_u16(uint16x4_t a, uint16x4_t b) {
  return vsri_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <2 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i32> @llvm.arm.neon.vshiftins.v2i32(<2 x i32> [[VSLI_N]], <2 x i32> [[VSLI_N1]], <2 x i32> <i32 -1, i32 -1>)
// CHECK:   ret <2 x i32> [[VSLI_N2]]
uint32x2_t test_vsri_n_u32(uint32x2_t a, uint32x2_t b) {
  return vsri_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <1 x i64> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <1 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <1 x i64> @llvm.arm.neon.vshiftins.v1i64(<1 x i64> [[VSLI_N]], <1 x i64> [[VSLI_N1]], <1 x i64> <i64 -1>)
// CHECK:   ret <1 x i64> [[VSLI_N2]]
uint64x1_t test_vsri_n_u64(uint64x1_t a, uint64x1_t b) {
  return vsri_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_p8(
// CHECK:   [[VSLI_N:%.*]] = call <8 x i8> @llvm.arm.neon.vshiftins.v8i8(<8 x i8> %a, <8 x i8> %b, <8 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <8 x i8> [[VSLI_N]]
poly8x8_t test_vsri_n_p8(poly8x8_t a, poly8x8_t b) {
  return vsri_n_p8(a, b, 1);
}

// CHECK-LABEL: @test_vsri_n_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <8 x i8> [[TMP0]] to <4 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i16> @llvm.arm.neon.vshiftins.v4i16(<4 x i16> [[VSLI_N]], <4 x i16> [[VSLI_N1]], <4 x i16> <i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <4 x i16> [[VSLI_N2]]
poly16x4_t test_vsri_n_p16(poly16x4_t a, poly16x4_t b) {
  return vsri_n_p16(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_s8(
// CHECK:   [[VSLI_N:%.*]] = call <16 x i8> @llvm.arm.neon.vshiftins.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <16 x i8> [[VSLI_N]]
int8x16_t test_vsriq_n_s8(int8x16_t a, int8x16_t b) {
  return vsriq_n_s8(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <8 x i16> @llvm.arm.neon.vshiftins.v8i16(<8 x i16> [[VSLI_N]], <8 x i16> [[VSLI_N1]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i16> [[VSLI_N2]]
int16x8_t test_vsriq_n_s16(int16x8_t a, int16x8_t b) {
  return vsriq_n_s16(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i32> @llvm.arm.neon.vshiftins.v4i32(<4 x i32> [[VSLI_N]], <4 x i32> [[VSLI_N1]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i32> [[VSLI_N2]]
int32x4_t test_vsriq_n_s32(int32x4_t a, int32x4_t b) {
  return vsriq_n_s32(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i64> @llvm.arm.neon.vshiftins.v2i64(<2 x i64> [[VSLI_N]], <2 x i64> [[VSLI_N1]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i64> [[VSLI_N2]]
int64x2_t test_vsriq_n_s64(int64x2_t a, int64x2_t b) {
  return vsriq_n_s64(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_u8(
// CHECK:   [[VSLI_N:%.*]] = call <16 x i8> @llvm.arm.neon.vshiftins.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <16 x i8> [[VSLI_N]]
uint8x16_t test_vsriq_n_u8(uint8x16_t a, uint8x16_t b) {
  return vsriq_n_u8(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <8 x i16> @llvm.arm.neon.vshiftins.v8i16(<8 x i16> [[VSLI_N]], <8 x i16> [[VSLI_N1]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i16> [[VSLI_N2]]
uint16x8_t test_vsriq_n_u16(uint16x8_t a, uint16x8_t b) {
  return vsriq_n_u16(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <4 x i32>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[VSLI_N2:%.*]] = call <4 x i32> @llvm.arm.neon.vshiftins.v4i32(<4 x i32> [[VSLI_N]], <4 x i32> [[VSLI_N1]], <4 x i32> <i32 -1, i32 -1, i32 -1, i32 -1>)
// CHECK:   ret <4 x i32> [[VSLI_N2]]
uint32x4_t test_vsriq_n_u32(uint32x4_t a, uint32x4_t b) {
  return vsriq_n_u32(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <2 x i64>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[VSLI_N2:%.*]] = call <2 x i64> @llvm.arm.neon.vshiftins.v2i64(<2 x i64> [[VSLI_N]], <2 x i64> [[VSLI_N1]], <2 x i64> <i64 -1, i64 -1>)
// CHECK:   ret <2 x i64> [[VSLI_N2]]
uint64x2_t test_vsriq_n_u64(uint64x2_t a, uint64x2_t b) {
  return vsriq_n_u64(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_p8(
// CHECK:   [[VSLI_N:%.*]] = call <16 x i8> @llvm.arm.neon.vshiftins.v16i8(<16 x i8> %a, <16 x i8> %b, <16 x i8> <i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
// CHECK:   ret <16 x i8> [[VSLI_N]]
poly8x16_t test_vsriq_n_p8(poly8x16_t a, poly8x16_t b) {
  return vsriq_n_p8(a, b, 1);
}

// CHECK-LABEL: @test_vsriq_n_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSLI_N:%.*]] = bitcast <16 x i8> [[TMP0]] to <8 x i16>
// CHECK:   [[VSLI_N1:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[VSLI_N2:%.*]] = call <8 x i16> @llvm.arm.neon.vshiftins.v8i16(<8 x i16> [[VSLI_N]], <8 x i16> [[VSLI_N1]], <8 x i16> <i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
// CHECK:   ret <8 x i16> [[VSLI_N2]]
poly16x8_t test_vsriq_n_p16(poly16x8_t a, poly16x8_t b) {
  return vsriq_n_p16(a, b, 1);
}

// CHECK-LABEL: @test_vst1q_u8(
// CHECK:   call void @llvm.arm.neon.vst1.p0.v16i8(ptr %a, <16 x i8> %b, i32 1)
// CHECK:   ret void
void test_vst1q_u8(uint8_t * a, uint8x16_t b) {
  vst1q_u8(a, b);
}

// CHECK-LABEL: @test_vst1q_u16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v8i16(ptr %a, <8 x i16> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1q_u16(uint16_t * a, uint16x8_t b) {
  vst1q_u16(a, b);
}

// CHECK-LABEL: @test_vst1q_u32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v4i32(ptr %a, <4 x i32> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1q_u32(uint32_t * a, uint32x4_t b) {
  vst1q_u32(a, b);
}

// CHECK-LABEL: @test_vst1q_u64(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v2i64(ptr %a, <2 x i64> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1q_u64(uint64_t * a, uint64x2_t b) {
  vst1q_u64(a, b);
}

// CHECK-LABEL: @test_vst1q_s8(
// CHECK:   call void @llvm.arm.neon.vst1.p0.v16i8(ptr %a, <16 x i8> %b, i32 1)
// CHECK:   ret void
void test_vst1q_s8(int8_t * a, int8x16_t b) {
  vst1q_s8(a, b);
}

// CHECK-LABEL: @test_vst1q_s16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v8i16(ptr %a, <8 x i16> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1q_s16(int16_t * a, int16x8_t b) {
  vst1q_s16(a, b);
}

// CHECK-LABEL: @test_vst1q_s32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v4i32(ptr %a, <4 x i32> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1q_s32(int32_t * a, int32x4_t b) {
  vst1q_s32(a, b);
}

// CHECK-LABEL: @test_vst1q_s64(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v2i64(ptr %a, <2 x i64> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1q_s64(int64_t * a, int64x2_t b) {
  vst1q_s64(a, b);
}

// CHECK-LABEL: @test_vst1q_f16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x half> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x half>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v8f16(ptr %a, <8 x half> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1q_f16(float16_t * a, float16x8_t b) {
  vst1q_f16(a, b);
}

// CHECK-LABEL: @test_vst1q_f32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x float>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v4f32(ptr %a, <4 x float> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1q_f32(float32_t * a, float32x4_t b) {
  vst1q_f32(a, b);
}

// CHECK-LABEL: @test_vst1q_p8(
// CHECK:   call void @llvm.arm.neon.vst1.p0.v16i8(ptr %a, <16 x i8> %b, i32 1)
// CHECK:   ret void
void test_vst1q_p8(poly8_t * a, poly8x16_t b) {
  vst1q_p8(a, b);
}

// CHECK-LABEL: @test_vst1q_p16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v8i16(ptr %a, <8 x i16> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1q_p16(poly16_t * a, poly16x8_t b) {
  vst1q_p16(a, b);
}

// CHECK-LABEL: @test_vst1_u8(
// CHECK:   call void @llvm.arm.neon.vst1.p0.v8i8(ptr %a, <8 x i8> %b, i32 1)
// CHECK:   ret void
void test_vst1_u8(uint8_t * a, uint8x8_t b) {
  vst1_u8(a, b);
}

// CHECK-LABEL: @test_vst1_u16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v4i16(ptr %a, <4 x i16> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1_u16(uint16_t * a, uint16x4_t b) {
  vst1_u16(a, b);
}

// CHECK-LABEL: @test_vst1_u32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v2i32(ptr %a, <2 x i32> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1_u32(uint32_t * a, uint32x2_t b) {
  vst1_u32(a, b);
}

// CHECK-LABEL: @test_vst1_u64(
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v1i64(ptr %a, <1 x i64> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1_u64(uint64_t * a, uint64x1_t b) {
  vst1_u64(a, b);
}

// CHECK-LABEL: @test_vst1_s8(
// CHECK:   call void @llvm.arm.neon.vst1.p0.v8i8(ptr %a, <8 x i8> %b, i32 1)
// CHECK:   ret void
void test_vst1_s8(int8_t * a, int8x8_t b) {
  vst1_s8(a, b);
}

// CHECK-LABEL: @test_vst1_s16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v4i16(ptr %a, <4 x i16> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1_s16(int16_t * a, int16x4_t b) {
  vst1_s16(a, b);
}

// CHECK-LABEL: @test_vst1_s32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v2i32(ptr %a, <2 x i32> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1_s32(int32_t * a, int32x2_t b) {
  vst1_s32(a, b);
}

// CHECK-LABEL: @test_vst1_s64(
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v1i64(ptr %a, <1 x i64> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1_s64(int64_t * a, int64x1_t b) {
  vst1_s64(a, b);
}

// CHECK-LABEL: @test_vst1_f16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x half> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x half>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v4f16(ptr %a, <4 x half> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1_f16(float16_t * a, float16x4_t b) {
  vst1_f16(a, b);
}

// CHECK-LABEL: @test_vst1_f32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x float>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v2f32(ptr %a, <2 x float> [[TMP2]], i32 4)
// CHECK:   ret void
void test_vst1_f32(float32_t * a, float32x2_t b) {
  vst1_f32(a, b);
}

// CHECK-LABEL: @test_vst1_p8(
// CHECK:   call void @llvm.arm.neon.vst1.p0.v8i8(ptr %a, <8 x i8> %b, i32 1)
// CHECK:   ret void
void test_vst1_p8(poly8_t * a, poly8x8_t b) {
  vst1_p8(a, b);
}

// CHECK-LABEL: @test_vst1_p16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v4i16(ptr %a, <4 x i16> [[TMP2]], i32 2)
// CHECK:   ret void
void test_vst1_p16(poly16_t * a, poly16x4_t b) {
  vst1_p16(a, b);
}

// CHECK-LABEL: @test_vst1q_lane_u8(
// CHECK:   [[TMP0:%.*]] = extractelement <16 x i8> %b, i32 15
// CHECK:   store i8 [[TMP0]], ptr %a, align 1
// CHECK:   ret void
void test_vst1q_lane_u8(uint8_t * a, uint8x16_t b) {
  vst1q_lane_u8(a, b, 15);
}

// CHECK-LABEL: @test_vst1q_lane_u16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = extractelement <8 x i16> [[TMP2]], i32 7
// CHECK:   store i16 [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1q_lane_u16(uint16_t * a, uint16x8_t b) {
  vst1q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vst1q_lane_u32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = extractelement <4 x i32> [[TMP2]], i32 3
// CHECK:   store i32 [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1q_lane_u32(uint32_t * a, uint32x4_t b) {
  vst1q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vst1q_lane_u64(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = shufflevector <2 x i64> [[TMP2]], <2 x i64> [[TMP2]], <1 x i32> <i32 1>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v1i64(ptr %a, <1 x i64> [[TMP3]], i32 4)
// CHECK:   ret void
void test_vst1q_lane_u64(uint64_t * a, uint64x2_t b) {
  vst1q_lane_u64(a, b, 1);
}

// CHECK-LABEL: @test_vst1q_lane_s8(
// CHECK:   [[TMP0:%.*]] = extractelement <16 x i8> %b, i32 15
// CHECK:   store i8 [[TMP0]], ptr %a, align 1
// CHECK:   ret void
void test_vst1q_lane_s8(int8_t * a, int8x16_t b) {
  vst1q_lane_s8(a, b, 15);
}

// CHECK-LABEL: @test_vst1q_lane_s16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = extractelement <8 x i16> [[TMP2]], i32 7
// CHECK:   store i16 [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1q_lane_s16(int16_t * a, int16x8_t b) {
  vst1q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vst1q_lane_s32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x i32>
// CHECK:   [[TMP3:%.*]] = extractelement <4 x i32> [[TMP2]], i32 3
// CHECK:   store i32 [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1q_lane_s32(int32_t * a, int32x4_t b) {
  vst1q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vst1q_lane_s64(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <2 x i64>
// CHECK:   [[TMP3:%.*]] = shufflevector <2 x i64> [[TMP2]], <2 x i64> [[TMP2]], <1 x i32> <i32 1>
// CHECK:   call void @llvm.arm.neon.vst1.p0.v1i64(ptr %a, <1 x i64> [[TMP3]], i32 4)
// CHECK:   ret void
void test_vst1q_lane_s64(int64_t * a, int64x2_t b) {
  vst1q_lane_s64(a, b, 1);
}

// CHECK-LABEL: @test_vst1q_lane_f16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x half> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x half>
// CHECK:   [[TMP3:%.*]] = extractelement <8 x half> [[TMP2]], i32 7
// CHECK:   store half [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1q_lane_f16(float16_t * a, float16x8_t b) {
  vst1q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vst1q_lane_f32(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <4 x float>
// CHECK:   [[TMP3:%.*]] = extractelement <4 x float> [[TMP2]], i32 3
// CHECK:   store float [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1q_lane_f32(float32_t * a, float32x4_t b) {
  vst1q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vst1q_lane_p8(
// CHECK:   [[TMP0:%.*]] = extractelement <16 x i8> %b, i32 15
// CHECK:   store i8 [[TMP0]], ptr %a, align 1
// CHECK:   ret void
void test_vst1q_lane_p8(poly8_t * a, poly8x16_t b) {
  vst1q_lane_p8(a, b, 15);
}

// CHECK-LABEL: @test_vst1q_lane_p16(
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <16 x i8> [[TMP1]] to <8 x i16>
// CHECK:   [[TMP3:%.*]] = extractelement <8 x i16> [[TMP2]], i32 7
// CHECK:   store i16 [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1q_lane_p16(poly16_t * a, poly16x8_t b) {
  vst1q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vst1_lane_u8(
// CHECK:   [[TMP0:%.*]] = extractelement <8 x i8> %b, i32 7
// CHECK:   store i8 [[TMP0]], ptr %a, align 1
// CHECK:   ret void
void test_vst1_lane_u8(uint8_t * a, uint8x8_t b) {
  vst1_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vst1_lane_u16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = extractelement <4 x i16> [[TMP2]], i32 3
// CHECK:   store i16 [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1_lane_u16(uint16_t * a, uint16x4_t b) {
  vst1_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vst1_lane_u32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = extractelement <2 x i32> [[TMP2]], i32 1
// CHECK:   store i32 [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1_lane_u32(uint32_t * a, uint32x2_t b) {
  vst1_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vst1_lane_u64(
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = extractelement <1 x i64> [[TMP2]], i32 0
// CHECK:   store i64 [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1_lane_u64(uint64_t * a, uint64x1_t b) {
  vst1_lane_u64(a, b, 0);
}

// CHECK-LABEL: @test_vst1_lane_s8(
// CHECK:   [[TMP0:%.*]] = extractelement <8 x i8> %b, i32 7
// CHECK:   store i8 [[TMP0]], ptr %a, align 1
// CHECK:   ret void
void test_vst1_lane_s8(int8_t * a, int8x8_t b) {
  vst1_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vst1_lane_s16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = extractelement <4 x i16> [[TMP2]], i32 3
// CHECK:   store i16 [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1_lane_s16(int16_t * a, int16x4_t b) {
  vst1_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vst1_lane_s32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x i32>
// CHECK:   [[TMP3:%.*]] = extractelement <2 x i32> [[TMP2]], i32 1
// CHECK:   store i32 [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1_lane_s32(int32_t * a, int32x2_t b) {
  vst1_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vst1_lane_s64(
// CHECK:   [[TMP1:%.*]] = bitcast <1 x i64> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <1 x i64>
// CHECK:   [[TMP3:%.*]] = extractelement <1 x i64> [[TMP2]], i32 0
// CHECK:   store i64 [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1_lane_s64(int64_t * a, int64x1_t b) {
  vst1_lane_s64(a, b, 0);
}

// CHECK-LABEL: @test_vst1_lane_f16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x half> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x half>
// CHECK:   [[TMP3:%.*]] = extractelement <4 x half> [[TMP2]], i32 3
// CHECK:   store half [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1_lane_f16(float16_t * a, float16x4_t b) {
  vst1_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vst1_lane_f32(
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <2 x float>
// CHECK:   [[TMP3:%.*]] = extractelement <2 x float> [[TMP2]], i32 1
// CHECK:   store float [[TMP3]], ptr %a, align 4
// CHECK:   ret void
void test_vst1_lane_f32(float32_t * a, float32x2_t b) {
  vst1_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vst1_lane_p8(
// CHECK:   [[TMP0:%.*]] = extractelement <8 x i8> %b, i32 7
// CHECK:   store i8 [[TMP0]], ptr %a, align 1
// CHECK:   ret void
void test_vst1_lane_p8(poly8_t * a, poly8x8_t b) {
  vst1_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vst1_lane_p16(
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i8> [[TMP1]] to <4 x i16>
// CHECK:   [[TMP3:%.*]] = extractelement <4 x i16> [[TMP2]], i32 3
// CHECK:   store i16 [[TMP3]], ptr %a, align 2
// CHECK:   ret void
void test_vst1_lane_p16(poly16_t * a, poly16x4_t b) {
  vst1_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vst2q_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x16x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x16x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x16x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x16x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x16x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   call void @llvm.arm.neon.vst2.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], i32 1)
// CHECK:   ret void
void test_vst2q_u8(uint8_t * a, uint8x16x2_t b) {
  vst2q_u8(a, b);
}

// CHECK-LABEL: @test_vst2q_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v8i16(ptr %a, <8 x i16> [[TMP8]], <8 x i16> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2q_u16(uint16_t * a, uint16x8x2_t b) {
  vst2q_u16(a, b);
}

// CHECK-LABEL: @test_vst2q_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v4i32(ptr %a, <4 x i32> [[TMP8]], <4 x i32> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2q_u32(uint32_t * a, uint32x4x2_t b) {
  vst2q_u32(a, b);
}

// CHECK-LABEL: @test_vst2q_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x16x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x16x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x16x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x16x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x16x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   call void @llvm.arm.neon.vst2.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], i32 1)
// CHECK:   ret void
void test_vst2q_s8(int8_t * a, int8x16x2_t b) {
  vst2q_s8(a, b);
}

// CHECK-LABEL: @test_vst2q_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v8i16(ptr %a, <8 x i16> [[TMP8]], <8 x i16> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2q_s16(int16_t * a, int16x8x2_t b) {
  vst2q_s16(a, b);
}

// CHECK-LABEL: @test_vst2q_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v4i32(ptr %a, <4 x i32> [[TMP8]], <4 x i32> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2q_s32(int32_t * a, int32x4x2_t b) {
  vst2q_s32(a, b);
}

// CHECK-LABEL: @test_vst2q_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x half> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x half> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x half>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x half>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v8f16(ptr %a, <8 x half> [[TMP8]], <8 x half> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2q_f16(float16_t * a, float16x8x2_t b) {
  vst2q_f16(a, b);
}

// CHECK-LABEL: @test_vst2q_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x float> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x float> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x float>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x float>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v4f32(ptr %a, <4 x float> [[TMP8]], <4 x float> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2q_f32(float32_t * a, float32x4x2_t b) {
  vst2q_f32(a, b);
}

// CHECK-LABEL: @test_vst2q_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x16x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x16x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x16x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x16x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x16x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   call void @llvm.arm.neon.vst2.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], i32 1)
// CHECK:   ret void
void test_vst2q_p8(poly8_t * a, poly8x16x2_t b) {
  vst2q_p8(a, b);
}

// CHECK-LABEL: @test_vst2q_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v8i16(ptr %a, <8 x i16> [[TMP8]], <8 x i16> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2q_p16(poly16_t * a, poly16x8x2_t b) {
  vst2q_p16(a, b);
}

// CHECK-LABEL: @test_vst2_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   call void @llvm.arm.neon.vst2.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], i32 1)
// CHECK:   ret void
void test_vst2_u8(uint8_t * a, uint8x8x2_t b) {
  vst2_u8(a, b);
}

// CHECK-LABEL: @test_vst2_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v4i16(ptr %a, <4 x i16> [[TMP8]], <4 x i16> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2_u16(uint16_t * a, uint16x4x2_t b) {
  vst2_u16(a, b);
}

// CHECK-LABEL: @test_vst2_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v2i32(ptr %a, <2 x i32> [[TMP8]], <2 x i32> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2_u32(uint32_t * a, uint32x2x2_t b) {
  vst2_u32(a, b);
}

// CHECK-LABEL: @test_vst2_u64(
// CHECK:   [[B:%.*]] = alloca %struct.uint64x1x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint64x1x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint64x1x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint64x1x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <1 x i64>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <1 x i64>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <1 x i64> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint64x1x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <1 x i64>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <1 x i64>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <1 x i64> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <1 x i64>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v1i64(ptr %a, <1 x i64> [[TMP8]], <1 x i64> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2_u64(uint64_t * a, uint64x1x2_t b) {
  vst2_u64(a, b);
}

// CHECK-LABEL: @test_vst2_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   call void @llvm.arm.neon.vst2.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], i32 1)
// CHECK:   ret void
void test_vst2_s8(int8_t * a, int8x8x2_t b) {
  vst2_s8(a, b);
}

// CHECK-LABEL: @test_vst2_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v4i16(ptr %a, <4 x i16> [[TMP8]], <4 x i16> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2_s16(int16_t * a, int16x4x2_t b) {
  vst2_s16(a, b);
}

// CHECK-LABEL: @test_vst2_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v2i32(ptr %a, <2 x i32> [[TMP8]], <2 x i32> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2_s32(int32_t * a, int32x2x2_t b) {
  vst2_s32(a, b);
}

// CHECK-LABEL: @test_vst2_s64(
// CHECK:   [[B:%.*]] = alloca %struct.int64x1x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int64x1x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int64x1x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int64x1x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <1 x i64>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <1 x i64>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <1 x i64> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int64x1x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <1 x i64>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <1 x i64>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <1 x i64> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <1 x i64>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v1i64(ptr %a, <1 x i64> [[TMP8]], <1 x i64> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2_s64(int64_t * a, int64x1x2_t b) {
  vst2_s64(a, b);
}

// CHECK-LABEL: @test_vst2_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x half> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x half> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x half>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x half>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v4f16(ptr %a, <4 x half> [[TMP8]], <4 x half> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2_f16(float16_t * a, float16x4x2_t b) {
  vst2_f16(a, b);
}

// CHECK-LABEL: @test_vst2_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x float> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x float> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x float>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x float>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v2f32(ptr %a, <2 x float> [[TMP8]], <2 x float> [[TMP9]], i32 4)
// CHECK:   ret void
void test_vst2_f32(float32_t * a, float32x2x2_t b) {
  vst2_f32(a, b);
}

// CHECK-LABEL: @test_vst2_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   call void @llvm.arm.neon.vst2.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], i32 1)
// CHECK:   ret void
void test_vst2_p8(poly8_t * a, poly8x8x2_t b) {
  vst2_p8(a, b);
}

// CHECK-LABEL: @test_vst2_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst2.p0.v4i16(ptr %a, <4 x i16> [[TMP8]], <4 x i16> [[TMP9]], i32 2)
// CHECK:   ret void
void test_vst2_p16(poly16_t * a, poly16x4x2_t b) {
  vst2_p16(a, b);
}

// CHECK-LABEL: @test_vst2q_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v8i16(ptr %a, <8 x i16> [[TMP8]], <8 x i16> [[TMP9]], i32 7, i32 2)
// CHECK:   ret void
void test_vst2q_lane_u16(uint16_t * a, uint16x8x2_t b) {
  vst2q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vst2q_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v4i32(ptr %a, <4 x i32> [[TMP8]], <4 x i32> [[TMP9]], i32 3, i32 4)
// CHECK:   ret void
void test_vst2q_lane_u32(uint32_t * a, uint32x4x2_t b) {
  vst2q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vst2q_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v8i16(ptr %a, <8 x i16> [[TMP8]], <8 x i16> [[TMP9]], i32 7, i32 2)
// CHECK:   ret void
void test_vst2q_lane_s16(int16_t * a, int16x8x2_t b) {
  vst2q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vst2q_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v4i32(ptr %a, <4 x i32> [[TMP8]], <4 x i32> [[TMP9]], i32 3, i32 4)
// CHECK:   ret void
void test_vst2q_lane_s32(int32_t * a, int32x4x2_t b) {
  vst2q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vst2q_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x half> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x half> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x half>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x half>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v8f16(ptr %a, <8 x half> [[TMP8]], <8 x half> [[TMP9]], i32 7, i32 2)
// CHECK:   ret void
void test_vst2q_lane_f16(float16_t * a, float16x8x2_t b) {
  vst2q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vst2q_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x float> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x float> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x float>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x float>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v4f32(ptr %a, <4 x float> [[TMP8]], <4 x float> [[TMP9]], i32 3, i32 4)
// CHECK:   ret void
void test_vst2q_lane_f32(float32_t * a, float32x4x2_t b) {
  vst2q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vst2q_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x2_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v8i16(ptr %a, <8 x i16> [[TMP8]], <8 x i16> [[TMP9]], i32 7, i32 2)
// CHECK:   ret void
void test_vst2q_lane_p16(poly16_t * a, poly16x8x2_t b) {
  vst2q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vst2_lane_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], i32 7, i32 1)
// CHECK:   ret void
void test_vst2_lane_u8(uint8_t * a, uint8x8x2_t b) {
  vst2_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vst2_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v4i16(ptr %a, <4 x i16> [[TMP8]], <4 x i16> [[TMP9]], i32 3, i32 2)
// CHECK:   ret void
void test_vst2_lane_u16(uint16_t * a, uint16x4x2_t b) {
  vst2_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vst2_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v2i32(ptr %a, <2 x i32> [[TMP8]], <2 x i32> [[TMP9]], i32 1, i32 4)
// CHECK:   ret void
void test_vst2_lane_u32(uint32_t * a, uint32x2x2_t b) {
  vst2_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vst2_lane_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], i32 7, i32 1)
// CHECK:   ret void
void test_vst2_lane_s8(int8_t * a, int8x8x2_t b) {
  vst2_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vst2_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v4i16(ptr %a, <4 x i16> [[TMP8]], <4 x i16> [[TMP9]], i32 3, i32 2)
// CHECK:   ret void
void test_vst2_lane_s16(int16_t * a, int16x4x2_t b) {
  vst2_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vst2_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v2i32(ptr %a, <2 x i32> [[TMP8]], <2 x i32> [[TMP9]], i32 1, i32 4)
// CHECK:   ret void
void test_vst2_lane_s32(int32_t * a, int32x2x2_t b) {
  vst2_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vst2_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x half> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x half> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x half>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x half>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v4f16(ptr %a, <4 x half> [[TMP8]], <4 x half> [[TMP9]], i32 3, i32 2)
// CHECK:   ret void
void test_vst2_lane_f16(float16_t * a, float16x4x2_t b) {
  vst2_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vst2_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x float> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x float> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x float>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x float>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v2f32(ptr %a, <2 x float> [[TMP8]], <2 x float> [[TMP9]], i32 1, i32 4)
// CHECK:   ret void
void test_vst2_lane_f32(float32_t * a, float32x2x2_t b) {
  vst2_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vst2_lane_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], i32 7, i32 1)
// CHECK:   ret void
void test_vst2_lane_p8(poly8_t * a, poly8x8x2_t b) {
  vst2_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vst2_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 16, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [2 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[TMP8:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst2lane.p0.v4i16(ptr %a, <4 x i16> [[TMP8]], <4 x i16> [[TMP9]], i32 3, i32 2)
// CHECK:   ret void
void test_vst2_lane_p16(poly16_t * a, poly16x4x2_t b) {
  vst2_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vst3q_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x16x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x16x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x16x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <16 x i8>, ptr [[ARRAYIDX4]], align 16
// CHECK:   call void @llvm.arm.neon.vst3.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], <16 x i8> [[TMP5]], i32 1)
// CHECK:   ret void
void test_vst3q_u8(uint8_t * a, uint8x16x3_t b) {
  vst3q_u8(a, b);
}

// CHECK-LABEL: @test_vst3q_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v8i16(ptr %a, <8 x i16> [[TMP10]], <8 x i16> [[TMP11]], <8 x i16> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3q_u16(uint16_t * a, uint16x8x3_t b) {
  vst3q_u16(a, b);
}

// CHECK-LABEL: @test_vst3q_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v4i32(ptr %a, <4 x i32> [[TMP10]], <4 x i32> [[TMP11]], <4 x i32> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3q_u32(uint32_t * a, uint32x4x3_t b) {
  vst3q_u32(a, b);
}

// CHECK-LABEL: @test_vst3q_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x16x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x16x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x16x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <16 x i8>, ptr [[ARRAYIDX4]], align 16
// CHECK:   call void @llvm.arm.neon.vst3.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], <16 x i8> [[TMP5]], i32 1)
// CHECK:   ret void
void test_vst3q_s8(int8_t * a, int8x16x3_t b) {
  vst3q_s8(a, b);
}

// CHECK-LABEL: @test_vst3q_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v8i16(ptr %a, <8 x i16> [[TMP10]], <8 x i16> [[TMP11]], <8 x i16> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3q_s16(int16_t * a, int16x8x3_t b) {
  vst3q_s16(a, b);
}

// CHECK-LABEL: @test_vst3q_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v4i32(ptr %a, <4 x i32> [[TMP10]], <4 x i32> [[TMP11]], <4 x i32> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3q_s32(int32_t * a, int32x4x3_t b) {
  vst3q_s32(a, b);
}

// CHECK-LABEL: @test_vst3q_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x half> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x half> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x half>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x half> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x half>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x half>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x half>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v8f16(ptr %a, <8 x half> [[TMP10]], <8 x half> [[TMP11]], <8 x half> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3q_f16(float16_t * a, float16x8x3_t b) {
  vst3q_f16(a, b);
}

// CHECK-LABEL: @test_vst3q_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x float> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x float> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x float>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x float> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x float>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x float>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x float>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v4f32(ptr %a, <4 x float> [[TMP10]], <4 x float> [[TMP11]], <4 x float> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3q_f32(float32_t * a, float32x4x3_t b) {
  vst3q_f32(a, b);
}

// CHECK-LABEL: @test_vst3q_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x16x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x16x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x16x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x16x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <16 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <16 x i8>, ptr [[ARRAYIDX4]], align 16
// CHECK:   call void @llvm.arm.neon.vst3.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], <16 x i8> [[TMP5]], i32 1)
// CHECK:   ret void
void test_vst3q_p8(poly8_t * a, poly8x16x3_t b) {
  vst3q_p8(a, b);
}

// CHECK-LABEL: @test_vst3q_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v8i16(ptr %a, <8 x i16> [[TMP10]], <8 x i16> [[TMP11]], <8 x i16> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3q_p16(poly16_t * a, poly16x8x3_t b) {
  vst3q_p16(a, b);
}

// CHECK-LABEL: @test_vst3_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   call void @llvm.arm.neon.vst3.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], i32 1)
// CHECK:   ret void
void test_vst3_u8(uint8_t * a, uint8x8x3_t b) {
  vst3_u8(a, b);
}

// CHECK-LABEL: @test_vst3_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v4i16(ptr %a, <4 x i16> [[TMP10]], <4 x i16> [[TMP11]], <4 x i16> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3_u16(uint16_t * a, uint16x4x3_t b) {
  vst3_u16(a, b);
}

// CHECK-LABEL: @test_vst3_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v2i32(ptr %a, <2 x i32> [[TMP10]], <2 x i32> [[TMP11]], <2 x i32> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3_u32(uint32_t * a, uint32x2x3_t b) {
  vst3_u32(a, b);
}

// CHECK-LABEL: @test_vst3_u64(
// CHECK:   [[B:%.*]] = alloca %struct.uint64x1x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint64x1x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint64x1x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint64x1x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <1 x i64>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <1 x i64>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <1 x i64> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint64x1x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <1 x i64>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <1 x i64>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <1 x i64> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint64x1x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <1 x i64>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <1 x i64>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <1 x i64> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <1 x i64>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <1 x i64>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v1i64(ptr %a, <1 x i64> [[TMP10]], <1 x i64> [[TMP11]], <1 x i64> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3_u64(uint64_t * a, uint64x1x3_t b) {
  vst3_u64(a, b);
}

// CHECK-LABEL: @test_vst3_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   call void @llvm.arm.neon.vst3.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], i32 1)
// CHECK:   ret void
void test_vst3_s8(int8_t * a, int8x8x3_t b) {
  vst3_s8(a, b);
}

// CHECK-LABEL: @test_vst3_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v4i16(ptr %a, <4 x i16> [[TMP10]], <4 x i16> [[TMP11]], <4 x i16> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3_s16(int16_t * a, int16x4x3_t b) {
  vst3_s16(a, b);
}

// CHECK-LABEL: @test_vst3_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v2i32(ptr %a, <2 x i32> [[TMP10]], <2 x i32> [[TMP11]], <2 x i32> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3_s32(int32_t * a, int32x2x3_t b) {
  vst3_s32(a, b);
}

// CHECK-LABEL: @test_vst3_s64(
// CHECK:   [[B:%.*]] = alloca %struct.int64x1x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int64x1x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int64x1x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int64x1x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <1 x i64>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <1 x i64>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <1 x i64> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int64x1x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <1 x i64>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <1 x i64>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <1 x i64> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int64x1x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <1 x i64>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <1 x i64>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <1 x i64> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <1 x i64>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <1 x i64>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v1i64(ptr %a, <1 x i64> [[TMP10]], <1 x i64> [[TMP11]], <1 x i64> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3_s64(int64_t * a, int64x1x3_t b) {
  vst3_s64(a, b);
}

// CHECK-LABEL: @test_vst3_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x half> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x half> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x half>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x half> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x half>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x half>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x half>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v4f16(ptr %a, <4 x half> [[TMP10]], <4 x half> [[TMP11]], <4 x half> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3_f16(float16_t * a, float16x4x3_t b) {
  vst3_f16(a, b);
}

// CHECK-LABEL: @test_vst3_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x float> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x float> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x float>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x float> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x float>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x float>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x float>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v2f32(ptr %a, <2 x float> [[TMP10]], <2 x float> [[TMP11]], <2 x float> [[TMP12]], i32 4)
// CHECK:   ret void
void test_vst3_f32(float32_t * a, float32x2x3_t b) {
  vst3_f32(a, b);
}

// CHECK-LABEL: @test_vst3_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   call void @llvm.arm.neon.vst3.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], i32 1)
// CHECK:   ret void
void test_vst3_p8(poly8_t * a, poly8x8x3_t b) {
  vst3_p8(a, b);
}

// CHECK-LABEL: @test_vst3_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst3.p0.v4i16(ptr %a, <4 x i16> [[TMP10]], <4 x i16> [[TMP11]], <4 x i16> [[TMP12]], i32 2)
// CHECK:   ret void
void test_vst3_p16(poly16_t * a, poly16x4x3_t b) {
  vst3_p16(a, b);
}

// CHECK-LABEL: @test_vst3q_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v8i16(ptr %a, <8 x i16> [[TMP10]], <8 x i16> [[TMP11]], <8 x i16> [[TMP12]], i32 7, i32 2)
// CHECK:   ret void
void test_vst3q_lane_u16(uint16_t * a, uint16x8x3_t b) {
  vst3q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vst3q_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v4i32(ptr %a, <4 x i32> [[TMP10]], <4 x i32> [[TMP11]], <4 x i32> [[TMP12]], i32 3, i32 4)
// CHECK:   ret void
void test_vst3q_lane_u32(uint32_t * a, uint32x4x3_t b) {
  vst3q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vst3q_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v8i16(ptr %a, <8 x i16> [[TMP10]], <8 x i16> [[TMP11]], <8 x i16> [[TMP12]], i32 7, i32 2)
// CHECK:   ret void
void test_vst3q_lane_s16(int16_t * a, int16x8x3_t b) {
  vst3q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vst3q_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v4i32(ptr %a, <4 x i32> [[TMP10]], <4 x i32> [[TMP11]], <4 x i32> [[TMP12]], i32 3, i32 4)
// CHECK:   ret void
void test_vst3q_lane_s32(int32_t * a, int32x4x3_t b) {
  vst3q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vst3q_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x half> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x half> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x half>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x half> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x half>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x half>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x half>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v8f16(ptr %a, <8 x half> [[TMP10]], <8 x half> [[TMP11]], <8 x half> [[TMP12]], i32 7, i32 2)
// CHECK:   ret void
void test_vst3q_lane_f16(float16_t * a, float16x8x3_t b) {
  vst3q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vst3q_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x float> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x float> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x float>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x float> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x float>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x float>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x float>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v4f32(ptr %a, <4 x float> [[TMP10]], <4 x float> [[TMP11]], <4 x float> [[TMP12]], i32 3, i32 4)
// CHECK:   ret void
void test_vst3q_lane_f32(float32_t * a, float32x4x3_t b) {
  vst3q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vst3q_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x3_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [6 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 48, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v8i16(ptr %a, <8 x i16> [[TMP10]], <8 x i16> [[TMP11]], <8 x i16> [[TMP12]], i32 7, i32 2)
// CHECK:   ret void
void test_vst3q_lane_p16(poly16_t * a, poly16x8x3_t b) {
  vst3q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vst3_lane_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], i32 7, i32 1)
// CHECK:   ret void
void test_vst3_lane_u8(uint8_t * a, uint8x8x3_t b) {
  vst3_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vst3_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v4i16(ptr %a, <4 x i16> [[TMP10]], <4 x i16> [[TMP11]], <4 x i16> [[TMP12]], i32 3, i32 2)
// CHECK:   ret void
void test_vst3_lane_u16(uint16_t * a, uint16x4x3_t b) {
  vst3_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vst3_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v2i32(ptr %a, <2 x i32> [[TMP10]], <2 x i32> [[TMP11]], <2 x i32> [[TMP12]], i32 1, i32 4)
// CHECK:   ret void
void test_vst3_lane_u32(uint32_t * a, uint32x2x3_t b) {
  vst3_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vst3_lane_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], i32 7, i32 1)
// CHECK:   ret void
void test_vst3_lane_s8(int8_t * a, int8x8x3_t b) {
  vst3_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vst3_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v4i16(ptr %a, <4 x i16> [[TMP10]], <4 x i16> [[TMP11]], <4 x i16> [[TMP12]], i32 3, i32 2)
// CHECK:   ret void
void test_vst3_lane_s16(int16_t * a, int16x4x3_t b) {
  vst3_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vst3_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v2i32(ptr %a, <2 x i32> [[TMP10]], <2 x i32> [[TMP11]], <2 x i32> [[TMP12]], i32 1, i32 4)
// CHECK:   ret void
void test_vst3_lane_s32(int32_t * a, int32x2x3_t b) {
  vst3_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vst3_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x half> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x half> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x half>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x half> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x half>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x half>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x half>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v4f16(ptr %a, <4 x half> [[TMP10]], <4 x half> [[TMP11]], <4 x half> [[TMP12]], i32 3, i32 2)
// CHECK:   ret void
void test_vst3_lane_f16(float16_t * a, float16x4x3_t b) {
  vst3_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vst3_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x float> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x float> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x2x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <2 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x float>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x float> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x float>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x float>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x float>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v2f32(ptr %a, <2 x float> [[TMP10]], <2 x float> [[TMP11]], <2 x float> [[TMP12]], i32 1, i32 4)
// CHECK:   ret void
void test_vst3_lane_f32(float32_t * a, float32x2x3_t b) {
  vst3_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vst3_lane_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], i32 7, i32 1)
// CHECK:   ret void
void test_vst3_lane_p8(poly8_t * a, poly8x8x3_t b) {
  vst3_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vst3_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 24, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x4x3_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [3 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[TMP10:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst3lane.p0.v4i16(ptr %a, <4 x i16> [[TMP10]], <4 x i16> [[TMP11]], <4 x i16> [[TMP12]], i32 3, i32 2)
// CHECK:   ret void
void test_vst3_lane_p16(poly16_t * a, poly16x4x3_t b) {
  vst3_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vst4q_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x16x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x16x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x16x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <16 x i8>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <16 x i8>, ptr [[ARRAYIDX6]], align 16
// CHECK:   call void @llvm.arm.neon.vst4.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], <16 x i8> [[TMP5]], <16 x i8> [[TMP6]], i32 1)
// CHECK:   ret void
void test_vst4q_u8(uint8_t * a, uint8x16x4_t b) {
  vst4q_u8(a, b);
}

// CHECK-LABEL: @test_vst4q_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i16> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v8i16(ptr %a, <8 x i16> [[TMP12]], <8 x i16> [[TMP13]], <8 x i16> [[TMP14]], <8 x i16> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4q_u16(uint16_t * a, uint16x8x4_t b) {
  vst4q_u16(a, b);
}

// CHECK-LABEL: @test_vst4q_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i32>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i32> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v4i32(ptr %a, <4 x i32> [[TMP12]], <4 x i32> [[TMP13]], <4 x i32> [[TMP14]], <4 x i32> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4q_u32(uint32_t * a, uint32x4x4_t b) {
  vst4q_u32(a, b);
}

// CHECK-LABEL: @test_vst4q_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x16x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x16x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x16x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <16 x i8>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <16 x i8>, ptr [[ARRAYIDX6]], align 16
// CHECK:   call void @llvm.arm.neon.vst4.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], <16 x i8> [[TMP5]], <16 x i8> [[TMP6]], i32 1)
// CHECK:   ret void
void test_vst4q_s8(int8_t * a, int8x16x4_t b) {
  vst4q_s8(a, b);
}

// CHECK-LABEL: @test_vst4q_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i16> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v8i16(ptr %a, <8 x i16> [[TMP12]], <8 x i16> [[TMP13]], <8 x i16> [[TMP14]], <8 x i16> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4q_s16(int16_t * a, int16x8x4_t b) {
  vst4q_s16(a, b);
}

// CHECK-LABEL: @test_vst4q_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i32>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i32> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v4i32(ptr %a, <4 x i32> [[TMP12]], <4 x i32> [[TMP13]], <4 x i32> [[TMP14]], <4 x i32> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4q_s32(int32_t * a, int32x4x4_t b) {
  vst4q_s32(a, b);
}

// CHECK-LABEL: @test_vst4q_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x half> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x half> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x half>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x half> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x half>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x half> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x half>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x half>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x half>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x half>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v8f16(ptr %a, <8 x half> [[TMP12]], <8 x half> [[TMP13]], <8 x half> [[TMP14]], <8 x half> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4q_f16(float16_t * a, float16x8x4_t b) {
  vst4q_f16(a, b);
}

// CHECK-LABEL: @test_vst4q_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x float> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x float> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x float>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x float> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x float>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <4 x float> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x float>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x float>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x float>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <4 x float>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v4f32(ptr %a, <4 x float> [[TMP12]], <4 x float> [[TMP13]], <4 x float> [[TMP14]], <4 x float> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4q_f32(float32_t * a, float32x4x4_t b) {
  vst4q_f32(a, b);
}

// CHECK-LABEL: @test_vst4q_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x16x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x16x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x16x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <16 x i8>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <16 x i8>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <16 x i8>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly8x16x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <16 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <16 x i8>, ptr [[ARRAYIDX6]], align 16
// CHECK:   call void @llvm.arm.neon.vst4.p0.v16i8(ptr %a, <16 x i8> [[TMP3]], <16 x i8> [[TMP4]], <16 x i8> [[TMP5]], <16 x i8> [[TMP6]], i32 1)
// CHECK:   ret void
void test_vst4q_p8(poly8_t * a, poly8x16x4_t b) {
  vst4q_p8(a, b);
}

// CHECK-LABEL: @test_vst4q_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i16> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v8i16(ptr %a, <8 x i16> [[TMP12]], <8 x i16> [[TMP13]], <8 x i16> [[TMP14]], <8 x i16> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4q_p16(poly16_t * a, poly16x8x4_t b) {
  vst4q_p16(a, b);
}

// CHECK-LABEL: @test_vst4_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   call void @llvm.arm.neon.vst4.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], i32 1)
// CHECK:   ret void
void test_vst4_u8(uint8_t * a, uint8x8x4_t b) {
  vst4_u8(a, b);
}

// CHECK-LABEL: @test_vst4_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i16> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v4i16(ptr %a, <4 x i16> [[TMP12]], <4 x i16> [[TMP13]], <4 x i16> [[TMP14]], <4 x i16> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4_u16(uint16_t * a, uint16x4x4_t b) {
  vst4_u16(a, b);
}

// CHECK-LABEL: @test_vst4_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <2 x i32>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <2 x i32> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v2i32(ptr %a, <2 x i32> [[TMP12]], <2 x i32> [[TMP13]], <2 x i32> [[TMP14]], <2 x i32> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4_u32(uint32_t * a, uint32x2x4_t b) {
  vst4_u32(a, b);
}

// CHECK-LABEL: @test_vst4_u64(
// CHECK:   [[B:%.*]] = alloca %struct.uint64x1x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint64x1x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint64x1x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <1 x i64>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <1 x i64> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <1 x i64>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <1 x i64> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <1 x i64>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <1 x i64> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <1 x i64>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <1 x i64> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <1 x i64>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <1 x i64>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <1 x i64>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v1i64(ptr %a, <1 x i64> [[TMP12]], <1 x i64> [[TMP13]], <1 x i64> [[TMP14]], <1 x i64> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4_u64(uint64_t * a, uint64x1x4_t b) {
  vst4_u64(a, b);
}

// CHECK-LABEL: @test_vst4_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   call void @llvm.arm.neon.vst4.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], i32 1)
// CHECK:   ret void
void test_vst4_s8(int8_t * a, int8x8x4_t b) {
  vst4_s8(a, b);
}

// CHECK-LABEL: @test_vst4_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i16> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v4i16(ptr %a, <4 x i16> [[TMP12]], <4 x i16> [[TMP13]], <4 x i16> [[TMP14]], <4 x i16> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4_s16(int16_t * a, int16x4x4_t b) {
  vst4_s16(a, b);
}

// CHECK-LABEL: @test_vst4_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <2 x i32>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <2 x i32> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v2i32(ptr %a, <2 x i32> [[TMP12]], <2 x i32> [[TMP13]], <2 x i32> [[TMP14]], <2 x i32> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4_s32(int32_t * a, int32x2x4_t b) {
  vst4_s32(a, b);
}

// CHECK-LABEL: @test_vst4_s64(
// CHECK:   [[B:%.*]] = alloca %struct.int64x1x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int64x1x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int64x1x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <1 x i64>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <1 x i64> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <1 x i64>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <1 x i64> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <1 x i64>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <1 x i64> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int64x1x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <1 x i64>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <1 x i64>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <1 x i64> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <1 x i64>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <1 x i64>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <1 x i64>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <1 x i64>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v1i64(ptr %a, <1 x i64> [[TMP12]], <1 x i64> [[TMP13]], <1 x i64> [[TMP14]], <1 x i64> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4_s64(int64_t * a, int64x1x4_t b) {
  vst4_s64(a, b);
}

// CHECK-LABEL: @test_vst4_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x half> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x half> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x half>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x half> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x half>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x half> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x half>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x half>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x half>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x half>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v4f16(ptr %a, <4 x half> [[TMP12]], <4 x half> [[TMP13]], <4 x half> [[TMP14]], <4 x half> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4_f16(float16_t * a, float16x4x4_t b) {
  vst4_f16(a, b);
}

// CHECK-LABEL: @test_vst4_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x float> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x float> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x float>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x float> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <2 x float>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <2 x float> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x float>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x float>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x float>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <2 x float>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v2f32(ptr %a, <2 x float> [[TMP12]], <2 x float> [[TMP13]], <2 x float> [[TMP14]], <2 x float> [[TMP15]], i32 4)
// CHECK:   ret void
void test_vst4_f32(float32_t * a, float32x2x4_t b) {
  vst4_f32(a, b);
}

// CHECK-LABEL: @test_vst4_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   call void @llvm.arm.neon.vst4.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], i32 1)
// CHECK:   ret void
void test_vst4_p8(poly8_t * a, poly8x8x4_t b) {
  vst4_p8(a, b);
}

// CHECK-LABEL: @test_vst4_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i16> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst4.p0.v4i16(ptr %a, <4 x i16> [[TMP12]], <4 x i16> [[TMP13]], <4 x i16> [[TMP14]], <4 x i16> [[TMP15]], i32 2)
// CHECK:   ret void
void test_vst4_p16(poly16_t * a, poly16x4x4_t b) {
  vst4_p16(a, b);
}

// CHECK-LABEL: @test_vst4q_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i16> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v8i16(ptr %a, <8 x i16> [[TMP12]], <8 x i16> [[TMP13]], <8 x i16> [[TMP14]], <8 x i16> [[TMP15]], i32 7, i32 2)
// CHECK:   ret void
void test_vst4q_lane_u16(uint16_t * a, uint16x8x4_t b) {
  vst4q_lane_u16(a, b, 7);
}

// CHECK-LABEL: @test_vst4q_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i32>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i32> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v4i32(ptr %a, <4 x i32> [[TMP12]], <4 x i32> [[TMP13]], <4 x i32> [[TMP14]], <4 x i32> [[TMP15]], i32 3, i32 4)
// CHECK:   ret void
void test_vst4q_lane_u32(uint32_t * a, uint32x4x4_t b) {
  vst4q_lane_u32(a, b, 3);
}

// CHECK-LABEL: @test_vst4q_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i16> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v8i16(ptr %a, <8 x i16> [[TMP12]], <8 x i16> [[TMP13]], <8 x i16> [[TMP14]], <8 x i16> [[TMP15]], i32 7, i32 2)
// CHECK:   ret void
void test_vst4q_lane_s16(int16_t * a, int16x8x4_t b) {
  vst4q_lane_s16(a, b, 7);
}

// CHECK-LABEL: @test_vst4q_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i32>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i32>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i32> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i32>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i32> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i32>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i32> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <4 x i32>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v4i32(ptr %a, <4 x i32> [[TMP12]], <4 x i32> [[TMP13]], <4 x i32> [[TMP14]], <4 x i32> [[TMP15]], i32 3, i32 4)
// CHECK:   ret void
void test_vst4q_lane_s32(int32_t * a, int32x4x4_t b) {
  vst4q_lane_s32(a, b, 3);
}

// CHECK-LABEL: @test_vst4q_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x half>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x half> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x half>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x half> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x half>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x half> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x half>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x half>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x half> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x half>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x half>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x half>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x half>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v8f16(ptr %a, <8 x half> [[TMP12]], <8 x half> [[TMP13]], <8 x half> [[TMP14]], <8 x half> [[TMP15]], i32 7, i32 2)
// CHECK:   ret void
void test_vst4q_lane_f16(float16_t * a, float16x8x4_t b) {
  vst4q_lane_f16(a, b, 7);
}

// CHECK-LABEL: @test_vst4q_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x4x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x float>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <4 x float> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x float>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <4 x float> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x float>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <4 x float> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float32x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x float>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x float>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <4 x float> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <4 x float>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <4 x float>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <4 x float>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <4 x float>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v4f32(ptr %a, <4 x float> [[TMP12]], <4 x float> [[TMP13]], <4 x float> [[TMP14]], <4 x float> [[TMP15]], i32 3, i32 4)
// CHECK:   ret void
void test_vst4q_lane_f32(float32_t * a, float32x4x4_t b) {
  vst4q_lane_f32(a, b, 3);
}

// CHECK-LABEL: @test_vst4q_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x8x4_t, align 16
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [8 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 16
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 16 [[__S1]], ptr align 16 [[B]], i32 64, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <8 x i16>, ptr [[ARRAYIDX]], align 16
// CHECK:   [[TMP5:%.*]] = bitcast <8 x i16> [[TMP4]] to <16 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <8 x i16>, ptr [[ARRAYIDX2]], align 16
// CHECK:   [[TMP7:%.*]] = bitcast <8 x i16> [[TMP6]] to <16 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <8 x i16>, ptr [[ARRAYIDX4]], align 16
// CHECK:   [[TMP9:%.*]] = bitcast <8 x i16> [[TMP8]] to <16 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly16x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <8 x i16>, ptr [[ARRAYIDX6]], align 16
// CHECK:   [[TMP11:%.*]] = bitcast <8 x i16> [[TMP10]] to <16 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <16 x i8> [[TMP5]] to <8 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <16 x i8> [[TMP7]] to <8 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <16 x i8> [[TMP9]] to <8 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <16 x i8> [[TMP11]] to <8 x i16>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v8i16(ptr %a, <8 x i16> [[TMP12]], <8 x i16> [[TMP13]], <8 x i16> [[TMP14]], <8 x i16> [[TMP15]], i32 7, i32 2)
// CHECK:   ret void
void test_vst4q_lane_p16(poly16_t * a, poly16x8x4_t b) {
  vst4q_lane_p16(a, b, 7);
}

// CHECK-LABEL: @test_vst4_lane_u8(
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], i32 7, i32 1)
// CHECK:   ret void
void test_vst4_lane_u8(uint8_t * a, uint8x8x4_t b) {
  vst4_lane_u8(a, b, 7);
}

// CHECK-LABEL: @test_vst4_lane_u16(
// CHECK:   [[B:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i16> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v4i16(ptr %a, <4 x i16> [[TMP12]], <4 x i16> [[TMP13]], <4 x i16> [[TMP14]], <4 x i16> [[TMP15]], i32 3, i32 2)
// CHECK:   ret void
void test_vst4_lane_u16(uint16_t * a, uint16x4x4_t b) {
  vst4_lane_u16(a, b, 3);
}

// CHECK-LABEL: @test_vst4_lane_u32(
// CHECK:   [[B:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.uint32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.uint32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <2 x i32>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <2 x i32> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v2i32(ptr %a, <2 x i32> [[TMP12]], <2 x i32> [[TMP13]], <2 x i32> [[TMP14]], <2 x i32> [[TMP15]], i32 1, i32 4)
// CHECK:   ret void
void test_vst4_lane_u32(uint32_t * a, uint32x2x4_t b) {
  vst4_lane_u32(a, b, 1);
}

// CHECK-LABEL: @test_vst4_lane_s8(
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], i32 7, i32 1)
// CHECK:   ret void
void test_vst4_lane_s8(int8_t * a, int8x8x4_t b) {
  vst4_lane_s8(a, b, 7);
}

// CHECK-LABEL: @test_vst4_lane_s16(
// CHECK:   [[B:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i16> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v4i16(ptr %a, <4 x i16> [[TMP12]], <4 x i16> [[TMP13]], <4 x i16> [[TMP14]], <4 x i16> [[TMP15]], i32 3, i32 2)
// CHECK:   ret void
void test_vst4_lane_s16(int16_t * a, int16x4x4_t b) {
  vst4_lane_s16(a, b, 3);
}

// CHECK-LABEL: @test_vst4_lane_s32(
// CHECK:   [[B:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.int32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x i32>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x i32> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x i32>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x i32> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x i32>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x i32> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.int32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x i32>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <2 x i32>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <2 x i32> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x i32>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x i32>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x i32>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <2 x i32>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v2i32(ptr %a, <2 x i32> [[TMP12]], <2 x i32> [[TMP13]], <2 x i32> [[TMP14]], <2 x i32> [[TMP15]], i32 1, i32 4)
// CHECK:   ret void
void test_vst4_lane_s32(int32_t * a, int32x2x4_t b) {
  vst4_lane_s32(a, b, 1);
}

// CHECK-LABEL: @test_vst4_lane_f16(
// CHECK:   [[B:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x half>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x half> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x half>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x half> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x half>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x half> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x half>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x half>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x half> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x half>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x half>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x half>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x half>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v4f16(ptr %a, <4 x half> [[TMP12]], <4 x half> [[TMP13]], <4 x half> [[TMP14]], <4 x half> [[TMP15]], i32 3, i32 2)
// CHECK:   ret void
void test_vst4_lane_f16(float16_t * a, float16x4x4_t b) {
  vst4_lane_f16(a, b, 3);
}

// CHECK-LABEL: @test_vst4_lane_f32(
// CHECK:   [[B:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.float32x2x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <2 x float>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <2 x float> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <2 x float>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <2 x float> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <2 x float>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <2 x float> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.float32x2x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <2 x float>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <2 x float>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <2 x float> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <2 x float>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <2 x float>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <2 x float>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <2 x float>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v2f32(ptr %a, <2 x float> [[TMP12]], <2 x float> [[TMP13]], <2 x float> [[TMP14]], <2 x float> [[TMP15]], i32 1, i32 4)
// CHECK:   ret void
void test_vst4_lane_f32(float32_t * a, float32x2x4_t b) {
  vst4_lane_f32(a, b, 1);
}

// CHECK-LABEL: @test_vst4_lane_p8(
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP3:%.*]] = load <8 x i8>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6]], align 8
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v8i8(ptr %a, <8 x i8> [[TMP3]], <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], i32 7, i32 1)
// CHECK:   ret void
void test_vst4_lane_p8(poly8_t * a, poly8x8x4_t b) {
  vst4_lane_p8(a, b, 7);
}

// CHECK-LABEL: @test_vst4_lane_p16(
// CHECK:   [[B:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[__S1:%.*]] = alloca %struct.poly16x4x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   call void @llvm.memcpy.p0.p0.i32(ptr align 8 [[__S1]], ptr align 8 [[B]], i32 32, i1 false)
// CHECK:   [[VAL:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL]], i32 0, i32 0
// CHECK:   [[TMP4:%.*]] = load <4 x i16>, ptr [[ARRAYIDX]], align 8
// CHECK:   [[TMP5:%.*]] = bitcast <4 x i16> [[TMP4]] to <8 x i8>
// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX2:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL1]], i32 0, i32 1
// CHECK:   [[TMP6:%.*]] = load <4 x i16>, ptr [[ARRAYIDX2]], align 8
// CHECK:   [[TMP7:%.*]] = bitcast <4 x i16> [[TMP6]] to <8 x i8>
// CHECK:   [[VAL3:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX4:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL3]], i32 0, i32 2
// CHECK:   [[TMP8:%.*]] = load <4 x i16>, ptr [[ARRAYIDX4]], align 8
// CHECK:   [[TMP9:%.*]] = bitcast <4 x i16> [[TMP8]] to <8 x i8>
// CHECK:   [[VAL5:%.*]] = getelementptr inbounds %struct.poly16x4x4_t, ptr [[__S1]], i32 0, i32 0
// CHECK:   [[ARRAYIDX6:%.*]] = getelementptr inbounds [4 x <4 x i16>], ptr [[VAL5]], i32 0, i32 3
// CHECK:   [[TMP10:%.*]] = load <4 x i16>, ptr [[ARRAYIDX6]], align 8
// CHECK:   [[TMP11:%.*]] = bitcast <4 x i16> [[TMP10]] to <8 x i8>
// CHECK:   [[TMP12:%.*]] = bitcast <8 x i8> [[TMP5]] to <4 x i16>
// CHECK:   [[TMP13:%.*]] = bitcast <8 x i8> [[TMP7]] to <4 x i16>
// CHECK:   [[TMP14:%.*]] = bitcast <8 x i8> [[TMP9]] to <4 x i16>
// CHECK:   [[TMP15:%.*]] = bitcast <8 x i8> [[TMP11]] to <4 x i16>
// CHECK:   call void @llvm.arm.neon.vst4lane.p0.v4i16(ptr %a, <4 x i16> [[TMP12]], <4 x i16> [[TMP13]], <4 x i16> [[TMP14]], <4 x i16> [[TMP15]], i32 3, i32 2)
// CHECK:   ret void
void test_vst4_lane_p16(poly16_t * a, poly16x4x4_t b) {
  vst4_lane_p16(a, b, 3);
}

// CHECK-LABEL: @test_vsub_s8(
// CHECK:   [[SUB_I:%.*]] = sub <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[SUB_I]]
int8x8_t test_vsub_s8(int8x8_t a, int8x8_t b) {
  return vsub_s8(a, b);
}

// CHECK-LABEL: @test_vsub_s16(
// CHECK:   [[SUB_I:%.*]] = sub <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[SUB_I]]
int16x4_t test_vsub_s16(int16x4_t a, int16x4_t b) {
  return vsub_s16(a, b);
}

// CHECK-LABEL: @test_vsub_s32(
// CHECK:   [[SUB_I:%.*]] = sub <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[SUB_I]]
int32x2_t test_vsub_s32(int32x2_t a, int32x2_t b) {
  return vsub_s32(a, b);
}

// CHECK-LABEL: @test_vsub_s64(
// CHECK:   [[SUB_I:%.*]] = sub <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[SUB_I]]
int64x1_t test_vsub_s64(int64x1_t a, int64x1_t b) {
  return vsub_s64(a, b);
}

// CHECK-LABEL: @test_vsub_f32(
// CHECK:   [[SUB_I:%.*]] = fsub <2 x float> %a, %b
// CHECK:   ret <2 x float> [[SUB_I]]
float32x2_t test_vsub_f32(float32x2_t a, float32x2_t b) {
  return vsub_f32(a, b);
}

// CHECK-LABEL: @test_vsub_u8(
// CHECK:   [[SUB_I:%.*]] = sub <8 x i8> %a, %b
// CHECK:   ret <8 x i8> [[SUB_I]]
uint8x8_t test_vsub_u8(uint8x8_t a, uint8x8_t b) {
  return vsub_u8(a, b);
}

// CHECK-LABEL: @test_vsub_u16(
// CHECK:   [[SUB_I:%.*]] = sub <4 x i16> %a, %b
// CHECK:   ret <4 x i16> [[SUB_I]]
uint16x4_t test_vsub_u16(uint16x4_t a, uint16x4_t b) {
  return vsub_u16(a, b);
}

// CHECK-LABEL: @test_vsub_u32(
// CHECK:   [[SUB_I:%.*]] = sub <2 x i32> %a, %b
// CHECK:   ret <2 x i32> [[SUB_I]]
uint32x2_t test_vsub_u32(uint32x2_t a, uint32x2_t b) {
  return vsub_u32(a, b);
}

// CHECK-LABEL: @test_vsub_u64(
// CHECK:   [[SUB_I:%.*]] = sub <1 x i64> %a, %b
// CHECK:   ret <1 x i64> [[SUB_I]]
uint64x1_t test_vsub_u64(uint64x1_t a, uint64x1_t b) {
  return vsub_u64(a, b);
}

// CHECK-LABEL: @test_vsubq_s8(
// CHECK:   [[SUB_I:%.*]] = sub <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[SUB_I]]
int8x16_t test_vsubq_s8(int8x16_t a, int8x16_t b) {
  return vsubq_s8(a, b);
}

// CHECK-LABEL: @test_vsubq_s16(
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[SUB_I]]
int16x8_t test_vsubq_s16(int16x8_t a, int16x8_t b) {
  return vsubq_s16(a, b);
}

// CHECK-LABEL: @test_vsubq_s32(
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vsubq_s32(int32x4_t a, int32x4_t b) {
  return vsubq_s32(a, b);
}

// CHECK-LABEL: @test_vsubq_s64(
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[SUB_I]]
int64x2_t test_vsubq_s64(int64x2_t a, int64x2_t b) {
  return vsubq_s64(a, b);
}

// CHECK-LABEL: @test_vsubq_f32(
// CHECK:   [[SUB_I:%.*]] = fsub <4 x float> %a, %b
// CHECK:   ret <4 x float> [[SUB_I]]
float32x4_t test_vsubq_f32(float32x4_t a, float32x4_t b) {
  return vsubq_f32(a, b);
}

// CHECK-LABEL: @test_vsubq_u8(
// CHECK:   [[SUB_I:%.*]] = sub <16 x i8> %a, %b
// CHECK:   ret <16 x i8> [[SUB_I]]
uint8x16_t test_vsubq_u8(uint8x16_t a, uint8x16_t b) {
  return vsubq_u8(a, b);
}

// CHECK-LABEL: @test_vsubq_u16(
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, %b
// CHECK:   ret <8 x i16> [[SUB_I]]
uint16x8_t test_vsubq_u16(uint16x8_t a, uint16x8_t b) {
  return vsubq_u16(a, b);
}

// CHECK-LABEL: @test_vsubq_u32(
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, %b
// CHECK:   ret <4 x i32> [[SUB_I]]
uint32x4_t test_vsubq_u32(uint32x4_t a, uint32x4_t b) {
  return vsubq_u32(a, b);
}

// CHECK-LABEL: @test_vsubq_u64(
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, %b
// CHECK:   ret <2 x i64> [[SUB_I]]
uint64x2_t test_vsubq_u64(uint64x2_t a, uint64x2_t b) {
  return vsubq_u64(a, b);
}

// CHECK-LABEL: @test_vsubhn_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSUBHN_I:%.*]] = sub <8 x i16> %a, %b
// CHECK:   [[VSUBHN1_I:%.*]] = lshr <8 x i16> [[VSUBHN_I]], <i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
// CHECK:   [[VSUBHN2_I:%.*]] = trunc <8 x i16> [[VSUBHN1_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VSUBHN2_I]]
int8x8_t test_vsubhn_s16(int16x8_t a, int16x8_t b) {
  return vsubhn_s16(a, b);
}

// CHECK-LABEL: @test_vsubhn_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSUBHN_I:%.*]] = sub <4 x i32> %a, %b
// CHECK:   [[VSUBHN1_I:%.*]] = lshr <4 x i32> [[VSUBHN_I]], <i32 16, i32 16, i32 16, i32 16>
// CHECK:   [[VSUBHN2_I:%.*]] = trunc <4 x i32> [[VSUBHN1_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VSUBHN2_I]]
int16x4_t test_vsubhn_s32(int32x4_t a, int32x4_t b) {
  return vsubhn_s32(a, b);
}

// CHECK-LABEL: @test_vsubhn_s64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSUBHN_I:%.*]] = sub <2 x i64> %a, %b
// CHECK:   [[VSUBHN1_I:%.*]] = lshr <2 x i64> [[VSUBHN_I]], <i64 32, i64 32>
// CHECK:   [[VSUBHN2_I:%.*]] = trunc <2 x i64> [[VSUBHN1_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VSUBHN2_I]]
int32x2_t test_vsubhn_s64(int64x2_t a, int64x2_t b) {
  return vsubhn_s64(a, b);
}

// CHECK-LABEL: @test_vsubhn_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VSUBHN_I:%.*]] = sub <8 x i16> %a, %b
// CHECK:   [[VSUBHN1_I:%.*]] = lshr <8 x i16> [[VSUBHN_I]], <i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
// CHECK:   [[VSUBHN2_I:%.*]] = trunc <8 x i16> [[VSUBHN1_I]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VSUBHN2_I]]
uint8x8_t test_vsubhn_u16(uint16x8_t a, uint16x8_t b) {
  return vsubhn_u16(a, b);
}

// CHECK-LABEL: @test_vsubhn_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VSUBHN_I:%.*]] = sub <4 x i32> %a, %b
// CHECK:   [[VSUBHN1_I:%.*]] = lshr <4 x i32> [[VSUBHN_I]], <i32 16, i32 16, i32 16, i32 16>
// CHECK:   [[VSUBHN2_I:%.*]] = trunc <4 x i32> [[VSUBHN1_I]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VSUBHN2_I]]
uint16x4_t test_vsubhn_u32(uint32x4_t a, uint32x4_t b) {
  return vsubhn_u32(a, b);
}

// CHECK-LABEL: @test_vsubhn_u64(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i64> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i64> %b to <16 x i8>
// CHECK:   [[VSUBHN_I:%.*]] = sub <2 x i64> %a, %b
// CHECK:   [[VSUBHN1_I:%.*]] = lshr <2 x i64> [[VSUBHN_I]], <i64 32, i64 32>
// CHECK:   [[VSUBHN2_I:%.*]] = trunc <2 x i64> [[VSUBHN1_I]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VSUBHN2_I]]
uint32x2_t test_vsubhn_u64(uint64x2_t a, uint64x2_t b) {
  return vsubhn_u64(a, b);
}

// CHECK-LABEL: @test_vsubl_s8(
// CHECK:   [[VMOVL_I_I:%.*]] = sext <8 x i8> %a to <8 x i16>
// CHECK:   [[VMOVL_I4_I:%.*]] = sext <8 x i8> %b to <8 x i16>
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
int16x8_t test_vsubl_s8(int8x8_t a, int8x8_t b) {
  return vsubl_s8(a, b);
}

// CHECK-LABEL: @test_vsubl_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <4 x i16> %a to <4 x i32>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = sext <4 x i16> %b to <4 x i32>
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vsubl_s16(int16x4_t a, int16x4_t b) {
  return vsubl_s16(a, b);
}

// CHECK-LABEL: @test_vsubl_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <2 x i32> %a to <2 x i64>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = sext <2 x i32> %b to <2 x i64>
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
int64x2_t test_vsubl_s32(int32x2_t a, int32x2_t b) {
  return vsubl_s32(a, b);
}

// CHECK-LABEL: @test_vsubl_u8(
// CHECK:   [[VMOVL_I_I:%.*]] = zext <8 x i8> %a to <8 x i16>
// CHECK:   [[VMOVL_I4_I:%.*]] = zext <8 x i8> %b to <8 x i16>
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
uint16x8_t test_vsubl_u8(uint8x8_t a, uint8x8_t b) {
  return vsubl_u8(a, b);
}

// CHECK-LABEL: @test_vsubl_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <4 x i16> %a to <4 x i32>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = zext <4 x i16> %b to <4 x i32>
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
uint32x4_t test_vsubl_u16(uint16x4_t a, uint16x4_t b) {
  return vsubl_u16(a, b);
}

// CHECK-LABEL: @test_vsubl_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <2 x i32> %a to <2 x i64>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I4_I:%.*]] = zext <2 x i32> %b to <2 x i64>
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> [[VMOVL_I_I]], [[VMOVL_I4_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
uint64x2_t test_vsubl_u32(uint32x2_t a, uint32x2_t b) {
  return vsubl_u32(a, b);
}

// CHECK-LABEL: @test_vsubw_s8(
// CHECK:   [[VMOVL_I_I:%.*]] = sext <8 x i8> %b to <8 x i16>
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[VMOVL_I_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
int16x8_t test_vsubw_s8(int16x8_t a, int8x8_t b) {
  return vsubw_s8(a, b);
}

// CHECK-LABEL: @test_vsubw_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <4 x i16> %b to <4 x i32>
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[VMOVL_I_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
int32x4_t test_vsubw_s16(int32x4_t a, int16x4_t b) {
  return vsubw_s16(a, b);
}

// CHECK-LABEL: @test_vsubw_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = sext <2 x i32> %b to <2 x i64>
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, [[VMOVL_I_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
int64x2_t test_vsubw_s32(int64x2_t a, int32x2_t b) {
  return vsubw_s32(a, b);
}

// CHECK-LABEL: @test_vsubw_u8(
// CHECK:   [[VMOVL_I_I:%.*]] = zext <8 x i8> %b to <8 x i16>
// CHECK:   [[SUB_I:%.*]] = sub <8 x i16> %a, [[VMOVL_I_I]]
// CHECK:   ret <8 x i16> [[SUB_I]]
uint16x8_t test_vsubw_u8(uint16x8_t a, uint8x8_t b) {
  return vsubw_u8(a, b);
}

// CHECK-LABEL: @test_vsubw_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <4 x i16> %b to <4 x i32>
// CHECK:   [[SUB_I:%.*]] = sub <4 x i32> %a, [[VMOVL_I_I]]
// CHECK:   ret <4 x i32> [[SUB_I]]
uint32x4_t test_vsubw_u16(uint32x4_t a, uint16x4_t b) {
  return vsubw_u16(a, b);
}

// CHECK-LABEL: @test_vsubw_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VMOVL_I_I:%.*]] = zext <2 x i32> %b to <2 x i64>
// CHECK:   [[SUB_I:%.*]] = sub <2 x i64> %a, [[VMOVL_I_I]]
// CHECK:   ret <2 x i64> [[SUB_I]]
uint64x2_t test_vsubw_u32(uint64x2_t a, uint32x2_t b) {
  return vsubw_u32(a, b);
}

// CHECK-LABEL: @test_vtbl1_u8(
// CHECK:   [[VTBL1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl1(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL1_I]]
uint8x8_t test_vtbl1_u8(uint8x8_t a, uint8x8_t b) {
  return vtbl1_u8(a, b);
}

// CHECK-LABEL: @test_vtbl1_s8(
// CHECK:   [[VTBL1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl1(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL1_I]]
int8x8_t test_vtbl1_s8(int8x8_t a, int8x8_t b) {
  return vtbl1_s8(a, b);
}

// CHECK-LABEL: @test_vtbl1_p8(
// CHECK:   [[VTBL1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl1(<8 x i8> %a, <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL1_I]]
poly8x8_t test_vtbl1_p8(poly8x8_t a, uint8x8_t b) {
  return vtbl1_p8(a, b);
}

// CHECK-LABEL: @test_vtbl2_u8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [2 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [2 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [2 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[VTBL2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl2(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL2_I]]
uint8x8_t test_vtbl2_u8(uint8x8x2_t a, uint8x8_t b) {
  return vtbl2_u8(a, b);
}

// CHECK-LABEL: @test_vtbl2_s8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [2 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [2 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [2 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[VTBL2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl2(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL2_I]]
int8x8_t test_vtbl2_s8(int8x8x2_t a, int8x8_t b) {
  return vtbl2_s8(a, b);
}

// CHECK-LABEL: @test_vtbl2_p8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [2 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [2 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [2 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[VTBL2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl2(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL2_I]]
poly8x8_t test_vtbl2_p8(poly8x8x2_t a, uint8x8_t b) {
  return vtbl2_p8(a, b);
}

// CHECK-LABEL: @test_vtbl3_u8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [3 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [3 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [3 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[VTBL3_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl3(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL3_I]]
uint8x8_t test_vtbl3_u8(uint8x8x3_t a, uint8x8_t b) {
  return vtbl3_u8(a, b);
}

// CHECK-LABEL: @test_vtbl3_s8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [3 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [3 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [3 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[VTBL3_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl3(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL3_I]]
int8x8_t test_vtbl3_s8(int8x8x3_t a, int8x8_t b) {
  return vtbl3_s8(a, b);
}

// CHECK-LABEL: @test_vtbl3_p8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [3 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [3 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [3 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[VTBL3_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl3(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL3_I]]
poly8x8_t test_vtbl3_p8(poly8x8x3_t a, uint8x8_t b) {
  return vtbl3_p8(a, b);
}

// CHECK-LABEL: @test_vtbl4_u8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [4 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [4 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [4 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[ARRAYIDX6_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6_I]], align 8
// CHECK:   [[VTBL4_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl4(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> [[TMP7]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL4_I]]
uint8x8_t test_vtbl4_u8(uint8x8x4_t a, uint8x8_t b) {
  return vtbl4_u8(a, b);
}

// CHECK-LABEL: @test_vtbl4_s8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [4 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [4 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [4 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[ARRAYIDX6_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6_I]], align 8
// CHECK:   [[VTBL4_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl4(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> [[TMP7]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL4_I]]
int8x8_t test_vtbl4_s8(int8x8x4_t a, int8x8_t b) {
  return vtbl4_s8(a, b);
}

// CHECK-LABEL: @test_vtbl4_p8(
// CHECK:   [[__P0_I:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[A:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[A]], i32 0, i32 0
// CHECK:   store [4 x i64] [[A]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[A]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [4 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [4 x i64] [[TMP2]], ptr [[__P0_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P0_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[ARRAYIDX6_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P0_I]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6_I]], align 8
// CHECK:   [[VTBL4_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbl4(<8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> [[TMP7]], <8 x i8> %b)
// CHECK:   ret <8 x i8> [[VTBL4_I]]
poly8x8_t test_vtbl4_p8(poly8x8x4_t a, uint8x8_t b) {
  return vtbl4_p8(a, b);
}

// CHECK-LABEL: @test_vtbx1_u8(
// CHECK:   [[VTBX1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx1(<8 x i8> %a, <8 x i8> %b, <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX1_I]]
uint8x8_t test_vtbx1_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c) {
  return vtbx1_u8(a, b, c);
}

// CHECK-LABEL: @test_vtbx1_s8(
// CHECK:   [[VTBX1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx1(<8 x i8> %a, <8 x i8> %b, <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX1_I]]
int8x8_t test_vtbx1_s8(int8x8_t a, int8x8_t b, int8x8_t c) {
  return vtbx1_s8(a, b, c);
}

// CHECK-LABEL: @test_vtbx1_p8(
// CHECK:   [[VTBX1_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx1(<8 x i8> %a, <8 x i8> %b, <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX1_I]]
poly8x8_t test_vtbx1_p8(poly8x8_t a, poly8x8_t b, uint8x8_t c) {
  return vtbx1_p8(a, b, c);
}

// CHECK-LABEL: @test_vtbx2_u8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [2 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [2 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[VTBX2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx2(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX2_I]]
uint8x8_t test_vtbx2_u8(uint8x8_t a, uint8x8x2_t b, uint8x8_t c) {
  return vtbx2_u8(a, b, c);
}

// CHECK-LABEL: @test_vtbx2_s8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.int8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [2 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [2 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[VTBX2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx2(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX2_I]]
int8x8_t test_vtbx2_s8(int8x8_t a, int8x8x2_t b, int8x8_t c) {
  return vtbx2_s8(a, b, c);
}

// CHECK-LABEL: @test_vtbx2_p8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x2_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [2 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [2 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [2 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [2 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[VTBX2_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx2(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX2_I]]
poly8x8_t test_vtbx2_p8(poly8x8_t a, poly8x8x2_t b, uint8x8_t c) {
  return vtbx2_p8(a, b, c);
}

// CHECK-LABEL: @test_vtbx3_u8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.uint8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [3 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [3 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[VTBX3_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx3(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX3_I]]
uint8x8_t test_vtbx3_u8(uint8x8_t a, uint8x8x3_t b, uint8x8_t c) {
  return vtbx3_u8(a, b, c);
}

// CHECK-LABEL: @test_vtbx3_s8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.int8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [3 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [3 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[VTBX3_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx3(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX3_I]]
int8x8_t test_vtbx3_s8(int8x8_t a, int8x8x3_t b, int8x8_t c) {
  return vtbx3_s8(a, b, c);
}

// CHECK-LABEL: @test_vtbx3_p8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x3_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [3 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.poly8x8x3_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [3 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [3 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [3 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[VTBX3_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx3(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX3_I]]
poly8x8_t test_vtbx3_p8(poly8x8_t a, poly8x8x3_t b, uint8x8_t c) {
  return vtbx3_p8(a, b, c);
}

// CHECK-LABEL: @test_vtbx4_u8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.uint8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.uint8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [4 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [4 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[ARRAYIDX6_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6_I]], align 8
// CHECK:   [[VTBX4_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx4(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> [[TMP7]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX4_I]]
uint8x8_t test_vtbx4_u8(uint8x8_t a, uint8x8x4_t b, uint8x8_t c) {
  return vtbx4_u8(a, b, c);
}

// CHECK-LABEL: @test_vtbx4_s8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.int8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.int8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [4 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [4 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[ARRAYIDX6_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6_I]], align 8
// CHECK:   [[VTBX4_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx4(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> [[TMP7]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX4_I]]
int8x8_t test_vtbx4_s8(int8x8_t a, int8x8x4_t b, int8x8_t c) {
  return vtbx4_s8(a, b, c);
}

// CHECK-LABEL: @test_vtbx4_p8(
// CHECK:   [[__P1_I:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[B:%.*]] = alloca %struct.poly8x8x4_t, align 8
// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   store [4 x i64] [[B]].coerce, ptr [[COERCE_DIVE]], align 8
// CHECK:   [[COERCE_DIVE1:%.*]] = getelementptr inbounds %struct.poly8x8x4_t, ptr [[B]], i32 0, i32 0
// CHECK:   [[TMP2:%.*]] = load [4 x i64], ptr [[COERCE_DIVE1]], align 8
// CHECK:   store [4 x i64] [[TMP2]], ptr [[__P1_I]], align 8
// CHECK:   [[TMP4:%.*]] = load <8 x i8>, ptr [[__P1_I]], align 8
// CHECK:   [[ARRAYIDX2_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 1
// CHECK:   [[TMP5:%.*]] = load <8 x i8>, ptr [[ARRAYIDX2_I]], align 8
// CHECK:   [[ARRAYIDX4_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 2
// CHECK:   [[TMP6:%.*]] = load <8 x i8>, ptr [[ARRAYIDX4_I]], align 8
// CHECK:   [[ARRAYIDX6_I:%.*]] = getelementptr inbounds [4 x <8 x i8>], ptr [[__P1_I]], i32 0, i32 3
// CHECK:   [[TMP7:%.*]] = load <8 x i8>, ptr [[ARRAYIDX6_I]], align 8
// CHECK:   [[VTBX4_I:%.*]] = call <8 x i8> @llvm.arm.neon.vtbx4(<8 x i8> %a, <8 x i8> [[TMP4]], <8 x i8> [[TMP5]], <8 x i8> [[TMP6]], <8 x i8> [[TMP7]], <8 x i8> %c)
// CHECK:   ret <8 x i8> [[VTBX4_I]]
poly8x8_t test_vtbx4_p8(poly8x8_t a, poly8x8x4_t b, uint8x8_t c) {
  return vtbx4_p8(a, b, c);
}

// CHECK: @test_vtrn_s8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VTRN_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
// CHECK:   store <8 x i8> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
// CHECK:   store <8 x i8> [[VTRN1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
int8x8x2_t test_vtrn_s8(int8x8_t a, int8x8_t b) {
  return vtrn_s8(a, b);
}

// CHECK: @test_vtrn_s16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 4, i32 2, i32 6>
// CHECK:   store <4 x i16> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 1, i32 5, i32 3, i32 7>
// CHECK:   store <4 x i16> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int16x4x2_t test_vtrn_s16(int16x4_t a, int16x4_t b) {
  return vtrn_s16(a, b);
}

// CHECK: @test_vtrn_s32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x i32> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x i32> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int32x2x2_t test_vtrn_s32(int32x2_t a, int32x2_t b) {
  return vtrn_s32(a, b);
}

// CHECK: @test_vtrn_u8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VTRN_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
// CHECK:   store <8 x i8> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
// CHECK:   store <8 x i8> [[VTRN1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
uint8x8x2_t test_vtrn_u8(uint8x8_t a, uint8x8_t b) {
  return vtrn_u8(a, b);
}

// CHECK: @test_vtrn_u16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 4, i32 2, i32 6>
// CHECK:   store <4 x i16> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 1, i32 5, i32 3, i32 7>
// CHECK:   store <4 x i16> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint16x4x2_t test_vtrn_u16(uint16x4_t a, uint16x4_t b) {
  return vtrn_u16(a, b);
}

// CHECK: @test_vtrn_u32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x i32> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x i32> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint32x2x2_t test_vtrn_u32(uint32x2_t a, uint32x2_t b) {
  return vtrn_u32(a, b);
}

// CHECK: @test_vtrn_f32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x float> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x float>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x float> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
float32x2x2_t test_vtrn_f32(float32x2_t a, float32x2_t b) {
  return vtrn_f32(a, b);
}

// CHECK: @test_vtrn_p8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VTRN_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
// CHECK:   store <8 x i8> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
// CHECK:   store <8 x i8> [[VTRN1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
poly8x8x2_t test_vtrn_p8(poly8x8_t a, poly8x8_t b) {
  return vtrn_p8(a, b);
}

// CHECK: @test_vtrn_p16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 4, i32 2, i32 6>
// CHECK:   store <4 x i16> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 1, i32 5, i32 3, i32 7>
// CHECK:   store <4 x i16> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
poly16x4x2_t test_vtrn_p16(poly16x4_t a, poly16x4_t b) {
  return vtrn_p16(a, b);
}

// CHECK: @test_vtrnq_s8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VTRN_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
// CHECK:   store <16 x i8> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
// CHECK:   store <16 x i8> [[VTRN1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
int8x16x2_t test_vtrnq_s8(int8x16_t a, int8x16_t b) {
  return vtrnq_s8(a, b);
}

// CHECK: @test_vtrnq_s16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
// CHECK:   store <8 x i16> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
// CHECK:   store <8 x i16> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int16x8x2_t test_vtrnq_s16(int16x8_t a, int16x8_t b) {
  return vtrnq_s16(a, b);
}

// CHECK: @test_vtrnq_s32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 0, i32 4, i32 2, i32 6>
// CHECK:   store <4 x i32> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 1, i32 5, i32 3, i32 7>
// CHECK:   store <4 x i32> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int32x4x2_t test_vtrnq_s32(int32x4_t a, int32x4_t b) {
  return vtrnq_s32(a, b);
}

// CHECK: @test_vtrnq_u8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VTRN_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
// CHECK:   store <16 x i8> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
// CHECK:   store <16 x i8> [[VTRN1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
uint8x16x2_t test_vtrnq_u8(uint8x16_t a, uint8x16_t b) {
  return vtrnq_u8(a, b);
}

// CHECK: @test_vtrnq_u16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
// CHECK:   store <8 x i16> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
// CHECK:   store <8 x i16> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint16x8x2_t test_vtrnq_u16(uint16x8_t a, uint16x8_t b) {
  return vtrnq_u16(a, b);
}

// CHECK: @test_vtrnq_u32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 0, i32 4, i32 2, i32 6>
// CHECK:   store <4 x i32> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 1, i32 5, i32 3, i32 7>
// CHECK:   store <4 x i32> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint32x4x2_t test_vtrnq_u32(uint32x4_t a, uint32x4_t b) {
  return vtrnq_u32(a, b);
}

// CHECK: @test_vtrnq_f32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %b, <4 x i32> <i32 0, i32 4, i32 2, i32 6>
// CHECK:   store <4 x float> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x float>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %b, <4 x i32> <i32 1, i32 5, i32 3, i32 7>
// CHECK:   store <4 x float> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
float32x4x2_t test_vtrnq_f32(float32x4_t a, float32x4_t b) {
  return vtrnq_f32(a, b);
}

// CHECK: @test_vtrnq_p8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VTRN_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
// CHECK:   store <16 x i8> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
// CHECK:   store <16 x i8> [[VTRN1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
poly8x16x2_t test_vtrnq_p8(poly8x16_t a, poly8x16_t b) {
  return vtrnq_p8(a, b);
}

// CHECK: @test_vtrnq_p16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VTRN_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
// CHECK:   store <8 x i16> [[VTRN_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VTRN1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
// CHECK:   store <8 x i16> [[VTRN1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
poly16x8x2_t test_vtrnq_p16(poly16x8_t a, poly16x8_t b) {
  return vtrnq_p16(a, b);
}

// CHECK-LABEL: @test_vtst_s8(
// CHECK:   [[TMP0:%.*]] = and <8 x i8> %a, %b
// CHECK:   [[TMP1:%.*]] = icmp ne <8 x i8> [[TMP0]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <8 x i1> [[TMP1]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VTST_I]]
uint8x8_t test_vtst_s8(int8x8_t a, int8x8_t b) {
  return vtst_s8(a, b);
}

// CHECK-LABEL: @test_vtst_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = and <4 x i16> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <4 x i16> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <4 x i1> [[TMP3]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VTST_I]]
uint16x4_t test_vtst_s16(int16x4_t a, int16x4_t b) {
  return vtst_s16(a, b);
}

// CHECK-LABEL: @test_vtst_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = and <2 x i32> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <2 x i32> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <2 x i1> [[TMP3]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VTST_I]]
uint32x2_t test_vtst_s32(int32x2_t a, int32x2_t b) {
  return vtst_s32(a, b);
}

// CHECK-LABEL: @test_vtst_u8(
// CHECK:   [[TMP0:%.*]] = and <8 x i8> %a, %b
// CHECK:   [[TMP1:%.*]] = icmp ne <8 x i8> [[TMP0]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <8 x i1> [[TMP1]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VTST_I]]
uint8x8_t test_vtst_u8(uint8x8_t a, uint8x8_t b) {
  return vtst_u8(a, b);
}

// CHECK-LABEL: @test_vtst_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = and <4 x i16> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <4 x i16> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <4 x i1> [[TMP3]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VTST_I]]
uint16x4_t test_vtst_u16(uint16x4_t a, uint16x4_t b) {
  return vtst_u16(a, b);
}

// CHECK-LABEL: @test_vtst_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = and <2 x i32> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <2 x i32> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <2 x i1> [[TMP3]] to <2 x i32>
// CHECK:   ret <2 x i32> [[VTST_I]]
uint32x2_t test_vtst_u32(uint32x2_t a, uint32x2_t b) {
  return vtst_u32(a, b);
}

// CHECK-LABEL: @test_vtst_p8(
// CHECK:   [[TMP0:%.*]] = and <8 x i8> %a, %b
// CHECK:   [[TMP1:%.*]] = icmp ne <8 x i8> [[TMP0]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <8 x i1> [[TMP1]] to <8 x i8>
// CHECK:   ret <8 x i8> [[VTST_I]]
uint8x8_t test_vtst_p8(poly8x8_t a, poly8x8_t b) {
  return vtst_p8(a, b);
}

// CHECK-LABEL: @test_vtst_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[TMP2:%.*]] = and <4 x i16> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <4 x i16> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <4 x i1> [[TMP3]] to <4 x i16>
// CHECK:   ret <4 x i16> [[VTST_I]]
uint16x4_t test_vtst_p16(poly16x4_t a, poly16x4_t b) {
  return vtst_p16(a, b);
}

// CHECK-LABEL: @test_vtstq_s8(
// CHECK:   [[TMP0:%.*]] = and <16 x i8> %a, %b
// CHECK:   [[TMP1:%.*]] = icmp ne <16 x i8> [[TMP0]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <16 x i1> [[TMP1]] to <16 x i8>
// CHECK:   ret <16 x i8> [[VTST_I]]
uint8x16_t test_vtstq_s8(int8x16_t a, int8x16_t b) {
  return vtstq_s8(a, b);
}

// CHECK-LABEL: @test_vtstq_s16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = and <8 x i16> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <8 x i16> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <8 x i1> [[TMP3]] to <8 x i16>
// CHECK:   ret <8 x i16> [[VTST_I]]
uint16x8_t test_vtstq_s16(int16x8_t a, int16x8_t b) {
  return vtstq_s16(a, b);
}

// CHECK-LABEL: @test_vtstq_s32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = and <4 x i32> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <4 x i32> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <4 x i1> [[TMP3]] to <4 x i32>
// CHECK:   ret <4 x i32> [[VTST_I]]
uint32x4_t test_vtstq_s32(int32x4_t a, int32x4_t b) {
  return vtstq_s32(a, b);
}

// CHECK-LABEL: @test_vtstq_u8(
// CHECK:   [[TMP0:%.*]] = and <16 x i8> %a, %b
// CHECK:   [[TMP1:%.*]] = icmp ne <16 x i8> [[TMP0]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <16 x i1> [[TMP1]] to <16 x i8>
// CHECK:   ret <16 x i8> [[VTST_I]]
uint8x16_t test_vtstq_u8(uint8x16_t a, uint8x16_t b) {
  return vtstq_u8(a, b);
}

// CHECK-LABEL: @test_vtstq_u16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = and <8 x i16> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <8 x i16> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <8 x i1> [[TMP3]] to <8 x i16>
// CHECK:   ret <8 x i16> [[VTST_I]]
uint16x8_t test_vtstq_u16(uint16x8_t a, uint16x8_t b) {
  return vtstq_u16(a, b);
}

// CHECK-LABEL: @test_vtstq_u32(
// CHECK:   [[TMP0:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = and <4 x i32> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <4 x i32> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <4 x i1> [[TMP3]] to <4 x i32>
// CHECK:   ret <4 x i32> [[VTST_I]]
uint32x4_t test_vtstq_u32(uint32x4_t a, uint32x4_t b) {
  return vtstq_u32(a, b);
}

// CHECK-LABEL: @test_vtstq_p8(
// CHECK:   [[TMP0:%.*]] = and <16 x i8> %a, %b
// CHECK:   [[TMP1:%.*]] = icmp ne <16 x i8> [[TMP0]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <16 x i1> [[TMP1]] to <16 x i8>
// CHECK:   ret <16 x i8> [[VTST_I]]
uint8x16_t test_vtstq_p8(poly8x16_t a, poly8x16_t b) {
  return vtstq_p8(a, b);
}

// CHECK-LABEL: @test_vtstq_p16(
// CHECK:   [[TMP0:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[TMP2:%.*]] = and <8 x i16> %a, %b
// CHECK:   [[TMP3:%.*]] = icmp ne <8 x i16> [[TMP2]], zeroinitializer
// CHECK:   [[VTST_I:%.*]] = sext <8 x i1> [[TMP3]] to <8 x i16>
// CHECK:   ret <8 x i16> [[VTST_I]]
uint16x8_t test_vtstq_p16(poly16x8_t a, poly16x8_t b) {
  return vtstq_p16(a, b);
}

// CHECK: @test_vuzp_s8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VUZP_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK:   store <8 x i8> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK:   store <8 x i8> [[VUZP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
int8x8x2_t test_vuzp_s8(int8x8_t a, int8x8_t b) {
  return vuzp_s8(a, b);
}

// CHECK: @test_vuzp_s16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK:   store <4 x i16> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK:   store <4 x i16> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int16x4x2_t test_vuzp_s16(int16x4_t a, int16x4_t b) {
  return vuzp_s16(a, b);
}

// CHECK: @test_vuzp_s32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x i32> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x i32> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int32x2x2_t test_vuzp_s32(int32x2_t a, int32x2_t b) {
  return vuzp_s32(a, b);
}

// CHECK: @test_vuzp_u8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VUZP_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK:   store <8 x i8> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK:   store <8 x i8> [[VUZP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
uint8x8x2_t test_vuzp_u8(uint8x8_t a, uint8x8_t b) {
  return vuzp_u8(a, b);
}

// CHECK: @test_vuzp_u16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK:   store <4 x i16> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK:   store <4 x i16> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint16x4x2_t test_vuzp_u16(uint16x4_t a, uint16x4_t b) {
  return vuzp_u16(a, b);
}

// CHECK: @test_vuzp_u32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x i32> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x i32> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint32x2x2_t test_vuzp_u32(uint32x2_t a, uint32x2_t b) {
  return vuzp_u32(a, b);
}

// CHECK: @test_vuzp_f32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x float> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x float>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x float> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
float32x2x2_t test_vuzp_f32(float32x2_t a, float32x2_t b) {
  return vuzp_f32(a, b);
}

// CHECK: @test_vuzp_p8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VUZP_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK:   store <8 x i8> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK:   store <8 x i8> [[VUZP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
poly8x8x2_t test_vuzp_p8(poly8x8_t a, poly8x8_t b) {
  return vuzp_p8(a, b);
}

// CHECK: @test_vuzp_p16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK:   store <4 x i16> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK:   store <4 x i16> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
poly16x4x2_t test_vuzp_p16(poly16x4_t a, poly16x4_t b) {
  return vuzp_p16(a, b);
}

// CHECK: @test_vuzpq_s8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VUZP_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
// CHECK:   store <16 x i8> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
// CHECK:   store <16 x i8> [[VUZP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
int8x16x2_t test_vuzpq_s8(int8x16_t a, int8x16_t b) {
  return vuzpq_s8(a, b);
}

// CHECK: @test_vuzpq_s16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK:   store <8 x i16> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK:   store <8 x i16> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int16x8x2_t test_vuzpq_s16(int16x8_t a, int16x8_t b) {
  return vuzpq_s16(a, b);
}

// CHECK: @test_vuzpq_s32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK:   store <4 x i32> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK:   store <4 x i32> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int32x4x2_t test_vuzpq_s32(int32x4_t a, int32x4_t b) {
  return vuzpq_s32(a, b);
}

// CHECK: @test_vuzpq_u8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VUZP_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
// CHECK:   store <16 x i8> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
// CHECK:   store <16 x i8> [[VUZP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
uint8x16x2_t test_vuzpq_u8(uint8x16_t a, uint8x16_t b) {
  return vuzpq_u8(a, b);
}

// CHECK: @test_vuzpq_u16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK:   store <8 x i16> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK:   store <8 x i16> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint16x8x2_t test_vuzpq_u16(uint16x8_t a, uint16x8_t b) {
  return vuzpq_u16(a, b);
}

// CHECK: @test_vuzpq_u32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK:   store <4 x i32> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK:   store <4 x i32> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint32x4x2_t test_vuzpq_u32(uint32x4_t a, uint32x4_t b) {
  return vuzpq_u32(a, b);
}

// CHECK: @test_vuzpq_f32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %b, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK:   store <4 x float> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x float>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %b, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK:   store <4 x float> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
float32x4x2_t test_vuzpq_f32(float32x4_t a, float32x4_t b) {
  return vuzpq_f32(a, b);
}

// CHECK: @test_vuzpq_p8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VUZP_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
// CHECK:   store <16 x i8> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
// CHECK:   store <16 x i8> [[VUZP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
poly8x16x2_t test_vuzpq_p8(poly8x16_t a, poly8x16_t b) {
  return vuzpq_p8(a, b);
}

// CHECK: @test_vuzpq_p16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VUZP_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK:   store <8 x i16> [[VUZP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VUZP1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK:   store <8 x i16> [[VUZP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
poly16x8x2_t test_vuzpq_p16(poly16x8_t a, poly16x8_t b) {
  return vuzpq_p16(a, b);
}

// CHECK: @test_vzip_s8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VZIP_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
// CHECK:   store <8 x i8> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
// CHECK:   store <8 x i8> [[VZIP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
int8x8x2_t test_vzip_s8(int8x8_t a, int8x8_t b) {
  return vzip_s8(a, b);
}

// CHECK: @test_vzip_s16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 4, i32 1, i32 5>
// CHECK:   store <4 x i16> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 2, i32 6, i32 3, i32 7>
// CHECK:   store <4 x i16> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int16x4x2_t test_vzip_s16(int16x4_t a, int16x4_t b) {
  return vzip_s16(a, b);
}

// CHECK: @test_vzip_s32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x i32> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x i32> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int32x2x2_t test_vzip_s32(int32x2_t a, int32x2_t b) {
  return vzip_s32(a, b);
}

// CHECK: @test_vzip_u8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VZIP_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
// CHECK:   store <8 x i8> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
// CHECK:   store <8 x i8> [[VZIP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
uint8x8x2_t test_vzip_u8(uint8x8_t a, uint8x8_t b) {
  return vzip_u8(a, b);
}

// CHECK: @test_vzip_u16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 4, i32 1, i32 5>
// CHECK:   store <4 x i16> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 2, i32 6, i32 3, i32 7>
// CHECK:   store <4 x i16> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint16x4x2_t test_vzip_u16(uint16x4_t a, uint16x4_t b) {
  return vzip_u16(a, b);
}

// CHECK: @test_vzip_u32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x i32> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x i32> %b to <8 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x i32> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <2 x i32> %a, <2 x i32> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x i32> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint32x2x2_t test_vzip_u32(uint32x2_t a, uint32x2_t b) {
  return vzip_u32(a, b);
}

// CHECK: @test_vzip_f32({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <2 x float> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <2 x float> %b to <8 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %b, <2 x i32> <i32 0, i32 2>
// CHECK:   store <2 x float> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <2 x float>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <2 x float> %a, <2 x float> %b, <2 x i32> <i32 1, i32 3>
// CHECK:   store <2 x float> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
float32x2x2_t test_vzip_f32(float32x2_t a, float32x2_t b) {
  return vzip_f32(a, b);
}

// CHECK: @test_vzip_p8({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VZIP_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
// CHECK:   store <8 x i8> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <8 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <8 x i8> %a, <8 x i8> %b, <8 x i32> <i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
// CHECK:   store <8 x i8> [[VZIP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
poly8x8x2_t test_vzip_p8(poly8x8_t a, poly8x8_t b) {
  return vzip_p8(a, b);
}

// CHECK: @test_vzip_p16({{.*}} sret({{.*}}) align 8 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i16> %a to <8 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i16> %b to <8 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 0, i32 4, i32 1, i32 5>
// CHECK:   store <4 x i16> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <4 x i16> %a, <4 x i16> %b, <4 x i32> <i32 2, i32 6, i32 3, i32 7>
// CHECK:   store <4 x i16> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
poly16x4x2_t test_vzip_p16(poly16x4_t a, poly16x4_t b) {
  return vzip_p16(a, b);
}

// CHECK: @test_vzipq_s8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VZIP_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
// CHECK:   store <16 x i8> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
// CHECK:   store <16 x i8> [[VZIP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
int8x16x2_t test_vzipq_s8(int8x16_t a, int8x16_t b) {
  return vzipq_s8(a, b);
}

// CHECK: @test_vzipq_s16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
// CHECK:   store <8 x i16> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
// CHECK:   store <8 x i16> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int16x8x2_t test_vzipq_s16(int16x8_t a, int16x8_t b) {
  return vzipq_s16(a, b);
}

// CHECK: @test_vzipq_s32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 0, i32 4, i32 1, i32 5>
// CHECK:   store <4 x i32> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 2, i32 6, i32 3, i32 7>
// CHECK:   store <4 x i32> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
int32x4x2_t test_vzipq_s32(int32x4_t a, int32x4_t b) {
  return vzipq_s32(a, b);
}

// CHECK: @test_vzipq_u8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VZIP_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
// CHECK:   store <16 x i8> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
// CHECK:   store <16 x i8> [[VZIP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
uint8x16x2_t test_vzipq_u8(uint8x16_t a, uint8x16_t b) {
  return vzipq_u8(a, b);
}

// CHECK: @test_vzipq_u16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
// CHECK:   store <8 x i16> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
// CHECK:   store <8 x i16> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint16x8x2_t test_vzipq_u16(uint16x8_t a, uint16x8_t b) {
  return vzipq_u16(a, b);
}

// CHECK: @test_vzipq_u32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x i32> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x i32> %b to <16 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 0, i32 4, i32 1, i32 5>
// CHECK:   store <4 x i32> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x i32>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <4 x i32> %a, <4 x i32> %b, <4 x i32> <i32 2, i32 6, i32 3, i32 7>
// CHECK:   store <4 x i32> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
uint32x4x2_t test_vzipq_u32(uint32x4_t a, uint32x4_t b) {
  return vzipq_u32(a, b);
}

// CHECK: @test_vzipq_f32({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <4 x float> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <4 x float> %b to <16 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %b, <4 x i32> <i32 0, i32 4, i32 1, i32 5>
// CHECK:   store <4 x float> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <4 x float>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <4 x float> %a, <4 x float> %b, <4 x i32> <i32 2, i32 6, i32 3, i32 7>
// CHECK:   store <4 x float> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
float32x4x2_t test_vzipq_f32(float32x4_t a, float32x4_t b) {
  return vzipq_f32(a, b);
}

// CHECK: @test_vzipq_p8({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[VZIP_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
// CHECK:   store <16 x i8> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP2:%.*]] = getelementptr inbounds <16 x i8>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <16 x i8> %a, <16 x i8> %b, <16 x i32> <i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
// CHECK:   store <16 x i8> [[VZIP1_I]], ptr [[TMP2]], align 4, !alias.scope
// CHECK:   ret void
poly8x16x2_t test_vzipq_p8(poly8x16_t a, poly8x16_t b) {
  return vzipq_p8(a, b);
}

// CHECK: @test_vzipq_p16({{.*}} sret({{.*}}) align 16 [[AGG_RESULT:%[0-9a-zA-Z.]+]],
// CHECK:   [[TMP1:%.*]] = bitcast <8 x i16> %a to <16 x i8>
// CHECK:   [[TMP2:%.*]] = bitcast <8 x i16> %b to <16 x i8>
// CHECK:   [[VZIP_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
// CHECK:   store <8 x i16> [[VZIP_I]], ptr [[AGG_RESULT]], align 4, !alias.scope
// CHECK:   [[TMP4:%.*]] = getelementptr inbounds <8 x i16>, ptr [[AGG_RESULT]], i32 1
// CHECK:   [[VZIP1_I:%.*]] = shufflevector <8 x i16> %a, <8 x i16> %b, <8 x i32> <i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
// CHECK:   store <8 x i16> [[VZIP1_I]], ptr [[TMP4]], align 4, !alias.scope
// CHECK:   ret void
poly16x8x2_t test_vzipq_p16(poly16x8_t a, poly16x8_t b) {
  return vzipq_p16(a, b);
}
