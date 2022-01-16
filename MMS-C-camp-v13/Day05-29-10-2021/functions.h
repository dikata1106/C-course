#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>

double f(double);
double power2(double);
int maxNum(int,int);
void printHello(int);
void printInfo(void);
int sumNums(int, ...);
int countEven(int, ...);
double average(int, ...);
void printArgs(char*, ...);

#endif