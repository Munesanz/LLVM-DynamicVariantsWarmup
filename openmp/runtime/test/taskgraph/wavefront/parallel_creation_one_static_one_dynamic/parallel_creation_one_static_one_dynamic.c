// RUN: %libomp-tdg-compile-and-run
#include "../square.h"
#include <stdbool.h>

#define REPETITIONS 1

int test_parallel_creation_one_static_one_dynamic()
{
    bool parallelCreation = false;
    bool volatile firstExecuting = false;
    bool volatile secondExecuting = false;

    init_matrix();

    #pragma omp parallel shared(parallelCreation,firstExecuting, secondExecuting)
    {
        int thid = omp_get_thread_num();
        if (thid == 0) {
            for (int i = 0; i < NUM_ITER / 2; i++) {
                #pragma omp taskgraph tdg_type(static) nowait
                {
                #pragma omp critical
                {
                    firstExecuting = true;
                    if(secondExecuting){
                        parallelCreation = true;
                    }
                }
                //Sleep to force concurrency
                sleep(1);

                wavefront(square);

                firstExecuting = false;
                }
            }
        } else if (thid == 1) {
            for (int i = NUM_ITER / 2; i < NUM_ITER; i++) {
                #pragma omp taskgraph tdg_type(dynamic) nowait
                {
                #pragma omp critical
                {
                    secondExecuting = true;
                    if(firstExecuting) {
                        parallelCreation = true;
                    }
                }
                //Sleep to force concurrency
                sleep(1);

                wavefront(square1);

                secondExecuting = false;
                }
            }
        }
    }

    if (vanilla_result_4 == square[N - 1][N - 1][BS - 1][BS - 1] &&
        vanilla_result_4 == square1[N - 1][N - 1][BS - 1][BS - 1] &&
        parallelCreation)
        return 1;
   
    return 0;
}

int main()
{
    int i;
    int num_failed=0;

    vanilla_result_computation();

    if (omp_get_max_threads() < 2)
        omp_set_num_threads(8);
    
    for(i = 0; i < REPETITIONS; i++) {
        if(!test_parallel_creation_one_static_one_dynamic()) {
            num_failed++;
        }
    }
    return num_failed;
}
