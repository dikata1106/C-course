/* Daniel Ruskov Vangelov 29/10/2021
daniel@daniel-GF63-Thin-10SCXR:~/MMS$ gcc Hw-Day-2_2.c -o Hw-Day-2_2 -lm
daniel@daniel-GF63-Thin-10SCXR:~/MMS$ ./Hw-Day-2_2
Enter number of tests: 50000
Test float or double (f/d): f
Enter new epsilon (0 and 1.0e-5 already to test): 0.001
Build-In compare (eps = 0):                     22 of 50000 correct comparations (0.0440%)
Fixed Epsilon compare (eps = 1.0e-5):           142 of 50000 correct comparations (0.2840%)
Adaptive Epsilon compare (eps = 1.0e-5):        2577 of 50000 correct comparations (5.1540%)
My Adaptive Epsilon compare:                    50000 of 50000 correct comparations (100.0000%)
Time measured:                                  2 seconds.
daniel@daniel-GF63-Thin-10SCXR:~/MMS$ ./Hw-Day-2_2
Enter number of tests: 50000
Test float or double (f/d): d
Enter new epsilon (0 and 1.0e-5 already to test): 0.001
Build-In compare (eps = 0):                     22 of 50000 correct comparations (0.0440%)
Fixed Epsilon compare (eps = 1.0e-5):           50000 of 50000 correct comparations (100.0000%)
Adaptive Epsilon compare (eps = 1.0e-5):        50000 of 50000 correct comparations (100.0000%)
My Adaptive Epsilon compare:                    50000 of 50000 correct comparations (100.0000%)
Time measured:                                  2 seconds.
daniel@daniel-GF63-Thin-10SCXR:~/MMS$ ./Hw-Day-2_2
Enter number of tests: 10
Test float or double (f/d): y
Wrong option, please select float or double (f/d):a
Wrong option, please select float or double (f/d):^C
daniel@daniel-GF63-Thin-10SCXR:~/MMS$ 
*/
#include <stdio.h>
#include <math.h>
#include <time.h>

// build-in compare operator
int floatCompare1(float a, float b){
    return a == b;
}

// fixed epsilon
int floatCompare2(float a, float b){
    return fabs(a - b) < 1.0e-5f;
}

// adaptive epsilon
int floatCompare3(float a, float b){
    return fabs(a - b) < 1.0e-5f * fmax(fabs(a), fabs(b));
}

// my adaptive epsilon
int floatCompare4(float a, float b, float e){
    return fabs(a - b) < e * fmax(fabs(a), fabs(b));
}

// build-in compare operator
int doubleCompare1(double a, double b){
    return a == b;
}

// fixed epsilon
int doubleCompare2(double a, double b){
    return fabs(a - b) < 1.0e-5;
}

// adaptive epsilon
int doubleCompare3(double a, double b){
    return fabs(a - b) < 1.0e-5 * fmax(fabs(a), fabs(b));
}

// my adaptive epsilon
int doubleCompare4(double a, double b, double e){
    return fabs(a - b) < e * fmax(fabs(a), fabs(b));
}

int main(void) {
    char option;
    time_t begin, end;
    int buildInCorrect = 0, fixedCorrect = 0, adaptiveCorrect = 0, myAdaptiveCorrect = 0, numberOfTests, i, j;
    printf("Enter number of tests: ");
    scanf("%d", &numberOfTests);
    printf("Test float or double (f/d): ");
    scanf(" %c", &option);  // getchar() make problem, take whitespace.
    // putchar(option);
    while(option != 'f' && option != 'd') {
        printf("Wrong option, please select float or double (f/d):");
        scanf(" %c", &option);
    }
    if (option == 'f') {
        float a, b, e;
        printf("Enter new epsilon (0 and 1.0e-5 already to test): ");
        scanf("%f", &e);
        // printf("%.20f\n", e);
        time(&begin);
        for (i=1; i<=numberOfTests; i++) {
            a = (float)i * 0.1f;
            b = 0.0f;
            for (j=0; j<i; j++, b += 0.1f);
            // printf("%.35f\n%.35f\n\n", a, b);
            if (floatCompare1(a, b))
                buildInCorrect++;
            if (floatCompare2(a, b))
                fixedCorrect++;
            if (floatCompare3(a, b))
                adaptiveCorrect++;
            if (floatCompare4(a, b, e))
                myAdaptiveCorrect++;
        }
        time(&end);
        printf("Build-In compare (eps = 0):\t\t\t%d of %d correct comparations (%.4f%%)\n", buildInCorrect, numberOfTests, (float)buildInCorrect/numberOfTests*100);
        printf("Fixed Epsilon compare (eps = 1.0e-5):\t\t%d of %d correct comparations (%.4f%%)\n", fixedCorrect, numberOfTests, (float)fixedCorrect/numberOfTests*100);
        printf("Adaptive Epsilon compare (eps = 1.0e-5):\t%d of %d correct comparations (%.4f%%)\n", adaptiveCorrect, numberOfTests, (float)adaptiveCorrect/numberOfTests*100);
        printf("My Adaptive Epsilon compare:\t\t\t%d of %d correct comparations (%.4f%%)\n", myAdaptiveCorrect, numberOfTests, (float)myAdaptiveCorrect/numberOfTests*100);
        printf("Time measured:\t\t\t\t\t%ld seconds.\n", end-begin);
    } else if (option == 'd') {
        double a, b, e;
        printf("Enter new epsilon (0 and 1.0e-5 already to test): ");
        scanf("%lf", &e);
        // printf("%.40lf\n", e);
        time(&begin);
        for (i=1; i<=numberOfTests; i++) {
            a = (double)i * 0.1;
            b = 0.0;
            for (j=0; j<i; j++, b += 0.1);
            // printf("%.70lf\n%.70lf\n\n", a, b);
            if (doubleCompare1(a, b))
                buildInCorrect++;
            if (doubleCompare2(a, b))
                fixedCorrect++;
            if (doubleCompare3(a, b))
                adaptiveCorrect++;
            if (doubleCompare4(a, b, e))
                myAdaptiveCorrect++;
        }
        time(&end);
        printf("Build-In compare (eps = 0):\t\t\t%d of %d correct comparations (%.4lf%%)\n", buildInCorrect, numberOfTests, (double)buildInCorrect/numberOfTests*100);
        printf("Fixed Epsilon compare (eps = 1.0e-5):\t\t%d of %d correct comparations (%.4lf%%)\n", fixedCorrect, numberOfTests, (double)fixedCorrect/numberOfTests*100);
        printf("Adaptive Epsilon compare (eps = 1.0e-5):\t%d of %d correct comparations (%.4lf%%)\n", adaptiveCorrect, numberOfTests, (double)adaptiveCorrect/numberOfTests*100);
        printf("My Adaptive Epsilon compare:\t\t\t%d of %d correct comparations (%.4lf%%)\n", myAdaptiveCorrect, numberOfTests, (double)myAdaptiveCorrect/numberOfTests*100);
        printf("Time measured:\t\t\t\t\t%ld seconds.\n", end-begin);
     } else {
        printf("Wrong option, finishing program,\n");
    }    
    return 0;
}
