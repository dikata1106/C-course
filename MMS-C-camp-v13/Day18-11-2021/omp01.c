#include <stdio.h>
#include <time.h>
#include <omp.h>

static float parallel_sum(const float *a, size_t n)
{
    // base case
    if (n <= CUTOFF) {
        return serial_sum(a, n);
    }

    // recursive case
    float x, y;
    size_t half = n / 2;

    #pragma omp task shared(x)
    x = parallel_sum(a, half);
    #pragma omp task shared(y)
    y = parallel_sum(a + half, n - half);
    #pragma omp taskwait
    x += y;

    return x;
}


int main(void){
    #pragma omp parallel num_threads(10)
    {
        int id = omp_get_thread_num();
        printf("Hello from %d\n", id);
    }
    #pragma omp parallel for
    for (int i = 0; i < 10; i++){
        printf("%d ", i);
    }

    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < 10; i++){
        sum *= arr[i];
    }

    int x = 0;
    omp_lock_t lock;
    omp_init_lock(&lock);
    #pragma omp parallel num_threads(100)
    {
        for (int i = 0; i < 100; i++){
            omp_set_lock(&lock);
            x++;
            omp_unset_lock(&lock);
        }
    }
    omp_destroy_lock(&lock);
    int res = sumArr(arr, 10);
    printf("Sum = %d\n", res);
    putchar('\n');
    return 0;
}