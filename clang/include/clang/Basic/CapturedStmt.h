//===--- CapturedStmt.h - Types for CapturedStmts ---------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//


#ifndef LLVM_CLANG_BASIC_CAPTUREDSTMT_H
#define LLVM_CLANG_BASIC_CAPTUREDSTMT_H

namespace clang {

/// The different kinds of captured statement.
enum CapturedRegionKind {
  CR_Default,
  CR_ObjCAtFinally,
  CR_OpenMP,
  CR_OmpSs
};

} // end namespace clang

#endif // LLVM_CLANG_BASIC_CAPTUREDSTMT_H
