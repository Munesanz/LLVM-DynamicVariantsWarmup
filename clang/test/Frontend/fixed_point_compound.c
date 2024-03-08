// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -ffixed-point -triple x86_64-unknown-linux-gnu -S -emit-llvm %s -o - | FileCheck %s --check-prefixes=CHECK,SIGNED
// RUN: %clang_cc1 -ffixed-point -triple x86_64-unknown-linux-gnu -fpadding-on-unsigned-fixed-point -S -emit-llvm %s -o - | FileCheck %s --check-prefixes=CHECK,UNSIGNED

short _Fract shf;
_Accum a;
unsigned _Fract uf;
unsigned long _Accum ula;

_Sat short _Fract sshf;
_Sat _Accum sa;
_Sat unsigned _Fract suf;
_Sat unsigned long _Accum sula;

int i;
unsigned int u;
signed char c;

float fl;


// CHECK-LABEL: @add_shfa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i8, ptr @shf, align 1
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i8 [[TMP1]] to i32
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i32 [[RESIZE]], 8
// CHECK-NEXT:    [[TMP2:%.*]] = add i32 [[UPSCALE]], [[TMP0]]
// CHECK-NEXT:    [[DOWNSCALE:%.*]] = ashr i32 [[TMP2]], 8
// CHECK-NEXT:    [[RESIZE1:%.*]] = trunc i32 [[DOWNSCALE]] to i8
// CHECK-NEXT:    store i8 [[RESIZE1]], ptr @shf, align 1
// CHECK-NEXT:    ret void
//
void add_shfa(void) {
  shf += a;
}

// SIGNED-LABEL: @add_auf(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// SIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// SIGNED-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i33
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i33 [[RESIZE]], 1
// SIGNED-NEXT:    [[RESIZE1:%.*]] = zext i16 [[TMP0]] to i33
// SIGNED-NEXT:    [[TMP2:%.*]] = add i33 [[UPSCALE]], [[RESIZE1]]
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i33 [[TMP2]], 1
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i33 [[DOWNSCALE]] to i32
// SIGNED-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @add_auf(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = zext i16 [[TMP0]] to i32
// UNSIGNED-NEXT:    [[TMP2:%.*]] = add i32 [[TMP1]], [[RESIZE]]
// UNSIGNED-NEXT:    store i32 [[TMP2]], ptr @a, align 4
// UNSIGNED-NEXT:    ret void
//
void add_auf(void) {
  a += uf;
}

// CHECK-LABEL: @add_ufula(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i64, ptr @ula, align 8
// CHECK-NEXT:    [[TMP1:%.*]] = load i16, ptr @uf, align 2
// CHECK-NEXT:    [[RESIZE:%.*]] = zext i16 [[TMP1]] to i64
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i64 [[RESIZE]], 16
// CHECK-NEXT:    [[TMP2:%.*]] = add i64 [[UPSCALE]], [[TMP0]]
// CHECK-NEXT:    [[DOWNSCALE:%.*]] = lshr i64 [[TMP2]], 16
// CHECK-NEXT:    [[RESIZE1:%.*]] = trunc i64 [[DOWNSCALE]] to i16
// CHECK-NEXT:    store i16 [[RESIZE1]], ptr @uf, align 2
// CHECK-NEXT:    ret void
//
void add_ufula(void) {
  uf += ula;
}

// SIGNED-LABEL: @add_ulashf(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i8, ptr @shf, align 1
// SIGNED-NEXT:    [[TMP1:%.*]] = load i64, ptr @ula, align 8
// SIGNED-NEXT:    [[RESIZE:%.*]] = zext i64 [[TMP1]] to i65
// SIGNED-NEXT:    [[RESIZE1:%.*]] = sext i8 [[TMP0]] to i65
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i65 [[RESIZE1]], 25
// SIGNED-NEXT:    [[TMP2:%.*]] = add i65 [[RESIZE]], [[UPSCALE]]
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i65 [[TMP2]], 1
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i65 [[DOWNSCALE]] to i64
// SIGNED-NEXT:    [[UPSCALE3:%.*]] = shl i64 [[RESIZE2]], 1
// SIGNED-NEXT:    store i64 [[UPSCALE3]], ptr @ula, align 8
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @add_ulashf(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i8, ptr @shf, align 1
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i64, ptr @ula, align 8
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = sext i8 [[TMP0]] to i64
// UNSIGNED-NEXT:    [[UPSCALE:%.*]] = shl i64 [[RESIZE]], 24
// UNSIGNED-NEXT:    [[TMP2:%.*]] = add i64 [[TMP1]], [[UPSCALE]]
// UNSIGNED-NEXT:    store i64 [[TMP2]], ptr @ula, align 8
// UNSIGNED-NEXT:    ret void
//
void add_ulashf(void) {
  ula += shf;
}

// SIGNED-LABEL: @add_ufshf(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i8, ptr @shf, align 1
// SIGNED-NEXT:    [[TMP1:%.*]] = load i16, ptr @uf, align 2
// SIGNED-NEXT:    [[RESIZE:%.*]] = zext i16 [[TMP1]] to i17
// SIGNED-NEXT:    [[RESIZE1:%.*]] = sext i8 [[TMP0]] to i17
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i17 [[RESIZE1]], 9
// SIGNED-NEXT:    [[TMP2:%.*]] = add i17 [[RESIZE]], [[UPSCALE]]
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i17 [[TMP2]], 1
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i17 [[DOWNSCALE]] to i16
// SIGNED-NEXT:    [[UPSCALE3:%.*]] = shl i16 [[RESIZE2]], 1
// SIGNED-NEXT:    store i16 [[UPSCALE3]], ptr @uf, align 2
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @add_ufshf(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i8, ptr @shf, align 1
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i16, ptr @uf, align 2
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = sext i8 [[TMP0]] to i16
// UNSIGNED-NEXT:    [[UPSCALE:%.*]] = shl i16 [[RESIZE]], 8
// UNSIGNED-NEXT:    [[TMP2:%.*]] = add i16 [[TMP1]], [[UPSCALE]]
// UNSIGNED-NEXT:    store i16 [[TMP2]], ptr @uf, align 2
// UNSIGNED-NEXT:    ret void
//
void add_ufshf(void) {
  uf += shf;
}

// CHECK-LABEL: @add_ashf(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i8, ptr @shf, align 1
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i8 [[TMP0]] to i32
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i32 [[RESIZE]], 8
// CHECK-NEXT:    [[TMP2:%.*]] = add i32 [[TMP1]], [[UPSCALE]]
// CHECK-NEXT:    store i32 [[TMP2]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void add_ashf(void) {
  a += shf;
}

// CHECK-LABEL: @add_ai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i47
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE1]], 15
// CHECK-NEXT:    [[TMP2:%.*]] = add i47 [[RESIZE]], [[UPSCALE]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[TMP2]] to i32
// CHECK-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void add_ai(void) {
  a += i;
}

// CHECK-LABEL: @add_au(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @u, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i48
// CHECK-NEXT:    [[RESIZE1:%.*]] = zext i32 [[TMP0]] to i48
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i48 [[RESIZE1]], 15
// CHECK-NEXT:    [[TMP2:%.*]] = add i48 [[RESIZE]], [[UPSCALE]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i48 [[TMP2]] to i32
// CHECK-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void add_au(void) {
  a += u;
}

// SIGNED-LABEL: @add_ulai(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// SIGNED-NEXT:    [[TMP1:%.*]] = load i64, ptr @ula, align 8
// SIGNED-NEXT:    [[RESIZE:%.*]] = zext i64 [[TMP1]] to i65
// SIGNED-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i65
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i65 [[RESIZE1]], 32
// SIGNED-NEXT:    [[TMP2:%.*]] = add i65 [[RESIZE]], [[UPSCALE]]
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i65 [[TMP2]] to i64
// SIGNED-NEXT:    store i64 [[RESIZE2]], ptr @ula, align 8
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @add_ulai(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i64, ptr @ula, align 8
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP0]] to i64
// UNSIGNED-NEXT:    [[UPSCALE:%.*]] = shl i64 [[RESIZE]], 31
// UNSIGNED-NEXT:    [[TMP2:%.*]] = add i64 [[TMP1]], [[UPSCALE]]
// UNSIGNED-NEXT:    store i64 [[TMP2]], ptr @ula, align 8
// UNSIGNED-NEXT:    ret void
//
void add_ulai(void) {
  ula += i;
}

// SIGNED-LABEL: @add_iula(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i64, ptr @ula, align 8
// SIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @i, align 4
// SIGNED-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i65
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i65 [[RESIZE]], 32
// SIGNED-NEXT:    [[RESIZE1:%.*]] = zext i64 [[TMP0]] to i65
// SIGNED-NEXT:    [[TMP2:%.*]] = add i65 [[UPSCALE]], [[RESIZE1]]
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i65 [[TMP2]] to i64
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = lshr i64 [[RESIZE2]], 32
// SIGNED-NEXT:    [[RESIZE3:%.*]] = trunc i64 [[DOWNSCALE]] to i32
// SIGNED-NEXT:    store i32 [[RESIZE3]], ptr @i, align 4
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @add_iula(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i64, ptr @ula, align 8
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @i, align 4
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i64
// UNSIGNED-NEXT:    [[UPSCALE:%.*]] = shl i64 [[RESIZE]], 31
// UNSIGNED-NEXT:    [[TMP2:%.*]] = add i64 [[UPSCALE]], [[TMP0]]
// UNSIGNED-NEXT:    [[DOWNSCALE:%.*]] = lshr i64 [[TMP2]], 31
// UNSIGNED-NEXT:    [[RESIZE1:%.*]] = trunc i64 [[DOWNSCALE]] to i32
// UNSIGNED-NEXT:    store i32 [[RESIZE1]], ptr @i, align 4
// UNSIGNED-NEXT:    ret void
//
void add_iula(void) {
  i += ula;
}

// CHECK-LABEL: @add_ca(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i8, ptr @c, align 1
// CHECK-NEXT:    [[CONV:%.*]] = sext i8 [[TMP1]] to i32
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[CONV]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE]], 15
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[TMP2:%.*]] = add i47 [[UPSCALE]], [[RESIZE1]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[TMP2]] to i32
// CHECK-NEXT:    [[TMP3:%.*]] = icmp slt i32 [[RESIZE2]], 0
// CHECK-NEXT:    [[TMP4:%.*]] = add i32 [[RESIZE2]], 32767
// CHECK-NEXT:    [[TMP5:%.*]] = select i1 [[TMP3]], i32 [[TMP4]], i32 [[RESIZE2]]
// CHECK-NEXT:    [[DOWNSCALE:%.*]] = ashr i32 [[TMP5]], 15
// CHECK-NEXT:    [[RESIZE3:%.*]] = trunc i32 [[DOWNSCALE]] to i8
// CHECK-NEXT:    store i8 [[RESIZE3]], ptr @c, align 1
// CHECK-NEXT:    ret void
//
void add_ca(void) {
  c += a;
}

// CHECK-LABEL: @add_sai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @sa, align 4
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i47
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE1]], 15
// CHECK-NEXT:    [[TMP2:%.*]] = call i47 @llvm.sadd.sat.i47(i47 [[RESIZE]], i47 [[UPSCALE]])
// CHECK-NEXT:    [[TMP3:%.*]] = icmp sgt i47 [[TMP2]], 2147483647
// CHECK-NEXT:    [[SATMAX:%.*]] = select i1 [[TMP3]], i47 2147483647, i47 [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = icmp slt i47 [[SATMAX]], -2147483648
// CHECK-NEXT:    [[SATMIN:%.*]] = select i1 [[TMP4]], i47 -2147483648, i47 [[SATMAX]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[SATMIN]] to i32
// CHECK-NEXT:    store i32 [[RESIZE2]], ptr @sa, align 4
// CHECK-NEXT:    ret void
//
void add_sai(void) {
  sa += i;
}

// CHECK-LABEL: @add_csa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @sa, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i8, ptr @c, align 1
// CHECK-NEXT:    [[CONV:%.*]] = sext i8 [[TMP1]] to i32
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[CONV]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE]], 15
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[TMP2:%.*]] = call i47 @llvm.sadd.sat.i47(i47 [[UPSCALE]], i47 [[RESIZE1]])
// CHECK-NEXT:    [[TMP3:%.*]] = icmp sgt i47 [[TMP2]], 2147483647
// CHECK-NEXT:    [[SATMAX:%.*]] = select i1 [[TMP3]], i47 2147483647, i47 [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = icmp slt i47 [[SATMAX]], -2147483648
// CHECK-NEXT:    [[SATMIN:%.*]] = select i1 [[TMP4]], i47 -2147483648, i47 [[SATMAX]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[SATMIN]] to i32
// CHECK-NEXT:    [[TMP5:%.*]] = icmp slt i32 [[RESIZE2]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = add i32 [[RESIZE2]], 32767
// CHECK-NEXT:    [[TMP7:%.*]] = select i1 [[TMP5]], i32 [[TMP6]], i32 [[RESIZE2]]
// CHECK-NEXT:    [[DOWNSCALE:%.*]] = ashr i32 [[TMP7]], 15
// CHECK-NEXT:    [[RESIZE3:%.*]] = trunc i32 [[DOWNSCALE]] to i8
// CHECK-NEXT:    store i8 [[RESIZE3]], ptr @c, align 1
// CHECK-NEXT:    ret void
//
void add_csa(void) {
  c += sa;
}

// SIGNED-LABEL: @add_sulau(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i32, ptr @u, align 4
// SIGNED-NEXT:    [[TMP1:%.*]] = load i64, ptr @sula, align 8
// SIGNED-NEXT:    [[RESIZE:%.*]] = zext i32 [[TMP0]] to i64
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i64 [[RESIZE]], 32
// SIGNED-NEXT:    [[TMP2:%.*]] = call i64 @llvm.uadd.sat.i64(i64 [[TMP1]], i64 [[UPSCALE]])
// SIGNED-NEXT:    store i64 [[TMP2]], ptr @sula, align 8
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @add_sulau(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i32, ptr @u, align 4
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i64, ptr @sula, align 8
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = trunc i64 [[TMP1]] to i63
// UNSIGNED-NEXT:    [[RESIZE1:%.*]] = zext i32 [[TMP0]] to i63
// UNSIGNED-NEXT:    [[UPSCALE:%.*]] = shl i63 [[RESIZE1]], 31
// UNSIGNED-NEXT:    [[TMP2:%.*]] = call i63 @llvm.uadd.sat.i63(i63 [[RESIZE]], i63 [[UPSCALE]])
// UNSIGNED-NEXT:    [[RESIZE2:%.*]] = zext i63 [[TMP2]] to i64
// UNSIGNED-NEXT:    store i64 [[RESIZE2]], ptr @sula, align 8
// UNSIGNED-NEXT:    ret void
//
void add_sulau(void) {
  sula += u;
}

// SIGNED-LABEL: @add_sshsuf(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @suf, align 2
// SIGNED-NEXT:    [[TMP1:%.*]] = load i8, ptr @sshf, align 1
// SIGNED-NEXT:    [[RESIZE:%.*]] = sext i8 [[TMP1]] to i17
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i17 [[RESIZE]], 9
// SIGNED-NEXT:    [[RESIZE1:%.*]] = zext i16 [[TMP0]] to i17
// SIGNED-NEXT:    [[TMP2:%.*]] = call i17 @llvm.sadd.sat.i17(i17 [[UPSCALE]], i17 [[RESIZE1]])
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i17 [[TMP2]], 1
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i17 [[DOWNSCALE]] to i16
// SIGNED-NEXT:    [[DOWNSCALE3:%.*]] = ashr i16 [[RESIZE2]], 8
// SIGNED-NEXT:    [[RESIZE4:%.*]] = trunc i16 [[DOWNSCALE3]] to i8
// SIGNED-NEXT:    store i8 [[RESIZE4]], ptr @sshf, align 1
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @add_sshsuf(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @suf, align 2
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i8, ptr @sshf, align 1
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = sext i8 [[TMP1]] to i16
// UNSIGNED-NEXT:    [[UPSCALE:%.*]] = shl i16 [[RESIZE]], 8
// UNSIGNED-NEXT:    [[TMP2:%.*]] = call i16 @llvm.sadd.sat.i16(i16 [[UPSCALE]], i16 [[TMP0]])
// UNSIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i16 [[TMP2]], 8
// UNSIGNED-NEXT:    [[RESIZE1:%.*]] = trunc i16 [[DOWNSCALE]] to i8
// UNSIGNED-NEXT:    store i8 [[RESIZE1]], ptr @sshf, align 1
// UNSIGNED-NEXT:    ret void
//
void add_sshsuf(void) {
  sshf += suf;
}

// CHECK-LABEL: @add_afl(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load float, ptr @fl, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP2:%.*]] = sitofp i32 [[TMP1]] to float
// CHECK-NEXT:    [[TMP3:%.*]] = fmul float [[TMP2]], 0x3F00000000000000
// CHECK-NEXT:    [[ADD:%.*]] = fadd float [[TMP3]], [[TMP0]]
// CHECK-NEXT:    [[TMP4:%.*]] = fmul float [[ADD]], 3.276800e+04
// CHECK-NEXT:    [[TMP5:%.*]] = fptosi float [[TMP4]] to i32
// CHECK-NEXT:    store i32 [[TMP5]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void add_afl(void) {
  a += fl;
}

// CHECK-LABEL: @add_fla(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = sitofp i32 [[TMP0]] to float
// CHECK-NEXT:    [[TMP2:%.*]] = fmul float [[TMP1]], 0x3F00000000000000
// CHECK-NEXT:    [[TMP3:%.*]] = load float, ptr @fl, align 4
// CHECK-NEXT:    [[ADD:%.*]] = fadd float [[TMP3]], [[TMP2]]
// CHECK-NEXT:    store float [[ADD]], ptr @fl, align 4
// CHECK-NEXT:    ret void
//
void add_fla(void) {
  fl += a;
}

// CHECK-LABEL: @add_safl(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load float, ptr @fl, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @sa, align 4
// CHECK-NEXT:    [[TMP2:%.*]] = sitofp i32 [[TMP1]] to float
// CHECK-NEXT:    [[TMP3:%.*]] = fmul float [[TMP2]], 0x3F00000000000000
// CHECK-NEXT:    [[ADD:%.*]] = fadd float [[TMP3]], [[TMP0]]
// CHECK-NEXT:    [[TMP4:%.*]] = fmul float [[ADD]], 3.276800e+04
// CHECK-NEXT:    [[TMP5:%.*]] = call i32 @llvm.fptosi.sat.i32.f32(float [[TMP4]])
// CHECK-NEXT:    store i32 [[TMP5]], ptr @sa, align 4
// CHECK-NEXT:    ret void
//
void add_safl(void) {
  sa += fl;
}

// CHECK-LABEL: @add_flsa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @sa, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = sitofp i32 [[TMP0]] to float
// CHECK-NEXT:    [[TMP2:%.*]] = fmul float [[TMP1]], 0x3F00000000000000
// CHECK-NEXT:    [[TMP3:%.*]] = load float, ptr @fl, align 4
// CHECK-NEXT:    [[ADD:%.*]] = fadd float [[TMP3]], [[TMP2]]
// CHECK-NEXT:    store float [[ADD]], ptr @fl, align 4
// CHECK-NEXT:    ret void
//
void add_flsa(void) {
  fl += sa;
}

// Subtraction, multiplication and division should work about the same, so
// just make sure we can do them.

// SIGNED-LABEL: @sub_auf(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// SIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// SIGNED-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i33
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i33 [[RESIZE]], 1
// SIGNED-NEXT:    [[RESIZE1:%.*]] = zext i16 [[TMP0]] to i33
// SIGNED-NEXT:    [[TMP2:%.*]] = sub i33 [[UPSCALE]], [[RESIZE1]]
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i33 [[TMP2]], 1
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i33 [[DOWNSCALE]] to i32
// SIGNED-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @sub_auf(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = zext i16 [[TMP0]] to i32
// UNSIGNED-NEXT:    [[TMP2:%.*]] = sub i32 [[TMP1]], [[RESIZE]]
// UNSIGNED-NEXT:    store i32 [[TMP2]], ptr @a, align 4
// UNSIGNED-NEXT:    ret void
//
void sub_auf(void) {
  a -= uf;
}

// CHECK-LABEL: @sub_ai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i47
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE1]], 15
// CHECK-NEXT:    [[TMP2:%.*]] = sub i47 [[RESIZE]], [[UPSCALE]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[TMP2]] to i32
// CHECK-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void sub_ai(void) {
  a -= i;
}

// CHECK-LABEL: @sub_csa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @sa, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i8, ptr @c, align 1
// CHECK-NEXT:    [[CONV:%.*]] = sext i8 [[TMP1]] to i32
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[CONV]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE]], 15
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[TMP2:%.*]] = call i47 @llvm.ssub.sat.i47(i47 [[UPSCALE]], i47 [[RESIZE1]])
// CHECK-NEXT:    [[TMP3:%.*]] = icmp sgt i47 [[TMP2]], 2147483647
// CHECK-NEXT:    [[SATMAX:%.*]] = select i1 [[TMP3]], i47 2147483647, i47 [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = icmp slt i47 [[SATMAX]], -2147483648
// CHECK-NEXT:    [[SATMIN:%.*]] = select i1 [[TMP4]], i47 -2147483648, i47 [[SATMAX]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[SATMIN]] to i32
// CHECK-NEXT:    [[TMP5:%.*]] = icmp slt i32 [[RESIZE2]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = add i32 [[RESIZE2]], 32767
// CHECK-NEXT:    [[TMP7:%.*]] = select i1 [[TMP5]], i32 [[TMP6]], i32 [[RESIZE2]]
// CHECK-NEXT:    [[DOWNSCALE:%.*]] = ashr i32 [[TMP7]], 15
// CHECK-NEXT:    [[RESIZE3:%.*]] = trunc i32 [[DOWNSCALE]] to i8
// CHECK-NEXT:    store i8 [[RESIZE3]], ptr @c, align 1
// CHECK-NEXT:    ret void
//
void sub_csa(void) {
  c -= sa;
}

// CHECK-LABEL: @sub_afl(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load float, ptr @fl, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP2:%.*]] = sitofp i32 [[TMP1]] to float
// CHECK-NEXT:    [[TMP3:%.*]] = fmul float [[TMP2]], 0x3F00000000000000
// CHECK-NEXT:    [[SUB:%.*]] = fsub float [[TMP3]], [[TMP0]]
// CHECK-NEXT:    [[TMP4:%.*]] = fmul float [[SUB]], 3.276800e+04
// CHECK-NEXT:    [[TMP5:%.*]] = fptosi float [[TMP4]] to i32
// CHECK-NEXT:    store i32 [[TMP5]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void sub_afl(void) {
  a -= fl;
}


// SIGNED-LABEL: @mul_auf(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// SIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// SIGNED-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i33
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i33 [[RESIZE]], 1
// SIGNED-NEXT:    [[RESIZE1:%.*]] = zext i16 [[TMP0]] to i33
// SIGNED-NEXT:    [[TMP2:%.*]] = call i33 @llvm.smul.fix.i33(i33 [[UPSCALE]], i33 [[RESIZE1]], i32 16)
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i33 [[TMP2]], 1
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i33 [[DOWNSCALE]] to i32
// SIGNED-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @mul_auf(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = zext i16 [[TMP0]] to i32
// UNSIGNED-NEXT:    [[TMP2:%.*]] = call i32 @llvm.smul.fix.i32(i32 [[TMP1]], i32 [[RESIZE]], i32 15)
// UNSIGNED-NEXT:    store i32 [[TMP2]], ptr @a, align 4
// UNSIGNED-NEXT:    ret void
//
void mul_auf(void) {
  a *= uf;
}

// CHECK-LABEL: @mul_ai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i47
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE1]], 15
// CHECK-NEXT:    [[TMP2:%.*]] = call i47 @llvm.smul.fix.i47(i47 [[RESIZE]], i47 [[UPSCALE]], i32 15)
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[TMP2]] to i32
// CHECK-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void mul_ai(void) {
  a *= i;
}

// CHECK-LABEL: @mul_csa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @sa, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i8, ptr @c, align 1
// CHECK-NEXT:    [[CONV:%.*]] = sext i8 [[TMP1]] to i32
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[CONV]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE]], 15
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[TMP2:%.*]] = call i47 @llvm.smul.fix.sat.i47(i47 [[UPSCALE]], i47 [[RESIZE1]], i32 15)
// CHECK-NEXT:    [[TMP3:%.*]] = icmp sgt i47 [[TMP2]], 2147483647
// CHECK-NEXT:    [[SATMAX:%.*]] = select i1 [[TMP3]], i47 2147483647, i47 [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = icmp slt i47 [[SATMAX]], -2147483648
// CHECK-NEXT:    [[SATMIN:%.*]] = select i1 [[TMP4]], i47 -2147483648, i47 [[SATMAX]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[SATMIN]] to i32
// CHECK-NEXT:    [[TMP5:%.*]] = icmp slt i32 [[RESIZE2]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = add i32 [[RESIZE2]], 32767
// CHECK-NEXT:    [[TMP7:%.*]] = select i1 [[TMP5]], i32 [[TMP6]], i32 [[RESIZE2]]
// CHECK-NEXT:    [[DOWNSCALE:%.*]] = ashr i32 [[TMP7]], 15
// CHECK-NEXT:    [[RESIZE3:%.*]] = trunc i32 [[DOWNSCALE]] to i8
// CHECK-NEXT:    store i8 [[RESIZE3]], ptr @c, align 1
// CHECK-NEXT:    ret void
//
void mul_csa(void) {
  c *= sa;
}

// CHECK-LABEL: @mul_afl(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load float, ptr @fl, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP2:%.*]] = sitofp i32 [[TMP1]] to float
// CHECK-NEXT:    [[TMP3:%.*]] = fmul float [[TMP2]], 0x3F00000000000000
// CHECK-NEXT:    [[MUL:%.*]] = fmul float [[TMP3]], [[TMP0]]
// CHECK-NEXT:    [[TMP4:%.*]] = fmul float [[MUL]], 3.276800e+04
// CHECK-NEXT:    [[TMP5:%.*]] = fptosi float [[TMP4]] to i32
// CHECK-NEXT:    store i32 [[TMP5]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void mul_afl(void) {
  a *= fl;
}


// SIGNED-LABEL: @div_auf(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// SIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// SIGNED-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i33
// SIGNED-NEXT:    [[UPSCALE:%.*]] = shl i33 [[RESIZE]], 1
// SIGNED-NEXT:    [[RESIZE1:%.*]] = zext i16 [[TMP0]] to i33
// SIGNED-NEXT:    [[TMP2:%.*]] = call i33 @llvm.sdiv.fix.i33(i33 [[UPSCALE]], i33 [[RESIZE1]], i32 16)
// SIGNED-NEXT:    [[DOWNSCALE:%.*]] = ashr i33 [[TMP2]], 1
// SIGNED-NEXT:    [[RESIZE2:%.*]] = trunc i33 [[DOWNSCALE]] to i32
// SIGNED-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @div_auf(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i16, ptr @uf, align 2
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// UNSIGNED-NEXT:    [[RESIZE:%.*]] = zext i16 [[TMP0]] to i32
// UNSIGNED-NEXT:    [[TMP2:%.*]] = call i32 @llvm.sdiv.fix.i32(i32 [[TMP1]], i32 [[RESIZE]], i32 15)
// UNSIGNED-NEXT:    store i32 [[TMP2]], ptr @a, align 4
// UNSIGNED-NEXT:    ret void
//
void div_auf(void) {
  a /= uf;
}

// CHECK-LABEL: @div_ai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[TMP1]] to i47
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE1]], 15
// CHECK-NEXT:    [[TMP2:%.*]] = call i47 @llvm.sdiv.fix.i47(i47 [[RESIZE]], i47 [[UPSCALE]], i32 15)
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[TMP2]] to i32
// CHECK-NEXT:    store i32 [[RESIZE2]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void div_ai(void) {
  a /= i;
}

// CHECK-LABEL: @div_csa(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @sa, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i8, ptr @c, align 1
// CHECK-NEXT:    [[CONV:%.*]] = sext i8 [[TMP1]] to i32
// CHECK-NEXT:    [[RESIZE:%.*]] = sext i32 [[CONV]] to i47
// CHECK-NEXT:    [[UPSCALE:%.*]] = shl i47 [[RESIZE]], 15
// CHECK-NEXT:    [[RESIZE1:%.*]] = sext i32 [[TMP0]] to i47
// CHECK-NEXT:    [[TMP2:%.*]] = call i47 @llvm.sdiv.fix.sat.i47(i47 [[UPSCALE]], i47 [[RESIZE1]], i32 15)
// CHECK-NEXT:    [[TMP3:%.*]] = icmp sgt i47 [[TMP2]], 2147483647
// CHECK-NEXT:    [[SATMAX:%.*]] = select i1 [[TMP3]], i47 2147483647, i47 [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = icmp slt i47 [[SATMAX]], -2147483648
// CHECK-NEXT:    [[SATMIN:%.*]] = select i1 [[TMP4]], i47 -2147483648, i47 [[SATMAX]]
// CHECK-NEXT:    [[RESIZE2:%.*]] = trunc i47 [[SATMIN]] to i32
// CHECK-NEXT:    [[TMP5:%.*]] = icmp slt i32 [[RESIZE2]], 0
// CHECK-NEXT:    [[TMP6:%.*]] = add i32 [[RESIZE2]], 32767
// CHECK-NEXT:    [[TMP7:%.*]] = select i1 [[TMP5]], i32 [[TMP6]], i32 [[RESIZE2]]
// CHECK-NEXT:    [[DOWNSCALE:%.*]] = ashr i32 [[TMP7]], 15
// CHECK-NEXT:    [[RESIZE3:%.*]] = trunc i32 [[DOWNSCALE]] to i8
// CHECK-NEXT:    store i8 [[RESIZE3]], ptr @c, align 1
// CHECK-NEXT:    ret void
//
void div_csa(void) {
  c /= sa;
}

// CHECK-LABEL: @div_afl(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load float, ptr @fl, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP2:%.*]] = sitofp i32 [[TMP1]] to float
// CHECK-NEXT:    [[TMP3:%.*]] = fmul float [[TMP2]], 0x3F00000000000000
// CHECK-NEXT:    [[DIV:%.*]] = fdiv float [[TMP3]], [[TMP0]]
// CHECK-NEXT:    [[TMP4:%.*]] = fmul float [[DIV]], 3.276800e+04
// CHECK-NEXT:    [[TMP5:%.*]] = fptosi float [[TMP4]] to i32
// CHECK-NEXT:    store i32 [[TMP5]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void div_afl(void) {
  a /= fl;
}


// CHECK-LABEL: @shft_ai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i32, ptr @a, align 4
// CHECK-NEXT:    [[TMP2:%.*]] = shl i32 [[TMP1]], [[TMP0]]
// CHECK-NEXT:    store i32 [[TMP2]], ptr @a, align 4
// CHECK-NEXT:    ret void
//
void shft_ai(void) {
  a <<= i;
}

// SIGNED-LABEL: @shft_sufi(
// SIGNED-NEXT:  entry:
// SIGNED-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// SIGNED-NEXT:    [[TMP1:%.*]] = load i16, ptr @suf, align 2
// SIGNED-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP0]] to i16
// SIGNED-NEXT:    [[TMP3:%.*]] = call i16 @llvm.ushl.sat.i16(i16 [[TMP1]], i16 [[TMP2]])
// SIGNED-NEXT:    store i16 [[TMP3]], ptr @suf, align 2
// SIGNED-NEXT:    ret void
//
// UNSIGNED-LABEL: @shft_sufi(
// UNSIGNED-NEXT:  entry:
// UNSIGNED-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// UNSIGNED-NEXT:    [[TMP1:%.*]] = load i16, ptr @suf, align 2
// UNSIGNED-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP0]] to i16
// UNSIGNED-NEXT:    [[TMP3:%.*]] = call i16 @llvm.sshl.sat.i16(i16 [[TMP1]], i16 [[TMP2]])
// UNSIGNED-NEXT:    store i16 [[TMP3]], ptr @suf, align 2
// UNSIGNED-NEXT:    ret void
//
void shft_sufi(void) {
  suf <<= i;
}

// CHECK-LABEL: @shft_ulai(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr @i, align 4
// CHECK-NEXT:    [[TMP1:%.*]] = load i64, ptr @ula, align 8
// CHECK-NEXT:    [[TMP2:%.*]] = zext i32 [[TMP0]] to i64
// CHECK-NEXT:    [[TMP3:%.*]] = lshr i64 [[TMP1]], [[TMP2]]
// CHECK-NEXT:    store i64 [[TMP3]], ptr @ula, align 8
// CHECK-NEXT:    ret void
//
void shft_ulai(void) {
  ula >>= i;
}
