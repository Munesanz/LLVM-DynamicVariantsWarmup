// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK

// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -target-feature +bf16 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1, A2_UNUSED, A3, A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1, A2, A3, A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svclastb_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x bfloat> @llvm.aarch64.sve.clastb.nxv8bf16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x bfloat> [[FALLBACK:%.*]], <vscale x 8 x bfloat> [[DATA:%.*]])
// CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z18test_svclastb_bf16u10__SVBool_tu14__SVBFloat16_tu14__SVBFloat16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x bfloat> @llvm.aarch64.sve.clastb.nxv8bf16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x bfloat> [[FALLBACK:%.*]], <vscale x 8 x bfloat> [[DATA:%.*]])
// CPP-CHECK-NEXT:    ret <vscale x 8 x bfloat> [[TMP1]]
//
svbfloat16_t test_svclastb_bf16(svbool_t pg, svbfloat16_t fallback, svbfloat16_t data) {
  // expected-warning@+1 {{implicit declaration of function 'svclastb_bf16'}}
  return SVE_ACLE_FUNC(svclastb, _bf16, , )(pg, fallback, data);
}

// CHECK-LABEL: @test_svclastb_n_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call bfloat @llvm.aarch64.sve.clastb.n.nxv8bf16(<vscale x 8 x i1> [[TMP0]], bfloat [[FALLBACK:%.*]], <vscale x 8 x bfloat> [[DATA:%.*]])
// CHECK-NEXT:    ret bfloat [[TMP1]]
//
// CPP-CHECK-LABEL: @_Z20test_svclastb_n_bf16u10__SVBool_tu6__bf16u14__SVBFloat16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call bfloat @llvm.aarch64.sve.clastb.n.nxv8bf16(<vscale x 8 x i1> [[TMP0]], bfloat [[FALLBACK:%.*]], <vscale x 8 x bfloat> [[DATA:%.*]])
// CPP-CHECK-NEXT:    ret bfloat [[TMP1]]
//
bfloat16_t test_svclastb_n_bf16(svbool_t pg, bfloat16_t fallback, svbfloat16_t data) {
  // expected-warning@+1 {{implicit declaration of function 'svclastb_n_bf16'}}
  return SVE_ACLE_FUNC(svclastb, _n_bf16, , )(pg, fallback, data);
}
