#include <stdio.h>
#include <omp.h>

void inc();
int var;

int main(void){ 
    register int a[10]; 
    auto int b = 10;
    static int s = 10; 
     printf("%d\n", a[1]);
     inc();
     printf("%d\n", var);
    /*#pragma omp parallel
    printf("Hello\n");

    #pragma omp parallel
    for (int i = 1; i <= 30; i++){
        printf("%d ", i);
    }
    putchar('\n');

   omp_set_num_threads(2);
   #pragma omp parallel
   {
       int id = omp_get_thread_num();
       printf("hello (%d)\n", id);
       printf("world (%d)\n", id);
   }*/
    return 0;
}