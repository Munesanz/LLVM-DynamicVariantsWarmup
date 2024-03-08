// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs --replace-value-regex "__omp_offloading_[0-9a-z]+_[0-9a-z]+" "reduction_size[.].+[.]" "pl_cond[.].+[.|,]" --prefix-filecheck-ir-name _
// RUN: %clang_cc1 -verify -fopenmp -fopenmp-version=50 -x c++ -triple x86_64-unknown-linux -emit-llvm %s -fexceptions -fcxx-exceptions -o - | FileCheck %s --check-prefix=CHECK1
// RUN: %clang_cc1 -fopenmp -fopenmp-version=50 -x c++ -std=c++11 -triple x86_64-unknown-linux -fexceptions -fcxx-exceptions -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp -fopenmp-version=50 -x c++ -triple x86_64-unknown-linux -fexceptions -fcxx-exceptions -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s --check-prefix=CHECK1

// RUN: %clang_cc1 -triple x86_64-unknown-linux -verify -fopenmp-simd -fopenmp-version=50 -x c++ -emit-llvm %s -fexceptions -fcxx-exceptions -o - | FileCheck %s --implicit-check-not="{{__kmpc|__tgt}}"
// RUN: %clang_cc1 -fopenmp-simd -fopenmp-version=50 -x c++ -std=c++11 -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp-simd -fopenmp-version=50 -x c++ -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -debug-info-kind=limited -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s --implicit-check-not="{{__kmpc|__tgt}}"
// expected-no-diagnostics
#ifndef HEADER
#define HEADER

int main(int argc, char **argv) {
#pragma omp target parallel reduction(task, +: argc, argv[0:10][0:argc])
  {
#pragma omp task in_reduction(+: argc, argv[0:10][0:argc])
    ;
  }
}



// Init firstprivate copy of argc

// Init firstprivate copy of argv[0:10][0:argc]

// Register task reduction.









#endif
// CHECK1-LABEL: define {{[^@]+}}@main
// CHECK1-SAME: (i32 noundef [[ARGC:%.*]], ptr noundef [[ARGV:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[ARGC_ADDR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[ARGV_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store i32 [[ARGC]], ptr [[ARGC_ADDR]], align 4
// CHECK1-NEXT:    store ptr [[ARGV]], ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    call void @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l14(ptr [[ARGC_ADDR]], ptr [[TMP0]]) #[[ATTR6:[0-9]+]]
// CHECK1-NEXT:    ret i32 0
//
//
// CHECK1-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l14
// CHECK1-SAME: (ptr noundef nonnull align 4 dereferenceable(4) [[ARGC:%.*]], ptr noundef [[ARGV:%.*]]) #[[ATTR1:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[ARGC_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[ARGV_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[ARGC]], ptr [[ARGC_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[ARGV]], ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[ARGC_ADDR]], align 8
// CHECK1-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    call void (ptr, i32, ptr, ...) @__kmpc_fork_call(ptr @[[GLOB1:[0-9]+]], i32 2, ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l14.omp_outlined, ptr [[TMP0]], ptr [[TMP1]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l14.omp_outlined
// CHECK1-SAME: (ptr noalias noundef [[DOTGLOBAL_TID_:%.*]], ptr noalias noundef [[DOTBOUND_TID_:%.*]], ptr noundef nonnull align 4 dereferenceable(4) [[ARGC:%.*]], ptr noundef [[ARGV:%.*]]) #[[ATTR1]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTBOUND_TID__ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[ARGC_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[ARGV_ADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[ARGC1:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[SAVED_STACK:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[__VLA_EXPR0:%.*]] = alloca i64, align 8
// CHECK1-NEXT:    [[TMP:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[_TMP5:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTRD_INPUT_:%.*]] = alloca [2 x %struct.kmp_taskred_input_t], align 8
// CHECK1-NEXT:    [[DOTTASK_RED_:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[AGG_CAPTURED:%.*]] = alloca [[STRUCT_ANON:%.*]], align 8
// CHECK1-NEXT:    [[DOTOMP_REDUCTION_RED_LIST:%.*]] = alloca [3 x ptr], align 8
// CHECK1-NEXT:    [[ATOMIC_TEMP:%.*]] = alloca i8, align 1
// CHECK1-NEXT:    [[_TMP24:%.*]] = alloca i8, align 1
// CHECK1-NEXT:    store ptr [[DOTGLOBAL_TID_]], ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[DOTBOUND_TID_]], ptr [[DOTBOUND_TID__ADDR]], align 8
// CHECK1-NEXT:    store ptr [[ARGC]], ptr [[ARGC_ADDR]], align 8
// CHECK1-NEXT:    store ptr [[ARGV]], ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[TMP0:%.*]] = load ptr, ptr [[ARGC_ADDR]], align 8
// CHECK1-NEXT:    store i32 0, ptr [[ARGC1]], align 4
// CHECK1-NEXT:    [[TMP1:%.*]] = load ptr, ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds ptr, ptr [[TMP1]], i64 0
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[ARRAYIDX]], align 8
// CHECK1-NEXT:    [[ARRAYIDX2:%.*]] = getelementptr inbounds i8, ptr [[TMP2]], i64 0
// CHECK1-NEXT:    [[TMP3:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK1-NEXT:    [[TMP4:%.*]] = sext i32 [[TMP3]] to i64
// CHECK1-NEXT:    [[LB_ADD_LEN:%.*]] = add nsw i64 -1, [[TMP4]]
// CHECK1-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[ARRAYIDX3:%.*]] = getelementptr inbounds ptr, ptr [[TMP5]], i64 9
// CHECK1-NEXT:    [[TMP6:%.*]] = load ptr, ptr [[ARRAYIDX3]], align 8
// CHECK1-NEXT:    [[ARRAYIDX4:%.*]] = getelementptr inbounds i8, ptr [[TMP6]], i64 [[LB_ADD_LEN]]
// CHECK1-NEXT:    [[TMP7:%.*]] = ptrtoint ptr [[ARRAYIDX4]] to i64
// CHECK1-NEXT:    [[TMP8:%.*]] = ptrtoint ptr [[ARRAYIDX2]] to i64
// CHECK1-NEXT:    [[TMP9:%.*]] = sub i64 [[TMP7]], [[TMP8]]
// CHECK1-NEXT:    [[TMP10:%.*]] = sdiv exact i64 [[TMP9]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK1-NEXT:    [[TMP11:%.*]] = add nuw i64 [[TMP10]], 1
// CHECK1-NEXT:    [[TMP12:%.*]] = mul nuw i64 [[TMP11]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK1-NEXT:    [[TMP13:%.*]] = call ptr @llvm.stacksave()
// CHECK1-NEXT:    store ptr [[TMP13]], ptr [[SAVED_STACK]], align 8
// CHECK1-NEXT:    [[VLA:%.*]] = alloca i8, i64 [[TMP11]], align 16
// CHECK1-NEXT:    store i64 [[TMP11]], ptr [[__VLA_EXPR0]], align 8
// CHECK1-NEXT:    [[TMP14:%.*]] = getelementptr i8, ptr [[VLA]], i64 [[TMP11]]
// CHECK1-NEXT:    [[OMP_ARRAYINIT_ISEMPTY:%.*]] = icmp eq ptr [[VLA]], [[TMP14]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYINIT_ISEMPTY]], label [[OMP_ARRAYINIT_DONE:%.*]], label [[OMP_ARRAYINIT_BODY:%.*]]
// CHECK1:       omp.arrayinit.body:
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[VLA]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYINIT_BODY]] ]
// CHECK1-NEXT:    store i8 0, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP14]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYINIT_DONE]], label [[OMP_ARRAYINIT_BODY]]
// CHECK1:       omp.arrayinit.done:
// CHECK1-NEXT:    [[TMP15:%.*]] = load ptr, ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[TMP16:%.*]] = load ptr, ptr [[TMP15]], align 8
// CHECK1-NEXT:    [[TMP17:%.*]] = ptrtoint ptr [[TMP16]] to i64
// CHECK1-NEXT:    [[TMP18:%.*]] = ptrtoint ptr [[ARRAYIDX2]] to i64
// CHECK1-NEXT:    [[TMP19:%.*]] = sub i64 [[TMP17]], [[TMP18]]
// CHECK1-NEXT:    [[TMP20:%.*]] = sdiv exact i64 [[TMP19]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK1-NEXT:    [[TMP21:%.*]] = getelementptr i8, ptr [[VLA]], i64 [[TMP20]]
// CHECK1-NEXT:    store ptr [[_TMP5]], ptr [[TMP]], align 8
// CHECK1-NEXT:    store ptr [[TMP21]], ptr [[_TMP5]], align 8
// CHECK1-NEXT:    [[DOTRD_INPUT_GEP_:%.*]] = getelementptr inbounds [2 x %struct.kmp_taskred_input_t], ptr [[DOTRD_INPUT_]], i64 0, i64 0
// CHECK1-NEXT:    [[TMP22:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T:%.*]], ptr [[DOTRD_INPUT_GEP_]], i32 0, i32 0
// CHECK1-NEXT:    store ptr [[ARGC1]], ptr [[TMP22]], align 8
// CHECK1-NEXT:    [[TMP23:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_]], i32 0, i32 1
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[TMP23]], align 8
// CHECK1-NEXT:    [[TMP24:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_]], i32 0, i32 2
// CHECK1-NEXT:    store i64 4, ptr [[TMP24]], align 8
// CHECK1-NEXT:    [[TMP25:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_]], i32 0, i32 3
// CHECK1-NEXT:    store ptr @.red_init., ptr [[TMP25]], align 8
// CHECK1-NEXT:    [[TMP26:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_]], i32 0, i32 4
// CHECK1-NEXT:    store ptr null, ptr [[TMP26]], align 8
// CHECK1-NEXT:    [[TMP27:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_]], i32 0, i32 5
// CHECK1-NEXT:    store ptr @.red_comb., ptr [[TMP27]], align 8
// CHECK1-NEXT:    [[TMP28:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_]], i32 0, i32 6
// CHECK1-NEXT:    call void @llvm.memset.p0.i64(ptr align 8 [[TMP28]], i8 0, i64 4, i1 false)
// CHECK1-NEXT:    [[DOTRD_INPUT_GEP_6:%.*]] = getelementptr inbounds [2 x %struct.kmp_taskred_input_t], ptr [[DOTRD_INPUT_]], i64 0, i64 1
// CHECK1-NEXT:    [[TMP29:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_6]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP30:%.*]] = load ptr, ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[ARRAYIDX7:%.*]] = getelementptr inbounds ptr, ptr [[TMP30]], i64 0
// CHECK1-NEXT:    [[TMP31:%.*]] = load ptr, ptr [[ARRAYIDX7]], align 8
// CHECK1-NEXT:    [[ARRAYIDX8:%.*]] = getelementptr inbounds i8, ptr [[TMP31]], i64 0
// CHECK1-NEXT:    [[TMP32:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK1-NEXT:    [[TMP33:%.*]] = sext i32 [[TMP32]] to i64
// CHECK1-NEXT:    [[LB_ADD_LEN9:%.*]] = add nsw i64 -1, [[TMP33]]
// CHECK1-NEXT:    [[TMP34:%.*]] = load ptr, ptr [[ARGV_ADDR]], align 8
// CHECK1-NEXT:    [[ARRAYIDX10:%.*]] = getelementptr inbounds ptr, ptr [[TMP34]], i64 9
// CHECK1-NEXT:    [[TMP35:%.*]] = load ptr, ptr [[ARRAYIDX10]], align 8
// CHECK1-NEXT:    [[ARRAYIDX11:%.*]] = getelementptr inbounds i8, ptr [[TMP35]], i64 [[LB_ADD_LEN9]]
// CHECK1-NEXT:    store ptr [[VLA]], ptr [[TMP29]], align 8
// CHECK1-NEXT:    [[TMP36:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_6]], i32 0, i32 1
// CHECK1-NEXT:    store ptr [[ARRAYIDX8]], ptr [[TMP36]], align 8
// CHECK1-NEXT:    [[TMP37:%.*]] = ptrtoint ptr [[ARRAYIDX11]] to i64
// CHECK1-NEXT:    [[TMP38:%.*]] = ptrtoint ptr [[ARRAYIDX8]] to i64
// CHECK1-NEXT:    [[TMP39:%.*]] = sub i64 [[TMP37]], [[TMP38]]
// CHECK1-NEXT:    [[TMP40:%.*]] = sdiv exact i64 [[TMP39]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK1-NEXT:    [[TMP41:%.*]] = add nuw i64 [[TMP40]], 1
// CHECK1-NEXT:    [[TMP42:%.*]] = mul nuw i64 [[TMP41]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK1-NEXT:    [[TMP43:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_6]], i32 0, i32 2
// CHECK1-NEXT:    store i64 [[TMP42]], ptr [[TMP43]], align 8
// CHECK1-NEXT:    [[TMP44:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_6]], i32 0, i32 3
// CHECK1-NEXT:    store ptr @.red_init..1, ptr [[TMP44]], align 8
// CHECK1-NEXT:    [[TMP45:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_6]], i32 0, i32 4
// CHECK1-NEXT:    store ptr null, ptr [[TMP45]], align 8
// CHECK1-NEXT:    [[TMP46:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_6]], i32 0, i32 5
// CHECK1-NEXT:    store ptr @.red_comb..2, ptr [[TMP46]], align 8
// CHECK1-NEXT:    [[TMP47:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASKRED_INPUT_T]], ptr [[DOTRD_INPUT_GEP_6]], i32 0, i32 6
// CHECK1-NEXT:    store i32 1, ptr [[TMP47]], align 8
// CHECK1-NEXT:    [[TMP48:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP49:%.*]] = load i32, ptr [[TMP48]], align 4
// CHECK1-NEXT:    [[TMP50:%.*]] = call ptr @__kmpc_taskred_modifier_init(ptr @[[GLOB1]], i32 [[TMP49]], i32 0, i32 2, ptr [[DOTRD_INPUT_]])
// CHECK1-NEXT:    store ptr [[TMP50]], ptr [[DOTTASK_RED_]], align 8
// CHECK1-NEXT:    [[TMP51:%.*]] = getelementptr inbounds [[STRUCT_ANON]], ptr [[AGG_CAPTURED]], i32 0, i32 0
// CHECK1-NEXT:    store ptr [[DOTTASK_RED_]], ptr [[TMP51]], align 8
// CHECK1-NEXT:    [[TMP52:%.*]] = getelementptr inbounds [[STRUCT_ANON]], ptr [[AGG_CAPTURED]], i32 0, i32 1
// CHECK1-NEXT:    store ptr [[ARGC1]], ptr [[TMP52]], align 8
// CHECK1-NEXT:    [[TMP53:%.*]] = getelementptr inbounds [[STRUCT_ANON]], ptr [[AGG_CAPTURED]], i32 0, i32 2
// CHECK1-NEXT:    [[TMP54:%.*]] = load ptr, ptr [[TMP]], align 8
// CHECK1-NEXT:    store ptr [[TMP54]], ptr [[TMP53]], align 8
// CHECK1-NEXT:    [[TMP55:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP56:%.*]] = load i32, ptr [[TMP55]], align 4
// CHECK1-NEXT:    [[TMP57:%.*]] = call ptr @__kmpc_omp_task_alloc(ptr @[[GLOB1]], i32 [[TMP56]], i32 1, i64 48, i64 24, ptr @.omp_task_entry.)
// CHECK1-NEXT:    [[TMP58:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T_WITH_PRIVATES:%.*]], ptr [[TMP57]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP59:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T:%.*]], ptr [[TMP58]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP60:%.*]] = load ptr, ptr [[TMP59]], align 8
// CHECK1-NEXT:    call void @llvm.memcpy.p0.p0.i64(ptr align 8 [[TMP60]], ptr align 8 [[AGG_CAPTURED]], i64 24, i1 false)
// CHECK1-NEXT:    [[TMP61:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T_WITH_PRIVATES]], ptr [[TMP57]], i32 0, i32 1
// CHECK1-NEXT:    [[TMP62:%.*]] = getelementptr inbounds [[STRUCT__KMP_PRIVATES_T:%.*]], ptr [[TMP61]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP63:%.*]] = load ptr, ptr [[DOTTASK_RED_]], align 8
// CHECK1-NEXT:    store ptr [[TMP63]], ptr [[TMP62]], align 8
// CHECK1-NEXT:    [[TMP64:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP65:%.*]] = load i32, ptr [[TMP64]], align 4
// CHECK1-NEXT:    [[TMP66:%.*]] = call i32 @__kmpc_omp_task(ptr @[[GLOB1]], i32 [[TMP65]], ptr [[TMP57]])
// CHECK1-NEXT:    [[TMP67:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP68:%.*]] = load i32, ptr [[TMP67]], align 4
// CHECK1-NEXT:    call void @__kmpc_task_reduction_modifier_fini(ptr @[[GLOB1]], i32 [[TMP68]], i32 0)
// CHECK1-NEXT:    [[TMP69:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOMP_REDUCTION_RED_LIST]], i64 0, i64 0
// CHECK1-NEXT:    store ptr [[ARGC1]], ptr [[TMP69]], align 8
// CHECK1-NEXT:    [[TMP70:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOMP_REDUCTION_RED_LIST]], i64 0, i64 1
// CHECK1-NEXT:    store ptr [[VLA]], ptr [[TMP70]], align 8
// CHECK1-NEXT:    [[TMP71:%.*]] = getelementptr inbounds [3 x ptr], ptr [[DOTOMP_REDUCTION_RED_LIST]], i64 0, i64 2
// CHECK1-NEXT:    [[TMP72:%.*]] = inttoptr i64 [[TMP11]] to ptr
// CHECK1-NEXT:    store ptr [[TMP72]], ptr [[TMP71]], align 8
// CHECK1-NEXT:    [[TMP73:%.*]] = load ptr, ptr [[DOTGLOBAL_TID__ADDR]], align 8
// CHECK1-NEXT:    [[TMP74:%.*]] = load i32, ptr [[TMP73]], align 4
// CHECK1-NEXT:    [[TMP75:%.*]] = call i32 @__kmpc_reduce_nowait(ptr @[[GLOB2:[0-9]+]], i32 [[TMP74]], i32 2, i64 24, ptr [[DOTOMP_REDUCTION_RED_LIST]], ptr @{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l14.omp_outlined.omp.reduction.reduction_func, ptr @.gomp_critical_user_.reduction.var)
// CHECK1-NEXT:    switch i32 [[TMP75]], label [[DOTOMP_REDUCTION_DEFAULT:%.*]] [
// CHECK1-NEXT:    i32 1, label [[DOTOMP_REDUCTION_CASE1:%.*]]
// CHECK1-NEXT:    i32 2, label [[DOTOMP_REDUCTION_CASE2:%.*]]
// CHECK1-NEXT:    ]
// CHECK1:       .omp.reduction.case1:
// CHECK1-NEXT:    [[TMP76:%.*]] = load i32, ptr [[TMP0]], align 4
// CHECK1-NEXT:    [[TMP77:%.*]] = load i32, ptr [[ARGC1]], align 4
// CHECK1-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP76]], [[TMP77]]
// CHECK1-NEXT:    store i32 [[ADD]], ptr [[TMP0]], align 4
// CHECK1-NEXT:    [[TMP78:%.*]] = getelementptr i8, ptr [[ARRAYIDX2]], i64 [[TMP11]]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_ISEMPTY:%.*]] = icmp eq ptr [[ARRAYIDX2]], [[TMP78]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY]], label [[OMP_ARRAYCPY_DONE18:%.*]], label [[OMP_ARRAYCPY_BODY:%.*]]
// CHECK1:       omp.arraycpy.body:
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST:%.*]] = phi ptr [ [[VLA]], [[DOTOMP_REDUCTION_CASE1]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST12:%.*]] = phi ptr [ [[ARRAYIDX2]], [[DOTOMP_REDUCTION_CASE1]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT16:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// CHECK1-NEXT:    [[TMP79:%.*]] = load i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST12]], align 1
// CHECK1-NEXT:    [[CONV:%.*]] = sext i8 [[TMP79]] to i32
// CHECK1-NEXT:    [[TMP80:%.*]] = load i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], align 1
// CHECK1-NEXT:    [[CONV13:%.*]] = sext i8 [[TMP80]] to i32
// CHECK1-NEXT:    [[ADD14:%.*]] = add nsw i32 [[CONV]], [[CONV13]]
// CHECK1-NEXT:    [[CONV15:%.*]] = trunc i32 [[ADD14]] to i8
// CHECK1-NEXT:    store i8 [[CONV15]], ptr [[OMP_ARRAYCPY_DESTELEMENTPAST12]], align 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT16]] = getelementptr i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST12]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT]] = getelementptr i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DONE17:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT16]], [[TMP78]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_DONE17]], label [[OMP_ARRAYCPY_DONE18]], label [[OMP_ARRAYCPY_BODY]]
// CHECK1:       omp.arraycpy.done18:
// CHECK1-NEXT:    call void @__kmpc_end_reduce_nowait(ptr @[[GLOB2]], i32 [[TMP74]], ptr @.gomp_critical_user_.reduction.var)
// CHECK1-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// CHECK1:       .omp.reduction.case2:
// CHECK1-NEXT:    [[TMP81:%.*]] = load i32, ptr [[ARGC1]], align 4
// CHECK1-NEXT:    [[TMP82:%.*]] = atomicrmw add ptr [[TMP0]], i32 [[TMP81]] monotonic, align 4
// CHECK1-NEXT:    [[TMP83:%.*]] = getelementptr i8, ptr [[ARRAYIDX2]], i64 [[TMP11]]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_ISEMPTY19:%.*]] = icmp eq ptr [[ARRAYIDX2]], [[TMP83]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY19]], label [[OMP_ARRAYCPY_DONE32:%.*]], label [[OMP_ARRAYCPY_BODY20:%.*]]
// CHECK1:       omp.arraycpy.body20:
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST21:%.*]] = phi ptr [ [[VLA]], [[DOTOMP_REDUCTION_CASE2]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT30:%.*]], [[ATOMIC_EXIT:%.*]] ]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST22:%.*]] = phi ptr [ [[ARRAYIDX2]], [[DOTOMP_REDUCTION_CASE2]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT29:%.*]], [[ATOMIC_EXIT]] ]
// CHECK1-NEXT:    [[TMP84:%.*]] = load i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST21]], align 1
// CHECK1-NEXT:    [[CONV23:%.*]] = sext i8 [[TMP84]] to i32
// CHECK1-NEXT:    [[ATOMIC_LOAD:%.*]] = load atomic i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST22]] monotonic, align 1
// CHECK1-NEXT:    br label [[ATOMIC_CONT:%.*]]
// CHECK1:       atomic_cont:
// CHECK1-NEXT:    [[TMP85:%.*]] = phi i8 [ [[ATOMIC_LOAD]], [[OMP_ARRAYCPY_BODY20]] ], [ [[TMP90:%.*]], [[ATOMIC_CONT]] ]
// CHECK1-NEXT:    store i8 [[TMP85]], ptr [[_TMP24]], align 1
// CHECK1-NEXT:    [[TMP86:%.*]] = load i8, ptr [[_TMP24]], align 1
// CHECK1-NEXT:    [[CONV25:%.*]] = sext i8 [[TMP86]] to i32
// CHECK1-NEXT:    [[TMP87:%.*]] = load i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST21]], align 1
// CHECK1-NEXT:    [[CONV26:%.*]] = sext i8 [[TMP87]] to i32
// CHECK1-NEXT:    [[ADD27:%.*]] = add nsw i32 [[CONV25]], [[CONV26]]
// CHECK1-NEXT:    [[CONV28:%.*]] = trunc i32 [[ADD27]] to i8
// CHECK1-NEXT:    store i8 [[CONV28]], ptr [[ATOMIC_TEMP]], align 1
// CHECK1-NEXT:    [[TMP88:%.*]] = load i8, ptr [[ATOMIC_TEMP]], align 1
// CHECK1-NEXT:    [[TMP89:%.*]] = cmpxchg ptr [[OMP_ARRAYCPY_DESTELEMENTPAST22]], i8 [[TMP85]], i8 [[TMP88]] monotonic monotonic, align 1
// CHECK1-NEXT:    [[TMP90]] = extractvalue { i8, i1 } [[TMP89]], 0
// CHECK1-NEXT:    [[TMP91:%.*]] = extractvalue { i8, i1 } [[TMP89]], 1
// CHECK1-NEXT:    br i1 [[TMP91]], label [[ATOMIC_EXIT]], label [[ATOMIC_CONT]]
// CHECK1:       atomic_exit:
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT29]] = getelementptr i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST22]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT30]] = getelementptr i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST21]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DONE31:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT29]], [[TMP83]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_DONE31]], label [[OMP_ARRAYCPY_DONE32]], label [[OMP_ARRAYCPY_BODY20]]
// CHECK1:       omp.arraycpy.done32:
// CHECK1-NEXT:    br label [[DOTOMP_REDUCTION_DEFAULT]]
// CHECK1:       .omp.reduction.default:
// CHECK1-NEXT:    [[TMP92:%.*]] = load ptr, ptr [[SAVED_STACK]], align 8
// CHECK1-NEXT:    call void @llvm.stackrestore(ptr [[TMP92]])
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@.red_init.
// CHECK1-SAME: (ptr noalias noundef [[TMP0:%.*]], ptr noalias noundef [[TMP1:%.*]]) #[[ATTR3:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    store i32 0, ptr [[TMP2]], align 4
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@.red_comb.
// CHECK1-SAME: (ptr noundef [[TMP0:%.*]], ptr noundef [[TMP1:%.*]]) #[[ATTR3]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP4:%.*]] = load i32, ptr [[TMP2]], align 4
// CHECK1-NEXT:    [[TMP5:%.*]] = load i32, ptr [[TMP3]], align 4
// CHECK1-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP4]], [[TMP5]]
// CHECK1-NEXT:    store i32 [[ADD]], ptr [[TMP2]], align 4
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@.red_init..1
// CHECK1-SAME: (ptr noalias noundef [[TMP0:%.*]], ptr noalias noundef [[TMP1:%.*]]) #[[ATTR3]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    [[TMP3:%.*]] = call ptr @llvm.threadlocal.address.p0(ptr @{{reduction_size[.].+[.]}})
// CHECK1-NEXT:    [[TMP4:%.*]] = load i64, ptr [[TMP3]], align 8
// CHECK1-NEXT:    [[TMP5:%.*]] = getelementptr i8, ptr [[TMP2]], i64 [[TMP4]]
// CHECK1-NEXT:    [[OMP_ARRAYINIT_ISEMPTY:%.*]] = icmp eq ptr [[TMP2]], [[TMP5]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYINIT_ISEMPTY]], label [[OMP_ARRAYINIT_DONE:%.*]], label [[OMP_ARRAYINIT_BODY:%.*]]
// CHECK1:       omp.arrayinit.body:
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[TMP2]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYINIT_BODY]] ]
// CHECK1-NEXT:    store i8 0, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP5]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYINIT_DONE]], label [[OMP_ARRAYINIT_BODY]]
// CHECK1:       omp.arrayinit.done:
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@.red_comb..2
// CHECK1-SAME: (ptr noundef [[TMP0:%.*]], ptr noundef [[TMP1:%.*]]) #[[ATTR3]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = call ptr @llvm.threadlocal.address.p0(ptr @{{reduction_size[.].+[.]}})
// CHECK1-NEXT:    [[TMP3:%.*]] = load i64, ptr [[TMP2]], align 8
// CHECK1-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP6:%.*]] = getelementptr i8, ptr [[TMP4]], i64 [[TMP3]]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_ISEMPTY:%.*]] = icmp eq ptr [[TMP4]], [[TMP6]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY]], label [[OMP_ARRAYCPY_DONE4:%.*]], label [[OMP_ARRAYCPY_BODY:%.*]]
// CHECK1:       omp.arraycpy.body:
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST:%.*]] = phi ptr [ [[TMP5]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[TMP4]], [[ENTRY]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// CHECK1-NEXT:    [[TMP7:%.*]] = load i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 1
// CHECK1-NEXT:    [[CONV:%.*]] = sext i8 [[TMP7]] to i32
// CHECK1-NEXT:    [[TMP8:%.*]] = load i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], align 1
// CHECK1-NEXT:    [[CONV2:%.*]] = sext i8 [[TMP8]] to i32
// CHECK1-NEXT:    [[ADD:%.*]] = add nsw i32 [[CONV]], [[CONV2]]
// CHECK1-NEXT:    [[CONV3:%.*]] = trunc i32 [[ADD]] to i8
// CHECK1-NEXT:    store i8 [[CONV3]], ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT]] = getelementptr i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP6]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYCPY_DONE4]], label [[OMP_ARRAYCPY_BODY]]
// CHECK1:       omp.arraycpy.done4:
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@.omp_task_privates_map.
// CHECK1-SAME: (ptr noalias noundef [[TMP0:%.*]], ptr noalias noundef [[TMP1:%.*]]) #[[ATTR7:[0-9]+]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    [[TMP3:%.*]] = getelementptr inbounds [[STRUCT__KMP_PRIVATES_T:%.*]], ptr [[TMP2]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP4:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    store ptr [[TMP3]], ptr [[TMP4]], align 8
// CHECK1-NEXT:    ret void
//
//
// CHECK1-LABEL: define {{[^@]+}}@.omp_task_entry.
// CHECK1-SAME: (i32 noundef [[TMP0:%.*]], ptr noalias noundef [[TMP1:%.*]]) #[[ATTR3]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTGLOBAL_TID__ADDR_I:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTPART_ID__ADDR_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTPRIVATES__ADDR_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTCOPY_FN__ADDR_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTTASK_T__ADDR_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[__CONTEXT_ADDR_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTFIRSTPRIV_PTR_ADDR_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[TMP_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[TMP4_I:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca i32, align 4
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store i32 [[TMP0]], ptr [[DOTADDR]], align 4
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load i32, ptr [[DOTADDR]], align 4
// CHECK1-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T_WITH_PRIVATES:%.*]], ptr [[TMP3]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP5:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T:%.*]], ptr [[TMP4]], i32 0, i32 2
// CHECK1-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T]], ptr [[TMP4]], i32 0, i32 0
// CHECK1-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[TMP6]], align 8
// CHECK1-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [[STRUCT_KMP_TASK_T_WITH_PRIVATES]], ptr [[TMP3]], i32 0, i32 1
// CHECK1-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META3:![0-9]+]])
// CHECK1-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META6:![0-9]+]])
// CHECK1-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META8:![0-9]+]])
// CHECK1-NEXT:    call void @llvm.experimental.noalias.scope.decl(metadata [[META10:![0-9]+]])
// CHECK1-NEXT:    store i32 [[TMP2]], ptr [[DOTGLOBAL_TID__ADDR_I]], align 4, !noalias !12
// CHECK1-NEXT:    store ptr [[TMP5]], ptr [[DOTPART_ID__ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    store ptr [[TMP8]], ptr [[DOTPRIVATES__ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    store ptr @.omp_task_privates_map., ptr [[DOTCOPY_FN__ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    store ptr [[TMP3]], ptr [[DOTTASK_T__ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    store ptr [[TMP7]], ptr [[__CONTEXT_ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    [[TMP9:%.*]] = load ptr, ptr [[__CONTEXT_ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    [[TMP10:%.*]] = load ptr, ptr [[DOTCOPY_FN__ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    [[TMP11:%.*]] = load ptr, ptr [[DOTPRIVATES__ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    call void [[TMP10]](ptr [[TMP11]], ptr [[DOTFIRSTPRIV_PTR_ADDR_I]]) #[[ATTR6]]
// CHECK1-NEXT:    [[TMP12:%.*]] = load ptr, ptr [[DOTFIRSTPRIV_PTR_ADDR_I]], align 8, !noalias !12
// CHECK1-NEXT:    [[TMP13:%.*]] = getelementptr inbounds [[STRUCT_ANON:%.*]], ptr [[TMP9]], i32 0, i32 1
// CHECK1-NEXT:    [[TMP14:%.*]] = load ptr, ptr [[TMP13]], align 8
// CHECK1-NEXT:    [[TMP15:%.*]] = load ptr, ptr [[TMP12]], align 8
// CHECK1-NEXT:    [[TMP16:%.*]] = load i32, ptr [[DOTGLOBAL_TID__ADDR_I]], align 4, !noalias !12
// CHECK1-NEXT:    [[TMP17:%.*]] = call ptr @__kmpc_task_reduction_get_th_data(i32 [[TMP16]], ptr [[TMP15]], ptr [[TMP14]])
// CHECK1-NEXT:    [[TMP18:%.*]] = getelementptr inbounds [[STRUCT_ANON]], ptr [[TMP9]], i32 0, i32 2
// CHECK1-NEXT:    [[TMP19:%.*]] = load ptr, ptr [[TMP18]], align 8
// CHECK1-NEXT:    [[TMP20:%.*]] = load ptr, ptr [[TMP19]], align 8
// CHECK1-NEXT:    [[TMP21:%.*]] = getelementptr inbounds [[STRUCT_ANON]], ptr [[TMP9]], i32 0, i32 1
// CHECK1-NEXT:    [[TMP22:%.*]] = load ptr, ptr [[TMP21]], align 8
// CHECK1-NEXT:    [[TMP23:%.*]] = load i32, ptr [[TMP22]], align 4
// CHECK1-NEXT:    [[TMP24:%.*]] = sext i32 [[TMP23]] to i64
// CHECK1-NEXT:    [[LB_ADD_LEN_I:%.*]] = add nsw i64 -1, [[TMP24]]
// CHECK1-NEXT:    [[TMP25:%.*]] = getelementptr inbounds [[STRUCT_ANON]], ptr [[TMP9]], i32 0, i32 2
// CHECK1-NEXT:    [[TMP26:%.*]] = load ptr, ptr [[TMP25]], align 8
// CHECK1-NEXT:    [[ARRAYIDX2_I:%.*]] = getelementptr inbounds ptr, ptr [[TMP26]], i64 9
// CHECK1-NEXT:    [[TMP27:%.*]] = load ptr, ptr [[ARRAYIDX2_I]], align 8
// CHECK1-NEXT:    [[ARRAYIDX3_I:%.*]] = getelementptr inbounds i8, ptr [[TMP27]], i64 [[LB_ADD_LEN_I]]
// CHECK1-NEXT:    [[TMP28:%.*]] = ptrtoint ptr [[ARRAYIDX3_I]] to i64
// CHECK1-NEXT:    [[TMP29:%.*]] = ptrtoint ptr [[TMP20]] to i64
// CHECK1-NEXT:    [[TMP30:%.*]] = sub i64 [[TMP28]], [[TMP29]]
// CHECK1-NEXT:    [[TMP31:%.*]] = add nuw i64 [[TMP30]], 1
// CHECK1-NEXT:    [[TMP32:%.*]] = mul nuw i64 [[TMP31]], ptrtoint (ptr getelementptr (i8, ptr null, i32 1) to i64)
// CHECK1-NEXT:    store i64 [[TMP31]], ptr @{{reduction_size[.].+[.]}}, align 8, !noalias !12
// CHECK1-NEXT:    [[TMP33:%.*]] = load ptr, ptr [[TMP12]], align 8
// CHECK1-NEXT:    [[TMP34:%.*]] = call ptr @__kmpc_task_reduction_get_th_data(i32 [[TMP16]], ptr [[TMP33]], ptr [[TMP20]])
// CHECK1-NEXT:    [[TMP35:%.*]] = getelementptr inbounds [[STRUCT_ANON]], ptr [[TMP9]], i32 0, i32 2
// CHECK1-NEXT:    [[TMP36:%.*]] = load ptr, ptr [[TMP35]], align 8
// CHECK1-NEXT:    [[TMP37:%.*]] = load ptr, ptr [[TMP36]], align 8
// CHECK1-NEXT:    [[TMP38:%.*]] = ptrtoint ptr [[TMP37]] to i64
// CHECK1-NEXT:    [[TMP39:%.*]] = ptrtoint ptr [[TMP20]] to i64
// CHECK1-NEXT:    [[TMP40:%.*]] = sub i64 [[TMP38]], [[TMP39]]
// CHECK1-NEXT:    [[TMP41:%.*]] = getelementptr i8, ptr [[TMP34]], i64 [[TMP40]]
// CHECK1-NEXT:    store ptr [[TMP4_I]], ptr [[TMP_I]], align 8, !noalias !12
// CHECK1-NEXT:    store ptr [[TMP41]], ptr [[TMP4_I]], align 8, !noalias !12
// CHECK1-NEXT:    ret i32 0
//
//
// CHECK1-LABEL: define {{[^@]+}}@{{__omp_offloading_[0-9a-z]+_[0-9a-z]+}}_main_l14.omp_outlined.omp.reduction.reduction_func
// CHECK1-SAME: (ptr noundef [[TMP0:%.*]], ptr noundef [[TMP1:%.*]]) #[[ATTR3]] {
// CHECK1-NEXT:  entry:
// CHECK1-NEXT:    [[DOTADDR:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    [[DOTADDR1:%.*]] = alloca ptr, align 8
// CHECK1-NEXT:    store ptr [[TMP0]], ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    store ptr [[TMP1]], ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP2:%.*]] = load ptr, ptr [[DOTADDR]], align 8
// CHECK1-NEXT:    [[TMP3:%.*]] = load ptr, ptr [[DOTADDR1]], align 8
// CHECK1-NEXT:    [[TMP4:%.*]] = getelementptr inbounds [3 x ptr], ptr [[TMP3]], i64 0, i64 0
// CHECK1-NEXT:    [[TMP5:%.*]] = load ptr, ptr [[TMP4]], align 8
// CHECK1-NEXT:    [[TMP6:%.*]] = getelementptr inbounds [3 x ptr], ptr [[TMP2]], i64 0, i64 0
// CHECK1-NEXT:    [[TMP7:%.*]] = load ptr, ptr [[TMP6]], align 8
// CHECK1-NEXT:    [[TMP8:%.*]] = getelementptr inbounds [3 x ptr], ptr [[TMP3]], i64 0, i64 1
// CHECK1-NEXT:    [[TMP9:%.*]] = load ptr, ptr [[TMP8]], align 8
// CHECK1-NEXT:    [[TMP10:%.*]] = getelementptr inbounds [3 x ptr], ptr [[TMP2]], i64 0, i64 1
// CHECK1-NEXT:    [[TMP11:%.*]] = load ptr, ptr [[TMP10]], align 8
// CHECK1-NEXT:    [[TMP12:%.*]] = getelementptr inbounds [3 x ptr], ptr [[TMP2]], i64 0, i64 2
// CHECK1-NEXT:    [[TMP13:%.*]] = load ptr, ptr [[TMP12]], align 8
// CHECK1-NEXT:    [[TMP14:%.*]] = ptrtoint ptr [[TMP13]] to i64
// CHECK1-NEXT:    [[TMP15:%.*]] = load i32, ptr [[TMP7]], align 4
// CHECK1-NEXT:    [[TMP16:%.*]] = load i32, ptr [[TMP5]], align 4
// CHECK1-NEXT:    [[ADD:%.*]] = add nsw i32 [[TMP15]], [[TMP16]]
// CHECK1-NEXT:    store i32 [[ADD]], ptr [[TMP7]], align 4
// CHECK1-NEXT:    [[TMP17:%.*]] = getelementptr i8, ptr [[TMP11]], i64 [[TMP14]]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_ISEMPTY:%.*]] = icmp eq ptr [[TMP11]], [[TMP17]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_ISEMPTY]], label [[OMP_ARRAYCPY_DONE5:%.*]], label [[OMP_ARRAYCPY_BODY:%.*]]
// CHECK1:       omp.arraycpy.body:
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRCELEMENTPAST:%.*]] = phi ptr [ [[TMP9]], [[ENTRY:%.*]] ], [ [[OMP_ARRAYCPY_SRC_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DESTELEMENTPAST:%.*]] = phi ptr [ [[TMP11]], [[ENTRY]] ], [ [[OMP_ARRAYCPY_DEST_ELEMENT:%.*]], [[OMP_ARRAYCPY_BODY]] ]
// CHECK1-NEXT:    [[TMP18:%.*]] = load i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 1
// CHECK1-NEXT:    [[CONV:%.*]] = sext i8 [[TMP18]] to i32
// CHECK1-NEXT:    [[TMP19:%.*]] = load i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], align 1
// CHECK1-NEXT:    [[CONV2:%.*]] = sext i8 [[TMP19]] to i32
// CHECK1-NEXT:    [[ADD3:%.*]] = add nsw i32 [[CONV]], [[CONV2]]
// CHECK1-NEXT:    [[CONV4:%.*]] = trunc i32 [[ADD3]] to i8
// CHECK1-NEXT:    store i8 [[CONV4]], ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], align 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DEST_ELEMENT]] = getelementptr i8, ptr [[OMP_ARRAYCPY_DESTELEMENTPAST]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_SRC_ELEMENT]] = getelementptr i8, ptr [[OMP_ARRAYCPY_SRCELEMENTPAST]], i32 1
// CHECK1-NEXT:    [[OMP_ARRAYCPY_DONE:%.*]] = icmp eq ptr [[OMP_ARRAYCPY_DEST_ELEMENT]], [[TMP17]]
// CHECK1-NEXT:    br i1 [[OMP_ARRAYCPY_DONE]], label [[OMP_ARRAYCPY_DONE5]], label [[OMP_ARRAYCPY_BODY]]
// CHECK1:       omp.arraycpy.done5:
// CHECK1-NEXT:    ret void
//
