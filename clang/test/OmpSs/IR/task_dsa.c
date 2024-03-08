// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple x86_64-gnu-linux -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=LIN64
// RUN: %clang_cc1 -triple ppc64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=PPC64
// RUN: %clang_cc1 -triple aarch64 -verify -fompss-2 -disable-llvm-passes -ferror-limit 100 %s -S -emit-llvm -o - | FileCheck %s --check-prefixes=AARCH64
// expected-no-diagnostics

struct A {
    int x;
};

// LIN64-LABEL: @main(
// LIN64-NEXT:  entry:
// LIN64-NEXT:    [[I:%.*]] = alloca i32, align 4
// LIN64-NEXT:    [[PI:%.*]] = alloca ptr, align 8
// LIN64-NEXT:    [[AI:%.*]] = alloca [5 x i32], align 16
// LIN64-NEXT:    [[SA:%.*]] = alloca [[STRUCT_A:%.*]], align 4
// LIN64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[I]], i32 undef), "QUAL.OSS.SHARED"(ptr [[PI]], ptr undef), "QUAL.OSS.SHARED"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.SHARED"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG9:![0-9]+]]
// LIN64-NEXT:    [[X:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG10:![0-9]+]]
// LIN64-NEXT:    [[TMP1:%.*]] = load i32, ptr [[X]], align 4, !dbg [[DBG10]]
// LIN64-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG11:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP1]], ptr [[ARRAYIDX]], align 8, !dbg [[DBG12:![0-9]+]]
// LIN64-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG13:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP1]], ptr [[TMP2]], align 4, !dbg [[DBG14:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP1]], ptr [[I]], align 4, !dbg [[DBG15:![0-9]+]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG16:![0-9]+]]
// LIN64-NEXT:    [[TMP3:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.PRIVATE"(ptr [[I]], i32 undef), "QUAL.OSS.PRIVATE"(ptr [[PI]], ptr undef), "QUAL.OSS.PRIVATE"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.PRIVATE"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG17:![0-9]+]]
// LIN64-NEXT:    [[X1:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG18:![0-9]+]]
// LIN64-NEXT:    [[TMP4:%.*]] = load i32, ptr [[X1]], align 4, !dbg [[DBG18]]
// LIN64-NEXT:    [[ARRAYIDX2:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG19:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP4]], ptr [[ARRAYIDX2]], align 8, !dbg [[DBG20:![0-9]+]]
// LIN64-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG21:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP4]], ptr [[TMP5]], align 4, !dbg [[DBG22:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP4]], ptr [[I]], align 4, !dbg [[DBG23:![0-9]+]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP3]]), !dbg [[DBG24:![0-9]+]]
// LIN64-NEXT:    [[TMP6:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[I]], i32 undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[PI]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG25:![0-9]+]]
// LIN64-NEXT:    [[X3:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG26:![0-9]+]]
// LIN64-NEXT:    [[TMP7:%.*]] = load i32, ptr [[X3]], align 4, !dbg [[DBG26]]
// LIN64-NEXT:    [[ARRAYIDX4:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG27:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP7]], ptr [[ARRAYIDX4]], align 8, !dbg [[DBG28:![0-9]+]]
// LIN64-NEXT:    [[TMP8:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG29:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP7]], ptr [[TMP8]], align 4, !dbg [[DBG30:![0-9]+]]
// LIN64-NEXT:    store i32 [[TMP7]], ptr [[I]], align 4, !dbg [[DBG31:![0-9]+]]
// LIN64-NEXT:    call void @llvm.directive.region.exit(token [[TMP6]]), !dbg [[DBG32:![0-9]+]]
// LIN64-NEXT:    ret i32 0, !dbg [[DBG33:![0-9]+]]
//
// PPC64-LABEL: @main(
// PPC64-NEXT:  entry:
// PPC64-NEXT:    [[I:%.*]] = alloca i32, align 4
// PPC64-NEXT:    [[PI:%.*]] = alloca ptr, align 8
// PPC64-NEXT:    [[AI:%.*]] = alloca [5 x i32], align 4
// PPC64-NEXT:    [[SA:%.*]] = alloca [[STRUCT_A:%.*]], align 4
// PPC64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[I]], i32 undef), "QUAL.OSS.SHARED"(ptr [[PI]], ptr undef), "QUAL.OSS.SHARED"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.SHARED"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG9:![0-9]+]]
// PPC64-NEXT:    [[X:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG10:![0-9]+]]
// PPC64-NEXT:    [[TMP1:%.*]] = load i32, ptr [[X]], align 4, !dbg [[DBG10]]
// PPC64-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG11:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP1]], ptr [[ARRAYIDX]], align 4, !dbg [[DBG12:![0-9]+]]
// PPC64-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG13:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP1]], ptr [[TMP2]], align 4, !dbg [[DBG14:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP1]], ptr [[I]], align 4, !dbg [[DBG15:![0-9]+]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG16:![0-9]+]]
// PPC64-NEXT:    [[TMP3:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.PRIVATE"(ptr [[I]], i32 undef), "QUAL.OSS.PRIVATE"(ptr [[PI]], ptr undef), "QUAL.OSS.PRIVATE"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.PRIVATE"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG17:![0-9]+]]
// PPC64-NEXT:    [[X1:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG18:![0-9]+]]
// PPC64-NEXT:    [[TMP4:%.*]] = load i32, ptr [[X1]], align 4, !dbg [[DBG18]]
// PPC64-NEXT:    [[ARRAYIDX2:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG19:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP4]], ptr [[ARRAYIDX2]], align 4, !dbg [[DBG20:![0-9]+]]
// PPC64-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG21:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP4]], ptr [[TMP5]], align 4, !dbg [[DBG22:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP4]], ptr [[I]], align 4, !dbg [[DBG23:![0-9]+]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP3]]), !dbg [[DBG24:![0-9]+]]
// PPC64-NEXT:    [[TMP6:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[I]], i32 undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[PI]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG25:![0-9]+]]
// PPC64-NEXT:    [[X3:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG26:![0-9]+]]
// PPC64-NEXT:    [[TMP7:%.*]] = load i32, ptr [[X3]], align 4, !dbg [[DBG26]]
// PPC64-NEXT:    [[ARRAYIDX4:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG27:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP7]], ptr [[ARRAYIDX4]], align 4, !dbg [[DBG28:![0-9]+]]
// PPC64-NEXT:    [[TMP8:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG29:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP7]], ptr [[TMP8]], align 4, !dbg [[DBG30:![0-9]+]]
// PPC64-NEXT:    store i32 [[TMP7]], ptr [[I]], align 4, !dbg [[DBG31:![0-9]+]]
// PPC64-NEXT:    call void @llvm.directive.region.exit(token [[TMP6]]), !dbg [[DBG32:![0-9]+]]
// PPC64-NEXT:    ret i32 0, !dbg [[DBG33:![0-9]+]]
//
// AARCH64-LABEL: @main(
// AARCH64-NEXT:  entry:
// AARCH64-NEXT:    [[I:%.*]] = alloca i32, align 4
// AARCH64-NEXT:    [[PI:%.*]] = alloca ptr, align 8
// AARCH64-NEXT:    [[AI:%.*]] = alloca [5 x i32], align 4
// AARCH64-NEXT:    [[SA:%.*]] = alloca [[STRUCT_A:%.*]], align 4
// AARCH64-NEXT:    [[TMP0:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.SHARED"(ptr [[I]], i32 undef), "QUAL.OSS.SHARED"(ptr [[PI]], ptr undef), "QUAL.OSS.SHARED"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.SHARED"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG13:![0-9]+]]
// AARCH64-NEXT:    [[X:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG14:![0-9]+]]
// AARCH64-NEXT:    [[TMP1:%.*]] = load i32, ptr [[X]], align 4, !dbg [[DBG14]]
// AARCH64-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG15:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP1]], ptr [[ARRAYIDX]], align 4, !dbg [[DBG16:![0-9]+]]
// AARCH64-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG17:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP1]], ptr [[TMP2]], align 4, !dbg [[DBG18:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP1]], ptr [[I]], align 4, !dbg [[DBG19:![0-9]+]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP0]]), !dbg [[DBG20:![0-9]+]]
// AARCH64-NEXT:    [[TMP3:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.PRIVATE"(ptr [[I]], i32 undef), "QUAL.OSS.PRIVATE"(ptr [[PI]], ptr undef), "QUAL.OSS.PRIVATE"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.PRIVATE"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG21:![0-9]+]]
// AARCH64-NEXT:    [[X1:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG22:![0-9]+]]
// AARCH64-NEXT:    [[TMP4:%.*]] = load i32, ptr [[X1]], align 4, !dbg [[DBG22]]
// AARCH64-NEXT:    [[ARRAYIDX2:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG23:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP4]], ptr [[ARRAYIDX2]], align 4, !dbg [[DBG24:![0-9]+]]
// AARCH64-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG25:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP4]], ptr [[TMP5]], align 4, !dbg [[DBG26:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP4]], ptr [[I]], align 4, !dbg [[DBG27:![0-9]+]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP3]]), !dbg [[DBG28:![0-9]+]]
// AARCH64-NEXT:    [[TMP6:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[I]], i32 undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[PI]], ptr undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[AI]], [5 x i32] undef), "QUAL.OSS.FIRSTPRIVATE"(ptr [[SA]], [[STRUCT_A]] undef) ], !dbg [[DBG29:![0-9]+]]
// AARCH64-NEXT:    [[X3:%.*]] = getelementptr inbounds [[STRUCT_A]], ptr [[SA]], i32 0, i32 0, !dbg [[DBG30:![0-9]+]]
// AARCH64-NEXT:    [[TMP7:%.*]] = load i32, ptr [[X3]], align 4, !dbg [[DBG30]]
// AARCH64-NEXT:    [[ARRAYIDX4:%.*]] = getelementptr inbounds [5 x i32], ptr [[AI]], i64 0, i64 2, !dbg [[DBG31:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP7]], ptr [[ARRAYIDX4]], align 4, !dbg [[DBG32:![0-9]+]]
// AARCH64-NEXT:    [[TMP8:%.*]] = load ptr, ptr [[PI]], align 8, !dbg [[DBG33:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP7]], ptr [[TMP8]], align 4, !dbg [[DBG34:![0-9]+]]
// AARCH64-NEXT:    store i32 [[TMP7]], ptr [[I]], align 4, !dbg [[DBG35:![0-9]+]]
// AARCH64-NEXT:    call void @llvm.directive.region.exit(token [[TMP6]]), !dbg [[DBG36:![0-9]+]]
// AARCH64-NEXT:    ret i32 0, !dbg [[DBG37:![0-9]+]]
//
int main(void) {
  int i;
  int *pi;
  int ai[5];
  struct A sa;
  #pragma oss task shared(i, pi, ai, sa)
  { i = *pi = ai[2] = sa.x; }
  #pragma oss task private(i, pi, ai, sa)
  { i = *pi = ai[2] = sa.x; }
  #pragma oss task firstprivate(i, pi, ai, sa)
  { i = *pi = ai[2] = sa.x; }
}


