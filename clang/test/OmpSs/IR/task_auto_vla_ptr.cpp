// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --include-generated-funcs
// RUN: %clang_cc1 -x c++ -fompss-2 -disable-llvm-passes %s -S -emit-llvm -o - | FileCheck %s
// expected-no-diagnostics

void foo(int n, void *_pvla) {
  auto *pvla = static_cast<int (*)[n + 1][n + 2]>(_pvla);
  #pragma oss task in(*pvla)
  { }
  #pragma oss task in(pvla[3][4])
  { }
}
// CHECK-LABEL: @_Z3fooiPv(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[N_ADDR:%.*]] = alloca i32, align 4
// CHECK-NEXT:    [[_PVLA_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[PVLA:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    store i32 [[N:%.*]], ptr [[N_ADDR]], align 4
// CHECK-NEXT:    store ptr [[_PVLA:%.*]], ptr [[_PVLA_ADDR]], align 8
// CHECK-NEXT:    [[TMP0:%.*]] = load i32, ptr [[N_ADDR]], align 4, !dbg [[DBG9:![0-9]+]]
// CHECK-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP0]], 1, !dbg [[DBG10:![0-9]+]]
// CHECK-NEXT:    [[TMP1:%.*]] = zext i32 [[ADD]] to i64, !dbg [[DBG11:![0-9]+]]
// CHECK-NEXT:    [[TMP2:%.*]] = load i32, ptr [[N_ADDR]], align 4, !dbg [[DBG12:![0-9]+]]
// CHECK-NEXT:    [[ADD1:%.*]] = add nsw i32 [[TMP2]], 2, !dbg [[DBG13:![0-9]+]]
// CHECK-NEXT:    [[TMP3:%.*]] = zext i32 [[ADD1]] to i64, !dbg [[DBG11]]
// CHECK-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[_PVLA_ADDR]], align 8, !dbg [[DBG14:![0-9]+]]
// CHECK-NEXT:    store ptr [[TMP4]], ptr [[PVLA]], align 8, !dbg [[DBG15:![0-9]+]]
// CHECK-NEXT:    [[TMP5:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[PVLA]], ptr undef), "QUAL.OSS.CAPTURED"(i64 [[TMP1]], i64 [[TMP3]]), "QUAL.OSS.DEP.IN"(ptr [[PVLA]], [6 x i8] c"*pvla\00", ptr @compute_dep, ptr [[PVLA]], i64 [[TMP1]], i64 [[TMP3]]) ], !dbg [[DBG16:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP5]]), !dbg [[DBG17:![0-9]+]]
// CHECK-NEXT:    [[TMP6:%.*]] = call token @llvm.directive.region.entry() [ "DIR.OSS"([5 x i8] c"TASK\00"), "QUAL.OSS.FIRSTPRIVATE"(ptr [[PVLA]], ptr undef), "QUAL.OSS.CAPTURED"(i64 [[TMP1]], i64 [[TMP3]]), "QUAL.OSS.DEP.IN"(ptr [[PVLA]], [11 x i8] c"pvla[3][4]\00", ptr @compute_dep.1, ptr [[PVLA]], i64 [[TMP1]], i64 [[TMP3]]) ], !dbg [[DBG18:![0-9]+]]
// CHECK-NEXT:    call void @llvm.directive.region.exit(token [[TMP6]]), !dbg [[DBG19:![0-9]+]]
// CHECK-NEXT:    ret void, !dbg [[DBG20:![0-9]+]]
//
//
// CHECK-LABEL: @compute_dep(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T:%.*]], align 8
// CHECK-NEXT:    [[PVLA_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTADDR1:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store ptr [[PVLA:%.*]], ptr [[PVLA_ADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP0:%.*]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP1:%.*]], ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[PVLA]], align 8, !dbg [[DBG23:![0-9]+]]
// CHECK-NEXT:    [[TMP3:%.*]] = mul i64 [[TMP1]], 4
// CHECK-NEXT:    [[TMP4:%.*]] = mul i64 [[TMP1]], 4
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[TMP2]], ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 1
// CHECK-NEXT:    store i64 [[TMP3]], ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 2
// CHECK-NEXT:    store i64 0, ptr [[TMP7]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 3
// CHECK-NEXT:    store i64 [[TMP4]], ptr [[TMP8]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 4
// CHECK-NEXT:    store i64 [[TMP0]], ptr [[TMP9]], align 8
// CHECK-NEXT:    [[TMP10:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 5
// CHECK-NEXT:    store i64 0, ptr [[TMP10]], align 8
// CHECK-NEXT:    [[TMP11:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], i32 0, i32 6
// CHECK-NEXT:    store i64 [[TMP0]], ptr [[TMP11]], align 8
// CHECK-NEXT:    [[TMP12:%.*]] = load [[STRUCT__DEPEND_UNPACK_T]], ptr [[RETVAL]], align 8, !dbg [[DBG23]]
// CHECK-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T]] [[TMP12]], !dbg [[DBG23]]
//
//
// CHECK-LABEL: @compute_dep.1(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[RETVAL:%.*]] = alloca [[STRUCT__DEPEND_UNPACK_T_0:%.*]], align 8
// CHECK-NEXT:    [[PVLA_ADDR:%.*]] = alloca ptr, align 8
// CHECK-NEXT:    [[DOTADDR:%.*]] = alloca i64, align 8
// CHECK-NEXT:    [[DOTADDR1:%.*]] = alloca i64, align 8
// CHECK-NEXT:    store ptr [[PVLA:%.*]], ptr [[PVLA_ADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP0:%.*]], ptr [[DOTADDR]], align 8
// CHECK-NEXT:    store i64 [[TMP1:%.*]], ptr [[DOTADDR1]], align 8
// CHECK-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[PVLA]], align 8, !dbg [[DBG26:![0-9]+]]
// CHECK-NEXT:    [[TMP3:%.*]] = mul i64 [[TMP1]], 4
// CHECK-NEXT:    [[TMP4:%.*]] = mul i64 [[TMP1]], 4
// CHECK-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 0
// CHECK-NEXT:    store ptr [[TMP2]], ptr [[TMP5]], align 8
// CHECK-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 1
// CHECK-NEXT:    store i64 [[TMP3]], ptr [[TMP6]], align 8
// CHECK-NEXT:    [[TMP7:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 2
// CHECK-NEXT:    store i64 0, ptr [[TMP7]], align 8
// CHECK-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 3
// CHECK-NEXT:    store i64 [[TMP4]], ptr [[TMP8]], align 8
// CHECK-NEXT:    [[TMP9:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 4
// CHECK-NEXT:    store i64 [[TMP0]], ptr [[TMP9]], align 8
// CHECK-NEXT:    [[TMP10:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 5
// CHECK-NEXT:    store i64 4, ptr [[TMP10]], align 8
// CHECK-NEXT:    [[TMP11:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 6
// CHECK-NEXT:    store i64 5, ptr [[TMP11]], align 8
// CHECK-NEXT:    [[TMP12:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 7
// CHECK-NEXT:    store i64 1, ptr [[TMP12]], align 8
// CHECK-NEXT:    [[TMP13:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 8
// CHECK-NEXT:    store i64 3, ptr [[TMP13]], align 8
// CHECK-NEXT:    [[TMP14:%.*]] = getelementptr inbounds [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], i32 0, i32 9
// CHECK-NEXT:    store i64 4, ptr [[TMP14]], align 8
// CHECK-NEXT:    [[TMP15:%.*]] = load [[STRUCT__DEPEND_UNPACK_T_0]], ptr [[RETVAL]], align 8, !dbg [[DBG26]]
// CHECK-NEXT:    ret [[STRUCT__DEPEND_UNPACK_T_0]] [[TMP15]], !dbg [[DBG26]]
//
