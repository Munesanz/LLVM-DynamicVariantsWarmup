// RUN: %libomp-tdg-compile-and-run
#include "../axpy.h"

#include <stdio.h>
#include <unistd.h>

#define REPETITIONS 1

int test_parallel_creation_one_static_one_dynamic()
{
    double *x, *y, *y1, *y2;
    x = (double*)malloc(sizeof(double) * N);
    y = (double*)malloc(sizeof(double) * N);
    y1 = (double*)malloc(sizeof(double) * N);
    y2 = (double*)malloc(sizeof(double) * N);

    for(int i = 0; i < N; ++i){
        x[i] = y[i] = y1[i] = y2[i] = 1;
    }

    bool parallelCreation = false;
    bool volatile firstExecuting = false;
    bool volatile secondExecuting = false;
    #pragma omp parallel shared(x,y,parallelCreation,firstExecuting, secondExecuting)
    {
      int thid = omp_get_thread_num();
      if (thid == 0) {
        for (int i = 0; i < NUM_ITER / 2; i++)
        #ifdef TDG
        #pragma omp taskgraph tdg_type(static) nowait
        #endif
        {
          #pragma omp critical
          {
            firstExecuting = true;
            if(secondExecuting)
              parallelCreation = true;
          }
          //Sleep to force concurrency
          sleep(1);

          saxpy(x, y1);

          firstExecuting = false;
        }
      } else if (thid == 1) {
        for (int i = NUM_ITER / 2; i < NUM_ITER; i++)
        #ifdef TDG
        #pragma omp taskgraph tdg_type(dynamic) nowait
        #endif
        {
          #pragma omp critical
          {
            secondExecuting = true;

            if(firstExecuting)
              parallelCreation = true;
          }
          //Sleep to force concurrency
          sleep(1);

          saxpy(x, y2);

          secondExecuting = false;
        }
      }
    }

    for(int i = 0; i < N; ++i){
        y[i] = y1[i]+y2[i];
    }

    if (!parallelCreation) return 0;
    for (int i=0; i<NUM_ITER; i++)
        if (x[i]*(NUM_ITER)+2 != y[i]) return 0;

    free(x);
    free(y);
    free(y1);
    free(y2);
    
    return 1;
}

int main()
{
    int i;
    int num_failed=0;

    if (omp_get_max_threads() < 2)
        omp_set_num_threads(8);
    
    for(i = 0; i < REPETITIONS; i++) {
        if(!test_parallel_creation_one_static_one_dynamic()) {
            num_failed++;
        }
    }

    return num_failed;
}
