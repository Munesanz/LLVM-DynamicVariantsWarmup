// RUN: %libomp-tdg-compile-and-run
#include "../axpy.h"

#include <stdio.h>
#include <unistd.h>

int test_asynchronous_tdgs_nowait()
{
     double *x, *y;
    x = (double*)malloc(sizeof(double) * N);
    y = (double*)malloc(sizeof(double) * N);

    for(int i = 0; i < N; ++i){
        x[i] = y[i] = 1;
    }

    bool volatile firstFinished = false;
    bool parallelCreation = true;
    #pragma omp parallel shared(x,y, parallelCreation)
    #pragma omp single
    {
      #ifdef TDG
      #pragma omp taskgraph tdg_type(static) nowait
      #endif
      {
        for (int i=0; i<NUM_ITER / 2; i++)
          saxpy(x, y);

        #pragma omp task
        {
          sleep(2);
          firstFinished = true;
        }
      }

      #ifdef TDG
      #pragma omp taskgraph tdg_type(dynamic) nowait
      #endif
      {
        if(firstFinished)
            parallelCreation = false;

        for (int i= NUM_ITER / 2; i<NUM_ITER; i++)
          saxpy(x, y);
      }
    }

    if (!parallelCreation) return 0;
    for (int i=0; i<NUM_ITER; i++)
        if (x[i]*(NUM_ITER)+1 != y[i]) return 0;

    free(x);
    free(y);
    
    return 1;
}

int main()
{
    int i;
    int num_failed=0;

    if (omp_get_max_threads() < 2)
        omp_set_num_threads(8);
    
    for(i = 0; i < REPETITIONS; i++) {
        if(!test_asynchronous_tdgs_nowait()) {
            num_failed++;
        }
    }
    return num_failed;
}
