#include "func.h"

int sum_f(int a, int b) { return a + b; }
int res_f(int a, int b) { return a - b; }
int mul_f(int a, int b) { return a * b; }
int div_f(int a, int b) { return ((0 != b) ? (a / b) : (0)); }