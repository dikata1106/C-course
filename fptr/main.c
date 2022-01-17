#include "func.h"
int main(void) {
  int (*fptr[])(int, int) = {sum_f, res_f, mul_f, div_f};
  int op, N1, N2;
  while (TRUE) {
    printf(
        "SELECT OPERATION CODE\n=====================\n0. Sum\n1. Rest\n2. "
        "Multiply\n3. Divide\nAny other for exit\n---------------------\n");
    scanf("%d", &op);
    if ((op >= 0) && (op < 4)) {
      printf("First number:\t");
      scanf("%d", &N1);
      printf("Second number:\t");
      scanf("%d", &N2);
      int buf=(fptr[op])(N1, N2);
      printf("Result:%d\n\n", buf);
    } else {
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}