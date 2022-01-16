#include <stdio.h>

int main() {

	int a = 10, b = 20;
	float c = 3.14;
	double d = 10.234;
	char e = 'S';
	char * str = "Hello";
	short s = 20;
	long al = 234;
	long long x = 344;
	// printf("a = %d\nb = %d\nc = %f\nd = %lf\ne = %c, %d\ne = %s\n", a, b, c, d, e, e, str);
	printf("%ld B\n", sizeof d);
	
	return 0;
}
